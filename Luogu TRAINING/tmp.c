#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    int x1;
    int x2;
    int y1;
    int y2;
}point;

int max(int a, int b)
{
    if (a>=b)
    {
        return a;
    }else{
        return b;
    }
}

int min(int a, int b)
{
    if (a>=b)
    {
        return b;
    }else{
        return a;
    }
}

int main(void)
{
    int n = 0;
    scanf("%d\n", &n);//线段组数量
    point * list = (point *)malloc(n*2*sizeof(point)); 
    for (int i=0;i<n;i++)
    {
        scanf("%d %d %d %d", &(list+i*2)->x1, &(list+i*2)->y1, &(list+i*2)->x2, &(list+i*2)->y2);
        scanf("%d %d %d %d", &(list+i*2+1)->x1, &(list+i*2+1)->y1, &(list+i*2+1)->x2, &(list+i*2+1)->y2);
        float k1, k2;
        k1 = ((list+i*2)->y2-(list+i*2)->y1)/((list+i*2)->x2-(list+i*2)->x1);
        k2 = ((list+i*2+1)->y2-(list+i*2+1)->y1)/((list+i*2+1)->x2-(list+i*2+1)->x1);
        if (k1==k2)
        {
            printf("disjoint\n");
        }else
        {
            point * a, b;
            a = list+i*2;
            b = list+i*2+1;
            if(max(b->x1,b->x2)<min(a->x1,a->x2)||max(a->x1,a->x2)<min(b->x1,b->x2)||max(b->y1,b->y2)<min(a->y1,a->y2)||max(a->y1,a->y2)<min(b->y1,b->y2))
            {
                printf("disjoint\n");
            }else if(cross(a-d,c-d)*cross(b-d,c-d)>0||cross(d-b,a-b)*cross(c-b,a-b)>0)
            {
                printf("disjoint\n");
            }else{
                printf("intersect\n");
            }
    }
    
    return 0;
}