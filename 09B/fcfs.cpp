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
ifstream inf("data1.txt");
ofstream ouf("ren1.txt");
ofstream ouf1("tian1.txt");
//freopen("ti.in","r",stdin);
const int maxlongint=2147483647;
const int d12=39703;
struct BR
{
  int mz,ry,sh,shh,cy;
  int ty,tm;
  bool ff;
  int h;
  bool operator <(const BR &b) const 
  {
    return tm>b.tm;
  }
};

int i,j,k,y,n,m,zu,pp;
int shi,zhou;
int wsh[10]={0,1,1,2,2,1};
double gai[10][30]={{0,0,0.29,0.51,0.20},{0,0,0.20,0.65,0.15},{0,0,0.00,0.00,0.02,0.05,0.07,0.24,0.29,0.20,0.05,0.05,0.02},{0,0,0.00,0.00,0.00,0.02,0.03,0.07,0.15,0.16,0.17,0.14,0.10,0.08,0.05,0.03},{0,0,0.00,0.04,0.18,0.22,0.20,0.16,0.09,0.05,0.05}};
int gc[10]={0,3,3,8,10,6};
int ed=39740;
int cwz,cws,cc,cr,cs,yzr,waish;//等待住院人数 等待手术人数 出院人数 入院人数 手术人数 医院中人数 转院人数
bool sws=false;
int csh[10];

BR mz[500],zhan[500];
priority_queue<BR> ry,sh,cy,wsdd;
vector<BR> shc;

bool sw=false;

int getzhou(int x)
{
  x++;
  if (x==8) x=1;
  return x;
}

void dayintian()
{
  ouf1<<shi<<';'<<yzr<<';'<<cr<<';'<<cc<<';'<<cs<<';'<<cwz<<';'<<cws<<"  ";
  int i;
  for (i=1;i<=5;i++)
    ouf1<<';'<<csh[i];
  ouf1<<endl;
}

int getcy(int tp)
{
  int i;
  double s=0,tt=rand()%1000/1000.0;
  for (i=2;i<=20;i++)
  {
    s+=gai[tp][i];
    if (s>=tt)
      return i;
  }
  //return gc[tp];
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
    zhan[i].tm=tt;
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
    if (cao.cy>shi)
      break;
    cc++;
    cy.pop();
    if (!cao.cy<d12)
      cao.cy=shi;
    dayinren(cao);
    yzr--;
  }
}

void menzhen()
{
  for (;pp<=zu;pp++)
  {
    if (mz[pp].mz>shi)
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
    tt=wsdd.top();
    if (tt.tm>shi)
      break;
    if (yzr>=79)
    {
      waish++;
      wsdd.pop();
      continue;
    }
    tt=wsdd.top();
    wsdd.pop();
    tt.ry=shi;tt.sh=shi+1;
    tt.tm=tt.sh;
    sh.push(tt);
    yzr++;cr++;
  }
  while ((!ry.empty())&&(yzr<79))
  {
    tt=ry.top();
    if (tt.mz==shi-1)
      break;//不允许当天入院
    ry.pop();
    tt.ry=shi;tt.tm=shi+wsh[tt.ty];
    sh.push(tt);
    yzr++;cr++;
  }
  cwz=ry.size()+wsdd.size();
}

void zuo(BR &a)
{
  cs++;
  csh[a.ty]++;
  if (a.ty==2)
  {
    if (a.sh)
    {
      a.shh=shi;
      a.cy=shi+getcy(a.ty);
      a.tm=a.cy;
      cy.push(a);
    }
    else
    {
      a.sh=shi;
      a.tm=shi+2;
      sh.push(a);
    }
    sw=true;
    return;
  }
  if (a.ty==1)
    sw=true;
  a.sh=shi;
  a.cy=shi+getcy(a.ty);
  a.tm=a.cy;
  cy.push(a);
}

void shoushu()
{
  cs=0;  memset(csh,0,sizeof(csh));
  if ((zhou>5)&&sws)
  {
    cws=sh.size();
    return;
  }
  BR tt;
  shc.clear();
  sw=false;
  while (!sh.empty())
  {
    tt=sh.top();
    if (tt.tm>shi)
      break;
    shc.push_back(tt);
    sh.pop();
  }
  vector<BR>::iterator i=shc.begin();
  for (;i!=shc.end();)
  {
    tt=*i;
    if (tt.ff||tt.ty==5)
    {
      i=shc.erase(i);
      zuo(tt);
    }
    else
      i++;
  }
  if (zhou==1||zhou==3)
  {
    for (i=shc.begin();i!=shc.end();)
    {
      bool shan=false;
      tt=*i;
      if (tt.ty==1)
      {
        i=shc.erase(i);
        shan=true;
        zuo(tt);
      }
      if (i==shc.end())
        break;
      if (tt.ty==2&&((tt.sh==0&&zhou==1)||(tt.sh!=0&&zhou==3)))
      {
        i=shc.erase(i);
        shan=true;
        zuo(tt);
      }
      if (!shan)
        i++;
    }
    if (!sw)
    {
      for (i=shc.begin();i!=shc.end();)
      {
        tt=*i;
        if (tt.ty!=1&&tt.ty!=2)
        {
          i=shc.erase(i);
          zuo(tt);
        }
        else
          i++;
      }
    }
  }
  else
  {
    for (i=shc.begin();i!=shc.end();)
    {
      tt=*i;
      if (tt.ty!=1&&tt.ty!=2)
      {
        i=shc.erase(i);
        zuo(tt);
      }
      else
        i++;
    }
  }
  for (i=shc.begin();i!=shc.end();i++)
    sh.push(*i);
  cws=sh.size();
}

int main()
{
  srand(time(NULL));
  read();
  zhou=5;yzr=79;pp=1;
  for (shi=d12;shi<=ed;shi++,zhou=getzhou(zhou))
  {
    chuyuan();
    menzhen();
    ruyuan();
    shoushu();
    dayintian();
  }
  return 0;
}

