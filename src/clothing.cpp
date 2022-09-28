#include "clothing.h"

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand) :
	Product(category, name, price, qty)
{
	size_ = size;
	brand_ = brand;
}

Clothing::~Clothing() { }

std::set<std::string> Clothing::keywords() const {
	std::set<std::string> keyword = parseStringToWords(brand_);
	std::set<std::string> name = parseStringToWords(name_);
	keyword = setUnion(keyword, name);
	return keyword;
}

std::string Clothing::displayString() const {
	std::string display;
	display = name_ + "\n" + "Size: " + size_ + " " + "Brand: " + brand_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
	return display;
}

void Clothing::dump(std::ostream& os) const {
	os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n"
		 << size_ << "\n" << brand_ << "\n";
}

std::string Clothing::getSize() const {return size_;}

std::string Clothing::getBrand() const {return brand_;}
