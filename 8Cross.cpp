#include <iostream>
#include <cmath>
using namespace std;

// Returns true if the number in column c is ok
bool ok(int q[], int c) {
	static int adj[8][5] = {          // static, so it is only initialized once
   {-1},                 // 0
   {0, -1},              // 1
   {0, 1, -1},           // 2
   {0, 2, -1},           // 3     <-- neighbor list for square 3
   {1, 2, -1},           // 4
   {1, 2, 3, 4, -1},     // 5
   {2, 3, 5, -1},        // 6
   {4, 5, 6, -1}         // 7
   };
   for (int i=0; i<c; i++)  //each i from 0 to c-1
   	  if (q[c]==q[i]) 
        return false;
   for (int i=0; adj[c][i] != -1; i++){
 	  if (q[c]==(q[adj[c][i]]+1) || q[c]==(q[adj[c][i]]-1))
	    return false;  	 
   }
   return true;
}

void print(int q[]) {
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ":\n";
   cout << " " << q[1] << q[4] << endl;
   cout << q[0] << q[2] << q[5] << q[7] << endl;
   cout << " " << q[3] << q[6] << endl;
   cout << endl;
   
   return;
}

int main() {
   int q[8]={1}, c=0;   // Initialize the array to 1.
  
   // Start in the 1st row, 1st column
   while (c >= 0) { // End the loop if you backtrack from the first column
	  c++;  // Move to the next column
      if (c>7){ // If you have passed the last column,
         print(q);// Call the print function and backtrack
	     c--;
	  }
	  else q[c]=0;  // Otherwise, move to one before the first row
	  
      while (c >= 0) {
      	
         q[c]++;  // Move to the next row
         if (q[c]>8)// If you have passed the end of the column, backtrack
        	c--;
       	 else if (ok(q,c)==true) break;// Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
      }
   }
   return 0;
}
