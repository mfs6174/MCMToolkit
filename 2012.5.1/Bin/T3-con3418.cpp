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
const int fks=5;

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

struct RECT
{
  P zs,yx;
  double w,h;
  RECT(){}
  RECT(P a,P b)
  {
    zs=a;
    yx=b;
    w=yx.x-zs.x;
    h=zs.y-yx.y;
  }
  P mid()
  {
    return P(zs.x+w/2,yx.y+h/2);
  }
  RECT sub(int x,int y)
  {
    return RECT(P(zs.x+(x-1)*w/fks,yx.y+y*h/fks),P(zs.x+x*w/fks,yx.y+(y-1)*h/fks));
  }
};


int i,j,k,t,n,m;
double s;
D bian[1000];
P dian[1000],tp;
int ff[1000];
bool yong[1000];
double dd[100][100],mmd[20][20],md[20][20];
bool ji[30];
RECT houxuan[500];
RECT subr[20][200];

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

inline bool os(SEG &l,P &p) //点在线段上
{ 
  return( (cwz(cha(l.s,l.e,p))==0) &&( ( cwz((p.x-l.s.x)*(p.x-l.e.x))<=0 )&&( cwz((p.y-l.s.y)*(p.y-l.e.y))<=0 ) ) ); 
}

inline P scp(SEG l1,SEG l2) //线段交点 不考虑（部分）重合的数据 fail表示不相交
{
  P rr;
  rr=lcp(l1.s,l1.e,l2.s,l2.e);
  if (!fail)
    if (os(l1,rr)&&os(l2,rr))
      return rr;
  fail=true;
  return P(0,0);
}
bool xj[100][100];
double mm=620,dm=0;
int zhan[100],rz[100];
D rrz[100],rrrz[100];
int zc=0,mt=0,cct=0,ct=0,ccct=0,cccct;
bool fl1;
int mk;
P xd[20];

void dfs(int x)
{
   if (dm>mm)
     return;
  if (x>m)
  {
    // if (! (ji[9]&&ji[10]&&ji[11]&&ji[12]) )
    //   return;
    memcpy(mmd,md,sizeof(mmd));
    for (int k=1;k<=n;k++)
      for (int i=1;i<=n;i++)
        for (int j=1;j<=n;j++)
          if (mmd[i][k]<INF&&mmd[k][j]<INF)
            if (mmd[i][k]+mmd[k][j]<mmd[i][j])
              mmd[i][j]=mmd[i][k]+mmd[k][j];
    fl1=true;
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
    if (fl1 && dm<mm)
    {
      memcpy(rz,zhan,sizeof(rz));
      cct=zc;
      mm=dm;
    }
    return;
  }
  fl1=true;
  for (int i=1;i<=zc;i++)
    if (xj[zhan[i]][x])
    {
      fl1=false;
      break;
    }
  if (fl1)
  {
    zc++;
    zhan[zc]=x;
    dm+=bian[x].l;
    double t=md[bian[x].a][bian[x].b];
    bool t1=ji[bian[x].a],t2=ji[bian[x].b];
    ji[bian[x].a]=ji[bian[x].b]=true;
    md[bian[x].b][bian[x].a]=md[bian[x].a][bian[x].b]=min(t,bian[x].l);
    dfs(x+1);
    ji[bian[x].a]=t1;ji[bian[x].b]=t2;
    zc--;
    dm-=bian[x].l;
    md[bian[x].b][bian[x].a]=md[bian[x].a][bian[x].b]=t;
  }
  dfs(x+1);
}

bool ispnt[10];
P fixp[10];
int ite;
double rsc,mmm;
int shixuan[20],rsx[20];

inline bool getbac()
{
  ite++;
  if (ite>1)
    return false;
  else
    return true;
}

