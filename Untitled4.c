#include<stdio.h>
#include<string.h>
int main ()
{
   string s[1000];
   gets(s);
   
   s[0] = s[0] + ('A' - 'a');
   printf("%s",s);
   return 0;
}

