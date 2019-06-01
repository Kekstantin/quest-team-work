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

int weapon::getCountOfUpgrade() const {
return count_of_upgrade;
}

void weapon::setCountOfUpgrade(int countOfUpgrade) {
count_of_upgrade = countOfUpgrade;
}

type_of_the_weapon_ weapon::getName() const {
return _type_of_the_weapon;
}

void weapon::set_type_of_the_weapon(type_of_the_weapon_ _type_of_the_weapon) {
_type_of_the_weapon = _type_of_the_weapon;
}

void upgrade_weapon(){
damage_ = damage_ + 1;
}

weapon::weapon(damage_ damage, class_of_the_monster_ crit, balance_ costOfUpgrade, int countOfUpgrade,
type_of_the_weapon_ name) : _damage(damage), _crit(crit), cost_of_upgrade(costOfUpgrade),
count_of_upgrade(countOfUpgrade), _name(name) {}
