#include "book.h"

Book::Book(const std::string category, const std::string name, double price, int qty, std::string ISBN, std::string author) :
	Product(category, name, price, qty)
{
	ISBN_ = ISBN;
	author_ = author;
}

Book::~Book() { }

std::set<std::string> Book::keywords() const{
	std::set<std::string> keyword = parseStringToWords(author_);
	std::set<std::string> name = parseStringToWords(name_);
	keyword = setUnion(keyword, name);
	keyword.insert(ISBN_);
	return keyword;
}

std::string Book::displayString() const{
	std::string display;
	display = name_ + "\n" + "Author: " + author_ + " " + "ISBN: " + ISBN_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
	return display;
}

void Book::dump(std::ostream& os) const{
	os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n"
		 << ISBN_ << "\n" << author_ << std::endl;
}

std::string Book::getISBN() const {return ISBN_;}

std::string Book::getAuthor() const {return author_;}



