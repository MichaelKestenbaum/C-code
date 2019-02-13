#include <iostream>
#include <cmath>
using namespace std;

bool ok(int q[], int c) {
   // Reuse the ok function from your 1D 8 queens program.
    for (int i = 0; i < c; ++i)
      if (q[i] == q[c] || abs(q[i] - q[c]) == c - i)
         return false;
   return true;
}

// This function should return the number of solutions for the given board size (you don't need to print the solutions).
int nqueens(int n) {
   // Dynamically declare an array of size n and initialize the first element to 0.
   // Reuse the code from your 1D 8 queens program to find the solutions (you may have to make changes).
   // Delete the array.
   // Return the number of solutions.
   int* q = new int[n];
   int c=0, count = 0;   // Initialize the array to 0.
   for (int i=0; i<n; i++)
   	  q[i]=0;
   // Start in the 1st row, 1st column
   while (c >= 0) { // End the loop if you backtrack from the first column
	  c++;  // Move to the next column
      if (c>n-1){ // If you have passed the last column,
         count ++;
	     c--;
	  }
	  else q[c]=-1;  // Otherwise, move to one before the first row
	  
      while (c >= 0) {
         q[c]++;  // Move to the next row
         if (q[c]>n-1)// If you have passed the end of the column, backtrack
        	c--;
       	 else if (ok(q,c)==true) break;// Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
      }
   }
   delete [ ] q;
   return count;
}

int main() {
   int n = 12;
   for (int i = 1; i <= n; ++i)
      cout << "There are " << nqueens(i) << " solutions to the " << i << " queens problem.\n";
   return 0;
}
