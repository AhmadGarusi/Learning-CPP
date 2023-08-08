#include <iostream>
#include <string>
using namespace std;

class Player
{
private:
	std::string name;
	char sign;

public:
	Player()
	{
	}

	void setName(const std::string name)
	{
		this->name = name;
	}

	void setSign(const char ch)
	{
		sign = ch;
	}

	std::string getName()
	{
		return name;
	}

	char getSign()
	{
		return sign;
	}

	void inputName()
	{
		std::cout << " enter your name plaese: ";
		std::cin >> name;
	}

	void inputSign()
	{
		std::cout << getName() << " please choose a sign: ";
		std::cin >> sign;
	}

	void input()
	{
		inputName();
		inputSign();
	}
};

class Game
{
private:
	char p[3][3];
	short int turn; // k shomarande ke bishtar az 9 nemire
	int counter;
	Player players[2];
	// int turn;
	int state; // 0 = normal, 1 = game end, 2 = draw
			   /* data */
public:
	Game()
	{
		state = 0;
		counter = 0;
		turn = 0;
		char k = '0';
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				k++;
				p[i][j] = k;
			} // for j
		}	  // for i
	}		  // Board

	void input()
	{
		players[0].input();
		players[1].input();
		while (players[1].getSign() == players[0].getSign())
		{
			std::cout << "players have same sign! ";
			players[1].inputSign();
		} // while
	}	  // input

	void run()
	{
		displayBoard();
		while (state == 0)
		{
			// get();
			turnMessage();

			displayBoard();
			// updateState();
			updateState();
			// changeTurn();
			if (state == 0)
				turn = ++turn % 2;
		} // while

		checkState();
	} // run

private:
	void turnMessage()
	{
		std::cout << players[turn].getName() << " enter a number between 1-9: ";
		getPlace();
	} // turnMessage

	void displayBoard()
	{
		std::cout << "\t\t\t\t     |     |     \n";
		std::cout << "\t\t\t\t  " << p[0][0] << "  |  " << p[0][1] << "  |  " << p[0][2] << " \n";
		std::cout << "\t\t\t\t_____|_____|_____\n";

		std::cout << "\t\t\t\t     |     |     \n";
		std::cout << "\t\t\t\t  " << p[1][0] << "  |  " << p[1][1] << "  |  " << p[1][2] << " \n";
		std::cout << "\t\t\t\t_____|_____|_____\n";

		std::cout << "\t\t\t\t     |     |     \n";
		std::cout << "\t\t\t\t  " << p[2][0] << "  |  " << p[2][1] << "  |  " << p[2][2] << " \n";
		std::cout << "\t\t\t\t     |     |     \n";
	} // displayBoard

	void updateState()
	{
		for (int i = 0; i < 3; i++)
		{
			if (p[i][0] == p[i][1] && p[i][1] == p[i][2])
			{
				state = 1;
				break;
			}
			if (p[0][i] == p[1][i] && p[1][i] == p[2][i])
			{
				state = 1;
				break;
			}
		}

		if (p[0][0] == p[1][1] && p[1][1] == p[2][2])
			state = 1;

		if (p[0][2] == p[1][1] && p[1][1] == p[2][0])
			state = 1;

		if (counter == 9)
			state = 2;
	} // check

	int getPlace()
	{
		int h;

		while (true)
		{
			std::cin >> h;
			if (h <= 9 && h >= 1)
			{
				h--;
				int i = h / 3, j = h % 3;
				p[i][j] = players[turn].getSign();
				break;
			}
			// 	if (h <= 9 && h >= 1)
			// {
			// 	for (int i = 0; i <= 2; i++)
			// 		for (int j = 0; j <= 2; j++)
			// 			if ((p[i][j] - '0') == h)
			// 			{
			// 				p[i][j] = players[turn].getSign();
			// 				counter++;
			// 				return 0;
			// 			}
			// 	std::cout << "space already have a sign try another number: ";
			// }
			else
				std::cout << "Wrong number :(    try again..\n";
		}
		counter++;
	}
	void checkState()
	{
		if (state == 1)
			std::cout << players[turn].getName() << " WON!!!";
		else if (state == 2)
			std::cout << "draw";
	}
};

int main()
{
	Game g;
	g.input();
	g.run();

	std::cin.get();
	return 0;
}