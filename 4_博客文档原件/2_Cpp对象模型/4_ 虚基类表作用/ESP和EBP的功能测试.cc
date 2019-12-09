main() {

//执行test前

print(int p1,int p2);

//执行test后

}

分析下上面程序的调用原理，假设执行print前esp=Q：

push p2; //函数参数p2入栈，esp=Q-4H

push p1; //函数参数p1入栈，esp=Q-8H

call print; //函数返回地址入栈，esp=Q-0CH

//现在进入print内，做些准备工作：

push ebp; //保护先前ebp指针，ebp入栈，esp=Q-10H

mov ebp,esp; //设置ebp等于当前的esp

// 此时，ebp+0CH=Q-4H，即p2的位置

// 同样，ebp+08H=Q-8H，即p1的位置

// 下面是print内的一些操作：

sub esp,20H; //设置长度为10H大小的局部变量空间，esp=Q-20H

// ... ...

// 一系列操作

// ... ...

add esp,20H; //释放局部变量空间，esp=Q-10H

pop ebp; //出栈，恢复原先的ebp的值，esp=Q-0CH

ret 8; //ret返回，弹出先前入栈的返回地址，esp=Q-08H，后面加操作数8H为平衡堆栈

// 之后，弹出函数参数，esp=Q，恢复执行print函数前的堆栈；