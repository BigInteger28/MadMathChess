#include <boost/algorithm/string.hpp>
#include <string>
#include "Game.h"

using namespace std;
/*
 * 	pnbr	0  1  2  3  4  5
 * 	0000	6  7  8  9  10 11
 * 	0000	12 13 14 15 16 17
 * 	PNBR    18 19 20 21 22 23
 * 			24 25 26 27 28 29
 * 			30 31 32 33 34 35
 * 			FILE=X-AS, RANK=Y-AS
 *
 * 			3  7  11 15
 * 			2  6  10 14
 * 			1  5  9  13
 * 			0  4  8  12
 *
 * 			5	11	17	23	29	35
 * 			4	10	16	22	28	34
 * 			3	9	15	21	27	33
 * 			2	8	14	20	26	32
 * 			1	7	13	19	25	31
 * 			0	6	12	18	24	30
 */

int GRID_WIDTH;
int GRID_EDGE;
int GRID_SIZE;
int piecesPos[12];
int *grid;

int Game::to_sq(int y, int x) {
	return x * GRID_WIDTH + y;
}

int Game::goNorth(int square, int value) {
	return (square + value) % GRID_SIZE;
}

int Game::goEast(int square, int value) {
	int dest = square;
	for (int i = 0; i < value; i++) {
		if (square < GRID_WIDTH * GRID_EDGE)
			dest = square + GRID_WIDTH;
		else dest = square + 1 -(GRID_WIDTH * GRID_EDGE);
	}
	return dest;
}

int Game::goSouth(int square, int value) {
	return (square - value) % GRID_SIZE;
}

int Game::goWest(int square, int value) {
	int dest = square;
	for (int i = 0; i < value; i++) {
		if (square > GRID_WIDTH)
			dest = square - GRID_WIDTH;
		else dest = square - 1 + (GRID_WIDTH * GRID_EDGE);
	}
	return dest;
}

int Game::goNorthEast(int square, int value) {
	int dest = square;
	for (int i = 0; i < value; i++) {
		dest = goNorth(square, 1);
		dest = goEast(square, 1);
	}
	return dest;
}

int Game::goSouthEast(int square, int value) {
	int dest = square;
	for (int i = 0; i < value; i++) {
		dest = goSouth(square, 1);
		dest = goEast(square, 1);
	}
	return dest;
}

int Game::goSouthWest(int square, int value) {
	int dest = square;
	for (int i = 0; i < value; i++) {
		dest = goSouth(square, 1);
		dest = goWest(square, 1);
	}
	return dest;
}

int Game::goNorthWest(int square, int value) {
	int dest = square;
	for (int i = 0; i < value; i++) {
		dest = goNorth(square, 1);
		dest = goWest(square, 1);
	}
	return dest;
}

void Game::takePiece(int own, int newSquare) {
	for (int i = 0; i < 12; i++) {
		if (i != own && piecesPos[i] == newSquare) {
			piecesPos[i] = -1;
		}
	}
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
			for (int i = 0; i <= 12; i++) {
				if (pos == piecesPos[i]) {
					cout << PIECES[i] << "\t";
					piece = true;
				}
			}
			if (!piece) cout << grid[pos] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void Game::doWhitePawn() {
	int square = piecesPos[0];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goNorth(square, 1);
	else newSquare = goNorth(square, value);
	piecesPos[0] = newSquare;
	takePiece(0, newSquare);
}

void Game::doWhiteKnight() {
	int square = piecesPos[1];
	int value = grid[square];
	int newSquare;
	if (value == 0) {
		newSquare = goEast(square, 2);
		newSquare = goNorth(square, 1);
	}
	else {
		for (int i = 0; i < value; i++) {
			newSquare = goEast(square, 2);
			newSquare = goNorth(square, 1);
		}
	}
	piecesPos[1] = newSquare;
	takePiece(1, newSquare);
}

void Game::doWhiteBishop() {
	int square = piecesPos[2];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goNorthEast(square, 1);
	else newSquare = goNorthEast(square, value);
	piecesPos[2] = newSquare;
	takePiece(2, newSquare);
}

void Game::doWhiteRook() {
	int square = piecesPos[3];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goEast(square, 1);
	else newSquare = goEast(square, value);
	piecesPos[3] = newSquare;
	takePiece(3, newSquare);
}

void Game::doWhiteQueen() {
	int square = piecesPos[4];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goNorthWest(square, 1);
	else newSquare = goNorthWest(square, value);
	piecesPos[4] = newSquare;
	takePiece(4, newSquare);
}

void Game::doWhiteKing() {
	int square = piecesPos[5];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goWest(square, 1);
	else newSquare = goWest(square, value);
	piecesPos[5] = newSquare;
	takePiece(5, newSquare);
}

void Game::doBlackPawn() {
	int square = piecesPos[6];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goSouth(square, 1);
	else newSquare = goSouth(square, value);
	piecesPos[6] = newSquare;
	takePiece(6, newSquare);
}

void Game::doBlackKnight() {
	int square = piecesPos[7];
	int value = grid[square];
	int newSquare;
	if (value == 0) {
		newSquare = goWest(square, 2);
		newSquare = goSouth(square, 1);
	}
	else {
		for (int i = 0; i < value; i++) {
			newSquare = goWest(square, 2);
			newSquare = goSouth(square, 1);
		}
	}
	piecesPos[7] = newSquare;
	takePiece(7, newSquare);
}

void Game::doBlackBishop() {
	int square = piecesPos[8];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goSouthWest(square, 1);
	else newSquare = goSouthWest(square, value);
	piecesPos[8] = newSquare;
	takePiece(8, newSquare);
}

void Game::doBlackRook() {
	int square = piecesPos[9];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goWest(square, 1);
	else newSquare = goWest(square, value);
	piecesPos[9] = newSquare;
	takePiece(9, newSquare);
}

void Game::doBlackQueen() {
	int square = piecesPos[10];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goSouthEast(square, 1);
	else newSquare = goSouthEast(square, value);
	piecesPos[10] = newSquare;
	takePiece(10, newSquare);
}

void Game::doBlackKing() {
	int square = piecesPos[11];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goEast(square, 1);
	else newSquare = goEast(square, value);
	piecesPos[11] = newSquare;
	takePiece(11, newSquare);
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

		for (int i = 0; i < 12; i++) {
			if (piecesPos[i] < -1 || piecesPos[i] > GRID_SIZE) piecesPos[i] = -1;
		}
	}
}

Game::~Game() {
	delete []grid;
}
