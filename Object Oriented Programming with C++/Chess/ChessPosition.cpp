#include "stdafx.h"
#include "string.h"
#include <iostream>
#include "ChessPosition.h"

using namespace std;

ChessPosition::ChessPosition(const char* position)
{
	setPosition(position);
}
void ChessPosition::setPosition(const char* position)
{
	if (strlen(position) == 2 && position[0] >= 'A' && position[0] <= 'H' && position[1] >= '1' && position[1] <= '8')
		strcpy(_position, position);
	else
		throw "Bad input !";
}
const char* ChessPosition::getPositionAsString() const
{ 
	return _position; 
}

