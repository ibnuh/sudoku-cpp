#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <iomanip>

using namespace std;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

void render(int playground[9][9], int x, int y, int newValue){
	system("cls");
	
	cout << endl << " -------------------------------------------------------" << endl;
	for(int row = 0; row < 9; row++){
		cout << " |  ";
		for(int column = 0; column < 9; column++){
			if(x == column && y == row){
				cout << setw(1) << playground[row][column] << "*" << setw(4);
				cout << "|  ";
			}
			else{
				cout << setw(1) << playground[row][column] << "  |  " << setw(2);
			}
		}
		cout << endl << " -------------------------------------------------------" << endl;
	}
}

int main(){
	
	int x, y = 0;
	int newVal = 10;
	
	int playground[9][9] = {
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
		{ 1, 2, 3, 4, 5, 6, 7, 8, 9 },
	};
	
	render(playground, x, y, newVal);
	
	while(true)
    {
        int buttonCode = 0;

        switch(buttonCode = getch()) {
	        case KEY_UP:
	        	if(y != 0) y--;
	            cout << endl << "Up" << endl;
	            break;
	        case KEY_DOWN:
	        	if(y != 8) y++;
	            cout << endl << "Down" << endl;
	            break;
	        case KEY_LEFT:
	        	if(x != 0) x--;
	            cout << endl << "Left" << endl;
	            break;
	        case KEY_RIGHT:
	        	if(x != 8) x++;
	            cout << endl << "Right" << endl;
	            break;
	        default:
	        	if(buttonCode >= 49 && buttonCode <= 57){
						playground[y][x] = char(buttonCode);
				}
	            break;
	        }
		
		render(playground, x, y, newVal);
		
		cout << "x: " << x;
		cout << "y: " << y;
    }
	
	system("pause");
	return 0;
}
