#pragma once
class ChessPosition
{
	public:
		ChessPosition(const char* position=NULL);
		
		void setPosition(const char* position);
		const char* getPositionAsString() const; 

	private:
		char _position[3];
};

