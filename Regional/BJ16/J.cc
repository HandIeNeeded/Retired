#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int mov[4][4]={{1,0},{0,1},{-1,0},{0,-1}};
int N,M,C,E;
int G[200][200];

struct Character
{
  int AD1,AD2;
  int HP,AT,MV;
  int GR;
  int x,y;
  int dead;
} ch[200];

bool init()
{
  if (scanf("%d%d%d%d",&N,&M,&C,&E)==EOF) return false;


  for (int i=1;i<=N;i++)
    for (int j=1;j<=M;j++)
      scanf("%d",&G[i][j]);
  //G[i][j]=1;

  //HP, AT, MV, AD1, AD2, STx, STy, GR
  for (int i=1;i<=C;i++)
  {
    scanf("%d%d%d%d%d%d%d%d",&ch[i].HP,&ch[i].AT,&ch[i].MV,&ch[i].AD1,&ch[i].AD2,&ch[i].x,&ch[i].y,&ch[i].GR);
    ch[i].dead=0;
  }

  return true;
}

int getactid(char s[])
{
  int ret=0;
  int now=20;
  while (now<strlen(s))
  {
    ret*=10;
    ret+=s[now]-'0';
    now++;
  }
  return ret;
}

void getmove(char s[],int &dx,int &dy)
{
  int tmp=0;
  int now=9;
  while (s[now]!=',')
  {
    tmp*=10;
    tmp+=s[now]-'0';
    now++;
  }
  dx=tmp;
  tmp=0;

  now++;

  while (s[now]!=')')
  {
    tmp*=10;
    tmp+=s[now]-'0';
    now++;
  }
  dy=tmp;
  tmp=0;
}

bool check(int x,int y)
{
  if (x>=1 && x<=N && y>=1 && y<=M) return true;
  return false;
}

void move(int id,int dx,int dy)
{
  int sx,sy;
  int xx,yy;

  sx=ch[id].x;
  sy=ch[id].y;


  int g[200][200];
  for (int i=1;i<=N;i++)
    for (int j=1;j<=M;j++)
      g[i][j]=G[i][j];

  for (int i=1;i<=C;i++)
  {
    if (i==id) continue;
    if (ch[i].dead==1) continue;

    if (ch[i].GR!=ch[id].GR)
    {
      if (ch[i].dead==1) continue;
      g[ch[i].x][ch[i].y]=-2;
      for (int k=0;k<4;k++)
      {
        xx=ch[i].x+mov[k][0];
        yy=ch[i].y+mov[k][1];
        if (check(xx,yy))
          g[xx][yy]=-1;
      }
    }
    else g[ch[i].x][ch[i].y]=-2;
  }

  if (dx==sx && dy==sy)
  {
    if (g[sx][sy]==-1) printf("%d\n",0);
    else printf("%d\n",ch[id].MV);
    return ;
  }

  if (g[sx][sy]==-1)
  {
    printf("INVALID\n");
    return ;
  }


  bool vis[101][101];
  int dis[101][101];

  memset(vis,0,sizeof(vis));
  memset(dis,127/3,sizeof(dis));

  vis[sx][sy]=1;
  dis[sx][sy]=0;
  int q[20020][2],head=0,tail=1;
  q[1][0]=sx;
  q[1][1]=sy;

  do
  {
    head++;
    if (head>20000) head=1;
    int nx,ny;
    nx=q[head][0];
    ny=q[head][1];

    //cout<<nx<<' '<<ny<<endl;

    vis[nx][ny]=0;
    for (int k=0;k<4;k++)
    {
      xx=nx+mov[k][0];
      yy=ny+mov[k][1];
      if (check(xx,yy))
      {
        if (g[xx][yy]>=0 && dis[xx][yy]>dis[nx][ny]+g[xx][yy])
        {
          dis[xx][yy]=dis[nx][ny]+g[xx][yy];
          if (!vis[xx][yy])
          {
            tail++;
            if (tail>20000) tail=1;
            q[tail][0]=xx;
            q[tail][1]=yy;
            vis[xx][yy]=1;
          }
        }
        else if (g[xx][yy]==-1)
        {
          if (dis[nx][ny]+G[xx][yy]<=ch[id].MV)
            dis[xx][yy]=ch[id].MV;
        }
      }
    }
  }
  while (head!=tail);


  if (dis[dx][dy]>ch[id].MV)
  {
    printf("INVALID\n");
    return ;
  }

  printf("%d\n",ch[id].MV-dis[dx][dy]);

  ch[id].x=dx;
  ch[id].y=dy;
}

int getattack(char s[])
{
  int now=7;
  int ret=0;
  while (now<strlen(s))
  {
    ret*=10;
    ret+=s[now]-'0';
    now++;
  }
  return ret;
}

void attack(int actid,int desid)
{
  int dis;
  if (desid>=C)
  {
    printf("INVALID\n");
    return ;
  }
  if (ch[desid].dead)
  {
    printf("INVALID\n");
    return ;
  }
  dis=abs(ch[actid].x-ch[desid].x)+abs(ch[actid].y-ch[desid].y);
  if (dis<ch[actid].AD1 || dis>ch[actid].AD2)
  {
    printf("INVALID\n");
    return ;
  }
  if (ch[desid].HP<=ch[actid].AT)
  {
    printf("INVALID\n");
    return ;
  }
  ch[desid].HP-=ch[actid].AT;
  printf("%d\n",ch[desid].HP);
  return ;
}

int getdo(char s[])
{
  int now=10;
  int ret=0;
  while (now<strlen(s))
  {
    ret*=10;
    ret+=s[now]-'0';
    now++;
  }
  return ret;
}

void dout(int actid,int desid)
{
  int dis;
  if (desid>=C)
  {
    printf("INVALID\n");
    return ;
  }
  if (ch[desid].dead)
  {
    printf("INVALID\n");
    return ;
  }
  dis=abs(ch[actid].x-ch[desid].x)+abs(ch[actid].y-ch[desid].y);
  if (dis<ch[actid].AD1 || dis>ch[actid].AD2)
  {
    printf("INVALID\n");
    return ;
  }
  if (ch[desid].HP>ch[actid].AT)
  {
    printf("INVALID\n");
    return ;
  }
  ch[desid].HP-=ch[actid].AT;
  ch[desid].dead=1;
  printf("%d\n",ch[desid].HP);
  return ;
}

void solve()
{
  char s[200];
  int round,actid=0;
  int dx,dy;
  round=0;
  gets(s);
  for (int i=1;i<=E;i++)
  {
    gets(s);
    if (s[0]=='R')
    {
      round=s[9]-'0';
      //cout<<round<<endl;
      continue;
    }
    if (s[0]=='A' && s[1]=='c')
    {
      actid=getactid(s);
      //cout<<actid<<endl;
      continue;
    }
    if (s[0]=='M')
    {
      getmove(s,dx,dy);
      //cout<<dx<<' '<<dy<<endl;
      move(actid,dx,dy);
      continue;
    }
    if (s[0]=='A')
    {
      dx=getattack(s);
      //cout<<dx<<endl;
      attack(actid,dx);
      continue;
    }
    if (s[0]=='D')
    {
      dx=getdo(s);
      //cout<<dx<<endl;
      dout(actid,dx);
      continue;
    }
  }
}

int main()
{
  while (init())
  {
    solve();
  }
}
