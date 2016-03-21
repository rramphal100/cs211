//Ryan Ramphal, CS211, Homework #6

#include <iostream>
#include <string>
#include "Address.h"
#include "Contact.h"
#include "ContactBook.h"

using namespace std;


int main() {
   cout << "Welcome to your new digital contact book!\n\n";
   
   int menu = 1; //stores the user's choice from the menu for proper program execution
   ContactBook list; //the ContactBook instance to be used by this program

   while (true){
      cout << endl << "Please make a selection from the menu below by entering the number next to your choice to proceed.\n\n";

      //menu
      cout << "1. Add a new contact" << endl
         << "2. Delete an old contact" << endl
         << "3. Display a contact's info" << endl
         << "4. Update a contact's info" << endl
         << "5. Display the entire contact list" << endl
         << "6. Exit" << endl << endl << "Your Menu Choice: ";

      cin >> menu;
      cout << endl;

      if (menu == 6) break; //exits if user enters 6

      else if (menu == 1){ //executed if user chooses to add a new contact
         Contact* x = new Contact(); //creates a new contact that will be input by the user
         cin >> *x;
         list.add(x);
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
               list.remove(index, done);
               if (done) cout << "Contact successfully deleted!\n\n";
            }

            else if (answer == 'N' || answer == 'n'){
               string name;
               cout << "Please enter the name of the contact you'd like to delete.: ";
               cin.ignore();
               getline(cin, name);
               list.remove(list.search(name), done);
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
         
         display: //return here if an exception is thrown for invalid search name parameter
         string display;
         cout << "Please enter the name of the contact you'd like to have displayed.: ";
         cin.ignore();
         getline(cin, display);

         cout << list.contactAtIndex(list.search(display)); //outputs the contact specified if it exists, throws an exception otherwise
         
      }

      else if (menu == 4){ //executed if the user decides to modify a contact's info
         string mod;
         cout << "Please enter the full name of the contact you'd like to modify.: ";
         cin.ignore();
         getline(cin, mod);

         int index = list.search(mod);

         cout << "Please enter the new data for the contact " << list.contactAtIndex(list.search(mod)).getFirstName()
              << ' ' << list.contactAtIndex(list.search(mod)).getLastName() << '.' << endl << endl;

         Contact* input = new Contact(); //stores the new data to be used to modify the existing contact
         cin >> *input;
         list.update(index, input);

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

   cout << "Thanks for using the digital contact book! This program will now exit." << endl;

   system("PAUSE");
   return 0;
}