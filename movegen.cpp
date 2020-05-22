#include "movegen.h"


int goNorth(int square, int value) {
	return (square + value) % GRID_SIZE;
}

int goEast(int square, int value) {
	int dest = square;
	for (int i = 0; i < value; i++) {
		if (square < GRID_WIDTH * GRID_EDGE)
			dest = square + GRID_WIDTH;
		else dest = square + 1 -(GRID_WIDTH * GRID_EDGE);
	}
	return dest;
}

int goSouth(int square, int value) {
	return (square - value) % GRID_SIZE;
}

int goWest(int square, int value) {
	int dest = square;
	for (int i = 0; i < value; i++) {
		if (square > GRID_WIDTH)
			dest = square - GRID_WIDTH;
		else dest = square - 1 + (GRID_WIDTH * GRID_EDGE);
	}
	return dest;
}

int goNorthEast(int square, int value) {
	int dest = square;
	for (int i = 0; i < value; i++) {
		dest = goNorth(square, 1);
		dest = goEast(square, 1);
	}
	return dest;
}

int goSouthEast(int square, int value) {
	int dest = square;
	for (int i = 0; i < value; i++) {
		dest = goSouth(square, 1);
		dest = goEast(square, 1);
	}
	return dest;
}

int goSouthWest(int square, int value) {
	int dest = square;
	for (int i = 0; i < value; i++) {
		dest = goSouth(square, 1);
		dest = goWest(square, 1);
	}
	return dest;
}

int goNorthWest(int square, int value) {
	int dest = square;
	for (int i = 0; i < value; i++) {
		dest = goNorth(square, 1);
		dest = goWest(square, 1);
	}
	return dest;
}

void takePiece(int piecesPos[], int own, int newSquare) {
	for (int i = 0; i < 12; i++) {
		if (i != own && piecesPos[i] == newSquare) {
			piecesPos[i] = -1;
		}
	}
}

void doWhitePawn(int piecesPos[], int grid[]) {
	int square = piecesPos[0];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goNorth(square, 1);
	else newSquare = goNorth(square, value);
	piecesPos[0] = newSquare;
	takePiece(piecesPos, 0, newSquare);
}

void doWhiteKnight(int piecesPos[], int grid[]) {
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
	takePiece(piecesPos, 1, newSquare);
}

void doWhiteBishop(int piecesPos[], int grid[]) {
	int square = piecesPos[2];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goNorthEast(square, 1);
	else newSquare = goNorthEast(square, value);
	piecesPos[2] = newSquare;
	takePiece(piecesPos, 2, newSquare);
}

void doWhiteRook(int piecesPos[], int grid[]) {
	int square = piecesPos[3];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goEast(square, 1);
	else newSquare = goEast(square, value);
	piecesPos[3] = newSquare;
	takePiece(piecesPos, 3, newSquare);
}

void doWhiteQueen(int piecesPos[], int grid[]) {
	int square = piecesPos[4];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goNorthWest(square, 1);
	else newSquare = goNorthWest(square, value);
	piecesPos[4] = newSquare;
	takePiece(piecesPos, 4, newSquare);
}

void doWhiteKing(int piecesPos[], int grid[]) {
	int square = piecesPos[5];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goWest(square, 1);
	else newSquare = goWest(square, value);
	piecesPos[5] = newSquare;
	takePiece(piecesPos, 5, newSquare);
}

void doBlackPawn(int piecesPos[], int grid[]) {
	int square = piecesPos[6];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goSouth(square, 1);
	else newSquare = goSouth(square, value);
	piecesPos[6] = newSquare;
	takePiece(piecesPos, 6, newSquare);
}

void doBlackKnight(int piecesPos[], int grid[]) {
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
	takePiece(piecesPos, 7, newSquare);
}

void doBlackBishop(int piecesPos[], int grid[]) {
	int square = piecesPos[8];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goSouthWest(square, 1);
	else newSquare = goSouthWest(square, value);
	piecesPos[8] = newSquare;
	takePiece(piecesPos, 8, newSquare);
}

void doBlackRook(int piecesPos[], int grid[]) {
	int square = piecesPos[9];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goWest(square, 1);
	else newSquare = goWest(square, value);
	piecesPos[9] = newSquare;
	takePiece(piecesPos, 9, newSquare);
}

void doBlackQueen(int piecesPos[], int grid[]) {
	int square = piecesPos[10];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goSouthEast(square, 1);
	else newSquare = goSouthEast(square, value);
	piecesPos[10] = newSquare;
	takePiece(piecesPos, 10, newSquare);
}

void doBlackKing(int piecesPos[], int grid[]) {
	int square = piecesPos[11];
	int value = grid[square];
	int newSquare;
	if (value == 0) newSquare = goEast(square, 1);
	else newSquare = goEast(square, value);
	piecesPos[11] = newSquare;
	takePiece(piecesPos, 11, newSquare);
}


