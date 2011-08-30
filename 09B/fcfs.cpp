/*
ID: mfs6174
email: mfs6174@gmail.com
PROG: FCFS
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
#include<ctime>
#define sf scanf
#define pf printf
#define llg long long 

using namespace std;
ifstream inf("data1.in");
ofstream ouf("ren1.out");
ofstream ouf1("tian1.out");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;
const int d12=39703;
struct BR
{
  int mz,ry,sh,shh,cy;
  int ty,tm;
  bool ff;
  int h;
  bool operator <(const BR &b)
  {
    return tm>b.ym;
  }
};

int i,j,k,y,n,m,zu,pp;
int time,zhou;
int wsh[10]={0,1,1,2,2,1};
int ed;
int cwz,cws,cc,cr,cs,yzr,ws;//等待住院人数 等待手术人数 出院人数 入院人数 手术人数 医院中人数 转院人数


BR mz[500],zhan[500];
priority_queue<BR> ry,sh,cy,wsdd;
vector<BR> shc;

int getzhou(int x)
{
  x++;
  if (x==8) x=1;
  return x;
}

void dayintian()
{
  ouf1<<time<<';'<<yzr<<';'<<cr<<';'<<cc<<';'<<cs<<';'<<cwz<<';'<<cws<<endl;
}

int getcy(int tp)
{
  int t;
  if (tp==1)
  {
    return t;
  }
  if (tp==2)
  {
    return t;
  }
  if (tp==3)
  {
    return t;
  }
  if (tp==4)
    return t;
  return t;
}

void dayinren(const BR &a)
{
  ouf<<a.ty<<';'<<a.mz<<';'<<a.ry<<';'<<a.sh<<';'<<a.shh<<';'<<a.cy<<endl;
}

void read()
{
  inf>>zu;
  int i,tt;
  for (i=1;i<=zu;i++)
  {
    inf>>zhan[i].ty>>zhan[i].mz>>zhan[i].ry>>zhan[i].sh>>zhan[i].shh;
    if (zhan[i].ty==2)
      tt=zhan[i].shh;
    else
      tt=zhan[i].sh;
    if (tt<d12)
    {
      tt+=getcy(zhan[i].ty);
      zhan[i].cy=tt;
      zhan[i].tm=tt;
      cy.push(zhan[i]);
      continue;
    }
    zhan[i].ff=true;
    zhan[i].tm=zhan[i].sh;
    sh.push(zhan[i]);
  }
  inf>>zu;
  for (i=1;i<=zu;i++)
    inf>>mz[i].ty>>mz[i].mz;
}

void chuyuan()
{
  BR cao;
  cc=0;
  while (!cy.empty())
  {
    cao=cy.top();
    if (cao.cy>time)
      break;
    cc++;
    cy.pop();
    if (!cao.cy<d12)
      cao.cy=time;
    dayinren(cao);
    yzr--;
  }
}

void menzhen()
{
  for (pp;pp<=zu;pp++)
  {
    if (mz[pp].mz>time)
      break;
    if (mz[pp].ty==5)
    {
      mz[pp].tm=mz[pp].mz+1;
      wsdd.push(mz[pp]);
      continue;
    }
    mz[pp].tm=mz[pp].mz;
    ry.push(mz[pp]);
  }
  
}

void ruyuan()
{
  BR tt;
  cr=0;
  while (!wsdd.empty())
  {
    if (wsdd.top.tm>time)
      break;
    if (yzr>=79)
    {
      ws++;
      wsdd.pop();
      continue;
    }
    tt=wsdd.top;
    wsdd.pop();
    tt.ry=time;tt.sh=time+1;
    tt.tm=tt.sh;
    sh.push(tt);
    yzr++;cr++;
  }
  while ((!ry.empty())&&(yzr<79))
  {
    tt=ry.top();
    if (tt.mz+1<time)
      break;//不允许当天入院
    ry.pop();
    tt.ry=time;tt.tm=time+wsh[tt.ty];
    sh.push(tt);
    yzr++;cr++;
  }
  cwz=ry.size()+wsdd.size();
}

void shoushu()
{
  bool sw=false;
  cs=0;
  shc.clear();
  while (!sh.empty())
  {
    if (sh.top.tm>time)
      break;
    shc.push_back(sh.top());
    sh.pop();
  }
  vector<BR>::iterator i=shc.begin();
  BR tt;
  for (i;i!=shc.end();i++)
  {
    tt=*i;
    if (tt.ff)
    {
      i=shc.erase(i);
      cs++;
    }
  }
  
  if (zhou==1)
  {
    return;
  }
  if (zhou==3)
  {
    return;
  }
}

int main()
{
  srand(time(NULL));
  read();
  time=d12;zhou=5;yzr=79;pp=1;
  for (time;time<=ed;time++,zhou=getzhou(zhou))
  {
    chuyuan();
    menzhen();
    ruyuan();
    shoushu();
    dayintian();
  }
  return 0;
}

