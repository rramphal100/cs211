//Ryan Ramphal, CS211, Homework #4                                                                                                                                                             

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
	//Contact(string fn, string ln, string add, string ph, string em);                                                                                                                           
	//for this assignment, all contacts are declared as blank and then the input function is called, or one of the setters for that particular contact variable                                  
	//Contact(); for this assignment the automatically generated default constructor only is used

	//accessors (will return the data as a string to wherever it was called)                                                                                                                     
	string getFirstName();
	string getLastName();
	string getAddress();
	string getPhone();
	string getEmail();

	//mutators                                                                                                                                                                                   
	void setFirstName(string x);
	void setLastName(string x);
	void setAddress();
	void setPhone(string x);
	void setEmail(string x);

	//input (displays queries to make the input of a new contact very easy to do)                                                                                                                
	void input();

	//output (displays the specified contact's info in a way that is very easy to read) 
	void output() const;
};

#endif