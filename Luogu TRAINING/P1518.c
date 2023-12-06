#include <stdio.h>
#include <stdlib.h>

//https://www.luogu.com.cn/problem/P1518

typedef struct
{
    int now_x;//现在坐标
    int now_y;
    int next_x;//下一步坐标
    int next_y;
    int start_x;//初始坐标
    int start_y;
    int rotate;//0上1右2下3左
}animal;

void find_next(animal *a);
int block_detect(animal *a, char map[10][10]);
void out_map(animal *COW, animal *JOHN, char map[10][10]);
int main(void)
{
    //Init
    char map[10][10];
    animal COW, JOHN;
    COW.rotate=0;JOHN.rotate=0;
    //Input
    for (int loop1=0;loop1<10;loop1++)
    {
        char tmp = ' ';
        for (int loop2=0;loop2<10;loop2++)
        {
            tmp = (char)getchar();
            if (tmp=='C')
            {
                COW.now_x=loop2;COW.start_x=loop2;
                COW.now_y=loop1;COW.start_y=loop1;
                map[loop1][loop2] = '.';
            }else if (tmp=='F')
            {
                JOHN.now_x=loop2;JOHN.start_x=loop2;
                JOHN.now_y=loop1;JOHN.start_y=loop1;
                map[loop1][loop2] = '.';
            }else
            {
                map[loop1][loop2] = tmp;
            }
        }
        getchar();
    }

    //Simulate
    int * route_cow_x = (int *)malloc(1);
    *route_cow_x = 0;
    int * route_cow_y = (int *)malloc(1);
    *route_cow_y = 0;
    int * route_john_x = (int *)malloc(1);
    *route_john_x = 0;
    int * route_john_y = (int *)malloc(1);
    *route_john_y = 0;
    simulate(&COW, route_cow_x, route_cow_y, map);
    //Calculate
    int step = 0;
    do
    {
        step++;//时间前进一分钟
        
    }while (!( ((COW.now_x==COW.start_x&&COW.now_y==COW.start_y)&&(JOHN.now_x==JOHN.start_x&&JOHN.now_y==JOHN.start_y)) || (COW.now_x==JOHN.now_x&&COW.now_y==JOHN.now_y) ));

    if (COW.now_x==JOHN.now_x&&COW.now_y==JOHN.now_y)
    {
        printf("%d", step);
    }else{
        putchar('0');
    }
}

void find_next(animal *a)
{
    if (a->rotate%4==0)//上
    {
        a->next_x = a->now_x;
        a->next_y = a->now_y - 1;
    }
    if (a->rotate%4==1)//右
    {
        a->next_x = a->now_x + 1;
        a->next_y = a->now_y;
    }
    if (a->rotate%4==2)//下
    {
        a->next_x = a->now_x;
        a->next_y = a->now_y + 1;
    }
    if (a->rotate%4==3)//左
    {
        a->next_x = a->now_x - 1;
        a->next_y = a->now_y;
    }
}

int block_detect(animal *a, char map[10][10])
{
    if (a->next_x<0||a->next_y<0||a->next_x>9||a->next_y>9||(map[a->next_y][a->next_x]=='*'))
    {
        a->rotate++;
        return 1;
    }
    a->now_x = a->next_x;
    a->now_y = a->next_y;
    return 0;
}

int * simulate(animal *a, int *x, int *y, int map[10][10])
{
    find_next(a);//查找下一步
    block_detect(a, map);//探测障碍
}