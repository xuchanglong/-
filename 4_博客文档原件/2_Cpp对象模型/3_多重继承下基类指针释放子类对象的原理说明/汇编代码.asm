007565AB  mov         dword ptr [pb2],eax  

    delete pb2;
007565AE  mov         eax,dword ptr [pb2]  
007565B1  mov         dword ptr [ebp-0ECh],eax  
007565B7  mov         ecx,dword ptr [ebp-0ECh]  
007565BD  mov         dword ptr [ebp-0E0h],ecx  
007565C3  cmp         dword ptr [ebp-0E0h],0  
007565CA  je          main+0D2h (07565F2h)  
007565CC  mov         esi,esp  
007565CE  push        1  
007565D0  mov         edx,dword ptr [ebp-0E0h]  
007565D6  mov         eax,dword ptr [edx]  
007565D8  mov         ecx,dword ptr [ebp-0E0h] 
; eax+8,找到 Base2 的虚函数表中 trunk 那一项的位置。
; [eax+8],获取 trunk 地址。 
007565DE  mov         edx,dword ptr [eax+8]  
; 跳转到 trunk 那段代码。
007565E1  call        edx  
007565E3  cmp         esi,esp  
007565E5  call        __RTC_CheckEsp (07511A9h)  
007565EA  mov         dword ptr [ebp-0F4h],eax  
007565F0  jmp         main+0DCh (07565FCh)  
007565F2  mov         dword ptr [ebp-0F4h],0  
    return 0;
007565FC  xor         eax,eax  
}


--- 无源文件 -----------------------------------------------------------------------
; 此时的 ecx 中的内容为 pb2 中的内容，即：new Son() 生成的对象中 Base2 部分的首地址。
; 经过 sub 之后，就得到了new Son() 生成的对象的首地址。
00691DB4  sub         ecx,4  
; 调用 Son 类的析构函数。
00691DB7  jmp         Son::`vector deleting destructor' (06914BAh)  
00691DBC  int         3  
00691DBD  int         3  
00691DBE  int         3  
00691DBF  int         3  


0069235F  int         3  
00692360  push        ebp  
00692361  mov         ebp,esp  
00692363  sub         esp,0CCh  
00692369  push        ebx  
0069236A  push        esi  
0069236B  push        edi  
0069236C  push        ecx  
0069236D  lea         edi,[ebp-0CCh]  
00692373  mov         ecx,33h  
00692378  mov         eax,0CCCCCCCCh  
0069237D  rep stos    dword ptr es:[edi]  
0069237F  pop         ecx  
00692380  mov         dword ptr [this],ecx  
00692383  mov         ecx,dword ptr [this]  
; 执行 Son 类的析构函数。
00692386  call        Son::~Son (06914D8h)  
0069238B  mov         eax,dword ptr [ebp+8]  
0069238E  and         eax,1  
00692391  je          Son::`scalar deleting destructor'+41h (06923A1h)  
00692393  push        8  
00692395  mov         eax,dword ptr [this]  
00692398  push        eax  
; 释放 new Son() 生成的对象。
00692399  call        operator delete (069105Fh)  
0069239E  add         esp,8  
006923A1  mov         eax,dword ptr [this]  
006923A4  pop         edi  
006923A5  pop         esi  
006923A6  pop         ebx  
006923A7  add         esp,0CCh  
006923AD  cmp         ebp,esp  
006923AF  call        __RTC_CheckEsp (06911A9h)  
006923B4  mov         esp,ebp  
006923B6  pop         ebp  
006923B7  ret         4  


00691E00  push        ebp  
00691E01  mov         ebp,esp  
00691E03  sub         esp,0CCh  
00691E09  push        ebx  
00691E0A  push        esi  
00691E0B  push        edi  
00691E0C  push        ecx  
00691E0D  lea         edi,[ebp-0CCh]  
00691E13  mov         ecx,33h  
00691E18  mov         eax,0CCCCCCCCh  
00691E1D  rep stos    dword ptr es:[edi]  
00691E1F  pop         ecx  
00691E20  mov         dword ptr [this],ecx  
00691E23  mov         ecx,dword ptr [this]  
00691E26  add         ecx,4  
; 执行 Base2 的析构函数。
00691E29  call        Base2::~Base2 (06914C4h)  
; 执行 Base1 的析构函数。
00691E2E  mov         ecx,dword ptr [this]  
00691E31  call        Base1::~Base1 (06914E7h)  
00691E36  pop         edi  
00691E37  pop         esi  
00691E38  pop         ebx  
00691E39  add         esp,0CCh  
00691E3F  cmp         ebp,esp  
00691E41  call        __RTC_CheckEsp (06911A9h)  
00691E46  mov         esp,ebp  
00691E48  pop         ebp  
00691E49  ret  