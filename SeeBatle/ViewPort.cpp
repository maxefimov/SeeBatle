#include "ViewPort.h"
#include <iostream>

Coord ViewPort::GetShipCoordinate()
{
    Coord coord;
    std::cout << "Input COORDINATE of SHIP\n";
    std::cout << "Input ROW: ";
    std::cin >> coord.row;
    std::cout << "Input COL: ";
    std::cin >> coord.col;
    return coord;
}

Coord ViewPort::GetShootCoordinate()
{
    Coord coord;
    std::cout << "Input COORDINATE of SHOOT\n";
    std::cout << "Input ROW: ";
    std::cin >> coord.row;
    std::cout << "Input COL: ";
    std::cin >> coord.col;
    return coord;
}

std::string ViewPort::GetHumanName()
{
    std::string name;
    std::cout << "Input YOUR NAME: ";
    std::cin >> name;
    return name;
}

void ViewPort::ShowMiss(std::string name)
{
    std::cout << name << " MISS!\n";
}

void ViewPort::ShowHit(std::string name)
{
    std::cout << name << " HIT!\n";
}

void ViewPort::ShowKill(std::string name)
{
    std::cout << name << " KILL of ship!\n";
}

void ViewPort::RoundStart(std::string name)
{
    std::cout << "**************************************\n";
    std::cout << "Round for " << name << "\n";
    std::cout << "**************************************\n";
}

void ViewPort::GameWin(std::string name)
{
    std::cout << "**************************************\n";
    std::cout << name << " WIN!!!!!!!!!!\n";
    std::cout << "**************************************\n";
}

int ViewPort::GetShipSize()
{
    int shipSize;
    std::cout << "Input SIZE of ship: ";
    std::cin >> shipSize;
    return shipSize;
}

void ViewPort::ShowShips(int array[])
{
    for (int i = 1; i < 5; i++)
        std::cout << "Ship at size = " << i << " is = " << array[i] << "\n";
}

ShipDirection ViewPort::GetShipDirection()
{
    int direction;
    std::cout << "Input DIRECTION of ship:\n1 - Horizontal\n2 - Vertical\nDirection: ";
    std::cin >> direction;
    return (direction == 1) ? ShipDirection::HORIZONTAL : ShipDirection::VERTICAL;
}
