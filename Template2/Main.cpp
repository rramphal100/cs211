//Ryan Ramphal
//CS211
//HW#7

#include <iostream>
#include <string>
#include "SafeMatrix.h"
#include "SafeMatrix.cpp"
using namespace std;

int main(){
   SafeMatrix<int> x(2, 3); //test with integer type
   cout << "Safe Matrix of integers:\n" << x.length() <<" " << x[0].length() << endl << endl;

   x[0][0] = 1;
   x[0][1] = 2;
   x[0][2] = 3;
   x[1][0] = 4;
   x[1][1] = 5;
   x[1][2] = 6;

   for (int i = 0; i < 2; i++){
      for (int j = 0; j < 3; j++){
         cout << x[i][j] << " ";
      }
   }
   cout << endl << endl;

   SafeMatrix<string> y(1, 2); //test with string type
   cout << "Safe Matrix of strings:\n" << y.length() << " " << y[0].length() << endl << endl;

   y[0][0] = "Hello ";
   y[0][1] = "there.";

   cout << y[0][0] << y[0][1] << endl << endl;

   SafeMatrix<char> z(2, 2);
   cout << "Safe Matrix of characters:\n" << z.length() << " " << z[0].length() << endl << endl;

   char insert = 'a';
   for (int i = 0; i < 2; i++){
      for (int j = 0; j < 2; j++) z[i][j] = insert++;
   }

   for (int i = 0; i < 2; i++) cout << z[i][0] << " " << z[i][1] << " ";
   cout << endl << endl;

   system("PAUSE");
   return 0;
}