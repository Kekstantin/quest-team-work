#include <iostream>
#include "list_of_functions.h"


using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	hero _hero(0, 20);
	_hero.push_weapon(new knife(2, earth_, 2, knife_));


	cout << "Вы просыпаетесь голым на полу с мыслями:'С кем я вчера бухал, где я?'. Рядом с вами лежит мешок с 20 гривнами и нож и вы отправляетесть искать выход" << endl;

	while (_hero.get_balance() >= 0)
	{
		vector<door*> doors;

		doors = door_generator();

		cout << "Вы находитесь на уровне " << /*doors[0]->getStage() <<*/ "В конце темного коридора в тусклом свете факелов вы видите " << doors.size() << "  двери." << "\n";
		for (auto obj : doors)
			cout << obj->introduce() << '\n';

		cout << "Вы можете улучшить свое оружие. Похлопав по карманам, вы оцениваете свой инвентарь, у вас есть: ";
		auto tmp = _hero.get_list_of_the_weapon();
		for (auto obj : tmp)
			cout << obj->introduce() << endl;
		bool select_up = 0;
		unsigned short int select_wp;
		cout << "Если вы хотите улучшить что-то из этого хлама введите один, если нет, то ноль: ";
		cin >> select_up;
		if (select_up == 1) {
			cout << "Введите номер средства умерщвления под апгрейд: ";
			cin >> select_wp;\

			if (_hero.get_balance() - tmp[select_wp - 1]->getCostOfUpgrade() > 0) {
				tmp[select_wp - 1]->upgrade_weapon();
				_hero.set_balance(_hero.get_balance() - tmp[select_wp - 1]->getCostOfUpgrade());
			}

			else
				cout << "У вас гривен не хватает!" << endl;
		}
			


			int door_number;
			cout << "Введите номер двери: ";
			cin >> door_number;
			unsigned short int _select;
			if (door_number <= doors.size() + 1)
				door_checker(_hero, doors, door_number);

			if (_hero.get_balance() > 1000){
				cout << "Вы набрали 1000 гривен, рискуя жизнью. В принципе, на пивко хватит... Это победа." << endl;
				break;
			}

		}

	system("pause");
	return 0;
}