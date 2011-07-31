/*
ID: mfs6174
PROG: ParticleSwarm
LANG: C++
*/

#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<cstring>
#include<algorithm>
#include<iomanip>
#include<ctime>
#include<cstdlib>

using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;
const int Wei_f=3;
const int Wei_i=0;
const int C1=2,C2=2;
const int N=100;
const double W=1.0;
const int Maxround=1000;
const unsigned seed=1331;
const int randmax=1000;

int imin[Wei_i+5],imax[Wei_i+5],vmaxi[Wei_i+5];
double fmin[Wei_f+5],fmax[Wei_f+5],vmaxf[Wei_f+5];
double a[10];
int b[10];

int i,j,k,t,n,m,tt,maxround;
double mm,mm2;

double frand()
{
  return rand()%randmax/((double)randmax);
}

class P
{
 public:
  double pf[Wei_f+5],vf[Wei_f+5],mf[Wei_f+5];//位置，速度，个体最佳位置
  int pi[Wei_i+5],vi[Wei_i+5],mi[Wei_i+5];
  double pm,pp;//个体最佳适应度，当前适应度
  int p;//粒子编号

  void chapf(int x)
  {
    if (pf[x]<fmin[x])
      pf[x]=fmin[x];
    if (pf[x]>fmax[x])
      pf[x]=fmax[x];
  }

  void chapi(int x)
  {
    if (pi[x]<imin[x])
      pi[x]=imin[x];
    if (pi[x]>imax[x])
      pi[x]=imax[x];
  }

  void chav()
  {
    int i;
    for (i=1;i<=Wei_f;i++)
      if (vf[i]>vmaxf[i])
        vf[i]=vmaxf[i];
    for (i=1;i<=Wei_i;i++)
      if (vi[i]>vmaxi[i])
        vi[i]=vmaxi[i];
  }
  
  void suan()
  {
    int i;
    pp=0;
    //这里应当计算出pp
    if (pp>pm)
    {
      pm=pp;
      memcpy(mf,pf,sizeof(pf));
      memcpy(mi,pi,sizeof(pi));
    }
    if (pm>mm)
    {
      mm=pm;
      tt=p;
    }
  }
  
  void tiaosu(const P &h)
  {
    int i;
    for (i=1;i<=Wei_f;i++)
      vf[i]=W*vf[i]+C1*frand()*(mf[i]-pf[i])+C2*frand()*(h.pf[i]-pf[i]);
    for (i=1;i<=Wei_i;i++)
      vi[i]=(int)(W*vi[i]+C1*frand()*(mi[i]-pi[i])+C2*frand()*(h.pi[i]-pi[i]));
    chav();
  }
  
  void fei()
  {
    int i;
    for (i=1;i<=Wei_f;i++)
    {
      pf[i]+=vf[i];
      chapf(i);
    }
    for (i=1;i<=Wei_i;i++)
    {
      pi[i]+=vi[i];
      chapi(i);
    }
  }

  void dayin()
  {
    int i;
    for (i=1;i<=Wei_f;i++)
      cout<<pf[i]<<"   ";
    cout<<endl;
    for (i=1;i<=Wei_i;i++)
      cout<<pi[i]<<"   ";
    cout<<endl;
  }
};
P zhu[N],shi[Maxround];
int zz;

void read()
{
  cin>>maxround;
  int i,n,m;
  for (i=1;i<=Wei_f;i++)
    cin>>fmin[i];
  for (i=1;i<=Wei_f;i++)
    cin>>fmax[i];
  for (i=1;i<=Wei_i;i++)
    cin>>imin[i];
  for (i=1;i<=Wei_i;i++)
    cin>>imax[i];
  cin>>n;
  for (i=1;i<=n;i++)
    cin>>a[i];
  cin>>m;
  for (i=1;i<=m;i++)
    cin>>b[i];
}

void init()
{
  mm=maxlongint;
  int i;
  srand(seed);
  //srand((unsigned)time(NULL));
  for (i=1;i<=N;i++)
  {
    zhu[i].rand();
    zhu[i].pm=maxlongint;
    zhu[i].p=i;
  }
}

int main()
{
  read();
  init();
  for (zz=0;zz<=maxround;zz++)
  {
    for (i=1;i<=N;i++)
      zhu[i].suan();
    if (mm!=mm2)
    {
      mm2=mm;
      shi[zz]=zhu[tt];
    }
    else
      if (zz-1>=0)
        shi[zz]=shi[zz-1];
    for (i=1;i<=N;i++)
    {
      zhu[i].tiaosu(shi[zz]);
      zhu[i].fei();
    }
  }
  for (i=1;i<=N;i++)
    zhu[i].suan();
  if (mm!=mm2)
  {
      mm2=mm;
      shi[zz]=zhu[tt];
    }
    else
      if (zz-1>=0)
        shi[zz]=shi[zz-1];
  cout<<mm<<endl;
  shi[zz].dayin();
  return 0;
}

