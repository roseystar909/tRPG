#include <stdio.h>
#include "header_\Game.h"
#include "header_\KeyboardInputs.h"
#include "header_\TitleScreenMessages.h"
#include "header_\Windows.h"

int main() {
  // Title screen
  drawWindows();
  showTitle();
  showOptions();
  selectOption(2);

  // Game
  startScreen();
  playerMovement();

<<<<<<< HEAD:appmain.c
  return 0;
=======
	return 0;
>>>>>>> 209e0ce403110f09880bfcd87bfa8bd5d2daaa60:AppMain.c
}
