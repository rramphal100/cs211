//Ryan Ramphal, CS211, Homework #6

#include "ContactBook.h"
using namespace std;


ContactBook::ContactBook() : storageSize(10), book(new Contact*[10]), nextIndex(0) { //default constructor
   for (int i = 0; i < 2; i++){
      book[i] = NULL; //everything is initialized to NULL (is this step and others like it necessary?)
   }
   cout << "Please enter the first name of this contact book's owner.: ";
   cin >> fn;
   cout << "Please enter the last name of this contact book's owner.: ";
   cin >> ln;
   cout << "Thank you. This contact book belongs to " << fn << " " << ln << ".\n\n";
}

ContactBook::~ContactBook(){ //destructor for the new dynamic class
   for (int i = 0; i < nextIndex; i++){
      if (book[i] != NULL)
      {
         delete book[i]; //this deletes all the elements in the array (the actual object, not the pointers)
      }
   }
   if (book != NULL)
   {
      delete[] book; //this deletes the array of pointers itself
   }
}
ContactBook::ContactBook(const ContactBook& other){ //overload of the copy constructor (for deep copies instead of shallow copies)
   nextIndex = other.nextIndex;
   storageSize = other.storageSize;

   book = new Contact*[storageSize];
   for (int i = 0; i < nextIndex; i++){
      book[i] = new Contact(*(other.book[i])); //makes an actual copy instead of passing by value (address) by default
   }
}

ContactBook& ContactBook::operator = (const ContactBook& other){ //assignment operator overload

   if (this != &other){ 
      //checks if this and the parameter object are the same or not first (just return the original object if this and parameter are the same)
      
      if (book != NULL){
         for (int i = 0; i < nextIndex; i++){
            delete book[i];
         }
         delete[] book;
      }

      //here is where the data is actually copied into the new array (hence, it looks like the copy constructor's code):
      nextIndex = other.nextIndex;
      storageSize = other.storageSize;
      book = new Contact*[storageSize];

      for (int i = 0; i < nextIndex; i++){
         book[i] = new Contact(*(other.book[i]));
      }

   }//closes if (this != &other)
   return *this;
}

void ContactBook::grow(){ //makes a new array of pointes to contacts twice the size of the original array
   storageSize += 10;
   Contact** newArray = new Contact*[storageSize];
   for (int i = 0; i < storageSize; i++){
      newArray[i] = NULL; //newArray is set to NULL by default
   }
   for (int i = 0; i < storageSize; i++){
      //*(newArray[i]) = *(book[i]);
      newArray[i] = book[i];
   }
   
   delete[] book;
   book = newArray;

   

   /*for (int i = 0; i < nextIndex; i++){
      delete newArray[i];
   }*/
   //delete[] newArray;
}

const int ContactBook::getSize() const{
   return nextIndex;
}

const int ContactBook::getCapacity() const{
   return storageSize;
}

void ContactBook::add(Contact* input){
   if (nextIndex == storageSize){
      grow();
   }
   book[nextIndex] = input;
   ++nextIndex;
}

void ContactBook::remove(int index){
   if (index > -1 && index < nextIndex){
      delete book[index];
      for (int i = index; i < nextIndex; i++){
         book[i] = book[i + 1];
      }
      nextIndex--;
   }

   else cerr << "Error: Index out of bound. No contact at that index or invalid index number." << endl << endl;
}

void ContactBook::remove(int index, bool& check){
   if (index > -1 && index < nextIndex){
      delete book[index];
      for (int i = index; i < nextIndex; i++){
         book[i] = book[i + 1];
      }
      nextIndex--;
      check = true;
   }

   else {
      cerr << "Error: Index out of bound. No contact at that index or invalid index number." << endl << endl;
      check = false;
   }
}

void ContactBook::update(int index, Contact* input){
   if (index > -1 && index < nextIndex){
      delete book[index];
      book[index] = input;
      cout << "Contact successfully updated!" << endl << endl;
   }
   else cerr << "Error: Index is out of bounds." << endl << endl;
}

void ContactBook::update(int index, Contact* input, bool& check){
   if (index > -1 && index < nextIndex){
      delete book[index];
      book[index] = input;
      cout << "Contact successfully updated!" << endl << endl;
      check = true;
   }
   else {
      cerr << "Error: Index is out of bounds." << endl << endl;
      check = false;
   }
}

const int ContactBook::search(string name) const{
   for (int i = 0; i < nextIndex; i++){
      string fullName = (*book[i]).getFirstName() + ' ' + book[i]->getLastName();
      //note that (*book[i]).getFirstName() and book[i]->getLastName() do the same type of call. This shows the definition of the "->" arrow operator

      if (name.compare(book[i]->getFirstName()) == 0) return i;
      else if (name.compare(book[i]->getLastName()) == 0) return i;
      else if (name.compare(fullName) == 0) return i;
   }

   return -1;
}

const Contact ContactBook::contactAtIndex(int index) const{
   if (index > -1 && index < nextIndex) return *book[index];
   else throw ('c');
}

const void ContactBook::displayAll() const{
   for (int i = 0; i < nextIndex; i++){
      book[i]->output();
   }
}

ostream& operator << (ostream& print, const ContactBook& list){ //replaces displayAll function
   if (list.getSize() == 0){
      print << "There are no contacts in " << list.fn << " " << list.ln << "'s contact book.\n";
      return print;
   }
   print << list.fn << " " << list.ln << "'s Contact Book:\n\n";
   for (int i = 0; i < list.getSize(); i++){
      print << *list.book[i] << endl;
   }
   print << "*End of " << list.fn << " " << list.ln << "'s Contact Book*\n\n";
   return print;
}