#include <stdio.h>
//#include "Marquest.h"

//https://www.luogu.com.cn/problem/P1786

typedef struct
{
    char name[30];
    int job;
    unsigned long score;
    int level;
    int raw_loc;
}people;

int min(int a, int b)
{
    return (a>=b)*b+(a<b)*a;
}

people * bubble_sort_score(people *p, int a, int b)//提供数组指针p 起始索引a 终止索引b
{
    for (int i=0;i<(b-a);i++) //循环n-1遍
    {
        for (int j=a+1;j<=b;j++)
        {
            if (((*(p+j)).score>(*(p+j-1)).score))
            {
                people tmp;
                tmp = *(p+j);
                *(p+j) = *(p+j-1);
                *(p+j-1) = tmp;
            }
        }
    }
}

people * bubble_sort_score_b(people *p, int a, int b)//提供数组指针p 起始索引a 终止索引b
{
    for (int i=0;i<(b-a);i++) //循环n-1遍
    {
        for (int j=a+1;j<=b;j++)
        {
            if (((*(p+j)).score==(*(p+j-1)).score)&((*(p+j)).level>(*(p+j-1)).level))
            {
                people tmp;
                tmp = *(p+j);
                *(p+j) = *(p+j-1);
                *(p+j-1) = tmp;
            }
        }
    }
}


people * bubble_sort_level(people *p, int a, int b)//提供数组指针p 起始索引a 终止索引b
{
    for (int i=0;i<(b-a);i++) //循环n-1遍
    {
        for (int j=a+1;j<=b;j++)
        {
            if (((*(p+j)).level>(*(p+j-1)).level))
            {
                people tmp;
                tmp = *(p+j);
                *(p+j) = *(p+j-1);
                *(p+j-1) = tmp;
            }
        }
    }
}

people * bubble_sort_raw_loc(people *p, int a, int b)//提供数组指针p 起始索引a 终止索引b
{
    for (int i=0;i<(b-a);i++) //循环n-1遍
    {
        for (int j=a+1;j<=b;j++)
        {
            if (((*(p+j)).level==(*(p+j-1)).level)&((*(p+j)).raw_loc<(*(p+j-1)).raw_loc))
            {
                people tmp;
                tmp = *(p+j);
                *(p+j) = *(p+j-1);
                *(p+j-1) = tmp;
            }
        }
    }
}

int main(void)
{
    char JOB[7][11]={"BangZhu", "FuBangZhu", "HuFa", "ZhangLao", "TangZhu", "JingYing", "BangZhong"};

    unsigned short job_place[7];
    job_place[0]=1;job_place[1]=2;job_place[2]=2;job_place[3]=4;job_place[4]=7;job_place[5]=25;job_place[6]=60000;
    //job_place表示各职位所余空位  好像不需要....全部职位重排 好吧 拿来查表也行
    int n = 0;
    char job_s[10];
    scanf("%d", &n);
    people list[n];
    for (int i=0;i<n;i++)
    {
        scanf("%s %s %d %d", &list[i].name, &job_s, &list[i].score, &list[i].level);
        //printf("GET\n");
        if (job_s=="BangZhu"){
            list[i].job = 0;
        }else if (job_s=="FuBangZhu"){
            list[i].job = 1;
        }else if (job_s=="HuFa"){
            list[i].job = 2;
        }else if (job_s=="ZhangLao"){
            list[i].job = 3;
        }else if (job_s=="TangZhu"){
            list[i].job = 4;
        }else if (job_s=="JingYing"){
            list[i].job = 5;
        }else if (job_s=="BangZhong"){
            list[i].job = 6;
        }
        list[i].raw_loc = i;
    }

    bubble_sort_score(list, 3, n-1);
    bubble_sort_score_b(list, 3, n-1);

    int job_index=0;
    people fubangzhu[2];
    people hufa[2];
    people zhanglao[4];
    people tangzhu[7];
    people jingying[25];
    people bangzhong[69];
    for (int i=0;i<n;i++) //重新安排职位
    {
        if (job_place[job_index]==0){job_index++;}
        list[i].job = job_index;
        switch (job_index)
        {
        case 1:
            fubangzhu[2-job_place[job_index]] = list[i];
            break;
        case 2:
            hufa[2-job_place[job_index]] = list[i];
            break;
        case 3:
            zhanglao[4-job_place[job_index]] = list[i];
            break;
        case 4:
            tangzhu[7-job_place[job_index]] = list[i];
            break;
        case 5:
            jingying[25-job_place[job_index]] = list[i];
            break;
        case 6:
            bangzhong[69-job_place[job_index]] = list[i];
            break;
        }
        //printf("%s %s\n", raw_list[list[i].loc_raw].name, JOB[raw_list[list[i].loc_raw].job]);
        job_place[job_index]--;
    }
    
    
    bubble_sort_level(fubangzhu, 0, 1);
    bubble_sort_level(hufa, 0, min(2,n-3)-1);
    bubble_sort_level(zhanglao, 0, min(4,n-5)-1);
    bubble_sort_level(tangzhu, 0, min(7,n-9)-1);
    bubble_sort_level(jingying, 0, min(25,n-16)-1);
    bubble_sort_level(bangzhong, 0, n-42);
    bubble_sort_raw_loc(fubangzhu, 0, 1);
    bubble_sort_raw_loc(hufa, 0, min(2,n-3)-1);
    bubble_sort_raw_loc(zhanglao, 0, min(4,n-5)-1);
    bubble_sort_raw_loc(tangzhu, 0, min(7,n-9)-1);
    bubble_sort_raw_loc(jingying, 0, min(25,n-16)-1);
    bubble_sort_raw_loc(bangzhong, 0, n-42);
    

    //for (int i=0;i<n;i++){printf("%s %d\n", list[i].name, list[i].score);}
    ///*
    printf("%s %s %d\n", list[0].name, JOB[0], list[0].level);
    for (int i=0;i<2;i++){ printf("%s %s %d\n", fubangzhu[i].name, JOB[1], fubangzhu[i].level); }
    for (int i=0;i<min(2,n-3);i++){ printf("%s %s %d\n", hufa[i].name, JOB[2], hufa[i].level); }
    for (int i=0;i<min(4,n-5);i++){ printf("%s %s %d\n", zhanglao[i].name, JOB[3], zhanglao[i].level); }
    for (int i=0;i<min(7,n-9);i++){ printf("%s %s %d\n", tangzhu[i].name, JOB[4], tangzhu[i].level); }
    for (int i=0;i<min(25,n-16);i++){ printf("%s %s %d\n", jingying[i].name, JOB[5], jingying[i].level); }
    for (int i=0;i<n-42;i++){ printf("%s %s %d\n", bangzhong[i].name, JOB[6], bangzhong[i].level); }
    //*/

    return 0;
}



    