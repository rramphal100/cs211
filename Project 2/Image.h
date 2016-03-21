//Ryan Ramphal, CS211, Project 2

#ifndef IMAGE_H
#define IMAGE_H

#include "File.h"

class Image : public File{
private:
   int rows;
   int columns;
   int color_depth;

public:
   Image();
   Image(std::string name);
   Image(std::string n, int r, int c, int cd);
   const int getRows() const;
   const int getColumns() const;
   const int getColorDepth() const;
   virtual const int getSize() const;

   void setRows(int);
   void setColumns(int);
   void setColorDepth(int);

   virtual void display() const;
};
#endif