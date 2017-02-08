
void osx_hello_world() {
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  delay(1000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press(' ');
  Keyboard.releaseAll();

  delay(250);

  Keyboard.print("terminal");

  delay(1000);

  typeKey(KEY_RETURN);

  delay(250);

  Keyboard.print("echo \"hello word\"");

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

void win_hello_world() {
  // Begining the Keyboard stream
  Keyboard.begin();

  // Wait 500ms
  delay(500);

  delay(3000);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  delay(500);

  Keyboard.print("notepad");

  delay(500);

  typeKey(KEY_RETURN);

  delay(750);

  Keyboard.print("Hello World!!!");

  typeKey(KEY_RETURN);

  // Ending stream
  Keyboard.end();
}

void (*ducky_fn[]) (void) = {
  osx_hello_world,
  win_hello_world,
};

const char *ducky_fn_names[] = {
  "OSX - Hello World",
  "Win - Hello World",
};
