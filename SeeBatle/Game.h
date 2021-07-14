#pragma once
#include "Player.h"
#include "ViewPort.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include <array>
#include <string>
enum TypePlayer
{
	HUMAN,
	COMPUTER
};

class Game
{
	std::array<Player*, 2> players;
	bool order;
	ViewPort view;

public:
	Game();
	void Init();
	void Play();
	void Win();
};

