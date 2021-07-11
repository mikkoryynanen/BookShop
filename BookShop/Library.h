#pragma once
#include <vector>

#include "Book.h"

class Library
{
private:
	int _librarySize = 10;
	std::vector<Book> _books;

	void GenerateBooks();

public:
	const Book* FindBook(std::string title);
	void AddBook(Book book);

	Library();
	~Library();
};

