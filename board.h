#ifndef BOARD_H
#define BOARD_H
#include "piece.h"


class Board
{
private:
    Piece* squares[8][8];

public:
    Board();

    Piece* getPiece(int row, int col);

    void movePiece(Position s, Position d);

    void reset_board();
};

//s부터 d까지 직선 거리상에 다른 기물이 있는지 확인하는 함수
bool isPathClear(Position s, Position d, Piece* squares[8][8]);

#endif // BOARD_H