#include "monster_abs.h"



int monster_abs::get_sum_defeat() const
{
	return _sum_defeat;
}

void monster_abs::set_sum_defeat(int sum_defeat)
{
	_sum_defeat = sum_defeat;
}

int monster_abs::get_donate() const
{
	return _donate;
}

void monster_abs::set_donate(int donate)
{
	_donate = donate;
}

class_of_the_monster_ monster_abs::ger_monster_class() const
{
	return _monster_class;
}

type_of_the_monster_ monster_abs::introduce()
{
	return _monster_type;
}

monster_abs::monster_abs()
{
}


monster_abs::~monster_abs()
{
}


