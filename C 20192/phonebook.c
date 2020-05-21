#include <stdio.h>

enum {SUCCESS, FAIL, MAX_ELEMENT = 20};

// the phone book structure
typedef struct phoneaddress_t {
      char name[20];
      char tel[11];
      char email[25];
}phoneaddress;

int main(void)
{
   FILE *fp;
   phoneaddress phonearr[MAX_ELEMENT];
	 int i,n, irc; // return code
   int reval = SUCCESS;
   printf("nhap so luong n: ");
   scanf("%d",&n);
   for (i=0; i<n;i++) {
		printf("name:"); scanf("%s",&phonearr[i].name);
		fflush(stdin);
    	printf("tel:"); scanf("%s",&phonearr[i].tel);
    	fflush(stdin);
    	printf("email:"); scanf("%s",&phonearr[i].email);
    	fflush(stdin);
   }
   if( (fp=fopen("phonebook.dat","wb")) == NULL){
   		printf("cannot open");
   		reval=FAIL;
   }
   // write the entire array into the file 
	irc = fwrite(phonearr, sizeof(phoneaddress), n, fp);
   printf(" fwrite return code = %d\n", irc); 
   fclose(fp);
   //read from this file to array again
   if ((fp = fopen("phonebook.dat","rb")) == NULL){
		printf("Can not open %s.\n", "out.txt");
		reval = FAIL;
	} 
   irc = fread(phonearr, sizeof(phoneaddress), n, fp);
   printf(" fread return code = %d\n", irc);
   for (i=0; i<n; i++){
     printf("%s-",phonearr[i].name);
     printf("%s-",phonearr[i].tel);
     printf("%s\n",phonearr[i].email);
   }
   fclose(fp);
   return reval;
}



