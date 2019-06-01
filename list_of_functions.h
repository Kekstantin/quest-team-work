#pragma once
#include "door.h"
#include "monster_abs.h"
#include "control.h"
#include "hero.h"

std::vector<door*> door_generator()
{
	int number_of_doors = rand() % 3 + 2;
	std::vector<door*> doors(number_of_doors);
	for (int i = 0, i < number_of_doors, i++)
	{
		doors.push_back(control::create_door());
	}
	return doors;
}


