#include <iostream>

using namespace std;

class CashManager {
	float changeAvailable;
	float total;
	float current;
	float currentChange;

	public:
		CashManager();
		void addMoney(float &money);
		void removeMoney(float &money);
		void displayTotal();
		void displayCurrent();
		void displayChange();
		float getTotal();
		float getCurrent();
		float getChange(float& money);
		float getChangeAvailable();
		void resetTransaction();
};

CashManager::CashManager() {
	total = 0;
	current = 0;
	currentChange = 0;
	changeAvailable = 100;
}

void CashManager::resetTransaction() {
	current = 0;
	currentChange = 0;
}

void CashManager::addMoney(float &money) {
	current += money;
	total += money;
}

void CashManager::removeMoney(float &change) {
	total -= change;
}

void CashManager::displayTotal() {
	cout << "Total: \x9C" << total << endl;
}

void CashManager::displayCurrent() {
	cout << "Current: \x9C" << current << endl;
}

void CashManager::displayChange() {
	cout << "Change: \x9C" << currentChange << endl;
}

float CashManager::getChangeAvailable() {
	return changeAvailable;
}

float CashManager::getTotal() {
	return total;
}

float CashManager::getCurrent() {
	return current;
}

float CashManager::getChange(float &money) {
	currentChange = current - money;
	return currentChange;
}