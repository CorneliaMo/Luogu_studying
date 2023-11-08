#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int * MergeSort(int a[], int n)  //归并排序 时间复杂度 O(NlogN)
{
    int * result; //用于return数组的临时变量
    if (n>1)
    {
        //分割数组
        int i[n/2]; 
        int j[n-n/2];
        memcpy(&i, &a[0], (n/2)*sizeof(int));
        memcpy(&j, &a[n/2], (n-n/2)*sizeof(int));

        int *tmp1 = MergeSort(i, n/2);
        int *tmp2 = MergeSort(j, n-n/2);
        memcpy(&i, tmp1, n/2*sizeof(int));
        memcpy(&j, tmp2, (n-n/2)*sizeof(int));
        free(tmp1);
        free(tmp2);
        
        //归并数组
        int r[n];
        int index1=0; int index2=0;
        for (int loop=0;loop<n;loop++)  //循环归并
        {
            if (index1<(n/2)&&index2<(n-n/2))        //判断数列为空
            {
                if (i[index1]>=j[index2])
                {
                    r[loop] = j[index2];
                    index2++;
                }else if(i[index1]<j[index2])
                {
                    r[loop] = i[index1];
                    index1++;
                }
            }else if(index1==n/2)             //r1数列为空
            {
                for (int loop2=loop;loop2<n;loop2++)
                {
                    r[loop2] = j[index2];
                    index2++;
                }
                loop = n;//退出循环
            }else if(index2==(n-n/2))             //r2数列为空
            {
                for (int loop2=loop;loop2<n;loop2++)
                {
                    r[loop2] = i[index1];
                    index1++;
                }
                loop = n;//退出循环
            }
        }
        //返回并释放
        result = (int *)malloc(n*sizeof(int));
        memcpy(result, &r[0], n*sizeof(int));
        return result;
    }else
    {
        result = (int *)malloc(n*sizeof(int));
        memcpy(result, &a[0], n*sizeof(int));
        return result;
    }
}



int main(void)
{
    int * a;
    int list[19] = {9,45,667,325,65,234,6554,23,65,345,12,511,35,78,90,5,1,0,4};
    a = MergeSort(list, 19);
    for (int i=0;i<19;i++)
    {
        printf("%d\n", *(a+i));
    }
    return 0;
}
