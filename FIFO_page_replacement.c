#include<stdio.h>
void main()
{
    int n,s,cr=0,PF=0,i,j,f;
    printf("Enter the no. of Frames:- ");
    scanf("%d",&n);
    printf("Enter the Size of Refrence String :- ");
    scanf("%d",&s);
    int fr[n],refs[s];
    printf("Enter the Reference String :-");
    for(i=0;i<s;i++)
        scanf("%d",&refs[i]);
    
    for(i=0;i<n;i++)
        fr[i]=-1;
    
    for(i=0;i<s;i++)
    {
        f=0;
        for(j=0;j<n;j++)
        {
            if(fr[j]==refs[i])
            {
                f=1;
            }
        }
        if(f==0)
        {
            PF++;
            fr[cr]=refs[i];
            cr=(cr+1)%n;
        }
    }
    printf("Total PAGE FAULT = %d\n", PF);
    printf("Page Fault Rate = %f\n", (float)PF/(float)n);
    
}
