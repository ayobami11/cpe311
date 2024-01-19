#ifndef _HEADER_H_
#define _HEADER_H_

struct Product
{
    char ProductName[40];
    float UnitPrice;
    int Quantity;
    float TotalPrice;
};

struct Shop
{
    char ShopName[40];
    char Address[40];
};

// the sample output he gave implies he meant character array, not character
struct Customer
{
    char CustomerName[30];
    char Phonenumber[15];
};

struct Person
{
    Shop shop;
    Customer customer;
    Product product;
};

void FillShoppingInfo(Person &);

void WriteReceipt(Person);

#endif