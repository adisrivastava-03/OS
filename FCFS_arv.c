#include<stdio.h>
void main()
{
	int AT[10],BT[10],WT[10],TAT[10],p,i;
	float avgWT,avgTAT,totWT=0,totTAT=0;
	printf("Enter the no. of Process :- ");
	scanf("%d",&p);
	printf("Enter Arrival Time\n");
	for(i=0;i<p;i++)
	{
		printf("Enter the Arrival time of %d :",i+1);
		scanf("%d",&AT[i]);
	}

	printf("Enter Burst Time\n");
	for(i=0;i<p;i++)
	{
		printf("Enter the Burst time of %d :",i+1);
		scanf("%d",&BT[i]);
	}
	for(i=0;i<p;i++)
	{
		TAT[i]=0;
	}
	for(i=0;i<p;i++)
	{
		WT[i]=0;
	}

	WT[0]=0;

	for(i=1;i<p;i++)
	{
		WT[i]=WT[i-1]+BT[i-1];
	}
	for(i=0;i<p;i++)
	{
		WT[i]-=AT[i];
	}
	for(i=0;i<p;i++)
	{
		TAT[i]=WT[i]+BT[i];
	}
	
	for(i=0;i<p;i++)
		totWT+=WT[i];

	for(i=0;i<p;i++)
		totTAT+=TAT[i];

	avgWT=totWT/p;
	avgTAT=totTAT/p;

	printf("Process\tArrival Time \t Burst Time \t Waiting Time \t TurnAround Time \n");
	for(i=0;i<p;i++)
	{
		printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\n",i+1,AT[i],BT[i],WT[i],TAT[i]);
	}
	
	printf("\tAverage Waiting Time = %f \n \tAverage TAT = %f \n",avgWT,avgTAT);
}
		
	
	
