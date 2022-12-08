#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<ctime>
#include<iomanip>
#include <conio.h>


using namespace std;
#define up 72
#define down 80
#define left 75
#define right 77

void inputMovement(int move, int &pX, int &pY, char dizi[100][100], int dimension, int& goldcounter, int start) {
	switch (move = _getch()) {
	case up:
		if (pY - 1 >= 0) {
			if (dizi[pY - 1][pX] != '1')
				if (dizi[pY - 1][pX] == 4)
				{
					goldcounter++;
					dizi[pY - 1][pX] = '0';
					pY--;
				}
				else if (dizi[pY - 1][pX] == 21)
				{
					pY = 0;
					pX = start;
				}
				else
					pY--;
		}
		break;
	case down:
		if (pY + 1 <= dimension - 1) {
			if (dizi[pY + 1][pX] != '1')
				if (dizi[pY + 1][pX] == 4)
				{
					goldcounter++;
					dizi[pY + 1][pX] = '0';
					pY++;
				}
				else if (dizi[pY + 1][pX] == 21)
				{
					pY = 0;
					pX = start;
				}
				else
					pY++;
		}
		break;
	case left:
		if (pX - 1 >= 0) {
			if (dizi[pY][pX - 1] != '1')
				if (dizi[pY][pX - 1] == 4)
				{
					goldcounter++;
					dizi[pY][pX - 1] = '0';
					pX--;
				}
				else if (dizi[pY][pX - 1] == 21)
				{
					pY = 0;
					pX = start;
				}
				else
					pX--;
		}
		break;
	case right:
		if (pX + 1 <= dimension - 1) {
			if (dizi[pY][pX + 1] != '1')
				if (dizi[pY][pX + 1] == 4)
				{
					goldcounter++;
					dizi[pY][pX + 1] = '0';
					pX++;
				}
				else if (dizi[pY][pX + 1] == 21)
				{
					pY = 0;
					pX = start;
				}
				else
					pX++;
		}
	}
	//cout << "\n\n" << pX << "\t" << pY;
}
void play(int &pX, int &pY, char dizi[100][100], int dimension, int start, ofstream &outFile) {
	for (int i = 0; i < dimension; i++)
	{
		for (int j = 0; j < dimension; j++)
		{
			if (j == pX && i == pY) {
				cout << "X ";
				outFile << "\n" << pX << "\t" << pY;
				continue;
			}
			cout << dizi[i][j] << " ";
		}
		cout << "\n";
	}
}
void makeRoad(char dizi[100][100], int sayi, int &finx, int &finy, int start) {

	for (int i = 0; i < sayi; i++) {
		for (int j = 0; j < sayi; j++) {
			dizi[i][j] = '1';
		}
	}
	srand(time(0));
	dizi[0][start] = 'S';

	int x = 0, y = start, random, fin = 0;

	while (fin == 0) {
		if (y == 0) {
			random = rand() % 2;
			switch (random) {
			case 0:
				dizi[x + 1][y] = '0';
				x++;
				break;
			case 1:
				if (dizi[x][y + 1] == '0' || dizi[x - 1][y + 1] == '0') {
					dizi[x + 1][y] = '0';
					x++;
				}
				else {
					dizi[x][y + 1] = '0';
					y++;
				}

				break;
			}
		}
		else if (y == (sayi - 1)) {
			random = rand() % 2;
			switch (random) {
			case 0:
				dizi[x + 1][y] = '0';
				x++;
				break;
			case 1:
				if (dizi[x][y - 1] == '0' || dizi[x - 1][y - 1] == '0') {
					dizi[x + 1][y] = '0';
					x++;
				}
				else {
					dizi[x][y - 1] = '0';
					y--;
				}

				break;
			}
		}
		else {
			int cik = 0;
			if (x == 0) {
				dizi[x + 1][y] = '0';
				x++;
			}
			else if (y == sayi - 1) {
				dizi[x][y] = 'F';
			}
			else {
				while (cik == 0) {
					random = rand() % 3;
					if (random == 0) {
						dizi[x + 1][y] = '0';
						x++;
						cik = 1;
					}
					else if (random == 1 && dizi[x][y - 1] != '0' &&  dizi[x - 1][y - 1] != '0') {
						dizi[x][y - 1] = '0';
						y--;
						cik = 1;
					}
					else if (random == 2 && dizi[x][y + 1] != '0' && dizi[x - 1][y + 1] != '0') {
						dizi[x][y + 1] = '0';
						y++;
					}
				}
			}
		}
		if (x == sayi - 1) {
			fin = 1;
			finx = y;
			finy = x;
			//cout << finx << " " << finy;
		}
	}

}

