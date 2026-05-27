
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
	//try is = watch this code
	//defines a protected zone
	{
		c.incrementGrade();
		//calls a function that has a throw inside
		//throw is something went wrong
		//throw will jump the code to the next catch and continue from there
		std::cout << c;
		c.incrementGrade();
	}
	catch (std::exception &e)
	//catch is handle the problem
	//way of catching the exception type
	{
		std::cout << e.what() << std::endl;
		//calls your version of what linked to that class exception
	}
	try
	{
		Bureaucrat d("Lorena", 500);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	//try, throw and catch is used to deal with the error and not crashing the code
}
