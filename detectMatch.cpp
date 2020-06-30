#include <stdlib.h>
#include <stdio.h>

int main() {
int currentMatch;int k;
int tiles[8][8] = { 
	{1,2,3,4,5,6,7,8},
	{8,7,6,5,4,3,2,1},	
	{1,2,3,4,5,6,7,8},
	{8,7,6,5,4,3,2,1},	
	{1,2,3,4,5,6,7,8},
	{8,7,6,5,4,9,2,1},	
	{1,2,3,4,5,9,7,8},
	{8,8,8,5,4,9,2,1},				


};
scanf("%d", &k);
//tiles[0] = {1,2,3,4,5,6,7,8};
//tiles[1] = {8,7,6,5,4,3,2,1};
printf("%d\n", tiles[0][1]);


//for (int i = 0; i < 8; i++) 
//        for (int j = 0; j < 8; j++) 
//        	scanf("%d",tiles[i,j]);
        	
        	
        	
 for (int i = 0; i < 8; i++) {
        currentMatch = 0;
        for (int j = 0; j < 8; j++) {
        	//printf("dmm\n");
            if (tiles[i][j] == tiles[i][j+1]) {
                currentMatch++;
            } else {
                if (currentMatch >= 2){
                    printf("%d %d\n", i, j);
                    //fall.run();
                }
                currentMatch = 0;
        
            }
        }
    }
}
