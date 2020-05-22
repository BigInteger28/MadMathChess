#include "engine.h"

#include <iostream>
#include <vector>

//using namespace std;

Engine::Engine() {
	//string position = "all";
	//int depth = 2;
	//cout << scoreOfPositionDepth(position, depth, -10000, 10000, true);

}

Engine::~Engine() {
	// TODO Auto-generated destructor stub
}

////////////////private///////////////////

/*  WHAT TO DO
*   legalmoves, minmax, wincond, pos inlezen, thread
*
*   DONE
*
*/




///////////////public//////////////////////


//bool gameOver(string position){return true;}
//int evaluation(string position)
//{
//	if (position == "all") return 2;
//	if (position == "bal") return -3;
//	if (position == "atr") return 5;
//	if (position == "cll") return -1;
//	return 0;
//}
//int amountpositions = 5;

//vector<string>  generateAllLegalMoves()
//{
//	vector<string> pos(4);
//	pos[0] = "all";
//	pos[1] = "bal";
//	pos[2] = "atr";
//	pos[3] = "cll";
//	return pos;
//}
/*
int scoreOfPositionDepth(string position, int depth, int alpha, int beta, bool maximizingPlayer)
{
	if (depth == 0 || gameOver(position))
		return evaluation(position);

	if (maximizingPlayer)
	{
		int maxEval = -10000;
		vector<string> legalPositions = generateAllLegalMoves();
		for (string position : legalPositions)
		{
			int eval = scoreOfPositionDepth(position, depth - 1, alpha, beta, false);
			int maxEval = max(maxEval, eval);
			int alpha = max(alpha, eval);
			if (beta <= alpha) break;
		}
		return maxEval;
	}

	else
	{
		int minEval = 10000;
		vector<string> legalPositions = generateAllLegalMoves();
		for (string position : legalPositions)
		{
			int eval = scoreOfPositionDepth(position, depth - 1, alpha, beta, true);
			int minEval = min(minEval, eval);
			int beta = min(beta, eval);
			if (beta <= alpha) break;
		}
		return minEval;
	}
}
*/
