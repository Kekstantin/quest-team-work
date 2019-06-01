#pragma once
#include "door.h"
#include "monster_abs.h"
#include "control.h"
#include "hero.h"

function std::vector<door*> door_generator()
{
	int number_of_doors = rand() % 3 + 2;
	std::vector<door*> doors(number_of_doors);
	for (int i = 0, i < number_of_doors, i++)
	{
		doors.push_back(control::create_door());
	}
	return doors;
}

function bool fight(hero hero, monster_abs monster)
{
	int your_damage = 0;
	for (obj : hero.get_list_of_weapon())
	{
		int damage_multiplier = 1;
		damage_multiplier *= obj.getDamage();
		if (weapon.getCrit() == monster.get_class_monster_class())
			damage_multiplier *= 1.5;
		if (damage_multiplier > your_damage)
			your_damage = damage_multiplier;
	}
	int your_chance = your_damage / (your_damage + monster.get_damage());
	int win_number = rand() % 100;
	if (your_chance <= win_number)
		return true;
	else return false;
}


