#include <iostream>
using namespace std;

class Shop
{
    int itemId[100];
    int itemPrice[100];
    int counter;

public:
    void initCounter() { counter = 0; }
    void getPrice();
    void displayPrice();
    int getCounter() { return counter; }
};

void Shop::getPrice()
{
    if (counter >= 100)
    {
        cout << "Maximum item limit reached (100 items).\n";
        return;
    }
    cout << "Enter Id of your item " << counter + 1 << ": ";
    cin >> itemId[counter];
    cout << "Enter Price of your item: ";
    cin >> itemPrice[counter];
    counter++;
}

void Shop::displayPrice()
{
    if (counter == 0)
    {
        cout << "No items added yet.\n";
        return;
    }
    cout << "\n=== Items List ===\n";
    for (int i = 0; i < counter; i++)
    {
        cout << "Item " << i + 1 << " → ID: " << itemId[i]
             << " | Price: ₹" << itemPrice[i] << endl;
    }
}

int main()
{
    Shop dukaan;
    dukaan.initCounter();

    int choice;

    while (true)
    {
        cout << "\n====== SHOP MENU ======\n";
        cout << "1. Add Item\n";
        cout << "2. Show All Items\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            dukaan.getPrice();
            break;
        case 2:
            dukaan.displayPrice();
            break;
        case 3:
            cout << "Exiting program. Goodbye.\n";
            return 0;
        default:
            cout << "Invalid choice. Try again.\n";
        }

        if (dukaan.getCounter() >= 100)
        {
            cout << "\nItem limit (100) reached. No more items can be added.\n";
        }
    }

    return 0;
}
