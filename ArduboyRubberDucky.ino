/*
 * Arduboy Rubber Ducky
 *
 * Benji Encalada
 * @benjifs
 */

#include "Arduboy2.h"
#include "Keyboard.h"

#include "bitmaps.h"
#include "helpers.h"
#include "menu.h"

uint8_t sequence[] = {
	UP_BUTTON, UP_BUTTON,
	DOWN_BUTTON, DOWN_BUTTON,
	LEFT_BUTTON, RIGHT_BUTTON,
	LEFT_BUTTON, RIGHT_BUTTON,
	B_BUTTON, A_BUTTON
};
uint8_t next_key = 0;
bool konami = true;

Arduboy2 arduboy;

void setup() {
	arduboy.begin();

	arduboy.setFrameRate(30);
}

void loop() {
  if (!(arduboy.nextFrame())) return;

  updateButtonState(arduboy);

  arduboy.clear();

  if (konami && next_key != ARRAY_LENGTH(sequence)) {
    arduboy.drawBitmap(0, 8, ducky, 128, 48, WHITE);

    if (isNewKeyPress()) {
      next_key = buttonPressed(sequence[next_key]) ? next_key + 1 : 0;
    }
  } else {
    drawMenu(arduboy);
  }

  arduboy.display();
}
