# 0 "main.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "main.c"


# 1 "math.h" 1



int sum(int a,int b);
int sub(int a,int b);
int mul(int a,int b);
double div(int a,int b);
# 4 "main.c" 2

int main()
{
 printf("sum of 4 and 3 is :%d\n",sum(4,3));
 printf("sub of 4 and 3 is :%d\n",sub(4,3));
 printf("mul of 4 and 3 is :%d\n",mul(4,3));
 printf("div of 4 and 3 is :%lf\n",div(4,3));
 return 0;
}
