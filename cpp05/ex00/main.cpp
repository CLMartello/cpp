
#include "Bureaucrat.hpp"
#include <iostream>

int	main()
{
	try
	//try is = watch this code
	//defines a protected zone
	{
		Bureaucrat a("Nino", 120);
		Bureaucrat b("Morfeu", 2);

		Bureaucrat c = b;

		std::cout << a;
		std::cout << b;

		c.incrementGrade();
		//calls a function that has a throw inside
		//throw is something went wrong
		//throw will jump the code to the next catch and continue from there
		std::cout << c;
		c.incrementGrade();
		
		Bureaucrat d("Lorena", 500);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	//try, throw and catch is used to deal with the error and not crashing the code
}
