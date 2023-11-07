#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
//////
void createdot(int a,int b,int c)
{
if(c!=7)
setcolor(9);
else
setcolor(12);
outtextxy(a*7.8,b*15.4,"#");
}
/////
void removedot(int a,int b)
{
setcolor(0);
outtextxy(a*7.8,b*15.4,"#");
}
/////
void removeme(int a,int b,int m)
{
setcolor(0);
outtextxy((a-2)*7.8,b*15.4,"* * *");
outtextxy((a-2)*7.8,(b-1)*15.4,"* * *");
outtextxy((a-2)*7.8,(b+1)*15.4,"* * *");
if(m==2)
{
line((a+3)*7.8,15.4*b,(a+4)*7.8,15.4*b);
line((a+4)*7.8,b*15.4,(a+5)*7.8,(b-3)*15.4);
}
if(m==3)
{
line((a+3)*7.8,15.8*b,(a+5)*7.8,15.8*b);
line((a+5)*7.8,b*15.8,(a+5)*7.8,(b-3)*15.4);
line((a+4)*7.8,(b-1)*15.8,(a+6)*7.8,(b-1)*15.8);
}
if(m==4)
{
setcolor(0);
line((a+3)*7.8,15.4*b,(a+4)*7.8,15.4*b);
line((a+4)*7.8,b*15.4,(a+5)*7.8,(b-3)*15.4);
}
if(m==5 || m==6)
{
line((a-3)*7.8,15.4*b,(a-4)*7.8,15.4*b);
line((a-4)*7.8,b*15.4,(a-5)*7.8,(b-3)*15.4);
}
}
void createme(int a,int b,int m)
{
if(m==1 || m==2 || m==3 || m==4)
setcolor(2);
else if(m==5)
setcolor(14);
else
setcolor(8);
outtextxy((a-2)*7.8,b*15.4,"* * *");
outtextxy((a-2)*7.8,(b-1)*15.4,"* * *");
outtextxy((a-2)*7.8,(b+1)*15.4,"* * *");
if(m==2)
{
setcolor(10);
line((a+3)*7.8,15.4*b,(a+4)*7.8,15.4*b);
line((a+4)*7.8,b*15.4,(a+5)*7.8,(b-3)*15.4);

}
if(m==3)
{
setcolor(15);
line((a+3)*7.8,15.8*b,(a+5)*7.8,15.8*b);
line((a+5)*7.8,b*15.8,(a+5)*7.8,(b-3)*15.4);
line((a+4)*7.8,(b-1)*15.8,(a+6)*7.8,(b-1)*15.8);
}
if(m==4)
{
setcolor(14);
line((a+3)*7.8,15.4*b,(a+4)*7.8,15.4*b);
line((a+4)*7.8,b*15.4,(a+5)*7.8,(b-3)*15.4);
}
if(m==5 || m==6)
{
line((a-3)*7.8,15.4*b,(a-4)*7.8,15.4*b);
line((a-4)*7.8,b*15.4,(a-5)*7.8,(b-3)*15.4);
}
}
//////
void createcup(int y)
{
setcolor(12);
ellipse(70*7.8,y*15.4,180,360,15,30);              //upper curve
ellipse(70*7.8,(y+3)*15.4,0,180,15,8);             //bottom curve
line(68*7.8,(y+3)*15.4,72*7.8,(y+3)*15.4);  //bottom line
line(70*7.8,(y+2)*15.4,70*7.8,(y+3)*14.8);          //vertical line
line(68*7.8,y*15.4,72*7.8,y*15.4);  //upper line
}
////
void removecup(int y)
{
setcolor(0);
ellipse(70*7.8,y*15.4,180,360,15,30);              //upper curve
ellipse(70*7.8,(y+3)*15.4,0,180,15,8);             //bottom curve
line(68*7.8,(y+3)*15.4,72*7.8,(y+3)*15.4);  //bottom line
line(70*7.8,(y+2)*15.4,70*7.8,(y+3)*14.8);          //vertical line
line(68*7.8,y*15.4,72*7.8,y*15.4);  //upper line
}
void win(int a,int b)
{
int a1,a3;
setcolor(8);
outtextxy(a*7.8,b*15.4,"*");
delay(500);
a1=a;
a3=a;
while(b>=2)
{
b--;
a1=a1-2;
a3=a3+2;
outtextxy(a*7.8,b*15.4,"*");
if(a1>=1)
outtextxy(a1*7.8,b*15.4,"*");
if(a3<=79)
outtextxy(a3*7.8,b*15.4,"*");
delay(100);
}
}
int level1()
{
closegraph();
clrscr();
int gd=DETECT,gm,l;
initgraph(&gd,&gm,"C://TC//BGI");
gotoxy(20,2);
printf("Level 1:Destory Tom Riddle's diary\n \n");
printf("Press a for left\n");
printf("Press l for right\n");
printf("Press t for up\n");
printf("Press v for down\n");
printf("Press j to activate sword\n");
printf("Press g to hit with sword\n");
printf("These controls will be same throughout the game\n");
printf("First kill the snake with sword and then destroy the diary using same sword\n");
printf("If the snake bytes you, you looses\n");
printf("You have to destroy within 120 seconds");
setcolor(9);
settextstyle(0,0,1);
outtextxy(2*7.8,15*15.4,"#######");
outtextxy(4*7.8,16*15.4,"Snake");
setcolor(12);
outtextxy(15*7.8,15*15.4,"* * *");
outtextxy(15*7.8,16*15.4,"* * *");
outtextxy(15*7.8,17*15.4,"* * *");
outtextxy(15*7.8,18*15.4,"Diary");
setcolor(2);
outtextxy(30*7.8,15*15.4,"* * *");
outtextxy(30*7.8,16*15.4,"* * *");
outtextxy(30*7.8,17*15.4,"* * *");
outtextxy(31*7.8,18*15.4,"You");
gotoxy(47,23);
printf("press any key to start game.....");
getch();
closegraph();
clrscr();
initgraph(&gd,&gm,"C://TC//BGI");
int a,b,m,T1,T2,x[7],y[7],i,st=1,d=1,life=1;
char e;
a=10;
b=10;
m=1;
T1=120;
T2=1300;
createme(a,b,m);
setcolor(9);
for(i=1;i<=6;i++)
{
x[i]=40;
y[i]=9+i;
outtextxy(x[i]*7.8,y[i]*15.4,"#");
}
setcolor(4);
for(i=13;i<=15;i++)
outtextxy(43*7.8,i*15.4,"* * *");
while(1)        /////infinite loop starts
{
/////snake starts
if(life==1)
{
if(T2%50==0)            ///snake speed
{
removedot(x[6],y[6]);
for(i=6;i>=2;i--)
{
x[i]=x[i-1];
y[i]=y[i-1];
}
if(st==1)
{
 if(d==1)
 x[1]++;
 else if(d==2)
 y[1]++;
 else if(d==3)
 x[1]--;
 else
 y[1]--;
 if(x[1]==40 && y[1]==10)
 d=d%4+1;
 else if(x[1]==50 && y[1]==10)
 d=d%4+1;
 else if(x[1]==50 && y[1]==20)
 d=d%4+1;
 else if(x[1]==40 && y[1]==20)
 d=d%4+1;
 else
 {}
}
else          /////chasing else
{
 if(x[1]<a+5)
 x[1]++;
 else
 {
   if(b==y[1])
   {
   x[1]--;
   if(x[1]<=a+4)
   goto lost;
   }
   else if(b>y[1])
   y[1]++;
   else
   y[1]--;
 }
}
createdot(x[1],y[1],1);
}
}
//////snake ends
//////clock starts
T2--;
if(T2==0)
{
T1--;
T2=1300;
}
if(T1==0)
goto lost;
gotoxy(75,1);
printf("%3d",T1);
//////clock ends
if(kbhit())    /////user input starts
{
e=getch();
if(e=='0')
goto end;
else if(e=='j')
{
removeme(a,b,m);
m=m%3+1;
if(m==2)
m=3;
createme(a,b,m);
}
else if(e=='l')
{
 if(a>74)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 a++;
 createme(a,b,m);
 if(a>20)
 st=2;
 }
}
else if(e=='a')
{
 if(a<4)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 a--;
 createme(a,b,m);
 }
}
else if(e=='t')
{
 if(b<6)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 b--;
 createme(a,b,m);
 }
}
else if(e=='v')
{
 if(b>21)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 b++;
 createme(a,b,m);
 }
}
else if(e=='g')
{
if(m==3)
{
setcolor(0);
line((a+5)*7.8,b*15.8,(a+5)*7.8,(b-3)*15.4);
line((a+4)*7.8,(b-1)*15.8,(a+6)*7.8,(b-1)*15.8);
setcolor(15);
//line((a+3)*7.8,15.8*b,(a+5)*7.8,15.8*b);
line((a+5)*7.8,b*15.8,(a+12)*7.8,b*15.8);
line((a+6)*7.8,(b-1)*16,(a+6)*7.8,(b+1)*15.4);
////check for kill
if(y[1]==b && x[1]>=a+7 && a+12>=x[1])
life=0;
if(b>=13 && b<=15 && a+12>=43 && a+12<=47)
goto won;
delay(100);
setcolor(15);
line((a+5)*7.8,b*15.8,(a+5)*7.8,(b-3)*15.4);
line((a+4)*7.8,(b-1)*15.8,(a+6)*7.8,(b-1)*15.8);
setcolor(0);
line((a+5)*7.8,b*15.8,(a+12)*7.8,b*15.8);
line((a+6)*7.8,(b-1)*16,(a+6)*7.8,(b+1)*15.4);
}
}
else     ////last else of user input
{}
}        /////user input ends
}              ////end of infinite loop
won:
win(45,14);
a1:
gotoxy(55,23);
printf("Press 6 to continue....");
if(getch()!='6')
goto a1;
return 1;
lost:
setcolor(12);
settextstyle(0,0,5);
outtextxy(20*7.8,5*15.4,"GAME OVER");
outtextxy(21*7.8,10*15.4,"YOU LOST");
a2:
gotoxy(55,23);
printf("Press 6 to exit.....");
if(getch()!='6')
goto a2;
return 0;
end:
gotoxy(35,1);
printf("GAME OVER");
return 0;
}
///////
int level2()
{
closegraph();
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"C://TC//BGI");
gotoxy(20,3);
printf("Level 2:Destroy Marvolo's Ring\n \n");
printf("Same motion control and sword controls\n");
printf("You have to escape from the little statues which hits spell while passing from\nthem\n");
printf("If you are hitted from spell then you looses\n");
printf("Destroy the ring using sword within 120 seconds\n");
setcolor(12);
circle(10*7.8,20*15.4,10);
outtextxy(8*7.8,21*15.4,"Ring");
gotoxy(47,23);
printf("press any key to start level....");
getch();
closegraph();
clrscr();
int l,T1,T2,a,b,m,i,x,y,B[10];
char e;
initgraph(&gd,&gm,"C://TC//BGI");
T1=120;
T2=1300;
a=5;
b=10;
m=1;
setcolor(12);
circle(78*7.8,13*15.4,10);
circle(78*7.8,13*15.4,11);
for(i=1;i<=9;i++)
B[i]=-1;
setcolor(9);
for(i=1;i<=9;i++)
{
x=6*(1+i);
if(i%2==0)
{
y=24;
outtextxy((x+2)*7.8,(y-1)*15.4,"*");
outtextxy((x+2)*7.8,(y-2)*15.4,"*");
}
else
{
y=2;
outtextxy((x+2)*7.8,(y+2)*15.4,"*");
outtextxy((x+2)*7.8,(y+1)*15.4,"*");
}
outtextxy(x*7.8,y*15.4,"* * *");
}
createme(a,b,m);
while(1)            ///start of infinite loop
{
//////clock starts
T2--;
if(T2==0)
{
T1--;
T2=1300;
}
if(T1==0)
goto lost;
gotoxy(75,1);
printf("%3d",T1);
//////clock ends
if(kbhit())    /////user input starts
{
e=getch();
if(e=='0')
goto end;
else if(e=='j')
{
removeme(a,b,m);
m=m%3+1;
if(m==2)
m=3;
createme(a,b,m);
}
else if(e=='l')
{
 if(a>74)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 a++;
 createme(a,b,m);
 }
}
else if(e=='a')
{
 if(a<4)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 a--;
 createme(a,b,m);
 }
}
else if(e=='t')
{
 if(b<8)
 {
 gotoxy(40,1);
 printf("Be Inside");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 b--;
 createme(a,b,m);
 }
}
else if(e=='v')
{
 if(b>18)
 {
 gotoxy(40,1);
 printf("Be Inside");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 b++;
 createme(a,b,m);
 }
}
else if(e=='g')
{
if(m==3)
{
setcolor(0);
line((a+5)*7.8,b*15.8,(a+5)*7.8,(b-3)*15.4);
line((a+4)*7.8,(b-1)*15.8,(a+6)*7.8,(b-1)*15.8);
setcolor(15);
//line((a+3)*7.8,15.8*b,(a+5)*7.8,15.8*b);
line((a+5)*7.8,b*15.8,(a+12)*7.8,b*15.8);
line((a+6)*7.8,(b-1)*16,(a+6)*7.8,(b+1)*15.4);
////check for destroy
if(b==13 && a>=66 && a<=70)
goto won;
delay(100);
setcolor(15);
line((a+5)*7.8,b*15.8,(a+5)*7.8,(b-3)*15.4);
line((a+4)*7.8,(b-1)*15.8,(a+6)*7.8,(b-1)*15.8);
setcolor(0);
line((a+5)*7.8,b*15.8,(a+12)*7.8,b*15.8);
line((a+6)*7.8,(b-1)*16,(a+6)*7.8,(b+1)*15.4);
}
}
else     ////last else of user input
{}
}
/////user input ends
////check for fire
if(T2%200==0)
{
for(i=1;i<=9;i++)
{
if(B[i]==-1)
{
setcolor(9);
x=6*(1+i);
if(a+2>=x && a-2<=x+4)
{
if(i%2!=0)
{
B[i]=6;
outtextxy((2+x)*7.8,6*15.4,"v");
outtextxy((x+2)*7.8,7*15.4,"*");
}
else
{
B[i]=20;
outtextxy((x+2)*7.8,20*15.4,"^");
outtextxy((x+2)*7.8,19*15.4,"*");
}
}
}
}
}                          /////checked for fire
if(T2%300==0)
{
for(i=1;i<=9;i++)          ////firing bullet
{
if(B[i]!=-1)
{
x=6*(1+i)+2;
setcolor(0);
 if(i%2!=0)
 {
   outtextxy(x*7.8,B[i]*15.4,"v");
   outtextxy(x*7.8,(B[i]-1)*15.4,"*");
   B[i]++;
   setcolor(9);
   outtextxy(x*7.8,B[i]*15.4,"v");
   outtextxy(x*7.8,(B[i]-1)*15.4,"*");
   if(x>=a-2 && x<=a+2 && B[i]>=b-1 && B[i]<=b+1)
   goto lost;
   if(B[i]==24)
   {
   setcolor(0);
   outtextxy(x*7.8,B[i]*15.4,"v");
   outtextxy(x*7.8,(B[i]-1)*15.4,"*");
   B[i]=-1;
   }
 }
 else
 {
   outtextxy(x*7.8,B[i]*15.4,"^");
   outtextxy(x*7.8,(B[i]+1)*15.4,"*");
   B[i]--;
   setcolor(9);
   outtextxy(x*7.8,B[i]*15.4,"^");
   outtextxy(x*7.8,(B[i]+1)*15.4,"*");
   if(x>=a-2 && x<=a+2 && B[i]>=b-1 && B[i]<=b+1)
   goto lost;
   if(B[i]==2)
   {
   setcolor(0);
   outtextxy(x*7.8,B[i]*15.4,"^");
   outtextxy(x*7.8,(B[i]+1)*15.4,"*");
   B[i]=-1;
   }
 }
}
}
}               /////fired bullet
}	 ////end of infinite loop
won:
win(78,13);
a1:
gotoxy(55,23);
printf("Press 6 to continue....");
if(getch()!='6')
goto a1;
return 1;
lost:
setcolor(12);
settextstyle(0,0,5);
outtextxy(20*7.8,5*15.4,"GAME OVER");
outtextxy(21*7.8,10*15.4,"YOU LOST");
a2:
gotoxy(55,23);
printf("Press 6 to exit.....");
if(getch()!='6')
goto a2;
return 0;
end:
gotoxy(35,1);
printf("Game Over");
return 0;
}
/////
int level3()
{
closegraph();
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"C://TC//BGI");
gotoxy(20,3);
printf("Level 3:Destroy Salazar's locket\n \n");
printf("Same motion control and sword controls\n");
printf("You will be provided with a wand\n");
printf("Press j to switch between wand and sword\n");
printf("You are in a dark room and you have to find the locket\n");
printf("There is a torch inside your wand, press g to start/stop torch\n");
printf("Torch will help you only for 20 seconds\n");
printf("Torch will not show you the locket but it will show you red 'x' mark, which\nindicates the center of locket\n");
printf("Find the red 'x' mark before torch losses its power and hit it with sword near\nred 'x' mark\n");
printf("If you didnt found red 'x' mark before 20 seconds you can simply hit anywhere in dark\n");
printf("Destroy the locket using sword within 120 seconds\n");
gotoxy(47,23);
printf("press any key to start game....");
getch();
closegraph();
clrscr();
int l,T1,T2,a,b,m,i,x,y,t=0,tt=25,v=0;
char e;
initgraph(&gd,&gm,"C://TC//BGI");
T1=120;
T2=1300;
a=5;
b=10;
srand(time(0));
x=rand()%61+10;
y=rand()%13+6;
m=1;
createme(a,b,m);

