#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int NUM_ROWS = 5, NUM_COLS = 6;
string path[NUM_ROWS][NUM_COLS];

int min(int a, int b, int c){
	int smallest = a;
	if (b < smallest) smallest = b;
	if (c < smallest) smallest = c;
	return smallest;
}



// Calculates the cost of every square and fills in the cost matrix.
void calculateCosts() {
   static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},
                                            {6,1,8,2,7,4},
                                            {5,9,3,9,9,5},
                                            {8,4,1,3,2,6},
                                            {3,7,2,8,6,4}};
   // Declare the cost matrix.
   static int cost[NUM_ROWS][NUM_COLS]={};
   // Copy the leftmost column of the weight matrix to the cost matrix, and initialize the leftmost column of the path matrix.
   for (int i=0; i<NUM_ROWS; i++){
   		 cost[i][0]=weight[i][0];
   		 path[i][0] = to_string(i);
   }
   // For each remaining column,
      // Calculate the cost of each square in the column (non-recursively),
      // and store the correct number in the cost matrix and the correct string in the path matrix.
      int small;
   for(int j=1; j<6;j++){
		for (int i = 0;i<5;i++){
   			small = min(cost[(i+4)%5][j-1], cost[i][j-1], cost[(i+1)%5][j-1]);
   			cost[i][j]=weight[i][j]+small;
   	
   if (small==cost[(i+4)%5][j-1])
      path[i][j] = (path[(i-1+5)%5][j-1]) + to_string(i);
   // If left is the minimum...
   if (small==cost[i][j-1])   
	  path[i][j] = (path[(i)][j-1]) + to_string(i);
   // If down is the minimum...
   if (small==cost[(i+1)%5][j-1])
      path[i][j] = (path[(i+1)%5][j-1]) + to_string(i);
   // Calculate the cost of the current square, store the correct number in the cost matrix, and return the cost.
		}
	}
   int minRow = 0;
   // Check which square in the rightmost column has the lowest cost.  Store the row number of that square in minRow.
   for (int i = 1; i < NUM_ROWS; i++)
   		if (cost[i][5]<cost[minRow][5]) minRow = i;
   
   cout << "The length of the shortest path is " << cost[minRow][NUM_COLS-1];
   cout << ".\nThe rows of the path from left to right are " << path[minRow][NUM_COLS-1] << ".";
}

int main() {
   calculateCosts();

   return 0;
}
