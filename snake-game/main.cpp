#include <iostream>

using namespace std;

#include "header.h"

bool gameOver;
int score;

SnakeGame game;

int main() {
	game.CreateConsole();
	game.Setup();

	while (!gameOver) {
		game.Draw();
	}
	return 0;
}