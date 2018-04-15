//#pragma once
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <list>
/*TODO:
1. Wenn am Rand, muessen nicht nur die constraints der umgebenden Pixel einbezogen werden,
	sondern abgefragt werden, ob -aufgrund der eigenen Umgebung- ueberhaupt beide Wahrheitswerte moegliche sind.
2. Wenn 1 erledigt, kann der Alg mehrmals angewandt werden - bis er kein Ergebnis findet
3.Datenbank anlegen vom Alphabet als board input - automatisch String Text in GOL umwandeln

*/
const int boardSize = 14;

bool boardA[boardSize][boardSize] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,1,1,1,1,1,1,0,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};
bool boardE[boardSize][boardSize] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,1,1,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,1,1,0,0,0,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};
bool boardW[boardSize][boardSize] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,1,1,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,1,1,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,1,1,0,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,0,1,1,0,0,1,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};
bool boardO[boardSize][boardSize] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,1,1,1,1,1,1,0,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,0,1,1,1,1,1,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};
bool boardL[boardSize][boardSize] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};
bool boardH[boardSize][boardSize] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};
bool boardR[boardSize][boardSize] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,0,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,0,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};
bool boardD[boardSize][boardSize] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,0,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};


//create board
/*
const int boardSize = 16;
bool board[boardSize][boardSize] = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0 },
	{ 0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },
	{ 0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0 },
	{ 0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0 },
	{ 0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};
*/
bool board[boardSize][boardSize];/* = {
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,1,1,1,1,1,1,0,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,1,1,1,1,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,1,1,0,0,0,0,1,1,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0 }
};*/

char domains[boardSize][boardSize];
char domainsRef[boardSize][boardSize];

