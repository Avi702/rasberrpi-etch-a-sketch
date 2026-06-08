#include "sense.h"
#include "sketch.h"
#include <stddef.h>
pi_framebuffer_t* fb_dev = NULL;

void open_display(void) {
    if (fb_dev == NULL) {
        fb_dev = getFrameBuffer();
    }
}

void clear_screen(void) {
    if (fb_dev != NULL) {
        clearFrameBuffer(fb_dev, 0x0000);
    }
}

void refresh_display(sense_fb_bitmap_t* canvas, int x, int y, unsigned int cursor_color) {
    if (fb_dev == NULL) return;
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            fb_dev->bitmap->pixel[i][j] = canvas->pixel[i][j];
    fb_dev->bitmap->pixel[x][y] = cursor_color;
}
void draw_to_canvas(sense_fb_bitmap_t* canvas, int x, int y, unsigned int color) {
    canvas->pixel[x][y] = color;
}

void close_display(void) {
    if (fb_dev != NULL) {
        clearFrameBuffer(fb_dev, 0x0000);
        freeFrameBuffer(fb_dev);
        fb_dev = NULL;
    }
}
