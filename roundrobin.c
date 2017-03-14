#include<stdio.h>
#include<stdlib.h>
int main()
{
	int at[10],bt[10],i,n,time,rt[10],q,a,b,j,tat[10],ct[10],wt[10],rs[10],rest;
	char pr[10];
	printf("\t \tROUND ROBIN SCHEDULING\n\n");
	printf("Total no. of processes?\n ");
	scanf("%d",&n);
	rest=n;
	for(i=0;i<n;i++)
	{
		printf("Name of the process (in single letter)?\n");
		fflush(stdin);
		scanf("%c",&pr[i]);
		printf("Arrival time?\n");
		scanf("%d",&at[i]);
		printf("Burst time?\n");
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
	}
	printf("Quanta time : ?\n");
	scanf("%d",&q);
	for(time=0,i=0;rest!=0;)
	{
		if(rt[i]<=q && rt[i]>0)
		{	
			printf("%c:%d\n",pr[i],rt[i]);	
		//	rs[i]=time;
			time=time+rt[i];
			rt[i]=0;
			rs[i]=time;
			a=1;
		}
		else if(rt[i]>q)
		{
			printf("%c:%d\n",pr[i],rt[i]);
			rt[i]=rt[i]-q;
			a=0;
			time=time+q;
			rs[i]=time;
		}
		if(rt[i]==0 && a==1)
		{
			ct[i]=time;
			rest=rest-1;
		}
		if(i==n-1)
		{
			i=0;
		}
		else if(at[i+1]<=time)
		{
			i++;
		}
		else 
		{
			i=0;
		}
	}
	for(i=0;i<n;i++)
	{
	//ct[i]=time;
	tat[i]=ct[i]-at[i];
	wt[i]=tat[i]-bt[i];
	}
	j=0;
	b=0;
	a=0;
	printf("\t\nThe Gantt Chart is as follows:\n\n");
	printf("Process\t At\t Bt\t Ct\t Tat\t Wt\t Rs\t \n");
	for(i=0;i<n;i++)
	{
	printf("%c\t %d\t %d\t %d\t %d\t %d\t %d\t \n",pr[i],at[i],bt[i],ct[i],tat[i],wt[i],rs[i]);
	j=j+ct[i];
	b=b+tat[i];
	a=a+wt[i];
	}
	j=j/n;
	b=b/n;
	a=a/n;
	printf("~the Average Completion Time is :%d\n",j);
	printf("~the Average Turn Around Time is :%d\n",b);
	printf("~the Average Waiting Time is :%d\n",a);	
return 0;
}
