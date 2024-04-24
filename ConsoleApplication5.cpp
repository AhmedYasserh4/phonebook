/*
#include <iostream>
#include <map>
#include <string>

using namespace std;

// Function to add a new contact to the phone book
void addContact(map<string, string>& phoneBook) {
    string name, number;
    cout << "Enter name: ";
    cin >> name;
    cout << "Enter number: ";
    cin >> number;
    phoneBook[name] = number;
    cout << "Contact added successfully!" << endl;
}

// Function to search for a contact in the phone book
void searchContact(const map<string, string>& phoneBook) {
    string name;
    cout << "Enter name to search: ";
    cin >> name;
    auto it = phoneBook.find(name);
    if (it != phoneBook.end()) {
        cout << "Name: " << it->first << ", Number: " << it->second << endl;
    }
    else {
        cout << "Contact not found!" << endl;
    }
}

// Function to display all contacts in the phone book
void displayContacts(const map<string, string>& phoneBook) {
    if (phoneBook.empty()) {
        cout << "Phone book is empty!" << endl;
        return;
    }
    cout << "Contacts:" << endl;
    for (const auto& entry : phoneBook) {
        cout << "Name: " << entry.first << ", Number: " << entry.second << endl;
    }
}

int main() {
    map<string, string> phoneBook;
    int choice;

    do {
        cout << "\nPhone Book Menu:" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Search Contact" << endl;
        cout << "3. Display All Contacts" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addContact(phoneBook);
            break;
        case 2:
            searchContact(phoneBook);
            break;
        case 3:
            displayContacts(phoneBook);
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }
    } while (choice != 4);

    return 0;
}
*/
/*
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Structure to represent a contact
struct Contact {
    string name;
    string phoneNumber;
};

// PhoneBook class to manage contacts
class PhoneBook {
private:
    vector<Contact> contacts;

public:
    // Function to add a contact
    void addContact(const string& name, const string& phoneNumber) {
        contacts.push_back({ name, phoneNumber });
        cout << "Contact added successfully!" << endl;
    }

    // Function to delete a contact
    void deleteContact(const string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->name == name) {
                contacts.erase(it);
                cout << "Contact deleted successfully!" << endl;
                return;
            }
        }
        cout << "Contact not found!" << endl;
    }

    // Function to retrieve a contact
    void retrieveContact(const string& name) {
        for (const auto& contact : contacts) {
            if (contact.name == name) {
                cout << "Name: " << contact.name << ", Phone Number: " << contact.phoneNumber << endl;
                return;
            }
        }
        cout << "Contact not found!" << endl;
    }

    // Function to display all contacts
    void displayAllContacts() {
        if (contacts.empty()) {
            cout << "Phone book is empty!" << endl;
            return;
        }
        cout << "All Contacts:" << endl;
        for (const auto& contact : contacts) {
            cout << "Name: " << contact.name << ", Phone Number: " << contact.phoneNumber << endl;
        }
    }
};

int main() {
    PhoneBook phoneBook;
    int choice;
    string name, phoneNumber;

    do {
        cout << "\nPhone Book Menu:" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Delete Contact" << endl;
        cout << "3. Retrieve Contact" << endl;
        cout << "4. Display All Contacts" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone number: ";
            cin >> phoneNumber;
            phoneBook.addContact(name, phoneNumber);
            break;
        case 2:
            cout << "Enter name to delete: ";
            cin >> name;
            phoneBook.deleteContact(name);
            break;
        case 3:
            cout << "Enter name to retrieve: ";
            cin >> name;
            phoneBook.retrieveContact(name);
            break;
        case 4:
            phoneBook.displayAllContacts();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

// Structure to represent a contact
struct Contact {
    string name;
    string phoneNumber;
};

// PhoneBook class to manage contacts
class PhoneBook {
private:
    vector<Contact> contacts;

public:
    // Function to add a contact
    void addContact(const string& name, const string& phoneNumber) {
        contacts.push_back({ name, phoneNumber });
        cout << "Contact added successfully!" << endl;
    }

    // Function to delete a contact
    void deleteContact(const string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->name == name) {
                contacts.erase(it);
                cout << "Contact deleted successfully!" << endl;
                return;
            }
        }
        cout << "Contact not found!" << endl;
    }

    // Function to retrieve a contact
    void retrieveContact(const string& name) {
        for (const auto& contact : contacts) {
            if (contact.name == name) {
                cout << "Name: " << contact.name << ", Phone Number: " << contact.phoneNumber << endl;
                return;
            }
        }
        cout << "Contact not found!" << endl;
    }

    // Function to display all contacts
    void displayAllContacts() {
        if (contacts.empty()) {
            cout << "Phone book is empty!" << endl;
            return;
        }
        cout << "All Contacts:" << endl;
        for (const auto& contact : contacts) {
            cout << "Name: " << contact.name << ", Phone Number: " << contact.phoneNumber << endl;
        }
    }
};

int main() {
    PhoneBook phoneBook;
    int choice;
    string name, phoneNumber;

    do {
        cout << "\nPhone Book Menu:" << endl;
        cout << "1. Add Contact" << endl;
        cout << "2. Delete Contact" << endl;
        cout << "3. Retrieve Contact" << endl;
        cout << "4. Display All Contacts" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter name: ";
            cin >> name;
            cout << "Enter phone number: ";
            cin >> phoneNumber;
            phoneBook.addContact(name, phoneNumber);
            break;
        case 2:
            cout << "Enter name to delete: ";
            cin >> name;
            phoneBook.deleteContact(name);
            break;
        case 3:
            cout << "Enter name to retrieve: ";
            cin >> name;
            phoneBook.retrieveContact(name);
            break;
        case 4:
            phoneBook.displayAllContacts();
            break;
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}





