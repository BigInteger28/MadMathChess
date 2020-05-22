#include <boost/algorithm/string.hpp>
#include <string>
#include "game.h"
#include "movegen.h"

using namespace std;

int GRID_WIDTH;
int GRID_EDGE;
int GRID_SIZE;
int piecesPos[12]; //public
int *grid; //public

int Game::to_sq(int y, int x) {
	return x * GRID_WIDTH + y;
}

bool Game::whiteWon() {
	for (int i = 6; i < 12; i++) {
		if (piecesPos[i] != -1) return false;
	}
	return true;
}

bool Game::blackWon() {
	for (int i = 0; i < 6; i++) {
		if (piecesPos[i] != -1) return false;
	}
	return true;
}


void Game::drawBoard() {
	for (int y = GRID_EDGE; y >= 0; y--) {
		for (int x = 0; x <= GRID_EDGE; x++) {
			int pos = to_sq(y, x);
			bool piece = false;
			for (int i = 0; i < 12; i++) {
				if (pos == piecesPos[i]) {
					piece = true;
					cout << PIECES[i] << "\t";
				}
			}
			if (!piece) cout << grid[pos] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

Game::Game(int grid_width, string boardsetup) {
	GRID_WIDTH = grid_width;
	GRID_EDGE = GRID_WIDTH - 1;
	GRID_SIZE = GRID_WIDTH * GRID_WIDTH;
	grid = new int[GRID_SIZE];

	string text = boardsetup;
	vector<string> results;
	boost::split(results, text, [](char c)
			{return c == ',';});

	for (int i = 0; i < GRID_SIZE; i++) {
		if (results[i] == "P") {
			piecesPos[0] = i;
			grid[i] = 0;
		}
		else if (results[i] == "N") {
			piecesPos[1] = i;
			grid[i] = 0;
		}
		else if (results[i] == "B") {
			piecesPos[2] = i;
			grid[i] = 0;
		}
		else if (results[i] == "R") {
			piecesPos[3] = i;
			grid[i] = 0;
		}
		else if (results[i] == "Q") {
			piecesPos[4] = i;
			grid[i] = 0;
		}
		else if (results[i] == "K") {
			piecesPos[5] = i;
			grid[i] = 0;
		}
		else if (results[i] == "p") {
			piecesPos[6] = i;
		}
		else if (results[i] == "n") {
			piecesPos[7] = i;
			grid[i] = 0;
		}
		else if (results[i] == "b") {
			piecesPos[8] = i;
			grid[i] = 0;
		}
		else if (results[i] == "r") {
			piecesPos[9] = i;
			grid[i] = 0;
		}
		else if (results[i] == "q") {
			piecesPos[10] = i;
			grid[i] = 0;
		}
		else if (results[i] == "k") {
			piecesPos[11] = i;
			grid[i] = 0;
		}
		else grid[i] = stoi(results[i]);
	}
}

Game::~Game() {
	delete []grid;
}
