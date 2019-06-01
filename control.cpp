#include "control.h"


control::control()
{
}

control control::initialization()
{
	static control _control;
	return _control;
}

door * control::create_door()
{
	std::mt19937 _gen(std::time(NULL));
	std::uniform_int_distribution<> uid(0, 50);
	monster_abs*  _ms= nullptr;
	weapon* _ws=nullptr;

	int _rnd = uid(_gen);
	if (_rnd >= MIN_GENERATION_LIMIT_DOOR_WITHOUT_MONSTER && _rnd < MAX_GENERATION_LIMIT_DOOR_WITHOUT_MONSTER)
		_ms = nullptr;
	if (_rnd >= MAX_GENERATION_LIMIT_DOOR_WITHOUT_MONSTER && _rnd < MAX_GENERATION_LIMIT_SLIME)
		_ms = new slime(_dmg_for_slime, NULL, _loose_balance_slime, _steal_balance_slime);			
	if (_rnd >= MAX_GENERATION_LIMIT_SLIME && _rnd < MAX_GENERATION_LIMIT_GOBLIN)
		_ms = new goblin(_dmg_for_goblin, NULL, _loose_balance_goblin, _steal_balance_goblin);		
	if (_rnd >= MAX_GENERATION_LIMIT_GOBLIN && _rnd <= MAX_GENERATION_LIMIT_SCP_173)
		_ms = new scp_173(_dmg_for_scp_173, NULL, _loose_balance_scp_173, _steal_balance_scp_173);	

	int _rnd1 = uid(_gen);

	if (_rnd >= MIN_GENERATION_LIMIT_DOOR_WITHOUT_WEAPON && _rnd < MAX_GENERATION_LIMIT_DOOR_WITHOUT_WEAPON)
		_ws = nullptr;
	if (_rnd >= MAX_GENERATION_LIMIT_DOOR_WITHOUT_WEAPON && _rnd < MAX_GENERATION_LIMIT_DOOR_MACE)
		_ws = new mace(_mace_dmg, water_, 2, mace_);		
	if (_rnd >= MAX_GENERATION_LIMIT_DOOR_MACE && _rnd < MAX_GENERATION_LIMIT_DOOR_SWORD)
		_ws = new sword(_sword_dmg, earth_, 4, sword_);		
	if (_rnd >= MAX_GENERATION_LIMIT_DOOR_SWORD && _rnd <= MAX_GENERATION_LIMIT_DOOR_BOW)
		_ws = new bow(_bow_dmg, air_, 10, bow_);		
	
	return new door(_ms, _ws, _balance_door, _stage);
}

void control::incriminate_stage(){
_steal_balance_slime = _steal_balance_slime * _multiplyer_for_loose_and_steal;
_steal_balance_goblin = _steal_balance_goblin * _multiplyer_for_loose_and_steal;
_steal_balance_scp_173 = _steal_balance_scp_173 * _multiplyer_for_loose_and_steal;

_loose_balance_slime = _loose_balance_slime * _multiplyer_for_loose_and_steal;
_loose_balance_goblin = _loose_balance_slime * _multiplyer_for_loose_and_steal;
_loose_balance_scp_173 = _loose_balance_slime * _multiplyer_for_loose_and_steal;

_dmg_for_slime = _dmg_for_slime * _multiplyer_for_monsters;
_dmg_for_goblin = _dmg_for_goblin * _multiplyer_for_monsters;
_dmg_for_scp_173 = _dmg_for_scp_173 * _multiplyer_for_monsters;

_balance_door = _balance_door * _multiplyer_for_rewards;

++_stage;

}

control::~control()
{
}
