#include "Game.h"

Game::Game()
{
	players[TypePlayer::HUMAN] = new HumanPlayer(view.GetHumanName());
	players[TypePlayer::COMPUTER] = new ComputerPlayer();
	order = false;
}

void Game::Init()
{
	for (int i = 0; i < 2; i++)
		players[i]->SetShips();
}

void Game::Play()
{
	while (true)
	{
		view.RoundStart(players[order]->Name());

		Coord coord = players[order]->Round();
		ShootState state = players[!order]->ShootCheck(coord);
		if (state == ShootState::MISS)
		{
			view.ShowMiss(players[order]->Name());
			order = !order;
		}

		if(state == ShootState::HIT)
			view.ShowHit(players[order]->Name());

		if(state == ShootState::KILL)
			view.ShowKill(players[order]->Name());

		if (players[!order]->GameCheck())
			break;
	}
}

void Game::Win()
{
	view.GameWin(players[order]->Name());
}
