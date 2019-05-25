#include "hero.h"



void hero::push_weapon(weapon* _weapon)
{
	_list_of_the_weapon.push_back(_weapon);
}

void hero::remove_weapon(weapon * _weapon)
{
	_list_of_the_weapon.remove(_weapon);
}

std::list<weapon*> hero::get_list_of_the_weapon() const
{
	return _list_of_the_weapon;
}




hero::hero()
{

}


hero::~hero()
{
	~_list_of_the_weapon;
}
