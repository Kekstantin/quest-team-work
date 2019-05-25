#pragma once
#include"creature_abs.h"

class monster_abs: public creature_abs
{
protected:
	type_of_the_monster_ _monster_type;
	class_of_the_monster_ _monster_class;
	int _sum_defeat;
	int _sum_for_win;

public:
	monster_abs();
	~monster_abs();
	monster_abs(damage_ damage, balance_ balance, type_of_the_monster_ monster_type, class_of_the_monster_ monster_class, int sum_defeat, int sum_for_win) :
		creature_abs(damage, balance)
	{
		_monster_type = monster_type; 
		_monster_class = monster_class; 
		_sum_defeat = sum_defeat; 
		_sum_for_win = sum_for_win;
	}


	int get_sum_defeat() const;
	void set_sum_defeat(int sum_defeat);

	int get_sum_for_win() const;
	void set_sum_for_win(int sum_for_win);

	class_of_the_monster_ ger_monster_class() const;

	type_of_the_monster_ introduce();

	
};

