#include <Gamebuino-Meta.h>
#include <time.h>

//RED_STAND
const uint16_t RED_STAND_DATA[] = {
  5, 5, // largeur, hauteur
  1, // images
  0, // boucle image
  0xa254, // couleur transparente
  0, // mode couleur

  0xa254, 0xe8e4, 0xe8e4, 0xe8e4, 0xa254,
  0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4,
  0xe8e4, 0x0000, 0x8802, 0x0000, 0xe8e4,
  0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4,
  0xa254, 0xe8e4, 0xe8e4, 0xe8e4, 0xa254,
};
Image RED_STAND(RED_STAND_DATA);


//BLUE_STAND
const uint16_t BLUE_STAND_DATA[] = {
  5, 5, // largeur, hauteur
  1, // images
  0, // boucle image
  0xa254, // couleur transparente
  0, // mode couleur

  0xa254, 0x051d, 0x051d, 0x051d, 0xa254,
    0x051d, 0xffff, 0x051d, 0xffff, 0x051d,
    0x051d, 0x0000, 0x051d, 0x0000, 0x051d,
    0x051d, 0x051d, 0x051d, 0x051d, 0x051d,
    0xa254, 0x051d, 0x051d, 0x051d, 0xa254,
};
Image BLUE_STAND(BLUE_STAND_DATA);


//GREEN_STAND
const uint16_t GREEN_STAND_DATA[] = {
  5, 5, // largeur, hauteur
  1, // images
  0, // boucle image
  0xa254, // couleur transparente
  0, // mode couleur

  0xa254, 0x2589, 0x2589, 0x2589, 0xa254,
    0xb723, 0xffff, 0x2589, 0xffff, 0xb723,
    0xffff, 0xb723, 0x2589, 0xb723, 0xffff,
    0x2589, 0x2589, 0x2589, 0x2589, 0x2589,
    0xa254, 0x2589, 0x2589, 0x2589, 0xa254,
};
Image GREEN_STAND(GREEN_STAND_DATA);


//YELLOW_STAND
const uint16_t YELLOW_STAND_DATA[] = {
  5, 5, // largeur, hauteur
  1, // images
  0, // boucle image
  0xa254, // couleur transparente
  0, // mode couleur

  0xa254, 0xff80, 0xff80, 0xff80, 0xa254,
    0xff80, 0xff80, 0xff80, 0xff80, 0xff80,
    0xfbe4, 0xfbe4, 0xff80, 0xfbe4, 0xfbe4,
    0xff80, 0xff80, 0xff80, 0xff80, 0xff80,
    0xa254, 0xff80, 0xff80, 0xff80, 0xa254,
};
Image YELLOW_STAND(YELLOW_STAND_DATA);


//RED_BLINK
const uint16_t RED_BLINK_DATA[] = {
  5, 5, // largeur, hauteur
  1, // images
  0, // boucle image
  0xa254, // couleur transparente
  0, // mode couleur

  0xa254, 0xe8e4, 0xe8e4, 0xe8e4, 0xa254,
    0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4,
    0xe8e4, 0x8802, 0x8802, 0x8802, 0xe8e4,
    0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4, 0xe8e4,
    0xa254, 0xe8e4, 0xe8e4, 0xe8e4, 0xa254,
};
Image RED_BLINK(RED_BLINK_DATA);


//BLUE_BLINK
const uint16_t BLUE_BLINK_DATA[] = {
  5, 5, // largeur, hauteur
  1, // images
  0, // boucle image
  0xa254, // couleur transparente
  0, // mode couleur

  0xa254, 0x051d, 0x051d, 0x051d, 0xa254,
    0x051d, 0x0000, 0x051d, 0x0000, 0x051d,
    0x051d, 0xffff, 0x051d, 0xffff, 0x051d,
    0x051d, 0x051d, 0x051d, 0x051d, 0x051d,
    0xa254, 0x051d, 0x051d, 0x051d, 0xa254,
};
Image BLUE_BLINK(BLUE_BLINK_DATA);