while(1)            ///start of infinite loop
{
if(T2==500)
{
if(v==1)
setcolor(12);
else
setcolor(0);
outtextxy(x*7.8,y*15.4,"X");
if(b>=y-10 && b<=y+10 && a>=x-10 && a<=x+10 && t==1)
v=1;
else
v=0;
}

//////checking tourch time
if(t==1)
{
if(T2==500)
tt--;
if(tt==0)
{
removeme(a,b,m);
m=2;
createme(a,b,m);
t=0;
}
}
//////tourch time checked
//////clock starts
T2--;
if(T2==0)
{
T1--;
T2=1300;
}
if(T1==0)
goto lost;
gotoxy(75,1);
printf("%3d",T1);
//////clock ends
if(kbhit())    /////user input starts
{
e=getch();
if(e=='0')
goto end;
else if(e=='j')
{
removeme(a,b,m);
if(m==4)
t=0;
m=m%3+1;
createme(a,b,m);
}
else if(e=='l')
{
 if(a>74)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 a++;
 createme(a,b,m);
 }
}
else if(e=='a')
{
 if(a<4)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 a--;
 createme(a,b,m);
 }
}
else if(e=='t')
{
 if(b<4)
 {
 gotoxy(40,1);
 printf("Be Inside");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 b--;
 createme(a,b,m);
 }
}
else if(e=='v')
{
 if(b>22)
 {
 gotoxy(40,1);
 printf("Be Inside");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 b++;
 createme(a,b,m);
 }
}
else if(e=='g')
{
if(m==4)
{
removeme(a,b,m);
m=2;
createme(a,b,m);
t=0;
}
else if(m==2)
{
if(tt>=0)
{
removeme(a,b,m);
m=4;
createme(a,b,m);
t=1;
}
}
else if(m==3)
{
setcolor(0);
line((a+5)*7.8,b*15.8,(a+5)*7.8,(b-3)*15.4);
line((a+4)*7.8,(b-1)*15.8,(a+6)*7.8,(b-1)*15.8);
setcolor(15);
//line((a+3)*7.8,15.8*b,(a+5)*7.8,15.8*b);
line((a+5)*7.8,b*15.8,(a+12)*7.8,b*15.8);
line((a+6)*7.8,(b-1)*16,(a+6)*7.8,(b+1)*15.4);
////check for destroy
if(b>=y-1 && b<=y+2 && a>=x-11 && a<=x-9)
{
setcolor(12);
ellipse(x*7.8,y*15.4,135,405,20,40);
goto won;
}
delay(100);
setcolor(15);
line((a+5)*7.8,b*15.8,(a+5)*7.8,(b-3)*15.4);
line((a+4)*7.8,(b-1)*15.8,(a+6)*7.8,(b-1)*15.8);
setcolor(0);
line((a+5)*7.8,b*15.8,(a+12)*7.8,b*15.8);
line((a+6)*7.8,(b-1)*16,(a+6)*7.8,(b+1)*15.4);
}
else
{}
}
else     ////last else of user input
{}
}
/////user input ends
}     ////end of infinite loop
won:
win(x,y);
a1:
gotoxy(55,23);
printf("Press 6 to continue....");
if(getch()!='6')
goto a1;
return 1;
lost:
setcolor(12);
settextstyle(0,0,5);
outtextxy(20*7.8,5*15.4,"GAME OVER");
outtextxy(21*7.8,10*15.4,"YOU LOST");
a2:
gotoxy(55,23);
printf("Press 6 to exit.....");
if(getch()!='6')
goto a2;
return 0;
end:
gotoxy(35,1);
printf("Game Over");
return 0;
}
/////
int level4()
{
closegraph();
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"C://TC//BGI");
gotoxy(20,3);
printf("Level 4:Destroy Hufflepuff's Cup\n \n");
printf("Here you and cup cant go right and left, just can move up and down\n");
printf("Here you will get 2 spells: Stupefy and Expecto Petronum\n");
printf("Press j to navigate spell and g to cast the spell\n");
printf("Stupefy: this is simple fast spell\n");
printf("Expecto Pertonum: after casting the spell, it will remain for 5 seconds\n");
printf("You can change direction of this spell using them\n");
printf("l= right, a=left, t=up, v=down\n");
printf("Be quick using this spell and use some common sense here\n");
printf("Destroy the cup using any spell within 120 seconds\n");
gotoxy(47,23);
printf("press any key to start game....");
getch();
closegraph();
clrscr();
int l,T1,T2,b,m,i,y=10,Sy=0,Sx=0,Ex[6],Ey[6],w=0,st,d=1,turn=0;
char e;
initgraph(&gd,&gm,"C://TC//BGI");
T1=120;
T2=1300;
b=10;
m=1;
createme(5,b,m);
createcup(y);
Ex[1]=0;
Ey[1]=0;
st=0;
while(1)            ///start of infinite loop
{
//////clock starts
T2--;
if(T2==0)
{
T1--;
T2=1300;
}
if(T1==0)
goto lost;
gotoxy(75,1);
printf("%3d",T1);
//////clock ends
if(kbhit())    /////user input starts
{
e=getch();
if(e=='0')
goto end;
else if(e=='j')
{
removeme(5,b,m);
if(m==2 && w==0)
{
w=1;
gotoxy(20,2);
printf("Spell:Stupefy          ");
}
else
{
m=m%2+1;
w=0;
gotoxy(20,2);
if(m==1)
printf("                      ");
else
printf("Spell:Expecto Petronum");
}
createme(5,b,m);
}
else if(e=='t')
{
if(st!=0 && Ex[1]!=0 && Ey[1]!=0)
d=4;
else
{
 if(b<4)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(5,b,m);
 b--;
 createme(5,b,m);
 }
 }
}
else if(e=='v')
{
if(st!=0 && Ex[1]!=0 && Ey[1]!=0)
d=2;
else
{
 if(b>22)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(5,b,m);
 b++;
 createme(5,b,m);
 }
 }
}
else if(e=='g')
{
if(m==2)
{
setcolor(0);
line(9*7.8,b*15.4,10*7.8,(b-3)*15.4);
setcolor(10);
line(9*7.8,b*15.4,15*7.8,(b-1)*15.4);
/////wand
if(w==0)
{
if(Ex[1]==0 && Ey[1]==0)
{
d=1;
st=5;
for(i=1;i<=5;i++)
{
delay(50);
Ey[6-i]=b-1;
Ex[6-i]=15+i;
setcolor(10);
outtextxy(Ex[6-i]*7.8,Ey[6-i]*15.4,"*");
}
}
}
else
{
if(Sx==0 && Sy==0)
{
Sy=(b-1);
Sx=15;
setcolor(10);
outtextxy(Sx*7.8,Sy*15.4,"*");
}
}
delay(100);
setcolor(0);
line(9*7.8,b*15.4,15*7.8,(b-1)*15.4);
setcolor(10);
line(9*7.8,b*15.4,10*7.8,(b-3)*15.4);
}
}
else if(e=='l')
d=1;
else if(e=='a')
d=3;
else     ////last else of user input
{}
}
/////user input ends
/////1st spell
if(Ex[1]!=0 && Ey[1]!=0 && T2==500)
st--;
if(st==0 && Ex[1]!=0 && Ey[1]!=0)
{
stopspell:
setcolor(0);
for(i=1;i<=5;i++)
outtextxy(Ex[i]*7.8,Ey[i]*15.4,"*");
Ex[1]=0;
Ey[1]=0;
}
if(T2%30==0)           ///1st spell speed
{
if(st!=0)
{
setcolor(0);
outtextxy(Ex[5]*7.8,Ey[5]*15.4,"*");
for(i=2;i<=5;i++)
{
Ex[7-i]=Ex[6-i];
Ey[7-i]=Ey[6-i];
}
if(d==1)
Ex[1]++;
else if(d==2)
Ey[1]++;
else if(d==3)
Ex[1]--;
else
Ey[1]--;
setcolor(10);
outtextxy(Ex[1]*7.8,Ey[1]*15.4,"*");
if(Ex[1]>=68 && Ey[1]>=y && Ey[1]<=y+2 && Ex[1]<=72)       ////destroying condition
goto won;
if(Ex[1]==1 || Ex[1]==79 || Ey[1]==1 || Ey[1]==23)
{st=0;
goto stopspell;
}
}
}
/////1st spell ends
/////Stupefy starts
if(T2%10==0 && Sy!=0)
{
setcolor(0);
outtextxy(Sx*7.8,Sy*15.4,"*");
Sx++;
setcolor(10);
outtextxy(Sx*7.8,Sy*15.4,"*");              ///destroying condition
if(Sx==69 && Sy>=y && Sy<=y+2)
goto won;
if(Sx==79)
{
setcolor(0);
outtextxy(Sx*7.8,Sy*15.4,"*");
Sx=0;
Sy=0;
}
}
/////Stupefy ends
///  start of cup
if(T2%150==0)               ////thinking speed to defend
{
if(Sx!=0 && Sy!=0)          ///active stupefy
{
if(Sy>=y && Sy<=y+2)        ///hitting spell
{ ////movement starts
removecup(y);
if(turn==0)
{
y--;
if(y==3)
turn=1;
}
else
{
y++;
if(y==21)
turn=0;
}
createcup(y);
////movement ends
}                        ////hitting stupefy
}
else
{
if(Ex[1]!=0 && Ey[1]!=0 && st!=0)    //active 1st spell
{
if(Ey[1]>=y && Ey[1]<=y+2)        ///hitting 1st spell
{ ////movement starts
removecup(y);
if(turn==0)
{
y--;
if(y==3)
turn=1;
}
else
{
y++;
if(y==21)
turn=0;
}
createcup(y);
////movement ends
}                        ////hitting 1st spell
}
}                  ///active 1st spell
}
////end of cup
}       ////end of infinite loop
won:
win(70,y);
a1:
gotoxy(55,23);
printf("Press 6 to continue....");
if(getch()!='6')
goto a1;
return 1;
lost:
setcolor(12);
settextstyle(0,0,5);
outtextxy(20*7.8,5*15.4,"GAME OVER");
outtextxy(21*7.8,10*15.4,"YOU LOST");
a2:
gotoxy(55,23);
printf("Press 6 to exit.....");
if(getch()!='6')
goto a2;
return 0;
end:
gotoxy(35,1);
printf("Game Over");
return 0;
}
//////
int level5()
{
int gd=DETECT,gm;
closegraph();
clrscr();

initgraph(&gd,&gm,"C://TC//BGI");
gotoxy(20,3);
printf("Level 5:Destroy Ravenclaw's crown\n \n");
printf("Here you can move in all 4 direction and you get one extra spell\n");
printf("Before distroying the crown, you have to defeate Draco Malfoi\n");
printf("Both health will be shown on top\n");
printf("press j for switching spells and g for casting spell\n");
printf("3rd spell is Avada Kedavra:It is very strong spell\n");
printf("This will directly kill him and vice versa\n");
printf("The one who cast this spell will be freezed for 3 seconds\n");
printf("Crown will be visible after dedeating him\n");
printf("Destroy the crown using any spell within 120 seconds\n");
gotoxy(47,23);
printf("press any key to start game....");
getch();
closegraph();
clrscr();
int life,l,T1,T2,a,b,m,i,y,x,w,lev1,lev2,mob1,mob2,st1,st2,d1,d2,tu1,tu2;
int S1x,S1y,S2x,S2y,E1x[6],E1y[6],E2x[6],E2y[6],A1x,A1y,A1z,A2x,A2y,A2z,dts,ats,o;
char e;
initgraph(&gd,&gm,"C://TC//BGI");
o=0;
T1=120;
T2=1300;
a=5;
b=8;
m=1;
x=60;
y=14;
w=0;
mob1=1;
mob2=1;
lev1=10;
lev2=10;
S1x=0;
S1y=0;
S2x=0;
S2y=0;
st1=0;
st2=0;
E1x[1]=0;
E1y[1]=0;
d1=1;
E2x[1]=0;
E2y[1]=0;
d2=1;
A1x=0;
A1y=0;
A1z=0;
A2x=0;
A2y=0;
A2z=0;
tu1=1;
tu2=1;
dts=350;
ats=600;
life=40;
setcolor(10);
for(i=2;i<=11;i++)
outtextxy(i*7.8,15.4,"*");
setcolor(14);
for(i=1;i<=10;i++)
outtextxy((65+i)*7.8,15.4,"*");
createme(a,b,m);
createme(x,y,5);
while(1)            ///start of infinite loop
{
/////my health
if(lev1<=0)
goto lost;
////my health checked
/////his helath
if(lev2<=0)
{
mob2=0;
removeme(x,y,5);
life=76;
setcolor(12);
ellipse(60*7.8,10*15.4,315,225,25,5);
line(59*7.8,10*15,60*7.8,9*15.4);
line(61*7.8,10*15,60*7.8,9*15.4);
}
/////his health checked
//////clock starts
T2--;
if(T2==0)
{
T1--;
T2=1300;
}
if(T1==0)
goto lost;
gotoxy(40,1);
printf("%3d",T1);
//////clock ends
/////mobility starts
if(mob1!=1)
 if(T2==500)
 mob1--;
if(mob2!=1)
 if(T2==500)
 mob2--;
/////mobility ends
if(kbhit())    /////user input starts
{
e=getch();
if(e=='0')
goto end;
if(mob1==1)
if(e=='j')
{
removeme(a,b,m);
if(m==2 && w==3)
{
m=1;
w=0;
gotoxy(30,2);
printf("                      ");
}
else
{
m=2;
w++;
gotoxy(30,2);
if(w==1)
printf("Spell:Stupefy          ");
else if(w==2)
printf("Spell:Expecto Petronum");
else
printf("Spell:Avada Kedavra   ");
}
createme(a,b,m);
}
else if(e=='t')
{
if(st1!=0)
d1=4;
 if(b<4)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 b--;
 createme(a,b,m);
 }
}
else if(e=='v')
{
if(st1!=0)
d1=2;
 if(b>22)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 b++;
 createme(a,b,m);
 }
}
else if(e=='g')
{
if(m==2)
{
setcolor(0);
line((a+4)*7.8,b*15.4,(a+5)*7.8,(b-3)*15.4);
setcolor(10);
line((a+4)*7.8,b*15.4,(a+10)*7.8,(b-1)*15.4);
/////wand
if(w==1 && S1x==0 && S1y==0)
{
S1y=(b-1);
S1x=a+10;
setcolor(10);
outtextxy(S1x*7.8,S1y*15.4,"*");
}
else if(w==2 && st1==0)
{
d1=1;
st1=5;
setcolor(10);
for(i=1;i<=5;i++)
{
delay(50);
E1y[6-i]=b-1;
E1x[6-i]=a+10+i;
outtextxy(E1x[6-i]*7.8,E1y[6-i]*15.4,"*");
}
}
else if(w==3 && A1x==0 && A1y==0)
{
mob1=3;
A1y=(b-1);
A1x=a+10;
setcolor(10);
outtextxy(A1x*7.8,A1y*15.4,"*");
A1z=A1x;
goto av;
}
else
{}
delay(100);
setcolor(0);
line((a+4)*7.8,b*15.4,(a+10)*7.8,(b-1)*15.4);
setcolor(10);
line((a+4)*7.8,b*15.4,(a+5)*7.8,(b-3)*15.4);
}
}
else if(e=='l')
{
if(st1!=0)
d1=1;
 if(a>life)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 a++;
 createme(a,b,m);
 }
}
else if(e=='a')
{
if(st1!=0)
d1=3;
 if(a<4)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 a--;
 createme(a,b,m);
 }
}
else     ////last else of user input
{}
}
/////user input ends
/////my spell 1 starts
if(T2%10==0 && S1y!=0)
{
setcolor(0);
outtextxy(S1x*7.8,S1y*15.4,"*");
S1x++;
setcolor(10);
outtextxy(S1x*7.8,S1y*15.4,"*");
if(S1x==60 && S1y==10 && life==76)
goto won;
if(S1x>=x-2 && S1x<=x+2 && S1y>=y-1 && S1y<=y+1 && life==40) ///destroying condition
{
setcolor(0);
outtextxy(S1x*7.8,S1y*15.4,"*");
S1x=0;
S1y=0;
outtextxy((65+lev2)*7.8,15.4,"*");
lev2--;
}
if(S1x==79)
{
setcolor(0);
outtextxy(S1x*7.8,S1y*15.4,"*");
S1x=0;
S1y=0;
}
}
/////my spell 1 ends
/////my spell 2 starts
if(E1x[1]!=0 && E1y[1]!=0 && T2==500)
st1--;
if(st1==0 && E1x[1]!=0 && E1y[1]!=0)
{
stopspell12:
setcolor(0);
for(i=1;i<=5;i++)
outtextxy(E1x[i]*7.8,E1y[i]*15.4,"*");
E1x[1]=0;
E1y[1]=0;
}
if(T2%40==0)           ///2nd spell speed
{
if(st1!=0)
{
setcolor(0);
outtextxy(E1x[5]*7.8,E1y[5]*15.4,"*");
for(i=2;i<=5;i++)
{
E1x[7-i]=E1x[6-i];
E1y[7-i]=E1y[6-i];
}
if(d1==1)
E1x[1]++;
else if(d1==2)
E1y[1]++;
else if(d1==3)
E1x[1]--;
else
E1y[1]--;
setcolor(10);
outtextxy(E1x[1]*7.8,E1y[1]*15.4,"*");
if(E1x[1]==60 && E1y[1]==10 && life==76)
goto won;
if(E1x[1]>=x-2 && E1y[1]>=y-1 && E1y[1]<=y+1 && E1x[1]<=x+2 && life==40)       ////destroying condition
{
setcolor(0);
outtextxy((65+lev2)*7.8,15.4,"*");
lev2--;
outtextxy((65+lev2)*7.8,15.4,"*");
lev2--;
st1=0;
goto stopspell12;
}
if(E1x[1]==1 || E1x[1]==79 || E1y[1]==1 || E1y[1]==23)
{st1=0;
goto stopspell12;
}
}
}
/////my spell 2 ends
av:
/////my spell 3 starts
if(T2%30==0 && A1y!=0)
{
A1x++;
setcolor(10);
outtextxy(A1x*7.8,A1y*15.4,"*");
if(A1x==60 && A1y==10 && life==76)
goto won;
if(A1x>=x-2 && A1x<=x+2 && A1y>=y-1 && A1y<=y+1 && life==40) ///destroying condition
{
setcolor(0);
outtextxy(66*7.8,15.4,"**********");
lev2=0;
}
if(A2x==A1x+1 || A2x==A1x+2)
{
o=1;
delay(3000);
goto stopspell13;
}
if(A1x==79)
{
stopspell13:
setcolor(0);
for(i=A1z;i<=A1x;i++)
outtextxy(i*7.8,A1y*15.4,"*");
A1x=0;
A1y=0;
mob1=4;
setcolor(0);
line((a+4)*7.8,b*15.4,(a+10)*7.8,(b-1)*15.4);
setcolor(10);
line((a+4)*7.8,b*15.4,(a+5)*7.8,(b-3)*15.4);
if(o==1)
goto stopspell23;
}
}
/////my spell 3 ends
/////his spell 1 starts
if(T2%10==0 && S2y!=0)
{
setcolor(0);
outtextxy(S2x*7.8,S2y*15.4,"*");
S2x--;
setcolor(14);
outtextxy(S2x*7.8,S2y*15.4,"*");
if(S2x>=a-2 && S2x<=a+2 && S2y>=b-1 && S2y<=b+1) ///destroying condition
{
setcolor(0);
outtextxy(S2x*7.8,S2y*15.4,"*");
S2x=0;
S2y=0;
outtextxy((1+lev1)*7.8,15.4,"*");
lev1--;
}
if(S2x==1)
{
setcolor(0);
outtextxy(S2x*7.8,S2y*15.4,"*");
S2x=0;
S2y=0;
}
}
/////his spell 1 ends
/////his spell 2 starts
if(E2x[1]!=0 && E2y[1]!=0 && T2==500)
st2--;
if(st2==0 && E2x[1]!=0 && E2y[1]!=0)
{
stopspell22:
setcolor(0);
for(i=1;i<=5;i++)
outtextxy(E2x[i]*7.8,E2y[i]*15.4,"*");
E2x[1]=0;
E2y[1]=0;
}
if(T2%150==0)           ///2nd spell speed
{
if(st2!=0)
{
setcolor(0);
outtextxy(E2x[5]*7.8,E2y[5]*15.4,"*");
for(i=2;i<=5;i++)
{
E2x[7-i]=E2x[6-i];
E2y[7-i]=E2y[6-i];
}
if(d2==1)
E2x[1]++;
else if(d2==2)
E2y[1]++;
else if(d2==3)
E2x[1]--;
else
E2y[1]--;
setcolor(14);
outtextxy(E2x[1]*7.8,E2y[1]*15.4,"*");
if(E2x[1]>=a-2 && E2y[1]>=b-1 && E2y[1]<=b+1 && E2x[1]<=a+2)       ////destroying condition
{
setcolor(0);
outtextxy((1+lev1)*7.8,15.4,"*");
lev1--;
outtextxy((1+lev1)*7.8,15.4,"*");
lev1--;
st2=0;
goto stopspell22;
}
if(E2x[1]==1 || E2x[1]==79 || E2y[1]==1 || E2y[1]==23)
{st2=0;
goto stopspell22;
}
}
}
/////his spell 2 ends
av2:
/////his spell 3 starts
if(T2%30==0 && A2y!=0)
{
A2x--;
setcolor(14);
outtextxy(A2x*7.8,A2y*15.4,"*");
if(A2x>=a-2 && A2x<=a+2 && A2y>=b-1 && A2y<=b+1) ///destroying condition
{
setcolor(0);
outtextxy(2*7.8,15.4,"**********");
lev1=0;
}
if(A2x==1)
{
stopspell23:
if(o==1)
o=0;
setcolor(0);
for(i=A2z;i>=A2x;i--)
outtextxy(i*7.8,A2y*15.4,"*");
A2x=0;
A2y=0;
mob2=4;
setcolor(0);
line((x-4)*7.8,b*15.4,(x-10)*7.8,(b-1)*15.4);
setcolor(14);
line((x-4)*7.8,b*15.4,(x-5)*7.8,(b-3)*15.4);
}
}
/////his spell 3 ends
/////his attack starts
if(T2%ats==0 && mob2==1)
{
if(mob1!=1)       ////main attack of 3rd spell
{
 if(y-1>=b-1 && y-1<=b+1)
 {
 setcolor(0);
 line((x-4)*7.8,y*15.4,(x-5)*7.8,(y-3)*15.4);
 setcolor(14);
 line((x-4)*7.8,y*15.4,(x-10)*7.8,(y-1)*15.4);
 mob2=3;
 A2y=(y-1);
 A2x=x-10;
 setcolor(14);
 outtextxy(A2x*7.8,A2y*15.4,"*");
 A2z=A2x;
 goto av2;
 }
 else if(y-1>b+1)
 {
  removeme(x,y,5);
  y--;
  createme(x,y,5);
 }
 else if(y-1<b-1)
 {
  removeme(x,y,5);
  y++;
  createme(x,y,5);
 }
 else
 {}
}
else if(y-1>=b-1 && y-1<=b+1 && x-a<=25)         ////other main attack of 3rd spell
{
setcolor(0);
line((x-4)*7.8,y*15.4,(x-5)*7.8,(y-3)*15.4);
setcolor(14);
line((x-4)*7.8,y*15.4,(x-10)*7.8,(y-1)*15.4);
mob2=3;
A2y=(y-1);
A2x=x-10;
setcolor(14);
outtextxy(A2x*7.8,A2y*15.4,"*");
A2z=A2x;
goto av2;
}
else if(S2x==0 && S2y==0 && y-1>=b-1 && y-1<=b+1)  ///main attack of 1st spell
{
setcolor(0);
line((x-4)*7.8,y*15.4,(x-5)*7.8,(y-3)*15.4);
setcolor(14);
line((x-4)*7.8,y*15.4,(x-10)*7.8,(y-1)*15.4);
S2y=(y-1);
S2x=x-10;
setcolor(14);
outtextxy(S2x*7.8,S2y*15.4,"*");
/////back to position
delay(100);
setcolor(0);
line((x-4)*7.8,y*15.4,(x-10)*7.8,(y-1)*15.4);
setcolor(14);
line((x-4)*7.8,y*15.4,(x-5)*7.8,(y-3)*15.4);
}
else        ////main attack of 2nd spell
{
if(st2==0 && E2x[1]==0 && E2y[1]==0)
{
setcolor(0);
line((x-4)*7.8,y*15.4,(x-5)*7.8,(y-3)*15.4);
setcolor(14);
line((x-4)*7.8,y*15.4,(x-10)*7.8,(y-1)*15.4);
d2=3;
st2=10;
setcolor(14);
for(i=1;i<=5;i++)
{
delay(50);
E2y[6-i]=y-1;
E2x[6-i]=x-10-i;
outtextxy(E2x[6-i]*7.8,E2y[6-i]*15.4,"*");
}
delay(100);
setcolor(0);
line((x-4)*7.8,y*15.4,(x-10)*7.8,(y-1)*15.4);
setcolor(14);
line((x-4)*7.8,y*15.4,(x-5)*7.8,(y-3)*15.4);
}
else
{
 if(d2==1)            ///main right
 {
    if(E2x[1]>=a-2 && E2x[1]<=a+2)
   {
     if(E2y[1]>b-1)
     d2=4;
     else
     d2=2;
   }
 }
 else if(d2==2)       ///main down
 {
   if(E2y[1]>=b-1 && E2y[1]<=b+1)
   {
     if(E2x[1]>a+2)
     d2=3;
     else
     d2=1;
   }
 }
 else if(d2==3)       ///main left
 {
   if(E2x[1]>=a-2 && E2x[1]<=a+2)
   {
     if(E2y[1]>b-1)
     d2=4;
     else
     d2=2;
   }
 }
 else if(d2==4)        ///main up
 {
   if(E2y[1]>=b-1 && E2y[1]<=b+1)
   {
     if(E2x[1]>a+2)
     d2=3;
     else
     d2=1;
   }
 }
 else    ///leave it
 {}
}
//
}
}
/////his attack over
////his defence starts
if(T2%dts==0 && mob2==1)     ////his defence thinking speed
{
i=0;
if(tu1==0)
{
  if(S1x!=0 && S1y!=0 && S1y>=y-1 && S1y<=y+1)
  i=1;
  else if(A1x!=0 && A1y!=0 && A1y>=y-1 && A1y<=y+1)
  i=1;
  else if(st1!=0 && E1y[1]>=y-1 && E1y[1]<=y+1)
  {
    if(d1==1 && E1x[1]<x-2)
    i=1;
    if(d1==3 && E1x[1]>x+2)
    i=1;
  }
  if(i==1)
  {
  removeme(x,y,5);
  y--;
  createme(x,y,5);
  }
  if(y==4)
  tu1=1;
}
else
{
  if(S1x!=0 && S1y!=0 && S1y>=y-1 && S1y<=y+1)
  i=1;
  else if(A1x!=0 && A1y!=0 && A1y>=y-1 && A1y<=y+1)
  i=1;
  else if(st1!=0 && E1y[1]>=y-1 && E1y[1]<=y+1)
  {
    if(d1==1 && E1x[1]<x-2)
    i=1;
    if(d1==3 && E1x[1]>x+2)
    i=1;
  }
  if(i==1)
  {
  removeme(x,y,5);
  y++;
  createme(x,y,5);
  }
  if(y==21)
  tu1=0;
}
i=0;
if(tu2==0)
{
  if(st1!=0 && E1x[1]>=x-2 && E1x[1]<=x+2)
  {
    if(d1==2 && E1y[1]<y-1)
    i=1;
    if(d1==4 && E1y[1]>y+1)
    i=1;
  }
  if(i==1)
  {
  removeme(x,y,5);
  x--;
  createme(x,y,5);
  }
  if(x==40)
  tu2=1;
}
else
{
  if(st1!=0 && E1x[1]>=x-2 && E1x[1]<=x+2)
  {
    if(d1==2 && E1y[1]<y-1)
    i=1;
    if(d1==4 && E1y[1]>y+1)
    i=1;
  }
  if(i==1)
  {
  removeme(x,y,5);
  x++;
  createme(x,y,5);
  }
  if(x==76)
  tu2=0;
}
}
////his defence end
}                   ////end of infinite loop
won:
win(60,10);
a1:
gotoxy(55,23);
printf("Press 6 to continue....");
if(getch()!='6')
goto a1;
return 1;
lost:
setcolor(12);
settextstyle(0,0,5);
outtextxy(20*7.8,5*15.4,"GAME OVER");
outtextxy(21*7.8,10*15.4,"YOU LOST");
a2:
gotoxy(55,23);
printf("Press 6 to exit.....");
if(getch()!='6')
goto a2;
return 0;
end:
gotoxy(35,1);
printf("Game Over");
return 0;
}
/////
int level6()
{
closegraph();
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"C://TC//BGI");
gotoxy(20,3);
printf("Level 6:Destroy Yourself\n \n");
printf("Here you have to cast any spell and kill your self\n");
printf("The spell should hit you\n");
printf("Destroy the yourself using any spell within 120 seconds\n");
gotoxy(47,23);
printf("press any key to start game....");
getch();
closegraph();
clrscr();
int l,T1,T2,b,m,i,Sy=0,Sx=0,Ex[6],Ey[6],d,w=0,st,a;
char e;
initgraph(&gd,&gm,"C://TC//BGI");
T1=120;
T2=1300;
b=10;
m=1;
createme(5,b,m);
Ex[1]=0;
Ey[1]=0;
st=0;
a=5;
while(1)            ///start of infinite loop
{
//////clock starts
T2--;
if(T2==0)
{
T1--;
T2=1300;
}
if(T1==0)
goto lost;
gotoxy(75,1);
printf("%3d",T1);
//////clock ends
if(kbhit())    /////user input starts
{
e=getch();
if(e=='0')
goto end;
else if(e=='j')
{
removeme(5,b,m);
if(m==2 && w==0)
{
w=1;
gotoxy(30,2);
printf("Spell:Stupefy          ");
}
else
{
m=m%2+1;
w=0;
gotoxy(30,2);
if(m==1)
printf("                      ");
else
printf("Spell:Expecto Petronum");
}
createme(5,b,m);
}
else if(e=='t')
{
if(st!=0 && Ex[1]!=0 && Ey[1]!=0)
d=4;
else
{
 if(b<4)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(5,b,m);
 b--;
 createme(5,b,m);
 }
 }
}
else if(e=='v')
{
if(st!=0 && Ex[1]!=0 && Ey[1]!=0)
d=2;
else
{
 if(b>22)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(5,b,m);
 b++;
 createme(5,b,m);
 }
 }
}
else if(e=='g')
{
if(m==2)
{
setcolor(0);
line(9*7.8,b*15.4,10*7.8,(b-3)*15.4);
setcolor(10);
line(9*7.8,b*15.4,15*7.8,(b-1)*15.4);
/////wand
if(w==0)
{
if(Ex[1]==0 && Ey[1]==0)
{
d=1;
st=5;
for(i=1;i<=5;i++)
{
delay(50);
Ey[6-i]=b-1;
Ex[6-i]=15+i;
setcolor(10);
outtextxy(Ex[6-i]*7.8,Ey[6-i]*15.4,"*");
}
}
}
else
{
if(Sx==0 && Sy==0)
{
Sy=(b-1);
Sx=15;
setcolor(10);
outtextxy(Sx*7.8,Sy*15.4,"*");
}
}
delay(100);
setcolor(0);
line(9*7.8,b*15.4,15*7.8,(b-1)*15.4);
setcolor(10);
line(9*7.8,b*15.4,10*7.8,(b-3)*15.4);
}
}
else if(e=='l')
d=1;
else if(e=='a')
d=3;
else     ////last else of user input
{}
}
/////user input ends
/////1st spell
if(Ex[1]!=0 && Ey[1]!=0 && T2==500)
st--;
if(st==0 && Ex[1]!=0 && Ey[1]!=0)
{
stopspell:
setcolor(0);
for(i=1;i<=5;i++)
outtextxy(Ex[i]*7.8,Ey[i]*15.4,"*");
Ex[1]=0;
Ey[1]=0;
}
if(T2%30==0)           ///1st spell speed
{
if(st!=0)
{
setcolor(0);
outtextxy(Ex[5]*7.8,Ey[5]*15.4,"*");
for(i=2;i<=5;i++)
{
Ex[7-i]=Ex[6-i];
Ey[7-i]=Ey[6-i];
}
if(d==1)
Ex[1]++;
else if(d==2)
Ey[1]++;
else if(d==3)
Ex[1]--;
else
Ey[1]--;
setcolor(10);
outtextxy(Ex[1]*7.8,Ey[1]*15.4,"*");
if(Ex[1]>=a-2 && Ey[1]>=b-1 && Ey[1]<=1+b && Ex[1]<=a+2)       ////destroying condition
goto won;
if(Ex[1]==1 || Ex[1]==79 || Ey[1]==1 || Ey[1]==23)
{st=0;
goto stopspell;
}
}
}
/////1st spell ends
/////Stupefy starts
if(T2%10==0 && Sy!=0)
{
setcolor(0);
outtextxy(Sx*7.8,Sy*15.4,"*");
Sx++;
setcolor(10);
outtextxy(Sx*7.8,Sy*15.4,"*");
if(Sx==79)
{
setcolor(0);
outtextxy(Sx*7.8,Sy*15.4,"*");
Sx=0;
Sy=0;
}
}
/////Stupefy ends
}                   ////end of infinite loop
won:
win(a,b);
a1:
gotoxy(55,23);
printf("Press 6 to continue....");
if(getch()!='6')
goto a1;
return 1;
lost:
setcolor(12);
settextstyle(0,0,5);
outtextxy(20*7.8,5*15.4,"GAME OVER");
outtextxy(21*7.8,10*15.4,"YOU LOST");
a2:
gotoxy(55,23);
printf("Press 6 to exit.....");
if(getch()!='6')
goto a2;
return 0;
end:
gotoxy(35,1);
printf("Game Over");
return 0;
}
//////
int level7()
{
closegraph();
clrscr();
int gd=DETECT,gm;
initgraph(&gd,&gm,"C://TC//BGI");
gotoxy(15,3);
printf("Final Level:Destroy Snake and kill Voldemort\n \n");
printf("Here you have all 3 spell, sword and move in all direction\n");
printf("First kill red snake using only sword before finishing your health\n");
printf("Then kill voldemort\n");
printf("The one who uses Avada Kedavra gets freezed for 3 second\n");
printf("Kill Voldemort only using Avada Kedavra within 120 seconds\n");
gotoxy(47,23);
printf("press any key to start game....");
getch();
closegraph();
clrscr();
int l,T1,T2,a,b,m,i,y,x,w,lev1,lev2,mob1,mob2,st1,st2,d1,d2,tu1,tu2;
int S1x,S1y,S2x,S2y,E1x[6],E1y[6],E2x[6],E2y[6],A1x,A1y,A1z,A2x,A2y,A2z,dts,ats,o;
char e;
int Nx[7],Ny[7],N=1,Nd=3;
initgraph(&gd,&gm,"C://TC//BGI");
o=0;
T1=120;
T2=1300;
a=5;
b=8;
m=1;
x=60;
y=14;
w=0;
mob1=1;
mob2=1;
lev1=10;
lev2=10;
S1x=0;
S1y=0;
S2x=0;
S2y=0;
st1=0;
st2=0;
E1x[1]=0;
E1y[1]=0;
d1=1;
E2x[1]=0;
E2y[1]=0;
d2=1;
A1x=0;
A1y=0;
A1z=0;
A2x=0;
A2y=0;
A2z=0;
tu1=1;
tu2=1;
dts=750;
ats=100;
setcolor(10);
for(i=2;i<=11;i++)
outtextxy(i*7.8,15.4,"*");
setcolor(12);
for(i=1;i<=6;i++)
{
Ny[i]=22;
Nx[i]=70+i;
createdot(Nx[i],Ny[i],7);
}
createme(a,b,m);
createme(x,y,6);
while(1)            ///start of infinite loop
{
/////snake starts
if(N==1)
{
if(T2%250==0)            ///snake speed
{
removedot(Nx[6],Ny[6]);
for(i=6;i>=2;i--)
{
Nx[i]=Nx[i-1];
Ny[i]=Ny[i-1];
}
 if(Nx[1]<a+5)
 Nx[1]++;
 else
 {
   if(b==Ny[1])
   {
   Nx[1]--;
   if(Nx[1]<=a+4)
   goto lost;
   }
   else if(b>Ny[1])
   Ny[1]++;
   else
   Ny[1]--;
 }
createdot(Nx[1],Ny[1],7);
if(Ny[1]==b && Nx[1]==a-2)
goto lost;
}
}
//////snake ends
/////my health
if(lev1<=0)
goto lost;
////my health checked
/////his helath
if(lev2<=0)
goto won;
/////his health checked
//////clock starts
T2--;
if(T2==0)
{
T1--;
T2=1300;
}
if(T1==0)
goto lost;
gotoxy(40,1);
printf("%3d",T1);
//////clock ends
/////mobility starts
if(mob1!=1)
 if(T2==500)
 mob1--;
if(mob2!=1)
 if(T2==500)
 mob2--;
/////mobility ends
if(kbhit())    /////user input starts
{
e=getch();
if(e=='0')
goto end;
if(mob1==1)
if(e=='j')
{
removeme(a,b,m);
if(m==2 && w==3)
{
m=3;
w=0;
gotoxy(30,2);
printf("                      ");
}
else if(m==3)
m=1;
else
{
m=2;
w++;
gotoxy(30,2);
if(w==1)
printf("Spell:Stupefy          ");
else if(w==2)
printf("Spell:Expecto Petronum");
else
printf("Spell:Avada Kedavra   ");
}
createme(a,b,m);
}
else if(e=='t')
{
if(st1!=0)
d1=4;
 if(b<4)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 b--;
 createme(a,b,m);
 }
}
else if(e=='v')
{
if(st1!=0)
d1=2;
 if(b>22)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 b++;
 createme(a,b,m);
 }
}
else if(e=='g')
{
if(m==3)
{
setcolor(0);
line((a+5)*7.8,b*15.8,(a+5)*7.8,(b-3)*15.4);
line((a+4)*7.8,(b-1)*15.8,(a+6)*7.8,(b-1)*15.8);
setcolor(15);
//line((a+3)*7.8,15.8*b,(a+5)*7.8,15.8*b);
line((a+5)*7.8,b*15.8,(a+12)*7.8,b*15.8);
line((a+6)*7.8,(b-1)*16,(a+6)*7.8,(b+1)*15.4);
////check for kill
if(Ny[1]==b && Nx[1]>=a+7 && a+12>=Nx[1])
N=0;
//if(b>=13 && b<=15 && a+12>=43 && a+12<=47)
//goto won;
delay(100);
setcolor(15);
line((a+5)*7.8,b*15.8,(a+5)*7.8,(b-3)*15.4);
line((a+4)*7.8,(b-1)*15.8,(a+6)*7.8,(b-1)*15.8);
setcolor(0);
line((a+5)*7.8,b*15.8,(a+12)*7.8,b*15.8);
line((a+6)*7.8,(b-1)*16,(a+6)*7.8,(b+1)*15.4);
}
if(m==2)
{
setcolor(0);
line((a+4)*7.8,b*15.4,(a+5)*7.8,(b-3)*15.4);
setcolor(10);
line((a+4)*7.8,b*15.4,(a+10)*7.8,(b-1)*15.4);
/////wand
if(w==1 && S1x==0 && S1y==0)
{
S1y=(b-1);
S1x=a+10;
setcolor(10);
outtextxy(S1x*7.8,S1y*15.4,"*");
}
else if(w==2 && st1==0)
{
d1=1;
st1=5;
setcolor(10);
for(i=1;i<=5;i++)
{
delay(50);
E1y[6-i]=b-1;
E1x[6-i]=a+10+i;
outtextxy(E1x[6-i]*7.8,E1y[6-i]*15.4,"*");
}
}
else if(w==3 && A1x==0 && A1y==0)
{
mob1=3;
A1y=(b-1);
A1x=a+10;
setcolor(10);
outtextxy(A1x*7.8,A1y*15.4,"*");
A1z=A1x;
goto av;
}
else
{}
delay(100);
setcolor(0);
line((a+4)*7.8,b*15.4,(a+10)*7.8,(b-1)*15.4);
setcolor(10);
line((a+4)*7.8,b*15.4,(a+5)*7.8,(b-3)*15.4);
}
}
else if(e=='l')
{
if(st1!=0)
d1=1;
 if(a>76)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 a++;
 createme(a,b,m);
 }
}
else if(e=='a')
{
if(st1!=0)
d1=3;
 if(a<4)
 {
 gotoxy(35,1);
 printf("Play Inside Ground");
 getch();
 gotoxy(35,1);
 printf("                  ");
 }
 else
 {
 removeme(a,b,m);
 a--;
 createme(a,b,m);
 }
}
else     ////last else of user input
{}
}
/////user input ends
/////my spell 1 starts
if(T2%10==0 && S1y!=0)
{
setcolor(0);
outtextxy(S1x*7.8,S1y*15.4,"*");
S1x++;
setcolor(10);
outtextxy(S1x*7.8,S1y*15.4,"*");
if(S1x==79)
{
setcolor(0);
outtextxy(S1x*7.8,S1y*15.4,"*");
S1x=0;
S1y=0;
}
}
/////my spell 1 ends
/////my spell 2 starts
if(E1x[1]!=0 && E1y[1]!=0 && T2==500)
st1--;
if(st1==0 && E1x[1]!=0 && E1y[1]!=0)
{
stopspell12:
setcolor(0);
for(i=1;i<=5;i++)
outtextxy(E1x[i]*7.8,E1y[i]*15.4,"*");
E1x[1]=0;
E1y[1]=0;
}
if(T2%40==0)           ///2nd spell speed
{
if(st1!=0)
{
setcolor(0);
outtextxy(E1x[5]*7.8,E1y[5]*15.4,"*");
for(i=2;i<=5;i++)
{
E1x[7-i]=E1x[6-i];
E1y[7-i]=E1y[6-i];
}
if(d1==1)
E1x[1]++;
else if(d1==2)
E1y[1]++;
else if(d1==3)
E1x[1]--;
else
E1y[1]--;
setcolor(10);
outtextxy(E1x[1]*7.8,E1y[1]*15.4,"*");
if(E1x[1]==1 || E1x[1]==79 || E1y[1]==1 || E1y[1]==23)
{st1=0;
goto stopspell12;
}
}
}
/////my spell 2 ends
av:
/////my spell 3 starts
if(T2%30==0 && A1y!=0)
{
A1x++;
setcolor(10);
outtextxy(A1x*7.8,A1y*15.4,"*");
if(A1x>=x-2 && A1x<=x+2 && A1y>=y-1 && A1y<=y+1 && N==0) ///destroying condition
goto won;
if((A2x==A1x+1 || A2x==A1x+2) && A1y==A2y && N==1)
{
o=1;
delay(3000);
goto stopspell13;
}
if((A2x==A1x+1 || A2x==A1x+2) && A1y==A2y && N==0)
{
delay(3000);
goto stopspell23;
}
if(A1x==79)
{
stopspell13:
setcolor(0);
for(i=A1z;i<=A1x;i++)
outtextxy(i*7.8,A1y*15.4,"*");
A1x=0;
A1y=0;
mob1=4;
setcolor(0);
line((a+4)*7.8,b*15.4,(a+10)*7.8,(b-1)*15.4);
setcolor(10);
line((a+4)*7.8,b*15.4,(a+5)*7.8,(b-3)*15.4);
if(o==1)
goto stopspell23;
}
}
/////my spell 3 ends
/////his spell 1 starts
if(T2%10==0 && S2y!=0)
{
setcolor(0);
outtextxy(S2x*7.8,S2y*15.4,"*");
S2x--;
setcolor(12);
outtextxy(S2x*7.8,S2y*15.4,"*");
if(S2x>=a-2 && S2x<=a+2 && S2y>=b-1 && S2y<=b+1) ///destroying condition
{
setcolor(0);
outtextxy(S2x*7.8,S2y*15.4,"*");
S2x=0;
S2y=0;
outtextxy((1+lev1)*7.8,15.4,"*");
lev1--;
}
if(S2x==1)
{
setcolor(0);
outtextxy(S2x*7.8,S2y*15.4,"*");
S2x=0;
S2y=0;
}
}
/////his spell 1 ends
/////his spell 2 starts
if(E2x[1]!=0 && E2y[1]!=0 && T2==500)
st2--;
if(st2==0 && E2x[1]!=0 && E2y[1]!=0)
{
stopspell22:
setcolor(0);
for(i=1;i<=5;i++)
outtextxy(E2x[i]*7.8,E2y[i]*15.4,"*");
E2x[1]=0;
E2y[1]=0;
}
if(T2%110==0)           ///2nd spell speed
{
if(st2!=0)
{
setcolor(0);
outtextxy(E2x[5]*7.8,E2y[5]*15.4,"*");
for(i=2;i<=5;i++)
{
E2x[7-i]=E2x[6-i];
E2y[7-i]=E2y[6-i];
}
if(d2==1)
E2x[1]++;
else if(d2==2)
E2y[1]++;
else if(d2==3)
E2x[1]--;
else
E2y[1]--;
setcolor(12);
outtextxy(E2x[1]*7.8,E2y[1]*15.4,"*");
if(E2x[1]>=a-2 && E2y[1]>=b-1 && E2y[1]<=b+1 && E2x[1]<=a+2)       ////destroying condition
{
setcolor(0);
outtextxy((1+lev1)*7.8,15.4,"*");
lev1--;
outtextxy((1+lev1)*7.8,15.4,"*");
lev1--;
st2=0;
goto stopspell22;
}
if(E2x[1]==1 || E2x[1]==79 || E2y[1]==1 || E2y[1]==23)
{st2=0;
goto stopspell22;
}
}
}
/////his spell 2 ends
av2:
/////his spell 3 starts
if(T2%30==0 && A2y!=0)
{
A2x--;
setcolor(12);
outtextxy(A2x*7.8,A2y*15.4,"*");
if(A2x>=a-2 && A2x<=a+2 && A2y>=b-1 && A2y<=b+1) ///destroying condition
{
setcolor(0);
outtextxy(2*7.8,15.4,"**********");
lev1=0;
}
if(A2x==1)
{
stopspell23:
if(o==1)
o=0;
setcolor(0);
for(i=A2z;i>=A2x;i--)
outtextxy(i*7.8,A2y*15.4,"*");
A2x=0;
A2y=0;
mob2=4;
setcolor(0);
line((x-4)*7.8,b*15.4,(x-10)*7.8,(b-1)*15.4);
setcolor(8);
line((x-4)*7.8,b*15.4,(x-5)*7.8,(b-3)*15.4);
}
}
/////his spell 3 ends
/////his attack starts
if(T2%ats==0 && mob2==1)
{
if(mob1!=1)       ////main attack of 3rd spell
{
 if(y-1>=b-1 && y-1<=b+1)
 {
 setcolor(0);
 line((x-4)*7.8,y*15.4,(x-5)*7.8,(y-3)*15.4);
 setcolor(8);
 line((x-4)*7.8,y*15.4,(x-10)*7.8,(y-1)*15.4);
 mob2=3;
 A2y=(y-1);
 A2x=x-10;
 setcolor(12);
 outtextxy(A2x*7.8,A2y*15.4,"*");
 A2z=A2x;
 goto av2;
 }
 else if(y-1>b+1)
 {
  removeme(x,y,6);
  y--;
  createme(x,y,6);
 }
 else if(y-1<b-1)
 {
  removeme(x,y,6);
  y++;
  createme(x,y,6);
 }
 else
 {}
}
else if(y-1>=b-1 && y-1<=b+1 && x-a<=25)         ////other main attack of 3rd spell
{
setcolor(0);
line((x-4)*7.8,y*15.4,(x-5)*7.8,(y-3)*15.4);
setcolor(8);
line((x-4)*7.8,y*15.4,(x-10)*7.8,(y-1)*15.4);
mob2=3;
A2y=(y-1);
A2x=x-10;
setcolor(12);
outtextxy(A2x*7.8,A2y*15.4,"*");
A2z=A2x;
goto av2;
}
else if(S2x==0 && S2y==0 && y-1>=b-1 && y-1<=b+1)  ///main attack of 1st spell
{
setcolor(0);
line((x-4)*7.8,y*15.4,(x-5)*7.8,(y-3)*15.4);
setcolor(8);
line((x-4)*7.8,y*15.4,(x-10)*7.8,(y-1)*15.4);
S2y=(y-1);
S2x=x-10;
setcolor(12);
outtextxy(S2x*7.8,S2y*15.4,"*");
/////back to position
delay(100);
setcolor(0);
line((x-4)*7.8,y*15.4,(x-10)*7.8,(y-1)*15.4);
setcolor(8);
line((x-4)*7.8,y*15.4,(x-5)*7.8,(y-3)*15.4);
}
else        ////main attack of 2nd spell
{
if(st2==0 && E2x[1]==0 && E2y[1]==0 && N==1)
{
setcolor(0);
line((x-4)*7.8,y*15.4,(x-5)*7.8,(y-3)*15.4);
setcolor(8);
line((x-4)*7.8,y*15.4,(x-10)*7.8,(y-1)*15.4);
d2=3;
st2=10;
setcolor(12);
for(i=1;i<=5;i++)
{
delay(50);
E2y[6-i]=y-1;
E2x[6-i]=x-10-i;
outtextxy(E2x[6-i]*7.8,E2y[6-i]*15.4,"*");
}
delay(100);
setcolor(0);
line((x-4)*7.8,y*15.4,(x-10)*7.8,(y-1)*15.4);
setcolor(8);
line((x-4)*7.8,y*15.4,(x-5)*7.8,(y-3)*15.4);
}
else
{
 if(d2==1)            ///main right
 {
    if(E2x[1]>=a-2 && E2x[1]<=a+2)
   {
     if(E2y[1]>b-1)
     d2=4;
     else
     d2=2;
   }
 }
 else if(d2==2)       ///main down
 {
   if(E2y[1]>=b-1 && E2y[1]<=b+1)
   {
     if(E2x[1]>a+2)
     d2=3;
     else
     d2=1;
   }
 }
 else if(d2==3)       ///main left
 {
   if(E2x[1]>=a-2 && E2x[1]<=a+2)
   {
     if(E2y[1]>b-1)
     d2=4;
     else
     d2=2;
   }
 }
 else if(d2==4)        ///main up
 {
   if(E2y[1]>=b-1 && E2y[1]<=b+1)
   {
     if(E2x[1]>a+2)
     d2=3;
     else
     d2=1;
   }
 }
 else    ///leave it
 {}
}
//
}
}
/////his attack over
////his defence starts
if(T2%dts==0 && mob2==1)     ////his defence thinking speed
{
i=0;
if(tu1==0)
{
  if(S1x!=0 && S1y!=0 && S1y>=y-1 && S1y<=y+1)
  i=1;
  else if(A1x!=0 && A1y!=0 && A1y>=y-1 && A1y<=y+1)
  i=1;
  else if(st1!=0 && E1y[1]>=y-1 && E1y[1]<=y+1)
  {
    if(d1==1 && E1x[1]<x-2)
    i=1;
    if(d1==3 && E1x[1]>x+2)
    i=1;
  }
  if(i==1)
  {
  removeme(x,y,6);
  y--;
  createme(x,y,6);
  }
  if(y==4)
  tu1=1;
}
else
{
  if(S1x!=0 && S1y!=0 && S1y>=y-1 && S1y<=y+1)
  i=1;
  else if(A1x!=0 && A1y!=0 && A1y>=y-1 && A1y<=y+1)
  i=1;
  else if(st1!=0 && E1y[1]>=y-1 && E1y[1]<=y+1)
  {
    if(d1==1 && E1x[1]<x-2)
    i=1;
    if(d1==3 && E1x[1]>x+2)
    i=1;
  }
  if(i==1)
  {
  removeme(x,y,6);
  y++;
  createme(x,y,6);
  }
  if(y==21)
  tu1=0;
}
i=0;
if(tu2==0)
{
  if(st1!=0 && E1x[1]>=x-2 && E1x[1]<=x+2)
  {
    if(d1==2 && E1y[1]<y-1)
    i=1;
    if(d1==4 && E1y[1]>y+1)
    i=1;
  }
  if(i==1)
  {
  removeme(x,y,6);
  x--;
  createme(x,y,6);
  }
  if(x==40)
  tu2=1;
}
else
{
  if(st1!=0 && E1x[1]>=x-2 && E1x[1]<=x+2)
  {
    if(d1==2 && E1y[1]<y-1)
    i=1;
    if(d1==4 && E1y[1]>y+1)
    i=1;
  }
  if(i==1)
  {
  removeme(x,y,6);
  x++;
  createme(x,y,6);
  }
  if(x==76)
  tu2=0;
}
}
////his defence end
}                   ////end of infinite loop
won:
removeme(x,y,6);
win(x,y);
setcolor(10);
settextstyle(0,0,5);
outtextxy(20*7.8,5*15.4,"GAME OVER");
outtextxy(30*7.8,10*15.4,"WINNER");
a1:
gotoxy(55,23);
printf("Press 6 to exit....");
if(getch()!='6')
goto a1;
return 1;
lost:
setcolor(12);
settextstyle(0,0,5);
outtextxy(20*7.8,5*15.4,"GAME OVER");
outtextxy(21*7.8,10*15.4,"YOU LOST");
a2:
gotoxy(55,23);
printf("Press 6 to exit.....");
if(getch()!='6')
goto a2;
return 0;
end:
gotoxy(35,1);
printf("Game Over");
return 0;
}
/////
void main()
{
clrscr();
int gd=DETECT,gm,l;
initgraph(&gd,&gm,"C://TC//BGI");
settextstyle(1,0,7);
setcolor(11);
outtextxy(10*7.8,5*15.4,"HARRY POTTER");
outtextxy(30*7.8,10*15.4,"AND");
settextstyle(1,0,6);
outtextxy(1*7.8,15*15.4,"THE SEVEN HORCRUXES");
gotoxy(52,23);
printf("press any key to continue....");
getch();

l=level1();
if(l==0)
goto end;
else
gotoxy(20,3);
printf("well played, Press any key for next level");
getch();
l=level2();
if(l==0)
goto end;
else
gotoxy(20,3);
printf("well played, Press any key for next level");
getch();
l=level3();
if(l==0)
goto end;
else
gotoxy(20,3);
printf("well played, Press any key for next level");
getch();
l=level4();
if(l==0)
goto end;
else
gotoxy(20,3);
printf("well played, Press any key for next level");
getch();
l=level5();
if(l==0)
goto end;
else
gotoxy(20,3);
printf("well played, Press any key for next level");
getch();
l=level6();
if(l==0)
goto end;
else
gotoxy(20,3);
printf("well played, Press any key for next level");
getch();
l=level7();
if(l==0)
goto end;
else
{
}
end:
closegraph();
}