void printArr(bool toPrint) {
	for (int i = 0; i < boardSize; i++) {
		std::cout << std::endl;
		for (int j = 0; j < boardSize; j++) {
			if (toPrint) std::cout << board[i][j] << " ";
			else {
				if (domains[i][j] == 't') std::cout << 1 << " ";
				else if(domains[i][j] == 'f') std::cout << 0 << " ";
				else std::cout << domains[i][j] << " ";
			}
		}
	}
	std::cout << std::endl;
}
bool isBoarder(int indI, int indJ, int margin) {
	return ((indI - margin < 0) || (indJ - margin < 0) || (indI + margin >= boardSize) || (indJ + margin >= boardSize));
}
bool isBoarderlessSol(int margin) {
	for (int i = 0; i <= boardSize; i++) {
		for (int j = 0; j <= boardSize; j++) {
			if (domains[i][j] == 't') {
				if (((i - margin) < 0) || ((j - margin) < 0) || ((i + margin) >= boardSize) || ((j + margin) >= boardSize)) {
					return false;
				}


			}
		}
	}
	return true;
}
std::vector<int> countNeigh(int indI, int indJ) {
	std::vector<int> res(3,0);
	//int res[3] = { 0,0,0 };
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) {
				continue;
			}
			else if ((indI + i < 0) || (indI + i >= boardSize) || (indJ + j < 0) || (indJ + j >= boardSize)) {
				res[1]++;
			}
			else if (domains[indI + i][indJ + j] == 't') {
				res[0] ++;
			}
			else if (domains[indI + i][indJ + j] == 'f') {
				res[1] ++;
			}
			else {
				res[2]++;
			}
		}
	}
	return res;
}
void restore(int indI, int indJ) {
	//std::cout <<"restore: " << indI << " " << indJ << std::endl;
	bool done = false;
	while (!done) {
		done = ((domains[indI][indJ] == 'b') || ((indI == boardSize - 1) && (indJ == boardSize - 1)));
		//done = ((indI == boardSize - 1) && (indJ == boardSize - 1));
		domains[indI][indJ] = domainsRef[indI][indJ];
		indI = indI + ((indJ + 1) / boardSize);
		indJ = (indJ + 1) % boardSize;
	}
	//printArr(false);
	//std::cout << "done restoring" << std::endl;

}
char applyConstraint(int indI, int indJ, char con, char newDomain) {
	if ((newDomain == 'b') || (newDomain == con)) {
		newDomain = con;
	}
	else {
		newDomain = 'x';
	}
	return newDomain;
}
//recursive function input: domain array:
bool solve(int indI, int indJ) {
	//std::cout << indI << " " << indJ << std::endl;
	//if (indI == boardSize - 1 && indJ == boardSize - 1) return true;
	if (indI == boardSize) {
		if (isBoarderlessSol(0)) return true;
		else return false;
	}
	if (domains[indI][indJ] == 'f') {
		return solve(indI + ((indJ + 1) / boardSize), (indJ + 1) % boardSize);
	}
	//check whether the domain of the current pixel can be reduced
	char newDomain = 'b';
	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			char currDomain; 
			bool currBoard;
			if ((indI + i < 0) || (indI + i >= boardSize) || (indJ + j < 0) || (indJ + j >= boardSize)) {
				currDomain = 'f';
				currBoard = false;
			}else{
				currDomain = domains[indI + i][indJ + j];
				currBoard = board[indI + i][indJ + j];
			}
			if (currDomain == 'b') {
				continue;
			}
			bool isOwn = false;
			if ((i == 0 && j == 0)) {
				isOwn = true;
			}
			//int *neighArr = countNeigh(indI + i, indJ + j);
			//nr alive/dead neighbors:
			//int nrAlive = *neighArr;
			//int nrDead = *(neighArr + 1);
			//int nrUndecided = *(neighArr + 2);
			std::vector<int> neighbors = countNeigh(indI + i, indJ + j);
			//if (indI == 9 && indJ == 5) {
			//	if (i == -1 && j == -1) {
			//		std::cout << " nachbarn von 84 von 95 gerechnet "  << std::endl;
			//		std::cout << neighbors[0] << " " << neighbors[1] << " " << neighbors[2] << std::endl;
			//		printArr(false);
			//	}
			//}
			//std::cout << neighbors[0] << " " << neighbors[1] << " " << neighbors[2] << std::endl;
			int nrAlive = neighbors[0];
			int nrDead = neighbors[1];
			int nrUndecided = neighbors[2];
			if ((currDomain == 't')&&(!isOwn)) {
				if (currBoard) {
					//wenn schon 3 lebende Nachbarn dann darf keiner dazu kommen
					if (nrAlive == 3) {
						//domain false only
						newDomain = applyConstraint(indI, indJ, 'f', newDomain);

					}
					//wenn nur 0 oder 1 lebende und nur 2 bzw 1 undecided dann muss der leben
					else if (nrAlive + nrUndecided == 2) {
						//domain alive only
						newDomain = applyConstraint(indI, indJ, 't', newDomain);

					}
					//if nrAlive>3 - widerspruch
					else if (nrAlive > 3) {
						//widerspruch
						newDomain = applyConstraint(indI, indJ, 'x', newDomain);

					}
					else if (nrAlive + nrUndecided < 2) {
						//widerspruch
						newDomain = applyConstraint(indI, indJ, 'x', newDomain);
					}
				}
				else {

					if (nrAlive == 2 || nrAlive == 3) {
						//wenn 2 oder 3 lebende Nachbarn und nrUndecided+nrAlive <=3 dann widerspruch 
						if (nrAlive + nrUndecided <= 3) {
							//widerspruch
							newDomain = applyConstraint(indI, indJ, 'x', newDomain);
						}
						//wenn 2 oder 3 lebende nachbarn, und nrUndecided ist 2 bzw 1 dann muss der leben
						else if (nrAlive + nrUndecided == 4) {
							//alive only
							newDomain = applyConstraint(indI, indJ, 't', newDomain);

						}
					}

					//wenn 1 lebender Nachbar und nrUndecided ist 1 oder 2 dann false
					else if ((nrAlive == 1) && (nrAlive + nrUndecided <= 3)) {
						//dead only
						newDomain = applyConstraint(indI, indJ, 'f', newDomain);
					}
				}
			}
			else if ((currDomain == 'f') && (!isOwn)) {
				if (currBoard) {
					//wenn nrAlive > 3 dann widerspruch
					if (nrAlive > 3) {
						//widerspruch
						newDomain = applyConstraint(indI, indJ, 'x', newDomain);
					}
					//wenn nrAlive == 3 dann false only
					else if (nrAlive == 3) {
						//dead only
						newDomain = applyConstraint(indI, indJ, 'f', newDomain);
					}
					//wenn nrALive + nrUndecided < 3 widerspruch
					else if (nrAlive + nrUndecided < 3) {
						//widerspruch
						newDomain = applyConstraint(indI, indJ, 'x', newDomain);
					}

					//wenn nrAlive + nrUndecided == 3 true only
					else if (nrAlive + nrUndecided == 3) {
						//alive only
						newDomain = applyConstraint(indI, indJ, 't', newDomain);
					}
				}
				else {
					if (nrAlive == 2 && nrUndecided == 1) {
						//dead only
						newDomain = applyConstraint(indI, indJ, 'f', newDomain);
					}
					else if ((nrAlive == 3) && nrUndecided == 1) {
						//alive only
						newDomain = applyConstraint(indI, indJ, 't', newDomain);
					}
				}

			}
			else if (isOwn) {
				if (board[indI + i][indJ + j]) {
					if (nrAlive + nrUndecided < 3) {
						newDomain = applyConstraint(indI, indJ, 't', newDomain);
					}
				}
				else {
					if ((nrAlive == 2 || nrAlive == 3) && (nrAlive + nrUndecided <= 3)) {
						newDomain = applyConstraint(indI, indJ, 'f', newDomain);
					}
							}
			}
		}
	}
	domains[indI][indJ] = newDomain;
	//if (indI == 1 && indJ == 5) {
	//	std::cout << "domain von 1 5: " << domains[indI][indJ] << std::endl;
	//	if (domains[indI][indJ] == 't') printArr(false);
	//}
	if (domains[indI][indJ] == 'x') {
		//std::cout << "fail" << std::endl;
		return false;
	}
	//call solve recursively
	else if (domains[indI][indJ] == 'b') {
		char fix0, fix1;
		//which path to follow first?
		//if (board[indI][indJ]) oder !isBoarder(indI,indJ,4)
		if (!isBoarder(indI, indJ, 3)) {
			fix0 = 't';
			fix1 = 'f';
		}
		else { 
			fix0 = 'f'; 
			fix1 = 't';
		}
		domains[indI][indJ] = fix0;
		bool res0 = solve(indI + ((indJ + 1) / boardSize), (indJ + 1) % boardSize);
		//if (indI == 1 && indJ == 3) std::cout << "Ergebnis von 1 3 true: " << res0 << std::endl;
		if (res0) {
			return res0;
		}
		else {

			restore(indI, indJ);

			domains[indI][indJ] = fix1;
			bool res1 = solve(indI + ((indJ + 1) / boardSize), (indJ + 1) % boardSize);
			//if (indI == 1 && indJ == 3) std::cout << "Ergebnis von 1 3 false: " << res0 << std::endl;
			if (res1) {
				return res1;
			}
			else {
				return false;
			}
		}
	}
	else if ((domains[indI][indJ] == 't')|| domains[indI][indJ] == 'f') {
		return solve(indI + ((indJ + 1) / boardSize), (indJ + 1) % boardSize);

	}
	
	//check for termination (conflict or succesful finish)

	//call solve for next pixel with each value of the domain fixed (explore current board value first)
}


