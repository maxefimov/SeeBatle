#pragma once
enum class CellValue
{
	WATER,
	DECK
};

class Cell
{
	CellValue value;
	bool state;

public:
	Cell(CellValue value = CellValue::WATER, bool state = false) 
		: value{ value }, state{ state }{}

	CellValue& Value()
	{
		return value;
	}

	bool& State()
	{
		return state;
	}
};

