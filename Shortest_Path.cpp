#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

const int rows = 5;
const int cols = 6;
vector<int> path;



int cost(int i, int j){ // i is the row, j is the column
	 int weight[rows][cols]={
	 {3,4,1,2,8,6},
	 {6,1,8,2,7,4},
	 {5,9,3,9,9,5},
	 {8,4,1,3,2,6},
	 {3,7,2,8,6,4}};
	 
   	 static int memo[rows][cols]={};
   	 

 	//base case
	 if(j==0)
	 return weight[i][0];

	 // recursive call
	 int left = cost (i, j-1);
	 int up = cost ((i-1)%5, j-1);
 	 int down = cost ((i+1)%5, j-1);

	 // find the value of the shortest path through cell (i,j)
	 int minimum = weight[i][j] + min (left, up, down);
	 
	 for (int r=0; r<rows; r++){
	 	for (int c=0; c<cols; c++){
	 		if (c==0) memo[r][c]=weight [r][c];
	 		else memo[r][c]= min (memo[r][c-1], memo[(r-1)%5][c-1], memo[(r+1)%5][c-1]) + weight [r][c];
	 	}
     }
    /* for( int r=0; r<rows; r++){
	 	for( int c=0; c<cols; c++)
	 		cout << memo[c][r];
	 	 cout << endl;
	 }
	 */
	 path.push_back(-1);
	 int fin = minimum;
	 	
	 for( int r=0; r<rows; r++){
	 	for( int c=0; c<cols; c++){
	 		if (fin == memo[r][c]){
	 			path.push_back(r);
	 			fin-=weight[r][c];
	 		}
	 	}
	 }

	

	 return minimum;
	 }

int main(){
	 int ex[rows];

	 // get the shortest path out of each cell on the right
	 for( int i=0; i<rows; i++)
	 ex[i]=cost(i,cols-1);

	 // now find the smallest of them
	 int minimum=ex[0];
	 for( int i=1; i<rows; i++){
	 	if (ex[i]<minimum) minimum = ex[i];
	 }
	

//	…some code goes here

	 cout<<"the sortest path is of length "<<minimum<<endl;
	 cout << "the path is: ";
	 while (path.back()!=-1){
	 	cout << path.back();
	 	path.pop_back();
	 }
	 return 0;

} 
