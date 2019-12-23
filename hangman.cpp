#include "hangman.h"
#include <fstream>
#include <windows.h>
#include <algorithm>
#include <vector>

using namespace std;

Hangman::Hangman(){
	RemainingAlphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	GameOver = false;
	ifstream file("Hangman.txt");
	vector<string> temp;
	mistakes = 0;
	allowedMistakes = 7;
	if(file.is_open()){
		while(getline(file,Answer))
			temp.push_back(Answer);
		file.close();
	}else
		cout << "Issue opening file";
	Answer = temp[rand() % temp.size()];
	for(int i = 0; i < Answer.size(); i++)
		Answer[i] = toupper(Answer[i]);
}

void Hangman::Display(){
	system("CLS");
	cout << string(allowedMistakes + 2, char(177)) << endl;
	for(int i = 0; i < allowedMistakes; i++){
		if(i == 0) cout << char(177);
		if(i < allowedMistakes - mistakes)
			cout << char(178);
		else
			cout << char(176);
		if(i == allowedMistakes - 1) cout << char(177);
	}
	cout << endl << string(allowedMistakes + 2, char(177)) << "\n\t";

	for(int i = 0; i < 26; i++)
		cout << RemainingAlphabet[i] << " ";
	cout << endl << "\t";
	for(int i = 0; i < Answer.size(); i++)
		if(!isChrInStr(Answer[i],RemainingAlphabet))
			cout << Answer[i] << " ";
		else
			cout << "_ ";
}
void Hangman::Input(){
	guess = _getch();
	if(guess == '~')
		GameOver = true;
	guess = toupper(guess);
}
void Hangman::Logic(){
	if(isNotChar()) return;
	bool win = true;
	if(!isChrInStr()){
		mistakes++;
		if(mistakes >= allowedMistakes)
			GameOver = true;
	}
	replace(RemainingAlphabet.begin(),RemainingAlphabet.end(),guess,'_');
	for(int i = 0; i < Answer.size(); i++)
		if(isChrInStr(Answer[i],RemainingAlphabet))
			win = false;
	if(win)
		GameOver = true;
}

bool Hangman::isOver(){
	return GameOver;
}
bool Hangman::isNotChar(){
	if(guess == '\r' || guess == '\t' || guess == ' ' ||
		guess == ';' || guess == '\'' || guess == ':' ||
		guess == '[' || guess == ']' || guess == '\\' ||
		guess == '{' || guess == '}' || guess == '|' ||
		guess == '"' || guess == '~' || guess == ',' ||
		guess == '.' || guess == '/' || guess == '<' ||
		guess == '>' || guess == '?' || guess == '-' ||
		guess == '=' || guess == '_' || guess == '+' ||
		guess == '1' || guess == '2' || guess == '3' ||
		guess == '4' || guess == '5' || guess == '6' ||
		guess == '7' || guess == '8' || guess == '9' ||
		guess == '0' || guess == '!' || guess == '@' ||
		guess == '#' || guess == '$' || guess == '%' ||
		guess == '^' || guess == '&' || guess == '*' ||
		guess == '(' || guess == ')' || guess == '`') return true;
	return false;
}
bool Hangman::isChrInStr(){
	for(int i = 0; i < Answer.size(); i++)
		if(Answer[i] == guess)
			return true;
}
bool Hangman::isChrInStr(char a, string b){
	for(int i = 0; i < b.size(); i++)
		if(b[i] == a)
			return true;
}
bool Hangman::isWin(){
	if(mistakes<7)
		return true;
	return false;
}
string Hangman::Solution(){
	return Answer;
}