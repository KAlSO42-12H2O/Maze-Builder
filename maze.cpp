#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod=1000000007;
const int dx[8]={-1,-1,-1,0,0,1,1,1},dy[8]={-1,0,1,-1,1,-1,0,1};
int n;
char s[505][505];
char dir[2005];
int cnt=0;
int main()
{
	
	printf("The size of your maze:\n");
	scanf("%d",&n);
	srand(time(0));
	int S=rand()%(n/3)+n/3,T=rand()%(n/3)+n/3;
	n=2*n-1;
	for(int i=1;i<=n;i++) s[i][1]=s[i][n]=s[1][i]=s[n][i]='#';
	
	
	if(T>S) for(int i=T;i>S;i--) dir[++cnt]='D';
    else for(int i=S;i>T;i--) dir[++cnt]='U';
    for(int i=1;i<=n-1;i++) dir[++cnt]='R';
    int ta=rand()%(n/3)+1;
    for(int i=1;i<=ta;i++) dir[++cnt]='L',dir[++cnt]='R';
    ta=rand()%(n/2)+1;
    for(int i=1;i<=ta;i++) dir[++cnt]='U',dir[++cnt]='D';
    random_shuffle(dir+1,dir+cnt+1);
    random_shuffle(dir+1,dir+cnt+1);
    random_shuffle(dir+1,dir+cnt+1);
//    printf("%s\n",dir+1);
	S=2*S-1,T=2*T-1;
    int cx=S,cy=1;
    int ax,ay;
    for(int i=1;i<=cnt;i++)
    {
    	switch(dir[i])
    	{
    		case 'R':ax=0,ay=1;break;
    		case 'L':ax=0,ay=-1;break;
    		case 'D':ax=1,ay=0; break;
    		case 'U':ax=-1,ay=0;break;
    		default:break;
		}
		s[cx][cy]='A';
		cx+=ax;
		cy+=ay;
		s[cx][cy]='A';
		cx+=ax;
		cy+=ay;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i][j]=='A') continue;
			bool ok=0;
			for(int k=0;k<8;k++)
			{
				if(s[i+dx[k]][j+dy[k]]=='A')
				{
					ok=1;
					break;
				}
			}
			if(ok) s[i][j]='#';
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(s[i][j]=='#') putchar('#');
			else
			{
				if(j==1&&i==S) putchar('S');
				else if(j==n&&i==T) putchar('T');
				else putchar('.');
			}
		}
		puts("");
	}
	return 0;
}

