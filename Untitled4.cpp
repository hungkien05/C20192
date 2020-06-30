#include<stdio.h>
#include<string>
int main ()
{
   string s;
   gets(s);
   
   s[0] = s[0] + ('A' - 'a');
   printf("%s",s);
   return 0;
}

