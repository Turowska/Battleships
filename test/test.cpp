#define BOOST_TEST_MODULE statki
#include <boost/test/included/unit_test.hpp>

#include "field.hpp"
#include "board.hpp"
#include "ship.hpp"
#include "player.hpp"
#include "game.hpp"

BOOST_AUTO_TEST_SUITE( field)

BOOST_AUTO_TEST_CASE( field_set_get1 )
{
	Field a;
	BOOST_CHECK( a.getIsOccupied() == false  );
	BOOST_CHECK( a.getIsHit() == false );
	a.setIsOccupied(true);
	BOOST_CHECK( a.getIsOccupied() == true  );
	BOOST_CHECK( a.getIsHit() == false );
}

BOOST_AUTO_TEST_CASE( field_set_get2 )
{
	Field a;
	BOOST_CHECK( a.getIsOccupied() == false  );
	BOOST_CHECK( a.getIsHit() == false );
	a.setIsOccupied(false);
	BOOST_CHECK( a.getIsOccupied() == false  );
	BOOST_CHECK( a.getIsHit() == false );
}

BOOST_AUTO_TEST_CASE( field_shotField1 )
{
	Field a;
	a.setIsOccupied(true);
	BOOST_CHECK( a.getIsHit() == false );
	BOOST_CHECK( a.getIsOccupied() == true  );
	BOOST_CHECK( a.shotField() == 	true );
	BOOST_CHECK( a.getIsHit() == true );
	BOOST_CHECK( a.getIsOccupied() == true  );
}

