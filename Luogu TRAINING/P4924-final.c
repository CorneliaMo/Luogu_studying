#include <stdio.h>

int* switch_pos(int i, int j, int k, int l, int tmp);

int main(void)
{
    int n, m = 0;
    scanf("%d %d\n", &n, &m);
    int sq[n][n];
    for (int i=0;i<n;i++)          //初始化数组（？
    {
        for (int j=0;j<n;j++)
        {
            sq[i][j]=i*n+j+1;
        }
    }

    int x, y, r, z = 0;
    
    for (int i=0;i<m;i++)  //获取“魔法”输入
    {
        scanf("%d %d %d %d", &x, &y, &r, &z);
        int up, down, left, right = 0;
        int *tmp_out;
        for (int range=r;range>0;range--)
        {
            up = x-1-range;
            down = x-1+range;
            left = y-1-range;
            right = y-1+range;
            //printf("%d %d %d %d", up, down, left, right);
            tmp_out = switch_pos(sq[up][left], sq[up][right], sq[down][right], sq[down][left], z);
            sq[up][left]=*(tmp_out+0);sq[up][right]=*(tmp_out+1);sq[down][right]=*(tmp_out+2);sq[down][left]=*(tmp_out+3); 
            for (int a=1;a<(down-up);a++) 
            {
                tmp_out = switch_pos(sq[up][left+a], sq[up+a][right], sq[down][right-a], sq[down-a][left], z);
                sq[up][left+a]=*(tmp_out+0);sq[up+a][right]=*(tmp_out+1);sq[down][right-a]=*(tmp_out+2);sq[down-a][left]=*(tmp_out+3); 
            }
        }
    }
    

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%d ", sq[i][j]);
        }
        putchar('\n');
    }

    return 0;
}

int* switch_pos(int i, int j, int k, int l, int tmp)
{
    int outp[4];
    int *o = outp;
    if (tmp==1){
        outp[0] = j;
        outp[1] = k;
        outp[2] = l;
        outp[3] = i;
        return o;
    }else if(tmp==0){
        outp[0] = l;
        outp[1] = i;
        outp[2] = j;
        outp[3] = k;
        return o;
    }   
}