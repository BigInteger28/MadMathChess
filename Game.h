#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <vector>

using namespace std;

class Game
{
	int GRID_WIDTH;
	int GRID_EDGE;
	int GRID_SIZE;
	char PIECES[12] = {'P', 'N', 'B', 'R', 'Q', 'K', 'p', 'n', 'b', 'r', 'q', 'k'};
	int piecesPos[12];
	int *grid;
	int to_sq(int y, int x);
	int goNorth(int square, int value);
	int goEast(int square, int value);
	int goSouth(int square, int value);
	int goWest(int square, int value);
	int goNorthEast(int square, int value);
	int goSouthEast(int square, int value);
	int goSouthWest(int square, int value);
	int goNorthWest(int square, int value);
	void takePiece(int own, int newSquare);
	bool whiteWon();
	bool blackWon();

public:
	Game(int grid_width, string boardsetup);
	~Game();
	void drawBoard();
	void doWhitePawn();
	void doWhiteKnight();
	void doWhiteBishop();
	void doWhiteRook();
	void doWhiteQueen();
	void doWhiteKing();
	void doBlackPawn();
	void doBlackKnight();
	void doBlackBishop();
	void doBlackRook();
	void doBlackQueen();
	void doBlackKing();
};

#endif /* GAME_H_ */
