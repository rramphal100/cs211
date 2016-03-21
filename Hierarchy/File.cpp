//Ryan Ramphal, CS211, HW#8

#include "File.h"

const std::string File::getName() const{
   return name;
}

const std::string File::getType() const{
   return type;
}

void File::setName(std::string n){
   name = n;
}

void File::setType(std::string t){
   type = t;
}