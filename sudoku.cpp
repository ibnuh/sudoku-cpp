#include <iostream>

#include <conio.h>

#include <stdlib.h>

#include <iomanip>

#include <algorithm>

#include <iterator>

#include "donkey.h"

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

// https://stackoverflow.com/a/7560171/4460712
int random(int min, int max) //range : [min, max]
{
   static bool first = true;
   if (first) 
   {  
      srand( time(NULL) ); //seeding for the first time only!
      first = false;
   }
   return min + rand() % (( max + 1 ) - min);
}

bool isUnique(int numbers[9]) {
    for (int i = 0; i < 9; i++) {
        if (numbers[i] == 0) continue;

        for (int j = i + 1; j < 9; j++) {
            if (numbers[i] == numbers[j]) {
                donkey::locate(60, 11);
                cout << "Number " << numbers[i];
                return false;
            }
        }
    }

    return true;
}

struct validationResult {
    int col;
    int row;
    string type;
    bool isValid;
    bool isCompleted;
};

// Validate each rows, columns, and squares by
// putting them into a linear array and checking for duplicates
validationResult validate(int playground[9][9]) {
    validationResult validationResult;
    validationResult.isCompleted = false;
    int sum;

    // Check each rows for duplication
    for (int row = 0; row < 9; row++) {
        int numbers[9];

        for (int block = 0; block < 9; block++) {
            numbers[block] = playground[row][block];
            
            sum += numbers[block]; // To check whether the game is completed
        }

        if (!isUnique(numbers)) {
            donkey::locate(60, 10);
            cout << "Row #" << row + 1;

            validationResult.isValid = false;
            validationResult.type = "row";
            validationResult.row = row;

            return validationResult;
        }
    }

    // Check each columns for duplication
    for (int column = 0; column < 9; column++) {
        int numbers[9];

        for (int block = 0; block < 9; block++) {
            numbers[block] = playground[block][column];
        }

        if (!isUnique(numbers)) {
            donkey::locate(60, 10);
            cout << "Column #" << column + 1;

            validationResult.isValid = false;
            validationResult.type = "column";
            validationResult.col = column;

            return validationResult;
        }
    }

    // Check each squares for duplication	
    for (int column = 0; column <= 6; column += 3) {
        int numbers[9];
        for (int row = 0; row <= 6; row += 3) {
            for (int k = 0, i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++)
                    numbers[k++] = playground[row + i][column + j];
            }

            if (!isUnique(numbers)) {
                donkey::locate(60, 10);
                cout << "Square" << endl;

                validationResult.isValid = false;
                validationResult.type = "square";
                validationResult.col = column;
                validationResult.row = row;

                return validationResult;
            }
        }
    }

    validationResult.isValid = true;
    validationResult.isCompleted = sum == 45 * 9;

    return validationResult;
}

void render(int playground[9][9], int x, int y) {
    donkey::cls();
    
	donkey::setColor(donkey::COLORS::WHITE);
    cout << "   _____           _       _          " << endl;
    cout << "  / ____|         | |     | |         " << endl;
    cout << " | (___  _   _  __| | ___ | | ___   _ " << endl;
    cout << "  \\___ \\| | | |/ _` |/ _ \\| |/ / | | |" << endl;
    cout << "  ____) | |_| | (_| | (_) |   <| |_| | by M. IBNU LUTHFI AZHAR " << endl;
    cout << " |_____/ \\__,_|\\__,_|\\___/|_|\\_\\\\__,_| 200401067" << endl << endl;

	donkey::setColor(donkey::COLORS::LIGHTBLUE);
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
    cout << " |     |     |     |     |     |     |     |     |     |" << endl;
    cout << " -------------------------------------------------------" << endl;
    cout << " |     |     |     |     |     |     |     |     |     |" << endl;
    cout << " -------------------------------------------------------" << endl;
    cout << " |     |     |     |     |     |     |     |     |     |" << endl;
    cout << " /-----------------/-----------------/-----------------/" << endl;

	donkey::setColor(donkey::COLORS::WHITE);
    const int initX = 4,
        initY = 9,
        gapX = 6,
        gapY = 2;

    validationResult validation = validate(playground);

    for (int row = 0; row < 9; row++) {
        int screenY = initY + (row * gapY);

        for (int column = 0; column < 9; column++) {
            int screenX = initX + (column * gapX);
            int currentNumber = playground[row][column];

            if (!validation.isValid && validation.type == "row" && validation.row == row) {
                donkey::setColor(donkey::COLORS::RED);
            }

            if (!validation.isValid && validation.type == "column" && validation.col == column) {
                donkey::setColor(donkey::COLORS::RED);
            }
            
            if (!validation.isValid
				&& validation.type == "square"
				&& (validation.col <= column && validation.col+2 >= column)
				&& (validation.row <= row && validation.row+2 >= row)) {
                donkey::setColor(donkey::COLORS::RED);
            }

            donkey::locate(screenX, screenY);

            if (x == column && y == row) { // Check if cursor is in current block
                if (currentNumber == 0) { // Treat 0 as empty block
                    cout << "___";
                } else {
                    cout << "_" << currentNumber << "_";
                }
            } else {
                if (currentNumber == 0) { // Treat 0 as empty block
                    cout << "   ";
                } else {
                    cout << " " << currentNumber << " ";
                }
            }

            donkey::setColor(donkey::COLORS::WHITE);
        }
    }

    if (validation.isCompleted) {
    	donkey::setColor(donkey::COLORS::GREEN);
        donkey::locate(60, 9);
        cout << "YOU'VE WON THE GAME" << endl;
        donkey::locate(60, 10);
        cout << "CONGRATULATIONS" << endl;
    } else if (validation.isValid) {
    	donkey::setColor(donkey::COLORS::GREEN);
        donkey::locate(60, 9);
        cout << "Playground is valid" << endl;
	} else {
    	donkey::setColor(donkey::COLORS::RED);
        donkey::locate(60, 9);
        cout << "Duplicate found" << endl;
    }
    
    donkey::setColor(donkey::COLORS::LIGHTMAGENTA);
    donkey::locate(60, 13);
	cout << "Inputs" << endl;
	donkey::locate(61, 14);
	cout << " - Use the arrow buttons to move right/left/up/down" << endl;
	donkey::locate(61, 15);
	cout << " - Use 0 to remove number from the block" << endl;
	donkey::locate(61, 16);
	cout << " - Use 1-9 to input answer to the block" << endl;
}

