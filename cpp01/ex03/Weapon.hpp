
#ifndef WEAPON_HPP

#define WEAPON_HPP

#include <string>

class   Weapon {
private:
    std::string _type;

public:
    Weapon(std::string type);
    //~Weapon(); not necessary
    //if the class does not manage memory, no need for destructor
    const std::string getType(void) const;
    //first const = i cannot modify the returned string
    //last const = this function does not modify the object
    void    setType(std::string type);

};

#endif
