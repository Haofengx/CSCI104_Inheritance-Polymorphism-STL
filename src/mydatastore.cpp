#include "mydatastore.h"

MyDataStore::MyDataStore() { }

MyDataStore::~MyDataStore() {
	product_.clear();
	cart_.clear();
	product_vector.clear();
	user_.clear();
}

// adding products
void MyDataStore::addProduct(Product* p){ 
	std::set<std::string> keyword = p->keywords();
	for(std::set<std::string>::iterator it = keyword.begin(); it != keyword.end(); ++it){
		if(keyword.find(*it) != keyword.end()){
			std::set<Product*> productset = product_[*it];
			productset.insert(p);
			product_[*it] = productset;
		}
		else{
			std::set<Product*> productset;
			productset.insert(p);
			product_[*it] = productset;
		}
	}
	product_vector.push_back(p);
}

// adding users
void MyDataStore::addUser(User* u){ user_.push_back(u); }

// search of products whose keywords match the given "terms"
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
	// type 0 = AND search
	std::set<Product*> result_set;
	result_set = product_[terms[0]];
	if(type == 0){
		for(unsigned int i=1; i < terms.size(); i++){
			std::set<Product*> temp_product_set = product_[terms[i]];
			result_set = setIntersection(result_set, temp_product_set);
		}
	}
	// type 1 = OR search
	else if(type == 1){
		for(unsigned int i=1; i < terms.size(); i++){
			std::set<Product*> temp_product_set = product_[terms[i]];
			result_set = setUnion(result_set, temp_product_set);
		}
	}
	std::vector<Product*> result(result_set.begin(), result_set.end());
	return result;
}

// Reproduce the database file from the current Products and User values
void MyDataStore::dump(std::ostream& ofile){
	ofile << "<products>" << std::endl;
	for(std::vector<Product*>::iterator it = product_vector.begin(); it != product_vector.end(); ++it){
		(*it)->dump(ofile);
	}
	ofile << "</prodcuts>" << std::endl;
	ofile << "<users>" << std::endl;
	for(std::vector<User*>::iterator it = user_.begin(); it != user_.end(); ++it){
		(*it)->dump(ofile);
	}
	ofile << "</users>";
}

// Each user can add products
void MyDataStore::addCart(Product* product, User* user){
	std::map<User*, std::vector<Product*>>::iterator it = cart_.find(user);
	if(it != cart_.end()){
		it->second.push_back(product);
	}
	else{
		std::vector<Product*> prod;
		prod.push_back(product);
		cart_[user] = prod;
	}
	std::cout << user->getName() << " add: " << product->getName() << std::endl;
}

// Print the products in username's cart (case insensitive) at the current time.
std::vector<Product*> MyDataStore::viewCart(User* user){
	std::map<User*, std::vector<Product*>>::iterator it = cart_.find(user);
	std::vector<Product*> cart;
	if(it != cart_.end()){
		cart = it->second;
	}
	return cart;
}

// User can buy product in the cart
void MyDataStore::buyCart(User* user){
	std::vector<Product*> cart = viewCart(user);
	for(std::vector<Product*>::iterator it = cart.begin(); it != cart.end(); ++it){
		int qty = (*it)->getQty();
		double price = (*it)->getPrice();
		double balance = user->getBalance();
		if((qty > 0) && (balance >= price)){
			(*it)->subtractQty(1);
			user->deductAmount(price);
			std::cout << user->getName() << " bought: " << (*it)->displayString() << std::endl;
			cart.erase(it--);
		}
	}
	cart_[user] = cart;
	cart.clear();
}

// get User
User* MyDataStore::getUser(std::string username){
	User* user = NULL;
	for(std::vector<User*>::iterator it = user_.begin(); it != user_.end(); ++it){
		std::string tmp_name = (*it)->getName();
		tmp_name = convToLower(tmp_name);
		if(tmp_name == username){
			user = *it;
			break;
		}
	}
	return user;
}

// additional part(self-testing)
// get products
std::vector<Product*> MyDataStore::getProd(){
	for(std::map<std::string, std::set<Product*>>::iterator it1 = product_.begin(); it1 != product_.end(); ++it1){
		std::cout << "Keyword: " << it1->first << std::endl;
		for(std::set<Product*>::iterator it2 = it1->second.begin(); it2 != it1->second.end(); ++it2){
			std::cout << (*it2)->displayString() << std::endl;
		}
		std::cout << std::endl;
	}
	return product_vector;
}

// print users
void MyDataStore::printUser(){
	for(std::vector<User*>::iterator it = user_.begin(); it != user_.end(); ++it){
		double balance = (*it)->getBalance();
		std::string name = (*it)->getName();
		std::cout << "Name: " << name << " Balance: " << balance << std::endl;
	}
}
