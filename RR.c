#include <stdio.h>

void waitTime(int p[][3], int n, int wt[], int q) {
    int rt[n];
    for (int i = 0; i < n; i++)
        rt[i] = p[i][2];

    int t = 0;
    while (1) {
        int done = 1;
        for (int i = 0; i < n; i++) {
            if (rt[i] > 0) {
                done = 0;
                if (rt[i] > q) {
                    t += q;
                    rt[i] -= q;
                } else {
                    t += rt[i];
                    wt[i] = t - p[i][2];
                    rt[i] = 0;
                }
            }
        }
        if (done)
            break;
    }
}

void tatTime(int p[][3], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++)
        tat[i] = p[i][2] + wt[i];
}

void avgTime(int p[][3], int n, int q) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    waitTime(p, n, wt, q);
    tatTime(p, n, wt, tat);

    printf("Process\tBurst Time\tWaiting Time\tTurn Around Time\n");
    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
        printf("%d\t%d\t\t%d\t\t%d\n", p[i][0], p[i][2], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f", (float)total_wt / n);
    printf("\nAverage Turn Around Time = %.2f", (float)total_tat / n);
}

int main() {
    int p[][3] = {{1, 0, 3}, {2, 0, 4}, {3, 0, 5}, {4, 0, 1}, {5, 0, 2}};
    int n = sizeof(p) / sizeof(p[0]);
    int q = 2;

    avgTime(p, n, q);
    return 0;
}