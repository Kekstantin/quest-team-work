#include "creature_abs.h"

int creature_abs::get_damage() const
{
	return _damage;
}

void creature_abs::set_damage(int damage)
{
	_damage = damage;
}

int creature_abs::get_balance() const
{
	return _balance;
}

void creature_abs::set_balance(int balance)
{
	_balance =balance;
}

creature_abs::creature_abs()
{
}

creature_abs::~creature_abs()
{
}
