//Ryan Ramphal, CS211, Project 2

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "Image.h"
#include "Text.h"

using namespace std;

void vectorOutput(vector<File*> x, unsigned int start = 0){ //first recurisve function of HW#9
   if (x.size() == 0){
      cerr << "Error: Vector is empty. No files present.\n\n";
      return;
   }
   if (start < x.size() - 1){
      x[start]->display();
      vectorOutput(x, ++start);
   }

   else {
      x[start]->display();
   }
}

void filter(vector<File*> in, string type, unsigned int index = 0){ //second recursive function of HW#9
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
   else {
      cerr << "Error: Vector is empty. No files present.\n\n";
      return;
   }
}

int main(){
   vector<File*> vector; //vector of file pointers that this program will use
   int choice;
   cout << "Welcome to the file management program.\n";
   while (1){
      cout << "\nPlease enter the number of your menu choice to continue.:\n\n";
      cout << "1. Read data from a file.\n2. Create an image file.\n3. Create a text file.\n4. Print all files.\n"
         << "5. Print image files only.\n6. Print text files only.\n7. Delete a file by name and type.\n8. Quit.\n\n";
      cin >> choice;
      cout << endl;

      if (choice > 8 || choice < 1){
         cerr << "Error: Invalid menu choice. Please try again.\n\n";
         continue;
      }

      else if (choice == 1){ //if user chooses to read data from a file
         ifstream in;
         string line; //holds single lines from the input file
         in.open("Files.txt");
         while (!in.eof()){
            getline(in, line);
            if (line.empty()) continue;
            else if (line.compare("txt") == 0){ //if specified by file, create a new text file
               string name;
               getline(in, name); //get the name of the text file
               int chars;
               in >> chars;
               vector.push_back(new Text(name, chars));
            }
            else if (line.compare("gif") == 0){
               string name;
               getline(in, name);
               string nothing; //does nothing but store the 'x' in the input file to be ignored
               int rows;
               int cols;
               int cd; //rows, columns, and color depth data for the new Image file to be input to the vector
               in >> rows;
               in >> nothing;
               in >> cols;
               in >> cd;
               vector.push_back(new Image(name, rows, cols, cd));
            }
            else {
               cerr << "Error: Corrupt input file. Please fix it and try again. This program will now close.\n\n";
               system("PAUSE");
               exit(1);
            }
         } //closes while loop for reading from file
         cout << "File data imported into vector successfully.\n\n";
         continue; //show the menu again
      }

      else if (choice == 2){ //if user chooses to create an image file
         string name;
         int data; //stores each of the parameters of the image file so they may be stored in the object
         cout << "Please enter the name for the new image file.: ";
         cin.ignore();
         getline(cin, name);
         Image* x = new Image(name); //this is the pointer to the image object that will be pushed into the vector
         cout << "Please enter the number of rows in this image.: ";
         cin >> data;
         x->setRows(data);
         cout << "Please enter the number of columns in this image.: ";
         cin >> data;
         x->setColumns(data);
         cout << "Please enter the color depth of this image's pixels.: ";
         cin >> data;
         x->setColorDepth(data);
         vector.push_back(x);
         continue;
      }

      else if (choice == 3){ //if user chooses to create a text file
         string name;
         int chars;
         cout << "Please enter the name of the new text file.: ";
         cin.ignore();
         getline(cin, name);
         cout << "Please enter the amount of characters in the text file.: ";
         cin >> chars;
         vector.push_back(new Text(name, chars));
         continue;
      }

      else if (choice == 4){ //if user chooses to print all files in the vector
         cout << "Here is the data for all of the files in the vector.:\n\n";
         vectorOutput(vector);
         cout << "\n";
         continue;
      }

      else if (choice == 5){ //if user chooses to print image files only
         cout << "Here is the data for all of the image files in the vector.:\n\n";
         filter(vector, "gif");
         cout << "\n";
         continue;
      }

      else if (choice == 6){ //if user chooses to print text files only
         cout << "Here is the data for all of the text files in the vector.:\n\n";
         filter(vector, "txt");
         cout << "\n";
         continue;
      }

      else if (choice == 7){ //if user chooses to delete a file by name and type
         string name, type = "";
         cout << "Please enter the name of the file you'd like to have deleted from the vector.: ";
         cin.ignore();
         getline(cin, name);
         while (type.compare("gif") != 0 && type.compare("txt") != 0){
            cout << "Please enter \"txt\" if this is a text file, or \"gif\" if this is an image file.: ";
            cin >> type;
         }
         int i = 0;
         while(i < vector.size()){ //iterate through the vector until either the end of the vector or until the correct file
            if (vector[i]->getName().compare(name) == 0 && vector[i]->getType().compare(type) == 0) break;
            ++i;
         }
         if (i >= vector.size()){ 
            cerr << "Error: File not found.\n\n";
            continue;
         }
         else {
            //delete the specified file* and shift the rest over (check built-in vector functions)
            File* temp = vector[i];
            while (i < vector.size()-1){
               vector[i] = vector[i + 1];
               ++i;
            }
            vector.resize(vector.size() - 1);
            cout << "File deleted successfully.\n\n";
            continue;
         }
      }

      else if (choice == 8) break;

   }

   cout << "\nThis program will now close.\n\n";
   system("PAUSE");
   return 0;
}