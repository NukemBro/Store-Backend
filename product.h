#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>

class Product {
public:
	Product(const int productID, const std::string productName);
	std::string getDescription();
	void setDescription(const std::string description);
	void addShipment(const int shipmentQuantity, const double shipmentCost);
	void reduceInventory(const int purchaseQuantity);
	double getPrice();
	std::string getName();
	int getID();
	int getNumberSold();
	double getTotalPaid();
	int getInventoryCount();

private:
	int productID = 0;
	std::string productName = "";
	std::string description = "";
	int inventoryCount = 0;
	int numSold = 0;
	double totalPaid = 0;
};

std::ostream& operator<<(std::ostream& os, Product& Product);

#endif