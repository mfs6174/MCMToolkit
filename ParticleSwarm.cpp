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
#include<map>
#include<vector>
#include<iomanip>
using namespace std;
ifstream inf("ti.in");
//ofstream ouf("ti.out");
const int maxlongint=2147483647;
const int Wei_f=3;
const int Wei_i=0;
const int C1=2,C2=2;
const int N=100;
const double W=1.0;
int seed=1331;
int imin[Wei_i+5],imax[Wei_i+5],vmaxi[Wei_i+5];
double fmin[Wei_f+5],fmax[Wei_f+5],vmaxf[Wei_f+5];
double a[5];
int b[5];

Class P
{
 public:
  double pf[Wei_f+5],vf[Wei_f+5],mf[Wei_f+5];
  int pi[Wei_i+5],vi[Wei_i+5],mi[Wei_i+5];
  double pm,pp;
  int p;
  void suan()
  {
    int i;
    pp=0;
    if (pp>pm)
    {
      pm=pp;
      for (i=1;i<=Wei_f;i++)
        mf[i]=pf[i];
      for (i=1;i<=Wei_i;i++)
        mi[i]=mi[i];
    }
    if (pm>mm)
    {
      mm=pm;
      tt=p;
    }
  }
  void tiaosu(const P &hao)
  {
  }
  void fei(int &tt)
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
      chavf(i);
    }
  }
};
P zhu[N];
int i,j,k,t,n,m,tt,maxround;
double mm;

int main()
{
  return 0;
}

