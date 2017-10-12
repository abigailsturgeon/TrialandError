// File: sodium_hw4_task1
// Created by Abigail Sturgeon and Dayton Baxter on 10/10/2017 for CS1410.
// Copyright (c) 2017 WSU

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 3;

// Define class
class houseInfo
{
private:
    int streetNum;
    string streetName;
    double price;
public:
    houseInfo() : streetNum(0), price(0)
    {}
    void houseInput()
    {
        cout << "Please enter the street number: " << endl;
        cin >> streetNum;
        cin.ignore();

        cout << "Please enter the street name: " << endl;
        getline(cin, streetName);

        cout << "Please enter the price: " << endl;
        cin >> price;
        cin.ignore();
    }
    void showHouse(int houseNum)
    {
        cout << "House " << houseNum << " at " << streetNum
             << " " << streetName << " for $" << price << ".00." << endl;
    }
    double returnPrice()
    {
        return price;
    }
};

// Function prototype
int comparePrices(houseInfo array[]);

// Main program
int main()
{
    houseInfo array[SIZE];
    houseInfo h1, h2, h3;
    cout << "Enter info for 1 house: " << endl;
    h1.houseInput();
    array[0] = h1;

    cout << "\nEnter info for 2 house: " << endl;
    h2.houseInput();
    array[1] = h2;

    cout << "\nEnter info for 3 house: " << endl;
    h3.houseInput();
    array[2] = h3;

    cout << "\nYour market analysis is as follows: " << endl;
    array[0].showHouse(1);
    array[1].showHouse(2);
    array[2].showHouse(3);

    cout << "\nYou should buy: ";
    int comparison = comparePrices(array);

    switch(comparison)
    {
        case 1:
            cout << "House 1" << endl;
            break;
        case 2:
            cout << "House 2" << endl;
            break;
        case 3:
            cout << "House 3" << endl;
            break;
        case 4:
            cout << "House 1 and 2." << endl;
            break;
        case 5:
            cout << "House 2 and 3." << endl;
            break;
        case 6:
            cout << "House 1 and 3." << endl;
            break;
        case 7:
            cout << "All houses are equal." << endl;
        default:
            cout << "Unsupported code" << endl;
            break;
    }
    return 0;


}
// Compare house prices and return comparison integer
int comparePrices(houseInfo array[])
{
    int i = 0;
    if ((array[0].returnPrice() < array[1].returnPrice()) && (array[0].returnPrice() < array[2].returnPrice()))
    {
        i = 1;
    } else if ((array[1].returnPrice() < array[2].returnPrice()) && (array[1].returnPrice() < array[0].returnPrice()))
    {
        i = 2;
    } else if ((array[2].returnPrice() < array[1].returnPrice()) && (array[2].returnPrice() < array[0].returnPrice()))
    {
        i = 3;
    } else if ((array[0].returnPrice() == array[1].returnPrice()) && (array[0].returnPrice() < array[2].returnPrice()))
    {
        i = 4;
    } else if((array[1].returnPrice() == array[2].returnPrice()) && (array[1].returnPrice() < array[0].returnPrice()))
    {
        i = 5;
    }else if((array[0].returnPrice() == array[2].returnPrice()) && (array[2].returnPrice() < array[1].returnPrice()))
    {
        i = 6;
    }else if((array[0].returnPrice() == array[1].returnPrice()) && (array[1].returnPrice() == array[2].returnPrice()) && (array[2].returnPrice() == array[0].returnPrice()))
    {
        i = 7;
    }
    else (i = 8);
    return i;

}