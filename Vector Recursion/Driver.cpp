//Ryan Ramphal, CS211, HW#9

#include <iostream>
#include <vector>
#include "Image.h"
#include "Text.h"

using namespace std;

void vectorOutput(vector<File*> x, unsigned int start = 0){ //first recurisve function of the assignment
   if (start < x.size() - 1){
      x[start]->display();
      vectorOutput(x, ++start);
   }

   else {
      x[start]->display();
   }
}

void filter(vector<File*> in, string type, unsigned int index = 0){
   while (type.compare("txt") != 0 && type.compare("gif") != 0){
      cerr << "Error: Bad type selection. Please try again.: ";
      cin >> type;
   }
   if (in.size() > 0){
      if (index < in.size()){
         while (in[index]->getType().compare(type) != 0){
            ++index;
            if (index == in.size()) return;
         }
         in[index]->display();
         filter(in, type, ++index);
      }
   }
   else return;
}

int main(){
   vector<File*> x;

   x.push_back(new Image("Image File 1", 300, 300, 8));
   x.push_back(new Text("Text File 1", 500));
   x.push_back(new Image("Image File 2", 400, 400, 8));
   x.push_back(new Text("Text File 2", 700));
   x.push_back(new Text("Text File 3", 1000));
   x.push_back(new Image("Image File 3", 500, 500, 8));

   filter(x, "gif");

   cout << endl;
   system("PAUSE");
   return 0;
}