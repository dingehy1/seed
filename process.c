#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include"show.h"
void ProcessInput(char input){
    switch (input)
    {
        case 3:
            Clear();
            break;
        case 22:
            Flash();
            break;
        case '\033':
            getchar();
            switch(getchar()){
                case 'A':
                    MOVEUP();
                    break;
                case 'B':
                    MOVEDOWN();
                    break;
                case 'C':
                    MOVERIGHT();
                    break;
                case 'D':
                    MOVELEFT();
                    break;
                default:
                    break;
            }
        break;
        case 127:
            Delete_();
            break;
    
    default:
        break;
    }
}

void  Flash(void){
        printf("\033[?25l");
        fflush(stdout); // 确保光标立即显示
        usleep(500000); // 500毫秒
        printf("\033[?25h");
        fflush(stdout); // 确保光标立即显示
        usleep(500000); // 500毫秒
        printf("\033[?25l");
        fflush(stdout); // 确保光标立即显示
        usleep(500000); // 500毫秒
        printf("\033[?25h");
        fflush(stdout); // 确保光标立即显示
        usleep(500000); // 500毫秒
}
void  Clear(void){
    system("clear");
}
void  Delete_(void){
    FileOpen();
}
