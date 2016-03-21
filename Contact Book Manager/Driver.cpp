//Ryan Ramphal, CS211, Project 1

#include <iostream>
#include <fstream>
#include <string>
#include "Address.h"
#include "Contact.h"
#include "ContactBook.h"

using namespace std;

void load(ifstream& in, ContactBook*& cbook, int& count){ //loads data from the text file into virtual contactbooks in the driver to work with them
   string input;
   if (!in.eof()){
      getline(in, input);
      string input1 = input.substr(0, input.find("|"));
      string input2 = input.substr(input.find("|")+1);
      cbook = new ContactBook(input1, input2);

      
      while (input.compare("endofbook|") != 0){
         getline(in, input);
         if (in.eof()) break;
         string inputmod = input; //stores copy of input string so it can be modified while preserving the original content
         string data[10]; //stores the separated data input from the file as different strings of the array
         for (int i = 0; i < 9; i++){
            data[i] = inputmod.substr(0, inputmod.find_first_of("|"));
            inputmod = inputmod.substr(inputmod.find_first_of("|") + 1);
         }
         data[9] = inputmod;

         Contact* x = new Contact(data[0], data[1], data[2], data[3]);
         Address y(data[4], data[5], data[6], data[7], data[8], data[9]);
         x->inputAddress(y);
         cbook->add(x);
      }
      //when "endofbook|" is reached, read up to the next line and return
      getline(in, input);
      count++;
   }
}


