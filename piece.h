#ifndef PIECE_H
#define PIECE_H
#include "QString"

struct Position{
    int row;
    int col;
};

class Piece
{
protected:
    //0은 black, 1이 white
    bool color;

    Position position;

public:
    Piece();

    bool virtual canMove(Position d, Piece* squares[8][8]) = 0;
    bool getColor();
    Position getPosition();
    QString virtual getSymbol() = 0;
};

class King : public Piece
{
public:
    King(bool c, int row, int col);

    bool canMove(Position d, Piece* squares[8][8]) override;
    QString getSymbol() override;
};

class Queen : public Piece
{
public:
    Queen(bool c, int row, int col);

    bool canMove(Position d, Piece* squares[8][8]) override;
    QString getSymbol() override;
};

class Rook : public Piece
{
public:
    Rook(bool c, int row, int col);

    bool canMove(Position d, Piece* squares[8][8]) override;
    QString getSymbol() override;
};

class Bishop : public Piece
{
public:
    Bishop(bool c, int row, int col);

    bool canMove(Position d, Piece* squares[8][8]) override;
    QString getSymbol() override;
};

class Knight : public Piece
{
public:
    Knight(bool c, int row, int col);

    bool canMove(Position d, Piece* squares[8][8]) override;
    QString getSymbol() override;
};

class Pawn : public Piece
{
private:
    bool move=0;
public:
    Pawn(bool c, int row, int col);

    bool canMove(Position d, Piece* squares[8][8]) override;
    QString getSymbol() override;
};

#endif // PIECE_H
