// Rat class i.e. a class for rational numbers
#include <iostream>
#include <cmath>
using namespace std;


int gcd(int n, int d){
      if (d<0){
      	d*=-1;
      	n*=-1;
      } 
      int m; 
      if (n>d){
      	 m = n/d;
      	 n=n%d;
      }
      while (d%n!=0){
      	int t = n;
      	n=d%n;
      	d=t;
	  }
	  return n;
}

class Rat{
private:
   int n;
   int d;
   
public:
   // constructors
   
   // default constructor
   Rat(){
      n=0;
      d=1;
   }
   
   // 2 parameter constructor
   Rat(int i, int j){
      n=i;
      d=j;
   }
   
   // conversion constructor
   Rat(int i){
      n=i;
      d=1;
   }
   
   //accessor functions (usually called get() and set(...) )
   int getN(){ return n;}
   int getD(){ return d;}
   
   void setN(int i){ n=i;}
   void setD(int i){ d=i;}
   
   //arithmetic operators
   Rat operator+(Rat r){
      Rat t;
      t.n = n*r.d + d*r.n;
      t.d = d*r.d;
      return t;
   }
   
   // Write the other 3 operators (operator-, operator*, operator/).
   Rat operator-(Rat r){
      Rat t;
      t.n = n*r.d - d*r.n;
      t.d = d*r.d;
      return t;
   }
   
   Rat operator*(Rat r){
      Rat t;
      t.n = n*r.n;
      t.d = d*r.d;
      return t;
   }
   
   Rat operator/(Rat r){
      Rat t;
      t.n = n*r.d;
      t.d = d*r.n;
      return t;
   }
   
   // Write a function to reduce the Rat to lowest terms, and then you can call this function from other functions.
   // Also make sure that the denominator is positive.  Rats should be printed in reduced form.
   
   // Calculate the GCD (Euclid's algorithm)
   

   // 2 overloaded i/o operators
   friend ostream& operator<<(ostream& os, Rat r);
   friend istream& operator>>(istream& is, Rat& r);
}; //end Rat

// operator<<() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
ostream& operator<<(ostream& os, Rat r){
   // Rewrite this function so that improper fractions are printed as mixed numbers.  For example:
   if (r.d<0){
      	r.d*=-1;
      	r.n*=-1;
  }
   // 0/1 should be printed as 0 
   if (r.n == 0) os << 0 << endl;
   // 2/1 should be printed as 2
   else{ if (r.n%r.d==0) os << r.n/r.d;
   // 3/2 should be printed as 1 1/2
   		 else{ 
   			if (r.n/r.d == 0) os << (r.n%r.d) / gcd (r.n,r.d) << "/" << r.d / gcd (r.n,r.d) << endl; 
   			else os << r.n/r.d << " " << (r.n%r.d) / gcd (r.n,r.d) << "/" << r.d / gcd (r.n,r.d) << endl;
   		 }
   }
   			
    
   // 1/2 should be printed as 1/2
  // else if (r.n%r.d==0) os << r.n / gcd (r.n,r.d) << "/" << r.d / gcd (r.n,r.d) << endl;
  
   
   // Negative numbers should be printed the same way, but beginning with a minus sign
   return os;
}

// operator>>() is NOT a member function but since it was declared a friend of Rat
// it has access to its private parts.
istream& operator>>(istream& is, Rat& r){
   is >> r.n >> r.d;
   return is;
}

int main() {
   Rat r1(5, 2), r2(3, 2);
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2;
   r2 = r1 * r2;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   cout << endl;
   
   r1 = r2 + r1 * r2 / r1;
   r2 = r2 + r1 * r2 / r1;
   
   cout << "r1: " << r1 << endl;
   cout << "r2: " << r2 << endl;
   cout << "r1 + r2: " << r1 + r2 << endl;
   cout << "r1 - r2: " << r1 - r2 << endl;
   cout << "r1 * r2: " << r1 * r2 << endl;
   cout << "r1 / r2: " << r1 / r2 << endl;
   
   return 0;
}
