#include <stdio.h>
//#include "Marquest.h"

//https://www.luogu.com.cn/problem/P1786

int min(int a, int b)
{
    return (a>=b)*b+(a<b)*a;
}

int main(void)
{
    char JOB[7][9]={"BangZhu", "FuBangZhu", "HuFa", "ZhangLao", "TangZhu", "JingYing", "BangZhong"};
    typedef struct
    {
        char name[30];
        int job;
        unsigned long score;
        int level;
    }people;

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
    }
    
    //for (int i=0;i<n;i++){printf("%6d ", list[i].score);}
    //putchar('\n');

    for (int i=1;i<n-3;i++) //冒泡排序 仅需n-1次  0大n小 前三个无需排序
    {
        for (int j=4;j<n;j++)
        {
            if (list[j].score>list[j-1].score)
            {
                people tmp;
                tmp = list[j];
                list[j] = list[j-1];
                list[j-1] = tmp;
            }
        }
        //for (int i=0;i<n;i++){printf("%6d ", list[i].score);}
        //putchar('\n');
    }
    
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
            fubangzhu[job_place[job_index]-1] = list[i];
            break;
        case 2:
            hufa[job_place[job_index]-1] = list[i];
            break;
        case 3:
            zhanglao[job_place[job_index]-1] = list[i];
            break;
        case 4:
            tangzhu[job_place[job_index]-1] = list[i];
            break;
        case 5:
            jingying[job_place[job_index]-1] = list[i];
            break;
        case 6:
            bangzhong[job_place[job_index]-1] = list[i];
            break;
        }
        //printf("%s %s\n", raw_list[list[i].loc_raw].name, JOB[raw_list[list[i].loc_raw].job]);
        job_place[job_index]--;
    }
    
    if (fubangzhu[0].level<fubangzhu[1].level){people tmp=fubangzhu[0];fubangzhu[0]=fubangzhu[1];fubangzhu[1]=tmp;}

    if (hufa[0].level<hufa[1].level){people tmp=hufa[0];hufa[0]=hufa[1];hufa[1]=tmp;}

    for (int i=0;i<(n-5);i++) //冒泡排序 仅需n-1次  0大n小 前三个无需排序
    {
        for (int j=0;j<min(n-5,4);j++)
        {
            if (zhanglao[j].level>zhanglao[j-1].level)
            {
                people tmp;
                tmp = zhanglao[j];
                zhanglao[j] = zhanglao[j-1];
                zhanglao[j-1] = tmp;
            }
        }
    }

    for (int i=0;i<(n-9);i++) //冒泡排序 仅需n-1次  0大n小 前三个无需排序
    {
        for (int j=0;j<min(n-9,7);j++)
        {
            if (tangzhu[j].level>tangzhu[j-1].level)
            {
                people tmp;
                tmp = tangzhu[j];
                tangzhu[j] = tangzhu[j-1];
                tangzhu[j-1] = tmp;
            }
        }
    }

    for (int i=0;i<(n-16);i++) //冒泡排序 仅需n-1次  0大n小 前三个无需排序
    {
        for (int j=0;j<min(n-16,25);j++)
        {
            if (jingying[j].level>jingying[j-1].level)
            {
                people tmp;
                tmp = jingying[j];
                jingying[j] = jingying[j-1];
                jingying[j-1] = tmp;
            }
        }
    }

    for (int i=0;i<(n-41);i++) //冒泡排序 仅需n-1次  0大n小 前三个无需排序
    {
        for (int j=0;j<n-41;j++)
        {
            if (bangzhong[j].level>bangzhong[j-1].level)
            {
                people tmp;
                tmp = bangzhong[j];
                bangzhong[j] = bangzhong[j-1];
                bangzhong[j-1] = tmp;
            }
        }
    }

    printf("%s %s %d\n", list[0].name, JOB[0], list[0].level);
    printf("%s %s %d\n", fubangzhu[0].name, JOB[1], fubangzhu[0].level);
    printf("%s %s %d\n", fubangzhu[1].name, JOB[1], fubangzhu[1].level);
    for (int i=0;i<min(n-3,2);i++){printf("%s %s %d\n", hufa[i].name, JOB[2], hufa[1].level);}
    for (int i=0;i<min(n-5,4);i++){printf("%s %s %d\n", zhanglao[i].name, JOB[3], zhanglao[1].level);}
    for (int i=0;i<min(n-9,7);i++){printf("%s %s %d\n", tangzhu[i].name, JOB[4], tangzhu[1].level);}
    for (int i=0;i<min(n-16,25);i++){printf("%s %s %d\n", jingying[i].name, JOB[5], jingying[1].level);}
    for (int i=0;i<(n-41);i++){printf("%s %s %d\n", bangzhong[i].name, JOB[6], bangzhong[1].level);}
    
    return 0;
}