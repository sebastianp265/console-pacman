﻿#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define EMPTY 0
#define WALL 1
#define COIN 2
#define PLAYER_START 3
#define ENEMY_START 4

#define MAP_WIDTH 21
#define MAP_HEIGHT 21

int map[MAP_HEIGHT][MAP_WIDTH] = {
	//       0        1        2        3        4        5        6        7        8        9            10             11            12       13       14       15       16       17       18       19       20
	/*0 */{EMPTY,   WALL,    WALL,    WALL,    WALL,    WALL,    WALL,    WALL,    WALL,    WALL,         WALL,          WALL,         WALL,    WALL,    WALL,    WALL,    WALL,    WALL,    WALL,    WALL,    EMPTY},/*0 */
	/*1 */{EMPTY,   WALL,    COIN,    COIN,    COIN,    COIN,    COIN,    COIN,    COIN,    COIN,         WALL,          COIN,         COIN,    COIN,    COIN,    COIN,    COIN,    COIN,    COIN,    WALL,    EMPTY},/*1 */
	/*2 */{EMPTY,   WALL,    COIN,    WALL,    WALL,    COIN,    WALL,    WALL,    WALL,    COIN,         WALL,          COIN,         WALL,    WALL,    WALL,    COIN,    WALL,    WALL,    COIN,    WALL,    EMPTY},/*2 */
	/*3 */{EMPTY,   WALL,    COIN,    COIN,    COIN,    COIN,    COIN,    COIN,    COIN,    COIN,         COIN,          COIN,         COIN,    COIN,    COIN,    COIN,    COIN,    COIN,    COIN,    WALL,    EMPTY},/*3 */
	/*4 */{EMPTY,   WALL,    COIN,    WALL,    WALL,    COIN,    WALL,    COIN,    WALL,    WALL,         WALL,          WALL,         WALL,    COIN,    WALL,    COIN,    WALL,    WALL,    COIN,    WALL,    EMPTY},/*4 */
	/*5 */{EMPTY,   WALL,    COIN,    COIN,    COIN,    COIN,    WALL,    COIN,    COIN,    COIN,         WALL,          COIN,         COIN,    COIN,    WALL,    COIN,    COIN,    COIN,    COIN,    WALL,    EMPTY},/*5 */
	/*6 */{EMPTY,   WALL,    WALL,    WALL,    WALL,    COIN,    WALL,    WALL,    WALL,    EMPTY,        WALL,          EMPTY,        WALL,    WALL,    WALL,    COIN,    WALL,    WALL,    WALL,    WALL,    EMPTY},/*6 */
	/*7 */{EMPTY,   EMPTY,   EMPTY,   EMPTY,   WALL,    COIN,    WALL,    EMPTY,   EMPTY,   EMPTY,        EMPTY,         EMPTY,        EMPTY,   EMPTY,   WALL,    COIN,    WALL,    EMPTY,   EMPTY,   EMPTY,   EMPTY},/*7 */
	/*8 */{WALL,    WALL,    WALL,    WALL,    WALL,    COIN,    WALL,    EMPTY,   WALL,    WALL,         EMPTY,         WALL,         WALL,    EMPTY,   WALL,    COIN,    WALL,    WALL,    WALL,    WALL,    WALL},/*8 */
	/*9 */{EMPTY,   EMPTY,   EMPTY,   EMPTY,   EMPTY,   COIN,    EMPTY,   EMPTY,   WALL,    ENEMY_START,  ENEMY_START,   ENEMY_START,  WALL,    EMPTY,   COIN,    COIN,    EMPTY,   EMPTY,   EMPTY,   EMPTY,   EMPTY},/*9 */
	/*10*/{WALL,    WALL,    WALL,    WALL,    WALL,    COIN,    WALL,    EMPTY,   WALL,    WALL,         WALL,          WALL,         WALL,    EMPTY,   WALL,    COIN,    WALL,    WALL,    WALL,    WALL,    WALL},/*10*/
	/*11*/{EMPTY,   EMPTY,   EMPTY,   EMPTY,   WALL,    COIN,    WALL,    EMPTY,   EMPTY,   EMPTY,        EMPTY,         EMPTY,        EMPTY,   EMPTY,   WALL,    COIN,    WALL,    EMPTY,   EMPTY,   EMPTY,   EMPTY},/*11*/
	/*12*/{EMPTY,   WALL,    WALL,    WALL,    WALL,    COIN,    WALL,    EMPTY,   WALL,    WALL,         WALL,          WALL,         WALL,    EMPTY,   WALL,    COIN,    WALL,    WALL,    WALL,    WALL,    EMPTY},/*12*/
	/*13*/{EMPTY,   WALL,    COIN,    COIN,    COIN,    COIN,    COIN,    COIN,    COIN,    COIN,         WALL,          COIN,         COIN,    COIN,    COIN,    COIN,    COIN,    COIN,    COIN,    WALL,    EMPTY},/*13*/
	/*14*/{EMPTY,   WALL,    COIN,    WALL,    WALL,    COIN,    WALL,    WALL,    WALL,    COIN,         WALL,          COIN,         WALL,    WALL,    WALL,    COIN,    WALL,    WALL,    COIN,    WALL,    EMPTY},/*14*/
	/*15*/{EMPTY,   WALL,    COIN,    COIN,    WALL,    COIN,    COIN,    COIN,    COIN,    COIN,         PLAYER_START,  COIN,         COIN,    COIN,    COIN,    COIN,    WALL,    COIN,    COIN,    WALL,    EMPTY},/*15*/
	/*16*/{EMPTY,   WALL,    WALL,    COIN,    WALL,    COIN,    WALL,    COIN,    WALL,    WALL,         WALL,          WALL,         WALL,    COIN,    WALL,    COIN,    WALL,    COIN,    WALL,    WALL,    EMPTY},/*16*/
	/*17*/{EMPTY,   WALL,    COIN,    COIN,    COIN,    COIN,    WALL,    COIN,    COIN,    COIN,         WALL,          COIN,         COIN,    COIN,    WALL,    COIN,    COIN,    COIN,    COIN,    WALL,    EMPTY},/*17*/
	/*18*/{EMPTY,   WALL,    COIN,    WALL,    WALL,    WALL,    WALL,    WALL,    WALL,    COIN,         WALL,          COIN,         WALL,    WALL,    WALL,    WALL,    WALL,    WALL,    COIN,    WALL,    EMPTY},/*18*/
	/*19*/{EMPTY,   WALL,    COIN,    COIN,    COIN,    COIN,    COIN,    COIN,    COIN,    COIN,         COIN,          COIN,         COIN,    COIN,    COIN,    COIN,    COIN,    COIN,    COIN,    WALL,    EMPTY},/*19*/
	/*20*/{EMPTY,   WALL,    WALL,    WALL,    WALL,    WALL,    WALL,    WALL,    WALL,    WALL,         WALL,          WALL,         WALL,    WALL,    WALL,    WALL,    WALL,    WALL,    WALL,    WALL,    EMPTY} /*20*/
};


