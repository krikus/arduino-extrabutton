#include <ExtraButton.h>

#define rPin 3
#define gPin 5
#define bPin 6

#define nextPin A5
#define lvlPin A4

ExtraButton nextBtn(nextPin);
ExtraButton levelBtn(lvlPin);

void setup() {
  pinMode(rPin, OUTPUT);
    analogWrite(rPin, 255);
  pinMode(gPin, OUTPUT);
    analogWrite(gPin, 255);
  pinMode(bPin, OUTPUT);
    analogWrite(bPin, 255);
}

int colors[] = {rPin, gPin, bPin};
int directions[] = {-1,-1,-1};
int lumen[] = {255,255,255};
int selectedColor = 0;
int speeds = 0;


void onClick(int btnPin){
  selectedColor = (selectedColor+1)%3;
  directions[selectedColor] = (lumen[selectedColor] > 125) ? -1 : 1;
}

void onRelease(int btnPin){
  speeds = 0;
  if (lumen[selectedColor] == 0 || lumen[selectedColor] == 255){
    directions[selectedColor] *= -1;
  }
}

void btnPressed(int btnPin){
  lumen[selectedColor] = lumen[selectedColor]+(1+speeds++/2)*directions[selectedColor];
  
  if (lumen[selectedColor] > 255){
    lumen[selectedColor] = 255;
  }else if(lumen[selectedColor] < 0){
    lumen[selectedColor] = 0;
  }
  analogWrite(colors[selectedColor], lumen[selectedColor]);
}

void loop() {
  nextBtn.onClick(*onClick);
  levelBtn.onRelease(*onRelease);
  levelBtn.whenPressed(*btnPressed,22);
  delay(1);
}
