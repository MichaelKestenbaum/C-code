#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
   // Initialize the board to 0
   int q[8], c=0;

   // Start in the 1st row, 1st column, and place a queen there

   q[0]=0;

nextCol:
   // Move to the next column
   c++;

   if (c>7)  //you have passed the last column
      goto print;

   // Move to one before the first row
   q[c] = -1;

nextRow:
   // Move to the next row
   q[c]++;

   if (q[c]>7)  //you have passed the end of the column
      goto backtrack;

   // If there is a queen in the same row (to the left), goto nextRow
   for (int i = 0; i<c; i++)  //each square to the left of the current square
      if (q[c]==q[i]||c-i==abs(q[c]-q[i]))  //there is a queen on that square
         goto nextRow;




   goto nextCol;

backtrack:
   // Move to the previous column
   c--;

   if (c<0) //you have moved to the left of the chessboard
      return 0;  //exit the program
      
  
   goto nextRow;

print:
   static int numSolutions = 0;
   cout << "Solution #" << ++numSolutions << ":\n";
   for (int i = 0; i<8; i++){ // Use a nested loop to print the chessboard
   		for (int j=0; j<8; j++){
   			if (q[i]==j) cout << 1;
		   	else cout << 0;
	}
 		cout << endl;
	}	
   goto backtrack;
}

