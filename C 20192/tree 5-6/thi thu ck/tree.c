#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tree.h"

tree createNullTree(){
	return (tree)NULL;
}

tree find_name(tree t, char *name){
	if (t==NULL) return NULL;
	if (strcmp(t->name,name)==0) return t;
	if(strcmp(name,t->name)<0)  {
			return find_name(t->left,name);
		}
		if(strcmp(name,t->name)>0) {
			return find_name(t->right, name);
		}
	
}

tree insertBST(tree t, char* x, struct Account* acc){
	if (t==NULL) {
		t=createTree(x,acc,NULL,NULL);
		return t;
	} else{
		if(strcmp(x,t->name)<0)  {
			t->left=insertBST(t->left, x, acc);
			return t;
		}
		if(strcmp(x,t->name)>0) {
			t->right=insertBST(t->right, x, acc);
			return t;
		}
	}

}

void insert_acc(tree tmp, struct Account* acc){
	tmp->accounts[tmp->numAccount]=*acc;
	tmp->total += acc->balance;
	tmp->numAccount++;
}

struct Account* make_acc(char *name, char *phone, double balance){
	struct Account* acc = (struct Account*)malloc(sizeof(struct Account));
	strcpy(acc->name,name);
	strcpy(acc->phone,phone);
	acc->balance=balance;
	return acc;
}

tree readDb(tree t, char *filename){
	FILE *fp1;
  int reval = 0;
	if ((fp1 = fopen(filename, "r")) == NULL){
		printf("Cannot open %s.\n", "NokiaDB.txt");
		reval = 1;
	}
	struct Account* acc;
	tree tmpTree;
	int n,i;
	char name[30],phone[15];
	double balance=0;
	fscanf(fp1,"%d",&n);
	for (i=0;i<n;i++){
		char c = getc(fp1);
		fgets(name,30,fp1);//doc name
		name[strlen(name)-1]='\0';
		
		fscanf(fp1,"%s",phone);//doc phone
		
		fscanf(fp1,"%lf",&balance);//doc balance
		
		acc = make_acc(name,phone, balance);
		tmpTree = find_name(t,name);
		if (tmpTree!=NULL) insert_acc(tmpTree, acc);
		else t=insertBST(t, name, acc);
	}
	fclose(fp1);
	return t;
}

tree createTree(char* x,struct Account* acc, tree l, tree r){
	tree tmp = (tree)malloc(sizeof(struct TreeNode));
	strcpy(tmp->name,x);
	tmp->numAccount=0;
	tmp->total=0;
	insert_acc(tmp,acc);
	tmp->left=l;
	tmp->right=r;
	return tmp;
}

tree createLeaf(char* x, struct Account* acc){
	return createTree(x,acc, createNullTree(), createNullTree());
}

int isNullTree(tree t){
	return (t==NULL);
}

int isLeaf(tree t){
	return (t!=NULL && t->left==NULL && t->right==NULL);
}

//int sizeOfTree(tree t){
//	if (isNullTree(t)) return 0;
//	else {
//		return (1+sizeOfTree(t->left)+sizeOfTree(t->right));
//	}
//}
//int sumOfTree(tree t){
//	if (isNullTree(t)) return 0;
//	else {
//		return (t->data+sumOfTree(t->left)+sumOfTree(t->right));
//	}
//}
tree left(tree n)
{ 
	if (n!=NULL) return n->left; 
	else return NULL;
}
tree right(tree n)
{ 
	if (n!=NULL) return n->right; 
	else return NULL;
}


tree leftMost(tree t){
	tree n=t;
	if (isNullTree(t)) return NULL;
	while (n->left!=NULL) n=n->left;
	return n;
}

tree rightMost(tree t){
	tree n=t;
	if (isNullTree(t)) return NULL;
	while (!isNullTree(right(n))) 
		n = right(n);
	return n;
}


