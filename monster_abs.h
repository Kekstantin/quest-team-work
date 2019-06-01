#pragma once
#include "creature_abs.h"

class monster_abs: public creature_abs
{
protected:
type_of_the_monster_ _monster_type;
class_of_the_monster_ _monster_class;
int _sum_defeat;
int _donate;

public:

monster_abs();
~monster_abs();
monster_abs(damage_ damage, balance_ balance, type_of_the_monster_ monster_type, class_of_the_monster_ monster_class, int sum_defeat, int donate) :
creature_abs(damage, balance), _monster_type(monster_type), _monster_class(monster_class), _sum_defeat(sum_defeat), _donate(donate){}

virtual std::string introduce() const;

int get_sum_defeat() const;
void set_sum_defeat(int sum_defeat);

int get_donate() const;
void set_donate(int donate);

class_of_the_monster_ get_monster_class() const;

type_of_the_monster_ get_type_of_the_monster() const;


};

