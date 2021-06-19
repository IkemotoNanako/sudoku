#include<stdio.h>

int main(void){
    int sudoku[4][4]={},cnt;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%ds%d—ñ‚ÍH",i+1,j+1);
            scanf("%d",&sudoku[i][j]);
        }
    }
    while (1)
    {
        cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if(sudoku[i][j]==0){
                    cnt++;
                    if (i%2 != 0 && j%2 != 2)
                    {
                        if (sudoku[i][j+1] != 0 && sudoku[i+1][j] != 0 && sudoku[i+1][j+1] != 0)
                        {
                            sudoku[i][j] = 10 - sudoku[i][j+1] - sudoku[i+1][j] - sudoku[i+1][j+1];
                        }
                    }
                    if (i%2 == 0 && j%2 != 2)
                    {
                        if (sudoku[i][j+1] != 0 && sudoku[i-1][j] != 0 && sudoku[i-1][j+1] != 0)
                        {
                            sudoku[i][j] = 10 - sudoku[i][j+1] - sudoku[i-1][j] - sudoku[i-1][j+1];
                        }
                    }
                    if (i%2 == 0 && j%2 == 2)
                    {
                        if (sudoku[i][j-1] != 0 && sudoku[i-1][j] != 0 && sudoku[i-1][j-1] != 0)
                        {
                            sudoku[i][j] = 10 - sudoku[i][j-1] - sudoku[i-1][j] - sudoku[i-1][j-1];
                        }
                    }
                    if (i%2 != 0 && j%2 == 2)
                    {
                        if (sudoku[i][j-1] != 0 && sudoku[i+1][j] != 0 && sudoku[i+1][j-1] != 0)
                        {
                            sudoku[i][j] = 10 - sudoku[i][j-1] - sudoku[i+1][j] - sudoku[i+1][j-1];
                        }
                    }  
                }
            }
        }
        if (cnt ==0) break;
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%d  ",sudoku[i][j]);
        }
        printf("\n");
    }   
}