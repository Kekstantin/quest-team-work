#pragma once
#include"creature_abs.h"

class hero:public creature_abs
{
protected:
	std::list<weapon*> _list_of_the_weapon;

public:
	hero();
	~hero();
	hero(damage_ _damage, balance_ _balance): creature_abs(_damage, _balance), _list_of_the_weapon(NULL){}

	void push_weapon(weapon* _weapon);
	void remove_weapon(weapon* _weapon);

	std::list<weapon*> get_list_of_the_weapon() const;	
};

