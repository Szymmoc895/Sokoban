#pragma once
#include <array>
#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <conio.h>
#include <typeinfo>
#include "Wall.h"

enum ObjectsTypes
{
	WALL,
	BOX,
	DEST
};

class Board
{
	static constexpr int l = 10;
	static constexpr int m = 14;
	

	Object* ObjectTab[l][m];
	Player* player;
	Box* box;
	Wall* wall;
	Destination* dest;
	vector<Destination*> dests;

	public:
	int counter = 0;
	string nickname;
	Board()
	{
		ReadFromFile();
	}

	void DrawTab();
	void ReadFromFile();
	void keyDown();
	bool gameover();
	void moveUp(int x, int y);
	void moveDown(int x, int y);
	void moveLeft(int x, int y);
	void moveRight(int x, int y);
	bool check(ObjectsTypes type, int x, int y);
	void restoreDests();
	void addPlayer(int x, int y);
	void addWall(int x, int y);
	void addDestination(int x, int y);
	void addBox(int x, int y);
	void clearObjectTab();
	void newPlayer();
	void game();
};