//GREEN_BLINK
const uint16_t GREEN_BLINK_DATA[] = {
  5, 5, // largeur, hauteur
  1, // images
  0, // boucle image
  0xa254, // couleur transparente
  0, // mode couleur

  0xa254, 0x2589, 0x2589, 0x2589, 0xa254,
    0x2589, 0x2589, 0x2589, 0x2589, 0x2589,
    0xb723, 0xb723, 0x2589, 0xb723, 0xb723,
    0x2589, 0x2589, 0x2589, 0x2589, 0x2589,
    0xa254, 0x2589, 0x2589, 0x2589, 0xa254,
};
Image GREEN_BLINK(GREEN_BLINK_DATA);


//YELLOW_BLINK
const uint16_t YELLOW_BLINK_DATA[] = {
  5, 5, // largeur, hauteur
  1, // images
  0, // boucle image
  0xa254, // couleur transparente
  0, // mode couleur

  0xa254, 0xff80, 0xff80, 0xff80, 0xa254,
  0xffff, 0xffff, 0xff80, 0xffff, 0xffff,
  0xffff, 0x0000, 0xff80, 0x0000, 0xffff,
  0xffff, 0xffff, 0xff80, 0xffff, 0xffff,
  0xa254, 0xff80, 0xff80, 0xff80, 0xa254,
};
Image YELLOW_BLINK(YELLOW_BLINK_DATA);

int i = 0;
int j = 0;
int k = 0;
int l = 0;

int timerFrame = 0;
int timerSecond = 0;
bool gameOver = false;
int state = 0;
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
int boardFall[12][6];
int boardPop[12][6];

