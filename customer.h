#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
#include "product.h"

class Customer {
public:
	Customer(const std::string name, const int customerID, bool credit);
	std::string getName();
	void setName(std::string name);
	void processPayment(double amount);
	void processPurchase(double amount, const Product product);
	void listProductsPurchased(std::ostream& os);
	int getID();
	bool getCredit();
	void setCredit(bool hasCredit);
	double getBalance();
private:
	int customerID = 0;
	std::string name = "";
	bool credit = false;
	double balance = 0;
	// creates a vector of product objects purchased by the customer
	std::vector<Product> productsPurchased;
};

std::ostream& operator<<(std::ostream& os, Customer& Customer);

#endif