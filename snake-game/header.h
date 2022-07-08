#pragma once
#include <conio.h>

class SnakeGame {
public:
	void CreateConsole(int width = 20, int height = 20) {
		nScreenWidth = width;
		nScreenHeight = height;
	}

	void Draw() {
		system("cls");

		for (int i = 0; i < nScreenHeight + 1; i++)
			cout << "#";
		cout << endl;

		for (int i = 0; i < nScreenHeight; i++) {
			for (int j = 0; j < nScreenWidth; j++) {
				if (j == 0 || j == nScreenWidth - 1)
					cout << "#";
				if (i == headY && j == headX)
					cout << "O";
				else if (i == fruitY && j == fruitX)
					cout << "F";
				else
					cout << " ";
			}
			cout << endl;
		}

		for (int i = 0; i < nScreenWidth + 1; i++)
			cout << "#";
		cout << endl;

		Input();
		Logic();
	};

	void Setup() {
		gameOver = false;
		direction = STOP;
		headX = nScreenWidth / 2;
		headY = nScreenHeight / 2;

		fruitX = rand() % nScreenWidth;
		fruitY = rand() % nScreenHeight;
	}

private:
	bool gameOver;
	int nScreenWidth;
	int nScreenHeight;
	int fruitX;
	int fruitY;
	int headX;
	int headY;

protected:
	enum eDirection {
		STOP = 0,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};
	eDirection direction;

	void Logic() {
		switch (direction) {
		case STOP:
			break;
		case LEFT:
			headX--;
			break;
		case RIGHT:
			headX++;
			break;
		case DOWN:
			headY++;
			break;
		case UP:
			headY--;
			break;
		}
	};

	void Input() {
		if (_kbhit()) {
			switch (_getch()) {
			case 'a':
				direction = LEFT;	
				break;

			case 's':
				direction = DOWN;
				break;

			case 'd':
				direction = RIGHT;
				break;

			case 'w':
				direction = UP;
				break;

			case 'x':
				gameOver = true;
				break;
			}
		}
	};
};