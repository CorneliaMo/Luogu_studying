void select_sort(int *a, int n)
{
    for(int i=0;i<n-1;i++)
    {
        int min_index = i;
        for (int j=i;j<n;j++)
        {
            min_index = (*(a+j)<*(a+min_index))*j + (*(a+j)>=*(a+min_index))*min_index;
        }
        int tmp = *(a+min_index);
        *(a+min_index) = *(a+i);
        *(a+i) = tmp;
    }
}