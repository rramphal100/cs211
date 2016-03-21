//Ryan Ramphal, CS211, HW#9

#ifndef FILE_H
#define FILE_H

#include <string>

class File{
private:
   std::string name;
   std::string type;
public:
   const std::string getName() const;
   const std::string getType() const;
   virtual const int getSize() const = 0;

   void setName(std::string);
   void setType(std::string);

   virtual void display() const = 0;
};

#endif