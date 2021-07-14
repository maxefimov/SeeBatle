#pragma once
#include <array>
#include <vector>
#include "Cell.h"
#include "Ship.h"

enum class ShootState
{
	MISS,
	HIT,
	KILL
};

class Board
{
	using cellarray = std::array<std::array<Cell, 10>, 10>;

	cellarray board;
	std::vector<Ship*> ships;

public:
	Board();
	void Statusrestart();
	bool AddShip(int row, int col, int size, ShipDirection direction);
	ShootState ShootCheck(int row, int col);
	bool ShipsCheck();
	const cellarray& GetBoard();
};

