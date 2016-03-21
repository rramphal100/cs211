//Ryan Ramphal, CS211, Homework #6

#ifndef CONTACTBOOK_H
#define CONTACTBOOK_H

#include <string>
#include <iostream>
#include "Contact.h"

using namespace std;

class ContactBook{
private:
   string fn; //owner's first name
   string ln; //owner's last name
   int storageSize = 10; //stores the actual size of the pointer array (defaults to this initial capacity)
   Contact** book; //pointer to a dynamic array of Contacts to make the ContactBook
   int nextIndex = 0; //stores the next empty index in the array (aka the # of stored contacts)

   
   void grow(); //private function to increase the size of the array each time it becomes filled up

public:
   ContactBook(); //default constructor
   const int getSize() const; //returns how many contacts are currently stored in the array (size of the list)
   const int getCapacity() const; //returns the capacity of the pointer array (returns storageSize)
   void add(Contact* input); //adds a contact object to the array
   void remove(int index); //deletes a contact from the array at the input index
   void ContactBook::remove(int index, bool& check); //same as other "remove" but can change a bool flag for if operation was completed or not
   void update(int index, Contact* input); //update a contact already stored in the array with the contact passed in as a parameter
   void update(int index, Contact* input, bool& check); //same as other "update" but can change a bool flag for if operation was completed or not
   const int search(string name) const; //searches for a contact already stored in the array by name and returns it's index if found, returns -1 if not found
   const Contact contactAtIndex(int index) const; //returns the contact stored at index "index" of the array
   const void displayAll() const; //displays all the contacts within the array

   //non-member overloads of extraction operator:
   friend ostream& operator << (ostream& print, const ContactBook& list);

   //Big 3 Overloads:
   ContactBook(const ContactBook& other);
   ~ContactBook();
   ContactBook& operator = (const ContactBook& other);
};

#endif