bool isDeadArea(int indI, int indJ) {
	return false;
	for (int i = -2; i <= 2; i++) {
		for (int j = -2; j <= 2; j++) {
			if (indI + i >= boardSize || indI + i < 0 || indJ + j >= boardSize || indJ + j < 0) {
				continue;
			}
			if (board[indI + i][indJ + j]) {
				return false;
			}

		}

	}
	return true;
}

std::map<int, std::vector<int>> fillResMap(std::map<int, std::vector<int>> resMap, int offRow, int offCol) {
	for (int i = 0; i < boardSize; i++) {
		std::vector<int> row;
		for (int j = 0; j < boardSize; j++) {
			if (domains[i][j] == 't') {
				int colC = j + offCol;
				row.push_back(colC);
			}
		}
		if (!row.empty()) {
			int rowC = i + offRow;
			std::map<int, std::vector<int>>::iterator it = resMap.find(rowC);
			if (it != resMap.end()) {
				std::vector<int> rowCont = it->second;
				rowCont.insert(rowCont.begin(), row.begin(), row.end());
				resMap.erase(it);
				resMap.insert(std::pair<int, std::vector<int>>(rowC, rowCont));
			}
			else resMap.insert(std::pair<int, std::vector<int>>(rowC, row));
			
		}

	}
	return resMap;
}
std::string mapToLink(std::map<int, std::vector<int>> resMap) {
	//pmav.eu/stuff/javascript-game-of-life-v3.1.1/?autoplay=0&trail=1&grid=1&colors=1&zoom=1&s=[{"0":[0]},{"28":[35]},{"29":[35]},{"30":[34,35,36]},{"31":[34,36]},{"32":[35]}]
	//[{"0":[0]},{"28":[35]},{"29":[35]},{"30":[34,35,36]},{"31":[34,36]},{"32":[35]}]
	std::string base = "pmav.eu/stuff/javascript-game-of-life-v3.1.1/?autoplay=0&trail=1&grid=1&colors=1&zoom=1&s=[";
	std::string coords;
	
	for (std::map<int, std::vector<int>>::iterator it = resMap.begin(); it != resMap.end(); ++it) {
		int rowC = it->first;

			coords = "{\"" + std::to_string(rowC) + "\":[";
			std::vector<int> row = it->second;
			for (std::vector<int>::iterator it = row.begin(); it != row.end(); ++it) {
				coords.append(std::to_string(*it) + ",");
			}
			coords.pop_back();
			coords.append("]},");
			base.append(coords);
		}

	base.pop_back();
	base.append("]");
	return base;
}
std::string getLinkOLD(int offRow, int offCol) {
	//pmav.eu/stuff/javascript-game-of-life-v3.1.1/?autoplay=0&trail=1&grid=1&colors=1&zoom=1&s=[{"0":[0]},{"28":[35]},{"29":[35]},{"30":[34,35,36]},{"31":[34,36]},{"32":[35]}]
	//[{"0":[0]},{"28":[35]},{"29":[35]},{"30":[34,35,36]},{"31":[34,36]},{"32":[35]}]
	std::string base = "pmav.eu/stuff/javascript-game-of-life-v3.1.1/?autoplay=0&trail=1&grid=1&colors=1&zoom=1&s=[";
	std::string coords;
	for (int i = 0; i < boardSize; i++) {
		std::vector<int> row;
		for (int j = 0; j < boardSize; j++) {
			if (domains[i][j] == 't'){
				int colC = j + offCol;
				row.push_back(colC);
			}
		}
		if (!row.empty()) {
			int rowC = i + offRow;
			
			coords = "{\""+ std::to_string(rowC)+"\":[";
			for (std::vector<int>::iterator it = row.begin(); it != row.end(); ++it) {
				coords.append(std::to_string(*it)+",");
			}
			coords.pop_back();
			coords.append("]},");
			base.append(coords);
		}
		
	}
	base.pop_back();
	base.append("]");
	return base;
}
void setBoardToLetter(char letter) {

	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {


			if (letter == 'A') {
				board[i][j] = boardA[i][j];
			}
			else if (letter == 'H') {
				board[i][j] = boardH[i][j];

			
			}
			else if (letter == 'E') {
				board[i][j] = boardE[i][j];

			}
			else if (letter == 'L') {
				board[i][j] = boardL[i][j];
			}
			else if (letter == 'O') {
				board[i][j] = boardO[i][j];
			}
			else if (letter == 'W') {
				board[i][j] = boardW[i][j];
			}
			else if (letter == 'R') {
				board[i][j] = boardR[i][j];
			}
			else if (letter == 'D') {
				board[i][j] = boardD[i][j];
			}
		}
	}


}
void setBoardToDomain() {
	for (int i = 0; i < boardSize; i++) {
		for (int j = 0; j < boardSize; j++) {
			if (domains[i][j] == 't') board[i][j] = 1;
			else if (domains[i][j] == 'f') board[i][j] = 0;
			else std::cout << "Something is wrong" << std::endl;
		}
	}
}
int main() {

	std::string toRevert = "HELLO";
	//extract sub-boards (extract islands)
	//for each island
	std::map<int, std::vector<int>> resMap;
	int offRow = 15;
	int offCol = 30;

	int index = 0;
	bool done = false;
	int solDepth = 1;
	while (!done) {
		if (toRevert.length() == 0) done = true;
		else {
			if (toRevert.length() == index + 1) done = true;
			if (!(toRevert[index] == ' ')) {
				setBoardToLetter(toRevert[index]);
			}
			else {
				index++;
				continue;
						}
		}
		/*create domain array, set domain of dead pixels with only dead neighbors to dead only*/
		bool success;
		for (int curSolDepth = 0; curSolDepth < solDepth; curSolDepth++) {
			for (int i = 0; i < boardSize; i++) {
				for (int j = 0; j < boardSize; j++) {
					if (isDeadArea(i, j)) {
						domains[i][j] = 'f';
						domainsRef[i][j] = 'f';
					}
					else {
						domains[i][j] = 'b';
						domainsRef[i][j] = 'b';

					}

				}

			}
			printArr(true);
			//printArr(false);
			success = solve(0, 0);
			printArr(false);
			setBoardToDomain();

		}
		if (success) {
			int newOffRow = offRow;
			resMap = fillResMap(resMap, newOffRow, offCol*index);

		}
		else std::cout << "no success" << std::endl;
		
		index++;
	}
	std::string resLink = mapToLink(resMap);
	std::cout << resLink << std::endl;
}

