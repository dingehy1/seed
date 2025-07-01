#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<string.h>
#include "file.h"
extern erow erow_0[200];
typedef struct Show
{
    char text[32];
    int length;
} showArray;
showArray showarray[16];
int x_min=0,y_min=0,x_max=31,y_max=15;
void Update(int x_min,int y_min)
{
    for(int i =0;i<16;i++)
    {
        strncpy(showarray[i].text,&erow_0[y_min+i].text[x_min],32);
    }
    FileShow();
}
void FileShow(void)
{
    system("clear");
    for(int i=0;i<16;i++){
        printf("%-32.32s",showarray[i].text);
        printf("\r\n");
    }
}

void getCursorPosition(void) {
    int x=0,y=0;
    // x=xt+x_min;
    // y=yt+y_min;
    // if(x>=x_max&&x_max<200){x_max=x;x_min=x_max-31;Update(x_min,y_min);}
    // if(x<=x_min&&x_min>0) {}{x_min=x;x_max=x_min+31;Update(x_min,y_min);}
    // if(y>=y_max&&y_max<200){}{y_max=y;y_min=y_max-15;Update(x_min,y_min);}
    // if(y<=y_min&&y_min>0){}{y_min=y;y_max=y_min+15;Update(x_min,y_min);}
}

void Init(void)
{
    printf("\033[5;10H");
}
