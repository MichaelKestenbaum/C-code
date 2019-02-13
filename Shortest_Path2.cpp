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
// Returns the cost of the shortest path from the left to the square in row i, column j.
int CalculateCost(int i, int j) {
   static int weight[NUM_ROWS][NUM_COLS] = {{3,4,1,2,8,6},
                                            {6,1,8,2,7,4},
                                            {5,9,3,9,9,5},
                                            {8,4,1,3,2,6},
                                            {3,7,2,8,6,4}};
   // Declare the cost matrix.
   static int cost[NUM_ROWS][NUM_COLS]={};
   // If the cost has already been calculated, return it.
   //_____
   // Check for the base case.
   if (j == 0) {
      path[i][j] = to_string(i);
      return cost[i][j]=weight[i][0];
   }
   if (cost[i][j]!=0) return cost[i][j];
   // Calculate the costs of the 3 adjacent squares by calling the function recursively.
   int left = CalculateCost (i, j-1);
   int up = CalculateCost ((i+4)%5, j-1);
   int down = CalculateCost ((i+1)%5, j-1);
   // Find the minimum of the 3 costs.
   int minCost =min(left, up, down);
   // Update the path matrix (store the path to the current square in path[i][j]):
   // If up is the minimum, get the shortest path to the up-left square from the path matrix and concatenate it with the current row.
	if (minCost==up)
      path[i][j] = (path[(i-1+5)%5][j-1]) + to_string(i);
   // If left is the minimum...
    if (minCost==left)   
	  path[i][j] = (path[(i)][j-1]) + to_string(i);
   // If down is the minimum...
    if (minCost==down)
      path[i][j] = (path[(i+1)%5][j-1]) + to_string(i);
   // Calculate the cost of the current square, store the correct number in the cost matrix, and return the cost.
   return minCost+weight[i][j];
}

int main() {
   int ex[NUM_ROWS];
   int minRows = 0;
   // Call the calculateCost function once for each square in the rightmost column of the grid.
   // Check which one has the lowest cost and store the row number in minRow.
   for( int i=0; i<NUM_ROWS; i++)
	 ex[i]=CalculateCost(i,NUM_COLS-1);
   int minWeight;	 
	 for( int i=1; i<NUM_ROWS; i++){
	 	if (ex[i]<ex[minRows]){
	 		minRows = i;
	 		minWeight=ex[i];
	 		
	 	} 
	 }
   cout << "The length of the shortest path is " << minWeight<< " leaving from " << minRows;
   cout << ".\nThe rows of the path from left to right are " << path[minRows][NUM_COLS-1] << ".";

   return 0;
}
