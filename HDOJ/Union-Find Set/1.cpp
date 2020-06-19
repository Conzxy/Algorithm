#include <iostream>
#include <string>
using namespace std;

const int maxsize=1e5;
int fa[maxsize];
string str[60];
int cnt=0;
int n,m;
int fields[11][4]={
{1,0,0,1},{1,1,0,0},{0,0,1,1},{0,1,1,0},
{1,0,1,0},{0,1,0,1},{1,1,0,1},{1,0,1,1},
{0,1,1,1},{1,1,1,0},{1,1,1,1}
};

void init(int n)       //初始化
{
    for(int i=0;i<n;i++)
      fa[i]=i;
}

int find(int x)        //查找父结点
{
    return (fa[x]==x)?x:(fa[x]=find(fa[x]));
}

void Union(int u,int v) //合并
{
    int uu=find(u);
    int vv=find(v);
    if(uu==vv)
      return ;
    else
      fa[vv]=uu;
}

int main()
{
    while(cin>>n>>m&&n>0&&m>0)     //n为行数，m为字母，n>=1,m<=50
    {
        init(n*m);
        for(int i=0;i<n;i++)
          cin>>str[i];

        for(int i=0;i<n;i++)
          for(int j=0;j<m;j++)
          {
            if(i!=n-1&&fields[str[i][j]-'A'][2]==1&&fields[str[i+1][j]-'A'][0]==1)
              Union(i*m+j,(i+1)*m+j);
            if(j!=m-1&&fields[str[i][j]-'A'][1]==1&&fields[str[i][j+1]-'A'][3]==1)
              Union(i*m+j,i*m+j+1);
          }
        for(int i=0;i<n*m;i++)
          if(fa[i]==i)
            cnt++;

        cout<<cnt<<endl;
        cnt=0;

    }

    return 0;

}
