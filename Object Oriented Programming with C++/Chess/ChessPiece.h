#pragma once
#include "ChessPosition.h"

class ChessPiece
{
	public:
		enum Type
		{
			ROOK,
			KNIGHT
		};

	public:
		ChessPiece(const char* position = NULL);
		ChessPosition getPosition() const;
		virtual ChessPosition* allowedMoves() const = 0;
		virtual bool captures(const ChessPosition chessPiecePosition) const = 0;
		virtual Type getType() const = 0;

	private:
		ChessPosition _position;
};

