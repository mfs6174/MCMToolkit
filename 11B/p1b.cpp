/*
ID: mfs6174
email: mfs6174@gmail.com
PROG: P1A
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<deque>
#include<iomanip>
#include<cmath>
#include<set>
#define sf scanf
#define pf printf
#define llg long long 

using namespace std;
ifstream inf("data1.txt");
ifstream infb("data3.txt");
ifstream inf5("data5.txt");
ofstream ouf("rs3.csv");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

struct D
{
  int h,q,c;
  double x,y,r;
  bool f;
  int dao[1000];
};

int i,j,k,t,n,m,q,tt;
double tu[1000][1000],d[1000][1000];
D dian[1000];
double mint[1000],rt[1000];
int tong[1000],shu[1000];
vector<int> guan[1000];
int you[1000];
vector<double> pai;

inline double dst(D &a,D &b)
{
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

inline double gettime(double d)
{
  return d/10.0;
}

void floyd(int a,int n)
{
  int i,j,k,t;
  for (i=a;i<=n;i++)
    for (j=a;j<=n;j++)
      d[i][j]=tu[i][j];
  for (k=a;k<=n;k++)
    for (i=a;i<=n;i++)
      for (j=a;j<=n;j++)
        if (d[i][k]!=maxlongint&&d[k][j]!=maxlongint)
        {
          t=d[i][k]+d[k][j];
          if (t<d[i][j])
            d[i][j]=t;
        }
}
int duiz[1000],duiy[1000];
bool yong[1000];

bool xiong(int x)
{
  int i,tt;
  //进入的点都是左点
  for (i=1;i<=dian[x].c;i++)//遍历所连所有右点
  {
    tt=dian[x].dao[i];
    if ((!yong[tt])&&(duiy[tt]!=x))//未重复出现且没有和此点匹配（保证交替1）
    {
      yong[tt]=true;
      if ((!duiy[tt])||xiong(duiy[tt]))//如果是未匹配点，可作为终点，否则顺着它匹配的左点找增广轨（保证交替2），如果找到：
      {
        duiz[x]=tt;
        duiy[tt]=x;//连接左右，右与原匹配的边自动删除
        return true;
      }
    }
  }
  return false;//木有找到增广轨
}

bool check(double ma)
{
  int i,j;
  for (i=1;i<=20;i++)
  {
    dian[i].c=0;
    for (j=1;j<=q;j++)
      if (d[i][you[j]]<=ma)
      {
        dian[i].c++;
        dian[i].dao[dian[i].c]=j;
      }
  }
  memset(duiz,0,sizeof(duiz));
  memset(duiy,0,sizeof(duiy));
  int cc=0;
  for (i=1;i<=20;i++)
    if (!duiz[i])
    {
      memset(yong,0,sizeof(yong));
      if (xiong(t))//找到增广轨
          cc++;//匹配数+1
	}
  if (cc>=13)
    return true;
  else
    return false;
} 

int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      tu[i][j]=maxlongint;
  for (i=1;i<=n;i++)
  {
    inf>>dian[i].x>>dian[i].y;
    inf5>>dian[i].r;
  }
  infb>>m;
  for (i=1;i<=m;i++)
  {
    infb>>t>>tt;
    tu[t][tt]=tu[tt][t]=dst(dian[t],dian[tt]);
  }
  inf5>>q;
  for (i=1;i<=q;i++)
    inf5>>you[i];
  floyd(1,n);
  for (i=1;i<=20;i++)
    for (j=1;j<=q;j++)
      pai.push_back(d[i][you[j]]);
  sort(pai.begin(),pai.end());
  for (i=0;i<pai.size();i++)
    if (check(pai[i]))
    {
      mint[0]=pai[i];
      break;
    }
  cout<<mint[0]<<endl;
  for (i=1;i<=q;i++)
    ouf<<you[i]<<';'<<duiy[i]<<';'<<fixed<<setprecision(2)<<d[you[i]][duiy[i]]<<endl;
  return 0;
}

