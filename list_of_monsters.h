#pragma once
#include"monster_abs.h"

class slime : public monster_abs
{
public:
	slime() {};
	slime(damage_ damage, balance_ balance, int sum_defeat, int donate) : monster_abs(damage, balance, slime_, water_, sum_defeat, donate) {}
	std::string introduce() const
	{
		return "Перед вами Слизь, принадлежащая к водному типу монстров. Его сила равна " + std::to_string(_damage) + ". Он пропустит вас, если вы заплатите ему " + std::to_string(_balance) + " рублей.";
	}
};

class goblin : public monster_abs
{
public:
	goblin() {};
	goblin(damage_ damage, balance_ balance, int sum_defeat, int donate) : monster_abs(damage, balance, goblin_, earth_, sum_defeat, donate) {}
	std::string introduce() const
	{
		return "Перед вами Гоблин, принадлежащий к земляному типу монстров. Его сила равна " + std::to_string(_damage) + ". Он пропустит вас, если вы заплатите ему " + std::to_string(_balance) + " рублей.";
	}
};

class scp_173 : public monster_abs
{
public:
	scp_173() {};
	scp_173(damage_ damage, balance_ balance, int sum_defeat, int donate) : monster_abs(damage, balance, scp_173_, air_, sum_defeat, donate) {}
	std::string introduce() const
	{
		return "Перед вами scp-173, принадлежащий к воздушному типу монстров. Его сила равна " + std::to_string(_damage) + ". Он пропустит вас, если вы заплатите ему " + std::to_string(_balance) + " рублей.";
	}

};
