/*
题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

例如：如果输入如下矩阵：

1              2              3              4
5              6              7              8
9              10           11           12
13           14           15           16

则依次打印出数字1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10。
*/
#include <iostream>
#include <cstdlib>
using namespace std;

void PrintARowIncreasingly(int** numbers, int columns, int rows,
                                int y, int firstX, int lastX)
{
        for(int i = firstX; i <= lastX; ++i)
        {
                int number = *(*(numbers + y) + i);
        printf("%d\t", number);
        }
}
void PrintAColumnIncreasingly(int** numbers, int columns, int rows,
                                  int x, int firstY, int lastY)
{
        for(int i = firstY; i <= lastY; ++i)
        {
                int number = *(*(numbers + i) + x);
        printf("%d\t", number);
        }
}
void PrintARowDecreasingly(int** numbers, int columns, int rows,
                                int y, int firstX, int lastX)
{
        for(int i = firstX; i >= lastX; --i)
        {
                int number = *(*(numbers + y) + i);
        printf("%d\t", number);
        }
}
void PrintAColumnDecreasingly(int** numbers, int columns, int rows,
                                  int x, int firstY, int lastY)
{
        for(int i = firstY; i >= lastY; --i)
        {
                int number = *(*(numbers + i) + x);
        printf("%d\t", number);
        }
}

void PrintMatrixInCircle(int** numbers, int columns, int rows,
                                  int startX, int startY)
{
        int endX = columns - 1 - startX;
        int endY = rows - 1 - startY;

        PrintARowIncreasingly(numbers, columns, rows, startY, startX, endX);

        if(startY < endY)
                PrintAColumnIncreasingly(numbers, columns, rows, endX, startY + 1, endY);

        if(startX < endX && startY < endY)
                PrintARowDecreasingly(numbers, columns, rows, endY, endX - 1, startX);

        if(startX < endX && startY < endY - 1)
                PrintAColumnDecreasingly(numbers, columns, rows, startX, endY - 1, startY + 1);
}

void PrintMatrixClockwisely(int** numbers, int columns, int rows)
{
        if(numbers == NULL || columns <= 0 || rows <= 0)
                return;
 
        int startX = 0;
        int startY = 0;
 
        while(columns > startX * 2 && rows > startY * 2)
        {
                PrintMatrixInCircle(numbers, columns, rows, startX, startY);
 
                ++startX;
                ++startY;
        }
}


int main(){
  int numbers[4][4] = {{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,16}};
  for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
      cout<<numbers[i][j]<<"**";
    cout<<endl;
  int* a = numbers[0];
  int** b = &a;
  PrintMatrixClockwisely(b,4,4);
}
