#pragma once
#include "list_of_types.h"

class creature_abs
{
protected:
	damage_ _damage;
	balance_ _balance;

public:
	creature_abs();
	~creature_abs();
	creature_abs(damage_ damage, balance_ balance): _damage(damage), _balance(balance){}

	int get_damage() const;
	void set_damage(int damage);
	int get_balance() const;
	void set_balance(int balance);

	
};

