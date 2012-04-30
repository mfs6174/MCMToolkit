/*
ID: mfs6174
email: mfs6174@gmail.com
PROG: ti
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
//ifstream inf("ti.in");
//ofstream ouf("ti.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

struct D
{
  double l;
  int a,b;
  bool operator<(const D &x) const
  {
    return l<x.l;
  }
};

const double INF=1e200;
const double Ling=1e-8;
bool fail;

inline int cwz(double x)
{
  if (abs(x)<Ling)
    return 0;
  else
    return (x>0)?1:-1;
}

struct P 
{ 
  double x; 
  double y;
  //constructor
  P(double a=0, double b=0) 
  { x=a; y=b;}
  P operator+(const P &b) const
  {  
    return P(x + b.x, y + b.y);  
  }
  P operator - (const P &b) const
  {  
    return P(x - b.x, y - b.y);  
  }  
  bool operator<(const P &b) const//a在b逆时针 
  {   
    return x * b.y < y * b.x;  
  }
  bool operator==(const P &b) const
  {
    return ((cwz(x-b.x)==0)&&(cwz(y-b.y)==0));
  }
  double operator ^ (const P &b) const //aXb
  {
    return x*b.y-b.x*y;
  }
  double operator *(const P &b) const
  {
    return x*b.x+y*b.y;
  }
  void input()
  {
    scanf("%lf%lf",&x,&y);
  }

}; 

struct SEG 
{ 
  P s,e; 
  SEG(P a=P(0,0), P b=P(0,0)) { s=a; e=b;}
  void input()
  {
    s.input();e.input();
  }
}; 

int i,j,k,t,n,m,mk,tt;
double s;
D bian[1000];
P dian[1000];
int ff[1000];
bool yong[1000];
double dd[100][100],md[100][100],mmd[100][100];

inline double sqr(double x)
{
  return x*x;
}

inline double dst(P p1,P p2)                
{ 
  return( sqrt( (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y) ) ); 
}

inline double cha(P a,P b,P c)
{
  return (b-a)^(c-a);
}

P lcp(P aa, P ad, P ba, P bd)//返回fail如果true说明平行或重合再交叉相减叉积即可
{ // 求直线交点  
  ad = ad - aa;  
  bd = bd - ba;  
  double tmp = bd ^ ad;
  fail=false;
  if (cwz(tmp)==0)
  {
    fail=true;
    return P(0,0);
  }
  else
    return P((ad.x * bd.x * (ba.y - aa.y) + aa.x * bd.x * ad.y - ba.x * ad.x * bd.y) / tmp,  
             (ad.y * bd.y * (aa.x - ba.x) + ba.y * ad.y * bd.x - aa.y * bd.y * ad.x) / tmp);  
}  

void init(int n)
{
  int i;
  for (i=1;i<=n;i++)
    ff[i]=i;
}

int cha(int x)
{
	if (ff[x]==x)
		return x;
	ff[x]=cha(ff[x]);
	return ff[x];
}

void bing(int x,int y)
{
	int i,j;
	i=cha(x);j=cha(y);
	if (i!=j)
	ff[i]=j;//总根为标志，把总根挂到另一个的总根下
}

P t1,t2,r1,r2;
int ox,oy,px,py;
const double prec=1;
double mm;
int main()
{
  freopen("park.in","r",stdin);
  for (i=1;i<=8;i++)
    dian[i].input();
  freopen("2-r.txt","r",stdin);
  cin>>mk;
  for (i=1;i<=mk;i++)
    dian[8+i].input();
  t1=dian[9];t2=dian[10];
  n=8+mk;
  cin>>m;
  for (i=1;i<=m;i++)
    cin>>bian[i].a>>bian[i].b;
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      if (i==j)
        md[i][j]=0;
      else
        md[i][j]=INF;
  for (i=1;i<=8;i++)
    for (j=i+1;j<=8;j++)
      if (dian[i].x==dian[j].x||dian[i].y==dian[j].y)
      {
        dd[i][j]=dd[j][i]=dst(dian[i],dian[j]);
        md[i][j]=md[j][i]=dd[i][j];
      }
  md[1][8]=min(md[1][8],45.0);
  md[8][1]=md[1][8];
  md[7][8]=min(md[7][8],85.0);
  md[8][7]=md[7][8];
  md[4][5]=min(md[4][5],130.0);
  md[5][4]=md[4][5];
  md[3][4]=min(md[3][4],90.0);
  md[4][3]=md[3][4];
  for (i=1;i<=8;i++)
    for (j=i+1;j<=8;j++)
      dd[i][j]=dst(dian[i],dian[j]);
  mm=360;
  for (ox=-20*(1/prec);ox<=20*(1/prec);ox++)
    for (oy=-20*(1/prec);oy<=20*(1/prec);oy++)
      for (px=-20*(1/prec);px<=20*(1/prec);px++)
        for (py=-20*(1/prec);py<=20*(1/prec);py++)
        {
          // if (ox==0&&oy==0&&px==0&&py==0)
          //   s=0;
          s=0;
          dian[9]=t1+P(ox,oy);
          dian[10]=t2+P(px,py);
          for (i=1;i<=m;i++)
          {
            md[bian[i].a][bian[i].b]=md[bian[i].b][bian[i].a]=dst(dian[bian[i].a],dian[bian[i].b]);
            s+= dst(dian[bian[i].a],dian[bian[i].b]);
          }
          if (s>=mm)
            continue;
          memcpy(mmd,md,sizeof(mmd));
          for (k=1;k<=n;k++)
            for (i=1;i<=n;i++)
              for (j=1;j<=n;j++)
                if (mmd[i][k]<INF&&mmd[k][j]<INF)
                  if (mmd[i][k]+mmd[k][j]<mmd[i][j])
                    mmd[i][j]=mmd[i][k]+mmd[k][j];
          bool fl1=true;
          if (mmd[3][4]>1.4*dd[3][4] || mmd[1][8]>1.4*dd[1][8])
            fl1=false;
          if (fl1)
            for (i=1;i<=3;i++)
              for (j=5;j<=7;j++)
                if (mmd[i][j]>1.4*dd[i][j])
                {
                  fl1=false;
                  break;
                }
          if (fl1)
          {
            mm=s;
            r1=dian[9];
            r2=dian[10];
          }
        }
  // printf("%.3lf\n",mm);
  // printf("%.3lf %.3lf\n",r1.x,r1.y);
  // printf("%.3lf %.3lf\n",r2.x,r2.y);
  s=0;
  dian[9]=r1;
  dian[10]=r2;
  for (i=1;i<=m;i++)
    md[bian[i].a][bian[i].b]=md[bian[i].b][bian[i].a]=dst(dian[bian[i].a],dian[bian[i].b]);
  memcpy(mmd,md,sizeof(mmd));
  for (k=1;k<=n;k++)
    for (i=1;i<=n;i++)
      for (j=1;j<=n;j++)
        if (mmd[i][k]<INF&&mmd[k][j]<INF)
          if (mmd[i][k]+mmd[k][j]<mmd[i][j])
            mmd[i][j]=mmd[i][k]+mmd[k][j];
  for (int i=1;i<=8;i++)
    for (int j=i+1;j<=8;j++)
      cout<<i<<' '<<j<<"   "<<mmd[i][j]<<' '<<dd[i][j]<<' '<<mmd[i][j]/dd[i][j]<<';'<<endl; 
  return 0;
}

  
