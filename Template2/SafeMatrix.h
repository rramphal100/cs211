//Ryan Ramphal
//CS211
//HW#7

#ifndef SAFEMATRIX_H
#define SAFEMATRIX_H

#include "SafeArray.h"
#include "SafeArray.cpp" //no separate compilation with template files!

template<class T>
class SafeMatrix{
private:
   SafeArray<SafeArray<T>>* array2d;
   int size; //# of rows in the 2D array

public:
   SafeMatrix();
   SafeMatrix(int, int); //constructor for rows, columns
   int length() const;
   SafeArray<T>& operator [] (int);

   //big 3:
   SafeMatrix<T>& operator = (const SafeMatrix<T>& other);
   SafeMatrix(const SafeMatrix<T>& other);
   ~SafeMatrix();
};


#endif