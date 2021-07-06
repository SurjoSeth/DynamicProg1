#import <stdio.h>
void swap(float *xp, float *yp)
{
    float temp = *xp;
    *xp = *yp;
    *yp = temp;
}
void fill(int n,float w[],float p[],float r[])
{
	int i,j;
	printf("Enter the weights of the items \n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&w[i]);	
	}
	printf("Enter the profits of the items \n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&p[i]);	
	}
	for(i=0;i<n;i++)
	{
		r[i]=p[i]/w[i];
	}
	for (i = 0; i < n-1; i++)     
 	{	
       for (j = 0; j < n-i-1; j++)
        {
        	if (r[j] < r[j+1])
            {
				swap(&r[j], &r[j+1]);
				swap(&p[j], &p[j+1]);
				swap(&w[j], &w[j+1]);
			}
		}
	}
}
void greedy(float x[],float w[],float m,int n)
{
	int i;
	float u=m;
	for(i=0;i<n;i++)
	{
		x[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(w[i]>u)
		{
			x[i]=u/w[i];
			break;
		}
		x[i]=1.0;
		u=u-w[i];
	}
}
float profit(float x[],float p[],int n)
{	
	int i;
	float P=0.0;
	for(i=0;i<n;i++)
	{
		P=P+(p[i]*x[i]);
	}
	return P;
}
int main()
{	
	float p[20],w[20],m;
	int n;
	float x[20],r[20];
	printf("enter number of items: \n");
	scanf("%d",&n);
	printf("enter the capacity: \n");
	scanf("%f",&m);
	fill(n,w,p,r);
	greedy(x,w,m,n);
	printf("the profit is %f",profit(x,p,n));
}
	
