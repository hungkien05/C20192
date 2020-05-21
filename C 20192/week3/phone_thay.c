#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXCHAR 100

typedef struct {
  char  model[20];
  char   memory[10];
  char screen_size[30];
  char   price[20];
} phone_t;

//phone_t *phoneDB;
typedef struct node {
	phone_t phoneDB;
	struct node* next;
} node;
node *cur;
node *root;
int total;
FILE *fp;

 node* makeNewNode(){
	struct node* newNode = (node*)malloc(sizeof(phone_t));
	char str[101];
	while (fgets(str, MAXCHAR, fp) != NULL){
		sscanf(str, "%s %s %s %s",
	   	&((newNode->phoneDB).model),
	   	&((newNode->phoneDB).memory),
	   	&((newNode->phoneDB).screen_size),
	   	&((newNode->phoneDB).price));
//	printf("%s\n",str);   	
    printf("%s, %s, %s, %s\n", (newNode->phoneDB).model, (newNode->phoneDB).memory, (newNode->phoneDB).screen_size, (newNode->phoneDB).price);
    break;
	}
	newNode->next = NULL;
	return newNode;
}

void convertDB() {
  FILE *fin;
  FILE *fout;
  phone_t phone;
  char str[MAXCHAR+1];

  if ((fin = fopen("NokiaDB1.txt", "r")) == NULL) {
    printf("Can\'t read from NokiaDB1.txt\n");
    return;
  };

  if ((fout = fopen("NokiaDB1.dat", "w")) == NULL) {
    printf("Can\'t open NokiaDB1.dat\n");
    return;
  };

  while (fgets(str, MAXCHAR, fin) != NULL) {
    sscanf(str, "%s %d %lf %d",
	   &(phone.model),
	   &(phone.memory),
	   &(phone.screen_size),
	   &(phone.price));
    printf("%s,%d,%f,%d\n", phone.model, phone.memory, phone.screen_size, phone.price);
    fwrite(&phone, sizeof(phone_t), 1, fout);
  }

  fclose(fin);
  fclose(fout);
}


void readDB() {
//  node* root;
  node* newNode;
//  node* cur;
 
  int i=0;
  printf("reading...\n");
  if ((fp=fopen("NokiaDB.txt","rb"))==NULL) {
  	printf("cannot open NokiaDB.dat");
  	return;
  }
  root = makeNewNode();
  cur = root;
  for (i=0;i<10;i++){
  	newNode = makeNewNode();
  	newNode->next = cur->next;
  	cur->next = newNode;
  	cur = cur->next;
  	//printf("%s", ((cur->phoneDB).model));
  }
  
}


void printDB() {
	 node* iNode;
  printf("printing...\n");
  for (iNode=root; iNode!= NULL; iNode = iNode->next){
  	printf("%s\n", ((iNode->phoneDB).model));
  	
  }
}
void searchDB() {
  printf("searching...\n");
}

int main() {
  int running = 1;
  int selection;

  //phoneDB = NULL;
  total = 0;
  
  while (running) {
    printf("\n1. Convert from text to binary\n");
    printf("2. Read binary file\n");
    printf("3. Print database\n");
    printf("4. Search by model\n");
    printf("5. Quit\n");
    printf("Choose an option:");
    scanf("%d", &selection);
    switch (selection) {
    case 1:
      convertDB();
      break;
    case 2:
      readDB();
      break;
    case 3:
      printDB();
      break;
    case 4:
      searchDB();
      break;
    case 5:
      running = 0;
      break;
    }
  }


//  if (phoneDB != NULL) {
//    free(phoneDB);
//    total = 0;
//  }

  return 0;
}
