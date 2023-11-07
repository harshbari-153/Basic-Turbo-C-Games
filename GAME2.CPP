#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
player1(int w,int x)
{
gotoxy(w,x);
printf("*****");
gotoxy(w,x+1);
printf("*******");
gotoxy(w,x+2);
printf("*****");
}
player2(int y,int z)
{
gotoxy(y,z);
printf("*****");
gotoxy(y-2,z+1);
printf("*******");
gotoxy(y,z+2);
printf("*****");
}
void main()
{
int a,b,c,d,e,f=0,g,h,i,q1,q2,q3;
char z1[100],z2[100];
int gdriver=DETECT,gmode;
clrscr();
printf("Welcome To Tank Fight Game");
printf("\nPress any key to continue...");
getche();
clrscr();
printf("Instructions for first player\n");
printf("Press s to move forward\n");
printf("Press a to move backward\n");
printf("Press w to move upward\n");
printf("Press z to move downward\n");
printf("Press r to fire\n");
printf("Press h to pause the game\n");
printf("Press any key to continue...");
getche();
clrscr();
printf("Instructions for second player\n");
printf("Press k to move foreward\n");
printf("Press l to move backward\n");
printf("Press o to move upward\n");
printf("Press m to move downward\n");
printf("Press u to fire\n");
printf("Press h to pause the game\n");
printf("Press any key to continue...");
getche();
clrscr();
printf("Enter first player name:");
scanf("%s",&z1);
printf("Enter second player name;");
scanf("%s",&z2);
int t;
initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
play:
for(t=3;t>=0;t--)
{
clrscr();
printf("Game begains in %d seconds",t);
delay(1000);
}
clrscr();
a=1;
b=1;
c=75;
d=23;
q1=0;
q2=0;
q3=0;
goto start;
fire1:
int w1;
for(w1=a+4;w1<=77;w1++)
{  if(w1==77)
{
f=0;
if(q3==6)
{
gotoxy(30,2);
printf("Game Over, no winner");
goto b1;
}
}
 gotoxy(w1,g+1);
printf("*)>");
if((w1+3)==c && (g+1)==d)
{ gotoxy(30,1);
printf("Game Over");
gotoxy(30,2);
printf("%s wins",z1);
b1:
gotoxy(30,3);
printf("Press f to play again and h to exit");
g2:
i=getche();
if(i=='f')
goto play;
else if(i=='h')
goto end;
else
goto g2;
}
else if((w1+5)==(c) && (g+1)==(d+1))
{   gotoxy(30,1);
printf("Game Over");
gotoxy(30,2);
printf("%s wins",z1);
gotoxy(30,3);
printf("Press f to play again and h to exit");
g3:
i=getche();
if(i=='f')
goto play;
else if(i=='h')
goto end;
else
goto g3;
}
else if((w1+3)==c && (g+1)==(d+2))
{  gotoxy(30,1);
printf("Game Over");
gotoxy(30,2);
printf("%s wins",z1);
gotoxy(30,3);
printf("Press f to play again and h to exit");
g4:
i=getche();
if(i=='f')
goto play;
else if(i=='h')
goto end;
else
goto g4;
}
else
{
}
delay(10);
goto a1;
x1:
cleardevice();
player1(a,b);
player2(c,d);
}
fire2:
int y1;
for(y1=c-2;y1>=1;y1--)
{
if(y1==1)
{
f=0;
if(q3==6)
{  gotoxy(30,2);
printf("Game Over, no winner");
goto b3;
}
}
     gotoxy(y1,h+1);
printf("<(*");
if((y1==a+5) && (h+1)==b)
{ gotoxy(30,1);
printf("Game Over");

gotoxy(30,2);
printf("%s wins",z2);
b3:
gotoxy(30,3);
printf("Press f to play again and h to exit");
g6:
i=getche();
if(i=='f')
goto play;
else if(i=='h')
goto end;
else
goto g6;
}
else if((y1==a+7) && (h+1)==(b+1))
{ gotoxy(30,1);
printf("Game Over");
gotoxy(30,2);
printf("%s wins",z2);
gotoxy(30,3);
printf("Press f to play again and h to exit");
g7:
i=getche();
if(i=='f')
goto play;
else if(i=='h')
goto end;
else
goto g7;
}
else if((y1==a+5) && (h+1)==(b+2))
{ gotoxy(30,1);
printf("Game Over");
gotoxy(30,2);
printf("%s wins",z2);
gotoxy(30,3);
printf("Press f to play again and h to exit");
g9:
i=getche();
if(i=='f')
goto play;
else if(i=='h')
goto end;
else
goto g9;
}
else
{
}
delay(10);
goto a1;
z1:
cleardevice();
player1(a,b);
player2(c,d);
}

start:
player1(a,b);
player2(c,d);
if(q1==3)
{   gotoxy(c-5,d+1);
printf("*");
}
if(q2==3)
{
gotoxy(10+a,b+1);
printf("*");
}
if(q1==3)
{
if((((a)==(c-5)) && ((b+1)==(1+d))) || (((a+1)==(c-5)) && ((1+b)==(1+d))) || (((a+2)==(c-5)) && ((1+b)==(1+d))) || (((a+3)==(c-5)) && ((1+b)==(1+d))) || (((a+4)==(c-5)) && ((1+b)==(1+d))) || (((a+5)==(c-5)) && ((1+b)==(1+d)))  ||(((a+6)==(c-5)) && ((1+b)==(1+d))) )
{ q1=q1-3;
q3=q3-3;
}
}
if(q2==3)
{
if((((c)==(a+10)) && ((b+1)==(1+d))) || (((c+1)==(a+10)) && ((1+b)==(1+d))) || (((c+2)==(a+10)) && ((1+b)==(1+d))) || (((c+3)==(a+10)) && ((1+b)==(1+d))) || (((c+4)==(a+10)) && ((1+b)==(1+d))) || (((c-2)==(a+10)) && ((1+b)==(1+d)))  ||(((c-1)==(a+10)) && ((1+b)==(1+d))) )
{  q2=q2-3;
q3=q3-3;
}
}
a1:
if(kbhit())
goto a2;
if(f==1)
goto x1;
else if(f==2)
goto z1;
else
{
}
a2:
e=getche();
if(e=='s')
{    if(a==73)
     a=a+0;
     else
     a++;
     cleardevice();
     goto start;
}
if(e=='h')
{
gotoxy(35,1);
printf("Game Paused");
gotoxy(30,2);
printf("Press any key twice to continue");
getche();
}
if(e=='a')
{    if(a==1)
     a=a+0;
     else
     a--;
     cleardevice();
     goto start;
}
if(e=='w')
{    if(b==1)
     b=b+0;
     else
     b--;
     cleardevice();
     goto start;
}
if(e=='z')
{    if(b==23)
     b=b+0;
     else
     b++;
     cleardevice();
     goto start;
}
if(e=='k')
{    if(c==3)
     c=c+0;
     else
     c--;
     cleardevice();
     goto start;
}
if(e=='l')
{    if(c==75)
     c=c+0;
     else
     c++;
     cleardevice();
     goto start;
}
if(e=='o')
{    if(d==1)
     d=d+0;
     else
     d--;
     cleardevice();
     goto start;
}
if(e=='m')
{    if(d==23)
     d=d+0;
     else
     d++;
     cleardevice();
     goto start;
}
if(f==0)
{
if(e=='r')
{
if(q1==3)
{
gotoxy(24,7);
printf("Sorry %s, no bullets available",z1);
delay(2000);
goto a2;
}
g=b;
f=1;
q1++;
q3++;
goto fire1;
}
else if(e=='u')
{
if(q2==3)
{
gotoxy(24,7);
printf("Sorry %s, no bullets available",z2);
delay(2000);
goto a2;
}
h=d;
f=2;
q2++;
q3++;
goto fire2;
}
else
{
}
}
if(e=='0')
goto end;
else
goto start;
getche();
end:
}