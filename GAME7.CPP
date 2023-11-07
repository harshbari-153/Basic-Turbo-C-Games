#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
#include<stdlib.h>
struct people
{
int x,y,move,st,live,vis,ht,ft,h,vt;
};
/////
void setpeople(struct people *P,int n)
{
int i,j;
char e[3];

settextstyle(0,0,3);
outtextxy(50,200,"Game begains in:");
 srand(time(0));
for(i=1;i<=(2*n);i++)
{
 setcolor(12);
 sprintf(e,"%d",2*n-i);
 outtextxy(430,200,e);
 come:
 (P+i)->x=(rand()%74)+3;
 (P+i)->y=(rand()%20)+3;
 for(j=1;j<i;j++)
 {
 if((P+i)->x==(P+j)->x && (P+i)->y==(P+j)->y)
 goto come;
 }
 if(i<=n)
 {
 (P+i)->st=2;
 (P+i)->vt=120;
 }
 else
 (P+i)->st=1;
 (P+i)->move=1;
 (P+i)->live=1;
 (P+i)->vis=0;
 (P+i)->h=0;
 setcolor(0);
 sprintf(e,"%d",2*n-i);
 outtextxy(430,200,e);
}
outtextxy(50,200,"Game begains in:88888");
settextstyle(0,0,1);
setcolor(7);
for(i=1;i<=(2*n);i++)
{
outtextxy((P+i)->x*7.8,(P+i)->y*15.4,"*");
}
}
///////
void freezepeople(int a,int b,struct people *P,int n,int T1)
{
int i;
for(i=1;i<=2*n;i++)
{
if((P+i)->x>=a-3 && (P+i)->x<=a+3 && (P+i)->y>=b-2 && (P+i)->y<=b+2 && (P+i)->live==1 && (P+i)->h==0)
{
(P+i)->move=0;
(P+i)->ft=T1;
}
}
}
/////
void createpeople(int x,int y,int vis,int st)
{
if(vis==0)
setcolor(7);
else if(st==1)
setcolor(10);
else if(st==2)
setcolor(14);
else
setcolor(12);
outtextxy(x*7.8,y*15.4,"*");
}
/////
void removepeople(int x,int y)
{
setcolor(0);
outtextxy(x*7.8,y*15.4,"*");
}
/////
void removeme(int a,int b,int m)
{
int i;
setcolor(0);
for(i=-1;i<=1;i++)
outtextxy((a-2)*7.8,(b+i)*15.4,"* * *");
if(m==4)
{
outtextxy(a*7.8,(b+2)*15.4,"*");
outtextxy(a*7.8,(b+3)*15,"v");
outtextxy(a*7.8,(b-2)*15.4,"*");
outtextxy(a*7.8,(b-3)*16,"^");
outtextxy((a-6)*7.8,(b)*15.4," <*");
outtextxy((a+4)*7.8,(b)*15.4,"*> ");
}
}
/////
void createme(int a,int b,int m)
{
int i;
if(m==1)
setcolor(13);
else if(m==2)
setcolor(11);
else if(m==3)
setcolor(15);
else
setcolor(9);
for(i=-1;i<=1;i++)
outtextxy((a-2)*7.8,(b+i)*15.4,"* * *");
if(m==4)
{
outtextxy(a*7.8,(b+2)*15.4,"*");
outtextxy(a*7.8,(b+3)*15,"v");
outtextxy(a*7.8,(b-2)*15.4,"*");
outtextxy(a*7.8,(b-3)*16,"^");
outtextxy((a-6)*7.8,(b)*15.4," <*");
outtextxy((a+4)*7.8,(b)*15.4,"*> ");
}
}
////////
int distance(int a,int b,int c,int d)
{
int i;
i=(c-a)*(c-a);
i=i+(d-b)*(d-b);
i=sqrt(i);
return i;
}
//////////
void update(int a,int b,int m)
{
int i;
for(i=1;i<=10;i++)
{
settextstyle(0,0,2);
setcolor(12);
outtextxy(180,31,"Integrating Gun....");
settextstyle(0,0,1);
if(i%2==1)
setcolor(9);
else
{
if(m==1)
setcolor(13);
else if(m==2)
setcolor(11);
else
setcolor(15);
}
outtextxy(a*7.8,b*15.4,"*");
delay(500);
}
delay(500);
setcolor(9);
outtextxy((a-2)*7.8,(b-1)*15.4,"* * *");
outtextxy((a-2)*7.8,(b)*15.4,"*   *");
outtextxy((a-2)*7.8,(b+1)*15.4,"* * *");
delay(800);
outtextxy(a*7.8,b*15.4,"*");
delay(1000);
outtextxy((a-4)*7.8,(b)*15.4,"*");
outtextxy((a+4)*7.8,(b)*15.4,"*");
outtextxy((a)*7.8,(b+2)*15.4,"*");
outtextxy((a)*7.8,(b-2)*15.4,"*");
delay(800);
outtextxy((a-5)*7.8,(b)*15.4,"<");
outtextxy((a+5)*7.8,(b)*15.4,">");
outtextxy((a)*7.8,(b+3)*15,"v");
outtextxy((a)*7.8,(b-3)*16,"^");
delay(1000);
settextstyle(0,0,2);
setcolor(0);
outtextxy(180,31,"Integrating Gun....");
setcolor(12);
outtextxy(180,31,"Gun Activated");
gotoxy(50,23);
printf("Press any key to resume game");
getch();
setcolor(0);
outtextxy(180,31,"Gun Activated");
gotoxy(50,23);
printf("                            ");
gotoxy(70,1);
printf("          ");
gotoxy(70,1);
printf("Gun");
settextstyle(0,0,1);
}
///////
int iswin(struct people *P,int n)
{
int i;
for(i=1;i<=2*n;i++)
{
if((P+i)->live==1 && (P+i)->st!=1 && (P+i)->h==0)
return 0;
}
return 1;
}
///////
int shortestpath(int a,struct people *P,int n)
{
int i,d=0,m;
if((P+a)->st!=1)        /////for affected people
{
 for(i=1;i<=2*n;i++)
 {
  if(a!=i && (P+i)->st==1 && (P+i)->live==1 && (P+i)->h==0)
  {
     if(d==0)
     {
     d=distance((P+a)->x,(P+a)->y,(P+i)->x,(P+i)->y);
     m=i;
     }
     else
     {
      if(d>distance((P+a)->x,(P+a)->y,(P+i)->x,(P+i)->y))
      {
       d=distance((P+a)->x,(P+a)->y,(P+i)->x,(P+i)->y);
       m=i;
      }
     }
  }
 }
 if(d!=0)
 return m;
}
else                    //////for green people
{
 for(i=1;i<=2*n;i++)
 {
  if(a!=i && (P+i)->st!=1 && (P+i)->live==1 && (P+i)->h==0)
  {
     if(d==0)
     {
     d=distance((P+a)->x,(P+a)->y,(P+i)->x,(P+i)->y);
     m=i;
     }
     else
     {
     if(d>distance((P+a)->x,(P+a)->y,(P+i)->x,(P+i)->y))
      {
       d=distance((P+a)->x,(P+a)->y,(P+i)->x,(P+i)->y);
       m=i;
      }
     }
  }
 }
 if(d!=0)
 return m;
}		///end of green people
return 0;
}
/////////
///////
void refreshtable(struct people *P,int n,int *RT,int *GT)
{
int i;
//////setting red table
for(i=1;i<=2*n;i++)
{
if(i<=n)
RT[i]=shortestpath(i,P,n);
else
RT[i]=-1;
}
//////setting green table
for(i=1;i<=2*n;i++)
{
if(i>n)
GT[i]=shortestpath(i,P,n);
else
GT[i]=-1;
}
}
////////
void movepeople(struct people *P,int n,int T1,int *RT,int *GT)
{
int i,t;
for(i=1;i<=2*n;i++)
{
if((P+i)->st==2 || (P+i)->st==3)            /////for red
{
  if((P+i)->h==0 && (P+i)->move==1 && (P+i)->live==1)
  {
    t=RT[i];
    if(t!=0 && t!=-1)
    {
     if((P+i)->x>=(P+t)->x-1 && (P+i)->x<=(P+t)->x+1 && (P+i)->y>=(P+t)->y-1 && (P+i)->y<=(P+t)->y+1)
     {
     (P+t)->st=2;
     (P+t)->vt=T1;
     removepeople((P+t)->x,(P+t)->y);
     createpeople((P+t)->x,(P+t)->y,(P+t)->vis,2);
     refreshtable(P,n,RT,GT);
     }
     else if((P+i)->x<(P+t)->x)
     {
     removepeople((P+i)->x,(P+i)->y);
     (P+i)->x++;
     createpeople((P+i)->x,(P+i)->y,(P+i)->vis,(P+i)->st);
     }
     else
     {
     removepeople((P+i)->x,(P+i)->y);
     if((P+i)->x!=(P+t)->x)
     (P+i)->x--;
     else if((P+i)->y<(P+t)->y)
     (P+i)->y++;
     else
     (P+i)->y--;
     createpeople((P+i)->x,(P+i)->y,(P+i)->vis,(P+i)->st);
     }
    }
  }
}
else            /////for green
{
  if((P+i)->h==0 && (P+i)->move==1 && (P+i)->live==1)
  {
    t=GT[i];
    if(t!=0 && t!=-1)
    {
     if((P+i)->x>=(P+t)->x-1 && (P+i)->x<=(P+t)->x+1 && (P+i)->y>=(P+t)->y-1 && (P+i)->y<=(P+t)->y+1)
     {
     (P+i)->st=2;
     (P+i)->vt=T1;
     removepeople((P+i)->x,(P+i)->y);
     createpeople((P+i)->x,(P+i)->y,(P+i)->vis,2);
     refreshtable(P,n,RT,GT);
     }
     else if((P+i)->y<(P+t)->y)
     {
     removepeople((P+i)->x,(P+i)->y);
     (P+i)->y++;
     createpeople((P+i)->x,(P+i)->y,(P+i)->vis,1);
     }
     else
     {
     removepeople((P+i)->x,(P+i)->y);
     if((P+i)->y!=(P+t)->y)
     (P+i)->y--;
     else if((P+i)->x<(P+t)->x)
     (P+i)->x++;
     else
     (P+i)->x--;
     createpeople((P+i)->x,(P+i)->y,(P+i)->vis,1);
     }
    }
  }
}
}
}
////////
int isolation(int a,int b,struct people *P,int n,int h, int T1)
{
int i;
if(h==0)
return h;
for(i=1;i<=2*n;i++)
{
if((P+i)->x>=a-4 && (P+i)->x<=a+4 && (P+i)->y>=b-2 && (P+i)->y<=b+2)
{
 if((P+i)->st!=1 && (P+i)->live==1 && (P+i)->vis==1 && (P+i)->h==0)
 {
  (P+i)->h=1;
  (P+i)->ht=T1;
  (P+i)->move=0;
  setcolor(0);
  outtextxy((P+i)->x*7.8,(P+i)->y*15.4,"*");
  h--;
  if(h==0)
  return h;
 }
}
}
return h;
}
///////
void checkpeople(int a,int b,struct people *P,int n)
{
int i;
for(i=1;i<=2*n;i++)
{
if((P+i)->x>=a-4 && (P+i)->x<=a+4 && (P+i)->y>=b-2 && (P+i)->y<=b+2 && (P+i)->live==1 && (P+i)->h==0)
{
 if((P+i)->st==1)
 setcolor(10);
 else if((P+i)->st==2)
 setcolor(14);
 else
 setcolor(12);
 outtextxy((P+i)->x*7.8,(P+i)->y*15.4,"*");
 (P+i)->vis=1;
}
}
}
////////
int islost(struct people *P,int n)
{
int i;
for(i=1;i<=2*n;i++)
{
if((P+i)->live==1 && (P+i)->h==0 && (P+i)->st==1)
return 0;
if((P+i)->live==1 && (P+i)->h==1)
return 0;
}
return 1;
}
//////////