void dfs0(int x,int ls)
{
  if (x>mk)
  {
    int i,j;
    //生成可行边
    for (i=1;i<=n;i++)
      for (j=i+1;j<=n;j++)
        dd[i][j]=dd[j][i]=dst(dian[i],dian[j]);
    m=0;
    for (i=1;i<=3;i++)
      for (j=9;j<=n;j++)
      {
        m++;
        bian[m].a=i;bian[m].b=j;
        bian[m].l=dd[i][j];
      }
    for (i=5;i<=7;i++)
      for (j=9;j<=n;j++)
      {
        m++;
        bian[m].a=i;bian[m].b=j;
        bian[m].l=dd[i][j];
      }
    for (i=9;i<=n;i++)
      for (j=i+1;j<=n;j++)
      {
        m++;
        bian[m].a=i;bian[m].b=j;
        bian[m].l=dd[i][j];
      }
    for (i=1;i<=3;i++)
      for (j=5;j<=7;j++)
      {
        m++;
        bian[m].a=i;bian[m].b=j;
        bian[m].l=dd[i][j];
      }
    //额外的边
    // m++;
    // bian[m].a=8;bian[m].b=1;
    // bian[m].l=dd[1][8];
    // // m++;
    // // bian[m].a=8;bian[m].b=7;
    // // bian[m].l=dd[7][8];
    // m++;
    // bian[m].a=4;bian[m].b=3;
    // bian[m].l=dd[3][4];
    // m++;
    // bian[m].a=4;bian[m].b=5;
    // bian[m].l=dd[4][5];
    
    // for (i=9;i<=n;i++)
    // {
    //   m++;
    //   bian[m].a=8;bian[m].b=i;
    //   bian[m].l=dd[i][8];
    //   m++;
    //   bian[m].a=4;bian[m].b=i;
    //   bian[m].l=dd[i][4];
    // }
    //相交预处理
    memset(xj,0,sizeof(xj));
    for (i=1;i<=m;i++)
      for (j=i+1;j<=m;j++)
      {
        if (bian[i].a==bian[j].a||bian[i].b==bian[j].b||bian[i].b==bian[j].a||bian[i].a==bian[j].b)
        {
          xj[i][j]=xj[j][i]=false;
          continue;
        }
        tp=scp(SEG(dian[bian[i].a],dian[bian[i].b]),SEG(dian[bian[j].a],dian[bian[j].b]));
        if (fail)
          xj[i][j]=xj[j][i]=false;
        else
          xj[i][j]=xj[j][i]=true;
      }
    //搜索初始化并搜索
    dm=dd[3][4]+dd[1][8];
    //dm=0;
    mm=min(rsc,mmm);
    zc=0;
    memset(ji,0,sizeof(ji));
    dfs(1);
    if (mm<mmm)
    {
      mmm=mm;
      memcpy(rsx,shixuan,sizeof(rsx));
      for (int i=1;i<=cct;i++)
        rrz[i]=bian[rz[i]];
      ccct=cct;
    }
    return;
  }
  if (ispnt[x])
  {
    dian[8+x]=fixp[x];
    dfs0(x+1,ls);
    return;
  }
  for (int i=ls+1;i<=fks*fks;i++)
  {
    dian[8+x]=subr[x][i].mid();
    shixuan[x]=i;
    dfs0(x+1,i);
  }
}

int main()
{
  //ispnt[3]=true;
  freopen("park11.in","r",stdin);
  for (i=1;i<=8;i++)
    dian[i].input();
  cin>>mk;
  for (i=1;i<=mk;i++)
  {
    if (!ispnt[i])
    {
      dian[9].input();
      dian[10].input();
      houxuan[i]=RECT(dian[9],dian[10]);
    }
    else
      fixp[i].input();
  }
  n=8+mk;m=0;
  //构造初始矩阵
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
      if (i==j)
        md[i][j]=0;
      else
        md[i][j]=INF;
  for (i=1;i<=8;i++)
    for (j=i+1;j<=8;j++)
      if (dian[i].x==dian[j].x||dian[i].y==dian[j].y)
        md[i][j]=md[j][i]=dst(dian[i],dian[j]);  
  md[1][8]=min(md[1][8],45.0);
  md[8][1]=md[1][8];
  md[7][8]=min(md[7][8],85.0);
  md[8][7]=md[7][8];
  md[4][5]=min(md[4][5],130.0);
  md[5][4]=md[4][5];
  md[3][4]=min(md[3][4],90.0);
  md[4][3]=md[3][4];
  md[3][4]=md[4][3]=dst(dian[3],dian[4]);
  md[1][8]=md[8][1]=dst(dian[1],dian[8]);
  rsc=380;
  mmm=INF;
  while (getbac())
  {
    //产生子区域
    for (k=1;k<=mk;k++)
      if (!ispnt[k])
        for (i=1;i<=fks;i++)
          for (j=1;j<=fks;j++)
            subr[k][((i-1)*fks+j-1)+1]=houxuan[k].sub(i,j);
    mmm=INF;
    dfs0(1,0);
    //更新区域
    for (i=1;i<=mk;i++)
      if (!ispnt[i])
        houxuan[i]=subr[i][rsx[i]];
    if (mmm<rsc)
    {
      rsc=mmm;
      memcpy(rrrz,rrz,sizeof(rrrz));
      cccct=ccct;
      for (i=1;i<=mk;i++)
        if (!ispnt[i])
          xd[i]=houxuan[i].mid();
        else
          xd[i]=fixp[i];
    }
  }
  // for (k=1;k<=n;k++)
  //   for (i=1;i<=n;i++)
  //     for (j=1;j<=n;j++)
  //       if (md[i][k]<INF&&md[k][j]<INF)
  //         if (md[i][k]+md[k][j]<md[i][j])
  //           md[i][j]=md[i][k]+md[k][j];
  // for (int i=1;i<=8;i++)
  //   for (int j=i+1;j<=8;j++)
  //     cout<<i<<' '<<j<<"   "<<md[i][j]<<' '<<dd[i][j]<<' '<<md[i][j]/dd[i][j]<<endl;
  // cout<<endl;
  printf("%.3lf\n",rsc);
  for (i=1;i<=mk;i++)
    printf("%.3lf  %.3lf\n",xd[i].x,xd[i].y);
  for (i=1;i<=cccct;i++)
    printf("%d %d\n",rrrz[i].a,rrrz[i].b);
  return 0;
}

  
