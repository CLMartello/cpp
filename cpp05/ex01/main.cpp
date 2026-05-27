
#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int	main()
{
	try
	{
		Bureaucrat a("Nino", 40);
		Form fa("FormNino", 50, 30);
	
		std::cout << a << std::endl;
		std::cout << fa << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat b("Morfeu", 2);
		Form fb("FormMorfeu", 50, 30);

		b.signForm(fb);

		std::cout << fb << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Bureaucrat c("Bernardette", 100);
		Form fc("FormBernardette", 50, 30);
	
		c.signForm(fc);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Form fd("FormWrong", 0, 200);

		std::cout << fd << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}
