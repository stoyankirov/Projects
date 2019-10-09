#include "stdafx.h"
#include "string.h"
#include "Knight.h"


Knight::Knight(const char* position) :ChessPiece(position)
{}
ChessPosition* Knight::allowedMoves() const
{
	
	ChessPosition* arr=new ChessPosition[8];
	int counter = 0;
	if (this->getPosition().getPositionAsString()[0] - 2 >= 'A'&&this->getPosition().getPositionAsString()[0] - 2 <= 'H'&&
		this->getPosition().getPositionAsString()[1] - 1 >= '1' && this->getPosition().getPositionAsString()[1] - 1<= '8')
	{
		char container[3];
		char letter = this->getPosition().getPositionAsString()[0] - 2;
		char number = this->getPosition().getPositionAsString()[1] - 1;
		container[0] = letter;
		container[1] = number;
		arr[counter].setPosition(container);
		counter++;
	}
	else if (this->getPosition().getPositionAsString()[0] - 2 >= 'A'&&this->getPosition().getPositionAsString()[0] - 2 <= 'H'&&
		this->getPosition().getPositionAsString()[1] + 1 >= '1' && this->getPosition().getPositionAsString()[1] + 1 <= '8')
		{
		char container[3];
		char letter = this->getPosition().getPositionAsString()[0] - 2;
		char number = this->getPosition().getPositionAsString()[1] + 1;
		container[0] = letter;
		container[1] = number;
		arr[counter].setPosition(container);
		counter++;
		}
	else if (this->getPosition().getPositionAsString()[0] + 2 >= 'A'&&this->getPosition().getPositionAsString()[0] + 2 <= 'H'&&
		this->getPosition().getPositionAsString()[1] + 1 >= '1' && this->getPosition().getPositionAsString()[1] + 1 <= '8')
		{
		char container[3];
		char letter = this->getPosition().getPositionAsString()[0] + 2;
		char number = this->getPosition().getPositionAsString()[1] + 1;
		container[0] = letter;
		container[1] = number;
		arr[counter].setPosition(container);
		counter++;
		}
	else if (this->getPosition().getPositionAsString()[0] + 2 >= 'A'&&this->getPosition().getPositionAsString()[0] + 2 <= 'H'&&
		this->getPosition().getPositionAsString()[1] - 1 >= '1' && this->getPosition().getPositionAsString()[1] - 1 <= '8')
		{
		char container[3];
		char letter = this->getPosition().getPositionAsString()[0] - 2;
		char number = this->getPosition().getPositionAsString()[1] + 1;
		container[0] = letter;
		container[1] = number;
		arr[counter].setPosition(container);
		counter++;
		}
	else if (this->getPosition().getPositionAsString()[0] - 1 >= 'A'&&this->getPosition().getPositionAsString()[0] - 1 <= 'H'&&
		this->getPosition().getPositionAsString()[1] - 2 >= '1' && this->getPosition().getPositionAsString()[1] - 2 <= '8')
		{
		char container[3];
		char letter = this->getPosition().getPositionAsString()[0] - 2;
		char number = this->getPosition().getPositionAsString()[1] + 1;
		container[0] = letter;
		container[1] = number;
		arr[counter].setPosition(container);
		counter++;
		}
	else if (this->getPosition().getPositionAsString()[0] + 1 >= 'A'&&this->getPosition().getPositionAsString()[0] + 1 <= 'H'&&
		this->getPosition().getPositionAsString()[1] - 2 >= '1' && this->getPosition().getPositionAsString()[1] - 2 <= '8')
		{
		char container[3];
		char letter = this->getPosition().getPositionAsString()[0] - 2;
		char number = this->getPosition().getPositionAsString()[1] + 1;
		container[0] = letter;
		container[1] = number;
		arr[counter].setPosition(container);
		counter++;
		}
	else if (this->getPosition().getPositionAsString()[0] - 1 >= 'A'&&this->getPosition().getPositionAsString()[0] - 1 <= 'H'&&
		this->getPosition().getPositionAsString()[1] + 2 >= '1' && this->getPosition().getPositionAsString()[1] + 2 <= '8')
		{
		char container[3];
		char letter = this->getPosition().getPositionAsString()[0] - 2;
		char number = this->getPosition().getPositionAsString()[1] + 1;
		container[0] = letter;
		container[1] = number;
		arr[counter].setPosition(container);
		counter++;
		}
	else if (this->getPosition().getPositionAsString()[0] + 1 >= 'A'&&this->getPosition().getPositionAsString()[0] + 1 <= 'H'&&
		this->getPosition().getPositionAsString()[1] + 2 >= '1' && this->getPosition().getPositionAsString()[1] + 2 <= '8')
		{
		char container[3];
		char letter = this->getPosition().getPositionAsString()[0] - 2;
		char number = this->getPosition().getPositionAsString()[1] + 1;
		container[0] = letter;
		container[1] = number;
		arr[counter].setPosition(container);
		counter++;
		}
	return arr;
}
bool Knight::captures(const ChessPosition chessPiecePosition)
{
	for (int i = 0; i < 8; i++)
	{
		if (strcmp(chessPiecePosition.getPositionAsString(), this->allowedMoves()[i].getPositionAsString()) == 0)
		{
			return true;
			break;
		}
	}
	return false;
}
ChessPiece::Type Knight::getType() const
{ 
	return KNIGHT; 
}
