// 查看汇编，用如下命名，禁止各种优化，方便调试
// gcc -Og -S -fno-if-conversion 01.absdiff.c

long absdiff(long x, long y)
{
    long result;
    if (x > y)
        result = x - y;
    else
        result = y - x;
    return result;
}

/*

因为使用的是long类型，所以使用的是64位8字节的rXX指令
如果使用的是int类型，使用的是32位4字节的eXX指令(e是r的一半，r兼容e)
由于是x86的架构指令集(cisv复杂指令集)
一个指令只能操作两个寄存器，所以不能 有 x = a + b 这种操作，所以只有 a += b, x = a
%rdi: x
%rsi: y
%rax: Return Value(保存返回值)

得到的汇编指令

absdiff:
.LFB0:
    .cfi_startproc
    endbr64
    movq	%rdi, %rax // 先将x保存到返回值(初始化返回值) result = x
    cmpq	%rsi, %rdi // 比较 cmpq(>) dest src => src > dest => result > y
    jle	.L2            // else 汇编生成 跳转标签，这个标签指向下一行要执行的代码的地址
    subq	%rsi, %rax // subq 相当于 a-=b的操作，subq(-=) dest src => src -= dest => result -= y
    ret                // 返回
.L2:
    subq	%rdi, %rsi // subq 相当于 a-=b的操作，subq(-=) dest src => src -= dest => y -= x
    movq	%rsi, %rax // 将 %rsi的值赋值给%ras => reuslt = y
    ret                // 返回
    .cfi_endproc
*/