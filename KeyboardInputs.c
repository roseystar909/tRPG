#include <stdio.h>
#include <stdlib.h>
#include "header/Extra.h"
#include "header/Game.h"
#include "header/KeyboardInputs.h"
#include "header/TitleScreenMessages.h"
#include "header/Windows.h"

#define UP 72
#define DOWN 80
#define ENTER 13
#define ESC 27
#define CTENTER 10

// Gets your key presses
void selectOption(int currentOption) {
  const char *url;
  currentOption = 2;

  // Prints the cursor at y = 2 because of some bullshit I can't fix
  printl(72, currentOption, ">");

  do {
    char key = getch();  // it works?
    switch (key) {
    case ENTER:    // Does the action according to the option
      switch (currentOption) {
        case 2:
          return;
          break;
        case 3:
          openWebsite(url);
          break;
        case 5:
          clearTerminal();
          abort();
          break;
        default:
          break;
      }
      if (currentOption > 2) {
        printl(72, currentOption, " ");
        printl(72, currentOption++, ">");
      }
    break;
    case UP:       // Goes up
      if (currentOption > 2) {
        printl(72, currentOption, " ");
        printl(72, --currentOption, ">");

        updateOption(currentOption);
      }
    break;
    case DOWN:     // Goes down
      if (currentOption < 5) {
        printl(72, currentOption, " ");
        printl(72, ++currentOption, ">");

        updateOption(currentOption);
      }
    break;
    case CTENTER:  // Dev tool
      switch (currentOption) {
        case 2:
          clearBigWindow();
          clearSmallWindow();
          clearSmallerWindow();
          playerMovement();
          break;
        default:
          break;
      }
    break;
    case ESC:      // Exit program
      clearTerminal();
      abort();
    break;
    }
  } while(1);
}
