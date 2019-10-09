#include "stdafx.h"
#include "iostream"
#include "ChessPiece.h"
#include "Rook.h"

using namespace std;

void allMoves(const ChessPiece** pieces, int countObjects)
{
	for (int i = 0; i < countObjects; i++)
		for (int j = 0; j < 14; j++)
		{
			bool flag = true;
			for (int k = 0; k < countObjects; k++)
				if (strcmp(pieces[i]->allowedMoves()[j].getPositionAsString(), 
						   pieces[k]->getPosition().getPositionAsString()) == 0)
				{
					flag = false;
				}
			if (flag) 
			{
				cout << pieces[i]->getType() << " " << pieces[i]->getPosition().getPositionAsString() 
					 << " -> " << pieces[i]->allowedMoves()[j].getPositionAsString() << endl;
			}
		}
}

int main()
{
	return 0;
}