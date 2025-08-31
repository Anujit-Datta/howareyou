#include <stdio.h>
int main() {
int n, i, j;
printf("Enter the number of processes: ");
scanf("%d", &n);
int pid[n], bt[n], wt[n], tat[n], temp;
for(i = 0; i < n; i++) {
pid[i] = i + 1;
printf("Enter burst time for process P%d: ", pid[i]);
scanf("%d", &bt[i]);
}
// Sort processes by burst time (SJF logic)
for(i = 0; i < n - 1; i++) {
for(j = i + 1; j < n; j++) {
if(bt[i] > bt[j]) {
// Swap burst time
temp = bt[i];
bt[i] = bt[j];
bt[j] = temp;
// Swap process ID to match burst time
temp = pid[i];
pid[i] = pid[j];
pid[j] = temp;
}
}
}
wt[0] = 0;
for(i = 1; i < n; i++) {
wt[i] = wt[i - 1] + bt[i - 1];
}
for(i = 0; i < n; i++) {
tat[i] = wt[i] + bt[i];
}
printf("\nProcess\tBT\tWT\tTAT\n");
for(i = 0; i < n; i++) {printf("P%d\t%d\t%d\t%d\n", pid[i], bt[i], wt[i], tat[i]);
}
return 0;
}