int main() {

    int x, y = 0;
    
    int playgrounds[3][9][9] = {
		{
			{ 0, 5, 7, 8, 1, 2, 3, 0, 4 },
			{ 8, 4, 0, 7, 5, 0, 1, 2, 9 },
			{ 2, 1, 6, 4, 3, 9, 5, 0, 7 },
			{ 7, 6, 0, 3, 9, 0, 8, 1, 2 },
			{ 0, 2, 1, 5, 7, 8, 0, 3, 6 },
			{ 3, 8, 9, 2, 0, 1, 4, 7, 5 },
			{ 5, 7, 0, 6, 4, 3, 2, 9, 1 },
			{ 0, 9, 0, 1, 8, 5, 0, 4, 3 },
			{ 0, 3, 0, 9, 0, 7, 6, 5, 0 },
		},
		{
			{ 0, 6, 8, 4, 3, 9, 7, 2, 0 },
			{ 0, 7, 4, 8, 0, 2, 1, 9, 3 },
			{ 0, 3, 9, 0, 0, 7, 0, 4, 6 },
			{ 3, 9, 1, 0, 7, 0, 2, 8, 4 },
			{ 7, 8, 0, 9, 0, 3, 6, 5, 1 },
			{ 0, 5, 6, 2, 0, 1, 0, 7, 0 },
			{ 6, 0, 5, 3, 2, 8, 9, 1, 0 },
			{ 8, 1, 0, 6, 0, 4, 5, 3, 2 },
			{ 0, 2, 0, 7, 0, 5, 4, 6, 0 },
		},
		{
			{ 9, 2, 3, 0, 4, 7, 1, 5, 0 },
			{ 1, 8, 6, 2, 0, 5, 7, 4, 3 },
			{ 5, 0, 7, 6, 3, 1, 9, 0, 2 },
			{ 0, 5, 4, 3, 6, 0, 8, 7, 1 },
			{ 7, 1, 0, 0, 2, 8, 3, 6, 4 },
			{ 0, 3, 8, 7, 1, 0, 2, 9, 5 },
			{ 3, 7, 0, 4, 8, 0, 6, 1, 9 },
			{ 4, 0, 2, 1, 7, 6, 5, 3, 8 },
			{ 0, 6, 1, 9, 0, 3, 4, 0, 7 },
		}
	};

    int playground[9][9];
    int randomNumber = random(0, 2);
    
    memcpy(playground, playgrounds[randomNumber], sizeof(playground)); // Apparently this is how you assign an array to a variable in C++, bonkers

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
            if (buttonCode >= 48 && buttonCode <= 57) { // 0 - 9
                playground[y][x] = buttonCode - '0'; // Convert ascii number to a real character
            }
            break;
        }

        if (buttonCode == KEY_UP ||
            buttonCode == KEY_DOWN ||
            buttonCode == KEY_LEFT ||
            buttonCode == KEY_RIGHT ||
            (buttonCode >= 48 && buttonCode <= 57)
        ) {
            render(playground, x, y);
        }
    }

    system("pause");
    return 0;
}
