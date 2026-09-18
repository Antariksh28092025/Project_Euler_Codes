#include <stdio.h>

int lastRow[15] = {0};
int currentRow[15] = {0};

void processRow(int count)
{
    int idx;

    for(idx = 0; idx <= count; idx++)
    {
        if(idx == 0) // start the row of numbers (leftmost)
        {
            currentRow[idx] += lastRow[idx];
        }
        else if(idx == count) // end of the row of numbers (rightmost)
        {
            currentRow[idx] += lastRow[idx - 1];
        }
        else
        {
            int left = lastRow[idx - 1];
            int right = lastRow[idx];

            currentRow[idx] += (left > right) ? left : right;
        }
    }

    for(idx = 0; idx <= count; idx++)
    {
        lastRow[idx] = currentRow[idx];
    }
}

int main(void)
{
    int maxSum = 0;
    int temp = 0;
    int rowIdx = 0;
    int i;
    int c;

    FILE *fp;

    // open the file for reading
    fp = fopen("triangleNums.txt", "r");

    if(fp == NULL)
    {
    perror("Error opening file");
    return 1;
    }

    while((c = fgetc(fp)) != EOF)
    {
        if(c == '\n')
        {
            currentRow[rowIdx] = temp;
            temp = 0;

            // process current row
            processRow(rowIdx);

            // reset row counter for next row
            rowIdx = 0;
        }
        else if(c == ' ')
        {
            currentRow[rowIdx] = temp;
            temp = 0;

            // move to next number
            rowIdx++;
        }
        else if(c >= '0' && c <= '9')
        {
            temp = temp * 10 + (c - '0');
        }
    }

    // Process final number/row if file doesn't end with newline
    if(temp != 0)
    {
        currentRow[rowIdx] = temp;
        processRow(rowIdx);
    }

    for(i = 0; i < 15; i++)
    {
        if(maxSum < lastRow[i])
            maxSum = lastRow[i];
    }

    printf("\nMax sum : %d\n", maxSum);

    fclose(fp);

    return 0;
}