BOOST_AUTO_TEST_CASE( field_shotField2 )
{
	Field a;
	BOOST_CHECK( a.getIsOccupied() == false  );
	BOOST_CHECK( a.getIsHit() == false );
	BOOST_CHECK( a.shotField() == 	false );
	BOOST_CHECK( a.getIsHit() == true );
	BOOST_CHECK( a.getIsOccupied() == false  );
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( board )

BOOST_AUTO_TEST_CASE( board_get )
{
	std::array<bool, 100> board;
	for(int i=0; i<100; ++i){
		if(i%3==0){
			board[i] = true;
		}else {
			board[i] = false;
		}
	}
	Board tab = Board(board);
	bool pom;
	for(int i=0; i<100; ++i){
		if(i%3==0){
			pom = true;
		}else {
			pom = false;
		}
		BOOST_CHECK(tab.getIsOccupied(i) == pom);
		BOOST_CHECK(tab.getIsHit(i) == false);
	}
	BOOST_CHECK(tab.shot(0) == true);
	BOOST_CHECK(tab.getIsHit(0) == true);
}
BOOST_AUTO_TEST_CASE( board_shot )
{
	std::array<bool, 100> board = {false};
	board[4] = true;
	Board tab = Board(board);
	BOOST_CHECK(tab.shot(0) == false);
	BOOST_CHECK(tab.shot(4) == true);
	BOOST_CHECK(tab.getIsHit(0) == true);
	BOOST_CHECK(tab.getIsHit(4) == true);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( ship )

BOOST_AUTO_TEST_CASE( ship_getSize )
{
	std::vector<int> vec = {1, 5, 6};
	Ship ship = Ship(vec);
	BOOST_CHECK(ship.getSize() == 3);
}

BOOST_AUTO_TEST_CASE( ship_getIsAfloat )
{
	std::vector<int> vec = {1, 5, 6};
	Ship ship = Ship(vec);
	BOOST_CHECK(ship.getIsAfloat() == false);
}

BOOST_AUTO_TEST_CASE( ship_getIsAfloat_sunk )
{
	std::vector<int> vec = {1, 5, 6};
	Ship ship = Ship(vec);
	ship.sunk();
	BOOST_CHECK(ship.getIsAfloat() == true);
}

BOOST_AUTO_TEST_CASE( ship_isInField )
{
	std::vector<int> vec = {1, 5, 6};
	Ship ship = Ship(vec);
	BOOST_CHECK(ship.isInField(5) == true);
	BOOST_CHECK(ship.isInField(7) == false);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( player )

BOOST_AUTO_TEST_CASE( player_getIsSunk1 )
{
	std::array<bool, 100> board = {false};
	board[0] = true;
	board[1] = true;
	board[2] = true;
	Player player = Player(board);
	BOOST_CHECK(player.getIsSunk(2) == false);
	BOOST_CHECK(player.getIsSunk(36) == false);
}

BOOST_AUTO_TEST_CASE( player_shot_getIsSunk1 )
{
	std::array<bool, 100> board = {false};
	board[0] = true;
	board[1] = true;
	board[2] = true;
	Player player = Player(board);
	BOOST_CHECK(player.shot(1) == true);
	BOOST_CHECK(player.getIsSunk(1) == false);
}

BOOST_AUTO_TEST_CASE( player_shot1 )
{
	std::array<bool, 100> board = {false};
	board[0] = true;
	board[1] = true;
	board[2] = true;
	Player player = Player(board);
	BOOST_CHECK(player.shot(1) == true);
	BOOST_CHECK(player.shot(0) == true);
	BOOST_CHECK(player.shot(2) == true);
	BOOST_CHECK(player.getIsSunk(0) == true);
}

BOOST_AUTO_TEST_CASE( player_shot_getIsSunk2 )
{
	std::array<bool, 100> board = {false};
	board[99] = true;
	board[89] = true;
	Player player = Player(board);
	BOOST_CHECK(player.shot(99) == true);
	BOOST_CHECK(player.getIsSunk(99) == false);
}

BOOST_AUTO_TEST_CASE( player_shot2 )
{
	std::array<bool, 100> board = {false};
	board[99] = true;
	board[89] = true;
	Player player = Player(board);
	BOOST_CHECK(player.shot(99) == true);
	BOOST_CHECK(player.shot(89) == true);
	BOOST_CHECK(player.getIsSunk(99) == true);
}

BOOST_AUTO_TEST_CASE( player_shot3 )
{
	std::array<bool, 100> board = {false};
	board[45] = true;
	Player player = Player(board);
	BOOST_CHECK(player.shot(45) == true);
	BOOST_CHECK(player.getIsSunk(45) == true);
}

BOOST_AUTO_TEST_CASE( player_shot4 )
{
	std::array<bool, 100> board = {false};
	board[45] = true;
	Player player = Player(board);
	BOOST_CHECK(player.shot(46) == false);
	BOOST_CHECK(player.getIsSunk(46) == false);
}

BOOST_AUTO_TEST_CASE( player_endGame1 )
{
	std::array<bool, 100> board = {false};
	board[45] = true;
	Player player = Player(board);
	BOOST_CHECK(player.endGame() == false);
}

BOOST_AUTO_TEST_CASE( player_endGame2 )
{
	std::array<bool, 100> board = {false};
	board[45] = true;
	Player player = Player(board);
	BOOST_CHECK(player.shot(45) == true);
	BOOST_CHECK(player.endGame() == true);
}

BOOST_AUTO_TEST_CASE( player_endGame3 )
{
	std::array<bool, 100> board = {false};
	board[45] = true;
	board[22] = true;
	Player player = Player(board);
	BOOST_CHECK(player.shot(45) == true);
	BOOST_CHECK(player.endGame() == false);
}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( game )

BOOST_AUTO_TEST_CASE( game_shot )
{
	std::array<bool, 100> firstBoard = {false};
	std::array<bool, 100> secondBoard = {false};
	firstBoard[30] = true;
	secondBoard[57] = true;
	Game game = Game(firstBoard, secondBoard);
	BOOST_CHECK(game.shot(30) == false);
	BOOST_CHECK(game.shot(57) == true);
}

BOOST_AUTO_TEST_CASE( game_shot_nextRound )
{
	std::array<bool, 100> firstBoard = {false};
	std::array<bool, 100> secondBoard = {false};
	firstBoard[30] = true;
	secondBoard[57] = true;
	Game game = Game(firstBoard, secondBoard);
	game.nextRound();
	BOOST_CHECK(game.shot(30) == true);
	BOOST_CHECK(game.shot(57) == false);
}

BOOST_AUTO_TEST_CASE( game_shot_sunk1 )
{
	std::array<bool, 100> firstBoard = {false};
	std::array<bool, 100> secondBoard = {false};
	firstBoard[30] = true;
	secondBoard[57] = true;
	Game game = Game(firstBoard, secondBoard);
	BOOST_CHECK(game.shot(30) == false);
	BOOST_CHECK(game.shot(57) == true);
	BOOST_CHECK(game.isSunk(30) == false);
	BOOST_CHECK(game.isSunk(57) == true);
	BOOST_CHECK(game.isSunk(40) == false);
}

BOOST_AUTO_TEST_CASE( game_shot_sunk2 )
{
	std::array<bool, 100> firstBoard = {false};
	std::array<bool, 100> secondBoard = {false};
	firstBoard[30] = true;
	secondBoard[57] = true;
	Game game = Game(firstBoard, secondBoard);
	BOOST_CHECK(game.shot(30) == false);
	BOOST_CHECK(game.shot(57) == true);
	game.nextRound();
	BOOST_CHECK(game.isSunk(57) == false);
}

BOOST_AUTO_TEST_CASE( game_shot_sunk3 )
{
	std::array<bool, 100> firstBoard = {false};
	std::array<bool, 100> secondBoard = {false};
	secondBoard[99] = true;
	secondBoard[89] = true;
	Game game = Game(firstBoard, secondBoard);
	BOOST_CHECK(game.shot(99) == true);
	BOOST_CHECK(game.isSunk(99) == false);
	BOOST_CHECK(game.shot(89) == true);
	BOOST_CHECK(game.isSunk(99) == true);
}

BOOST_AUTO_TEST_CASE( game_shot_sunk4 )
{
	std::array<bool, 100> firstBoard = {false};
	std::array<bool, 100> secondBoard = {false};
	secondBoard[0] = true;
	secondBoard[1] = true;
	Game game = Game(firstBoard, secondBoard);
	BOOST_CHECK(game.shot(1) == true);
	BOOST_CHECK(game.isSunk(1) == false);
	BOOST_CHECK(game.shot(0) == true);
	BOOST_CHECK(game.isSunk(1) == true);
}

BOOST_AUTO_TEST_CASE( game_end1 )
{
	std::array<bool, 100> firstBoard = {false};
	std::array<bool, 100> secondBoard = {false};
	Game game = Game(firstBoard, secondBoard);
	BOOST_CHECK(game.isEnd() == true);
}

BOOST_AUTO_TEST_CASE( game_end2 )
{
	std::array<bool, 100> firstBoard = {false};
	std::array<bool, 100> secondBoard = {false};
	firstBoard[1] = true;
	Game game = Game(firstBoard, secondBoard);
	BOOST_CHECK(game.isEnd() == true);
}

BOOST_AUTO_TEST_CASE( game_end3 )
{
	std::array<bool, 100> firstBoard = {false};
	std::array<bool, 100> secondBoard = {false};
	firstBoard[1] = true;
	secondBoard[47] = true;
	Game game = Game(firstBoard, secondBoard);
	BOOST_CHECK(game.isEnd() == false);
}

BOOST_AUTO_TEST_CASE( game_end4 )
{
	std::array<bool, 100> firstBoard = {false};
	std::array<bool, 100> secondBoard = {false};
	firstBoard[1] = true;
	secondBoard[47] = true;
	Game game = Game(firstBoard, secondBoard);
	BOOST_CHECK(game.shot(47) == true);
	BOOST_CHECK(game.isEnd() == true);
}
BOOST_AUTO_TEST_SUITE_END()
