#include <stdio.h>

struct P {
    int id;
    int at;
    int bt;
    int pri;
};

void waitTime(struct P p[], int n, int wt[]) {
    wt[0] = 0;
    for (int i = 1; i < n; i++) {
        wt[i] = p[i - 1].bt + wt[i - 1];
    }
}

void turnAroundTime(struct P p[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = p[i].bt + wt[i];
    }
}

void display(struct P p[], int n, int wt[], int tat[], float avg_wt, float avg_tat) {
    printf("P\t AT\t BT\t Pri\t WT\t TAT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t %d\t %d\t %d\t %d\t %d\n", p[i].id, p[i].at, p[i].bt, p[i].pri, wt[i], tat[i]);
    }
    printf("\nAvg WT: %.2f", avg_wt);
    printf("\nAvg TAT: %.2f\n", avg_tat);
}

void avgTime(struct P p[], int n) {
    int wt[n], tat[n];
    int total_wt = 0, total_tat = 0;

    waitTime(p, n, wt);
    turnAroundTime(p, n, wt, tat);

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    display(p, n, wt, tat, avg_wt, avg_tat);
}

int cmpPri(const void* a, const void* b) {
    return ((struct P*)a)->pri - ((struct P*)b)->pri;
}

int main() {
    struct P p[] = {
        {1, 0, 3, 4}, {2, 0, 4, 2}, {3, 0, 5, 3}, {4, 0, 1, 1}, {5, 0, 2, 5}
    };
    int n = sizeof(p) / sizeof(p[0]);

    qsort(p, n, sizeof(struct P), cmpPri);

    avgTime(p, n);
    return 0;
}