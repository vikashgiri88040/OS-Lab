#include <stdio.h>

int main() {
    int n, i;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], at[n], wt[n], tat[n];

    printf("Enter arrival time and burst time for each process:\n");
    for (i = 0; i < n; i++) {
        printf("P%d Arrival Time: ", i+1);
        scanf("%d", &at[i]);
        printf("P%d Burst Time: ", i+1);
        scanf("%d", &bt[i]);
    }


    for (i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (at[i] > at[j]) {
                int temp = at[i];
                at[i] = at[j];
                at[j] = temp;

                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
            }
        }
    }


    wt[0] = 0;


    for (i = 1; i < n; i++) {
        wt[i] = (at[i-1] + bt[i-1] + wt[i-1]) - at[i];
        if (wt[i] < 0) wt[i] = 0;
    }

    for (i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\tAT\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\n", i+1, at[i], bt[i], wt[i], tat[i]);
    }

    return 0;
}
