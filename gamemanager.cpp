#include "gamemanager.h"
#include "piece.h"
#include "board.h"

GameManager::GameManager() {}

void GameManager::reset_game(){
    board.reset_board();
}

Board GameManager::getBoard(){
    return board;
}
