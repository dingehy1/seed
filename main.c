#include<stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    char c; 
    EnableRawMode();
    char array[8];
    FileOpen(argv[1]);
    int count=0;
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q') {
            if (c == '\n') {
                write(STDOUT_FILENO, "\n", 1);
            }
            ProcessInput(c);
            getCursorPosition();
            if(count==0){
                Init();
                count++;
            }
            write(STDOUT_FILENO, &c, 1);
            // sprintf(array,"%d",c); 
            // write(STDOUT_FILENO, array, 8);   //显示按键的ASCII值
        }
    DisableRawMode();
}
