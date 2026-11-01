#include <stdio.h>
#include <string.h>

#define MAX 100

void computeLPS(char pattern[], int m, int lps[])
{
    int length = 0;
    int i = 1;

    lps[0] = 0;

    while (i < m)
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}

void KMPsearch(char text[], char pattern[])
{
    int n, m, i, j;
    int lps[MAX];
    int found = 0;

    n = strlen(text);
    m = strlen(pattern);

    if (m == 0)
    {
        printf("\nPattern is empty.");
        return;
    }

    computeLPS(pattern, m, lps);

    i = 0;
    j = 0;

    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            i++;
            j++;
        }

        if (j == m)
        {
            printf("\nPattern found at position %d", i - j);
            found = 1;
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }

    if (found == 0)
        printf("\nPattern not found.");
}

void main()
{
    char text[MAX], pattern[MAX];

    clrscr();

    printf("Enter the text: ");
    gets(text);

    printf("Enter the pattern to search: ");
    gets(pattern);

    KMPsearch(text, pattern);

    getch();
}