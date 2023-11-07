int max(int a, int b)
{
    return (a>=b)*a+(a<b)*b;
}

int min(int a, int b)
{
    return (a>=b)*b+(a<b)*a;
}

bubblesort_high2low(int *p, int a, int b)//提供数组指针p 起始索引a 终止索引b
{
    for (int i=0;i<(b-a);i++) //循环n-1遍
    {
        for (int j=a+1;j<=b;j++)
        {
            if (*(p+j)>*(p+j-1))
            {
                int tmp;
                tmp = *(p+j);
                *(p+j) = *(p+j-1);
                *(p+j-1) = tmp;
            }
        }
    }
}

bubblesort_low2high(int *p, int a, int b)//提供数组指针p 起始索引a 终止索引b
{
    for (int i=0;i<(b-a);i++) //循环n-1遍
    {
        for (int j=a+1;j<=b;j++)
        {
            if (*(p+j)<*(p+j-1))
            {
                int tmp;
                tmp = *(p+j);
                *(p+j) = *(p+j-1);
                *(p+j-1) = tmp;
            }
        }
    }
}