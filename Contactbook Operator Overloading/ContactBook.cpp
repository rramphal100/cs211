//Ryan Ramphal, CS211, Homework #5

#include "ContactBook.h"
using namespace std;

const int ContactBook::numContacts() const{
   return nextIndex;
}

void ContactBook::add(Contact input){
   if (nextIndex < 10){
      book[nextIndex] = input;
      nextIndex++;
   }
   else cerr << "Error: Contact book is already full! No more space for a new contact!" << endl;
}

void ContactBook::remove(int index){
   if (index > -1 && index < 10){
      //a temp array is created to store everything except the deleted contact, then it's copied to the original array:
      Contact temp[10];
      int i = 0;

      //the following 2 while loops create a temp array that contains all the original contacts except for the "deleted" contact
      while (i != index){
         temp[i] = book[i];
         i++;
      }

      while (i < 9){
         temp[i] = book[i + 1]; //stores everything except for "deleted" contact
         i++;
      }

      //this for loop stores the now correct temp array back into the original array
      for (int j = 0; j < 10; j++){
         book[j] = temp[j];
      }

      nextIndex--;

      cout << "Contact successfully deleted from the contact book!" << endl << endl;
   }
   else cerr << "Error: Index out of bound." << endl << endl;
}

void ContactBook::update(int index, Contact input){
   if (index > -1 && index < 10){
      book[index] = input;
      cout << "Contact successfully updated!" << endl << endl;
   }
   else cerr << "Error: Index is out of bounds." << endl << endl;
}

int ContactBook::search(string name){
   for (int i = 0; i < nextIndex; i++){
      string fullName = book[i].getFirstName() + ' ' + book[i].getLastName();

      if (name.compare(book[i].getFirstName()) == 0) return i;
      else if (name.compare(book[i].getLastName()) == 0) return i;
      else if (name.compare(fullName) == 0) return i;
   }

   return -1;
}

Contact ContactBook::contactAtIndex(int index) const{
   if (index > -1 && index < 10) return book[index];
   else throw exception("Error: Index is out of bounds of the contact book.");
}

void ContactBook::displayAll() const{
   for (int i = 0; i < nextIndex; i++){
      book[i].output();
   }
}

ostream& operator << (ostream& out, const ContactBook& list){ //replaces displayAll function
   for (int i = 0; i < list.numContacts(); i++){
      out << list.book[i] << endl;
   }
   return out;
}