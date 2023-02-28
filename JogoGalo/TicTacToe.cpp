#include "TicTacToe.h"
#include <iostream>
#include <map>
#include <vector>
#include <string> 


using namespace MyGames;
using namespace std;

map<int, Symbol> symbolsMap;

void TicTacToe::initSquares() {
	for (int i = 0; i < 9; i++) {
		symbolsMap[i] = Symbol::NONE;
	}
}


void TicTacToe::init() {
	cout << "Prima enter para começar" << endl;
	
	while (true) {

		if (cin.get() == '\n') {
			TicTacToe::onGame();
			break;
		}
	}

	while (true) {
		char opt;
		cout << "Pretende jogar outra vez?(s/n)";
		cin >> opt;
		if (opt == 's') {
			TicTacToe::onGame();
		}
		else if (opt == 'n') {
			break;
		}
	}


	cout << symbolToStr(Symbol::X) << endl;
}

void TicTacToe::onGame() {
	TicTacToe::initSquares();

	Symbol currentPlayer = Symbol::X;

	while (true)
	{
		TicTacToe::draw();

		int option;

		cout << "Escolher opção jogador " << symbolToStr(currentPlayer) << ": ";
		cin >> option;

		option--;

		bool wrongOption = option < 0 || option > 8;

		if (symbolsMap[option] != Symbol::NONE || wrongOption) {
			cout << "Opção errada!\n";
		}
		else {
			bool isXPlayer = currentPlayer == Symbol::X;
			symbolsMap[option] = isXPlayer ? Symbol::X : Symbol::O;

			if (checkResult()) {
				TicTacToe::draw();
				cout << "Parabens jogador " << symbolToStr(currentPlayer) << ", ganhou!!!" << endl;

				break;
			}

			currentPlayer = isXPlayer ? Symbol::O : Symbol::X;
		}
	}


	
}

bool TicTacToe::checkResult() {

	const int rowVerify = 1;
	const int columnVerify = 3;

	Symbol middleHouse = symbolsMap[4];
	bool firstDiag = middleHouse == symbolsMap[0] && middleHouse == symbolsMap[8];
	bool secondDiag = middleHouse == symbolsMap[2] && middleHouse == symbolsMap[6];

	if ((firstDiag || secondDiag) && middleHouse != Symbol::NONE) {
		return true;
	}

	for (int i = 0; i < 3; i++) {
		int initRow = i * 3;

		if (TicTacToe::checkRowCol(initRow, rowVerify)) {
			return true;
		}

		if (TicTacToe::checkRowCol(i, columnVerify)) {
			return true;
		}
	}

	return false;
}

bool TicTacToe::checkRowCol(int first, int incr) {
	int second = first + incr;
	int third = first + incr * 2;

	if (symbolsMap[first] == Symbol::NONE) {
		return false;
	}

	bool isWinner = symbolsMap[first] == symbolsMap[second]
		&& symbolsMap[second] == symbolsMap[third];

	return isWinner;
}

void TicTacToe::draw() {
	const int totalLines = 5;
	std::string board = "";

	int square = 0;

	for (int i = 0; i < totalLines; i++) {
		if (i % 2 != 0) {
			board.append("-|-|-");
			board.append("\n");
			continue;
		}

		for (int j = 0; j < 3; j++) {

			if (symbolsMap[square] == Symbol::NONE) {
				int value = square + 1;
				string str = std::to_string(value);

				board.append(str);
			}
			else {
				char symbolChar = symbolToStr(symbolsMap[square]);
				std::string s(1, symbolChar);
				board.append(s);
			}


			if (j != 2) {
				board.append("|");
			}
			else {
				board.append("\n");
			}
			
			square++;
		}
	}

	cout << board << endl;
}

