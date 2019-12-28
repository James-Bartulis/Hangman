#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include "hangman.cpp"

using namespace std;

void SetFontSize(int size){
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	cfi.dwFontSize.X = 0;                   // Width of each character in the font
	cfi.dwFontSize.Y = size;                  // Height
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	std::wcscpy(cfi.FaceName, L"Consolas"); // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

int main(){

	srand(time(NULL));
	SetFontSize(52);
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
	SetFontSize(16);
}