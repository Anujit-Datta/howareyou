#include <stdio.h>
int main() {
int n, i, smallest, count = 0, time;
printf("Enter the number of processes: ");
scanf("%d", &n);
int at[n], bt[n], rt[n], wt[n], tat[n];
for(i = 0; i < n; i++) {
printf("Enter arrival time and burst time for process P%d: ", i + 1);
scanf("%d %d", &at[i], &bt[i]);
rt[i] = bt[i]; // remaining time = burst time initially
}
int completed = 0;
int min_time = 9999;
smallest = -1;
for(time = 0; completed < n; time++) {
smallest = -1;
min_time = 9999;
for(i = 0; i < n; i++) {
if(at[i] <= time && rt[i] > 0 && rt[i] < min_time) {
min_time = rt[i];
smallest = i;
}
}
if(smallest == -1) continue;
rt[smallest]--;
if(rt[smallest] == 0) {
completed++;
int finish_time = time + 1;
wt[smallest] = finish_time - at[smallest] - bt[smallest];if(wt[smallest] < 0) wt[smallest] = 0;
tat[smallest] = wt[smallest] + bt[smallest];
}
}
printf("\nProcess\tAT\tBT\tWT\tTAT\n");
for(i = 0; i < n; i++) {
printf("P%d\t%d\t%d\t%d\t%d\n", i + 1, at[i], bt[i], wt[i], tat[i]);
}
return 0;
}
