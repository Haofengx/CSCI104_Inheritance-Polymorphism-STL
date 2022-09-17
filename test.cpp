#include "util.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"
#include <iostream>
#include <string>
#include <set>
// need to include gtest to use TEST()
// #include "gtest/gtest.h"

// using namespace std;

int main(){
	std::set<std::string>::iterator itr;

	// test first task
	// test parseStringToWords() in util.cpp
	// std::string test_string = "We c++ test.tes...te.t.testone.....tst";
	// std::set<std::string> test_set = parseStringToWords(test_string);
	// for (itr = test_set.begin(); itr != test_set.end(); ++itr)
	// {std::cout << *itr << " " << std::endl;}

	// task second task
	// test setUnion() in util.h
	// std::set<std::string> test_set = {"2342", "this", "23i3u2r", "is"};
	// std::set<std::string> test_set2 = {"2222", "this", "is"};
	// std::set<std::string> test_union = setUnion(test_set,test_set2);
	// std::cout<<"what is inside the union:"<<std::endl;
	// for (itr = test_union.begin(); itr != test_union.end(); itr++)
	// {
	// 	std::cout << *itr << std::endl;
	// }

	// test second task
	// test setIntersection() in util.h
	// std::set<std::string> test_set = {"2342", "this", "23i3u2r", "is"};
	// std::set<std::string> test_set2 = {"2222", "this", "is"};
	// std::set<std::string> test_inter= setIntersection(test_set,test_set2);
	// std::cout<<"what is inside the intersection:"<<std::endl;
	// for (itr = test_inter.begin(); itr != test_inter.end(); itr++)
	// {
	// 	std::cout << *itr << std::endl;
	// }


	// test third task
	// Book b = Book("book", "My HARD life with C++", 100, 100, "978-013292372-9", "Ace Xu");
  // Clothing c = Clothing("clothing", "Medium HHH shirt", 10, 10, "Mediu", "J. Crew");  
  // Movie m =Movie("movie", "How Life Becomes Better Without C++", 1, 1, "Drama", "PG");
  // test dislplay
  // std::cout<<b.displayString()<<std::endl;
  // std::cout<<c.displayString()<<std::endl;
  // std::cout<<m.displayString()<<std::endl;

  // test keywords
  // std::set<std::string> bookKey= b.keywords();
  // std::cout<<"This is the keywords for books "<<std::endl;
  // for (itr = bookKey.begin(); itr != bookKey.end(); itr++)
  // {
  //   std::cout << *itr << std::endl;
  // }
 
  // std::set<std::string> clothingKey= c.keywords();
  // std::cout<<"This is the keywords for Clothing "<<std::endl;
  // for (itr = clothingKey.begin(); itr != clothingKey.end(); itr++)
  // {
  //   std::cout << *itr << std::endl;
  // }
 
 
  // std::set<std::string> movieKey= m.keywords();
  // std::cout<<"This is the keywords for movie "<<std::endl;
  // for (itr = movieKey.begin(); itr != movieKey.end(); itr++)
  // {
  //   std::cout << *itr << std::endl;
  // }
	
}