void makeMaze(char dizi[100][100], int sayi, int basla) {

	srand(time(0));
	//		dizi[start][1] = 'S';

	int x = basla, y = 1, random, fin = 0;
	//dizi[x][y] = '0'; 

	while (fin == 0) {
		if (x == 1) {
			random = rand() % 2;
			switch (random) {
			case 0:
				dizi[x][y + 1] = '0';
				y++;
				break;
			case 1:
				dizi[x + 1][y] = '0';
				x++;
				break;
			}
		}
		else if (x == (sayi - 2)) {
			random = rand() % 2;
			switch (random) {
			case 0:
				dizi[x][y + 1] = '0';
				y++;
				break;
			case 1:
				dizi[x - 1][y] = '0';
				y--;

				break;
			}
		}
		else {
			int cik = 0;
			if (y == 1) {
				dizi[x][y + 1] = '0';
				y++;
			}
			else if (y == sayi - 1) {
				dizi[x][y] = 'F';
			}
			else {
				while (cik == 0) {
					random = rand() % 3;
					if (random == 0) {
						dizi[x][y + 1] = '0';
						y++;
						cik = 1;
					}
					else if (random == 1 && dizi[x + 1][y] != '0' &&  dizi[x + 1][y + 1] != '0') {
						dizi[x + 1][y] = '0';
						x++;
						cik = 1;
					}
					else if (random == 2 && dizi[x - 1][y] != '0' && dizi[x - 1][y - 1] != '0') {
						dizi[x - 1][y] = '0';
						x--;
					}
				}
			}
		}
		if (y == sayi - 2) {
			fin = 1;
		}

	}


}

bool checkWin(int &pX, int &pY, int finx, int finy) {
	if (pX == finx && pY == finy) {
		return true;
	}
	return false;
}
void Clear() {
	system("CLS");
}


int main() {
	srand(time(NULL));
	ofstream outFile;
	outFile.open("moves.txt");
	int dimension;
	int goldcounter = 0;
	int finx = 0, finy = 0;
	char dizi[100][100];
	int movement = 0;
	cout << "Maze Game-------- Your moves are saving to moves.txt.";
	cout << "\nEnter the length of maze(minimum 10x10 maximum 100x100:";
	cin >> dimension;
	while (dimension>100||dimension<10)
	{
		cout << "\nYou must enter a number between 10 and 100";
		cout << "\nEnter the length of maze(minimum 10x10 maximum 100x100:";
		cin >> dimension;
	}
	int a = dimension - 1;
	int start, b;
	start = rand() % a;
	int positionX = start;
	int positionY = 0;
	char monster = 21;
	char gold = 4;

	outFile << "Your moves in the game:";
	outFile << "\n\nX\tY";
	outFile << "\n---\t---";
	cout << "\nUse arrow keys to play!" << endl;
	cout << "If you hit the monster you will spawn to start point!" << endl;
	cout << "NOTE: If you see monster on the ending road please restart the game" << endl;
	cout << "\nX--You";
	cout << "\n1--Walls";
	cout << "\n0--Roads";
	cout << "\n" << monster << "--Monsters";
	cout << "\n" << gold << "--Golds" << endl;


	makeRoad(dizi, dimension, finx, finy, start);
	int dallanmasayisi = dimension / 5;
	int basla = 2;
	for (int i = 0; i < dallanmasayisi; i++) {
		makeMaze(dizi, dimension, basla);
		basla = basla + 4;
	}




	for (int i = 1; i < dimension - 1; i++) {
		for (int j = 0; j < dimension; j++) {
			if (dizi[i][j] == '0') {
				int ranx = rand() % 100;
				if (ranx < 20) {
					dizi[i][j] = gold;
				}
				else if (ranx >= 20 && ranx < 25) {
					dizi[i][j] = monster;
				}
			}
		}
	}

	while (!checkWin(positionX, positionY, finx, finy))
	{
		play(positionX, positionY, dizi, dimension, start, outFile);
		inputMovement(movement, positionX, positionY, dizi, dimension, goldcounter, start);
		Clear();
	}
	cout << "\n\nCongrats You finish the game!" << endl;
	cout << "\nCollected Gold:" << goldcounter << endl;

	return 0;
}
