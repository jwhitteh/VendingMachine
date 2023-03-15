
#include <iostream>

using namespace std;

class Inventory {

	struct items {
		string name;
		float price;
		int quantity;
	};

	items inv[5] = {
		{"Coke", 1.25, 5},
		{"Sprite", 1.25, 5},
		{"Fanta", 1.25, 5},
		{"Water", 1.00, 5},
		{"Gatorade", 1.50, 5}
	};

	public:
		void displayInventory();
		void sellItem(int &i);
		string getItemName(int &i);
		float getItemPrice(int &i);
		int getItemQuantity(int &i);
		int getSelectionAmount();
		bool hasStock();
};

void Inventory::displayInventory() {
	cout << "No. Item\tPrice\tQuantity" << endl;
	for (int i = 0; i < 5; i++) {
		cout << i + 1 << ".  " << inv[i].name << "\t\x9C" << inv[i].price << "\t" << inv[i].quantity << endl;
	}
}

void Inventory::sellItem(int &i) {
		inv[i].quantity--;
}

string Inventory::getItemName(int &i) {
	return inv[i].name;
}

float Inventory::getItemPrice(int &i) {
	return inv[i].price;
}

int Inventory::getItemQuantity(int &i) {
	return inv[i].quantity;
}

int Inventory::getSelectionAmount() {
	return (sizeof(inv) / sizeof(*inv));
}

bool Inventory::hasStock() {
	for (int i = 0; i < 5; i++) {
		if (inv[i].quantity > 0) {
			return true;
		}
	}
	return false;
}


