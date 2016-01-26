// Zad1_CV.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <random>
#include <vector>
#include <string>

using namespace std;

class Person {
protected:
	int player1;
	int player2;


public:
	void virtual game() = 0;
	/*void virtual game1() {
	std::cout << "class Person" << std::endl;
	}*/
	int virtual ret1() = 0;
	int virtual ret2() = 0;


};

class Player : public Person {

private:
	std::string name1;
	std::string name2;


public:
	Player(std::string _name1, std::string _name2) {

		name1 = _name1;
		name2 = _name2;
	}

	void game();
	//void game1();
	int ret1();
	int ret2();


};


int Player::ret1() {
	return player1;
}

int Player::ret2() {
	return player2;
}

void Player::game() {

	random_device _rand;
	mt19937 _generator(_rand());
	uniform_int_distribution <> dis(1, 6);

	int dice1, dice2;
	

	dice1 = dis(_generator);
	dice2 = dis(_generator);

	player1 = dice1 + dice2;

	dice1 = dis(_generator);
	dice2 = dis(_generator);

	player2 = dice1 + dice2;

	cout << "\t" << name1 << "\t\t\t\t" << name2 << endl;
	cout << "\t" << player1 << "\t\t\t\t" << player2 << endl;

	if (player1 > player2) {
		cout << "\t\t\t" << name1 << " WON!!" << endl << endl;
	}
	if (player2 > player1) {
		cout << "\t\t\t" << name2 << " WON!!" << endl << endl;
	}
	if (player1 == player2) {
		cout << "\t\t\t" << "DRAW!!" << endl << endl;
	}



}

int main()
{
	//Gra - rzut dwoma kostkami
	
	vector <int> _playerV1;
	vector <int> _playerV2;

	int *wsk;
	wsk = wsk + 1;
	int _zm1, _zm2;
	
	char _cplayer1[20], _cplayer2[6];
	cout << "Player one. Write your name: ";
	cin >> _cplayer1;
	cout << endl;

	cout << "Player two. Write your name: ";
	cin >> _cplayer2;
	cout << endl;

	
	string _player1(_cplayer1);
	string _player2(_cplayer2);
	cout << "Player two. Name: " << _player2 << endl;
	cout << endl << endl;
	
	Person *_player;
	_player = new Player(_player1, _player2);

	random_device _rand;
	mt19937 _generation(_rand());
	uniform_int_distribution <> dis(1, 2);

	int _number1 = dis(_generation);
	
	string _sel = " ";

	switch (_number1)
	{
	case 1:
		while (_sel != "Q") {

			_player->game();
			_zm1 = _player->ret1();
			_playerV1.push_back(_zm1);
			_zm2 = _player->ret2();
			_playerV2.push_back(_zm2);
			cout << endl << "[Q] - quit" << endl;
			cout << endl << "[C] - continue" << endl;
			cin >> _sel;
		}

	case 2:
		do
		{
			_player->game();
			_zm1 = _player->ret1();
			_playerV1.push_back(_zm1);
			_zm2 = _player->ret2();
			_playerV2.push_back(_zm2);
			cout << endl << "[Q] - quit" << endl;
			cout << endl << "[C] - continue" << endl;
			cin >> _sel;
		} while (_sel != "Q");
	default:
		break;
	}
	
	for (int i = 1; i < _playerV1.size(); i++)
	{
		cout << "Round " << i << " : " << _playerV1[i - 1] << endl;
	}

	for (int i = 1; i < _playerV2.size(); i++)
	{
		cout << "Round " << i << " : " << _playerV2[i - 1] << endl;
	}

	_playerV1.clear();
	_playerV2.clear();
	delete _player;

    return 0;
}

