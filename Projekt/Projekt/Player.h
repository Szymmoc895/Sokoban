#pragma once
#include "Box.h"

class Player : public Object
{
public:
	Player(Position* _pos) : Object(_pos) {}
	virtual void Draw() override;
	Player();
	
};

