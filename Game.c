#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "header\Extra.h"
#include "header\Game.h"
#include "header\TitleScreenMessages.h"
#include "header\Windows.h"

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define ESC 27

#define MAPULIMIT 1
#define MAPDLIMIT 30
#define MAPLLIMIT 1
#define MAPRLIMIT 71

#define ENEMYx 34
#define ENEMYy 14

void startScreen() {
  clearBigWindow();
  clearSmallWindow();
  clearSmallerWindow();
  printl(2, 2, "Initiating MAP");
  printl(72, 2, "Initiating DIALOGBOX");
  printl(72, 18, "Initiating HEALTHBARS");
  delay(500);

  // MAP "Loading" screen
  printl(2, 3, "[          ]");

  for (int i = 3; i < 13; i++) {
    printl(i, 3, "█");
    delay(100);
  }
  printl(15, 3, "Done!");
  delay(250);

  // DIALOGBOX "Loading" screen
  printl(72, 3, "[          ]");

  for (int i = 73; i < 83; i++) {
    printl(i, 3, "█");
    delay(150);
  }
  printl(85, 3, "Done!");
  delay(250);

	// HEALTHBARS "Loading" screen
	printl(72, 19, "[          ]");

	for (int i = 73; i < 83; i++) {
		printl(i, 19, "█");
		delay(100);
	}
	printl(85, 19, "Done!");
	delay(2500);

	// actual "Loading" screen
	clearBigWindow();
	clearSmallWindow();
	clearSmallerWindow();
	printl(2, 2, "Initiating GAME");
	delay(500);

	printl(2, 3, "[          ]");

	for (int i = 3 ; i < 13; i++) {
		printl(i, 3, "█");
		delay(100);
	}
	printl(15, 3, "Done!");
	delay(2500);
	clearBigWindow();
}

void enemyMovement() {
	printl(ENEMYx, ENEMYy, "X");
}

void playerMovement() {
	int x = 34;
	int y = 24;
	int prevX = x;
	int prevY = y;
	int key;
	bool collided = false;

	enemyMovement();
	printl(x, y, "O");

	do {
		key = getch();

		switch(key) {
			case UP:
				prevY = y;
				--y;
				if (y == MAPULIMIT) {
					y++;
				}
				break;
			case DOWN:
				prevY = y;
				++y;
				if (y == MAPDLIMIT) {
          y--;
        }
        break;
      case LEFT:
        prevX = x;
        --x;
        if (x == MAPLLIMIT) {
          x++;
        }
        break;
      case RIGHT:
        prevX = x;
        ++x;
        if (x == MAPRLIMIT) {
          x--;
        }
        break;
      case ESC:
        return;
        break;
      default:
        break;
    }

    delay(10);
    clearBigWindow();

    if ((x == ENEMYx && y == ENEMYy) || (x == ENEMYx+1 || x == ENEMYx-1) || (y == ENEMYy+1 || y == ENEMYy-1)) {
      collided = true;
    } else {
      collided = false;
    }

    if (collided) {
      printl(2, 2, "WHAT");
    }

    enemyMovement();
    printl(x, y, "O");
  } while(1);
}
