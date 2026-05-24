# Chess Project
객체지향프로그래밍설계 수업 4차 과제 - C++ Qt로 구현한 체스 게임

## 개발 환경
- C++
- Qt 6.11.1
- Qt Creator

## 클래스 구조
- MainWindow : UI 담당 (drawBoard, handleClick)
- GameManager : 게임 로직 담당 (validateMove, checkState, switchTurn)
- Board : 보드 상태 관리 (squares[8][8], movePiece)
- Piece : 기물 추상 클래스
  - King, Queen, Rook, Bishop, Knight, Pawn

## 빌드 방법
Qt Creator에서 CMakeLists.txt 열고 빌드
