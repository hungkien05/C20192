#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int search_tp( int key,int r[], int n ) 
{ 
  int i; 
	int tempr;
	for ( i=0; i<n && r[i] != key; i++ );
	if ( key == r[i] ) 
	{ if ( i>0 ) {
 /*** Transpose with predecessor ***/ 
	tempr = r[i]; 
	r[i] = r[i-1];
	r[--i] = tempr; 
	}; 
	return( i ); 
	} else return( -1 ); 
}

int search_front( int key,int r[], int n ){ //move to front  
	int i,j; 
	int tempr;
	for ( i=0; i<n-1 && r[i] != key; i++ );
	if ( key == r[i] ) 
	{ if ( i>0 ) {
		tempr = r[i]; 
		for (j=i-1; j>=0; j--) r[j+1]=r[j];
		r[0]=tempr; 
	}; 
	return( i ); 
	} else return( -1 ); 
}

int main(){
	int r[]={1,2,3,4,5,6,7,8,9};
	printf("%d\n", r[search_tp(3,r,9)]);
	int i;
	for (i=0; i<9; i++){
		printf("%d ", r[i]);
	}
}





