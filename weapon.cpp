//
// Created by aylhttd on 25.05.19.
//

#include "weapon.h"

damage_ weapon::getDamage() const {
return _damage;
}

void weapon::setDamage(damage_ damage) {
_damage = damage;
}

class_of_the_monster_ weapon::getCrit() const {
return _crit;
}

void weapon::setCrit(class_of_the_monster_ crit) {
_crit = crit;
}

balance_ weapon::getCostOfUpgrade() const {
return cost_of_upgrade;
}

void weapon::setCostOfUpgrade(int costOfUpgrade) {
cost_of_upgrade = costOfUpgrade;
}

type_of_the_weapon_ weapon::get_type_of_the_weapon() const {
return _type_of_the_weapon;
}

void weapon::set_type_of_the_weapon(type_of_the_weapon_ _type_of_the_weapon) {
_type_of_the_weapon = _type_of_the_weapon;
}

void weapon::upgrade_weapon(){
	_damage = _damage + 1;
}


