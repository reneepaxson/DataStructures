/* 
    Renee Paxson
    Project 6
    9 Dec 2023
    driver file
    made with help from Jon Cole, the goat
*/
#include "Database.h"


int main(){
    Database DB;
    int collisions;
    // index will come from DB later

    //////// TEST INSERT /////////
    // [13], collisions = 0
    DB.insert(Record("Agatha", "Frisky", 71239, "Freshman"),collisions);
    
    // collisions = 1
    DB.insert(Record("Alton", "BaxPax", 79176, "Senior"), collisions);

    // collisions = 2
    DB.insert(Record("Sam", "Yosemite", 87113, "Junior"), collisions);

    //collisions = 3
    DB.insert(Record("Finn", "Mertens", 99996, "Sophomore"), collisions);


    //////// TEST FIND /////////
    
    Record r;

    // [13], collisions = 0
    DB.find(71239, r, collisions);

    // collisions = 1
    DB.find(79176, r, collisions);

    // collisions = 2
    DB.find(87113, r, collisions);

    // collisions = 3
    DB.find(99996, r, collisions);

    // not in there
    DB.find(95050, r, collisions);

    // //// DATABASE ///////

    string firstname;
    string lastname;
    int uid;
    string year;

    char menu;
    do {
        cout << "Would you like to (I)nsert or (D)elete a record, ";
        cout << "(S)earch for a record, (P)rint the database, or (Q)uit? \n";
        cout << "Enter action: ";
        cin >> menu;

        switch (menu) {
            case 'I':
                cout << "Inserting a new record. \n";
                cout << "Last Name: ";
                cin >> lastname;
                cout << "First name: ";
                cin >> firstname;
                cout << "UID: ";
                cin >> uid;
                cout << "Year: ";
                cin >> year;
                if (DB.insert(Record(firstname, lastname, uid, year), collisions)) {
                    cout << "Record inserted. (" << collisions << " collisions during insert).\n\n";
                    break;
                }

                cout << "Insert failed \n\n";
                break;

            case 'D':
                cout << "Enter UID to delete: ";
                cin >> uid;
                cout << "Deleting....";
                if (DB.remove(uid)){
                    cout << " record deleted.\n\n";
                    break;
                }

                cout << " record does not exist\n\n";
                break;

            case 'S':
                cout << "Enter UID to search for: ";
                cin >> uid;
                cout << "Searching....";
                if (DB.find(uid, r, collisions)){
                    cout << " record found ("<< collisions << " collisions";
                    cout <<" during search)\n";
                    cout << "----------------------------\n";
                    cout << "Name: " << r.getName() << "\n";
                    cout << "UID: " << r.getUID() << "\n";
                    cout << "Year: " << r.getYear() << "\n"; 
                    cout << "----------------------------\n\n";
                    break;
                } 
                cout << " record not found \n\n";
                
                break;

            case 'P':
                cout << "\n";
                cout << DB;
                cout << "\n";
                break;
            
            case 'Q':
                cout << "Exiting....\n\n";
                break;
            
            default:
                cout << "Please enter a valid menu option.\n\n";
                
        }

    } while (menu != 'Q');
}