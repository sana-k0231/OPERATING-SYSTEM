#include<stdio.h>

int main(){
    int n,bt[10],pr[10],rt[10],wt[10],tat[10],i,t=0,complete=0,small;
    float avgwt=0,avgtat=0;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        printf("BT and Priority for P%d: ",i+1);
        scanf("%d%d",&bt[i],&pr[i]);
        rt[i]=bt[i];
    }

    while(complete!=n){
        small=-1;
        for(i=0;i<n;i++){
            if(rt[i]>0 && (small==-1 || pr[i]<pr[small]))
                small=i;
        }

        rt[small]--;
        t++;

        if(rt[small]==0){
            complete++;
            tat[small]=t;
            wt[small]=tat[small]-bt[small];
            avgwt+=wt[small];
            avgtat+=tat[small];
        }
    }

    printf("Avg WT=%.2f\n",avgwt/n);
    printf("Avg TAT=%.2f\n",avgtat/n);

    return 0;
}
