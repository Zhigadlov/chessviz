#include <stdio.h>
#include <malloc.h>

#define None ' '
#define PAWN 'P'
#define ROOK 'R'
#define KNIGHT 'N'
#define QUEEN 'Q'
#define KING 'K'
#define BISHOP 'B'

#define FigColorBlack 35
#define FigColorWhite 38	
	
#define KletColorWhite 45
#define KletColorBlack 48


typedef struct Fig
{
	int color;
	int type;	
} Fig;

typedef struct Klet
{
	Fig fig;
} Klet;

typedef struct Board
{
	Klet* klets;
} Board;

Board build_board();
void print_board(Board board);

int main()
{
	char a[10];
	Board board = build_board();
	print_board(board);
	scanf("%s", a);
	return 0;
}

void print_board(Board board)
{	
	int i;
	for (i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8;	j++)
		{
			printf("\x1b[%d;%dm%2c\x1b[0m", i % 2 == j % 2 ? KletColorBlack : KletColorWhite, board.klets[i * 8 + j].fig.color, board.klets[i * 8 + j].fig.type);
			
		}
		printf("\n");
	}
}
Board build_board()
{	
	int i;

	Klet* klets = malloc(sizeof(Klet) * 64);
	for (i = 2; i < 6; i++)
		{
		for (int j = 0; j < 8; j++)
			{
				Fig fig = {0, None};		
				klets[i * 8 + j].fig = fig;
			}
		}

	for (i = 0; i < 8; i++)
		klets[i + 48].fig.type = PAWN;

	for (i = 0; i < 8; i++)
		klets[i + 8].fig.type = PAWN;
	
	klets[56].fig.type = klets[63].fig.type = klets[0].fig.type = klets[7].fig.type = ROOK;
	klets[57].fig.type = klets[62].fig.type = klets[1].fig.type = klets[6].fig.type = KNIGHT;
	klets[58].fig.type = klets[61].fig.type = klets[2].fig.type = klets[5].fig.type = BISHOP;
	klets[59].fig.type = klets[4].fig.type = QUEEN;
	klets[60].fig.type = klets[3].fig.type = KING;
	
	for (i = 0; i < 64; i++)
		klets[i].fig.color = KletColorWhite;

	for (i = 48; i < 64; i++)
		klets[i].fig.color = KletColorBlack;
	
	Board b = {klets};
	return b;
}
	
void exit_game(){
	printf("\033[2J\033[1;1H");
}
