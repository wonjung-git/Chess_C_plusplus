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

## 수정사항
첫 개발 시작 커밋
1. 초기 화면(start page) 구현
2. 기본 클래스 구성 완료
3. 메인 플레이화면 초기 세팅 구현
