#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int rows = 5;
const int cols = 6;


	 


int main(){
	 int weight[rows][cols]={
	 {3,4,1,2,8,6},
	 {6,1,8,2,7,4},
	 {5,9,3,9,9,5},
	 {8,4,1,3,2,6},
	 {3,7,2,8,6,4}};
	 
	 vector<int> path[1];
	 
	 static int memo[rows][cols]={};
	 path[1].push_back(-1);
	 
	 for (int r=0; r<rows; r++){
     	for (int c=0; c<cols; c++){
	 		 if (c==0) memo[r][c]=weight [r][c];
	 		 else memo[r][c]=  weight [r][c] + min (memo[r][c-1], memo[(r-1)%5][c-1], memo[(r+1)%5][c-1]);
	 	}
	 }
	 //	cout << memo[1][5]; 
	 int minimum = memo[0][5];
	 for (int i=1; i<rows; i++)
	 	if (memo[i][5]<minimum) minimum=memo[i][5]; 
	 	
	 cout << "the shortest path is: " << minimum << endl;
	 cout << "the path is: ";
	 while (minimum > 0){
	 	for (int r = rows; r>-1; r--){
	 		for (int c = cols; c>-1; c--){
	 			if (memo[r][c]== minimum){
	 				path[1].push_back(r);
	 				minimum-= weight[r][c];
	 			}
	 		}
	 	}
	 }
	 
	 while (path[1].back()!=-1){
	 	cout << path[1].back();
	 	path[1].pop_back();
	 }	
	 return 0;
}
