#include<stdio.h>
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,i,j;
		scanf("%d",&n);
		int a[n],prod[n],add[n];
		
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			if(i==0)
			{
				add[i]=prod[i]=a[i];
			}
			else
			{
				add[i]=add[i-1]+a[i];
				prod[i]=prod[i-1]*a[i];
			}
			
		}
		int count=0;
		for(i=0;i<n;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(add[j]-add[i]==prod[j]/prod[i])
				{
					count++;
					if(a[i]==1)
					{
						count--;
					}
				}
			}
		}
		count+=n;
		printf("%d\n",count);
	}
	return 0;
}
