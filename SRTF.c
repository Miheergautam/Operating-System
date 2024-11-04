#include <stdio.h>
#include <limits.h>

struct P {
    int id;
    int bt;
};

void waitTime(struct P p[], int n, int wt[]) {
    int rt[n];
    for (int i = 0; i < n; i++) {
        rt[i] = p[i].bt;
    }

    int complete = 0, t = 0, min_t = INT_MAX;
    int short_p = 0, flag = 0;

    while (complete != n) {
        for (int i = 0; i < n; i++) {
            if (rt[i] < min_t && rt[i] > 0) {
                min_t = rt[i];
                short_p = i;
                flag = 1;
            }
        }

        if (!flag) {
            t++;
            continue;
        }

        rt[short_p]--;
        min_t = rt[short_p];
        if (min_t == 0) {
            min_t = INT_MAX;
        }

        if (rt[short_p] == 0) {
            complete++;
            flag = 0;
            int fin_t = t + 1;
            wt[short_p] = fin_t - p[short_p].bt;
            if (wt[short_p] < 0) {
                wt[short_p] = 0;
            }
        }
        t++;
    }
}

void tatTime(struct P p[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = p[i].bt + wt[i];
    }
}

void display(struct P p[], int n, int wt[], int tat[], float avg_wt, float avg_tat) {
    printf("P\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\n", p[i].id, p[i].bt, wt[i], tat[i]);
    }
    printf("\nAvg WT: %.2f", avg_wt);
    printf("\nAvg TAT: %.2f\n", avg_tat);
}

void avgTime(struct P p[], int n) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    waitTime(p, n, wt);
    tatTime(p, n, wt, tat);

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    display(p, n, wt, tat, avg_wt, avg_tat);
}

int main() {
    struct P p[] = {{1, 3}, {2, 4}, {3, 5}, {4, 1}, {5, 2}};
    int n = sizeof(p) / sizeof(p[0]);

    avgTime(p, n);
    return 0;
}