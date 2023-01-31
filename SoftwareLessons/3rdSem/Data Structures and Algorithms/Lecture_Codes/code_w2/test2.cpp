#include <iostream>
using namespace std;
int main()
{
// declare variables
int var1 = 0x12345613;
char *c;

c=(char*)&var1;

// print address of var1
printf("c=0x%lx\n",(long unsigned int)c);
printf("c=0x%x\n",*c);
printf("c=0x%x\n",*(c+1));
printf("c=0x%x\n",*(c+2));
printf("c=0x%x\n",*(c+3));

return 0;
}
