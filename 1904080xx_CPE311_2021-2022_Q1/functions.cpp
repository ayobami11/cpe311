#include <iostream>
// for strcpy function
#include <string.h>
// for creating, reading and writing to files
#include <fstream>

#include "header.h"

using namespace std;

void FillShoppingInfo(Person &person_shopping_info)
{
    // variable that temporarily stores different user inputs
    char temp[40];

    cout << "\nPlease enter in all the information required:\n";

    // Shop details
    cout << "\nShop\n";

    cout << "\nShop name: ";
    cin.getline(temp, 40);
    strcpy(person_shopping_info.shop.ShopName, temp);

    cout << "Shop address: ";
    cin.getline(temp, 40);
    strcpy(person_shopping_info.shop.Address, temp);

    // Customer details
    cout << "\nCustomer\n";

    cout << "\nCustomer name: ";
    cin.getline(temp, 30);
    strcpy(person_shopping_info.customer.CustomerName, temp);

    cout << "Customer phone number: ";
    cin.getline(temp, 15);
    strcpy(person_shopping_info.customer.Phonenumber, temp);

    // Product
    cout << "\nProduct\n";

    cout << "\nProduct name: ";
    cin.getline(temp, 40);
    strcpy(person_shopping_info.product.ProductName, temp);

    cout << "Unit price: ";
    cin.getline(temp, 10);
    // atof - converts a char array to float
    person_shopping_info.product.UnitPrice = atof(temp);

    cout << "Quantity: ";
    cin.getline(temp, 10);
    // atoi - converts a char array to int
    person_shopping_info.product.Quantity = atoi(temp);

    // Total price
    person_shopping_info.product.TotalPrice = person_shopping_info.product.UnitPrice * person_shopping_info.product.Quantity;
}

void WriteReceipt(Person person)
{

    /*
        creates and opens a text file for writing - https://www.guru99.com/cpp-file-read-write-open.html
        I created the receipt.txt file beforehand just so it always shows in the Visual Studio solution explorer
    */
    fstream ReceiptFile("receipt.txt", ios::out);

    if (ReceiptFile.is_open())
    {

        /*
            \n = newline character
            \t = tab character
        */
        ReceiptFile << "********************************************************************"
                    << "\n\t\t\t\t\t" << person.shop.ShopName << "\n"
                    << "\t\t\t\t" << person.shop.Address
                    << "\n\nCustomer\t" << person.customer.CustomerName
                    << "\nPhone Number\t" << person.customer.Phonenumber
                    << "\n\nYour Order\n"
                    << "\nProduct Name\tUnitPrice\tQuantity Ordered\n"
                    << person.product.ProductName << "\t\t" << person.product.UnitPrice << "\t\t\t" << person.product.Quantity
                    << "\n\t\t\t\t\t\t\t*******"
                    << "\n\t\t\t\tTotal Price\t" << person.product.TotalPrice
                    << "\n\t\t\t\t\t\t\t*******"
                    << "\n\tThanks for your patronage\n"
                    << "********************************************************************";

        ReceiptFile.close();

        cout << "\nReceipt has been written to receipt.txt successfully!" << endl;
    }
    else
    {
        cout << "\nError opening receipt file" << endl;
    }
}