
#include "Bureaucrat.hpp"

int	main()
{
	Beraucrat a = new Beraucrat("Nino", 120);
	Beraucrat b = new Beraucrat("Morfeu", 2);

	Beraucrat c = b;

	c.incrementGrade;
	try
		c.incrementGrade;
	catch (std::exception &e)
		std::cout << e.what();

	try
		Beraucrat d = new Beraucrat("Lorena", 500);
	catch (std::exception &e)
		std::cout << e.what();
}
