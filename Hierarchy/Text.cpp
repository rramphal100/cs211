//Ryan Ramphal, CS211, HW#8

#include "Text.h"
#include <iostream>

Text::Text(){
   setName("");
   setType("txt");
   chars = 0;
}

Text::Text(std::string n, int c){
   setName(n);
   setType("txt");
   chars = c;
}

const int Text::getSize() const{
   return chars;
}

const int Text::getCount() const{
   return chars;
}

void Text::display() const{
   std::cout << "Name: " << getName() << std::endl;
   std::cout << "Type: " << getType() << std::endl;
   std::cout << "Number of Characters: " << getCount() << " Characters\n";
   std::cout << "Size: " << getSize() << " Bytes\n\n";
}