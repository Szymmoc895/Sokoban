#pragma once
#include <iostream>

using namespace std;

template <class T>
class Score
{
	int result;
	T name;
public:
	Score(int Result, T Name) : result(Result), name(Name) {}
	void print();
	friend bool operator< (const Score<T>& score1, const Score<T>& score2) { return score1.result < score2.result; }
	friend bool operator> (const Score<T>& score1, const Score<T>& score2) { return score2 < score1; }
	friend bool operator== (const Score<T>& score1, const Score<T>& score2) { return !((score1 < score2) || (score2 < score1)); }
};

template<class T>
inline void Score<T>::print()
{
	cout << "Player ";
	cout << name << ": " << result << endl;
}

template<class T>
inline bool sortPointers(const Score<T>* score1, const Score<T>* score2) 
{
	return *score1 < *score2;
}
