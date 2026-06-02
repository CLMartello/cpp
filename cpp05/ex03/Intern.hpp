
#ifndef INTERN_HPP

#define INTERN_HPP

#include <string>
#include "AForm.hpp"

class Intern {
private:

public:
    Intern();
    Intern(Intern &copy);
    Intern &operator=(Intern &copy);
    ~Intern();

    AForm *makeForm(const std::string &form, const std::string &target);

    class   NoValidFormException: public std::exception
    {
    public:
        virtual const char * what() const throw();
    };

};

#endif
