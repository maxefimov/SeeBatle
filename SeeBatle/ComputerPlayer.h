#pragma once
#include "Player.h"
class ComputerPlayer : public Player
{
public:
	ComputerPlayer() : Player() {};
	virtual void SetShips() override;
	virtual Coord Round() override;
};

