// Zad1_CV.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <random>
#include <string>

using namespace std;

class Person {

public:
	void virtual game() = 0;
	void virtual game1() {
		std::cout << "class Person" << std::endl;
	}



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


};

void Player::game() {

	random_device _rand;
	mt19937 _generator(_rand());
	uniform_int_distribution <> dis(1, 6);

	int dice1, dice2;
	int player1, player2;

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
	
	string _player1, _player2;
	cout << "Player one. Write your name: ";
	cin >> _player1;
	cout << endl;
	cout << "Player two. Write your name: ";
	cin >> _player2;
	cout << endl << endl;
	Person *_player;
	_player = new Player(_player1, _player2);
	_player->game();
	_player->game1();


    return 0;
}

