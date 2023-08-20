#include <Adafruit_GFX.h>    
#include <Adafruit_TFTLCD.h> 

#define LCD_CS A3 
#define LCD_CD A2 
#define LCD_WR A1 
#define LCD_RD A0
#define LCD_RESET A4

#define LTBLUE    0xB6DF
#define LTTEAL    0xBF5F
#define LTGREEN         0xBFF7
#define LTCYAN    0xC7FF
#define LTRED           0xFD34
#define LTMAGENTA       0xFD5F
#define LTYELLOW        0xFFF8
#define LTORANGE        0xFE73
#define LTPINK          0xFDDF
#define LTPURPLE  0xCCFF
#define LTGREY          0xE71C

#define BLUE            0x001F
#define TEAL    0x0438
#define GREEN           0x07E0
#define CYAN          0x07FF
#define RED           0xF800
#define MAGENTA       0xF81F
#define YELLOW        0xFFE0
#define ORANGE        0xFD20
#define PINK          0xF81F
#define PURPLE    0x801F
#define GREY        0xC618
#define WHITE         0xFFFF
#define BLACK         0x0000

#define DKBLUE        0x000D
#define DKTEAL    0x020C
#define DKGREEN       0x03E0
#define DKCYAN        0x03EF
#define DKRED         0x6000
#define DKMAGENTA       0x8008
#define DKYELLOW        0x8400
#define DKORANGE        0x8100
#define DKPINK          0x9009
#define DKPURPLE      0x4010
#define DKGREY        0x4A49

#define ADJ_PIN A5

boolean display1 = true;
boolean display2 = true;
boolean display3 = true;
boolean display4 = true;
boolean display5 = true;
boolean display6 = true;
boolean display7 = true;
boolean display8 = true;
boolean display9 = true;
boolean display10 = true;
boolean display11 = true;
boolean display12 = true;
boolean display13 = true;
boolean display14 = true;
boolean display15 = true;
boolean display16 = true;
boolean display17 = true;
boolean display18 = true;
boolean display19 = true;
boolean display20 = true;
boolean display21 = true;
boolean display22 = true;
boolean display23 = true;
boolean display24 = true;
boolean display25 = true;
boolean display26 = true;
boolean display27 = true;
boolean display28 = true;
boolean display29 = true;
boolean display30 = true;
boolean display31 = true;
boolean display32 = true;
boolean display33 = true;
boolean display34 = true;
boolean display35 = true;

double vo;
double ox , oy;

Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);

void Graph(Adafruit_TFTLCD &d, double x, double y, double gx, double gy, double w, double h, double xlo, double xhi, double xinc, double ylo, double yhi, double yinc, String title, String xlabel, String ylabel, unsigned int gcolor, unsigned int acolor, unsigned int pcolor, unsigned int tcolor, unsigned int bcolor, boolean &redraw) {

  double ydiv, xdiv;
  // initialize old x and old y in order to draw the first point of the graph
  // but save the transformed value
  // note my transform funcition is the same as the map function, except the map uses long and we need doubles
  //static double ox = (x - xlo) * ( w) / (xhi - xlo) + gx;
  //static double oy = (y - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
  double i;
  double temp;
  int rot, newrot;

  if (redraw == true) {

    redraw = false;
    ox = (x - xlo) * ( w) / (xhi - xlo) + gx;
    oy = (y - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
    // draw y scale
    for ( i = ylo; i <= yhi; i += yinc) {
      // compute the transform
      temp =  (i - ylo) * (gy - h - gy) / (yhi - ylo) + gy;

      if (i == 0) {
        d.drawLine(gx, temp, gx + w, temp, acolor);
      }
      else {
        d.drawLine(gx, temp, gx + w, temp, gcolor);
      }

      d.setTextSize(1);
      d.setTextColor(tcolor, bcolor);
      d.setCursor(gx - 40, temp);
      // precision is default Arduino--this could really use some format control
      d.println(i);
    }
    // draw x scale
    for (i = xlo; i <= xhi; i += xinc) {

      // compute the transform

      temp =  (i - xlo) * ( w) / (xhi - xlo) + gx;
      if (i == 0) {
        d.drawLine(temp, gy, temp, gy - h, acolor);
      }
      else {
        d.drawLine(temp, gy, temp, gy - h, gcolor);
      }

      d.setTextSize(1);
      d.setTextColor(tcolor, bcolor);
      d.setCursor(temp, gy + 10);
      // precision is default Arduino--this could really use some format control
      d.println(i);
    }

    //now draw the labels
    d.setTextSize(2);
    d.setTextColor(tcolor, bcolor);
    d.setCursor(gx , gy - h - 30);
    d.println(title);

    d.setTextSize(1);
    d.setTextColor(acolor, bcolor);
    d.setCursor(gx , gy + 20);
    d.println(xlabel);

    d.setTextSize(1);
    d.setTextColor(acolor, bcolor);
    d.setCursor(gx - 30, gy - h - 10);
    d.println(ylabel);

  }

  //graph drawn now plot the data
  // the entire plotting code are these few lines...
  // recall that ox and oy are initialized as static above
  x =  (x - xlo) * ( w) / (xhi - xlo) + gx;
  y =  (y - ylo) * (gy - h - gy) / (yhi - ylo) + gy;
  d.drawLine(ox, oy, x, y, pcolor);
  d.drawLine(ox, oy + 1, x, y + 1, pcolor);
  d.drawLine(ox, oy - 1, x, y - 1, pcolor);
  ox = x;
  oy = y;

}

/*
  End of graphing functioin
*/

void setup() {
  Serial.begin(115200);
  tft.begin(0x9341);
  tft.fillScreen(BLACK);
  tft.setRotation(1);
  pinMode(ADJ_PIN, INPUT);

  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display1);
    delay(100);                                
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display2);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);
  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display3);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);
  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display4);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);
  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display5);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);
  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display6);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);
  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display7);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);
  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display8);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);
  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display9);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);
  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display10);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);
  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display11);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);


for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display12);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display13);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display14);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display15);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display16);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display17);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display18);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display19);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display20);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display21);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display22);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display23);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display24);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display25);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display26);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display27);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display28);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display29);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display30);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);
  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display31);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display32);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display33);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display34);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);

  for (int x = 0; x < 60; x += 1) {
    vo = analogRead(ADJ_PIN) / 204.6;
    Graph(tft, x, vo, 50, 290, 390, 260, 0, 60, 10, 0, 5, 1, "ECG MONITOR", " Time [s]", "Heart rate", DKBLUE, RED, GREEN, WHITE, BLACK, display35);
    delay(100);
  }
  
  delay(1000);
  tft.fillScreen(BLACK);
}

void loop(void) { 
}
