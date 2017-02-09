
#define ARRAY_LENGTH(x)  (sizeof(x) / sizeof((x)[0]))

uint8_t prevButtonState = 0;
uint8_t currButtonState = 0;

void updateButtonState(Arduboy2 &a) {
	prevButtonState = currButtonState;
	currButtonState = a.buttonsState();
}

bool buttonPressed(uint8_t button) {
	return (!(prevButtonState & button) && (currButtonState & button));
}

bool isNewKeyPress() {
	return currButtonState && (currButtonState != prevButtonState);
}

void typeKey(int key) {
	Keyboard.press(key);
	delay(50);
	Keyboard.release(key);
}

int ceil(float num) {
	int i = (int) num;
	return (num == (float) i) ? i : i + 1;
}
