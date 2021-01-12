#define BOOST_TEST_MODULE statki
#include <boost/test/included/unit_test.hpp>

#include "board.h"
#include "field.h"
#include "game.h"
#include "player.h"
#include "ship.h"

BOOST_AUTO_TEST_SUITE(field)

BOOST_AUTO_TEST_CASE(field_set_get1) {
  Field a;
  BOOST_CHECK(a.GetIsOccupied() == false);
  BOOST_CHECK(a.GetIsHit() == false);
  a.SetIsOccupied(true);
  BOOST_CHECK(a.GetIsOccupied() == true);
  BOOST_CHECK(a.GetIsHit() == false);
}

BOOST_AUTO_TEST_CASE(field_set_get2) {
  Field a;
  BOOST_CHECK(a.GetIsOccupied() == false);
  BOOST_CHECK(a.GetIsHit() == false);
  a.SetIsOccupied(false);
  BOOST_CHECK(a.GetIsOccupied() == false);
  BOOST_CHECK(a.GetIsHit() == false);
}

BOOST_AUTO_TEST_CASE(field_ShotField1) {
  Field a;
  a.SetIsOccupied(true);
  BOOST_CHECK(a.GetIsHit() == false);
  BOOST_CHECK(a.GetIsOccupied() == true);
  BOOST_CHECK(a.ShotField() == true);
  BOOST_CHECK(a.GetIsHit() == true);
  BOOST_CHECK(a.GetIsOccupied() == true);
}