char* treeToString(tree t) {
  char *result;
  char *left;
  char *right;
  
  if (isNullTree(t)) {
    result = (char*)malloc(20);
    strcpy(result, "Nil");
    return result;
  } else {
    left = treeToString(t->left);
    right = treeToString(t->right);
    
    result = (char*)malloc(60 + strlen(left) + strlen(right));
    sprintf(result, "node(%s,%s,%s)", t->name, left, right);
    free(left);
    free(right);
    return result;
  }
}

tree addToLeftMost(tree t, char* x, struct Account* acc) {
  tree n = leftMost(t);
  
  if (isNullTree(t))
    return createLeaf(x,acc);
  else {
    n->left = createLeaf(x,acc);
    return t;
  }
}

tree addToRightMost(tree t, element_t x, struct Account* acc) {
  tree n = rightMost(t);
  
  if (isNullTree(t))
    return createLeaf(x,acc);
  else {
    n->right = createLeaf(x,acc);
    return t;
  }
}

char *value(tree t) {
  if (isNullTree(t))
    return 0;
  else return t->name;
}

int height(tree t){
	if (t==NULL) return 0;
	int a=height(t->left);
	int b=height(t->right);
	if (a>b) return a+1;
	return b+1;
}

int leavesCount(tree t){
	if (t==NULL) return 0;
	if (isLeaf(t)) return 1;
	return leavesCount(t->left) + leavesCount(t->right);
}




tree removeRootBST(tree t) {
  tree p, tmp;
  
  if (isNullTree(t))
    return NULL;
  // Xoa nut la
  if (isLeaf(t)) {
    free(t);
    return NULL;
  }
  // Xoa nut co 1 con phai
  if (left(t) == NULL) {
    tmp = right(t);
    free(t);
    return tmp;
  }
  // Xoa nut co 1 con trai
  if (right(t) == NULL) {
    tmp = left(t);
    free(t);
    return tmp;
  }
  // Xoa nut co hai con
  p = t;
  tmp = right(t);
  while (left(tmp) != NULL) {
    p = tmp;
    tmp = left(tmp);
  }

  strcpy(t->name,tmp->name);
  tmp = removeRootBST(tmp);
  if (p == t)
    p->right = tmp;
  else
    p->left = tmp;
  return t;
}

tree removeBST(tree t, char* x) { // xoa node trong BST
  tree p, tmp;
  
  if (isNullTree(t))
    return NULL;

  if (strcmp(t->name,x)==0)
    return removeRootBST(t);

  p = NULL;
  tmp = t;
  while ((tmp != NULL) && strcmp(tmp->name,x)!=0) 
    if (strcmp(x,tmp->name)<0) {
      p = tmp;
      tmp = tmp->left;
    } else {
      p = tmp;
      tmp = tmp->right;
    }

  if (tmp != NULL) {
    if (p->left == tmp) {
      p->left = removeRootBST(tmp);
    }
    else {
      p->right = removeRootBST(tmp);
    }
  }
  return t;
}

void inOrder(tree t){ 
	if(!isNullTree(t)){
		inOrder(t->left);
		printf("%d ", t->name);
		inOrder(t->right);
	}
}

void inOrderPrint(tree t){ 
	if(!isNullTree(t)){
		inOrderPrint(t->left);
		printf("%s\t%.1lf\t%s\n",t->name, t->total, t->accounts[0].phone);
		inOrderPrint(t->right);
	}
}

void postOrder(tree t){
	if(!isNullTree(t)){
		postOrder(t->left);
		postOrder(t->right);
		printf("%d ", t->name);
	}
}
void preOrder(tree t){
	if(!isNullTree(t)){
		printf("%d ", t->name);
		preOrder(t->left);
		preOrder(t->right);
	}
}

tree reverse(tree t){
	tree tmp;
	if (t!=NULL){
		reverse(t->left);
		reverse(t->right);
		tmp = t->left;
		t->left=t->right;
		t->right=tmp;
	}
	return t;
}

void finOrderPrint(tree t, FILE *fp){ 
	if(!isNullTree(t)){
		finOrderPrint(t->left,fp);
		fprintf(fp,"%s\t%.1lf\t%s\n",t->name, t->total, t->accounts[0].phone);
		finOrderPrint(t->right,fp);
	}
}


