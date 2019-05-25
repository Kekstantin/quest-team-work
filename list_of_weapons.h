//
// Created by aylhttd on 25.05.19.
//

#ifndef GAME_OF_DOORS_LIST_OF_WEAPONS_H
#define GAME_OF_DOORS_LIST_OF_WEAPONS_H

#include "weapon.h"

class knife : public weapon {
public:
	knife () {};
	knife(damage_ damage, class_of_the_monster_ crit, balance_ costOfUpgrade, type_of_the_weapon_ name) :
		weapon(damage, crit, costOfUpgrade, name) {}
class sword : public weapon{
	public:
	sword() {};
	sword(damage_ damage, class_of_the_monster_ crit, balance_ costOfUpgrade, type_of_the_weapon_ name) :
		weapon(damage, crit, costOfUpgrade, name) {}
};
class bow : public weapon{
public:
	bow() {};
	bow(damage_ damage, class_of_the_monster_ crit, balance_ costOfUpgrade, type_of_the_weapon_ name) :
		weapon(damage, crit, costOfUpgrade, name) {}
};
class mace : public weapon {
public:
	mace() {};
	mace(damage_ damage, class_of_the_monster_ crit, balance_ costOfUpgrade, type_of_the_weapon_ name) :
		weapon(damage, crit, costOfUpgrade, name) {}
}
};



#endif //GAME_OF_DOORS_LIST_OF_WEAPONS_H
