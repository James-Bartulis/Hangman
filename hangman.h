#ifndef _hangman_h_
#define _hangman_h_

class Hangman{
private:
	std::string RemainingAlphabet;
	bool GameOver;
	char guess;
	std::string Answer;
	int mistakes, allowedMistakes;

public:
	Hangman();

	void Display();
	void Input();
	void Logic();

	bool isOver();
	bool isNotChar();
	bool isChrInStr();
	bool isChrInStr(char a, std::string b);
	bool isWin();
	std::string Solution();
};

#endif