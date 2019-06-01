#include <iostream>
#include "list_of_functions.h"


using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	hero _hero(0, 20);
	_hero.push_weapon(new knife(2, earth_, 2, knife_));

	//cout << //приветствие

	while (_hero.get_balance() >= 0)
	{
		vector<door*> doors;

		doors = door_generator();

		cout << "Вы находитесь на уровне " << /*doors[0]->getStage() <<*/ "В конце темного коридора в тусклом свете факелов вы видите " << doors.size() << "  двери." << "\n";
		for (auto obj : doors)
			cout << obj->introduce() << '\n';

		cout << "Вы можете улучшить свое оружие. Похлопав по карманам, вы оцениваете свой инвентарь: ";
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

				switch (door_number)
				{
				case 1:
					if (doors[0]->getMA() == nullptr)
						cout << "Зал оказывается пустым, наверное, здесь уже кто-то побывал до вас." << endl;
					else {
						cout << doors[0]->getMA()->introduce() << endl;
						cout << "Введите единицу, чтобы напасть на этого головотяпа. \n Введите два, чтобы позорно отдать этому грязному грабителю свои гривны!";
						cin >> _select;
						if (_hero.get_balance() - doors[0]->getMA()->get_donate() < 0) {
							cout << "Вы хлопаете по карманам и с ужасом понимаете, что у вас не хватает денег для откупа. Остается лишь только набить морду этому говноеду." << endl;
							_select = 1;
						}
						switch (_select)
						{
						case 1:
							if (fight(_hero, doors[0]->getMA()))

								cout << "Резко уклонившись от монстра вы наносите сокрушительный удар. Поверженный монстр падает на холодный пол подземелья. " << endl;
							else
								cout << "Во время уклонения вы падаете и бьетесь головой об пол. Резко очнувшись вы оказываетесь в темном коридоре, проверив карманы вы обнаруживаете что пропало " << doors[0]->getMA()->get_sum_defeat() << " гривень." << endl;
							if (_hero.get_balance() < 0) 
							{
								cout << "СМЭРТЬ";
								break;
							}
							break;
						case 2:
							cout << "Монстр, довольно хрюкая, забирает ваши денежки и говорит: \"Можешь проходить дальше, бомжара\"." << endl;
							_hero.set_balance(_hero.get_balance() - doors[0]->getMA()->get_donate());
							break;
						default:
							break;
						}

					}

					if (doors[0]->getWA() == nullptr)
						cout << "Оружия в зале не оказалось!" << endl;
					else {
						cout << "Вы нашли покрытое пылью старое оружие. Это " << doors[0]->getWA()->introduce();
						_hero.push_weapon(doors[0]->getWA());
					}

					cout << "На полу вы находите " << doors[0]->getReward() << " гривень. Вы пережили этот этаж, что не может не радовать. Отряхнувшись, вы переходите на другой этаж." << endl;

					_hero.set_balance(_hero.get_balance() + doors[0]->getReward());

					break;
				case 2:

				default:
					break;
				}
			if (_hero.get_balance() > 1000){
				cout << "Вы набрали 1000 гривен, рискуя жизнью. В принципе, на пивко хватит... Это победа." << endl;
				break;
			}

		}

	system("pause");
	return 0;
}