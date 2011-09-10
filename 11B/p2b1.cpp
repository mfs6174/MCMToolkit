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
ifstream inf4("data4.txt");
ofstream ouf("rs9.csv");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;
const int P=32;

struct D
{
  int h,q,c;
  double x,y,r;
  bool f;
  int dao[1000];
};

int i,j,k,t,n,m,mz,tt,cc;
double tu[1000][1000],d[1000][1000];
D dian[1000];
double mint[1000][1000],rt[1000];
int tong[1000],shu[1000];
vector<int> guan[1000];
int qu[10][3]={{0},{1,20},{93,100},{166,182},{320,328},{372,386},{475,485}};
int jie[10]={0,92,73,154,52,103,108};
int shi[1000];
vector<int> dang,jian;
bool zai[1000],keyd[1000];
int zuo[1000],you[1000],duiz[1000],duiy[1000];
bool yong[1000];
bool fl;

inline double dst(D &a,D &b)
{
  return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int celi(double x)
{
  int t=(int)x;
  if (abs(x-t)>1e-6)
    return t+1;
  else
    return t;
}

inline double gettime(double d)
{
  return d/10.0;
}
inline int getnum(int x)
{
  int i,m=0;
  for (i=1;i<=5;i++)
  {
    if (x>m&&x<=m+jie[i])
      return i;
    m+=jie[i];
  }
  return i;
}

void floyd(int a,int n)
{
  int i,j,k;
  double t;
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

void solve(int li)
{
  int i,j,k,t;
  dang.clear();jian.clear();
  memset(keyd,0,sizeof(keyd));
  memset(zai,0,sizeof(zai));
  memset(duiz,0,sizeof(duiz));
  memset(duiy,0,sizeof(duiy));
  memset(zuo,0,sizeof(zuo));
  cc=0;
  for (i=1;i<=n;i++)
    if (d[P][i]<=li)
    {
      zai[i]=true;
      dang.push_back(i);
    }
  for (i=0;i<dang.size();i++)
    for (j=1;j<=n;j++)
      if ((!zai[j])&&tu[dang[i]][j]!=maxlongint)
      {
        keyd[dang[i]]=true;
        cc++;zuo[cc]=dang[i];
        jian.push_back(dang[i]);
      }
  for (i=0;i<cc;i++)
  {
    t=jian[i];
    dian[t].c=0;
    for (j=1;j<=6;j++)
      for (k=qu[j][0];k<=qu[j][1];k++)
        if (mint[k][t]+3<=mint[P][t])
        {
          dian[t].c++;
          dian[t].dao[dian[t].c]=k;
        }
  }
  int rr=0;
  for (i=1;i<=cc;i++)
  {
    t=zuo[i];
    if (!duiz[t])
    {
      memset(yong,0,sizeof(yong));
      if (xiong(t))//找到增广轨
          rr++;//匹配数+1
	}
  }
  if (rr>=cc)
  {
    fl=true;
    return;
  }
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
    inf4>>dian[i].r;
    tu[i][i]=0;
  }
  infb>>m;
  for (i=1;i<=m;i++)
  {
    infb>>t>>tt;
    tu[t][tt]=tu[tt][t]=dst(dian[t],dian[tt]);
  }
  floyd(1,n);
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      mint[i][j]=gettime(d[i][j]);
  j=1;
  for (i=1;i<=n;i++)
    if (i!=P)
      shi[j++]=d[P][i];
  sort(&shi[1],&shi[n]);
  int la=0;
  for (k=1;k<n;k++)
    if (celi(shi[k])!=la)
    {
      la=celi(shi[k]);
      solve(la);
      if (fl)
      {
        cout<<dang.size()<<endl;
        ouf<<dang.size()<<endl;
        ouf<<cc<<endl;
        for (i=1;i<=cc;i++)
          ouf<<zuo[cc]<<';'<<duiz[zuo[cc]]<<endl;
        break;
      }
    }
  return 0;
}

