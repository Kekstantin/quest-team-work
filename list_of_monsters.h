#pragma once
#include"monster_abs.h"

class slime : public monster_abs
{
public:
slime(damage_ damage, balance_ balance, int sum_defeat, int sum_for_win) : monster_abs(damage, balance, slime_, water_, sum_defeat, sum_for_win) {}
};

class goblin : public monster_abs
{
public:
	goblin(damage_ damage, balance_ balance, int sum_defeat, int sum_for_win) : monster_abs(damage, balance, goblin_, earth_, sum_defeat, sum_for_win) {}
};

class scp_173 : public monster_abs
{
public:
	scp_173(damage_ damage, balance_ balance, int sum_defeat, int sum_for_win) : monster_abs(damage, balance, scp_173_, air_, sum_defeat, sum_for_win) {}

};