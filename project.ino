#include <Gamebuino-Meta.h>

// SETUP CODE = ONCE
void setup() {
  // put your setup code here, to run once:
  gb.begin();
}

// INFINITE LOOP
void loop() {
  // put your main code here, to run repeatedly:
  while(!gb.update());
  gb.display.clear();


  // C'est ici que le plus gros du programme se déroule
  gb.display.print("hello, world");
  drawPuyo(3, 3, 'r');
}

// FUNCTIONS
// SYSTEM
void setDisplayColor(char _color) {
  if (_color == 'b') {
    gb.display.setColor(BLUE);
  }
  else if (_color == 'r') {
    gb.display.setColor(RED);
  }
  else if (_color == 'g') {
    gb.display.setColor(GREEN);
  }
  else if (_color == 'y') {
    gb.display.setColor(YELLOW);
  }
  else if (_color == 'w') {
    gb.display.setColor(WHITE);
  }
  else {
    gb.display.setColor(PURPLE);
  }
}
// PUYO
void drawPuyo(int _x, int _y, char _color) {
  setDisplayColor(_color);
  gb.display.fillRect(_x+1, _y, 8, 10);
  gb.display.fillRect(_x, _y+1, 10, 8);
}
