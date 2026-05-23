
#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	Bureaucrat a("Nino", 120);
	Bureaucrat b("Morfeu", 2);

	Bureaucrat c = b;

	std::cout << a;
	std::cout << b;

	try 
	{
		c.incrementGrade();
		std::cout << c;
		c.incrementGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat d("Lorena", 500);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
