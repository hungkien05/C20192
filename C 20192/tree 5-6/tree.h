#ifndef _TREE_H_
#define _TREE_H_

typedef int element_t;

struct TreeNode{
	element_t data;
	struct TreeNode *left;
	struct TreeNode *right;
};

typedef struct TreeNode* tree;

tree createNullTree();
tree createLeaf(element_t x);
tree createTree(element_t x, tree l, tree r);
int isNullTree(tree t);
int isLeaf(tree t);
int sizeOfTree(tree t);
int sumOfTree(tree t);


struct TreeNode* leftMost(tree t);
struct TreeNode* rightMost(tree t);

tree addToLeftMost(tree t, element_t x);
tree addToRightMost(tree t, element_t x); 


#endif
