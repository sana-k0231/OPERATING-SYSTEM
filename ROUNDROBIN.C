#include <stdio.h>

void calculateTimes(int n, int bt[], int quantum) {
int wt[n], tat[n], rem_bt[n];
int total_wt = 0, total_tat = 0;
int t = 0; // Current time

// Copy burst times to remaining burst times
for (int i = 0; i < n; i++)
rem_bt[i] = bt[i];

while (1) {
int done = 1;
for (int i = 0; i < n; i++) {
if (rem_bt[i] > 0) {
done = 0; // There is a pending process
if (rem_bt[i] > quantum) {
t += quantum;
rem_bt[i] -= quantum;
} else {
t = t + rem_bt[i];
wt[i] = t - bt[i];
rem_bt[i] = 0;
}
}
}
if (done == 1) break;
}

// Calculate Turnaround Time (TAT = Burst Time + Waiting Time)
for (int i = 0; i < n; i++)
tat[i] = bt[i] + wt[i];

// Display Results
printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
for (int i = 0; i < n; i++) {
total_wt += wt[i];
total_tat += tat[i];
printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
}

printf("\nAverage Waiting Time = %.2f", (float)total_wt / (float)n);
printf("\nAverage Turnaround Time = %.2f\n", (float)total_tat / (float)n);
}

int main() {
int n, quantum;
printf("Enter number of processes: ");
scanf("%d", &n);

int burst_time[n];
for (int i = 0; i < n; i++) {
printf("Enter Burst Time for Process %d: ", i + 1);
scanf("%d", &burst_time[i]);
}

printf("\nEnter Time Quantum: ");
scanf("%d", &quantum);

printf("\n--- Round Robin Simulation (Quantum: %d) ---", quantum);
calculateTimes(n, burst_time, quantum);

return 0;
}
