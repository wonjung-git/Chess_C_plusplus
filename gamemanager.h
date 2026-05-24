#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H
#include "piece.h"
#include "board.h"

class GameManager
{
private:
    //black=0, white=1
    bool currentTurn;

    Board board;

public:
    GameManager();

    //허용되는 움직임인지 체크
    bool validateMove(Position s, Position d);

    //체크메이트 등의 상태 체크
    void checkState();

    //턴 변경
    void switchTurn();

    //게임 초기화
    void reset_game();

    Board getBoard();
};

#endif // GAMEMANAGER_H
