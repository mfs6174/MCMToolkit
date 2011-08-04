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
const double Vl=0.035;

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

  void rand()
  {
    int i;
    for (i=1;i<=Wei_f;i++)
      vf[i]=(vmaxf[i]-vmaxf[i]/2)*frand();
    for (i=1;i<=Wei_i;i++)
      vi[i]=(int)((vmaxi[i]-vmaxi[i]/2)*frand());
    for (i=1;i<=Wei_f;i++)
      pf[i]=(fmax[i]-fmin[i])*frand();
    for (i=1;i<=Wei_i;i++)
      pi[i]=(int)((imax[i]-imin[i])*frand());
  }
  
  void chapf(int x)//检查浮点维位置
  {
    if (pf[x]<fmin[x])
      pf[x]=fmin[x];
    if (pf[x]>fmax[x])
      pf[x]=fmax[x];
  }

  void chapi(int x)//检查整数维位置
  {
    if (pi[x]<imin[x])
      pi[x]=imin[x];
    if (pi[x]>imax[x])
      pi[x]=imax[x];
  }

  void chav()//检查速度，进行最大限速
  {
    int i;
    for (i=1;i<=Wei_f;i++)
      if (vf[i]>vmaxf[i])
        vf[i]=vmaxf[i];
    for (i=1;i<=Wei_i;i++)
      if (vi[i]>vmaxi[i])
        vi[i]=vmaxi[i];
  }
  
  void suan()//计算适应度并更新最优值
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
  
  void tiaosu(const P &h)//调整速度
  {
    int i;
    for (i=1;i<=Wei_f;i++)
      vf[i]=W*vf[i]+C1*frand()*(mf[i]-pf[i])+C2*frand()*(h.pf[i]-pf[i]);
    for (i=1;i<=Wei_i;i++)
      vi[i]=(int)(W*vi[i]+C1*frand()*(mi[i]-pi[i])+C2*frand()*(h.pi[i]-pi[i]));
    chav();
  }
  
  void fei()//用调整后的速度进行位置变更
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

  void dayin()//打印粒子的相关数据
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
  cin>>maxround;//输入最大迭代次数
  int i,n,m;
  for (i=1;i<=Wei_f;i++)
    cin>>fmin[i];//输入浮点维下界
  for (i=1;i<=Wei_f;i++)
    cin>>fmax[i];//浮点维上界
  for (i=1;i<=Wei_i;i++)
    cin>>imin[i];//整数维下界
  for (i=1;i<=Wei_i;i++)
    cin>>imax[i];//整数维上界
  cin>>n;//浮点参数个数和浮点参数
  for (i=1;i<=n;i++)
    cin>>a[i];
  cin>>m;//整数参数个数和整数参数
  for (i=1;i<=m;i++)
    cin>>b[i];
}

void init()
{
  mm=maxlongint;//初始化全局最优值
  int i;
  for (i=1;i<=Wei_f;i++)
    vmaxf[i]=(fmax[i]-fmin[i])*Vl;
  for (i=1;i<=Wei_i;i++)
    vmaxi[i]=(int)((imax[i]-imin[i])*Vl);
  srand(seed);
  //srand((unsigned)time(NULL));
  for (i=1;i<=N;i++)
  {
    zhu[i].rand();
    zhu[i].pm=maxlongint;//初始化个体最优值
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

