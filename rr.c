#include <stdio.h>
int main() {
int i, n, time = 0, tq, remain, flag = 0;
printf("Enter number of processes: ");
scanf("%d", &n);
int bt[n], rt[n], wt[n], tat[n];
remain = n;
for(i = 0; i < n; i++) {
printf("Enter burst time for P%d: ", i + 1);
scanf("%d", &bt[i]);
rt[i] = bt[i]; // Remaining time initialized
}printf("Enter time quantum: ");
scanf("%d", &tq);
int count = 0;
while(remain != 0) {
flag = 0;
for(i = 0; i < n; i++) {
if(rt[i] > 0) {
if(rt[i] > tq) {
time += tq;
rt[i] -= tq;
} else {
time += rt[i];
wt[i] = time - bt[i];
rt[i] = 0;
tat[i] = wt[i] + bt[i];
remain--;
}
flag = 1;
}
}
if(flag == 0) break;
}
printf("\nProcess\tBT\tWT\tTAT\n");
for(i = 0; i < n; i++) {
printf("P%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
}
return 0;
}