// ANSI escape color codes
// https://en.wikipedia.org/wiki/ANSI_escape_code#Colors
// Template: "\033[{color_code_here}m"
#define BG_BLACK "\033[40m"
#define BG_RED "\033[41m"
#define BG_GREEN "\033[42m"
#define BG_YELLOW "\033[43m"
#define BG_BLUE "\033[44m"
#define BG_MAGENTA "\033[45m"
#define BG_CYAN "\033[46m"
#define BG_WHITE "\033[47m"
#define BG_CLEAR "\033[0m"

void set_cursor_to_left_top_corner() {
	COORD cursorPosition;
	cursorPosition.X = 0;
	cursorPosition.Y = 0;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), cursorPosition);
}

int player_pos_x;
int player_pos_y;

int player_velocity_x = 0;
int player_velocity_y = 0;

void print_map() {
	set_cursor_to_left_top_corner();

    for (int y = 0; y < MAP_HEIGHT; y++) {
        for (int x = 0; x < MAP_WIDTH; x++) {
			if (player_pos_y == y && player_pos_x == x) {
				cout << BG_YELLOW << "  ";
			}
            else if (map[y][x] == EMPTY) {
                cout << BG_CLEAR << "  ";
            }
            else if (map[y][x] == WALL) {
                cout << BG_BLUE << "  ";
			}
			else {
				cout << BG_CLEAR << "  ";
			}
        }

        cout << endl;
    }

    cout << BG_CLEAR;
}

void init_player_position() {
	int player_count = 0;

	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			if (map[y][x] == PLAYER_START) {
				player_count++;
				player_pos_y = y;
				player_pos_x = x;
				map[y][x] = EMPTY;
			}
		}
	}

	if (player_count != 1) {
		cout << BG_RED << "ERROR: There has to be only one player on the map!" << endl;
		exit(1);
	}
}

void handle_key_input() {
	if (_kbhit()) {
		char key_pressed = _getch();

		if (key_pressed == 'w') {
			player_velocity_y = -1;
			player_velocity_x = 0;
		}
		else if (key_pressed == 's') {
			player_velocity_y = 1;
			player_velocity_x = 0;
		}
		else if (key_pressed == 'a') {
			player_velocity_x = -1;
			player_velocity_y = 0;
		}
		else if (key_pressed == 'd') {
			player_velocity_x = 1;
			player_velocity_y = 0;
		}
		else if (key_pressed == ' ') {
			exit(0);
		}

		cout << "Pressed key: " << key_pressed;
	}
}

void hide_cursor() {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(hConsole, &cursorInfo);
	cursorInfo.bVisible = false;
	SetConsoleCursorInfo(hConsole, &cursorInfo);
}

void update_game() {
	player_pos_x += player_velocity_x;
	player_pos_y += player_velocity_y;
}

int main()
{
	hide_cursor();
	init_player_position();
	
	while (true) {
		handle_key_input();
		update_game();
		print_map();
		Sleep(100);
	}
}