///////
void play(struct people *P,int n,int l)
{
int a,b,m,st,g,B1x,B1y,B2x,B2y,B3x,B3y,B4x,B4y,T1,T2,i,h,*RT,*GT,kills;
char e,z[3];
RT=(int *)malloc(sizeof(int)*(n+1));
GT=(int *)malloc(sizeof(int)*(n+1));
h=n;
kills=0;
a=40;
b=12;
m=1;
st=1;
g=1;
T1=120;
T2=1300;
B1x=0;
B1y=0;
B2x=0;
B2y=0;
B3x=0;
B3y=0;
B4x=0;
B4y=0;
setpeople(P,n);

refreshtable(P,n,RT,GT);
//////
createme(a,b,m);
gotoxy(3,1);
printf("Gear:%d",g);
gotoxy(65,1);
printf("Mode:Diagnose");
gotoxy(16,1);
printf("Empty Bed:%2d",h);
gotoxy(30,2);
printf("Press anykey to begain......");
getch();
gotoxy(30,2);
printf("                             ");
while(1)
{
/////timer
if(T2==0)
{
T2=1300;
T1--;
}
else
T2--;
gotoxy(35,1);
printf("%3d",T1);
if(T1==100 && T2==1200)
{
st=2;
update(a,b,m);
m=4;
}
if(T1==-1)
goto end;
/////timer ends
/////checking results

if(iswin(P,n))
goto win;
if(islost(P,n))
goto lost;
/////results checked
/////user inputs
if(kbhit())
{
 e=getch();
 if(e=='0')
 goto end;
 else if(e=='j')
 {
  g=g%5+1;
  gotoxy(8,1);
  printf("%d",g);
 }
 else if(e=='d')
 {
  g=(g+3)%5+1;
  gotoxy(8,1);
  printf("%d",g);
 }
 else if(e=='a')
 {
  if(a-g<=3)
  {
  gotoxy(30,1);
  printf("Please Play Inside Ground");
  gotoxy(30,1);
  getch();
  printf("                          ");
  }
  else
  {
  removeme(a,b,m);
  a=a-g;
  createme(a,b,m);
  }
 }
 else if(e=='l')
 {
  if(a+g>=77)
  {
  gotoxy(30,1);
  printf("Please Play Inside Ground");
  gotoxy(30,1);
  getch();
  printf("                          ");
  }
  else
  {
  removeme(a,b,m);
  a=a+g;
  createme(a,b,m);
  }
 }
 else if(e=='t')
 {
  if(b-g<=2)
  {
  gotoxy(30,1);
  printf("Please Play Inside Ground");
  gotoxy(30,1);
  getch();
  printf("                          ");
  }
  else
  {
  removeme(a,b,m);
  b=b-g;
  createme(a,b,m);
  }
 }
 else if(e=='v')
 {
  if(b+g>=23)
  {
  gotoxy(30,1);
  printf("Please Play Inside Ground");
  gotoxy(30,1);
  getch();
  printf("                          ");
  }
  else
  {
  removeme(a,b,m);
  b=b+g;
  createme(a,b,m);
  }
 }
 else if(e=='o')
 {
 if(m==4)
 removeme(a,b,m);
 if(st>1)
 m=m%4+1;
 else
 m=m%3+1;
 gotoxy(70,1);
 printf("          ");
 gotoxy(70,1);
 if(m==1)
 printf("Diagnose");
 else if(m==2)
 printf("Freez");
 else if(m==3)
 printf("Isolation");
 else
 printf("Gun");
 createme(a,b,m);
 }
 else if(e=='g')
 {
  if(m==4)         /////main gun condition starts
  {
  if(B1y==0 && B2x==0 && B3y==0 && B4x==0)
  {
  B1x=a;
  B1y=b-3;
  B2x=a+6;
  B2y=b;
  B3x=a;
  B3y=b+3;
  B4x=a-6;
  B4y=b;
  setcolor(9);
  outtextxy(B1x*7.8,B1y*15.4,"*");
  outtextxy(B1x*7.8,(B1y-1)*15.4,"^");
  outtextxy(B2x*7.8,B2y*15.4,"* >");
  outtextxy(B3x*7.8,B3y*15.4,"*");
  outtextxy(B3x*7.8,(B3y+1)*15.4,"v");
  outtextxy(B4x*7.8,B4y*15.4,"*");
  outtextxy((B4x-1)*7.8,B4y*15.4,"<");
  delay(100);
  }
  }    ////gun condition ends
  else if(m==1)    ////diagnose condition starts
  {
  checkpeople(a,b,P,n);
  }           ////diagnose condition ends
  else if(m==2)   ////freez condition starts
  {
   freezepeople(a,b,P,n,T1);
  }           ////freez condition ends
  else        /////isolation condition starts
  {
  h=isolation(a,b,P,n,h,T1);
  gotoxy(26,1);
  printf("%2d",h);
  }           /////isolation condition ends
 }
 else           /////user input last else
 {
 }
}
/////user inputs ends
//////checking release hospital
for(i=1;i<=2*n;i++)
{
 if((P+i)->h==1 && (P+i)->live==1)
 {
  if((P+i)->ht-T1==5)
  {
  (P+i)->move=1;
  (P+i)->st=1;
  (P+i)->vis=1;
  (P+i)->h=0;
  h++;
  gotoxy(26,1);
  printf("%2d",h);
  (P+i)->x=2+h;
  (P+i)->y=13;
  setcolor(10);
  outtextxy((P+i)->x*7.8,(P+i)->y*15.4,"*");
  refreshtable(P,n,RT,GT);
  }
 }
}
//////checked released hospital
/////checking for last stage
if(T2==500)
{
for(i=1;i<=2*n;i++)
{
if((P+i)->st==2 && (P+i)->live==1 && (P+i)->h==0)
{
if((P+i)->vt-T1>=5)
{
removepeople((P+i)->x,(P+i)->y);
(P+i)->st=3;
createpeople((P+i)->x,(P+i)->y,(P+i)->vis,3);
}
}
}
}
//////checking last stage done
//////checking for last stage death
if(T2==300)
{
for(i=1;i<=2*n;i++)
{
if((P+i)->st==3 && (P+i)->live==1 && (P+i)->h==0)
{
if((P+i)->vt-T1>=20)
{
setcolor(12);
outtextxy(((P+i)->x-2)*7.8,((P+i)->y-1)*15.4,"*    *");
outtextxy(((P+i)->x-2)*7.8,((P+i)->y+1)*15.4,"*    *");
outtextxy(((P+i)->x-2)*7.8,((P+i)->y+2)*15.4," Dead ");
getch();
setcolor(0);
outtextxy(((P+i)->x-2)*7.8,((P+i)->y-1)*15.4,"*    *");
outtextxy(((P+i)->x-2)*7.8,((P+i)->y+1)*15.4,"*    *");
outtextxy(((P+i)->x-2)*7.8,((P+i)->y+2)*15.4," Dead ");
removepeople((P+i)->x,(P+i)->y);
(P+i)->live=0;
kills++;
}
}
}
}
//////checking last stage death complete
//////checking time of freeze
if(T2==500)
{
for(i=1;i<=2*n;i++)
{
if((P+i)->move==0 && (P+i)->live==1 && (P+i)->h==0)
{
if((P+i)->ft-T1==5)
{
(P+i)->move=1;
}
}
}
}
/////checked time of freeze
/////moving people
if(T2==650)
movepeople(P,n,T1,RT,GT);
/////moving people completed
/////bullet
if(T2%6==0)
{
if(B1y!=0 || B2x!=0 || B3y!=0 || B4x!=0)
{
delay(30);
 if(B1y!=0)
 {
  setcolor(0);
  outtextxy(B1x*7.8,B1y*15.4,"*");
  outtextxy(B1x*7.8,(B1y-1)*15.4,"^");
  B1y--;
  if(B1y<3)
  B1y=0;
  else
  {
  setcolor(9);
  outtextxy(B1x*7.8,B1y*15.4,"*");
  outtextxy(B1x*7.8,(B1y-1)*15.4,"^");
  }
 }
 if(B2x!=0)
 {
  setcolor(0);
  outtextxy(B2x*7.8,B2y*15.4,"* >");
  B2x++;
  if(B2x>80)
  B2x=0;
  else
  {
  setcolor(9);
  outtextxy(B2x*7.8,B2y*15.4,"* >");
  }
 }
 if(B3y!=0)
 {
  setcolor(0);
  outtextxy(B3x*7.8,B3y*15.4,"*");
  outtextxy(B3x*7.8,(B3y+1)*15.4,"v");
  B3y++;
  if(B3y>22)
  B3y=0;
  else
  {
  setcolor(9);
  outtextxy(B3x*7.8,B3y*15.4,"*");
  outtextxy(B3x*7.8,(B3y+1)*15.4,"v");
  }
 }
 if(B4x!=0)
 {
  setcolor(0);
  outtextxy(B4x*7.8,B4y*15.4,"*");
  outtextxy((B4x-1)*7.8,B4y*15.4,"<");
  B4x--;
  if(B4x<3)
  B4x=0;
  else
  {
  setcolor(9);
  outtextxy(B4x*7.8,B4y*15.4,"*");
  outtextxy((B4x-1)*7.8,B4y*15.4,"<");
  }
 }
 for(i=1;i<=2*n;i++)
 {
 if((P+i)->h==0 && (P+i)->live==1)
 {
 if(B1x==(P+i)->x && B1y==(P+i)->y)
 {
 removepeople((P+i)->x,(P+i)->y);
 (P+i)->live=0;
 kills++;
 refreshtable(P,n,RT,GT);
 }
 else if(B2x==(P+i)->x && B2y==(P+i)->y)
 {
 removepeople((P+i)->x,(P+i)->y);
 (P+i)->live=0;
 kills++;
 refreshtable(P,n,RT,GT);
 }
 else if(B3x==(P+i)->x && B3y==(P+i)->y)
 {
 removepeople((P+i)->x,(P+i)->y);
 (P+i)->live=0;
 kills++;
 refreshtable(P,n,RT,GT);
 }
 else if(B4x==(P+i)->x && B4y==(P+i)->y)
 {
 removepeople((P+i)->x,(P+i)->y);
 (P+i)->live=0;
 kills++;
 refreshtable(P,n,RT,GT);
 }
 else
 {
 }
 }
 }
}
}
/////bullet ends
//st=2;
/////end of infinite while loop
}
win:
i=2*n-kills;
i=i*100;
i=i/2;
i=i/n;
if(i>=70)
{
settextstyle(0,0,5);
removeme(a,b,m);
setcolor(10);
outtextxy(30*7.8,3*15.4,"You");
if(l==1)
outtextxy(30*7.8,12*15.4,"Daman");
else if(l==2)
outtextxy(30*7.8,12*15.4,"Jaipur");
else if(l==3)
outtextxy(30*7.8,12*15.4,"Kolkata");
else if(l==4)
outtextxy(30*7.8,12*15.4,"Indore");
else if(l==5)
outtextxy(30*7.8,12*15.4,"Chennai");
else if(l==6)
outtextxy(11*7.8,12*15.4,"Ahmedabad");
else
outtextxy(30*7.8,12*15.4,"Mumbai");
outtextxy(30*7.8,7*15.4,"Rescued");
outtextxy(10*7.8,16*15.4,"with   kills");
sprintf(z,"%d",kills);
outtextxy(34*7.8,16*15.4,z);
}
else
goto lost;
goto end;
lost:
removeme(a,b,m);
setcolor(12);
settextstyle(0,0,5);
if(l==1)
outtextxy(30*7.8,12*15.4,"Daman");
else if(l==2)
outtextxy(30*7.8,12*15.4,"Jaipur");
else if(l==3)
outtextxy(30*7.8,12*15.4,"Kolkata");
else if(l==4)
outtextxy(30*7.8,12*15.4,"Indore");
else if(l==5)
outtextxy(30*7.8,12*15.4,"Chennai");
else if(l==6)
outtextxy(11*7.8,12*15.4,"Ahmedabad");
else
outtextxy(30*7.8,12*15.4,"Mumbai");
outtextxy(15*7.8,7*15.4,"Destroyed");
outtextxy(30*7.8,3*15.4,"You");
end:
settextstyle(0,0,2);
gotoxy(35,1);
printf("   ");
outtextxy(240,1,"GAME OVER");
free(RT);
free(GT);
for(i=1;i<=2*n;i++)
free(P+i);
/////end of play
}
//////
void rules()
{
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"C://TC//BGI");
printf("You have total 4 modes");
setcolor(13);
outtextxy(4*7.8,4*15.4,"* * *");
outtextxy(4*7.8,5*15.4,"* * *");
outtextxy(4*7.8,6*15.4,"* * *");
outtextxy(1*7.8,7*15.4,"Diagnose Mode");
setcolor(11);
outtextxy(22*7.8,4*15.4,"* * *");
outtextxy(22*7.8,5*15.4,"* * *");
outtextxy(22*7.8,6*15.4,"* * *");
outtextxy(19*7.8,7*15.4,"Freezing Mode");
setcolor(15);
setcolor(15);
outtextxy(40*7.8,4*15.4,"* * *");
outtextxy(40*7.8,5*15.4,"* * *");
outtextxy(40*7.8,6*15.4,"* * *");
outtextxy(37*7.8,7*15.4,"Isolation Mode");
setcolor(9);
setcolor(9);
outtextxy(58*7.8,2*15.4,"     ^ ");
outtextxy(58*7.8,3*15.4,"     *   ");
outtextxy(58*7.8,4*15.4,"   * * *");
outtextxy(58*7.8,5*15.4,"<* * * * *>");
outtextxy(58*7.8,6*15.4,"   * * *");
outtextxy(58*7.8,7*15.4,"     *");
outtextxy(58*7.8,8*15.4,"     v");
outtextxy(60*7.8,9*15.4,"Gun Mode");
gotoxy(1,10);
printf("Controls:\n");
printf("a for left\n");
printf("l for right\n");
printf("t for up\n");
printf("v for down\n");
printf("j for gear up\n");
printf("d for gear down\n");
printf("o for changing your mode\n");
printf("g for checking stage(normal, 1st or last stage), freezing, sending hospital, \n  killing people(if situation is getting worst)\n");
printf("Gun will be available after 30 seconds\n");
printf("Press any key for further....");
getch();
closegraph();
clrscr();
initgraph(&gd,&gm,"C://TC//BGI");
printf("There will be 3 types of people");
settextstyle(0,0,2);
setcolor(7);
outtextxy(10*7.8,3*15.4,"*");
outtextxy(1*7.8,4*15.4,"Undiagnosed");
outtextxy(3*7.8,5*15.4,"People");
setcolor(10);
outtextxy(33*7.8,3*15.4,"*");
outtextxy(27*7.8,4*15.4,"Normal");
outtextxy(27*7.8,5*15.4,"People");
setcolor(14);
outtextxy(54*7.8,3*15.4,"*");
outtextxy(49*7.8,4*15.4,"First");
outtextxy(49*7.8,5*15.4,"Stage");
setcolor(12);
outtextxy(73*7.8,3*15.4,"*");
outtextxy(70*7.8,4*15.4,"Last");
outtextxy(70*7.8,5*15.4,"Stage");
gotoxy(1,7);
printf("Initially all people are undiagnosed\n");
printf("You can diagnose and freeze them\n");
printf("1st stage will be till 5 seconds after that people will go in last stage\n");
printf("Last stage peoole can only survive upto 15 seconds after that they will die\n");

