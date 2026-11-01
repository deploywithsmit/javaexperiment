#include <stdio.h>
#include <string.h>
#define MAX 100

void lcs(char X[], char Y[])
{
    int c[MAX + 1][MAX + 1];
    char result[MAX];
    int m = strlen(X);
    int n = strlen(Y);
    int i, j, index;

    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                c[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                c[i][j] = c[i - 1][j - 1] + 1;
            else
                c[i][j] = (c[i - 1][j] > c[i][j - 1])
                            ? c[i - 1][j]
                            : c[i][j - 1];
        }
    }

    index = c[m][n];
    result[index] = '\0';

    i = m;
    j = n;

    while (i > 0 && j > 0)
    {
        if (X[i - 1] == Y[j - 1])
        {
            result[index - 1] = X[i - 1];
            i--;
            j--;
            index--;
        }
        else if (c[i - 1][j] > c[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    printf("\nLength of LCS = %d", c[m][n]);
    printf("\nLongest Common Subsequence = %s\n", result);
}

int main()
{
    char X[MAX], Y[MAX];
    clrscr();

    printf("Enter first string: ");
    fgets(X, MAX, stdin);
    X[strcspn(X, "\n")] = '\0';

    printf("Enter second string: ");
    fgets(Y, MAX, stdin);
    Y[strcspn(Y, "\n")] = '\0';

    lcs(X, Y);
    getch();
    return 0;
}


