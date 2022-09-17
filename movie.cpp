#include "movie.h"

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating) :
	Product(category, name, price, qty)
{
	genre_ = genre;
	rating_ = rating;
}

Movie::~Movie() { }

std::set<std::string> Movie::keywords() const{
	std::set<std::string> keyword = parseStringToWords(name_);
	keyword.insert(genre_);
	return keyword;
}

std::string Movie::displayString() const{
	std::string display;
	display = name_ + "\n" + "Genre: " + genre_ + " " + "Rating: " + rating_ + "\n" + std::to_string(price_) + " " + std::to_string(qty_) + " left.";
	return display;
}

void Movie::dump(std::ostream& os) const{
	os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n"
		 << genre_ << "\n" << rating_ << std::endl;
}

std::string Movie::getGenre() const {return genre_;}

std::string Movie::getRating() const {return rating_;}
