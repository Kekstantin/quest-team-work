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
			cout << "��� ����������� ������, ��������, ����� ��� ���-�� ������� �� ���." << endl;
		else {
			cout << _doors[_number_of_door]->getMA()->introduce() << endl;
			cout << "������� �������, ����� ������� �� ����� ����������. \n ������� ���, ����� ������� ������ ����� �������� ��������� ���� ������!";
			cin >> _select;;
			if (_hero.get_balance() - _doors[_number_of_door]->getMA()->get_donate() < 0) {
				cout << "�� �������� �� �������� � � ������ ���������, ��� � ��� �� ������� ����� ��� ������. �������� ���� ������ ������ ����� ����� ��������." << endl;
				_select = 1;
			}
			switch (_select)
			{
			case 1:
				if (fight(_hero, _doors[_number_of_door]->getMA())) {

					cout << "����� ����������� �� ������� �� �������� �������������� ����. ����������� ������ ������ �� �������� ��� ����������. " << endl;
					//_hero.set_balance(_hero.get_balance() + doors[0]->getReward());
				}
				else
					cout << "�� ����� ��������� �� ������� � ������� ������� �� ���. ����� ��������� �� ������������ � ������ ��������, �������� ������� �� ������������� ��� ������� " << _doors[_number_of_door]->getMA()->get_sum_defeat() << " �������." << endl;
				if (_hero.get_balance() < 0)
				{
					cout << "������";
					break;
				}
				break;
			case 2:
				cout << "������, �������� ������, �������� ���� ������� � �������: \"������ ��������� ������, �������\"." << endl;
				_hero.set_balance(_hero.get_balance() - _doors[_number_of_door]->getMA()->get_donate());
				break;
			default:
				break;
			}

		}

		if (_doors[0]->getWA() == nullptr)
			cout << "������ � ���� �� ���������!" << endl;
		else {
			cout << "�� ����� �������� ����� ������ ������. ��� " << _doors[0]->getWA()->introduce();
			_hero.push_weapon(_doors[0]->getWA());
		}

		cout << "�� ���� �� �������� " << _doors[0]->getReward() << " �������. �� �������� ���� ����, ��� �� ����� �� ��������. ������������, �� ���������� �� ������ ����." << endl;
		_hero.set_balance(_hero.get_balance() + _doors[0]->getReward());
		cout << "� ����� ������� ������� " << _hero.get_balance() << " �������." << endl;

}


