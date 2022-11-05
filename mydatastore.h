#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include "datastore.h"
#include "util.h"
#include "movie.h"
#include "book.h"
#include "clothing.h"
#include <map>
#include <iostream>



class MyDataStore : public DataStore{
public:
	MyDataStore();
	~MyDataStore();
	// adding products
	void addProduct(Product* p);
	// adding users
	void addUser(User* u);
	// search of products whose keywords match the given "terms"
	std::vector<Product*> search(std::vector<std::string>& terms, int type);
	// Reproduce the database file from the current Products and User values
	void dump(std::ostream& ofile);
	// Each user can add products
	void addCart(Product* product, User* user);
	// Print the products in username's cart (case insensitive) at the current time.
	std::vector<Product*> viewCart(User*);
	// User can buy product in the cart
	void buyCart(User*);
	// Get user
	User* getUser(std::string username);
	// get products
	std::vector<Product*> getProd();
	// print users
	void printUser();
private:
	std::map<std::string, std::set<Product*>> product_;
	std::vector<Product*> product_vector;
	std::vector<User*> user_;
	std::map<User*, std::vector<Product*>> cart_;
};
#endif