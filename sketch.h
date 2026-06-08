#ifndef SKETCH_H
#define SKETCH_H

#include <stdint.h>
#include "sense.h"

void open_display(void);
void close_display(void);
void clear_screen(void);
void refresh_display(sense_fb_bitmap_t* canvas, int x, int y, unsigned int cursor_color);
void draw_to_canvas(sense_fb_bitmap_t* canvas, int x, int y, unsigned int color);

void open_input(void);
void close_input(void);
void check_joy(void (*callback)(unsigned int), int delay);
int check_shake(void);

#endif
