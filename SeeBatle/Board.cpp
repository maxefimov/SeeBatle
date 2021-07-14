#include "Board.h"

Board::Board()
{
}

void Board::Statusrestart()
{
    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            board[i][j].State() = false;
}

bool Board::AddShip(int row, int col, int size, ShipDirection direction)
{
    bool isOk{ true };
    for (int i = 0; i < size; i++)
    {
        if (direction == ShipDirection::HORIZONTAL)
            isOk = isOk && !board[row][col + i].State();
        else
            isOk = isOk && !board[row + i][col].State();
    }
    if (!isOk)
        return false;

    if (direction == ShipDirection::HORIZONTAL)
        isOk = isOk && (col + size) < 10;
    else
        isOk = isOk && (row + size) < 10;
    
    if (!isOk)
        return false;

    ships.push_back(new Ship(size, direction));

    for (int i = 0; i < size; i++)
    {
        if (direction == ShipDirection::HORIZONTAL)
            board[row][col + i].Value() = CellValue::DECK;
        else
            board[row + i][col].Value() = CellValue::DECK;
    }

    for (int i = -1; i < size + 1; i++)
    {
        for (int j = -1; j < 2; j++)
        {
            if (direction == ShipDirection::HORIZONTAL)
                board[row + j][col + i].State() = true;
            else
                board[row + i][col + j].State() = true;
        }
    }
    return true;
}

ShootState Board::ShootCheck(int row, int col)
{
    board[row][col].State() = true;

    if (board[row][col].Value() == CellValue::WATER)
        return ShootState::MISS;

    for (Ship* ship : ships)
    {
        if (ship->GoodCells() == 0)
            continue;

        bool isHit{ false };

        for (int i = 0; i < ship->Size(); i++)
        {
            if (ship->Direction() == ShipDirection::HORIZONTAL)
                isHit = isHit || (row == ship->Row() && col == ship->Col() + i);
            else
                isHit = isHit || (row == ship->Row() + i && col == ship->Col());
        }

        if (isHit)
        {
            ship->GoodCells()--;
            if (ship->GoodCells() == 0)
            {
                for (int i = -1; i < ship->Size() + 1; i++)
                {
                    for (int j = -1; j < 2; j++)
                    {
                        if (ship->Direction() == ShipDirection::HORIZONTAL)
                            board[row + j][col + i].State() = true;
                        else
                            board[row + i][col + j].State() = true;
                    }
                }
                return ShootState::KILL;
            }
            return ShootState::HIT;
        }
    }
}

bool Board::ShipsCheck()
{
    bool shipcheck{ true };
    for (Ship* ship : ships)
        shipcheck = shipcheck && (ship->GoodCells() == 0);
    return shipcheck;
}

const Board::cellarray& Board::GetBoard()
{
    return board;
}
