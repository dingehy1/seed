#include<stdio.h>
#include <unistd.h>
char *addr;
int main(int argc, char *argv[])
{
    char c; 
    addr=argv[1];
    EnableRawMode();
    char array[8];
    FileOpen(argv[1]);
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
            if (c == '\n') {
                write(STDOUT_FILENO, "\n", 1);
            }
            ProcessInput(c);
            getCursorPosition();
            write(STDOUT_FILENO, &c, 1);
            // sprintf(array,"%d",c); 
            // write(STDOUT_FILENO, array, 8);   //显示按键的ASCII值
        }
    DisableRawMode();
}
