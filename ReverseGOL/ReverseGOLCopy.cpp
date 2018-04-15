//#pragma once
#include "stdafx.h"
#include <iostream>



//create board
const int boardSize = 5;
bool board[boardSize][boardSize];
struct domainStruct
{
	char domainArr[boardSize][boardSize];
};
//TODO: statt jedes Mal eine Kopie des Arrays zu erzeugen waere es besser nur einen Zaehler zu erzeugen und die entsprechende
//Anzahl an Schritten im falle eines Widerspuches rueckgaengig zu machen. Nur wenn ein branch parallel abgearbeitet werden soll
//muss das domain Array kopiert werden


int* countNeigh(int indI, int indJ, domainStruct& dStruct) {
	int res[3] = { 0,0,0 };
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) {
				continue;
			}
			if (dStruct.domainArr[indI + i][indJ + j] == 't') {
				res[0] ++;
			}
			else if (dStruct.domainArr[indI + i][indJ + j] == 'f') {
				res[1] ++;
			}
			else {
				res[2]++;
			}
		}
	}
	return res;
}

//recursive function input: domain array:
domainStruct solve(int indI, int indJ, struct domainStruct dStruct) {
	if (indI == boardSize - 1 && indJ == boardSize - 1) {
		return dStruct;
	}
	if (dStruct.domainArr[indI][indJ] == 'f') {
		return solve(indI + ((indJ + 1) / boardSize), (indJ + 1) % boardSize, dStruct);
	}
	//check whether the domain of the current pixel can be reduced

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if ((i == 0 && j == 0) || (dStruct.domainArr[i][j] == 'b')) {
				continue;
			}
			int *neighArr = countNeigh(indI + i, indJ + j, dStruct);
			//nr alive/dead neighbors:
			int nrAlive = *neighArr;
			int nrDead = *(neighArr + 1);
			int nrUndecided = *(neighArr + 2);
			if (dStruct.domainArr[indI + i][indJ + j] == 't') {
				if (board[indI + i][indJ + j]) {
					//wenn schon 3 lebende Nachbarn dann darf keiner dazu kommen
					if (nrAlive == 3) {
						//domain false only
						dStruct.domainArr[indI][indJ] = 'f';

					}
					//wenn nur 0 oder 1 lebende und nur 2 bzw 1 undecided dann muss der leben
					else if (nrAlive + nrUndecided == 2) {
						//domain alive only
						dStruct.domainArr[indI][indJ] = 't';

					}
					//if nrAlive>3 - widerspruch
					else if (nrAlive > 3) {
						//widerspruch
						dStruct.domainArr[indI][indJ] = 'x';

					}
					else if (nrAlive + nrUndecided < 2) {
						//widerspruch
						dStruct.domainArr[indI][indJ] = 'x';
					}
				}
				else {
					if (nrAlive == 2 || nrAlive == 3) {
						//wenn 2 oder 3 lebende Nachbarn und nrUndecided+nrAlive <=3 dann widerspruch 
						if (nrAlive + nrUndecided <= 3) {
							//widerspruch
							dStruct.domainArr[indI][indJ] = 'x';
						}
						//wenn 2 oder 3 lebende nachbarn, und nrUndecided ist 2 bzw 1 dann muss der leben
						else if (nrAlive + nrUndecided == 4) {
							//alive only
							dStruct.domainArr[indI][indJ] = 't';

						}
					}

					//wenn 1 lebender Nachbar und nrUndecided ist 1 oder 2 dann false
					else if ((nrAlive == 1) && (nrAlive + nrUndecided <= 3)) {
						//dead only
						dStruct.domainArr[indI][indJ] = 'f';
					}
				}
			}
			else if (dStruct.domainArr[i][j] == 'f') {
				if (board[indI + i][indJ + j]) {
					//wenn nrAlive > 3 dann widerspruch
					if (nrAlive > 3) {
						//widerspruch
						dStruct.domainArr[indI][indJ] = 'x';
					}
					//wenn nrAlive == 3 dann false only
					else if (nrAlive == 3) {
						//dead only
						dStruct.domainArr[indI][indJ] = 'f';
					}
					//wenn nrALive + nrUndecided < 3 widerspruch
					else if (nrAlive + nrUndecided < 3) {
						//widerspruch
						dStruct.domainArr[indI][indJ] = 'x';
					}

					//wenn nrAlive + nrUndecided == 3 true only
					else if (nrAlive + nrUndecided == 3) {
						//alive only
						dStruct.domainArr[indI][indJ] = 't';
					}
				}
				else {
					if (nrAlive == 2 && nrUndecided == 1) {
						//dead only
						dStruct.domainArr[indI][indJ] = 'f';
					}
					else if ((nrAlive == 3) && nrUndecided == 1) {
						//alive only
						dStruct.domainArr[indI][indJ] = 't';
					}
				}

			}
		}

		//call solve recursively
		if (dStruct.domainArr[indI][indJ] == 'b') {
			dStruct.domainArr[indI][indJ] = 't';
			solve(indI + ((indJ + 1) / boardSize), (indJ + 1) % boardSize, dStruct);
			dStruct.domainArr[indI][indJ] = 'f';
			solve(indI + ((indJ + 1) / boardSize), (indJ + 1) % boardSize, dStruct);
			dStruct.domainArr[indI][indJ] = 'b';
		}
		else if ((dStruct.domainArr[indI][indJ] == 't') || dStruct.domainArr[indI][indJ] == 'f') {
			int newIndI = indI + ((indJ + 1) / boardSize);
			int newIndJ = (indJ + 1) % boardSize;
			solve(newIndI, newIndJ, dStruct);
		}
	}
	//check for termination (conflict or succesful finish)

	//call solve for next pixel with each value of the domain fixed (explore current board value first)
}

bool isDeadArea(bool board[][boardSize], int indI, int indJ) {
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (board[indI + i][indJ + j]) {
				return false;
			}

		}

	}
	return true;
}

int main() {

	//set example board:
	board[2][2] = true;

	//extract sub-boards (extract islands)

	//for each island

	//create domain array, set domain of dead pixels with only dead neighbors to dead only

	struct domainStruct dStruct;
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (isDeadArea(board, i, j)) {
				dStruct.domainArr[i][j] = 'f';

			}
			else {
				dStruct.domainArr[i][j] = 'b';
			}

		}

	}
	solve(0, 0, dStruct);

}

