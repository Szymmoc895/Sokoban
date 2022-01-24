#include "Board.h"
#include"Scores.h"
#include <algorithm>



int main()
{
	vector<Score<int>*> leaderboard_ano;
	vector<Score<string>*> leaderboard_nick;
	string option;
	bool chceGrac = true;
	int number = 1;
	Board* board = new Board();
	while (chceGrac)
	{
		board->newPlayer();
		board->DrawTab();
		board->game();
		cout << "GAME OVER!" << endl;
		if (board->nickname == "L")
		{
			Score<int>* score = new Score<int>(board->counter, number);
			cout << "Current ";
			score->print();
			number++;
			leaderboard_ano.push_back(score);
			sort(leaderboard_ano.begin(), leaderboard_ano.end(), sortPointers<int>);
			for(Score<int>* score : leaderboard_ano)
			{
				score->print();
			}
			for (Score<string>* score : leaderboard_nick)
			{
				score->print();
			}
		}
		else
		{
			Score<string>* score = new Score<string>(board->counter, board->nickname);
			cout << "Current ";
			score->print();
			leaderboard_nick.push_back(score);
			sort(leaderboard_nick.begin(), leaderboard_nick.end(), sortPointers<string>);
			for (Score<string>* score : leaderboard_nick)
			{
				score->print();
			}
			for (Score<int>* score : leaderboard_ano)
			{
				score->print();
			}
		}
		cout << "Chcesz zagrac jeszcze raz? Tak/Nie" << endl;
		cin >> option;
		if (option == "Tak" || option =="tak")
		{
			board->ReadFromFile();
			board->counter = 0;
			system("cls");
		}
		else
		{
			board->clearObjectTab();
			delete board;
			chceGrac = false;
		}
	}
}