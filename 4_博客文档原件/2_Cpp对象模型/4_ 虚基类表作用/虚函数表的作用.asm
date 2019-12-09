;-----------------------  唯一父类是虚基类  -----------------------
00B24114  lea         ecx,[Pobj]  
00B24117  call        Parent::Parent (0B21375h)  
    16: 	Pobj.i_grand_ = 1;
    ; 将 Pobj 首 4B 的内容赋值给 eax 寄存器。
    ; 该 4B 就是虚基类表指针的内容，即：虚基类表的首地址。
    ; 现在 eax 寄存器中就放置了虚基类表的首地址。
00B2411C  mov         eax,dword ptr [Pobj]  
    ; 将虚基类表的地址偏移4个字节之后的虚基类表的内容赋值给 ecx 寄存器。
00B2411F  mov         ecx,dword ptr [eax+4]  
    ; 将 Pobj 第8个字节的内容赋值为1。
00B24122  mov         dword ptr Pobj[ecx],1  
    17: 	Pobj.i_parent_ = 2;
00B2412A  mov         dword ptr [ebp-10h],2  
    18: 	
    19: 	return 0;

;-----------------------  父类分别是虚基类和普通父类  -----------------------
    Parent Pobj;
001F187B  push        1  
001F187D  lea         ecx,[Pobj]  
001F1880  call        Parent::Parent (01F114Fh)  
	Pobj.i_grand1_ = 1;
    ; ebp-1Ch Pobj对象中虚基类表的首地址。
    ; 将虚基类表地址中的内容赋值给 eax 。
001F1885  mov         eax,dword ptr [ebp-1Ch]  
    ; 将虚基类表的地址偏移4个字节之后的虚基类表的内容赋值给 ecx 寄存器。
001F1888  mov         ecx,dword ptr [eax+4]  
    ; 将 Pobj 第8个字节的内容赋值为1。
001F188B  mov         dword ptr [ebp+ecx-1Ch],1  
	Pobj.i_grand2_ = 2;
001F1893  mov         dword ptr [Pobj],2  
	Pobj.i_grand3_ = 3;
001F189A  mov         eax,dword ptr [ebp-1Ch]  
    ; 将虚基类表的地址偏移8个字节之后的虚基类表的内容赋值给 ecx 寄存器。
001F189D  mov         ecx,dword ptr [eax+8]  
    ; 将 Pobj 第12个字节的内容赋值为1。
001F18A0  mov         dword ptr [ebp+ecx-1Ch],3  
	Pobj.i_grand4_ = 4;
001F18A8  mov         eax,dword ptr [ebp-1Ch] 
    ; 将虚基类表的地址偏移12个字节之后的虚基类表的内容赋值给 ecx 寄存器。 
001F18AB  mov         ecx,dword ptr [eax+0Ch]  
    ; 将 Pobj 第16个字节的内容赋值为1。
001F18AE  mov         dword ptr [ebp+ecx-1Ch],4  
	Pobj.i_grand5_ = 5;
001F18B6  mov         eax,dword ptr [ebp-1Ch]  
    ; 将虚基类表的地址偏移16个字节之后的虚基类表的内容赋值给 ecx 寄存器。
001F18B9  mov         ecx,dword ptr [eax+10h]  
    ; 将 Pobj 第24个字节的内容赋值为1。
001F18BC  mov         dword ptr [ebp+ecx-1Ch],5  
	Pobj.i_parent_ = 6;
001F18C4  mov         dword ptr [ebp-18h],6  
	return 0;
001F18CB  xor         eax,eax  