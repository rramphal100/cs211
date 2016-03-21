//Ryan Ramphal, CS211, Project 1

#ifndef CONTACT_H
#define CONTACT_H
#include "Address.h"
#include <regex>
using namespace std;

class Contact{
private:
   string firstname;
   string lastname;
   Address address;
   string phone;
   string email;

   //regex input checkers (these will hold the input requirements for phone numbers and email addresses)                                                                                        
   static const regex checkPhone;
   static const regex checkEmail;

public:
   //constructors                                                                                                                                                                               
   Contact(string fn, string ln, string ph, string em);                                                                                                                           
   //for this assignment, all contacts are declared as blank and then the input function is called, or one of the setters for that particular contact variable                                  
   Contact();
   //default constructor that initializes all values to empty strings

   //accessors (will return the data as a string to wherever it was called)                                                                                                                     
   string getFirstName() const;
   string getLastName() const;
   string getAddress() const;
   string getPhone() const;
   string getEmail() const;
   Address returnAddress() const; //created for the operator overloads of hw#5

   //mutators                                                                                                                                                                                   
   void setFirstName(string x);
   void setLastName(string x);
   void setAddress();
   void inputAddress(Address x);
   void setPhone(string x);
   void setEmail(string x);

   //input (displays queries to make the input of a new contact very easy to do)                                                                                                                
   void input();

   //output (displays the specified contact's info in a way that is very easy to read) 
   void output() const;

   //member overloads of <, >, ==, !=, <=, and >= operators:
   const bool operator < (const Contact& contact);
   const bool operator > (const Contact& contact);
   const bool operator == (const Contact& contact);
   const bool operator != (const Contact& contact);
   const bool operator <= (const Contact& contact);
   const bool operator >= (const Contact& contact);

   //non-member overloads of insertion and extraction operators:
   friend istream& operator >> (istream& in, Contact& contact);
   friend ostream& operator << (ostream& out, const Contact& contact);
};

#endif