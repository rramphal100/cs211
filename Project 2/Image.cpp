//Ryan Ramphal, CS211, Project 2

#include "Image.h"
#include <iostream>

Image::Image(){
   setName("");
   setType("gif");
   rows = 0;
   columns = 0;
   color_depth = 0;
}

Image::Image(std::string name){
   setName(name);
   setType("gif");
   rows = 0;
   columns = 0;
   color_depth = 0;
}

Image::Image(std::string n, int r, int c, int cd){
   setName(n);
   setType("gif");
   rows = r;
   columns = c;
   color_depth = cd;
}

const int Image::getRows() const{
   return rows;
}

const int Image::getColumns() const{
   return columns;
}

const int Image::getColorDepth() const{
   return color_depth;
}

const int Image::getSize() const{
   return rows*columns*color_depth / 8;
}

void Image::setRows(int r){
   while (r < 1){
      std::cout << "Error: invalid row amount. Please try again.: ";
      std::cin >> r;
   }
   rows = r;
}

void Image::setColumns(int c){
   while (c < 1){
      std::cout << "Error: invalid column amount. Please try again.: ";
      std::cin >> c;
   }
   columns = c;
}

void Image::setColorDepth(int cd){
   while (cd < 1){
      std::cout << "Error: invalid color depth amount. Please try again.: ";
      std::cin >> cd;
   }
   color_depth = cd;
}

void Image::display() const{
   std::cout << "Name: " << getName() << std::endl;
   std::cout << "Type: " << getType() << std::endl;
   std::cout << "Dimensions:\n";
   std::cout << "\tRows: " << getRows() << " Pixels\n";
   std::cout << "\tColumns: " << getColumns() << " Pixels\n";
   std::cout << "\tColor Depth: " << getColorDepth() << " Bits\n";
   std::cout << "File Size: " << getSize() << " Bytes\n\n";
}