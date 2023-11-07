#include<stdio.h>
#include<conio.h>
#include<dos.h>
void main()
{
int a,b,c,d,e,f,g,h,i;
char z[100];
clrscr();
printf("Welcome to the game\n");
printf("Press any key to continue....");
getche();
clrscr();
printf("Game rules:\n");
printf("Press b to go up\n");
printf("Press c to go down\n");
printf("Press p to pause the game\n");
printf("Avoid hitting this obstackle #\n");
printf("Press any key to continue....");
getche();
clrscr();
printf("Please enter your name:");
scanf("%s",&z);
start:
clrscr();
for(i=3;i>=0;i--)
{
clrscr();
printf("Welcome %s, your game begains in %d seconds",z,i);
delay(1000);
}
f=0;
g=20;
e=33;
d=7;
b=10;
for(a=0;a<=81;a++)
{
if(kbhit())
{
c=getche();
clrscr();
if(c==48)
goto end;
if(c==112)
{
gotoxy(32,10);
printf("Game Paused, Press any key to resume:");
getche();
}
if(c==99)
{
    if(b>=24)
b=1;
b=b+1;
goto up;
}
if(c==98)
{
if(b<=1)
b=24;
b=b-1;
goto up;
}
}
up:
clrscr();
gotoxy(a,b);
printf("*****)>");
gotoxy(e,d);
printf("#");
if(a==(e-7) && b==d)
{gotoxy(1,1);
printf("\ngame over %s\n",z);
printf("Your score is %d\n",f);
printf("Press w for new game or press y to exit\n");
to:
h=getche();
if(h==119)
goto start;
else if(h==121)
goto end;
else
goto to;
}
gotoxy(73,1);
printf("score:%d",f);
delay(g);
if(a==80)
d=b;
if(a==80)
{
f++;
a=0;
g=g-1;
}
}
clrscr();
end:
}