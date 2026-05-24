#include "board.h"

Board::Board() {}

Piece* Board::getPiece(int row, int col){
    return squares[row][col];
}

void Board::movePiece(Position s, Position d){
    //목적지에 이동
    if(squares[d.row][d.col] == nullptr){
        squares[d.row][d.col] = squares[s.row][s.col];
    }
    else{
        delete squares[d.row][d.col];
        squares[d.row][d.col] = squares[s.row][s.col];
    }

    //원래 있던곳 삭제
    delete squares[s.row][s.col];
    squares[s.row][s.col] = nullptr;
}

bool isPathClear(Position s, Position d, Piece* squares[8][8]){
    //도착지와 색이 같으면 못감
    if(squares[s.row][s.col]->getColor() == squares[d.row][d.col]->getColor())
        return 0;

    //대각선일때
    if(s.row != d.row && s.col != d.col){
        //아래 방향
        if(s.row < d.row){
            //오른쪽 방향
            if(s.col < d.col){
                for(int i=s.row+1, j=s.col+1; i<d.row && j<d.col;i++, j++){
                    if(squares[i][j] != nullptr) return 0;
                }
            }
            //왼쪽 방향
            else{
                for(int i=s.row+1, j=s.col-1; i<d.row && j>d.col;i++, j--){
                    if(squares[i][j] != nullptr) return 0;
                }
            }
        }
        //위 방향
        else{
            //오른쪽 방향
            if(s.col < d.col){
                for(int i=s.row-1, j=s.col+1; i>d.row && j<d.col;i--, j++){
                    if(squares[i][j] != nullptr) return 0;
                }
            }
            //왼쪽 방향
            else{
                for(int i=s.row-1, j=s.col-1; i>d.row && j>d.col;i--, j--){
                    if(squares[i][j] != nullptr) return 0;
                }
            }
        }
    }

    //좌우 직선일때
    else if(s.row == d.row){
        //오른쪽 방향
        if(s.col < d.col){
            for(int i=s.row, j=s.col+1; j<d.col; j++){
                if(squares[i][j] != nullptr) return 0;
            }
        }
        //왼쪽 방향
        else{
            for(int i=s.row, j=s.col-1; j>d.col; j--){
                if(squares[i][j] != nullptr) return 0;
            }
        }
    }

    //위아래 직선일때
    else{
        //아래쪽 방향
        if(s.row < d.row){
            for(int i=s.row+1, j=s.col; i<d.row; i++){
                if(squares[i][j] != nullptr) return 0;
            }
        }
        //위쪽 방향
        else{
            for(int i=s.row-1, j=s.col; i>d.row; i--){
                if(squares[i][j] != nullptr) return 0;
            }
        }
    }

    //전부에서 안걸렸을땐 True
    return 1;
}

void Board::reset_board(){
    //흑 쪽 기물
    squares[0][0] = new Rook(0, 0, 0);
    squares[0][1] = new Knight(0, 0, 1);
    squares[0][2] = new Bishop(0, 0, 2);
    squares[0][3] = new Queen(0, 0, 3);
    squares[0][4] = new King(0, 0, 4);
    squares[0][5] = new Bishop(0, 0, 5);
    squares[0][6] = new Knight(0, 0, 6);
    squares[0][7] = new Rook(0, 0, 7);
    for(int i=0; i<8; i++){
        squares[1][i] = new Pawn(0, 1, i);
    }

    //백 쪽 기물
    squares[7][0] = new Rook(1, 7, 0);
    squares[7][1] = new Knight(1, 7, 1);
    squares[7][2] = new Bishop(1, 7, 2);
    squares[7][3] = new Queen(1, 7, 3);
    squares[7][4] = new King(1, 7, 4);
    squares[7][5] = new Bishop(1, 7, 5);
    squares[7][6] = new Knight(1, 7, 6);
    squares[7][7] = new Rook(1, 7, 7);
    for(int i=0; i<8; i++){
        squares[6][i] = new Pawn(1, 6, i);
    }

    for(int i=2; i<6; i++){
        for(int j=0; j<8; j++){
            squares[i][j] = nullptr;
        }
    }
}