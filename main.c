#include <unistd.h>
#include <linux/input.h>
#include "sketch.h"
int cur_x = 3;
int cur_y = 3;
unsigned int colors[] = {0xFFFF, 0xF800, 0x07E0, 0x001F,0xFFFF};
int color_idx = 0; 
int running = 1;
sense_fb_bitmap_t canvas;
void handler(unsigned int code) {
 if (code == KEY_UP) {
        cur_x = (((cur_x - 1) % 8) + 8) % 8;
    } else if (code == KEY_DOWN) {
        cur_x = (((cur_x + 1) % 8) + 8) % 8;
    } else if (code == KEY_LEFT) {
        cur_y = (((cur_y - 1) % 8) + 8) % 8;
    } else if (code == KEY_RIGHT) {
        cur_y = (((cur_y + 1) % 8) + 8) % 8;
    } else if (code == KEY_ENTER) {
        color_idx++;
        if (color_idx > 4) color_idx = 0;
    }
}
int main(void) {
    open_display();
    open_input();
    for (int i = 0; i < 8; i++) {
       for (int j = 0; j < 8; j++) {
          canvas.pixel[i][j] = 0x0000;
      }
    }

  while (running) {
     check_joy(handler, 100);
     if (check_shake()) {
       for (int i = 0; i < 8; i++) {
         for (int j = 0; j < 8; j++) { 
           canvas.pixel[i][j] = 0x0000;
            }
          }
        }
      if (color_idx > 0) {
        draw_to_canvas(&canvas, cur_x, cur_y, colors[color_idx]);
      }

    refresh_display(&canvas, cur_x, cur_y, colors[color_idx]);

        usleep(50000);
    }

    close_input();
    close_display();
    return 0;
}
