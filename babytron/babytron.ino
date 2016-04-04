/**********************************************************  
Code for blinkinlabs led dots for a cardboard computer
The first LED is in the top right of the grid,
going down the right side, then across the bottom row,
back along the second row up, and so on. The last two
LEDs of the 50 LED string aren't used.

March 2016
**********************************************************/

#include <Adafruit_NeoPixel.h>
#define PIN 13

int numPix = 48;
int allRows[] = {41,42,43,44,45,46,47,40,39,38,37,36,35,34,27,28,29,30,31,32,33,26,25,24,23,22,21,20,13,14,15,16,17,18,19,12,11,10,9,8,7,6};
int allCols[] = {41,40,27,26,13,12,42,39,28,25,14,11,43,38,29,24,15,10,44,37,30,23,16,9,45,36,31,22,17,8,46,35,32,21,18,7,47,34,33,20,19,6,0,1,2,3,4,5};

Adafruit_NeoPixel strip = Adafruit_NeoPixel(numPix, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
}

void loop() {
    
  converge(10, 0, 0, 0, 0, 10, 15);
  converge(0, 20, 0, 0, 20, 0, 15);

  for(int a=0; a<3; a++){
    int p1 = random(0, 6);
    strip.setPixelColor(p1, 0, 10, 0);
    for(int i=0; i<4; i++){
      randomDots(200);
    }  
    for(int i=0; i<3; i++){
      randomDots(0);
      rightDotsGreen(40);
    }
  }

  rowChase(100);
  rowChaseTwo(100);
  rowChase(100);
  columnWipe(50);
  columnWipe(150);

  for(int a=0; a<4; a++){
    int p1 = random(0, 6);
    strip.setPixelColor(p1, 0, 10, 0);
    for(int i=0; i<4; i++){
      randomDots(200);
    }  
    for(int i=0; i<2; i++){
      randomDots(0);
      rightDotsRed(40);
    }
  }
  
}


void clearString() {
  for (int p = 0; p < numPix; p++) {
    strip.setPixelColor(p, 0, 0, 0);
  }
}

void randomDots(int del) {
  clearString();
  for (int n = 0; n < 5; n++){
    int p = random(6,48);
    strip.setPixelColor(p, 5, 10, 0);
  }
  strip.show();
  delay(del);
}

void rightDotsGreen(int del) {
  for (int f = 0; f<11; f++){
    strip.setPixelColor(0, f, 0, 0);
    strip.show();
    delay(del); 
    }
  for (int d = 1; d<6; d++){
    for (int f = 0; f<11; f++){
      strip.setPixelColor(d, f, 0, 0);
      strip.setPixelColor((d-1), (10-f), 0, 0);
      strip.show();
      delay(del); 
    }
  }
  for (int f = 0; f<11; f++){
    strip.setPixelColor(5, (10-f), 0, 0);
    strip.show();
    delay(del); 
    }  
}

void rightDotsRed(int del) {
  for (int f = 0; f<11; f++){
    strip.setPixelColor(0, 0, f, 0);
    strip.show();
    delay(del); 
    }
  for (int d = 1; d<6; d++){
    for (int f = 0; f<11; f++){
      strip.setPixelColor(d, 0, f, 0);
      strip.setPixelColor((d-1), 0, (10-f), 0);
      strip.show();
      delay(del); 
    }
  }
  for (int f = 0; f<11; f++){
    strip.setPixelColor(5, 0, (10-f), 0);
    strip.show();
    delay(del); 
    }  
}

void rowChase(int del) {
  for(int row = 0; row<6; row++){
    clearString();
    strip.setPixelColor(row, 0, 0, 20);
    strip.show();
    delay(del);
    for(int index = 0; index < 7; index++){
      strip.setPixelColor(allRows[((row*7) + index)], 0, 10, 10);
      strip.show();
      delay(del);
    }
    for(int index = 0; index < 7; index++){
      strip.setPixelColor(allRows[((row*7) + index)], 0, 0, 0);
      strip.show();
      delay(del);
    }
  }
  clearString();
}

void rowChaseTwo(int del) {
  for(int row = 0; row<6; row++){
    clearString();
    strip.setPixelColor(row, 0, 0, 20);
    strip.show();
    delay(del);
    for(int index = 0; index < 7; index++){
      strip.setPixelColor(allRows[((row*7) + index)], 10, 0, 10);
      strip.show();
      delay(del);
    }
    for(int index = 0; index < 7; index++){
      strip.setPixelColor(allRows[((row*7) + index)], 0, 0, 0);
      strip.show();
      delay(del);
    }
  }
  clearString();
}

void dotChase (int g, int r, int b, int del) {
    strip.setPixelColor(0, g, r, b);
    strip.show();
    delay(del); 
  for (int p = 0; p < numPix; p++) {
    strip.setPixelColor(p, 0, 0, 0);
    strip.setPixelColor(p+1, g, r, b);
    strip.show();
    delay(del);  
  }
}

void columnWipe (int del) {
  for (int col = 0; col<8; col++){
    clearString();
    for(int index = 0; index < 6; index++){
      strip.setPixelColor(allCols[((col*6) + index)], 20, 20, 20);
      strip.show();
    }
    delay(del);
  }
  for (int col = 6; col>0; col--){
    clearString();
    for(int index = 0; index < 6; index++){
      strip.setPixelColor(allCols[((col*6) + index)], 4, 8, 0);
      strip.show();
    }
    delay(del);
  }
  clearString();
  for(int index = 0; index < 6; index++){
    strip.setPixelColor(allCols[index], 5, 5, 0);
    strip.show();
  }
  delay(del);
  clearString();
}

void dotChaseRev (int g, int r, int b, int del) {
    strip.setPixelColor((numPix-1), g, r, b);
    strip.show();
    delay(del); 
  for (int p = (numPix-1); p >= 0; p--) {
    strip.setPixelColor(p, 0, 0, 0);
    strip.setPixelColor(p-1, g, r, b);
    strip.show();
    delay(del);  
  }
}

void converge (int g1, int r1, int b1, int g2, int r2, int b2, int del) {
  for (int i=0; i<numPix; i++) {
    strip.setPixelColor(i, g1, r1, b1);
    strip.setPixelColor(((numPix-1)-i), g2, r2, b2);
    strip.show();
    delay(del);
    strip.setPixelColor(i, 0, 0, 0);
    strip.setPixelColor(((numPix-1)-i), 0, 0, 0);
  }
  strip.show();  
}
