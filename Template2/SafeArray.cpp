//Ryan Ramphal
//CS211
//HW#7

#include "SafeArray.h"
#include <iostream>

using namespace std;

template <class T>
SafeArray<T>::SafeArray()
{
   size = 0;
   array = NULL;
}

template <class T>
SafeArray<T>::SafeArray(int s)
{
   size = s;
   array = new T[size];
}

template <class T>
int SafeArray<T>::length() const
{
   return size;
}

template <class T>
T& SafeArray<T>::operator [] (int index)
{
   if (index < 0 || index >= size)
   {
      cerr << "Index: " << index << " is out of bounds." << endl;
      system("PAUSE");
      exit(1);
   }
   return array[index];
}


template <class T>
SafeArray<T>::~SafeArray()
{
   if (array != NULL)
      delete[] array;
}

template <class T>
SafeArray<T>& SafeArray<T>::operator = (const SafeArray<T>& other)
{
   if (this != &other)
   {
      if (array != NULL)
      {
         delete[] array;
      }

      size = other.size;
      array = new T[size];
      for (int i = 0; i < size; i++)
      {
         array[i] = other.array[i];
      }
   }

   return *this;
}

template <class T>
SafeArray<T>::SafeArray(const SafeArray<T>& other)
{
   size = other.size;
   array = new T[size];
   for (int i = 0; i < size; i++)
   {
      array[i] = other.array[i];
   }
}