//Ryan Ramphal, CS211, HW#8

#ifndef TEXT_H
#define TEXT_H

#include "File.h"

class Text : public File{
private:
   int chars; //number of characters in the file

public:
   Text();
   Text(std::string, int);
   virtual const int getSize() const;
   const int getCount() const;
   virtual void display() const;
};
#endif