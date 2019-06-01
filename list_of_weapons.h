//
// Created by aylhttd on 25.05.19.
//

#ifndef GAME_OF_DOORS_LIST_OF_WEAPONS_H
#define GAME_OF_DOORS_LIST_OF_WEAPONS_H

#include "weapon.h"
#include <string>

class knife : public weapon 
{
public:
	knife () {};
	knife(damage_ damage, class_of_the_monster_ crit, balance_ costOfUpgrade, type_of_the_weapon_ _type_of_the_weapon) :
		weapon(damage, crit, costOfUpgrade, _type_of_the_weapon) {}
	std::string weapon::introduce()
	{
		std::string _tmp = " U vas est' nozh s uronom: " + std::to_string(getDamage()) + ". Stoimost' uluchshenia: " + std::to_string(getCostOfUpgrade()) + ".";
	return _tmp;
	}
};
class sword : public weapon{
	public:
	sword() {};
	sword(damage_ damage, class_of_the_monster_ crit, balance_ costOfUpgrade, type_of_the_weapon_ _type_of_the_weapon) :
		weapon(damage, crit, costOfUpgrade, _type_of_the_weapon) {}
	std::string weapon::introduce()
	{
	return " mech s uronom: " + std::to_string(getDamage()) + ". Stoimost' uluchshenia: " + std::to_string(getCostOfUpgrade()) + ".";
	}
};
class bow : public weapon{
public:
	bow() {};
	bow(damage_ damage, class_of_the_monster_ crit, balance_ costOfUpgrade, type_of_the_weapon_ _type_of_the_weapon) :
		weapon(damage, crit, costOfUpgrade, _type_of_the_weapon) {}
	std::string weapon::introduce()
	{
	return " luk s uronom: " + std::to_string(getDamage()) + ". Stoimost' uluchshenia: " + std::to_string(getCostOfUpgrade()) + ".";
	}
};
class mace : public weapon {
public:
	mace() {};
	mace(damage_ damage, class_of_the_monster_ crit, balance_ costOfUpgrade, type_of_the_weapon_ _type_of_the_weapon) :
		weapon(damage, crit, costOfUpgrade, _type_of_the_weapon) {}
	std::string weapon::introduce()
	{
	return " bulava s uronom: " + std::to_string(getDamage()) + ". Stoimost' uluchshenia: " + std::to_string(getCostOfUpgrade()) + ".";
	}
};



#endif //GAME_OF_DOORS_LIST_OF_WEAPONS_H
