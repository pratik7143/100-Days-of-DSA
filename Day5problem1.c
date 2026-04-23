#include <stdio.h>
#include <string.h>
struct ArrivalLog {
    char name[50];
    int time;
};
void sortLogs(struct ArrivalLog logs[], int n) 
{
    int i, j;
    struct ArrivalLog temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) 
        {
            if (logs[j].time > logs[j + 1].time) 
            {
                temp = logs[j];
                logs[j] = logs[j + 1];
                logs[j + 1] = temp;
            }
        }
    }
}
int main() 
{
    int n, i;
    printf("Enter number of arrivals: ");
    scanf("%d", &n);
    struct ArrivalLog logs[n];
    printf("Enter name and arrival time:\n");
    for (i = 0; i < n; i++) 
    {
        printf("Person %d - Name: ", i + 1);
        scanf("%s", logs[i].name);
        printf("Arrival time: ");
        scanf("%d", &logs[i].time);
    }
    for (i = 0; i < n; i++)
        printf("%s - %d\n", logs[i].name, logs[i].time);
    sortLogs(logs, n);
    printf("\n--- After Sorting ---\n");
    for (i = 0; i < n; i++)
        printf("%s - %d\n", logs[i].name, logs[i].time);
    return 0;
}
