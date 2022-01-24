#include "Board.h"

void Board::DrawTab()
{

	for (int i = 0; i < l; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (ObjectTab[i][j] != nullptr)
			{
				ObjectTab[i][j]->Draw();
			}
			else
			{
				cout << " ";
			}
		}
		cout << endl;
	}
}

void Board::ReadFromFile()
{
	string file = "map.txt";
	char chr;

	ifstream map(file);
	if (map.is_open())
	{
		for (int i = 0; i < l; i++)
		{
			for (int j = 0; j < m; j++)
			{
				map.get(chr);

				if (chr == '@')
				{
					addPlayer(i,j);
				}
				else if (chr == 'X')
				{
					addWall(i, j);
				}
				else if (chr == '.')
				{
					addDestination(i, j);
				}
				else if (chr == '*')
				{
					addBox(i, j);
				}
				else
				{
					ObjectTab[i][j] = nullptr;
				}
			}
			map.get(chr);
		}

	}
	map.close();

}

void Board::keyDown()
{
	int x, y;
	x = player->pos->x;
	y = player->pos->y;
	char userKey = _getch();
	userKey = tolower(userKey);
	switch (userKey)
	{
	case 'w':
	
		moveUp(x, y);
		break;

	case 's':
		
		moveDown(x, y);
		break;
	case 'a':
	
		moveLeft(x, y);
		break;

	case 'd':
	
		moveRight(x, y);
		break;
	case 'r':
		ReadFromFile();
		if (counter == 0)
			return;
		else
			counter = -1;
		break;
	case 't':
		newPlayer();
		ReadFromFile();
		if (counter == 0)
			return;
		else
			counter = -1;
		break;
	}
	if (x != player->pos->x || y != player->pos->y)
		counter++;

}

bool Board::gameover()
{
	int x, y;
	for (Destination* dest : dests)
	{
		
		x = dest->pos->x;
		y = dest->pos->y;
		if (!check(BOX, x, y))
		{
			return false;

		}

	}
	return true;

}

void Board::moveUp(int x, int y)
{
	if (ObjectTab[x - 1][y] == nullptr || ObjectTab[x - 1][y] == dynamic_cast<Destination*>(ObjectTab[x - 1][y]))
	{
		ObjectTab[x][y] = nullptr;
		ObjectTab[x - 1][y] = player;
		player->pos->x = x - 1;

	}

	if (Box* tempbox = dynamic_cast<Box*> (ObjectTab[x - 1][y])) 
	{
		if (ObjectTab[x - 2][y] == nullptr || ObjectTab[x - 2][y] == dynamic_cast<Destination*>(ObjectTab[x - 2][y]))
		{
			ObjectTab[x][y] = nullptr;
			ObjectTab[x - 1][y] = player;
			ObjectTab[x - 2][y] = tempbox;
			player->pos->x = x - 1;

		}
	}

}

void Board::moveDown(int x, int y)
{
	if (ObjectTab[x + 1][y] == nullptr || ObjectTab[x + 1][y] == dynamic_cast<Destination*>(ObjectTab[x + 1][y]))
	{
		ObjectTab[x][y] = nullptr;
		ObjectTab[x + 1][y] = player;
		player->pos->x = x + 1;

	}
	else if (Box* tempbox = dynamic_cast<Box*> (ObjectTab[x + 1][y]))
	{
		if (ObjectTab[x + 2][y] == nullptr)
		{
			ObjectTab[x][y] = nullptr;
			ObjectTab[x + 1][y] = player;
			ObjectTab[x + 2][y] = tempbox;
			player->pos->x = x + 1;

		}
		if (Destination* tempdest = dynamic_cast<Destination*>(ObjectTab[x + 2][y]))
		{
			ObjectTab[x][y] = nullptr;
			ObjectTab[x + 1][y] = player;
			ObjectTab[x + 2][y] = tempbox;
			player->pos->x = x + 1;

		}

	}
}

