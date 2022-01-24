#pragma once
#include "Position.h"
#include <iostream>
using namespace std;

class Object
{
public:
	Position* pos;
	Object(Position* _pos) { pos = _pos; }
	Object();
	virtual void Draw(){}
};

