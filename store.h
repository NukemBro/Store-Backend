#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include "customer.h"
#include "product.h"

class Store {
public:
	Store();
	Store(const std::string name);
	std::string getName();
	void setName(const std::string name);
	void addProduct(const int productID, const std::string productName);
	void addCustomer(const int customerID, const std::string customerName);
	Product& getProduct(int productID);
	Customer& getCustomer(int customerID);
	void takeShipment(int productID, int quantity, double cost);
	void makePurchase(int customerID, int productID, int quantity);
	void takePayment(int customerID, double amount);
	void listProducts();
	void listCustomers();

private:
	// vector of objects that store product objects
	std::vector<Product> products;
	// vector of objects that store customer objects
	std::vector<Customer> customers;
	std::string name = "";
};

#endif
