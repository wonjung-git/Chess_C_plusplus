#include "piece.h"
#include "board.h"
#include "mymath.h"

Piece::Piece() {}

bool Piece::getColor(){
    return color;
}

Position Piece::getPosition(){
    return position;
}

King::King(bool c, int row, int col){
    color = c;
    position.row = row;
    position.col = col;
}

bool King::canMove(Position d, Piece* squares[8][8]) {
    if(MyAbs(d.row-position.row)>1 || MyAbs(d.col-position.col)>1) return 0;
    else return 1;
}

QString King::getSymbol() {
    if(color) return "♔";
    else return "♚";
}

Queen::Queen(bool c, int row, int col){
    color = c;
    position.row = row;
    position.col = col;
}

bool Queen::canMove(Position d, Piece* squares[8][8]) {
    if((MyAbs(d.row-position.row) != MyAbs(d.col-position.col)) && (position.row != d.row && position.col != d.col)) return 0;

    return isPathClear(position, d, squares);
}

QString Queen::getSymbol() {
    if(color) return "♕";
    else return "♛";
}

Rook::Rook(bool c, int row, int col){
    color = c;
    position.row = row;
    position.col = col;
}

bool Rook::canMove(Position d, Piece* squares[8][8]) {
    if(position.row != d.row && position.col != d.col) return 0;

    return isPathClear(position, d, squares);
}

QString Rook::getSymbol() {
    if(color) return "♖";
    else return "♜";
}

Bishop::Bishop(bool c, int row, int col){
    color = c;
    position.row = row;
    position.col = col;
}

bool Bishop::canMove(Position d, Piece* squares[8][8]) {
    if(MyAbs(d.row-position.row) != MyAbs(d.col-position.col)) return 0;

    return isPathClear(position, d, squares);
}

QString Bishop::getSymbol() {
    if(color) return "♗";
    else return "♝";
}

Knight::Knight(bool c, int row, int col){
    color = c;
    position.row = row;
    position.col = col;
}

bool Knight::canMove(Position d, Piece* squares[8][8]) {
    int row = MyAbs(d.row-position.row);
    int col = MyAbs(d.col-position.col);

    bool result = (row == 2 && col == 1) || (row == 1 && col == 2);

    return result;
}

QString Knight::getSymbol() {
    if(color) return "♘";
    else return "♞";
}

Pawn::Pawn(bool c, int row, int col){
    color = c;
    position.row = row;
    position.col = col;
}

bool Pawn::canMove(Position d, Piece* squares[8][8]) {
    //앞 한칸
    if(d.row == position.row + 1 && d.col == position.col && squares[d.row][d.col] == nullptr)
        return 1;

    //대각선 공격 가능 한칸
    if(d.row == position.row + 1 && ((d.col == position.col-1) || (d.col == position.col+1)) && squares[d.row][d.col] != nullptr)
        return 1;

    //첫 move면 2칸 앞도 가능
    if(move==0 && d.row == position.row + 2 && d.col == position.col && squares[d.row][d.col] == nullptr)
        return 1;

    return 0;
}

QString Pawn::getSymbol() {
    if(color) return "♙";
    else return "♟";
}