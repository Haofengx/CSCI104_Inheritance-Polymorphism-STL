CXX=g++
CXXFLAGS=-g -Wall -std=c++11 -Ilib
# Uncomment for parser DEBUG
#DEFS=-DDEBUG
BIN_DIR = bin

OBJS= $(BIN_DIR)/user.o $(BIN_DIR)/db_parser.o $(BIN_DIR)/product.o $(BIN_DIR)/product_parser.o $(BIN_DIR)/util.o $(BIN_DIR)/amazon.o $(BIN_DIR)/book.o $(BIN_DIR)/clothing.o $(BIN_DIR)/movie.o $(BIN_DIR)/mydatastore.o

all: $(BIN_DIR)/.dirstamp $(BIN_DIR)/amazon

$(BIN_DIR)/amazon: $(OBJS)
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ $(OBJS)

$(BIN_DIR)/amazon.o: src/amazon.cpp lib/db_parser.h lib/product_parser.h lib/mydatastore.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c src/amazon.cpp
$(BIN_DIR)/user.o: src/user.cpp lib/user.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c src/user.cpp
$(BIN_DIR)/db_parser.o: src/db_parser.cpp lib/db_parser.h lib/product_parser.h lib/datastore.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c src/db_parser.cpp
$(BIN_DIR)/product.o: src/product.cpp lib/product.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c src/product.cpp
$(BIN_DIR)/product_parser.o: src/product_parser.cpp lib/product_parser.h lib/product.h lib/book.h lib/movie.h lib/clothing.h 
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c src/product_parser.cpp
$(BIN_DIR)/util.o: src/util.cpp lib/util.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c src/util.cpp
$(BIN_DIR)/book.o: src/book.cpp lib/book.h lib/product.h lib/util.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c src/book.cpp
$(BIN_DIR)/clothing.o: src/clothing.cpp lib/clothing.h lib/product.h lib/util.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c src/clothing.cpp
$(BIN_DIR)/movie.o: src/movie.cpp lib/movie.h lib/product.h lib/util.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c src/movie.cpp
$(BIN_DIR)/mydatastore.o: src/mydatastore.cpp lib/mydatastore.h lib/datastore.h lib/movie.h lib/clothing.h lib/book.h lib/product.h
	$(CXX) $(CXXFLAGS) $(DEFS) -o $@ -c src/mydatastore.cpp

$(BIN_DIR)/.dirstamp:
		mkdir -p $(BIN_DIR)
		touch $(BIN_DIR)/.dirstamp

.PHONY: clean
clean:
	rm -rf $(BIN_DIR)