int main() {
   cout << "Welcome to your digital contact book management system!\n\n";

   int numbooks = 0;
   ContactBook** books = new ContactBook*[5];
   ifstream in;
   in.open("ContactBooks.txt");
   string input; //stores the text input from the ContactBooks.txt file.
   cout << "Loading data...\n\n";
   if (in.is_open()){
      while (!in.eof()){
         load(in, books[numbooks], numbooks);
      }
   }
   in.close();


   int MENU = 1;
   while (true){
      cout << "Menu\n\n" << "1. Create new contact book\n" << "2. Remove a contact book\n" << "3. Display all contact books\n"
         << "4. Merge two contact books\n" << "5. Select a contact book\n" << "6. Save and exit\n";

      cin >> MENU;

      if (MENU > 6 || MENU < 1) continue;

      if (MENU == 1){
         if (numbooks == 5){
            cerr << "Error: Maximum amount of contact books reached. You can merge two contact books or delete a contact book to" <<
               " make room for another one.";
            continue;
         }
         else {
            books[numbooks] = new ContactBook();
            cin >> *books[numbooks];
            numbooks++;
            continue;
         }
      }

      else if (MENU == 2){
         string search = "someone";
         cout << "Please enter the name of the owner of the contact boook you'd like to have destroyed.: ";
         getline(cin, search);
         int index = -1;
         for (int i = 0; i < numbooks; i++){
            string fullName = books[i]->getFirstName() + ' ' + books[i]->getLastName();

            if (search.compare(books[i]->getFirstName()) == 0) index = i;
            else if (search.compare(books[i]->getLastName()) == 0) index = i;
            else if (search.compare(fullName) == 0) index = i;
         }

         if (index == -1) {
            cerr << "Error: No contact book for that person. Please try again.\n\n";
            continue;
         }
         else {
            delete[] books[index];
            delete books[index];
            cout << "Contact book deleted successfully.\n\n";
            numbooks--;
         }
      }

      else if (MENU == 3){
         if (numbooks == 0){
            cerr << "Error: no contact books within the system. Please make at least 1 contact book first.\n";
            continue;
         }
         for (int i = 0; i < numbooks; i++){
            cout << *books[i] << endl;
         }
         cout << endl << endl;
         continue;
      }

      else if (MENU == 4){
         string name1, name2;
         cout << "Please enter the name of the contact book owner who's book you want to store the info of the other.: ";
         getline(cin, name1);
         cout << "Please enter the name of the contact book owner who's book will be deleted after being merged.: ";
         getline(cin, name2);

         int index;
         for (int i = 0; i < numbooks; i++){
            string fullName = books[i]->getFirstName() + ' ' + books[i]->getLastName();

            if (name1.compare(books[i]->getFirstName()) == 0) index = i;
            else if (name1.compare(books[i]->getLastName()) == 0) index = i;
            else if (name1.compare(fullName) == 0) index = i;
         }

         int index2;
         for (int j = 0; j < numbooks; j++){
            string fullName2 = books[j]->getFirstName() + ' ' + books[j]->getLastName();

            if (name2.compare(books[j]->getFirstName()) == 0) index2 = j;
            else if (name2.compare(books[j]->getLastName()) == 0) index2 = j;
            else if (name2.compare(fullName2) == 0) index2 = j;
         }

         books[index]->merge(*books[index2]);
         delete[] books[index2];
         delete books[index2];
         continue;
      }


      else if (MENU == 5){
         string name;
         cout << "Please enter the owner's name of the contact book you'd like to access.: ";
         cin.ignore();
         getline(cin, name);

         int index;
         for (int i = 0; i < numbooks; i++){
            string fullName = books[i]->getFirstName() + ' ' + books[i]->getLastName();

            if (name.compare(books[i]->getFirstName()) == 0) index = i;
            else if (name.compare(books[i]->getLastName()) == 0) index = i;
            else if (name.compare(fullName) == 0) index = i;
         }


         int menu = 1; //stores the user's choice from the menu for proper program execution
         ContactBook* list = books[index]; //the ContactBook instance to be used by this program

         while (true){
            cout << endl << "Please make a selection from the menu below by entering the number next to your choice to proceed.\n\n";

            //menu
            cout << "1. Add a new contact" << endl
               << "2. Delete an old contact" << endl
               << "3. Display a contact's info" << endl
               << "4. Update a contact's info" << endl
               << "5. Display the entire contact book" << endl
               << "6. Exit" << endl << endl << "Your Menu Choice: ";

            cin >> menu;
            cout << endl;

            if (menu == 6) break; //exits if user enters 6

            else if (menu == 1){ //executed if user chooses to add a new contact
               Contact* x = new Contact(); //creates a new contact that will be input by the user
               cin >> *x;
               list->add(x);
               continue;
            }

            else if (menu == 2){ //executed if user decides to delete an old contact
               int index;
               char answer;
               bool done = false; //checks if menu choice 2 has completed execution or if it needs to be re-done (due to bad user input)

               while (!done){
                  cout << "Do you know the index of the contact you'd like to delete? (Y/N): ";
                  //cin.ignore();
                  cin >> answer;

                  if (answer == 'Y' || answer == 'y'){
                     cout << "Please enter the index you'd like to delete.: ";
                     cin >> index;
                     list->remove(index, done);
                     if (done) cout << "Contact successfully deleted!\n\n";
                  }

                  else if (answer == 'N' || answer == 'n'){
                     string name;
                     cout << "Please enter the name of the contact you'd like to delete.: ";
                     cin.ignore();
                     getline(cin, name);
                     list->remove(list->search(name), done);
                     if (done) cout << "Contact successfully deleted!\n\n";
                  }

                  else {
                     cerr << "Error: Invalid input. Please try again.\n\n";
                     continue;
                  }
                  if (done) break;
                  else continue;
               }
            }

            else if (menu == 3){ //executed if a user decides to display a contact's info

               string display;
               cout << "Please enter the name of the contact you'd like to have displayed.: ";
               cin.ignore();
               getline(cin, display);

               cout << list->contactAtIndex(list->search(display)); //outputs the contact specified if it exists, throws an exception otherwise

            }

            else if (menu == 4){ //executed if the user decides to modify a contact's info
               string mod;
               cout << "Please enter the full name of the contact you'd like to modify.: ";
               cin.ignore();
               getline(cin, mod);

               int index = list->search(mod);

               cout << "Please enter the new data for the contact " << list->contactAtIndex(list->search(mod)).getFirstName()
                  << ' ' << list->contactAtIndex(list->search(mod)).getLastName() << '.' << endl << endl;

               Contact* input = new Contact(); //stores the new data to be used to modify the existing contact
               cin >> *input;
               list->update(index, input);

               cout << "Contact updated successfully!" << endl << endl;
               continue;
            }

            else if (menu == 5){ //executed if the user decides to display the entire contact list
               cout << list;
               cout << endl << endl;
               continue;
            }
            else {
               cerr << "Error: Invalid menu selection. Please try again.\n\n";
               continue;
            }
         }
         continue;
      }

      else if (MENU == 6){
         ofstream out;
         out.open("ContactBooks.txt");
         for (int i = 0; i < numbooks; i++){
            out << books[i]->getFirstName() << "|" << books[i]->getLastName() << endl;
            for (int j = 0; j < books[i]->getSize(); j++){
               out << books[i]->contactAtIndex(j).getFirstName() << "|" << books[i]->contactAtIndex(j).getLastName() << "|"
                  << books[i]->contactAtIndex(j).getPhone() << "|" << books[i]->contactAtIndex(j).getEmail()
                  << "|" << books[i]->contactAtIndex(j).returnAddress().getHome() << "|" << books[i]->contactAtIndex(j).returnAddress().getStreet()
                  << "|" << books[i]->contactAtIndex(j).returnAddress().getApt() << "|" << books[i]->contactAtIndex(j).returnAddress().getCity()
                  << "|" << books[i]->contactAtIndex(j).returnAddress().getState() << "|" << books[i]->contactAtIndex(j).returnAddress().getZip() << endl;
            }
            out << "endofbook|" << endl << endl;
         }
      }
   }
   
   cout << "Thanks for using the digital contact book! This program will now exit." << endl;

   system("PAUSE");
   return 0;
}