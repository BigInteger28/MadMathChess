#ifndef MOVEGEN_H_
#define MOVEGEN_H_


extern int GRID_WIDTH;
extern int GRID_EDGE;
extern int GRID_SIZE;

int goNorth(int square, int value);
int goEast(int square, int value);
int goSouth(int square, int value);
int goWest(int square, int value);
int goNorthEast(int square, int value);
int goSouthEast(int square, int value);
int goSouthWest(int square, int value);
int goNorthWest(int square, int value);
void takePiece(int piecesPos[], int own, int newSquare);
void doWhitePawn(int piecesPos[], int grid[]);
void doWhiteKnight(int piecesPos[], int grid[]);
void doWhiteBishop(int piecesPos[], int grid[]);
void doWhiteRook(int piecesPos[], int grid[]);
void doWhiteQueen(int piecesPos[], int grid[]);
void doWhiteKing(int piecesPos[], int grid[]);
void doBlackPawn(int piecesPos[], int grid[]);
void doBlackKnight(int piecesPos[], int grid[]);
void doBlackBishop(int piecesPos[], int grid[]);
void doBlackRook(int piecesPos[], int grid[]);
void doBlackQueen(int piecesPos[], int grid[]);
void doBlackKing(int piecesPos[], int grid[]);


#endif /* MOVEGEN_H_ */
