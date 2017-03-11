#include<stdio.h>
#include<stdio.h>
void main()
{
	int pr[20],n,p[20],at[20],bt[10],wt[10],t=0,kt[20],c[10][10],tat[10],ct[10],i=0,j=0,k=0,s=0,rt[10],lt[10],a=0,a1,a2,a3,a4,count=0;
	printf("enter the number of processes\n");
	scanf("%d",&n);
	printf("enter the priority,arrival time and burst time in order\n");
	for(i=0;i<n;i++)
	{
		printf("enter the priority for p%d\n",i);
		scanf("%d",&p[i]);
		printf("enter the arrival time for p%d\n",i);
		scanf("%d",&at[i]);
		printf("enter the burst time for p%d\n",i);
		scanf("%d",&bt[i]);
		kt[i]=bt[i];
		rt[i]=-1;
		pr[i]=i;
	}//entered data
	while(count!=n)
	{
		t++;
		printf("test");
		for(i=0;i<n;i++)
		{
			if(t==at[i])
			{
				c[j][1]=i;
				c[j][2]=p[i];
				j++;
			}
			else
			{
				continue;
			}
		}	//storing in 2d array
		for(i=0;i<j;i++)
		{
			for(s=0;s<j;s++)
			{

			if(c[i][2]>c[s][2])
			{
				a=c[i][1];
				c[i][1]=c[s][1];
				c[s][1]=a;
				a=c[i][2];
				c[i][2]=c[s][2];
				c[s][2]=a;
			}
		}
		}//sorting
		for(i=0;i<j;i++)
		{
			printf("%d->",c[i][1]);
		}
		lt[k]=c[0][1];
		k++;
		
		for(s=0;s<n;s++)
		{
			if(pr[s]==lt[k])
			{
				kt[s]=kt[s]-1;
				if(kt[s]==0)
				{
					ct[s]=t;
					tat[s]=ct[s]-at[s];
					wt[s]=tat[s]-bt[s];
					for(i=0;i<j-1;i++)
					{			
			  			c[i][1]=c[i+1][1];
						c[i][2]=c[i+1][2];
						count+=1;
					}
				}
				else
				{
					kt[s]=kt[s]-1;
					if(rt[s]==-1)
					{
						rt[s]=t-at[s];
					}
				}
			}
		}	
	}
	printf("G-chart=\n");
	for(i=0;i<k;i++)
	{
		printf("->p%d",lt[i]);
	}
	for(i=0;i<n;i++)
	{
	a1=a1+ct[i];
	a2=a2+tat[i];
	a3=a3+wt[i];
	a4=a4+rt[i];		
	}
	printf("process table = \n");
	printf("process \t at \t bt \t ct \t tat \t wt \t rs \t\n");
	for(i=0;i<n;i++)
	{
			printf("p%d \t%d \t %d \t %d \t %d \t %d \t %d \t\n",at[i],bt[i],ct[i],tat[i],wt[i],rt[i]);
	}
	printf("avg completion time=%d",a1/n);
	printf("avg turn around time=%d",a2/n);
	printf("avg waiting time=%d",a3/n);
	printf("avg response time=%d",a4/n);
	}
