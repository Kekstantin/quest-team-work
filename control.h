#pragma once
#include "door.h"

class control
{
public:
	control();
	door* create_door();
	~control();

private:
	int _stage = 0;
	damage_ _dmg_for_slime = 5;
	damage_ _dmg_for_goblin = 15;
	damage_ _dmg_for_scp_173 = 50;

	const damage_ _knife_dmg = 10;
	const damage_ _mace_dmg = 20;
	const damage_ _sword_dmg = 30;
	const damage_ _bow_dmg = 50;

	const balance_ _balance_door = 10;

	const balance_ _steal_balance_slime = 5;
	const balance_ _steal_balance_goblin = 15;
	const balance_ _steal_balance_scp_173 = 40;

	balance_ _loose_balance_slime = _start_steal_balance_slime *1.5;
	balance_ _loose_balance_goblin = _start_steal_balance_goblin * 1.5;
	balance_ _loose_balance_scp_173 = _start_steal_balance_scp_173 * 1.5;

	const int _multiplyer_for_loose_and_steal = 1.5;
	const int _multiplyer_for_monsters = 1.2;
	const int _multiplyer_for_rewards = 1.3;
};
};

