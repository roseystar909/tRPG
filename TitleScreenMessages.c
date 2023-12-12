#include <stdio.h>
#include "header\TitleScreenMessages.h"
#include "header\Windows.h"

// Function 'printl' prints any text in any place
void printl(int x, int y, const char *string) {
  printf("\033[%d;%dH", y, x);
  printf("%s", string);
}

// Game title, should look like
/* _   ___ ___  ___
  | |_| _ \ _ \/ __|
  |  _|   /  _/ (_ |
   \__|_|_\_|  \___|
*/
void showTitle() {
  printl(25, 3, " _   ___ ___  ___ ");
  printl(25, 4, "| |_| _ \\ _ \\/ __|");
  printl(25, 5, "|  _|   /  _/ (_ |");
  printl(25, 6, " \\__|_|_\\_|  \\___|");
}

//Shows the Options
void showOptions() {
  printl(74, 2, "Start");
  printl(74, 3, "Credits");
  printl(74, 4, "Instructions");
  printl(74, 5, "Exit");

  printl(72, 26, "Press \"UP\" to go up or \"DOWN\" to go down");
  printl(72, 27, "Then press \"ENTER\" to select your option!");
  printl(72, 28, "\033[38;5;240mAlternatively, press ESC to exit the program");
  printl(72, 29, "anywhere\033[0m");
}

//Updates 'SmallerWindow' according to the selected Option
void updateOption(int currentOption) {
  clearSmallerWindow();

  switch (currentOption) {
    case 2: // Start
      printl(72, 18, "Press \033[1;32mENTER\033[0m to start the game!");
      break;
    case 3: // Credits
      printl(72, 18, "Game developed by \033[1;31mRoseyStar_\033[0m\n");
      printl(72, 28, "Go to my \033[38;5;55mGitHub\033[0m page for more info!\n");
      printl(72, 29, "\033[38;5;240mPress enter to open it\033[0m");
      break;
    case 4: // Instructions
      printl(72, 18, "Use the \033[1;32mArrow Keys\033[0m or \033[1;32mWASD\033[0m to move!");
      printl(72, 19, "Other things will be asked along the way");
      break;
    case 5: // Exit
      printl(72, 18, "\033[1;31mExit the program\033[0m");
      break;
  }
}
