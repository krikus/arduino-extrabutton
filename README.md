arduino-easyeasing
==================

Library for arduino that will make using switch button very easy.

This library does not use interrupts, you must manually call `update()` in main loop.
You should not use any long delays in your code - for the best is to use `millis()` instead.

==================

For start you need to new object using `ExtraButton button = new ExtraButton(int btnPin)`. This object has following public methods:

`void onClick(clickHandler)` // sets handler for 'click' state - when button is pressed

`void onRelease(clickHandler)` // sets handler for when button is released

`void whenPressed(clickHandler, int)` // sets handler for when button is pressed - handler will be called untill button will be released (with the debounce of second parameter in milliseconds)

`void update()` // called in main loop - updates button state


`clickHandler` is pointer to function that returns type `void` and argument `int` - argument holds pin of the button so you can have one handler to few buttons.
