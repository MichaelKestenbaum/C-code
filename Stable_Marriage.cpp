#include <iostream>
#include <cmath>
using namespace std;

// Returns true if the number in column c is ok
bool ok(int q[], int c) {
   static int mp[3][3] = { {0,2,1},  // Man#0's preferences
                        {0,2,1},  // Man#1's preferences
                        {1,2,0}}; // Man#2's preferences

   static int wp[3][3] = { {2,1,0},  // Woman#0's preferences
                        {0,1,2},  // Woman#1's preferences
                        {2,0,1}}; // Woman#2's preferences
   for (int i=0; i<c; i++)  //each i from 0 to c-1
   	  if (q[c]==q[i]) 
        return false;
   for (int i=0; i<c; i++){
 	  if (mp[i][q[c]] < mp[i][q[i]] && wp[q[i]][c] < wp[q[i]][i] || mp[c][q[i]] < mp[c][q[c]] && wp[q[c]][i] < wp[q[c]][c])
	    return false;  	 
   }
   return true;
}

void print(int q[]) {
   static int solution = 0;
   cout << "Solution #" << ++solution << ":\nMan\tWoman\n";
   for (int i = 0; i < 3; ++i)
      cout << i << "\t" << q[i] << "\n";
   cout << "\n";
}

int main() {
   int q[3]={}, c=0;   // Initialize the array to 1.
  
   // Start in the 1st row, 1st column
   while (c >= 0) { // End the loop if you backtrack from the first column
	  c++;  // Move to the next column
      if (c>2){ // If you have passed the last column,
         print(q);// Call the print function and backtrack
	     c--;
	  }
	  else q[c]=-1;  // Otherwise, move to one before the first row
	  
      while (c >= 0) {
      	
         q[c]++;  // Move to the next row
         if (q[c]>2)// If you have passed the end of the column, backtrack
        	c--;
       	 else if (ok(q,c)==true) break;// Otherwise, call the ok function.  If it returns true, go back to the beginning of the outer loop.
      }
   }
   return 0;
}
