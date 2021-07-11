#pragma once

#include <string>


class Book
{
private:
	unsigned long	id;

	unsigned int	inventoryCount;

	std::string		title = "";
	std::string		description = "";
	std::string		author = "";

public:

	void Purchase();

	const std::string GetName() const;

	Book();
	Book(unsigned int id, std::string title, std::string description, std::string author);
	~Book();
};

