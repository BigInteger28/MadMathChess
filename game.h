#ifndef GAME_H_
#define GAME_H_

#include <iostream>
#include <vector>

using namespace std;

class Game
{
private:
	int to_sq(int y, int x);
	void takePiece(int own, int newSquare);
	bool whiteWon();
	bool blackWon();

public:
	Game(int grid_width, string boardsetup);
	~Game();
	char PIECES[12] = {'P', 'N', 'B', 'R', 'Q', 'K', 'p', 'n', 'b', 'r', 'q', 'k'};
	void drawBoard();
	void drawBoard2();
	int piecesPos[12] = {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
	int *grid;
};

#endif /* GAME_H_ */
