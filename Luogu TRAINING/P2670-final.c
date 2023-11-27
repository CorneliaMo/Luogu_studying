#include <stdio.h>

// https://www.luogu.com.cn/problem/P2670

void Pluser(int r, int c);
void printList(int r, int c);

static int BombList[102][102] = {0};//炸弹数 10表示炸弹

int main(void)
{
    int n, m  = 0; //行数 列数
    scanf("%d %d", &n, &m); //输入行数+列数
    //printf("%d", n);
    char list[n][m];
    
    for (int i = 0;i<n;i++)
    {
        scanf("%s", &list[i]); //将雷图保存到list中
    }

    for (int row = 0;row<n;row++)
    {
        for (int col = 0;col<m;col++) 
        {
            //遍历行-列每一棋格
            if (list[row][col]=='*')
            {
                BombList[row+1][col+1] = 10;
                Pluser( row+2, col+2);
                Pluser( row+2, col);
                Pluser( row+2, col+1);
                Pluser( row+1, col+2);
                Pluser( row+1, col);
                Pluser( row, col+1);
                Pluser( row, col+2);
                Pluser( row, col);
            }
        }
    }
    printList(n, m);
    return 0;
}

void Pluser(int r, int c)
{
    if(BombList[r][c]!=10)
    {
        BombList[r][c]++;
    }
}

void printList(int r, int c)
{
    for (int i=1;i<=r;i++)
    {
        for (int j=1;j<=c;j++)
        {
            if (BombList[i][j]==10)
            {
                putchar('*');
            }else{
                printf("%d", BombList[i][j]);
            }
        }
        putchar('\n');
    }
}