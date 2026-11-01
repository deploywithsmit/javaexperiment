#include <stdio.h>

int main()
{
    float weight[50], profit[50], ratio[50];
    float Totalvalue = 0, temp, capacity;
    int i, j, num;
    clrscr();

    printf("Enter number of items: ");
    scanf("%d", &num);

    for(i = 0; i < num; i++)
    {
        printf("\nEnter Weight and Profit for item[%d]: ", i + 1);
        scanf("%f %f", &weight[i], &profit[i]);
    }

    printf("\nEnter capacity of knapsack: ");
    scanf("%f", &capacity);

   
    for(i = 0; i < num; i++)
        ratio[i] = profit[i] / weight[i];

    
    for(i = 0; i < num - 1; i++)
    {
        for(j = i + 1; j < num; j++)
        {
            if(ratio[i] < ratio[j])
            {
                temp = ratio[i];
                ratio[i] = ratio[j];
                ratio[j] = temp;

                temp = weight[i];
                weight[i] = weight[j];
                weight[j] = temp;

                temp = profit[i];
                profit[i] = profit[j];
                profit[j] = temp;
            }
        }
    }

   
    for(i = 0; i < num; i++)
    {
        if(weight[i] <= capacity)
        {
            Totalvalue += profit[i];
            capacity -= weight[i];
        }
        else
        {
            Totalvalue += ratio[i] * capacity;
            break;
        }
    }

    printf("\nThe maximum value is %.2f\n", Totalvalue);
    getch();
    return 0;
}
