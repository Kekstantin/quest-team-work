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

class_of_the_monster_ monster_abs::get_monster_class() const
{
return _monster_class;
}

type_of_the_monster_ monster_abs::get_type_of_the_monster() const
{
return _monster_type;
}

std::string introduce() const{
return "Вы видите " + std::to_string(get_type_of_the_monster()) + "Типа " + std::to_string(get_monster_class());

}

monster_abs::monster_abs(){}

monster_abs::~monster_abs(){}
