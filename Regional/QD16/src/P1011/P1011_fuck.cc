/*************************************************************************
  >         File: P1011_fuck.cc
  >       Author: lyyllyyl
  >         Mail: riho.yoshioka@yandex.com
  > Created Time: Sat 17 Sep 2016 01:23:51 PM CST
 *************************************************************************/
#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<queue>
#include<stdio.h>
#define oo 1<<29
#define MAXN 1005
#define MAXM 21005
using namespace std; 
struct Dinic                    
{                    
  struct node                  
  {                   
    int c,u,v,next;                  
  }edge[MAXM];                  
  int ne,head[MAXN];                  
  int cur[MAXN], ps[MAXN], dep[MAXN];                
  void initial()                  
  {                  
    ne=2;                  
    memset(head,0,sizeof(head));                   
  }                  
  void addedge(int u, int v,int c)                  
  {                   
    edge[ne].u=u,edge[ne].v=v,edge[ne].c=c,edge[ne].next=head[u];                  
    head[u]=ne++;                  
    edge[ne].u=v,edge[ne].v=u,edge[ne].c=0,edge[ne].next=head[v];             
    head[v]=ne++;                  
  }                  
  int MaxFlow(int s,int t)                  
  {                                       
    int tr, res = 0;                  
    int i,j,k,f,r,top;                  
    while(1)                  
    {                  
      memset(dep, -1, sizeof(dep));                  
      for(f=dep[ps[0]=s]=0,r=1;f!= r;)                  
        for(i=ps[f++],j=head[i];j;j=edge[j].next)                  
          if(edge[j].c&&dep[k=edge[j].v]==-1)                  
          {                  
            dep[k]=dep[i]+1;                  
            ps[r++]=k;                  
            if(k == t){  f=r; break;  }                  
          }                  
      if(dep[t]==-1) break;                  
      memcpy(cur,head,sizeof(cur));                  
      i=s,top=0;                  
      while(1)                  
      {                  
        if(i==t)                  
        {                  
          for(tr=oo,k=0;k<top;k++)                  
            if(edge[ps[k]].c<tr)                  
              tr=edge[ps[f=k]].c;                  
          for(k=0;k<top;k++)                  
          {                  
            edge[ps[k]].c-=tr;                  
            edge[ps[k]^1].c+=tr;                  
          }                  
          i=edge[ps[top=f]].u;                  
          res+= tr;                  
        }                  
        for(j=cur[i];cur[i];j=cur[i]=edge[cur[i]].next)                   
          if(edge[j].c && dep[i]+1==dep[edge[j].v]) break;                   
        if(cur[i])  ps[top++]=cur[i],i=edge[cur[i]].v;                   
        else                  
        {                  
          if(!top) break;                  
          dep[i]=-1;                  
          i=edge[ps[--top]].u;                  
        }                  
      }                  
    }                  
    return res;                  
  }          
}T;     
struct node
{
  int u,v,d,c,next;
}edge[MAXM];
int _next[MAXN],En,dis[2][MAXN];
queue<int> Q;
bool inQ[MAXN];
void addedge(int u,int v,int d,int c)
{
  edge[++En].next=_next[u],_next[u]=En;
  edge[En].u=u,edge[En].v=v,edge[En].d=d,edge[En].c=c;
}
void SPFA(int n,int s,int tp)
{
  int k,u,v;
  memset(inQ,false,sizeof(inQ));
  memset(dis[tp],0x7f,sizeof(dis[tp]));
  Q.push(s),dis[tp][s]=0;
  while (Q.size())
  {
    u=Q.front();
    Q.pop(),inQ[u]=false;
    for (k=_next[u];k;k=edge[k].next)
    {
      v=edge[k].v;
      if (dis[tp][v]<=dis[tp][u]+edge[k].d) continue;
      dis[tp][v]=dis[tp][u]+edge[k].d;
      if (!inQ[v])
        Q.push(v),inQ[v]=true; 
    }
  }
} 
int main()
{ 
  int n,m,s,t,v,u,d,c,i,cases=0,MinDis;
  int cas;
  scanf("%d", &cas);
  while (cas--)
  {
    scanf("%d%d",&n,&m);
    memset(_next,0,sizeof(_next)),En=0;
    s=1, t=n;
    while (m--)
    {
      d = 1;
      scanf("%d%d%d",&u,&v,&c);
      addedge(u,v,d,c);
      addedge(v,u,d,c);
    }
    SPFA(n,s,0);
    SPFA(n,t,1);
    MinDis=dis[0][t];
    T.initial();
    for (i=1;i<=En;i++) 
      if (dis[0][edge[i].u]+dis[1][edge[i].v]+edge[i].d==MinDis)
        T.addedge(edge[i].u,edge[i].v,edge[i].c);
    printf("%d\n",++cases,T.MaxFlow(s,t));
  }
  return 0;
}

