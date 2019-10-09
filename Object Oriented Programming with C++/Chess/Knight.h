#pragma once
#include "ChessPiece.h"

class Knight:public ChessPiece
{
	public:
		Knight(const char* position);
		virtual ChessPosition* allowedMoves() const;
		virtual bool captures(const ChessPosition chessPiecePosition);
		virtual Type getType() const;
};

