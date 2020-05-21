#include <stdio.h>
#include <stdlib.h>

enum {SUCCESS, FAIL, MAX_ELEMENT = 20};

// the phone book structure
typedef struct {
      char name[20];
      char ram[11];
      char screen[40];
      char price[40];
}phoneaddress;

int main(){
	FILE *fp1, *fp2;
   	phoneaddress a[MAX_ELEMENT];
	int i,n, irc; // return code
   	int reval = SUCCESS;
//   	printf("nhap so luong n: ");
	if ((fp1 = fopen("NokiaDB.txt", "r")) == NULL){
		printf("Cannot open %s.\n", "NokiaDB.txt");
		reval = FAIL;
	}
	scanf("%d",&n);
	fflush(stdin);
	for (i=0;i<n;i++){
		fflush(stdin);
		scanf("%s %s %s %s",a[i].name,a[i].ram, a[i].screen, a[i].price);
		
	}
	fclose(fp1);
	if( (fp2=fopen("NokiaDB.dat","wb")) == NULL){
   		printf("cannot open");
   		reval=FAIL;
   	}
   	
   	// write the entire array into the file (write vao file)
	irc = fwrite(a, sizeof(phoneaddress), n, fp2);
   	printf(" fwrite return code = %d\n", irc); 
   	fclose(fp2);
   	
   	//read from this file to array again ( read tu file)
   	if ((fp2 = fopen("NokiaDB.dat","rb")) == NULL){
		printf("Can not open %s.\n", "NokiaDB.dat");
		reval = FAIL;
	} 
   	irc = fread(a, sizeof(phoneaddress), n, fp2);
   	printf(" fread return code = %d\n", irc);
   	for (i=0; i<n; i++){
		printf("%s - ",a[i].name);
	    printf("%s - ",a[i].ram);
	    printf("%s - ",a[i].screen);
	    printf("%s\n",a[i].price);
   	}
   	fclose(fp2);
}
