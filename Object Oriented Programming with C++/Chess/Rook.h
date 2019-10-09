#pragma once
#include "ChessPiece.h"

class Rook :public ChessPiece
{
	public:
		Rook(const char* position);
		virtual ChessPosition* allowedMoves() const;
		virtual bool captures(const ChessPosition chessPiecePosition) const;
		virtual Type getType() const; 
};

