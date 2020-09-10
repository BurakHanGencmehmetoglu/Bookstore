#include "Book.h"

Book::Book() {
	this->next = NULL;
}




Book::Book(int ISBN, double price) {
	this->ISBN = ISBN;
	this->price = price;
	this->next = NULL;

}




int Book::GetISBN() const {
	return ISBN;
}




double Book::GetPrice() const {
	return price;
}




Book* Book::GetNext() const {
	return next;
}



void Book::SetNext(const Book& book) {
	this->next = book.Clone();
}




void Book::SetNext() {
	this->next = NULL;
}




Book::~Book() {
	this->next = NULL;	
}



bool Book::operator<(const Book& rhs) const {
    if (ISBN<rhs.GetISBN()){return true;}
    return false;
}



bool Book::operator<(int rhs) const {
    if (ISBN<rhs){return true;}
    return false;
}   



bool Book::operator>(int rhs) const {
    if (ISBN>rhs){return true;}
    return false;
} 