String string1 = "";
String string2 = "";
String string3 = "";

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
  while (!gb.update());
  gb.display.clear();

  if (board[0][2] != 'x' || board[0][3] != 'x') {
    gameOver = true;
  }
  if (gb.buttons.pressed(BUTTON_MENU)) {
    resetGame();
  }

  if (!gameOver) {    
    // GAME
    incrementTimer();
    if (state == 4) {spawnNew();}
    if (state == 0) {currentPuyoMove();}
    if (state == 0) {collisionCurrentPuyo();}
    if (state == 1) {checkBoard();}
    if (state == 2) {checkCombos();}

    // UI
    drawBoard();
    drawNextPuyos();
    drawUI();

    // TESTS
    drawText("", state, "");
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
  timerSecond = 60;
  timerFrame = 0;
  gameOver = false;
  state = 4;

  // board
  for (i = 0; i < 12; i++) {
    for (j = 0; j < 6; j++) {
      board[i][j] = 'e';
      boardFall[i][j] = 0;
      boardPop[i][i] = 0;
    }
  }
  board[0][2] = 'x';
  board[0][3] = 'x';

  // puyos
  puyo11 = getRandomColor();
  puyo12 = getRandomColor();
  puyo21 = getRandomColor();
  puyo22 = getRandomColor();
}
void spawnNew() {
    currentPuyoOrientation = 0;
    currentPuyoX = 10;
    currentPuyoY = 0;
  
    puyo01 = puyo11;
    puyo02 = puyo12;
    puyo11 = puyo21;
    puyo12 = puyo22;
    puyo21 = getRandomColor();
    puyo22 = getRandomColor();

    state = 0;
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
  for (i = 0; i < 12; i++) {
    for (j = 0; j < 6; j++) {
      boardPop[i][j]--;
    }
  }
}
char getRandomColor() {
  return colorList[rand() % 4];
}
void currentPuyoMove() {
  if (gb.buttons.repeat(BUTTON_DOWN, 0)) {
    currentPuyoY += 4;
  }
  else if (timerFrame % 10 == 0) {
    currentPuyoY++;
  }

  bool pressR = false;
  bool pressL = false;
  if (gb.buttons.repeat(BUTTON_RIGHT, 5) && currentPuyoX < 25) {
    currentPuyoX += 5;
    pressR = true;
  }
  if (gb.buttons.repeat(BUTTON_LEFT, 5) && currentPuyoX > 0) {
    currentPuyoX -= 5;
    pressL = true;
  }

  bool pressB = false;
  bool pressA = false;
  if (gb.buttons.pressed(BUTTON_B)) {
    currentPuyoOrientation++;
    pressB = true;
  }
  if (gb.buttons.pressed(BUTTON_A)) {
    currentPuyoOrientation--;
    pressA = true;;
  }

  // boucle
  if (currentPuyoOrientation >= 4) {
    currentPuyoOrientation -= 4;
  }
  if (currentPuyoOrientation <= -1) {
    currentPuyoOrientation += 4;
  }
  // collisions variables
  int currentYTile = ceil(currentPuyoY / 5);
  int currentXTile = currentPuyoX / 5;
  int current2YTile = ceil(currentPuyoY / 5);
  int current2XTile = currentPuyoX / 5;
  if (currentPuyoOrientation == 0) {
    current2YTile -= 1;
  }
  if (currentPuyoOrientation == 1) {
    current2XTile += 1;
  }
  if (currentPuyoOrientation == 2) {
    current2YTile += 1;
  }
  if (currentPuyoOrientation == 3) {
    current2XTile -= 1;
  }

  if (currentPuyoOrientation == 1 && hasCollision(current2XTile, current2YTile)) {
    if (!hasCollision(currentXTile - 1, currentYTile)) {
      currentPuyoX -= 5;
    }
    else if (pressB) {
      currentPuyoOrientation++;
    }
    else if (pressA) {
      currentPuyoOrientation--;
    }
  }
  else if (currentPuyoOrientation == 3 && hasCollision(current2XTile, current2YTile)) {
    if (!hasCollision(currentXTile + 1, currentYTile)) {
      currentPuyoX += 5;
    }
    else if (pressB) {
      currentPuyoOrientation++;
    }
    else if (pressA) {
      currentPuyoOrientation--;
    }
  }
  else if (hasCollision(current2XTile, current2YTile) || hasCollision(currentXTile, currentYTile)) {
    if (pressR) {
      currentPuyoX -= 5;
    }
    else if (pressL) {
      currentPuyoX += 5;
    }
  }
}
void collisionCurrentPuyo() {
  int currentYTile = ceil((currentPuyoY + 4) / 5);
  int currentXTile = currentPuyoX / 5;

  if ( hasCollision(currentXTile, currentYTile) || (currentPuyoOrientation == 1 && hasCollision(currentXTile + 1, currentYTile)) ||
       (currentPuyoOrientation == 3 && hasCollision(currentXTile - 1, currentYTile)) || (currentPuyoOrientation == 2 && hasCollision(currentXTile, currentYTile + 1))) {
    currentPuyoY -= 5;
    currentYTile = ceil((currentPuyoY + 4) / 5);

    if (currentPuyoOrientation == 0) {
      board[currentYTile][currentXTile] = puyo01;
      board[currentYTile - 1][currentXTile] = puyo02;
    }
    else if (currentPuyoOrientation == 1) {
      board[currentYTile][currentXTile] = puyo01;
      board[currentYTile][currentXTile + 1] = puyo02;
    }
    else if (currentPuyoOrientation == 2) {
      board[currentYTile][currentXTile] = puyo01;
      board[currentYTile + 1][currentXTile] = puyo02;
    }
    else {
      board[currentYTile][currentXTile] = puyo01;
      board[currentYTile][currentXTile - 1] = puyo02;
    }

    state = 1;
  }
}
bool hasCollision(int _x, int _y) {
  if (_y >= 12 || _y <= -1 || _x >= 6 || _x <= -1) {
    return true;
  }
  if (board[_y][_x] != 'e' && board[_y][_x] != 'x') {
    return true;
  }
  return false;
}
void checkBoard() {
  bool chute = false;
  for (i = 0; i < 11; i++) {
    for (j = 0; j < 6; j++) {
      if (board[i+1][j] == 'e' && board[i][j] != 'x' && board[i][j] != 'e') {
        chute = true;
        boardFall[i][j] += 1;
        if (boardFall[i][j] >= 5) {
          boardFall[i+1][j] = boardFall[i][j] - 5;
          boardFall[i][j] = 0;
          board[i+1][j] = board[i][j];
          board[i][j] = 'e';
        }
      }
      else {
        boardFall[i][j] = 0;
      }
    }
  }
  for (j = 0; j < 6; j++) {
    boardFall[11][j] = 0;
  }
  if (!chute) {
    state = 2;
  }
}
void checkCombos() {
  bool comboBoard[12][6];
  int comboCounter = 0;
  state = 3;
  
  // All Puyos Loop
  for (i = 0; i < 12; i++) {
    for (j = 0; j < 6; j++) {
      if (board[i][j] != 'e' && board[i][j] != 'x' && boardPop[i][j] != 0) {
        
        // reset board
        for (k = 0; k < 12; k++) {
          for (l = 0; l < 6; l++) {
            comboBoard[k][l] == false;
          }
        }
        comboCounter = 0;
        
        // All Puyos Loop Comparison ASC
        for (k = 0; k < 12; k++) {
          for (l = 1; l < 5; l++) {
            if (i == k && j == l) {
              comboBoard[k][l] == true;
              comboCounter++;
            }
            if (comboBoard[k][l-1]) {
              comboBoard[k][l] == true;
              comboCounter++;
            }
            if (k == 0) {
              // just to make sure next won't be an error
            }
            else if (comboBoard[k-1][l]) {
              comboBoard[k][l] == true;
              comboCounter++;
            }
          }
        }

        // Explosion confirmed ?
        if (comboCounter >= 4) {
          boardPop[i][j] = 10; // nb frames
          board[i][j] = 'e';
        }
      }
    }
  }

  // anim
  for (i = 0; i < 12; i++) {
    for (j = 0; j < 6; j++) {
      if (boardPop[i][j] > 5) {
        drawPuyoPopA(j * 5 + 2, i * 5 + 2, board[i][j]);
        state = 2;
      }
      else if (boardPop[i][j] > 0) {
        drawPuyoPopB(j * 5 + 2, i * 5 + 2, board[i][j]);
        state = 2;
      }
      else if (boardPop[i][j] == 0) {
        state = 4;
      }
    }
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
  gb.display.setColor(BLACK);
  gb.display.drawLine(0, 0, 32, 0);
  gb.display.setColor(WHITE);

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
  for (i = 0; i < 12; i++) {
    for (j = 0; j < 6; j++) {
      if (board[i][j] == 'e') {
        // empty
      }
      else if (board[i][j] == 'x') {
        drawCross(j * 5 + 2, i * 5 + 2);
      }
      else {
        drawPuyo(j * 5 + 2, i * 5 + 2 + boardFall[i][j], board[i][j]);
      }
    }
  }
}
void drawNextPuyos() {
  drawPuyo(36, 4, puyo11);
  drawPuyo(36, 9, puyo12);
  drawPuyo(38, 18, puyo21);
  drawPuyo(38, 23, puyo22);
  if (state == 0) {
    drawPuyo(currentPuyoX + 2, currentPuyoY + 2, puyo01);
    if (currentPuyoOrientation == 0) {
      drawPuyo(currentPuyoX + 2, currentPuyoY - 3, puyo02);
    }
    else if (currentPuyoOrientation == 1) {
      drawPuyo(currentPuyoX + 7, currentPuyoY + 2, puyo02);
    }
    else if (currentPuyoOrientation == 2) {
      drawPuyo(currentPuyoX + 2, currentPuyoY + 7, puyo02);
    }
    else if (currentPuyoOrientation == 3) {
      drawPuyo(currentPuyoX - 3, currentPuyoY + 2, puyo02);
    }
  }
}
void drawText(String _string1, int _string2, String _string3) {
  setDisplayColor('w');
  gb.display.setCursor(56, 26);
  gb.display.print(_string1);
  gb.display.setCursor(59, 33);
  gb.display.print(_string2);
  gb.display.setCursor(53, 41);
  gb.display.print(_string3);
}
void drawPuyo(int _x, int _y, char _color) {
  if (_color == 'r') {
    if (timerFrame >= 25 && timerSecond%4 == 0) {
      gb.display.drawImage(_x, _y, RED_BLINK);
    }
    else {
      gb.display.drawImage(_x, _y, RED_STAND);
    }
  }
  if (_color == 'b') {
    if (timerFrame >= 25 && timerSecond%4 == 1) {
      gb.display.drawImage(_x, _y, BLUE_STAND);
    }
    else {
      gb.display.drawImage(_x, _y, BLUE_STAND);
    }
  }
  if (_color == 'g') {
    if (timerFrame >= 25 && timerSecond%4 == 2) {
      gb.display.drawImage(_x, _y, GREEN_BLINK);
    }
    else {
      gb.display.drawImage(_x, _y, GREEN_STAND);
    }
  }
  if (_color == 'y') {
    if (timerFrame >= 25 && timerSecond%4 == 3) {
      gb.display.drawImage(_x, _y, YELLOW_BLINK);
    }
    else {
      gb.display.drawImage(_x, _y, YELLOW_STAND);
    }
  }
}
void drawPuyoPopA(int _x, int _y, char _color) {
  if (_color == 'r') {
    if (timerFrame >= 25 && timerSecond%4 == 0) {
      gb.display.drawImage(_x, _y, RED_BLINK);
    }
    else {
      gb.display.drawImage(_x, _y, RED_STAND);
    }
  }
  if (_color == 'b') {
    if (timerFrame >= 25 && timerSecond%4 == 1) {
      gb.display.drawImage(_x, _y, BLUE_STAND);
    }
    else {
      gb.display.drawImage(_x, _y, BLUE_STAND);
    }
  }
  if (_color == 'g') {
    if (timerFrame >= 25 && timerSecond%4 == 2) {
      gb.display.drawImage(_x, _y, GREEN_BLINK);
    }
    else {
      gb.display.drawImage(_x, _y, GREEN_STAND);
    }
  }
  if (_color == 'y') {
    if (timerFrame >= 25 && timerSecond%4 == 3) {
      gb.display.drawImage(_x, _y, YELLOW_BLINK);
    }
    else {
      gb.display.drawImage(_x, _y, YELLOW_STAND);
    }
  }
}
void drawPuyoPopB(int _x, int _y, char _color) {
  if (_color == 'r') {
    if (timerFrame >= 25 && timerSecond%4 == 0) {
      gb.display.drawImage(_x, _y, RED_BLINK);
    }
    else {
      gb.display.drawImage(_x, _y, RED_STAND);
    }
  }
  if (_color == 'b') {
    if (timerFrame >= 25 && timerSecond%4 == 1) {
      gb.display.drawImage(_x, _y, BLUE_STAND);
    }
    else {
      gb.display.drawImage(_x, _y, BLUE_STAND);
    }
  }
  if (_color == 'g') {
    if (timerFrame >= 25 && timerSecond%4 == 2) {
      gb.display.drawImage(_x, _y, GREEN_BLINK);
    }
    else {
      gb.display.drawImage(_x, _y, GREEN_STAND);
    }
  }
  if (_color == 'y') {
    if (timerFrame >= 25 && timerSecond%4 == 3) {
      gb.display.drawImage(_x, _y, YELLOW_BLINK);
    }
    else {
      gb.display.drawImage(_x, _y, YELLOW_STAND);
    }
  }
}
void drawCross(int _x, int _y) {
  setDisplayColor('r');
  gb.display.drawLine(_x, _y, _x + 4, _y + 4);
  gb.display.drawLine(_x + 4, _y, _x, _y + 4);
}
