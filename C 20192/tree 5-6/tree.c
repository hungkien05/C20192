#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "tree.h"

tree createNullTree(){
	return (tree)NULL;
}

tree createTree(element_t x, tree l, tree r){
	tree t = (struct TreeNode*)malloc(sizeof(struct TreeNode));
	t->data=x;
//	if (l!=NULL) 
		t->left=l;
//	if (r!=NULL) 
		t->right=r;
}

tree createLeaf(element_t x){
	return createTree(x, createNullTree(), createNullTree());
}

int isNullTree(tree t){
	return (t==NULL);
}

int isLeaf(tree t){
	return (t!=NULL && t->left==NULL && t->right==NULL);
}

int sizeOfTree(tree t){
	if (isNullTree(t)) return 0;
	else {
		return (1+sizeOfTree(t->left)+sizeOfTree(t->right));
	}
}
int sumOfTree(tree t){
	if (isNullTree(t)) return 0;
	else {
		return (t->data+sumOfTree(t->left)+sumOfTree(t->right));
	}
}
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
    result = (char*)malloc(4);
    strcpy(result, "Nil");
    return result;
  } else {
    left = treeToString(t->left);
    right = treeToString(t->right);
    
    result = (char*)malloc(40 + strlen(left) + strlen(right));
    sprintf(result, "node(%d,%s,%s)", t->data, left, right);
    free(left);
    free(right);
    return result;
  }
}

tree addToLeftMost(tree t, element_t x) {
  tree n = leftMost(t);
  
  if (isNullTree(t))
    return createLeaf(x);
  else {
    n->left = createLeaf(x);
    return t;
  }
}

tree addToRightMost(tree t, element_t x) {
  tree n = rightMost(t);
  
  if (isNullTree(t))
    return createLeaf(x);
  else {
    n->right = createLeaf(x);
    return t;
  }
}

element_t value(tree t) {
  if (isNullTree(t))
    return 0;
  else return t->data;
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

tree insertBST(tree t, element_t x){
	if (t==NULL) {
		t=createTree(x,NULL,NULL);
		return t;
	} else{
		if(x< t->data)  {
			t->left=insertBST(t->left, x);
			return t;
		}
		if(x> t->data) {
			t->right=insertBST(t->right, x);
			return t;
		}
	}

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

  t->data = tmp->data;
  tmp = removeRootBST(tmp);
  if (p == t)
    p->right = tmp;
  else
    p->left = tmp;
  return t;
}

tree removeBST(tree t, element_t x) {
  tree p, tmp;
  
  if (isNullTree(t))
    return NULL;

  if (t->data == x)
    return removeRootBST(t);

  p = NULL;
  tmp = t;
  while ((tmp != NULL) && (tmp->data != x)) 
    if (tmp->data > x) {
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
		printf("%d ", t->data);
		inOrder(t->right);
	}
}

void postOrder(tree t){
	if(!isNullTree(t)){
		postOrder(t->left);
		postOrder(t->right);
		printf("%d ", t->data);
	}
}
void preOrder(tree t){
	if(!isNullTree(t)){
		printf("%d ", t->data);
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


