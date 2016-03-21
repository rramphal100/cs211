//Ryan Ramphal, CS211, HW#8

#include <iostream>
#include "Image.h"
#include "Text.h"

using namespace std;

int main(){
   Text x("Text File", 200);
   Image y("Image File", 400, 400, 8);
   x.display();
   y.display();
   return 0;
}