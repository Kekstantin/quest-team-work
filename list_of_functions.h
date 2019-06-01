#pragma once
#include "control.h"
#include "hero.h"

using namespace std;

std::vector<door*> door_generator()
{
	std::mt19937 _gen(std::time(NULL));
	std::uniform_int_distribution<> uid(2, 4);

	int number_of_doors = uid(_gen);

	std::cout << (number_of_doors) << std::endl;
	std::vector<door*> doors(number_of_doors);
	for (int i = 0; i < number_of_doors; i++)
	{
		doors[i]=(control::initialization().create_door());
	}
	return doors;
}

bool fight(hero hero, monster_abs* monster)
{
	std::mt19937 _gen(std::time(NULL));
	std::uniform_int_distribution<> uid(0, 100);

	int your_damage = 0;
	for (auto obj : hero.get_list_of_the_weapon())
	{
		int damage_multiplier = 1;
		damage_multiplier *= obj->getDamage();
		if (obj->getCrit() == monster->get_monster_class())
			damage_multiplier *= 1.5;
		if (damage_multiplier > your_damage)
			your_damage = damage_multiplier;
	}
	int your_chance = your_damage / (your_damage + monster->get_damage());
	int win_number = uid(_gen);
	if (your_chance <= win_number)
		return true;
	else return false;
}

void door_checker(hero _hero, std::vector<door*> _doors, int _number_of_door) {

	unsigned short int _select;

		if (_doors[_number_of_door]->getMA() == nullptr)
			cout << "Зал оказывается пустым, наверное, здесь уже кто-то побывал до вас." << endl;
		else {
			cout << _doors[_number_of_door]->getMA()->introduce() << endl;
			cout << "Введите единицу, чтобы напасть на этого головотяпа. \n Введите два, чтобы позорно отдать этому грязному грабителю свои гривны!";
			cin >> _select;;
			if (_hero.get_balance() - _doors[_number_of_door]->getMA()->get_donate() < 0) {
				cout << "Вы хлопаете по карманам и с ужасом понимаете, что у вас не хватает денег для откупа. Остается лишь только набить морду этому говноеду." << endl;
				_select = 1;
			}
			switch (_select)
			{
			case 1:
				if (fight(_hero, _doors[_number_of_door]->getMA())) {

					cout << "Резко уклонившись от монстра вы наносите сокрушительный удар. Поверженный монстр падает на холодный пол подземелья. " << endl;
					//_hero.set_balance(_hero.get_balance() + doors[0]->getReward());
				}
				else
					cout << "Во время уклонения вы падаете и бьетесь головой об пол. Резко очнувшись вы оказываетесь в темном коридоре, проверив карманы вы обнаруживаете что пропало " << _doors[_number_of_door]->getMA()->get_sum_defeat() << " гривень." << endl;
				if (_hero.get_balance() < 0)
				{
					cout << "СМЭРТЬ";
					break;
				}
				break;
			case 2:
				cout << "Монстр, довольно хрюкая, забирает ваши денежки и говорит: \"Можешь проходить дальше, бомжара\"." << endl;
				_hero.set_balance(_hero.get_balance() - _doors[_number_of_door]->getMA()->get_donate());
				break;
			default:
				break;
			}

		}

		if (_doors[0]->getWA() == nullptr)
			cout << "Оружия в зале не оказалось!" << endl;
		else {
			cout << "Вы нашли покрытое пылью старое оружие. Это " << _doors[0]->getWA()->introduce();
			_hero.push_weapon(_doors[0]->getWA());
		}

		cout << "На полу вы находите " << _doors[0]->getReward() << " гривень. Вы пережили этот этаж, что не может не радовать. Отряхнувшись, вы переходите на другой этаж." << endl;
		_hero.set_balance(_hero.get_balance() + _doors[0]->getReward());
		cout << "В вашем кармане бряцает " << _hero.get_balance() << " гривень." << endl;

}


