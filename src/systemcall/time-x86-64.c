#include <stdio.h>
#include <time.h>
int main()
{
      time_t tt;
      struct tm *t;
      asm volatile(
          "movl $0, %%edi\n\t"   //EDI寄存器用于传递参数
          "movl $0xc9,%%eax\n\t" //使用EAX传递系统调用号
          "syscall\n\t"          //触发系统调用
          "movq %%rax,%0\n\t"    //保存返回值
          : "=m"(tt));
      t = localtime(&tt);
      printf("time: %d/%d/%d %d:%d:%d\n",
             t->tm_year + 1900,
             t->tm_mon,
             t->tm_mday,
             t->tm_hour,
             t->tm_min,
             t->tm_sec);
      return 0;
}
