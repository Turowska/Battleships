#define BOOST_BIND_GLOBAL_PLACEHOLDERS
#include "pythonGame.h"
#include <boost/python.hpp>
#include <iostream>

using namespace boost::python;

PythonGame::PythonGame(list tabListFirstPlayer, list tabListSecondPlayer)
{
	if (len(tabListFirstPlayer) != 100 || len(tabListSecondPlayer) != 100)
	{
		isGood_ = false;
	}
	else
	{
		std::array<bool, 100> tabArrayFirstPlayer;
		std::array<bool, 100> tabArraySecondPlayer;
		for (int i = 0; i < 100; ++i)
		{
			tabArrayFirstPlayer[i] = extract<bool>(tabListFirstPlayer[i]);
			tabArraySecondPlayer[i] = extract<bool>(tabListSecondPlayer[i]);
		}
		game_ = new Game(tabArrayFirstPlayer, tabArraySecondPlayer);
		isGood_ = game_->IsGood();
	}
}

bool PythonGame::Shot(int number, int player)
{
	return game_->Shot(number, player);
}

bool PythonGame::IsSunk(int number)
{
	return game_->IsSunk(number);
}

bool PythonGame::IsEnd()
{
	if (game_->IsEnd())
	{
		delete game_;
		return true;
	}
	return false;
}

bool PythonGame::IsGood()
{
	return isGood_;
}

BOOST_PYTHON_MODULE(pythonGame)
{
	class_<PythonGame>("Game", init<list, list>())
			.def("IsSunk", &PythonGame::IsSunk)
			.def("Shot", &PythonGame::Shot)
			.def("IsEnd", &PythonGame::IsEnd)
			.def("IsGood", &PythonGame::IsGood);
}
