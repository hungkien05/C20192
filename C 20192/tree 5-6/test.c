#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "tree.c"

int main() {
//  tree t = createTree(1,
//		      createTree(2,
//					 createLeaf(6),
//					 createNullTree()),
//		      createTree(3,
//				   createLeaf(4),
//				   createLeaf(5)));
//  char *s;
//  printf("size = %d\n", sizeOfTree(t));
//  printf("sum = %d\n", sumOfTree(t));
//  s = treeToString(t);
//  printf("%s\n", s);
//  free(s);
//  inOrder(t);

//  t=reverse(t);
//  s = treeToString(t);
//  printf("%s\n", s);
//  free(s);
//  inOrder(t);
  
  // printf("left most:%d\n", value(leftMost(t)));
  // printf("right most:%d\n", value(rightMost(t)));

  // t = addToLeftMost(t, 6);
  // t = addToRightMost(t, 7);

  // s = treeToString(t);
  // printf("%s\n", s);
  // free(s);

//--------------
//  printf("Height:%d\n", height(t));
//  printf("Leaves count:%d\n", leavesCount(t));
//  printf("Inner node count:%d\n", innerNodeCount(t));
//  printf("Right children count:%d\n", rightChildCount(t));


//-------------
  int a[5]={3,6,2,7,4}; //BST
  int i;
  tree t = createNullTree();
  for ( i = 0; i < 5; ++i)   {
    t= insertBST(t,a[i]);
  }

  char *s;
  s = treeToString(t);
  printf("%s\n", s);
  t=removeBST(t,6);
  s = treeToString(t);
  printf("%s\n", s);
  free(s);
  


  return 0;
}
