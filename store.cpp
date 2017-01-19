#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "customer.h"
#include "product.h"
#include "store.h"

using namespace std;

Store::Store() {}
Store::Store(const string name) {
	this->name = name;
}
string Store::getName() {
	return name;
}
void Store::setName(const string name) {
	this->name = name;
}
void Store::addProduct(const int productID, const string productName) {
	// If the products list is empty, add product to product list, else
	// through exception if product ID is not unique
	if (!products.empty()) {
		for (int i = 0; i < products.size(); ++i) {
			if (products.at(i).getID() == productID) {
				throw invalid_argument("Product ID already registered");
			}
		}
		// stores the newly created product in a vector of product objects
		products.push_back(Product(productID, productName));
	}
	else { products.push_back(Product(productID, productName)); }
}
void Store::addCustomer(const int customerID, const string customerName) {
	// If the customer list is empty, add customer to customer list, else
	// through exception if customer ID is not unique
	if (!customers.empty()) {
		for (int i = 0; i < customers.size(); ++i) {
			if (customers.at(i).getID() == customerID) {
				throw invalid_argument("Customer ID already registered");
			}
		}
		// stores the newly created customer in a vector of customer objects
		customers.push_back(Customer(customerName, customerID, false));
	}
	else { customers.push_back(Customer(customerName, customerID, false)); }
}
Product& Store::getProduct(int productID) {
	// Finds the matching productID in the vector of objects and returns that object
	// Throws an exception if the productID is not found in the vector of objects
	for (int i = 0; i < products.size(); ++i) {
		if (products.at(i).getID() == productID) {
			return products.at(i);
		}
	}
	throw invalid_argument("Not a valid Product ID");
}
Customer& Store::getCustomer(int customerID) {
	// Finds the matching customerID in the vector of objects and returns that object
	// Throws an exception if the customerID is not found in the vector of objects
	for (int i = 0; i < customers.size(); ++i) {
		if (customers.at(i).getID() == customerID) {
			return customers.at(i);
		}
	}
	throw invalid_argument("Not a valid customer ID");
}
void Store::takeShipment(int productID, int quantity, double cost) {
	// gets the product object and adds new shipment, exceptions are already handled
	getProduct(productID).addShipment(quantity, cost);
}
void Store::makePurchase(int customerID, int productID, int quantity) {
	// TODO: check these Customer Object function calls
	getProduct(productID).reduceInventory(quantity);
	getCustomer(customerID).processPurchase(getProduct(productID).getPrice(), getProduct(productID));
}
void Store::takePayment(int customerID, double amount) {
	// gets the customer object and makes the purchase, exceptions are already handled
	getCustomer(customerID).processPayment(amount);
}
// TODO: fix ostream functions
void Store::listProducts() {
	for (int i = 0; i < products.size(); ++i) {
		cout << "Product ID: " << products.at(i).getID() << endl;
		cout << "Product Name: " << products.at(i).getName() << endl;
		cout << endl;
	}
	
}
void Store::listCustomers() {
	for (int i = 0; i < customers.size(); ++i) {
		cout << "Customer ID: " << customers.at(i).getID() << endl;
		cout << "Customer Name: " << customers.at(i).getName() << endl;
		cout << endl;
	}
}
