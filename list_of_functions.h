#pragma once
#include "control.h"
#include "hero.h"

std::vector<door*> door_generator()
{
	std::mt19937 _gen(std::time(NULL));
	std::uniform_int_distribution<> uid(2, 4);

	int number_of_doors = uid(_gen);

	std::cout << (number_of_doors) << std::endl;
	std::vector<door*> doors(number_of_doors);
	for (int i = 0; i < number_of_doors; i++)
	{
		doors[i]=(control::initialization().create_door());
	}
	return doors;
}

bool fight(hero hero, monster_abs* monster)
{
	int your_damage = 0;
	for (auto obj : hero.get_list_of_the_weapon())
	{
		int damage_multiplier = 1;
		damage_multiplier *= obj->getDamage();
		if (obj->getCrit() == monster->get_monster_class())
			damage_multiplier *= 1.5;
		if (damage_multiplier > your_damage)
			your_damage = damage_multiplier;
	}
	int your_chance = your_damage / (your_damage + monster->get_damage());
	int win_number = rand() % 100;
	if (your_chance <= win_number)
		return true;
	else return false;
}


