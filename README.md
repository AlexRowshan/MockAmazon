# Mock Amazon

Description:
In this project, code is written to model a very simplified version of an online retail system, similar to Amazon. 
The program reads a database of products from certain categories, along with users and their associated information. 
The program allows users to interactively search for products based on specific keywords, returning products that match the search. 
From those matches, the program enables users to add select items to a "cart," view items in the cart, purchase the items in the cart, and save the updated database of 
product and user information.

Compile instructions:
g++ -g -Wall -std=c++11 amazon.cpp book.cpp clothing.cpp movie.cpp mydatastore.cpp db_parser.cpp product_parser.cpp product.cpp user.cpp util.cpp -o amazon

./amazon database.txt