BOOST_AUTO_TEST_CASE(field_ShotField2) {
  Field a;
  BOOST_CHECK(a.GetIsOccupied() == false);
  BOOST_CHECK(a.GetIsHit() == false);
  BOOST_CHECK(a.ShotField() == false);
  BOOST_CHECK(a.GetIsHit() == true);
  BOOST_CHECK(a.GetIsOccupied() == false);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(board)

BOOST_AUTO_TEST_CASE(board_get) {
  std::array<bool, 100> board;
  for (int i = 0; i < 100; ++i) {
    if (i % 3 == 0) {
      board[i] = true;
    } else {
      board[i] = false;
    }
  }
  Board tab = Board(board);
  bool pom;
  for (int i = 0; i < 100; ++i) {
    if (i % 3 == 0) {
      pom = true;
    } else {
      pom = false;
    }
    BOOST_CHECK(tab.GetIsOccupied(i) == pom);
    BOOST_CHECK(tab.GetIsHit(i) == false);
  }
  BOOST_CHECK(tab.Shot(0) == true);
  BOOST_CHECK(tab.GetIsHit(0) == true);
}
BOOST_AUTO_TEST_CASE(board_Shot) {
  std::array<bool, 100> board = {false};
  board[4] = true;
  Board tab = Board(board);
  BOOST_CHECK(tab.Shot(0) == false);
  BOOST_CHECK(tab.Shot(4) == true);
  BOOST_CHECK(tab.GetIsHit(0) == true);
  BOOST_CHECK(tab.GetIsHit(4) == true);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(ship)

BOOST_AUTO_TEST_CASE(ship_GetSize) {
  std::vector<int> vec = {1, 5, 6};
  Ship ship = Ship(vec);
  BOOST_CHECK(ship.GetSize() == 3);
}

BOOST_AUTO_TEST_CASE(ship_GetIsAfloat) {
  std::vector<int> vec = {1, 5, 6};
  Ship ship = Ship(vec);
  BOOST_CHECK(ship.GetIsAfloat() == false);
}

BOOST_AUTO_TEST_CASE(ship_GetIsAfloat_sunk) {
  std::vector<int> vec = {1, 5, 6};
  Ship ship = Ship(vec);
  ship.Sunk();
  BOOST_CHECK(ship.GetIsAfloat() == true);
}

BOOST_AUTO_TEST_CASE(ship_IsInField) {
  std::vector<int> vec = {1, 5, 6};
  Ship ship = Ship(vec);
  BOOST_CHECK(ship.IsInField(5) == true);
  BOOST_CHECK(ship.IsInField(7) == false);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(player)

BOOST_AUTO_TEST_CASE(player_GetIsSunk1) {
  std::array<bool, 100> board = {false};
  board[1] = true;
  board[2] = true;
  Player player = Player(board);
  BOOST_CHECK(player.GetIsSunk(2).size() == 0);
  BOOST_CHECK(player.GetIsSunk(36).size() == 0);
}

BOOST_AUTO_TEST_CASE(player_Shot_GetIsSunk1) {
  std::array<bool, 100> board = {false};
  board[0] = true;
  board[1] = true;
  board[2] = true;
  Player player = Player(board);
  BOOST_CHECK(player.Shot(1) == true);
  BOOST_CHECK(player.GetIsSunk(1).size() == 0);
}

BOOST_AUTO_TEST_CASE(player_Shot1) {
  std::array<bool, 100> board = {false};
  board[0] = true;
  board[1] = true;
  board[2] = true;
  Player player = Player(board);
  BOOST_CHECK(player.Shot(1) == true);
  BOOST_CHECK(player.Shot(0) == true);
  BOOST_CHECK(player.Shot(2) == true);
  BOOST_CHECK(player.GetIsSunk(0).size() == 3);
}

BOOST_AUTO_TEST_CASE(player_Shot_GetIsSunk2) {
  std::array<bool, 100> board = {false};
  board[99] = true;
  board[89] = true;
  Player player = Player(board);
  BOOST_CHECK(player.Shot(99) == true);
  BOOST_CHECK(player.GetIsSunk(99).size() == 0);
}

BOOST_AUTO_TEST_CASE(player_Shot2) {
  std::array<bool, 100> board = {false};
  board[99] = true;
  board[89] = true;
  Player player = Player(board);
  BOOST_CHECK(player.Shot(99) == true);
  BOOST_CHECK(player.Shot(89) == true);
  BOOST_CHECK(player.GetIsSunk(99).size() == 2);
}

BOOST_AUTO_TEST_CASE(player_Shot3) {
  std::array<bool, 100> board = {false};
  board[45] = true;
  Player player = Player(board);
  BOOST_CHECK(player.Shot(45) == true);
  BOOST_CHECK(player.GetIsSunk(45).size() == 1);
}

BOOST_AUTO_TEST_CASE(player_Shot4) {
  std::array<bool, 100> board = {false};
  board[45] = true;
  Player player = Player(board);
  BOOST_CHECK(player.Shot(46) == false);
  BOOST_CHECK(player.GetIsSunk(46).size() == 0);
}

BOOST_AUTO_TEST_CASE(player_endGame1) {
  std::array<bool, 100> board = {false};
  board[45] = true;
  Player player = Player(board);
  BOOST_CHECK(player.EndGame() == false);
}

BOOST_AUTO_TEST_CASE(player_endGame2) {
  std::array<bool, 100> board = {false};
  board[45] = true;
  Player player = Player(board);
  BOOST_CHECK(player.Shot(45) == true);
  BOOST_CHECK(player.EndGame() == true);
}

BOOST_AUTO_TEST_CASE(player_endGame3) {
  std::array<bool, 100> board = {false};
  board[45] = true;
  board[22] = true;
  Player player = Player(board);
  BOOST_CHECK(player.Shot(45) == true);
  BOOST_CHECK(player.EndGame() == false);
}

BOOST_AUTO_TEST_CASE(player_isGood1) {
  std::array<bool, 100> board = {false};
  Player player = Player(board);
  BOOST_CHECK(player.IsGood() == false);
}

BOOST_AUTO_TEST_CASE(player_isGood2) {
  std::array<bool, 100> board = {false};
  board[0] = true;
  board[11] = true;
  Player player = Player(board);
  BOOST_CHECK(player.IsGood() == false);
}

BOOST_AUTO_TEST_CASE(player_isGood3) {
  std::array<bool, 100> board = {false};
  board[2] = true;
  board[11] = true;
  Player player = Player(board);
  BOOST_CHECK(player.IsGood() == false);
}

BOOST_AUTO_TEST_CASE(player_isGood4) {
  std::array<bool, 100> board = {false};
  board[2] = true;
  board[12] = true;
  board[3] = true;
  Player player = Player(board);
  BOOST_CHECK(player.IsGood() == false);
}

BOOST_AUTO_TEST_CASE(player_isGood5) {
  std::array<bool, 100> board = {false};
  board[0] = true;
  board[1] = true;
  board[2] = true;
  board[3] = true;
  board[4] = true;
  board[23] = true;
  board[24] = true;
  board[25] = true;
  board[26] = true;
  board[41] = true;
  board[42] = true;
  board[43] = true;
  board[67] = true;
  board[68] = true;
  board[83] = true;
  Player player = Player(board);
  BOOST_CHECK(player.IsGood() == true);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(game)

BOOST_AUTO_TEST_CASE(game_Shot1) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  firstBoard[30] = true;
  secondBoard[57] = true;
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.Shot(30, 1) == false);
  BOOST_CHECK(game.Shot(57, 1) == true);
}

BOOST_AUTO_TEST_CASE(game_Shot2) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  firstBoard[30] = true;
  secondBoard[57] = true;
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.Shot(30, 2) == true);
  BOOST_CHECK(game.Shot(57, 2) == false);
}

