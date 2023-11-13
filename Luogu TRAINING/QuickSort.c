#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Marquest.h"


int * QuickSort(int a[], int n)  //快速排序 平均时间复杂度：O(N*logN)
{
    int * result;  //return用指针
    if (n<=1)
    {
        result = (int *)malloc((n+1)*sizeof(int));
        memcpy(result, &a[0], n*sizeof(int));
        return result;     //记得free内存空间
    }else if(n>1)
    {
        //选取key
        int key = a[n/2];
        int *process = (int *)malloc(n*sizeof(int));
        memcpy(process, &a, n);
        process = delpos(process, n/2, n);  //待处理序列中删除key值
        
        //左右分块
        int *left=(int *)malloc(1); int l=0;
        int *right=(int *)malloc(1); int r=0;
        for (int i=0;i<n-1;i++)
        {
            if (*(process+i)>=key)
            {
                right = append(right, *(process+i), r);
                r++;
            }else if (*(process+i)<key)
            {
                left = append(left, *(process+i), l);
                l++;
            }
        }
        
        //分别将左右分块用递归排序
        int tmp1[l+1];
        int tmp2[r+1];
        memcpy(&tmp1[0], left, l*sizeof(int));
        memcpy(&tmp2[0], right, r*sizeof(int));
        left = QuickSort(tmp1, l);
        right = QuickSort(tmp2, r);
        
        //拼接左右分块和key
        result = (int *)malloc(n*sizeof(int));
        memcpy(result, left, l*sizeof(int));
        *(result+l+1) = key;
        memcpy(result+l+2, right, r*sizeof(int));
        free(left);
        free(right);
        
        //return拼接结果
        return result;
    }
}


int main(void)
{
    int l[20] = {484, 484, 997, 753, 634, 721, 458, 168, 112, 1, 2, 9, 7, 8, 45, 69, 445, 213, 789, 12};
    int *a = QuickSort(l, 20);
    for (int i=0;i<20;i++)
    {
        printf("%d ", *(a+i));
    }
}