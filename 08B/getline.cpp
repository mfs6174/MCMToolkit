/*
ID: mfs6174
email: mfs6174@gmail.com
PROG: 旋转卡尺法求公切线
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
ifstream inf("data3.txt");
ofstream ouf("data5.txt");
ofstream ouf1("data6.txt");
ofstream ouf2("data7.txt");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;

int i,j,k,n,m;
double t;

const double Ling=1e-8;

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
  double operator ^ (const P &b) const //aXb
  {
    return x*b.y-b.x*y;
  }
  void print(int p)
  {
    ouf2<<p<<endl;
    ouf2<<x<<' '<<y<<endl<<endl;
  }
};
P yuan[10][500];
P xian;
int c[10];
bool fl;
int o,p;
P a1[10][10];
P a2[10][10];
double kk[10][10];
double bb[10][10];
bool fail;
P cp;

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

int main()
{
  inf>>n;
  for (i=1;i<=n;i++)
  {
    inf>>c[i];
    for (j=1;j<=c[i];j++)
      inf>>yuan[i][j].x;
    for (j=1;j<=c[i];j++)
      inf>>yuan[i][j].y;
  }
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      if (i==j)
        continue;
      o=1;p=1;
      fl=true;
      xian=yuan[j][p]-yuan[i][o];
      while (fl)
      {
        fl=false;
        for (k=1;k<=c[j];k++)
        {
          t=(yuan[j][k]-yuan[i][o])^xian;
          if (cwz(t)<0)
          {
            p=k;
            xian=yuan[j][p]-yuan[i][o];
            fl=true;
          }
        }
        for (k=1;k<=c[i];k++)
        {
          t=(yuan[i][k]-yuan[i][o])^xian;
          if (cwz(t)<0)
          {
            o=k;
            xian=yuan[j][p]-yuan[i][o];
            fl=true;
          }
        }
      }
      a1[i][j]=yuan[i][o];
      a2[i][j]=yuan[j][p];
      kk[i][j]=(yuan[j][p].y-yuan[i][o].y)/(yuan[j][p].x-yuan[i][o].x);
      bb[i][j]=yuan[j][p].y-kk[i][j]*yuan[j][p].x;
    }
  for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    {
      if (i==j)
        continue;
      ouf1<<i<<' '<<j<<endl;
      ouf1<<a1[i][j].x<<' '<<a1[i][j].y<<endl;
      ouf1<<a2[i][j].x<<' '<<a2[i][j].y<<endl;
      ouf1<<"y="<<kk[i][j]<<"*x";
      if (bb[i][j]>0)
        ouf1<<'+';
      ouf1<<bb[i][j]<<endl<<endl;
      ouf<<kk[i][j]<<' '<<bb[i][j]<<endl;
    }
  cp=lcp(a1[1][3],a2[3][1],a1[1][4],a2[4][1]);
  cp.print(1);
  cp=lcp(a1[2][1],a2[1][2],a1[2][5],a2[5][2]);
  cp.print(2);
  cp=lcp(a2[1][3],a1[3][1],a1[3][5],a2[5][3]);
  cp.print(3);
  cp=lcp(a1[4][1],a2[1][4],a1[4][5],a2[5][4]);
  cp.print(4);
  cp=lcp(a1[5][3],a2[3][5],a1[5][4],a2[4][5]);
  cp.print(5);
  return 0;
}

