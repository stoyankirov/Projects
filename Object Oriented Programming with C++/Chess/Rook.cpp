#include "stdafx.h"
#include <string.h>
#include "ChessPosition.h"
#include "Rook.h"

Rook::Rook(const char* position) :ChessPiece(position)
{}
ChessPosition* Rook::allowedMoves() const
{
	ChessPosition* arr=new ChessPosition[14];
	int counter = 0;

	//up and down
	for (int i = 1; i <= 8; i++)
	{
		char container[3];
		if (this->getPosition().getPositionAsString()[1] - 48 != i)
		{
			strcpy(container, this->getPosition().getPositionAsString());
			container[1] = i;
			arr[counter].setPosition(container);
			counter++;
		}
		
	}

	//left and right
	for (char i = 'A'; i <= 'H'; i++)
	{
		char container[3];
		if (this->getPosition().getPositionAsString()[0] != i)
		{
			strcpy(container, this->getPosition().getPositionAsString());
			container[0] = i;
			arr[counter].setPosition(container);
			counter++;
		}
	}
	return arr;
}
bool Rook::captures(const ChessPosition chessPiecePosition) const
{
	for (int i = 0; i < 14; i++)
	{
		if (strcmp(chessPiecePosition.getPositionAsString(), this->allowedMoves()[i].getPositionAsString()) == 0)
		{
			return true;
			break;
		}
	}
	return false;
}
ChessPiece::Type Rook::getType() const 
{ 
	return ROOK; 
}
