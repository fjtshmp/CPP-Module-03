#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap(void) : ClapTrap("FragTrap",100,100,30)
{
	std::cout << "FragTrap default constructor called (" << _name << ")\n";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name,100,100,30)
{
	std::cout << "FragTrap name constructor called (" << _name << ")\n";
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called (" << _name << ")\n";
	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap copy assignment operator called (" << _name << ")\n";
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called (" << _name << ")\n";
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << _name << " requests a positive high five!\n";
}
