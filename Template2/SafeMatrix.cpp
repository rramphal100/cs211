//Ryan Ramphal
//CS211
//HW#7

#include "SafeMatrix.h"
#include <iostream>

template<class T>
SafeMatrix<T>::SafeMatrix(){
   array2d = new SafeArray < SafeArray<T> >();
   size = 0;
}

template<class T>
SafeMatrix<T>::SafeMatrix(int r, int c){
   array2d = new SafeArray<SafeArray<T>>(r);
   size = r;
   for (int i = 0; i < size; i++){
      (*array2d)[i] = SafeArray<T>(c);
      //need to de-reference array2d since it is a pointer to a single SafeArray object. only then does it use the proper [] operator overload
      //for the stored SafeArrays
   }
}

template<class T>
int SafeMatrix<T>::length() const{
   return size;
}

template<class T>
SafeArray<T>& SafeMatrix<T>::operator [] (int x){
   if (x >= size || x < 0){
      std::cerr << "Error: Index out of bounds.\n";
      system("PAUSE");
      exit(1);
   }
   else return (*array2d)[x];
}

template<class T>
SafeMatrix<T>& SafeMatrix<T>::operator = (const SafeMatrix<T>& other){
   if (this != &other){
      if (array2d != NULL){
         for (int i = 0; i < size; i++){
            delete (*array2d)[i];
         }
         delete array2d;
      }

      size = other.size;
      int subsize = other[0].length(); //stores the # of columns in the "other" safematrix instead of calculating each time in the for loop
      array2d = new SafeArray<SafeArray<T>>(size);
      for (int i = 0; i < size; i++){
         (*array2d)[i] = SafeArray<T>(subsize);
         for (int j = 0; j < subsize; j++){
            this[i][j] = other[i][j];
         }
      }
   }
   return *this;
}

template<class T>
SafeMatrix<T>::SafeMatrix(const SafeMatrix& other){
   size = other.size;
   int subsize = other[0].length(); //stores the # of columns in the "other" safematrix instead of calculating each time in the for loop
   array2d = new SafeArray < SafeArray<T> >(subsize);
   for (int i = 0; i < size; i++){
      (*array2d)[i] = SafeArray<T>(subsize);
      for (int j = 0; j < subsize; j++){
         array2d[i][j] = other.array2d[i][j];
      }
   }
}

template<class T>
SafeMatrix<T>::~SafeMatrix(){
   if (array2d != NULL){
      delete array2d;
   }
}