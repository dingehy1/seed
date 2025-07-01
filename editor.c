#include<termios.h>
#include<stdio.h>

#define InputMode 0

struct termios old_t ,new_t;
int EnableRawMode(){

    tcgetattr(InputMode,&old_t);
    new_t = old_t;

    new_t.c_lflag &= ~(ECHO | ICANON | ISIG | IEXTEN);
    new_t.c_iflag &= ~(IXON | BRKINT | INPCK|ISTRIP);
    new_t.c_oflag &= ~(OPOST);

    new_t.c_cc[VMIN]=0;
    new_t.c_cc[VTIME]=300;

    tcsetattr(InputMode,TCSAFLUSH,&new_t);
    return 0;
}

int DisableRawMode(){
    tcsetattr(InputMode,TCSAFLUSH,&old_t);
    return 0;
}
