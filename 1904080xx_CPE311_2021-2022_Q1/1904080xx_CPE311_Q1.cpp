/*

    Instructions:
Time Allowed: 1 Hour 30 Minutes
Create a new project with the format: MatricNo_CPE311_QNumber and save all
your source and header files into the appropriate folders.
When you complete a question, zip the project folder and upload it to the server.
*** Use only Visual Studio 2010 unless otherwise stated. *** - important
Use multi-file technique.
QUESTION 1 [30 Marks]
Write a complete C++ program that implements the following data stucture:
Product structure (character array for ProductName, float for UnitPrice and integer for
Quantity, float for TotalPrice). TotalPrice is a product of the UnitPrice and Quantity.
Shop structure (character array for ShopName and Address).
Customer structure (character for CustomerName and Phonenumber).
Person structure (Create an instance of Shop structure, Customer structure, and Product
structure).
The program should have a FillShoppingInfo function that ask the user to enter all information for
a Person instance. The prototype for this function is:
void FillShoppingInfo (Person *);
You should have a WriteReceipt function that writes out the Person and TotalPrice information to
a text file. The prototype for this function is:
void WriteReceipt (Person);
The output format is given below:
******************************************************
Yem Yem Ltd
University of Lagos, Akoka
Customer Ronke Ahmed
Phone Number 08067701544
Your Order
Product Name UnitPrice Quantity Ordered
Chocolate 50 5
 *******
 Total Price 250
 *******
 Thanks for your patronage
******************************************************


*/

#include <iostream>
// for strcpy function
#include <string.h>
// for creating, reading and writing to files
#include <fstream>
// syntax for including a custom header file - https://www.simplilearn.com/tutorials/cpp-tutorial/guide-to-understand-cpp-header-files#:~:text=MEANExplore%20Program-,What%20Are%20C%2B%2B%20Header%20Files%3F,processed%20prior%20to%20the%20compilation
#include "1904080xx_CPE311_Q1.h"

using namespace std;

// to get the appropriate folder for saving files: use Project->Add New Item

int main(void)
{

    Person anon;

    FillShoppingInfo(&anon);

    WriteReceipt(anon);

    system("pause");

    return 0;
}

void FillShoppingInfo(Person *person_shopping_info)
{
    // variable that temporarily stores different user inputs
    char temp[40];

    cout << "\nPlease enter in all the information required:\n";

    // Shop details
    cout << "\nShop\n";

    cout << "\nShop name: ";
    cin.getline(temp, 40);
    strcpy(person_shopping_info->shop.ShopName, temp);

    cout << "Shop address: ";
    cin.getline(temp, 40);
    strcpy(person_shopping_info->shop.Address, temp);

    // Customer details
    cout << "\nCustomer\n";

    cout << "\nCustomer name: ";
    cin.getline(temp, 30);
    strcpy(person_shopping_info->customer.CustomerName, temp);

    cout << "Customer phone number: ";
    cin.getline(temp, 15);
    strcpy(person_shopping_info->customer.Phonenumber, temp);

    // Product
    cout << "\nProduct\n";

    cout << "\nProduct name: ";
    cin.getline(temp, 40);
    strcpy(person_shopping_info->product.ProductName, temp);

    cout << "Unit price: ";
    cin.getline(temp, 10);
    // atof - converts a char array to float
    person_shopping_info->product.UnitPrice = atof(temp);

    cout << "Quantity: ";
    cin.getline(temp, 10);
    // atoi - converts a char array to int
    person_shopping_info->product.Quantity = atoi(temp);

    // Total price
    person_shopping_info->product.TotalPrice = person_shopping_info->product.UnitPrice * person_shopping_info->product.Quantity;
}

void WriteReceipt(Person person)
{

    /*
        creates and opens a text file for writing - https://www.guru99.com/cpp-file-read-write-open.html
        I created the receipt.txt file beforehand just so it always shows in the Visual Studio solution explorer
    */
    ofstream ReceiptFile("receipt.txt", ios::out);

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