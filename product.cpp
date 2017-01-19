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

Product::Product(const int productID, const string productName) {
	this->productID = productID;
	this->productName = productName;
}
string Product::getDescription() {
	return description;
}
void Product::setDescription(const string description) {
	this->description = description;
}
void Product::addShipment(const int shipmentQuantity, const double shipmentCost) {
	if (shipmentQuantity < 0 || shipmentCost < 0) {
		throw invalid_argument("Not a valid quantity");
	}
	inventoryCount += shipmentQuantity;
	totalPaid += shipmentCost;
}
void Product::reduceInventory(const int purchaseQuantity) {
	if (inventoryCount < purchaseQuantity) {
		throw invalid_argument("Not enough inventory");
	}
	else {
		inventoryCount -= purchaseQuantity;
		numSold += purchaseQuantity;
		if (purchaseQuantity < 0) {
			throw invalid_argument("Not a valid quantity");
		}
	}
}
ostream& operator<<(ostream& os, Product& Product) {
	os << "Product ID: " << Product.getID() << endl;
	os << "Product Name: " << Product.getName() << endl;
	return os;
}
double Product::getPrice() {
	if (inventoryCount == 0 && numSold == 0) {
		return 0;
	}
	else { return (totalPaid / (inventoryCount + numSold)) * 1.25; }
}
string Product::getName() {
	return productName;
}
int Product::getID() {
	return productID;
}
int Product::getNumberSold() {
	return numSold;
}
double Product::getTotalPaid() {
	return totalPaid;
}
int Product::getInventoryCount() {
	return inventoryCount;
}
