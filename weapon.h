//
// Created by aylhttd on 25.05.19.
//

#ifndef GAME_OF_DOORS_WEAPON_H
#define GAME_OF_DOORS_WEAPON_H


#include "list_of_types.h"

class weapon {
public:
    damage_ getDamage() const;
    void setDamage(damage_ damage);
    class_of_the_monster_ getCrit() const;
    void setCrit(class_of_the_monster_ crit);
    balance_ getCostOfUpgrade() const;
    void setCostOfUpgrade(int costOfUpgrade);
    int getCountOfUpgrade() const;
    void setCountOfUpgrade(int countOfUpgrade);
    type_of_the_weapon_ getName() const;
    void setName(type_of_the_weapon_ name);
    weapon(damage_ damage, class_of_the_monster_ crit, balance_ costOfUpgrade, int countOfUpgrade,
           type_of_the_weapon_ name);

private:
    damage_ _damage;
class_of_the_monster_ _crit;
balance_ cost_of_upgrade;
int count_of_upgrade;
type_of_the_weapon_ _name;


};


#endif //GAME_OF_DOORS_WEAPON_H