void Board::moveLeft(int x, int y)
{
	if (ObjectTab[x][y - 1] == nullptr || ObjectTab[x][y - 1] == dynamic_cast<Destination*>(ObjectTab[x][y - 1]))
	{
		ObjectTab[x][y] = nullptr;
		ObjectTab[x][y - 1] = player;

		player->pos->y = y - 1;
	}
	else if (Box* tempbox = dynamic_cast<Box*> (ObjectTab[x][y - 1]))
	{
		if (ObjectTab[x][y - 2] == nullptr)
		{
			ObjectTab[x][y] = nullptr;
			ObjectTab[x][y - 1] = player;
			ObjectTab[x][y - 2] = tempbox;

			player->pos->y = y - 1;
		}
		if (Destination* tempdest = dynamic_cast<Destination*>(ObjectTab[x][y - 2]))
		{
			ObjectTab[x][y] = nullptr;
			ObjectTab[x][y - 1] = player;
			ObjectTab[x][y - 2] = tempbox;

			player->pos->y = y - 1;
		}

	}
}

void Board::moveRight(int x, int y)
{
	if (ObjectTab[x][y + 1] == nullptr || ObjectTab[x][y + 1] == dynamic_cast<Destination*>(ObjectTab[x][y + 1]))
	{
		ObjectTab[x][y] = nullptr;
		ObjectTab[x][y + 1] = player;

		player->pos->y = y + 1;
	}
	else if (Box* tempbox = dynamic_cast<Box*> (ObjectTab[x][y + 1]))
	{
		if (ObjectTab[x][y + 2] == nullptr)
		{
			ObjectTab[x][y] = nullptr;
			ObjectTab[x][y + 1] = player;
			ObjectTab[x][y + 2] = tempbox;

			player->pos->y = y + 1;
		}
		if (Destination* tempdest = dynamic_cast<Destination*>(ObjectTab[x][y + 2]))
		{
			ObjectTab[x][y] = nullptr;
			ObjectTab[x][y + 1] = player;
			ObjectTab[x][y + 2] = tempbox;

			player->pos->y = y + 1;
		}

	}
}

bool Board::check(ObjectsTypes type,int x, int y)
{
	switch(type)
	{
	case WALL:
	{
		Wall* w = dynamic_cast<Wall*> (ObjectTab[x][y]);
	return w != nullptr; 
	}
	case BOX:
	{
		Box* b = dynamic_cast<Box*> (ObjectTab[x][y]);
		return b != nullptr;
	}
	case DEST:
	{
		Destination* d = dynamic_cast<Destination*> (ObjectTab[x][y]);
		return d != nullptr;
	}
	default:
	break;
	}
	return false;
}

void Board::restoreDests()
{
	
	for(Destination* dest :  dests)
	{
		int x, y;
		x = dest->pos->x;
		y = dest->pos->y;
		if (ObjectTab[x][y] == nullptr)
		{
			ObjectTab[x][y] = dest;

		}

	}

}

void Board::addPlayer(int x, int y)
{
	player = new Player(new Position(x, y));
	ObjectTab[x][y] = player;
}

void Board::addWall(int x, int y)
{
	wall = new Wall(new Position(x, y));
	ObjectTab[x][y] = wall;
}

void Board::addDestination(int x, int y)
{
	dest = new Destination(new Position(x, y));
	ObjectTab[x][y] = dest;
	dests.push_back(dest);
}

void Board::addBox(int x, int y)
{
	box = new Box(new Position(x, y));
	ObjectTab[x][y] = box;
}

void Board::clearObjectTab()
{
	for (int i = 0; i < l; i++)
	{
		for(int j = 0; j<m;j++)
		{
			delete ObjectTab[i][j];
		}
	}
}

void Board::newPlayer()
{
	cout << "Do poruszania sie uzyj WSAD, aby zrestartowac gre nacisnij R, aby zmienic gracza nacisnij T!" << endl;
	cout << "Podaj nazwe lub wpisz L, jezeli chcesz pozostac anonimowy " << endl;
	cin >> nickname;
}

void Board::game()
{
	while (!gameover())
	{

		keyDown();
		restoreDests();
		system("cls");
		cout << "Liczba krokow: " << counter << endl;
		DrawTab();
	}
}
