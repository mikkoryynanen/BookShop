#include "Library.h"

void Library::GenerateBooks()
{
	for (int i = 0; i < _librarySize; i++)
	{
		_books.emplace_back(Book(i, "test", "this is my first book", "mike"));
	}
}

const Book* Library::FindBook(std::string title)
{
	for (const Book& b : _books)
		if (b.GetName() == title)
			return &(b);

	return NULL;
}

void Library::AddBook(Book book)
{
	_books.reserve(_books.size() + 1);
	_books.emplace_back(book);
}

Library::Library()
{
	_books.reserve(_librarySize);

	GenerateBooks();
}

Library::~Library()
{
}
