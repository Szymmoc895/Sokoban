#pragma once
#include "Object.h"
class Box : public Object
{
public:
	Box(Position* _pos) : Object(_pos){}
	Box();
	virtual void Draw();
};

