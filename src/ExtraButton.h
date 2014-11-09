#ifndef ExtraButton_h
#define ExtraButton_h

#include "Arduino.h"

typedef void (*clickHandler)(int);


class ExtraButton
{
public:
  ExtraButton(int);
  void onClick(clickHandler);
  void onRelease(clickHandler);
  void whenPressed(clickHandler, int);
  void update();
private:
  void _onClick(clickHandler);
  void _onRelease(clickHandler);
  void _whenPressed(clickHandler, int);

  int _pin;
  int _onClickHistory, _onReleaseHistory, _whenPressedDelay;
  unsigned long _lastMillis;
  clickHandler _onClickHandler, _onReleaseHandler, _whenPressedHandler;
};



#endif
