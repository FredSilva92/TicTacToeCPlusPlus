#pragma once


namespace MyGames {

	enum class Player : short {P1, P2};
	enum class Symbol : short {NONE, X, O};

	constexpr const char symbolToStr(Symbol s) {
		switch (s) {
			case Symbol::X:
				return 'X';
			case Symbol::O:
				return 'O';
			default: return '|';
		}
	}



	class TicTacToe {
		public:
			void init();
		private:
			const short totalSquares = 9;
			bool checkResult();
			bool checkRowCol(int first, int incr);
			void draw();
			void initSquares();
			void onGame();
	};

}