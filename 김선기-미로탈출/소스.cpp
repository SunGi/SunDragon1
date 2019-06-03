#include <stdio.h>
#include <conio.h>
#include <Windows.h>
int Maze[40][40] = {
	//1:벽
	//0:길
	//2.출발점
	//3:도착점
	{4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4},
	{1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,1,0,1,1,1,1,0,0,0,0,0,0,1,1,1,1,1,1,1},
	{1,1,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,1,1,1},
	{1,1,1,1,1,1,0,1,1,1,1,1,0,0,0,1,1,1,1,1},
	{1,1,1,1,1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1},
	{1,0,1,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,1},
	{1,0,0,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,1},
	{1,1,0,1,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,1},
	{1,1,0,0,1,1,1,1,0,1,1,1,1,1,0,1,1,1,1,1},
	{1,1,1,0,0,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1},
	{1,1,1,0,1,1,1,1,1,0,1,1,1,1,1,1,0,1,1,1},
	{1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,1,1,1,0,1,1,1,1,1,1,1,0,0,0,1,1,0,1,1},
	{1,1,1,1,0,1,1,1,1,1,1,1,1,0,0,1,1,0,1,1},
	{1,1,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,0,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1},
	{1,1,0,0,0,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1},
	{1,1,0,1,1,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1},
	{1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};
int Maze2[40][40] = {
    {1,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,0,0,0,0,1,0,0,0,0,0,0,0,1,1,0,0,0,1},
    {1,0,1,1,1,0,1,0,0,0,1,0,0,1,1,0,0,0,0,1},
    {1,0,1,1,0,0,0,0,1,0,1,1,0,0,0,0,0,0,0,1},
    {1,0,1,0,0,1,1,0,1,0,1,0,0,1,1,0,1,1,1,1},
    {1,0,0,0,1,1,1,0,1,1,0,0,0,1,1,0,0,0,0,1},
    {1,1,1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,0,0,1},
    {1,0,0,1,0,0,0,1,0,1,0,1,0,0,0,1,1,1,0,1},
    {1,0,1,1,1,1,0,1,1,0,0,1,0,0,1,0,1,0,0,1},
    {1,0,0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,0,1},
    {1,0,1,1,0,1,1,0,0,0,0,0,0,0,1,0,1,1,0,1},
    {1,1,1,0,0,1,1,0,1,1,0,1,1,1,1,1,1,0,0,1},
    {1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,1,0,0,1},
    {1,1,1,1,0,1,0,0,1,0,1,0,0,0,1,0,0,0,1,1},
    {1,0,0,1,0,1,1,0,1,0,1,1,0,1,1,0,1,1,0,1},
    {1,0,0,0,0,1,0,0,0,0,1,1,0,1,0,0,1,0,1,1},
    {1,0,1,1,1,0,0,1,0,0,0,1,0,0,0,1,1,0,0,1},
    {1,0,0,1,0,0,1,0,0,1,0,0,1,1,0,1,0,1,1,1},
    {1,1,0,1,0,1,0,0,1,0,0,0,1,1,0,0,0,1,0,1},
    {1,1,1,0,1,1,1,0,0,0,0,0,0,0,1,1,0,0,1,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,1},
};
char star = 0;
int x = 2, y = 1;
void start();
void pic(int Maze[][40], int num);
void move(int Maze[][40], int num);
void pic2(int Maze2[][40], int num);
void move2(int Maze2[][40], int num);
void finish();
int main() {
	start();
	pic(Maze, 21);
	move(Maze, 20);
	system("cls");
	pic2(Maze2, 21);
	move2(Maze2, 20);
	finish();
}
void start() {
	char n;
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("        $$$$$$$$$$$$$      $$$$$$$$$$$$$$$$    $$$$$$$$$$$$$$$    $$$$$$$$$$$$$$$$$   $$$$$$$$$$$$$$$$             \n");
	printf("        $$$$$$$$$$$$$      $$$$$$$$$$$$$$$$    $$$$$$$$$$$$$$$    $$$$$$$$$$$$$$$$$   $$$$$$$$$$$$$$$$             \n");
	printf("        $$$                      $$$$          $$$         $$$    $$$           $$$         $$$$                   \n");
	printf("        $$$$$$$$$$$$$            $$$$          $$$         $$$    $$$$$$$$$$$$$$$$$         $$$$                   \n");
	printf("        $$$$$$$$$$$$$            $$$$          $$$$$$$$$$$$$$$    $$$          $$$          $$$$                   \n");
	printf("                  $$$            $$$$          $$$         $$$    $$$           $$$         $$$$                   \n");
	printf("        $$$$$$$$$$$$$            $$$$          $$$         $$$    $$$             $$$       $$$$                   \n");
	printf("        $$$$$$$$$$$$$            $$$$          $$$         $$$    $$$              $$$      $$$$                   \n");
	printf("                                                                                                                 \n");
	printf("                                                                                                                       \n");
	printf("                                                                                                                       \n");
	printf("                                        스페이스바 누르면 시작합니다.\n");
	while (1) {
		n = getch();
		if (n == ' ') {
			system("cls");
			break;
		}
		else
			printf("다시 입력해주세요\n");
	}
}
void gotoxy(int x, int y)

{

	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
void pic(int Maze[][40], int num) {
	for (int i = 0; i <= num; i++) {
		for (int j = 0; j <= 20; j++) {
			if (Maze[i][j] == 0) {
				printf("  "); Sleep(1);
			}
			else if (Maze[i][j] == 1) {
				printf("□"); Sleep(1);
			}
			else if (Maze[i][j] == 4)
				printf("■"); Sleep(1);
		}
		printf("\n");
	}
}
void move(int Maze[][40], int num) {
	while (x != 2 || y != 21) {
		gotoxy(40, 5);
		printf("%d       %d       ", x, y);
		gotoxy(x * 2, y);
		printf("★");
		star = _getch();
		switch (star) {
		case 'w':
			if (Maze[y - 1][x] != 0)
				break;
			else
				gotoxy(x * 2, y);
			printf(" ");
			y--;
			break;
		case 'a':
			if (Maze[y][x - 1] != 0)
				break;
			else
				gotoxy(x * 2, y);
			printf(" ");
			x--;
			break;
		case 's':
			if (Maze[y + 1][x] != 0)
				break;
			else
				gotoxy(x * 2, y);
			printf(" ");
			y++;
			break;
		case 'd':
			if (Maze[y][x + 1] != 0)
				break;
			else
				gotoxy(x * 2, y);
			printf(" ");
			x++;
			break;
		}
	}
}
void pic2(int Maze2[][40], int num) {
	for (int i = 0; i <= num; i++) {
		for (int j = 0; j <= 20; j++) {
			if (Maze2[i][j] == 0) {
				printf("  "); Sleep(1);
			}
			else if (Maze2[i][j] == 1) {
				printf("□"); Sleep(1);
			}
		}
		printf("\n");
	}
}
void move2(int Maze2[][40], int num) {
	x = 2, y = 0;
	while (x != 17 || y != 20) {
		gotoxy(40, 5);
		printf("%d       %d       ", x, y);
		gotoxy(x * 2, y);
		printf("★");
		star = _getch();
		switch (star) {
		case 'w':
			if (Maze2[y - 1][x] != 0)
				break;
			else
				gotoxy(x * 2, y);
			printf(" ");
			y--;
			break;
		case 'a':
			if (Maze2[y][x - 1] != 0)
				break;
			else
				gotoxy(x * 2, y);
			printf(" ");
			x--;
			break;
		case 's':
			if (Maze2[y + 1][x] != 0)
				break;
			else
				gotoxy(x * 2, y);
			printf(" ");
			y++;
			break;
		case 'd':
			if (Maze2[y][x + 1] != 0)
				break;
			else
				gotoxy(x * 2, y);
			printf(" ");
			x++;
			break;
		}
	}
}
void finish() {
	system("cls");
	printf("EEEEEEEEEEEEEEEEEEEEEE     NNNNNNNN        NNNNNNNN     DDDDDDDDDDDDD              !!! \n"); Sleep(25);
	printf("E::::::::::::::::::::E     N:::::::N       N::::::N     D::::::::::::DDD          !!:!!\n"); Sleep(25);
	printf("E::::::::::::::::::::E     N::::::::N      N::::::N     D:::::::::::::::DD        !:::!\n"); Sleep(25);
	printf("EE::::::EEEEEEEEE::::E     N:::::::::N     N::::::N     DDD:::::DDDDD:::::D       !:::!\n"); Sleep(25);
	printf("  E:::::E       EEEEEE     N::::::::::N    N::::::N       D:::::D    D:::::D      !:::!\n"); Sleep(25);
	printf("  E:::::E                  N:::::::::::N   N::::::N       D:::::D     D:::::D     !:::!\n"); Sleep(25);
	printf("  E::::::EEEEEEEEEE        N:::::::N::::N  N::::::N       D:::::D     D:::::D     !:::!\n"); Sleep(25);
	printf("  E:::::::::::::::E        N::::::N N::::N N::::::N       D:::::D     D:::::D     !:::!\n"); Sleep(25);
	printf("  E:::::::::::::::E        N::::::N  N::::N:::::::N       D:::::D     D:::::D     !:::!\n"); Sleep(25);
	printf("  E::::::EEEEEEEEEE        N::::::N   N:::::::::::N       D:::::D     D:::::D     !:::!\n"); Sleep(25);
	printf("  E:::::E                  N::::::N    N::::::::::N       D:::::D     D:::::D     !!:!!\n"); Sleep(25);
	printf("  E:::::E       EEEEEE     N::::::N     N:::::::::N       D:::::D    D:::::D       !!! \n"); Sleep(25);
	printf("EE::::::EEEEEEEE:::::E     N::::::N      N::::::::N     DDD:::::DDDDD:::::D            \n"); Sleep(25);
	printf("E::::::::::::::::::::E     N::::::N       N:::::::N     D:::::::::::::::DD         !!! \n"); Sleep(25);
	printf("E::::::::::::::::::::E     N::::::N        N::::::N     D::::::::::::DDD          !!:!!\n"); Sleep(25);
	printf("EEEEEEEEEEEEEEEEEEEEEE     NNNNNNNN         NNNNNNN     DDDDDDDDDDDDD              !!! \n"); Sleep(25);
}




                  
                  
                  
           		
					
                  
					
					
                  
                  
					
					
					
					
					
					
							  
		                 
