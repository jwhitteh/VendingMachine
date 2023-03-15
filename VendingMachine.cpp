// VendingMachine3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>

#include "inventoryManager.h"
#include "cashManager.h"

using namespace std;

int main() {
	Inventory inv;
	CashManager cash;
	int selection;
	float money, cost, change;
	string line = "================================";

	cout << "Whittys Vending Machine\n" << endl;

	while (inv.hasStock()) 
	{
		cout << line << endl;
		inv.displayInventory();
		cout << "\nPlease enter item number: " << endl;
		cin >> selection;
		selection -= 1;

		if (selection >= 0 && selection <= inv.getSelectionAmount()) 
		{
			if (inv.getItemQuantity(selection) > 0)
			{
				cout << "\nPlease insert \x9C" << inv.getItemPrice(selection) << " for a " << inv.getItemName(selection) << endl;
				cin >> money;
				cash.addMoney(money);
				// cash.displayCurrent();
				cost = inv.getItemPrice(selection);
				change = cash.getChange(cost);

				if (change > cash.getChangeAvailable()) // if change is greater than the change available, return money and reset transaction
				{
					cout << "Not enough change available. Please take your money back." << endl;
				}
				else
				{
					if (cash.getCurrent() >= inv.getItemPrice(selection)) // if the money inserted is greater than or equal to the cost of the item, sell the item and return change
					{
						inv.sellItem(selection);
						cout << "\nYou have purchased a " << inv.getItemName(selection) << " for \x9C" << inv.getItemPrice(selection) << endl;
						if (cash.getCurrent() > inv.getItemPrice(selection)) // only return change if the money inserted is greater than the cost of the item
						{
							cout << line << endl;
							cout << "Your change is: \x9C" << change << endl;
							cout << line << "\n" << endl;
							cash.removeMoney(change);
						}
						cout << "Thank you for your purchase!\n\n" << endl;
						cash.resetTransaction();
					}
					else if (cash.getCurrent() < inv.getItemPrice(selection) && cash.getCurrent() > 0) // if the money inserted is less than the cost of the item, ask for more money
					{
						cout << "\nYou have not inserted enough money." << endl;
						while (cash.getCurrent() < inv.getItemPrice(selection)) // loop until the money inserted is greater than or equal to the cost of the item
						{
							cout << "Please insert \x9C" << inv.getItemPrice(selection) - cash.getCurrent() << " more." << endl;
							cin >> money;
							cash.addMoney(money);
							// cash.displayCurrent();
						}
					}
					else
					{
						cout << "I don't know how you managed to insert negative money!!" << endl;
					}
					cash.displayTotal();
				}
				
			}
			else
			{
				cout << "\nThere is no " << inv.getItemName(selection) << " in stock." << endl;
			}
		}
		else
		{
			cout << "\nInvalid selection. Please try again." << endl;
		}
	}
	cout << "\nSorry, we are out of stock. Please come back later." << endl;
	system("pause");
}