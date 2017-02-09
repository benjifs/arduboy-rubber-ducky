
#include "ducky.h"

#define FUNCTIONS ARRAY_LENGTH(ducky_fn)
#define LABELS ARRAY_LENGTH(ducky_fn_names)
#define PAGE_SIZE 6

uint8_t page = 0;
uint8_t pages = 1;

uint8_t pos = 0;
uint8_t selected = 0;

char arrow = '\020';

void checkSelections() {
	if (selected > 0 && selected <= FUNCTIONS) {
		(*ducky_fn[selected - 1])();
	}
	selected = 0;
}

void drawMenu(Arduboy2 &arduboy) {
	checkSelections();

	pages = ceil((1.0 * LABELS) / PAGE_SIZE);
	uint8_t items = min(LABELS - (page * PAGE_SIZE), PAGE_SIZE);

	uint8_t i = page * PAGE_SIZE, j;

	for (j = 0; j < items; j++) {
		arduboy.setCursor(10, (j * 8));
		arduboy.print(ducky_fn_names[i++]);
	}

	arduboy.drawLine(0, 54, 128, 54, WHITE);
	arduboy.drawLine(0, 53, 128, 53, BLACK);

	arduboy.setCursor(104, 56);
	arduboy.print(page + 1);
	arduboy.print(F("/"));
	arduboy.print(pages);

	arduboy.setCursor(0, (pos * 8));
	arduboy.print(arrow);

	if (isNewKeyPress()) {
		if (buttonPressed(LEFT_BUTTON) && page > 0) {
			page--;
			pos = 0;
		} else if (buttonPressed(RIGHT_BUTTON) && page < pages - 1) {
			page++;
			pos = 0;
		} else if (buttonPressed(UP_BUTTON) && pos > 0) {
			pos--;
		} else if (buttonPressed(DOWN_BUTTON) && pos < items - 1) {
			pos++;
		} else if (buttonPressed(A_BUTTON)) {
			arduboy.setCursor(0, 56);
			arduboy.print(F("Working..."));
			selected = (page * PAGE_SIZE) + pos + 1;
		}
	}
}
