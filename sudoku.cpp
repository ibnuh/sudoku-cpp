#include <iostream>

#include <conio.h>

#include <stdlib.h>

#include <iomanip>

#include "donkey.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void render(int playground[9][9], int x, int y) {
    donkey::cls();

    cout << "   _____           _       _          " << endl;
    cout << "  / ____|         | |     | |         " << endl;
    cout << " | (___  _   _  __| | ___ | | ___   _ " << endl;
    cout << "  \\___ \\| | | |/ _` |/ _ \\| |/ / | | |" << endl;
    cout << "  ____) | |_| | (_| | (_) |   <| |_| | by M. IBNU LUTHFI AZHAR " << endl;
    cout << " |_____/ \\__,_|\\__,_|\\___/|_|\\_\\\\__,_| 200401067" << endl << endl;
    
    cout << " /-----------------/-----------------/-----------------/" << endl;
	cout << " | .5. |     |     |     |     |     |     |     |     |" << endl;
	cout << " -------------------------------------------------------" << endl;
	cout << " |     |     |     |     |     |     |     |     |     |" << endl;
	cout << " -------------------------------------------------------" << endl;
	cout << " |     |     |     |     |     |     |     |     |     |" << endl;
	cout << " /-----------------/-----------------/-----------------/" << endl;
	cout << " |     |     |     |     |     |     |     |     |     |" << endl;
	cout << " -------------------------------------------------------" << endl;
	cout << " |     |     |     |     |     |     |     |     |     |" << endl;
	cout << " -------------------------------------------------------" << endl;
	cout << " |     |     |     |     |     |     |     |     |     |" << endl;
	cout << " /-----------------/-----------------/-----------------/" << endl;
	cout << " |     |     |     |     |     |     |     |     |     |" << endl;
	cout << " -------------------------------------------------------" << endl;
	cout << " |     |     |     |     |     |     |     |     |     |" << endl;
	cout << " -------------------------------------------------------" << endl;
	cout << " |     |     |     |     |     |     |     |     |     |" << endl;
	cout << " /-----------------/-----------------/-----------------/" << endl;
	
	const int initX = 4, initY = 9, gapX = 6, gapY = 2;

    for (int row = 0; row < 9; row++) {
    	int screenY = initY + (row * gapY);
    	
        for (int column = 0; column < 9; column++) {
        	int screenX = initX + (column * gapX);
            int currentNumber = playground[row][column];
            
            donkey::locate(screenX, screenY);
            
            if (x == column && y == row) { // Check if cursor is in current block
            	if(currentNumber == 0) { // Treat 0 as empty block
            		cout << " _ ";
				}
				else {
					cout << "_" << currentNumber << "_";
				}
            }
            else {
            	if(currentNumber == 0) { // Treat 0 as empty block
            		cout << "   ";
				}
				else {
					cout << " " << currentNumber << " ";
				}
			}
        }
    }
}

int main() {

    int x, y = 0;

    int playground[9][9] = {
		{ 0, 0, 0, 0, 3, 2, 0, 5, 7 },
		{ 0, 0, 5, 1, 0, 0, 0, 0, 0 },
		{ 2, 8, 1, 7, 4, 5, 0, 9, 6 },
		{ 0, 0, 0, 0, 7, 0, 0, 0, 0 },
		{ 0, 0, 8, 0, 0, 9, 7, 6, 0 },
		{ 0, 4, 0, 5, 0, 1, 0, 0, 8 },
		{ 5, 0, 3, 9, 8, 4, 0, 7, 0 },
		{ 6, 0, 4, 0, 6, 7, 0, 3, 1 },
		{ 0, 0, 2, 0, 1, 0, 0, 0, 9 },
	};

	// Render initial playground
    render(playground, x, y);

    while (true) {
        int buttonCode = 0;

        switch (buttonCode = getch()) {
	        case KEY_UP:
	            if (y != 0) y--;
	            break;
	        case KEY_DOWN:
	            if (y != 8) y++;
	            break;
	        case KEY_LEFT:
	            if (x != 0) x--;
	            break;
	        case KEY_RIGHT:
	            if (x != 8) x++;
	            break;
	        default:
	            if (buttonCode >= 48 && buttonCode <= 57) {
	                playground[y][x] = buttonCode - '0'; // Convert ascii number to a real character
	            }
	            break;
        }

        render(playground, x, y);
    }

    system("pause");
    return 0;
}
