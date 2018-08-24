#ifndef __GET_KEY_H__
#define __GET_KEY_H__

int kbd_init();
int kbd_close();
char get_key();
int get_line(char* cmd);

#endif
