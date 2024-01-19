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

// syntax for including a custom header file - https://www.simplilearn.com/tutorials/cpp-tutorial/guide-to-understand-cpp-header-files#:~:text=MEANExplore%20Program-,What%20Are%20C%2B%2B%20Header%20Files%3F,processed%20prior%20to%20the%20compilation
#include "header.h"

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