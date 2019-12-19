// atexit.c
#include "minicrt.h"

typedef struct _func_mode
{
	atexit_func_t func;
	void*         arg;
	int           is_cxa;
	struct        _func_node* next;
} func_node;

static func_node* atexit_list = 0;

int register_atexit(atexit_func_t func, void* arg, int is_cxa)
{
	func_node* node;
	if(!func) return -1;
	
	node = (func_node *)malloc(sizeof(func_node));
	
	if(node == 0) return -1;
	
	node->func = func;
	node->arg = arg;
	node->is_cxa = is_cxa;
	node->next = atexit_list;
	atexit_list = node;
	return 0;
}

#ifndef WIN32
typedef void (*cxa_func_t)( void* );
int __cxa_atexit(cxa_func_t func, void* arg, void* unused)
{
	return register_atexit9(atexit_func_t)func, arg, 1);
}
#endif

int atexit(atexit_func_t func)
{
	return register_atexit(func, 0, 0);
}

void mini_crt_call_exit_routine()
{
	func_node* p = atexit_list;
	for(; p != 0; p = p->next )
	{
		#ifdef WIN32
			p->func();
		#else
		if( p->is_cxa )
			(( cxa_func_t)p->func)(p->arg);
		else
			p->func();
		#endif
		free(p);
	}
	atexit_list = 0;
}

//     值得一提的是，在注册函数时，被注册的函数是插入到列表头部的，而尾后
// mini_crt_call_exit_routine()是从头部开始遍历的，于是由atexit()或_cxa_atexit()注册的函数
// 是按照先注册后调用的顺序，这符台析构函数的规则，因为先构造的全局对象应该后析构。
		
// 13.3.4入口函数修改
//     由于增加了全局构造和析构的支持，那么需要对MiniCRT的入口函数和exit()函数进行
// 修改，把对do_global_ctors()和mini_crt_call_exit_routine()的调用加入到entry()和exit()函数
// 中去。修改后的entry.c如下（省略一部分未修改的内容）：