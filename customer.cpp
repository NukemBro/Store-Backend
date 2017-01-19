#include <ostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "customer.h"
#include "product.h"

using namespace std;

Customer::Customer(const string name, const int customerID, bool credit) {
	this->name = name;
	this->customerID = customerID;
	this->credit = credit;
}
string Customer::getName() {
	return name;
}
void Customer::setName(string name) {
	this->name = name;
}
void Customer::processPayment(double amount) {
	if (amount < 0) {
		throw invalid_argument("Not a valid amount");
	}
	balance += amount;
}
void Customer::processPurchase(double amount, Product product) {
	if (amount < 0) {
		throw invalid_argument("Not a valid amount");
	}
	if (credit) {
			balance -= amount; 
	}
	else {
		if (balance >= amount) {
			balance -= amount;
		}
		else if (balance < amount) { 
			throw invalid_argument("Insufficient funds"); 
		}
	}
	// Pushes the purchased product into the list of purchased products
	// if it is not already on the list of purchased products
	if (!productsPurchased.empty()) {
		for (int i = 0; i < productsPurchased.size(); ++i) {
			if (productsPurchased.at(i).getID() != product.getID()) {
				productsPurchased.push_back(Product(product.getID(), product.getName()));
			}
		}
	}
	else { productsPurchased.push_back(Product(product.getID(), product.getName())); }
}
void Customer::listProductsPurchased(ostream& os) {
	for (int i = 0; i < productsPurchased.size(); ++i) {
		os << "Product ID: " << productsPurchased.at(i).getID() << endl;
		os << "Product Name: " << productsPurchased.at(i).getName() << endl;
		os << "Product Description: " << productsPurchased.at(i).getDescription() << endl;
		os << "Product Price: " << productsPurchased.at(i).getPrice() << endl;
	}
}
ostream& operator<<(ostream& os, Customer& Customer) {
	os << "Customer ID: " << Customer.getID() << endl;
	os << "Customer Name: " << Customer.getName() << endl;
	return os;
}
int Customer::getID() {
	return customerID;
}
bool Customer::getCredit() {
	return credit;
}
void Customer::setCredit(bool hasCredit) {
	this->credit = hasCredit;
}
double Customer::getBalance() {
	return balance;
}
