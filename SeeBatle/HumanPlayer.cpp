#include "HumanPlayer.h"

void HumanPlayer::SetShips()
{
	int shipsSize[5]{ 0, 4, 3, 2, 1 };

	ViewPort view;
	while (true)
	{
		view.ShowShips(shipsSize);

		int currsize;
		ShipDirection direction;
		Coord coord;

		do {
			currsize = view.GetShipSize();
			if (shipsSize[currsize] > 0)
			{
				shipsSize[currsize]--;
				break;
			}
		} while (true);

		direction = view.GetShipDirection();

		do {
			coord = view.GetShipCoordinate();
		} while (board.AddShip(coord.row, coord.col, currsize, direction));
		
		int zero{};
		for (int i = 1; i < 5; i++)
			zero += shipsSize[i];

		if (zero == 0)
			break;
	}
}

Coord HumanPlayer::Round()
{
	ViewPort view;
	Coord coord;

	coord = view.GetShootCoordinate();
	return coord;
}
