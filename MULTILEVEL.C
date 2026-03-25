#include <stdio.h>
struct Process {
    int pid;
    int at;
    int bt;
    int type;
    int ct;
    int tat;
    int wt;
};
void sortByArrival(struct Process p[], int n) {
    struct Process temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].at > p[j + 1].at) {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
int main() {
    int n, sCount = 0, uCount = 0;
    int currentTime = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    struct Process all[n], systemQueue[n], userQueue[n];
    for (int i = 0; i < n; i++) {
        printf("\nProcess %d Details:\n", i + 1);
        printf("PID: ");
        scanf("%d", &all[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &all[i].at);
        printf("Burst Time: ");
        scanf("%d", &all[i].bt);
        printf("Type (0=System, 1=User): ");
        scanf("%d", &all[i].type);
        if (all[i].type == 0) {
            systemQueue[sCount++] = all[i];
        } else {
            userQueue[uCount++] = all[i];
        }
    }
    sortByArrival(systemQueue, sCount);
    sortByArrival(userQueue, uCount);
    for (int i = 0; i < sCount; i++) {
        if (currentTime < systemQueue[i].at) {
            currentTime = systemQueue[i].at;
        }
        systemQueue[i].ct = currentTime + systemQueue[i].bt;
        systemQueue[i].tat = systemQueue[i].ct - systemQueue[i].at;
        systemQueue[i].wt = systemQueue[i].tat - systemQueue[i].bt;
        currentTime = systemQueue[i].ct;
    }
    for (int i = 0; i < uCount; i++) {
        if (currentTime < userQueue[i].at) {
            currentTime = userQueue[i].at;
        }
        userQueue[i].ct = currentTime + userQueue[i].bt;
        userQueue[i].tat = userQueue[i].ct - userQueue[i].at;
        userQueue[i].wt = userQueue[i].tat - userQueue[i].bt;
        currentTime = userQueue[i].ct;
    }
    printf("\n--- Scheduling Results ---\n");
    printf("PID\tType\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < sCount; i++) {
        printf("%d\tSys\t%d\t%d\t%d\t%d\t%d\n",
               systemQueue[i].pid, systemQueue[i].at, systemQueue[i].bt,
               systemQueue[i].ct, systemQueue[i].tat, systemQueue[i].wt);
    }
    for (int i = 0; i < uCount; i++) {
        printf("%d\tUser\t%d\t%d\t%d\t%d\t%d\n",
               userQueue[i].pid, userQueue[i].at, userQueue[i].bt,
               userQueue[i].ct, userQueue[i].tat, userQueue[i].wt);
    }
    return 0;
}



