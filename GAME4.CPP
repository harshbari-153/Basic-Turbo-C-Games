#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct list
{
int top,D[25];
};
void listadd(struct list *game,int d)
{
game->D[game->top]=d;
game->top++;
}
void getsolution(struct list *game)
{
int x;
printf("Solution:\n");
for(x=1;x<game->top;x++)
{
 if(game->D[x]==1)
 printf("%d)right\n",x);
 else if(game->D[x]==2)
 printf("%d)down\n",x);
 else if(game->D[x]==3)
 printf("%d)left\n",x);
 else
 printf("%d)up\n",x);
}
printf("press anykey to exit");
getch();
exit(0);
}
void play(int a[4][4],int d,struct list *game,int i,int j)
{
 int k,check=9,temp,sol=1,x,y;
 if(d<=20)
 {
  for(k=1;k<=4;k++)
  {
   if(k==1)
   {if(j!=3)
   check=1+j;}
   else if(k==2)
   {if(i!=3)
   check=1+i;}
   else if(k==3)
   {if(j!=1)
   check=j-1;}
   else
   {if(i!=1)
   check=i-1;}
   if(check!=9)
   {
    listadd(game,k);
    ////swap starts
    temp=a[i][j];
    if(k%2!=0)
    {
     a[i][j]=a[i][check];
     a[i][check]=temp;
    }
    else
    {
     a[i][j]=a[check][j];
     a[check][j]=temp;
    }
    ///swap ends
    ///check solution starts
    for(x=0;x<3;x++)
    {
     for(y=1;y<=3;y++)
     {
      if(x==2 && y==3)
      {}
      else
      {
       if(a[x+1][y]!=3*x+y)
       sol=0;
      }
     }
    }
    ///check solution ends
    if(sol!=0)
    getsolution(game);
    if(k%2!=0)
    play(a,d+1,game,i,check);
    else
    play(a,d+1,game,check,j);
    game->top--;
    ///next swap begaings
    temp=a[i][j];
    if(k%2!=0)
    {
     a[i][j]=a[i][check];
     a[i][check]=temp;
    }
    else
    {
     a[i][j]=a[check][j];
     a[check][j]=temp;
    }
    ///next swap ends
   }
   check=9;
   sol=1;
  }
 }
}
void main()
{
int a[4][4],i,j,x,t=0,y,w[10],e=0,p;
struct list *game;
clrscr();
printf("Enter elements:\n");
for(i=1;i<=3;i++)
{
for(j=1;j<=3;j++)
{
gotoxy(1+2*j,2+i);
scanf("%d",&a[i][j]);
e++;
if(a[i][j]>8 || a[i][j]<0)
{
printf("Wrong input\nprogram terminated");
getch();
exit(0);
}
for(p=1;p<e;p++)
{
if(w[p]==a[i][j])
{
printf("repetative input\nprogram terminated");
getch();
exit(0);
}
}
w[e]=a[i][j];
}
}
game=(struct list*)malloc(sizeof(struct list));
game->top=1;
for(i=1;i<=3;i++)
for(j=1;j<=3;j++)
if(a[i][j]==0)
{
x=i;
y=j;
t=1;
}
if(t==1)
play(a,1,game,x,y);
else
printf("not possible");
getch();
}