#include "ExtraButton.h"

ExtraButton::ExtraButton(int pin)
{
  pinMode(pin, INPUT_PULLUP);
  _pin = pin;
  _onClickHistory = HIGH;
  _onReleaseHistory = HIGH;
  _lastMillis = 0;
  _whenPressedHandler = NULL;
  _onReleaseHandler = NULL;
  _onClickHandler = NULL;
}

void ExtraButton::_onClick(clickHandler fun){
  int currentState = digitalRead(_pin);
  if (_onClickHistory != currentState && currentState == LOW){
    fun(_pin);
  }
  _onClickHistory = currentState;
}

void ExtraButton::_onRelease(clickHandler fun){
  int currentState = digitalRead(_pin);
  if (_onReleaseHistory != currentState && currentState == HIGH){
    fun(_pin);
  }
  _onReleaseHistory = currentState;
}



void ExtraButton::_whenPressed(clickHandler fun, int ms){
   int currentState = digitalRead(_pin);
   if (currentState == LOW){
     unsigned long currentMs = millis();
     if (currentMs < _lastMillis || (currentMs - _lastMillis >= ms)){
       _lastMillis = millis();
      fun(_pin);
     }
   }

}

void ExtraButton::update(){
  if (_whenPressedHandler){
    _whenPressed(_whenPressedHandler, _whenPressedDelay);
  }
  if (_onClickHandler){
    _onClick(_onClickHandler);
  }
  if (_onReleaseHandler){
    _onRelease(_onReleaseHandler);
  }
}

void ExtraButton::whenPressed(clickHandler fun, int delay){
  _whenPressedHandler = fun;
  _whenPressedDelay = delay;
}
void ExtraButton::onRelease(clickHandler fun){
  _onReleaseHandler = fun;
}
void ExtraButton::onClick(clickHandler fun){
  _onClickHandler = fun;
}
