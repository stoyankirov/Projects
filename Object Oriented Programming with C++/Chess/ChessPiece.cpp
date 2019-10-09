#include "stdafx.h"
#include "ChessPiece.h"

ChessPiece::ChessPiece(const char* position) 
{
	_position.ChessPosition::setPosition(position);
}
ChessPosition ChessPiece::getPosition() const
{
	return _position;
}
