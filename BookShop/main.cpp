#include <iostream>
#include <string>
#include <vector>

#include "Book.h"
#include "Library.h"

void PrintCommand(std::string message)
{
	std::cout << message << std::endl;
}

void FindBook(Library& library)
{
	std::cout << "Please specify the name of a book you want to find: ";

	bool canRun = true;
	std::string bookName;
	while (canRun)
	{
		std::cin >> bookName;

		const Book* foundBook = library.FindBook(bookName);

		if (foundBook == nullptr)
		{
			std::cout << "Could not find book with title " << bookName << std::endl;

		}
		else
		{
			std::cout << "Found book: " << foundBook->GetName() << std::endl;

			std::cout << "Want to purchase it? (y/n) ";

			std::string input;
			std::cin >> input;
			if (input == "y")
			{
				std::cout << "Book '" << foundBook->GetName() << "' purchased" << std::endl << std::endl;
				return;
			}
			else if (input == "n")
			{
				std::cout << "Book '" << foundBook->GetName() << "' hasn't been purchsed" << std::endl << std::endl;
				return;
			}
			else
			{
				std::cout << "Did not regonize command " << input << std::endl;
			}
		}
	}
}

void AddBook(Library& library)
{
	std::string title = "";
	while (title == "")
	{
		std::cout << "Please enter book title: ";
		std::cin >> title;

	}

	std::cout << "Please enter book description: ";
	std::string description;
	std::cin >> description;

	std::cout << "Please enter book author: ";
	std::string author;
	std::cin >> author;

	library.AddBook(Book(0, title, description, author));

	std::cout << std::endl << "Book Added! \ntitle:" << title << "\ndescription: " << description << "\nauthor:" << author << std::endl << std::endl;

}

int main()
{
	Library library;

	std::string cmd;

	while (true)
	{
		std::cout << R"(Commands
<find> find book
<add> add book
<close> close app
)";

		std::cin >> cmd;

		if (cmd == "find")
		{
			FindBook(library);
		}
		else if (cmd == "add")
		{
			AddBook(library);
		}
		else if (cmd == "close")
		{
			break;
		}
		else
		{
			PrintCommand("Could not find command: " + cmd);
		}
	}

	return 0;
}