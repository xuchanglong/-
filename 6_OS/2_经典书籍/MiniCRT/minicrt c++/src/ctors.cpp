//ctors.cpp
typedef void (*init_func)(void);
#ifdef WIN32

#pragma code_seg(".CRT$XCA")
#pragma code_seg(".CRT$XCZ")

//#pragma data_seg(".CRT$XCA")
//#pragma data_seg(".CRT$XCZ")

//#pragma section(".CRT$XCA", long, write)
//#pragma section(".CRT$XCZ", long, write)

//#pragma section(".CRT$XCA", long, read)
//#pragma section(".CRT$XCZ", long, read)

__declspec(allocate(".CRT$XCA")) init_func ctors_begin[] = {0};
__declspec(allocate(".CRT$XCZ")) init_func ctors_end[] = {0};

extern "C" void do_global_ctors()
{
	init_func *p = ctors_begin;
	while (p < ctors_end)
	{
		if (*p != 0)
			(**p)();
		++p;
	}
}

#else

void run_hooks();
extern "C" void do_global_ctors()
{
	run_hooks();
}

#endif