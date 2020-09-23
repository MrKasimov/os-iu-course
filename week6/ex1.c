#include <stdio.h>

#define MAX_P_NUMBER 100

int main() {
    int bt[MAX_P_NUMBER] = {0}, at[MAX_P_NUMBER] = {0}, tat[MAX_P_NUMBER] = {0},
    et[MAX_P_NUMBER] = {0}, wt[MAX_P_NUMBER] = {0};

    int p_n;
    float sumTAT = 0, sumWT = 0;

    printf("Input processes quantity: ");
    scanf("%d", &p_n);

    // I assume each AT is bigger than previous one
    printf("Input ATs and BTs:\n");

    int i = 0;
    for (i = 0; i < p_n; i++) {
        printf("AT of p%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("BT of p%d: ", i + 1);
        scanf("%d", &bt[i]);
    }

    int cur_time = at[0];

    for (i = 0; i < p_n; i++) {
        cur_time += bt[i];
        et[i] = cur_time;
    }

    for (i = 0; i < p_n; i++) {
        tat[i] = et[i] - at[i];
        sumTAT += tat[i];
    }

    for (i = 0; i < p_n; i++) {
        wt[i] = tat[i] - bt[i];
        sumWT += wt[i];
    }

    printf("P#\t AT\t BT\t ET\t TAT\t WT\t\n\n");
    for (i = 0; i < p_n; i++) {
            printf("P%d\t %d\t %d\t %d\t %d\t %d\t\n", i+1, at[i], bt[i], et[i], tat[i], wt[i]);
    }

    printf("Average TAT equals: %f\n", sumTAT/p_n);
    printf("Average WT equals: %f\n", sumWT/p_n);
}
