#include <iostream>
#include <string>
using namespace std;


struct User {
    string name;
    string address;
    string phone;
    struct User* next;
};


void updateContact(struct User* head)
{
    bool matchFound = false;
    string name, phone, address, findUserName;

    cout << "What is the name of the user you want to update?" << endl;
    getline(cin, findUserName);

    if (head == 0)
    {
        cout << "There are currently no users in the address book. Please add a user." << endl;
    }
    else
    {
        string name, phone, address;

        struct User* current = head;
         while (current != 0)
        {
            if (current->name == findUserName)
            {
                cout << "Please provide updated information." << endl;
                
                cout << "Add the name of the user:" << endl;
                getline(cin, name);
                cout << "Add the phone of the user:" << endl;
                getline(cin, phone);
                cout << "Add the address of the user:" << endl;
                getline(cin, address);

                current->name = name;
                current->phone = phone;
                current->address = address;
                matchFound = true;
            }
            current = current->next;
        }

        if (!matchFound)
        {
            cout << "Sorry no match was found" << endl;
        }
    }
}

void listAllContacts(struct User* head)
{   
    if (head == 0)
    {
        cout << "There are currently no users in the address book. Please add a user." << endl;
       return; //Need to return here as no point continuing since the list is empty
    }
 
   User* current = head;
 
    while(current != 0)
    {
        cout << current->name << endl;
        cout << current->phone << endl;
        cout << current->address << endl << endl;
        current = current->next;
    }
}

void searchContact(struct User* head)
{
    bool matchFound = false;
    string findUserName;

    cout << "What is the name of the user you want to find?" << endl;
    getline(cin, findUserName);

    if (head == 0)
    {
        cout << "There are currently no users in the address book. Please add a user." << endl;
    }
    else
    {
        struct User* current = head;
         while (current != 0)
        {
            if (current->name == findUserName)
            {
                cout << current->name << endl;
                cout << current->phone << endl;
                cout << current->address << endl;
                matchFound = true;
            }
            current = current->next;
        }

        if (!matchFound)
        {
            cout << "Sorry no match was found" << endl;
        }
    }

}


void addEntry(struct User** head)
{

    string name, phone, address;
    cout << "Add the name of the user:" << endl;
    getline(cin, name);
    cout << "Add the phone of the user:" << endl;
    getline(cin, phone);
    cout << "Add the address of the user:" << endl;
    getline(cin, address);

    if (*head == 0)
    {
        (*head) = new User;
        (*head)->name = name;
        (*head)->phone = phone;
        (*head)->address = address;
        (*head)->next = NULL;
    }
    else
    {
        struct User* current = *head;
         while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new User;
        current->next->name = name;
        current->next->phone = phone;
        current->next->address = address;
        current->next->next = NULL;

    }
}


void displayMenu()
{
    cout << "Menu" << endl;
    cout << "1) Add new contact" << endl;
    cout << "2) Update existing contact" << endl;
    cout << "3) Delete contact" << endl;
    cout << "4) List all contacts" << endl;
    cout << "5) Search for a contact" << endl;
    cout << "6) Quit" << endl;
}

int main(){
    bool keepPlaying = true;
    struct User* head = 0; //head points to the struct User object

    while (keepPlaying) {
        displayMenu();
        
        int SIZE = 40;
        char menu_choice[SIZE];
        cout << "Please choose an option";
        
        cin.getline(menu_choice, SIZE);

        while((menu_choice[0] < 49 || menu_choice[0] > 54) || menu_choice[1] != '\0')
        {
            cout << "Invalid choice, please enter valid choice" << endl;
            cin.getline(menu_choice, SIZE);
        }
        
        //address book array
        if (menu_choice[0] == '1')
        {
            addEntry(&head);
        } 
        else if (menu_choice[0] == '2')
        {
            updateContact(head);
        }
        else if (menu_choice[0] == '4')
        {
            listAllContacts(head);
        }
         else if (menu_choice[0] == '5')
        {
            searchContact(head);
        }
        else if (menu_choice[0] == '6')
        {
            keepPlaying = false;
        }
    }
    
}