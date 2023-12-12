#include <stdio.h>
#include <stdlib.h>
#include "header_\TitleScreenMessages.h"
#include "header_\Windows.h"

#define WINDOW_START 1
#define WINDOW_WIDTH 120
#define WINDOW_HEIGHT 30

#define SMALLWINDOW_START 71
#define SMALLERWINDOW_START 17

// Should be self-explanatory
void clearTerminal() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

// Should be self-explanatory
void clearSmallerWindow() {
  for (int i=18; i<30; i++) {
    printl(72, i, "                                                ");
  }
}

// Should be self-explanatory
void clearSmallWindow() {
  for (int i=2; i<17; i++) {
    printl(72, i, "                                                ");
  }
}

// Should be self-explanatory
void clearBigWindow() {
  for (int i=2; i<30; i++) {
    printl(2, i, "                                                                     ");
  }
}

// This will draw all the windows
void drawWindows() {
  clearTerminal();

  // Prints the top and bottom
  printl(WINDOW_START, WINDOW_START, "╔");
  for (int i=2; i<WINDOW_WIDTH; i++) {
    printl(i, WINDOW_START, "═");
  }
  printl(WINDOW_WIDTH, WINDOW_START, "╗");

  printl(WINDOW_START, WINDOW_HEIGHT, "╚");
  for (int i=2; i<WINDOW_WIDTH; i++) {
    printl(i, WINDOW_HEIGHT, "═");
  }
  printl(WINDOW_WIDTH, WINDOW_HEIGHT, "╝");

  // Prints the in-betweens
  for (int i=2; i<WINDOW_HEIGHT; i++){
    printl(WINDOW_START, i, "║");
    printl(WINDOW_WIDTH, i, "║");
  }

  // Prints 'SmallWindow' and 'SmallerWindow'
  printl(SMALLWINDOW_START, WINDOW_START, "╦");
  printl(SMALLWINDOW_START, WINDOW_HEIGHT, "╩");
  for (int i=2; i<WINDOW_HEIGHT; i++){
    printl(SMALLWINDOW_START, i, "║");
  }

  printl(SMALLWINDOW_START, SMALLERWINDOW_START, "╠");
  printl(WINDOW_WIDTH, SMALLERWINDOW_START, "╣");
  for (int i=72; i<WINDOW_WIDTH; i++){
    printl(i, SMALLERWINDOW_START, "═");
  }
}
