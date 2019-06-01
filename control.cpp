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
	if (_rnd >= MIN_GENERATION_LIMIT_DOOR_WITHOUT_MONSTER && _rnd < MAX_GENERATION_LIMIT_DOOR_WITHOUT_MONSTER)
		_ms = nullptr;
	if (_rnd >= MAX_GENERATION_LIMIT_DOOR_WITHOUT_MONSTER && _rnd < MAX_GENERATION_LIMIT_SLIME)
		_ms = new slime(_start_dmg_for_slime, NULL, _start_loose_balance_slime, _start_steal_balance_slime);			
	if (_rnd >= MAX_GENERATION_LIMIT_SLIME && _rnd < MAX_GENERATION_LIMIT_GOBLIN)
		_ms = new goblin(_start_dmg_for_goblin, NULL, _start_loose_balance_goblin, _start_steal_balance_goblin);		
	if (_rnd >= MAX_GENERATION_LIMIT_GOBLIN && _rnd <= MAX_GENERATION_LIMIT_SCP_173)
		_ms = new scp_173(_start_dmg_for_scp_173, NULL, _start_loose_balance_scp_173, _start_steal_balance_scp_173);	

	int _rnd1 = uid(_gen);

	if (_rnd >= MIN_GENERATION_LIMIT_DOOR_WITHOUT_WEAPON && _rnd < MAX_GENERATION_LIMIT_DOOR_WITHOUT_WEAPON)
		_ws = nullptr;
	if (_rnd >= MAX_GENERATION_LIMIT_DOOR_WITHOUT_WEAPON && _rnd < MAX_GENERATION_LIMIT_DOOR_MACE)
		_ws = new mace(_mace_dmg, water_, 2, mace_);		
	if (_rnd >= MAX_GENERATION_LIMIT_DOOR_MACE && _rnd < MAX_GENERATION_LIMIT_DOOR_SWORD)
		_ws = new sword(_sword_dmg, earth_, 4, sword_);		
	if (_rnd >= MAX_GENERATION_LIMIT_DOOR_SWORD && _rnd <= MAX_GENERATION_LIMIT_DOOR_BOW)
		_ws = new bow(_bow_dmg, air_, 10, bow_);		

	++_stage;
	return new door();
}


control::~control()
{
}
