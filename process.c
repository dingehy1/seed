#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
// 清除屏幕
void ProcessInput(char input){
    switch (input)
    {
        case 3:
            Clear();
            break;
        case 22:
            Flash();
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
