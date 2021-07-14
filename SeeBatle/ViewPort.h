#pragma once
#include "Ship.h"
#include <string>

class ViewPort
{
public:
	int GetShipSize();
	void ShowShips(int array[]);
	ShipDirection GetShipDirection();
	Coord GetShipCoordinate();
	Coord GetShootCoordinate();
	std::string GetHumanName();
	void ShowMiss(std::string name);
	void ShowHit(std::string name);
	void ShowKill(std::string name);
	void RoundStart(std::string name);
	void GameWin(std::string name);
};

