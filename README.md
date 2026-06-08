# cisc210-final
Avneet Aurora
Project: Etch a Sketch
Description:A cursor is moved around the grid with the
Sense Hat joystick, and pressing the joystick button cycles the pen
through five states: white (pen up), red, green, blue, and white. While
the pen is lit, moving the cursor lays down a trail of that color, which
is saved on the canvas. Shaking the Pi (detected with the accelerometer)
erases the entire canvas. The cursor wraps around the edges of the grid
in both the x and y directions, so moving off one side brings you back
in on the opposite side.
`main.c` — program entry point and main loop; holds the cursor state,
  color cycling, and the joystick callback.
`input.c` — opens and closes joystick and accelerometer.
`output.c` — framebuffer initialization, canvas-to-display blitting,
  cursor overlay, and screen clearing.
`sketch.h` — function prototypes and declarations.
`Makefile` — build rules.
Usage:
run: make clean -> make all -> make run
Joystick moves the pen around, clicking down changes color of pen and 
pen-down state. Keep clicking down to return to initial state of pen up.
Shaking clears the canvas.
