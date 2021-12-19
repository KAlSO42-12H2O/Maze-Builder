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
	int S=rand()%(n-3)+2,T=rand()%(n-3)+2;
	
//	printf("S=%d T=%d\n",S,T);
	
	if(T>S) for(int i=T;i>S;i--) dir[++cnt]='D';
    else for(int i=S;i>T;i--) dir[++cnt]='U';
    for(int i=1;i<=n-1;i++) dir[++cnt]='R';
    n=2*n-1;
	for(int i=1;i<=n;i++) s[i][1]=s[i][n]=s[1][i]=s[n][i]='#';
    int ta=rand()%(n/3)+1;
    for(int i=1;i<=ta;i++) dir[++cnt]='L',dir[++cnt]='R';
    ta=rand()%(n/3)+1;
    for(int i=1;i<=ta;i++) dir[++cnt]='U',dir[++cnt]='D';
    random_shuffle(dir+1,dir+cnt+1);
    random_shuffle(dir+1,dir+cnt+1);
    random_shuffle(dir+1,dir+cnt+1);
    for(int i=1;i<cnt;i++)
    {
    	if(dir[i]+dir[i+1]=='L'+'R'||dir[i]+dir[i+1]=='U'+'D')
    	{
    		dir[i]=dir[i+1]='X';
		}
	}
//    printf("%s\n",dir+1);
	S=2*S-1,T=2*T-1;
    int cx=S,cy=1;
    int ax,ay;
    int uu=0,dd=0,rr=0,LL=0;
    while(dir[cnt]=='X') cnt--;
    for(int i=1;i<=cnt;i++)
    {
    	ax=ay=0;
    	switch(dir[i])
    	{
    		case 'R':if(LL) LL--; else ax=0,ay=1;break;
    		case 'L':if(rr) rr--; else ax=0,ay=-1;break;
    		case 'D':if(uu) uu--; else ax=1,ay=0; break;
    		case 'U':if(dd) dd--; else ax=-1,ay=0;break;
    		default:ax=ay=0;break;
		}
		if(!ax&&!ay) continue;
		cx+=2*ax;
		cy+=2*ay;
		bool ok=1;
		if(cx<1||cy<1||cx>n||cy>n)
		{
			switch(dir[i])
	    	{
	    		case 'R':ok=0,rr++;break;
	    		case 'L':ok=0,LL++;break;
	    		case 'D':ok=0,dd++; break;
	    		case 'U':ok=0,uu++;break;
	    		default:break;
			}
		}
		cx-=2*ax;
		cy-=2*ay;
		if(ok)
		{
			s[cx][cy]='A';
			cx+=ax;
			cy+=ay;
			s[cx][cy]='A';
			cx+=ax;
			cy+=ay;
		}
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
			if(j==1&&i==S) putchar('S');
			else if(j==n&&i==T) putchar('T');
			else
			if(s[i][j]=='#') putchar('#');
			else
			{
				putchar('.');
			}
		}
		puts("");
	}
	return 0;
}
