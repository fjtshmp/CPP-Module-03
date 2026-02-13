#include "ScavTrap.hpp"

ScavTrap::ScavTrap(void) : ClapTrap("default",100,50,20)
{
	std::cout << "ScavTrap default constructor called (" << _name << ")\n";
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name,100,50,20)
{
	std::cout << "ScavTrap name constructor called (" << _name << ")\n";
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called (" << _name << ")\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "ScavTrap copy assignment operator called\n";
	if (this != &other)
		ClapTrap::operator=(other);
	return *this;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "ScavTrap destructor called (" << _name << ")\n";
}

void ScavTrap::attack(const std::string &target)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack (no hit points)\n";
		return;
	}
	if (_energyPoints <= 0)
	{
		std::cout << "ScavTrap " << _name << " can't attack (no energy points)\n";
		return;
	}
	_energyPoints -= 1;
	std::cout << "ScavTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!\n";
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << _name << " is now in Gate keeper mode.\n";
}
