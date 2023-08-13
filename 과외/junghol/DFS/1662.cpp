#include<stdio.h>

int n,inp[50][50],check[50],ans;

void back(int a,int cnt)
{
    if(a==2*n)
    {
        if(cnt>ans) ans=cnt;
        return;
    }
    int r=a,c=1,f=0;
    if(a>n) r=n,c+=(a-n);


    for(;r>=1 && c<=n;r--,c++)
    {
        if(check[r-c+n] || inp[r][c]==0) continue;
        check[r-c+n]=1; f=1;
        back(a+1,cnt+1);
        check[r-c+n]=0;
    }
    if(f==0) back(a+1,cnt);
}

int main()
{
//    freopen("input.txt","r",stdin);
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&inp[i][j]);
        }
    }

    back(1,0);
    printf("%d",ans);
    return 0;
}