BOOST_AUTO_TEST_CASE(game_Shot3) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  firstBoard[30] = true;
  secondBoard[57] = true;
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.Shot(30, 2) == true);
  BOOST_CHECK(game.Shot(57, 1) == true);
}

BOOST_AUTO_TEST_CASE(game_Shot_sunk1) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  firstBoard[30] = true;
  secondBoard[57] = true;
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.Shot(30, 1) == false);
  BOOST_CHECK(game.Shot(57, 1) == true);
  BOOST_CHECK(game.IsSunk(30).size() == 0);
  BOOST_CHECK(game.IsSunk(57).size() == 1);
  BOOST_CHECK(game.IsSunk(57)[0] == 57);
  BOOST_CHECK(game.IsSunk(40).size() == 0);
}

BOOST_AUTO_TEST_CASE(game_Shot_sunk2) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  firstBoard[30] = true;
  secondBoard[57] = true;
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.Shot(57, 1) == true);
  BOOST_CHECK(game.Shot(30, 2) == true);
  BOOST_CHECK(game.IsSunk(57).size() == 0);
}

BOOST_AUTO_TEST_CASE(game_Shot_sunk3) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  secondBoard[99] = true;
  secondBoard[89] = true;
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.Shot(99, 1) == true);
  BOOST_CHECK(game.IsSunk(99).size() == 0);
  BOOST_CHECK(game.Shot(89, 1) == true);
  BOOST_CHECK(game.IsSunk(99).size() == 2);
}

BOOST_AUTO_TEST_CASE(game_Shot_sunk4) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  secondBoard[0] = true;
  secondBoard[1] = true;
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.Shot(1, 1) == true);
  BOOST_CHECK(game.IsSunk(1).size() == 0);
  BOOST_CHECK(game.Shot(0, 1) == true);
  BOOST_CHECK(game.IsSunk(1).size() == 2);
}

BOOST_AUTO_TEST_CASE(game_end1) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.IsEnd() == true);
}

BOOST_AUTO_TEST_CASE(game_end2) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  firstBoard[1] = true;
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.IsEnd() == true);
}

BOOST_AUTO_TEST_CASE(game_end3) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  firstBoard[1] = true;
  secondBoard[47] = true;
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.IsEnd() == false);
}

BOOST_AUTO_TEST_CASE(game_end4) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  firstBoard[1] = true;
  secondBoard[47] = true;
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.Shot(47, 1) == true);
  BOOST_CHECK(game.IsEnd() == true);
}

BOOST_AUTO_TEST_CASE(is_good1) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.IsGood() == false);
}

BOOST_AUTO_TEST_CASE(is_good2) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  firstBoard[6] = true;
  firstBoard[15] = true;
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.IsGood() == false);
}

BOOST_AUTO_TEST_CASE(is_good3) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  firstBoard[6] = true;
  firstBoard[17] = true;
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.IsGood() == false);
}

BOOST_AUTO_TEST_CASE(is_good4) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  firstBoard[6] = true;
  firstBoard[7] = true;
  firstBoard[16] = true;
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.IsGood() == false);
}

BOOST_AUTO_TEST_CASE(is_good5) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  firstBoard[6] = true;
  firstBoard[7] = true;
  secondBoard[16] = true;
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.IsGood() == false);
}

BOOST_AUTO_TEST_CASE(is_good6) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  firstBoard[6] = true;
  secondBoard[17] = true;
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.IsGood() == false);
}

BOOST_AUTO_TEST_CASE(is_good7) {
  std::array<bool, 100> firstBoard = {false};
  std::array<bool, 100> secondBoard = {false};
  firstBoard[6] = true;
  secondBoard[15] = true;
  Game game = Game(firstBoard, secondBoard);
  BOOST_CHECK(game.IsGood() == false);
}

BOOST_AUTO_TEST_SUITE_END()
