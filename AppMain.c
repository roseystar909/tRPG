#include <stdio.h>
#include "header\Game.h"
#include "header\KeyboardInputs.h"
#include "header\TitleScreenMessages.h"
#include "header\Windows.h"

int main() {
  // Title screen
  drawWindows();
  showTitle();
  showOptions();
  selectOption(2);

  // Game
  startScreen();
  playerMovement();

  return 0;
}
