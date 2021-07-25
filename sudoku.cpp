#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void render(int playground[9][9], int x, int y){
	system("cls");
	
	cout << "   _____           _       _          " << endl;
	cout << "  / ____|         | |     | |         " << endl;
	cout << " | (___  _   _  __| | ___ | | ___   _ " << endl;
	cout << "  \\___ \\| | | |/ _` |/ _ \\| |/ / | | |" << endl;
	cout << "  ____) | |_| | (_| | (_) |   <| |_| | by M. IBNU LUTHFI AZHAR " << endl;
	cout << " |_____/ \\__,_|\\__,_|\\___/|_|\\_\\\\__,_| 200401067" << endl;
	
	cout << endl << " /-----------------/-----------------/-----------------/" << endl;
	for(int row = 0; row < 9; row++){
		cout << " |  ";
		for(int column = 0; column < 9; column++){
			int currentNumber = playground[row][column];
			
			if (currentNumber == 0){
				if (x == column && y == row){
					cout << "_  |  ";
				}
				else {
					cout << "   |  ";
				}
			}
			else {
				if (x == column && y == row){
					cout << setw(1) << currentNumber << "*" << setw(4);
					cout << "|  ";
				}
				else{
					cout << setw(1) << currentNumber << "  |  " << setw(2);
				}
			}
		}
		
		if((row + 1) % 3 == 0){
			cout << endl << " /-----------------/-----------------/-----------------/" << endl;
		}
		else{
			cout << endl << " -------------------------------------------------------" << endl;
		}
	}
}

int main(){
	
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
	
	render(playground, x, y);
	
	while(true)
    {
        int buttonCode = 0;

        switch(buttonCode = getch()) {
	        case KEY_UP:
	        	if(y != 0) y--;
	            break;
	        case KEY_DOWN:
	        	if(y != 8) y++;
	            break;
	        case KEY_LEFT:
	        	if(x != 0) x--;
	            break;
	        case KEY_RIGHT:
	        	if(x != 8) x++;
	            break;
	        default:
	        	if(buttonCode >= 48 && buttonCode <= 57){
						playground[y][x] = buttonCode - '0'; // Convert ascii number to a real character
				}
	            break;
	        }
		
		render(playground, x, y);
    }
	
	system("pause");
	return 0;
}
