//Federico Baron
//10/12/18
//Connect four

#include<stdio.h>

//dimensions of board
#define ROWS 6
#define COLS 7
#define WINSIZE 4

//what can be stored in the board
#define BLANK 0
#define RED 1
#define BLACK 2

//possible directions for winning sets
const int DX[] = {1, 0, 1, 1};
const int DY[] = {0, 1, 1, -1};

void print(int board[][COLS]){

	int i, j;

	//print backwards
	for(i = ROWS - 1; i >= 0; i--)
}

int main(void){

	int board[ROWS][COLS];

}