#pragma once
#include "Player.h"

class Destination : public Object
{
public:
	Destination(Position* _pos) : Object(_pos){}
	Destination() {}
	virtual void Draw() override
	{
		if(cover == nullptr)
		cout << ".";
		else
		{
			cover->Draw();
		}
	}
	Object* cover = nullptr;

};

