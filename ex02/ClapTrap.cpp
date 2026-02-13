#include "ClapTrap.hpp"
#include <iostream>
#include <climits>

ClapTrap::ClapTrap(void)
	: _name("noname"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructor called (" << _name << ")\n";
}

ClapTrap::ClapTrap(const std::string &name, int hp, int ep, int ad)
	: _name(name), _hitPoints(hp), _energyPoints(ep), _attackDamage(ad)
{
	std::cout << "ClapTrap name constructor called (" << _name << ")\n";
}

ClapTrap::ClapTrap(const ClapTrap &other)
	: _name(other._name),
	  _hitPoints(other._hitPoints),
	  _energyPoints(other._energyPoints),
	  _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructor called (" << _name << ")\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap copy assignment operator called\n";
	if (this != &other)
	{
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called (" << _name << ")\n";
}

static bool can_act(const ClapTrap &ct)
{
	if (ct.getHitPoints() <= 0)
	{
		std::cout << "ClapTrap " << ct.getName()
				  << " no hit points\n";
		return false;
	}
	if (ct.getEnergyPoints() <= 0)
	{
		std::cout << "ClapTrap " << ct.getName()
				  << " no energy points\n";
		return false;
	}
	return true;
}

void ClapTrap::attack(const std::string &target)
{
	if (!can_act(*this))
		return;
	_energyPoints -= 1;
	std::cout << "ClapTrap " << _name << " attacks " << target
			  << ", causing " << _attackDamage << " points of damage!\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!can_act(*this))
		return;
	_energyPoints -= 1;

	int heal = static_cast<int>(amount);

	int before = _hitPoints;
	_hitPoints += heal;

	std::cout << "ClapTrap " << _name << " repairs itself for " << amount
			  << " hit points! (HP: " << before << " -> " << _hitPoints
	 		  << ")\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0)
	{
		std::cout << "ClapTrap " << _name << " is already down\n";
		return;
	}
	int dmg = static_cast<int>(amount);

	int before = _hitPoints;
	_hitPoints -= dmg;
	if (_hitPoints < 0)
		_hitPoints = 0;

	std::cout << "ClapTrap " << _name << " takes " << amount
			  << " points of damage! (HP: " << before << " -> " << _hitPoints
			  << ")\n";
}

const std::string &ClapTrap::getName(void) const { return _name; }
int ClapTrap::getHitPoints(void) const { return _hitPoints; }
int ClapTrap::getEnergyPoints(void) const { return _energyPoints; }
int ClapTrap::getAttackDamage(void) const { return _attackDamage; }
void ClapTrap::setAttackDamage(int dmg) {_attackDamage = dmg;}
