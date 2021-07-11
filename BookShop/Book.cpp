#include "Book.h"

#include <iostream>


void Book::Purchase()
{

}

const std::string Book::GetName() const
{
	return title;
}

Book::Book()
{
}

Book::Book(unsigned int id, std::string title, std::string description, std::string author)
	: id(id), title(title), description(description), author(author)
{
}

Book::~Book()
{
	//std::cout << "destroyed book" << std::endl;
}