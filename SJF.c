#include <stdio.h>
void main()
{
    int p[10],BT[10],TAT[10],WT[10],i,j,n,temp1,temp2;
    float avgWT,avgTAT,s1=0,s2=0;
    printf("Enter the no. process:-");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        p[i]=i+1;
    }
    for(i=0;i<n;i++)
    {
        printf("Enter the Burst Time of Process %d :",i+1);
        scanf("%d",&BT[i]);
    }
    for(i=0;i<n;i++)
    {
       WT[i]=0;
    }
    
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(BT[j]>BT[j+1])
            {
                temp1=BT[j];
                BT[j]=BT[j+1];
                BT[j+1]=temp1;
                
                temp2=p[j];
                p[j]=p[j+1];
                p[j+1]=temp2;
            }
        }
    }
    WT[0]=0;
    for(i=1;i<n;i++)
    {  
        WT[i]=BT[i-1]+WT[i-1];
    }
    for(i=0;i<n;i++)
    {
        TAT[i]=WT[i]+BT[i];
    }
    for(i=0;i<n;i++)
    {
        s1+=WT[i];
        s2+=TAT[i];
    }
    avgWT=s1/n;
    avgTAT=s2/n;
    
    printf("Process\t BT\t WT\t TAT\n");
    for(i=0;i<n;i++)
    {
        printf("%d \t %d\t %d\t %d\n",p[i],BT[i],WT[i],TAT[i]);
    }
    
    printf("\nAverage WT = %f\n",avgWT);
    printf("Average TAT = %f",avgTAT);

    
}
