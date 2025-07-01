#include<stdio.h>
#include<string.h>
typedef struct Erow
{
    char text[200];
    int length;
} erow;
erow erow_0[200];
void FileOpen(char*addr )
{
        FILE *fp;
        fp=0;
        int i=0;
        if((fp=fopen(addr,"r"))==0)
        {
                printf("文件打开失败!\n");
                return -1;
        }
        for( i=0;i<200;i++){
            if(fgets(&erow_0[i].text,200,fp) == NULL)
            {
                break;
            }
            erow_0[i].length=sizeof(erow_0[i].text);           
        }
        for(;i<200;i++){
            strcpy(erow_0[i].text," \n");     
        }

        Update(0,0);

        fclose(fp);
}
