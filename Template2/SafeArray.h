//Ryan Ramphal
//CS211
//HW#7

#ifndef SAFE_ARRAY_H
#define SAFE_ARRAY_H

template <class T>
class SafeArray
{
private:
   T* array;
   int size;

public:
   SafeArray();
   SafeArray(int s);
   int length() const;
   T& operator [] (int index);
   ~SafeArray();
   SafeArray(const SafeArray<T>& other);
   SafeArray<T>& operator = (const SafeArray<T>& other);
};

#endif