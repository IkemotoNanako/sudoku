#include<stdio.h>
#define size 9

int serch_box(int sudoku[size][size],int i,int j);
int serch_vertical(int sudoku[size][size],int j);
int serch_horizontal(int sudoku[size][size],int i);

int main(void){
    int cnt;
    int sudoku[size][size]={
    0,8,3,6,4,2,7,9,5,
    0,5,6,7,9,8,3,4,1,
    9,4,7,3,5,1,6,2,8,
    7,1,8,5,3,9,4,5,2,
    5,3,2,1,6,4,8,7,9,
    6,9,4,8,2,7,5,1,3,
    4,2,5,9,7,3,1,8,6,
    8,6,9,4,1,5,2,3,7,
    3,7,1,2,8,6,9,5,4,
    // 1,8,3,6,4,2,7,9,5,
    // 2,5,6,7,9,8,3,4,1,
    // 9,4,7,3,5,1,6,2,8,
    // 7,1,8,5,3,9,4,5,2,
    // 5,3,2,1,6,4,8,7,9,
    // 6,9,4,8,2,7,5,1,3,
    // 4,2,5,9,7,3,1,8,6,
    // 8,6,9,4,1,5,2,3,7,
    // 3,7,1,2,8,6,9,5,4,
    };
    // for (int i = 0; i < size; i++)
    // {
    //     for (int j = 0; j < size; j++)
    //     {
    //         printf("%ds%d—ñ‚ÍH",i+1,j+1);
    //         scanf("%d",&sudoku[i][j]);
    //     }
    // }
    while (1)
    {
        cnt = 0;
        for (int i = 1; i < size; i+=3)
        {
            for (int j = 1; j < size; j+=3)
            {
                serch_box(sudoku,i,j);
            }
        }
        for (int i = 0; i < size; i++)
        {
            serch_horizontal(sudoku,i);
        }
        for (int i = 0; i < size; i++)
        {
            serch_vertical(sudoku,i);
        }
        
        if (cnt ==0) break;
    }
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            printf("%d  ",sudoku[i][j]);
        }
        printf("\n");
    }  
    return 0; 
}

int serch_box(int sudoku[size][size], int a, int b){
    int count=0,c=0,d=0,total=0;
    for (int x = -1, y = 0, k = 0; k < 4; x += y, y = x - y, x = y - x, ++k) {
        total+=sudoku[a+x][b+y];
        if (sudoku[a+x][b+y] ==0)
        {
            count++;c=1+x;d=b+y;
        }
    }
    for (int x = -1, y = -1, k = 0; k < 2; x += 2, y +=2 ,++k) {
        total+=sudoku[a+x][b+y];
        if (sudoku[a+x][b+y] ==0)
        {
            count++;c=a+x;d=b+y;
        }
    }
    for (int x = -1, y = 1, k = 0; k < 2; x += 2, y -=2 ,++k) {
        total+=sudoku[a+x][b+y];
        if (sudoku[a+x][b+y] ==0)
        {
            count++;c=a+x;d=b+y;
        }
    }
    if (count == 1)
    {
        sudoku[c][d] = 45-total-sudoku[a][b];
    } 
}
int serch_vertical(int sudoku[size][size],int j){
    int count=0,c=0,d=0,total=0;
    for (int x = 0; x < size; x++) {
        total+=sudoku[x][j];
        if (sudoku[x][j] ==0)
        {
            count++;c=x;d=j;
        }
    }
    if (count == 1)
    {
        sudoku[c][d] = 45-total;
    }
}
int serch_horizontal(int sudoku[size][size],int i){
    int count=0,c=0,d=0,total=0;
    for (int x = 0; x < size; x++) {
        total+=sudoku[i][x];
        if (sudoku[i][x] ==0)
        {
            count++;c=i;d=x;
        }
    }
    if (count == 1)
    {
        sudoku[c][d] = 45-total;
    }
}