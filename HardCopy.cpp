#include "HardCopy.h"


HardCopy::HardCopy(int ISBN, double price) : Book(ISBN, price) {

}




HardCopy::HardCopy(const HardCopy& hardcopy) {
	this->ISBN = hardcopy.ISBN;
	this->price = hardcopy.price;
	this->next = hardcopy.next;
}



HardCopy::~HardCopy() {

}



Book* HardCopy::Clone() const {
    HardCopy *copy = new HardCopy(ISBN,price);
    return copy;
}



void HardCopy::Discount() {
    price=price*(9./10);
}