printf("People will be freezed for 5 seconds\n");
printf("Without diagnosing people you can't isolate them\n");
printf("Hospital can release people in 5 seconds\n");
printf("Start from level 1 and move step by step,dont jump in between levels\n");
printf("Wining:\n");
printf("If all the people gets normal \nOr after killing some people 70 percent or more people must be alive\n");
printf("Loosing:\n");
printf("If all the people are affected \nOr more than 30 percent people are killed or died\n");
printf("Press any key to continue.....");
getch();
closegraph();
}
//////
void main()
{
clrscr();
int i,gd=DETECT,gm,n;
char e;
n=1;
struct people *P;
P=(struct people*)malloc(sizeof(struct people)*(2*n+1));
initgraph(&gd,&gm,"C://TC//BGI");
setcolor(3);
settextstyle(0,0,4);
outtextxy(10*7.8,10*15.4,"Rescue The City");
gotoxy(50,23);
printf("Press any key to continue.....");
getch();
closegraph();
while(1)
{
clrscr();
printf("Press your choice\n");
printf("Press 1 to Play\n");
printf("Press 2 to check rules\n");
printf("Press 3 to exit");
e=getch();
if(e=='1')
{
while(1)
{
clrscr();
printf("Press the number of level\n");
printf("Level 1: Daman\n");
printf("Level 2: Jaipur\n");
printf("Level 3: Kolkata\n");
printf("Level 4: Indore\n");
printf("Level 5: Chennai\n");
printf("Level 6: Ahmedabad\n");
printf("Level 7: Mumbai\n");
printf("Press e to exit");
e=getch();
if(e=='1')
n=1;
else if(e=='2')
n=2;
else if(e=='3')
n=3;
else if(e=='4')
n=4;
else if(e=='5')
n=5;
else if(e=='6')
n=6;
else if(e=='7')
n=7;
else if(e=='e')
goto exits1;
else
goto over;
////game begains
/////setting ground
for(i=1;i<=40;i++)
{
gotoxy(i*2,2);
printf("*");
gotoxy(i*2,24);
printf("*");
}
for(i=1;i<=24;i++)
{
gotoxy(1,i);
printf("*");
gotoxy(80,i);
printf("*");
}
gotoxy(1,1);
printf(" ");
gotoxy(80,1);
printf(" ");
////setting ground ends
initgraph(&gd,&gm,"C://TC//BGI");
play(P,n,n);
gotoxy(50,23);
printf("Press any key to continue.....");
getch();
closegraph();
over:
}
}
else if(e=='2')
rules();
else if(e=='3')
goto exits;
else
{}
exits1:

}
exits:
gotoxy(40,14);
printf("Game Exited");
getch();
}