#include <stdio.h>
#include <string.h>

int main()
{
	char a[50]="abc", b[50]="defg";
	int l=strlen(a);
	int i;
	for (i=l; i<=l+strlen(b)-1; i++)
		a[i]=b[i-l];
	strcpy(b,a);
	puts(b);
	return 0;
}
/* strcat example 
#include <stdio.h>
#include <string.h>

int main ()
{
  char str[80];
  puts(str);
  printf("\n");
  strcpy (str,"these ");
  strcat (str,"strings ");
  strcat (str,"are ");
  strcat (str,"concatenated.");
  puts (str);
  return 0;
}*/
