#include <iostream>
#include "list_of_functions.h"


using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	hero _hero(0, 20);
	_hero.push_weapon(new knife(2, earth_, 2, knife_));

	//cout << //�����������

	while (_hero.get_balance() >= 0)
	{
		vector<door*> doors;

		doors = door_generator();

		cout << "�� ���������� �� ������ " << /*doors[0]->getStage() <<*/ "� ����� ������� �������� � ������� ����� ������� �� ������ " << doors.size() << "  �����." << "\n";
		for (auto obj : doors)
			cout << obj->introduce() << '\n';

		cout << "�� ������ �������� ���� ������. �������� �� ��������, �� ���������� ���� ���������: ";
		auto tmp = _hero.get_list_of_the_weapon();
		for (auto obj : tmp)
			cout << obj->introduce() << endl;
		bool select_up = 0;
		unsigned short int select_wp;
		cout << "���� �� ������ �������� ���-�� �� ����� ����� ������� ����, ���� ���, �� ����: ";
		cin >> select_up;
		if (select_up == 1) {
			cout << "������� ����� �������� ����������� ��� �������: ";
			cin >> select_wp;\

			if (_hero.get_balance() - tmp[select_wp - 1]->getCostOfUpgrade() > 0) {
				tmp[select_wp - 1]->upgrade_weapon();
				_hero.set_balance(_hero.get_balance() - tmp[select_wp - 1]->getCostOfUpgrade());
			}

			else
				cout << "� ��� ������ �� �������!" << endl;
		}
			


			int door_number;
			cout << "������� ����� �����: ";
			cin >> door_number;
			unsigned short int _select;
			if (door_number <= doors.size() + 1)

				switch (door_number)
				{
				case 1:
					if (doors[0]->getMA() == nullptr)
						cout << "��� ����������� ������, ��������, ����� ��� ���-�� ������� �� ���." << endl;
					else {
						cout << doors[0]->getMA()->introduce() << endl;
						cout << "������� �������, ����� ������� �� ����� ����������. \n ������� ���, ����� ������� ������ ����� �������� ��������� ���� ������!";
						cin >> _select;
						if (_hero.get_balance() - doors[0]->getMA()->get_donate() < 0) {
							cout << "�� �������� �� �������� � � ������ ���������, ��� � ��� �� ������� ����� ��� ������. �������� ���� ������ ������ ����� ����� ��������." << endl;
							_select = 1;
						}
						switch (_select)
						{
						case 1:
							if (fight(_hero, doors[0]->getMA()))

								cout << "����� ����������� �� ������� �� �������� �������������� ����. ����������� ������ ������ �� �������� ��� ����������. " << endl;
							else
								cout << "�� ����� ��������� �� ������� � ������� ������� �� ���. ����� ��������� �� ������������ � ������ ��������, �������� ������� �� ������������� ��� ������� " << doors[0]->getMA()->get_sum_defeat() << " �������." << endl;
							if (_hero.get_balance() < 0) 
							{
								cout << "������";
								break;
							}
							break;
						case 2:
							cout << "������, �������� ������, �������� ���� ������� � �������: \"������ ��������� ������, �������\"." << endl;
							_hero.set_balance(_hero.get_balance() - doors[0]->getMA()->get_donate());
							break;
						default:
							break;
						}

					}

					if (doors[0]->getWA() == nullptr)
						cout << "������ � ���� �� ���������!" << endl;
					else {
						cout << "�� ����� �������� ����� ������ ������. ��� " << doors[0]->getWA()->introduce();
						_hero.push_weapon(doors[0]->getWA());
					}

					cout << "�� ���� �� �������� " << doors[0]->getReward() << " �������. �� �������� ���� ����, ��� �� ����� �� ��������. ������������, �� ���������� �� ������ ����." << endl;

					_hero.set_balance(_hero.get_balance() + doors[0]->getReward());

					break;
				case 2:

				default:
					break;
				}
			if (_hero.get_balance() > 1000){
				cout << "�� ������� 1000 ������, ������ ������. � ��������, �� ����� ������... ��� ������." << endl;
				break;
			}

		}

	system("pause");
	return 0;
}