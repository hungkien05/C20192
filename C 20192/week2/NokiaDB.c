#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// doc chuan
enum {SUCCESS, FAIL, MAX_ELEMENT = 9999};

// the phone book structure
typedef struct {
      char name[30];
      char ram[11];
      char screen[40];
      char price[40];
}phoneaddress;

int main(){
	FILE *fp1, *fp2;
	int i,n, irc; // return code
   	int reval = SUCCESS;
	if ((fp1 = fopen("NokiaDB.txt", "r")) == NULL){
		printf("Cannot open %s.\n", "NokiaDB.txt");
		reval = FAIL;
	}
	fscanf(fp1,"%d",&n);
	phoneaddress a[n+1];
	for (i=0;i<n;i++){
		fflush(stdin);
		fscanf(fp1,"%s %s %s %s",a[i].name ,a[i].ram, a[i].screen, a[i].price);
		
	}
	fclose(fp1);
	
	// create and open NokiaDB.txt for writing
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
   	
   	//search
   	char model[30];
   	printf("-----\nWhich model you want to search: ");
  	scanf("%s", model);
   	for (i=0; i<n; i++){
   		if (strcasecmp(a[i].name, model)==0){
   			printf("Found: %s - ",a[i].name);
		    printf("%s - ",a[i].ram);
		    printf("%s - ",a[i].screen);
		    printf("%s\n",a[i].price);
		}
	}
   	return 0;
}
