#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "hangman.cpp"

using namespace std;

int main(){

	srand(time(NULL));

	Hangman *test = new Hangman();

	while(!test->isOver()){
		test->Display();
		test->Input();
		test->Logic();
	}

	test->Display();

	if(!test->isWin())
		cout << test->Solution() << endl << "Better Luck Next Time!\n";
	else
		cout << endl << "Congratulations!!\n";
	system("PAUSE");
}