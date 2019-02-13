#include <iostream>
#include <cmath>
using namespace std;

// Returns true if the queen in column c is ok
bool ok(int q[], int c) {
   for (int i=0; i<c; i++)  //each i from 0 to c-1
      if (q[c]==q[i]||c-i==abs(q[c]-q[i]))  //there is a conflict between the queens in columns i and c
         return false;
   return true;
}

void print(int q[]) {
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ":\n";
   for (int i = 0; i<8; i++){ // Use a nested loop to print the chessboard
   		for (int j=0; j<8; j++){
   			if (q[i]==j) cout << 1;
		   	else cout << 0;// Print the array
		}
  	    cout << "\n";
   }
   return;
}

int main() {
   int q[8]={}, c=0;   // Initialize the array to 0.
   // Start in the 1st row, 1st column
   while (c >= 0) { // End the loop if you backtrack from the first column
	  c++;  // Move to the next column
      if (c>7){ // If you have passed the last column,
         print(q);// Call the print function and backtrack
	     c--;
	  }
	  else q[c]=-1;  // Otherwise, move to one before the first row
	  
      while (c >= 0) {
         q[c]++;  // Move to the next row
         if (q[c]>7)// If you have passed the end of the column, backtrack
        	c--;
       	 else if (ok(q,c)==true) break;// Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
      }
   }
   return 0;
}
