#include "control.h"



control::control()
{
}

door * control::create_door()
{
	std::mt19937 _gen(std::time(NULL));
	std::uniform_int_distribution<> uid(0, 50);
	monster_abs* _ms;
	weapon* _ws;

	int _rnd = uid(_gen);
	if (_rnd >= 0 && _rnd < 20)
		_ms = nullptr;
	if (_rnd >= 20 && _rnd < 30)
		_ms = new slime(_start_dmg_for_slime, NULL, _start_loose_balance_slime, _start_steal_balance_slime);			//todo написать входящие в конструкторры элементы
	if (_rnd >= 30 && _rnd < 47)
		_ms = new goblin(_start_dmg_for_goblin, NULL, _start_loose_balance_goblin, _start_steal_balance_goblin);			//todo написать входящие в конструкторры элементы
	if (_rnd >= 47 && _rnd <= 50)
		_ms = new scp_173(_start_dmg_for_scp_173, NULL, _start_loose_balance_scp_173, _start_steal_balance_scp_173);		//todo написать входящие в конструкторры элементы

	int _rnd1 = uid(_gen);

	if (_rnd >= 0 && _rnd < 30)
		_ws = nullptr;
	if (_rnd >= 30 && _rnd < 30)
		_ws = new mace(_mace_dmg, water_, 2, mace_);		//todo написать входящие в конструкторры элементы
	if (_rnd >= 30 && _rnd < 47)
		_ws = new sword(_sword_dmg, earth_, 4, sword_);		//todo написать входящие в конструкторры элементы
	if (_rnd >= 47 && _rnd <= 50)
		_ws = new bow(_bow_dmg, air_, 10, bow_);			//todo написать входящие в конструкторры элементы

	++_stage;
	return new door();
}


control::~control()
{
}
