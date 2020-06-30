#ifndef _TREE_H_
#define _TREE_H_

struct Account{
	char name[30];
	char phone[15];
	double balance;	
};

typedef char* element_t;

struct TreeNode{
	char name[30];
	struct Account accounts[5];
	int numAccount;
	double total;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode* tree; //AccountDB
tree t;
int n;

tree createNullTree();
tree createLeaf(char* x, struct Account* acc);
tree createTree(char *name, struct Account *acc, tree l, tree r);
int isNullTree(tree t);
int isLeaf(tree t);
int sizeOfTree(tree t);
int sumOfTree(tree t);


struct TreeNode* leftMost(tree t);
struct TreeNode* rightMost(tree t);

tree addToLeftMost(tree t, element_t x, struct Account* acc);
tree addToRightMost(tree t, element_t x, struct Account* acc); 


#endif
