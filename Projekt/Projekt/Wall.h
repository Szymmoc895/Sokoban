#pragma once
#include "Destination.h"
class Wall : public Object
{
	public:
	Wall(Position* _pos) : Object(_pos){}
	Wall();
	virtual void Draw();
};

