#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n, size;
    cout << "Enter the initial number of grocery items: ";
    cin >> n;

    vector<string> grocery(n);

    for (int i = 0; i < grocery.size(); i++) {
        cout << "Enter name of item " << i + 1 << ": ";
        cin >> grocery[i];
    }

    // Ask user if they forgot any items
    
    cout << "How many additional items would you like to add? ";
    cin >> size;

    for (int i = 0; i < size; i++) {
        string item;
        cout << "Enter additional item " << i + 1 << ": ";
        cin >> item;
        grocery.push_back(item);
    }

    // Display all items
    cout << "\n--- Current Grocery List ---\n";
    for (int i = 0; i < grocery.size(); i++) {
        cout << "Item " << i + 1 << ": " << grocery[i] << endl;
    }

    // Ask user to delete items they already added
    
    string deleteItem;
    string answer;
    cout << "\nDo you want to delete any item you previously added? (yes/no): ";
    cin >> answer;

    while (answer == "yes" || answer == "Yes") {
        cout << "Enter the name of the item to delete: ";
        cin >> deleteItem;

        bool found = false;
        for (int i = 0; i < grocery.size(); i++) {
            if (grocery[i] == deleteItem) {
                grocery.erase(grocery.begin() + i);
                cout << "Item '" << deleteItem << "' deleted successfully.\n";
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "Item not found in the list.\n";
        }

        cout << "Do you want to delete another item? (yes/no): ";
        cin >> answer;
    }

    // Display final list
    cout << "\n--- Final Grocery List ---\n";
    for (int i = 0; i < grocery.size(); i++) {
        cout << "Item " << i + 1 << ": " << grocery[i] << endl;
    }

    cout << "\nThese are your final grocery items. Make sure you don’t forget them!\n";

    return 0;
}
