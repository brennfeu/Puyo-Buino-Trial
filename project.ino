#include <Gamebuino-Meta.h>
#include <time.h>

int i = 0;
int j = 0;

int timerFrame = 0;
int timerSecond = 0;
bool gameOver = false;
char colorList[4] = {'r', 'g', 'b', 'y'};

char puyo01 = 'w';
char puyo02 = 'w';
char puyo11 = 'w';
char puyo12 = 'w';
char puyo21 = 'w';
char puyo22 = 'w';

int currentPuyoX = 0;
int currentPuyoY = 0;
int currentPuyoOrientation = 0;

char board[12][6] = {
    {'e', 'e', 'x', 'x', 'e', 'e'}, 
    {'e', 'e', 'e', 'e', 'e', 'e'},
    {'e', 'e', 'e', 'e', 'e', 'e'}, 
    {'e', 'e', 'e', 'e', 'e', 'e'}, 
    {'e', 'e', 'e', 'e', 'e', 'e'}, 
    {'e', 'e', 'e', 'e', 'e', 'e'}, 
    {'e', 'e', 'e', 'e', 'e', 'e'}, 
    {'e', 'e', 'e', 'e', 'e', 'e'}, 
    {'e', 'e', 'e', 'e', 'e', 'e'}, 
    {'e', 'e', 'e', 'e', 'e', 'e'}, 
    {'e', 'e', 'e', 'e', 'e', 'e'}, 
    {'e', 'e', 'e', 'e', 'e', 'e'},
};

// SETUP CODE = ONCE
void setup() {
  // put your setup code here, to run once:
  gb.begin();

  srand(time(NULL));
  resetGame();
}

// INFINITE LOOP
void loop() {
  // put your main code here, to run repeatedly:
  while(!gb.update());
  gb.display.clear();

  if (!gameOver) {
    // TIMER
    incrementTimer();
    currentPuyoMove();
    
    // UI
    drawUI();
    drawBoard();
    drawNextPuyos();
  
    // TESTS
    drawText("POP", "10", "PUYOS");
  }
  else {
    gb.display.setCursor(10, 10);
    gb.display.print("GAME OVER\n\nPRESS A\nTO RESTART !");
    if (gb.buttons.pressed(BUTTON_A)) {
      resetGame();
    }
  }
}

// FUNCTIONS
// SYSTEM
void resetGame() {
  // variables reset
  timerSecond = 5;
  timerFrame = 0;
  gameOver = false;
  currentPuyoX = 10;
  currentPuyoY = 0;

  // board
  for (i = 0; i<12; i++) {
    for (j = 0; j<6; j++) {
      board[i][j] = 'e';
    }
  }
  board[0][2] = 'x';
  board[0][3] = 'x';

  // puyos
  puyo01 = getRandomColor();
  puyo02 = getRandomColor();
  puyo11 = getRandomColor();
  puyo12 = getRandomColor();
  puyo21 = getRandomColor();
  puyo22 = getRandomColor();
}
void setDisplayColor(char _color) {
  if (_color == 'b') {
    gb.display.setColor(BLUE);
  }
  else if (_color == 'r') {
    gb.display.setColor(RED);
  }
  else if (_color == 'g') {
    gb.display.setColor(LIGHTGREEN);
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
void incrementTimer() {
  timerFrame++;
  if (timerFrame > 30) {
    timerSecond--;
    timerFrame -= 30;
  }
  if (timerSecond <= 0) {
    gameOver = true;
  }
}
char getRandomColor() {
  return colorList[rand() % 4];
}
void currentPuyoMove() {
  if (gb.buttons.repeat(BUTTON_DOWN, 0)) {
    currentPuyoY += 4;
  }
  else if(timerFrame%10 == 0) {
    currentPuyoY++;
  }
  if (gb.buttons.repeat(BUTTON_RIGHT, 5) && currentPuyoX < 25) {
    currentPuyoX += 5;
  }
  if (gb.buttons.repeat(BUTTON_LEFT, 5) && currentPuyoX > 0) {
    currentPuyoX -= 5;
  }
  
  if (gb.buttons.pressed(BUTTON_B)) {
    currentPuyoOrientation++;
  }
  if (gb.buttons.pressed(BUTTON_A)) {
    currentPuyoOrientation--;
  }
  
  if(currentPuyoOrientation >= 4) {
    currentPuyoOrientation -= 4;
  }
  if (currentPuyoOrientation <= -1) {
    currentPuyoOrientation += 4;
  }

  if (currentPuyoOrientation == 3 && currentPuyoX <= 0) {
    currentPuyoX += 5;
  }
  if (currentPuyoOrientation == 1 && currentPuyoX >= 25) {
    currentPuyoX -= 5;
  }
}

// DRAW
void drawUI() {
  setDisplayColor('w');
  
  // timer
  gb.display.setCursor(51, 51);
  gb.display.printf("%is", timerSecond);
  
  // main board
  gb.display.drawRect(1, 1, 32, 62);

  // next puyos
  gb.display.drawRect(35, 3, 7, 12);
  gb.display.drawRect(37, 17, 7, 12);

  // titre
  gb.display.setCursor(48, 3);
  gb.display.print("Puyo");
  gb.display.setCursor(53, 10);
  gb.display.print("Buino");
}
void drawBoard() {
  for (i = 0; i<12; i++) {
    for (j = 0; j<6; j++) {
      if (board[i][j] == 'e') {
        // drawPuyo(j*5+2, i*5+2, 'p');
      }
      else if (board[i][j] == 'x') {
        drawCross(j*5+2, i*5+2);
      }
      else {
        drawPuyo(j*5+2, i*5+2, board[i][j]);
      }
    }
  }
}
void drawNextPuyos() {
  drawPuyo(36, 4, puyo11);
  drawPuyo(36, 9, puyo12);
  drawPuyo(38, 18, puyo21);
  drawPuyo(38, 23, puyo22);
  drawPuyo(currentPuyoX+2, currentPuyoY+2, puyo01);
  if (currentPuyoOrientation == 0) {
    drawPuyo(currentPuyoX+2, currentPuyoY-3, puyo02);
  }
  else if (currentPuyoOrientation == 1) {
    drawPuyo(currentPuyoX+7, currentPuyoY+2, puyo02);
  }
  else if (currentPuyoOrientation == 2) {
    drawPuyo(currentPuyoX+2, currentPuyoY+7, puyo02);
  }
  else if (currentPuyoOrientation == 3) {
    drawPuyo(currentPuyoX-3, currentPuyoY+2, puyo02);
  }
}
void drawText(String _string1, String _string2, String _string3) {
  setDisplayColor('w');
  gb.display.setCursor(56, 26);
  gb.display.print(_string1);
  gb.display.setCursor(59, 33);
  gb.display.print(_string2);
  gb.display.setCursor(53, 41);
  gb.display.print(_string3);
}
void drawPuyo(int _x, int _y, char _color) {
  setDisplayColor(_color);
  gb.display.fillRect(_x+1, _y, 3, 5);
  gb.display.fillRect(_x, _y+1, 5, 3);
}
void drawCross(int _x, int _y) {
  setDisplayColor('r');
  gb.display.drawLine(_x, _y, _x+4, _y+4);
  gb.display.drawLine(_x+4, _y, _x, _y+4);
}
