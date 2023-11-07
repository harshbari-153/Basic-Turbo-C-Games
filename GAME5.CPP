#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct ground
{
int square[10],turn;
};
void fill(struct ground *add,int n)
{
if(add->turn%2==0)
add->square[n]=3;
else
add->square[n]=5;
add->turn++;
}
void erase(struct ground *add,int n)
{
add->square[n]=2;
add->turn--;
}
int iswin(struct ground *add)
{
int i,j,ans=1,results;
for(i=1;i<=3;i++)
{
ans=add->square[3*(i-1)+1]*add->square[3*(i-1)+2]*add->square[3*(i-1)+3];
if(ans==27)
return 3;
if(ans==125)
return 5;
}
for(i=1;i<=3;i++)
{
ans=add->square[i]*add->square[3+i]*add->square[6+i];
if(ans==27)
return 3;
if(ans==125)
return 5;
}
if((add->square[1]*add->square[5]*add->square[9])==27)
return 3;
else if((add->square[3]*add->square[5]*add->square[7])==27)
return 3;
else if((add->square[1]*add->square[5]*add->square[9])==125)
return 5;
else if((add->square[3]*add->square[5]*add->square[7])==125)
return 5;
else
return 0;
}
void show(struct ground *add)
{
int i,j,a,b,k;
for(i=0;i<=2;i++)
{
for(j=0;j<=2;j++)
{
a=13+26*j;
b=4+8*i;
gotoxy(a,b);
if(add->square[3*i+j+1]==2)
printf(" ");
else if(add->square[3*i+j+1]==3)
{
gotoxy(1+a,b);
printf("*");
gotoxy(a,b);
printf(" ");
for(k=1;k<=2;k++)
{
gotoxy(a-k+1,b-k);
printf("*");
gotoxy(a+k+1,b+k);
printf("*");
gotoxy(a+k+1,b-k);
printf("*");
gotoxy(a-k+1,b+k);
printf("*");
}
}
else
{
for(k=0;k<=4;k++)
{
gotoxy(a-3,b-2+k);
printf("*");
gotoxy(a+3,b-2+k);
printf("*");
}
for(k=0;k<=2;k++)
{
gotoxy(a-3+2*k,b-2);
printf("*");
gotoxy(a-3+2*k,b+2);
printf("*");
}
}
}
}
}
int isempty(struct ground *add)
{
int i;
for(i=1;i<=9;i++)
if(add->square[i]==2)
return 0;
return 1;
}
int tictac(struct ground *add,int level)
{
int points[10],check,check2,i,max;
if(level>9)
return 0;
else
{
 for(i=1;i<=9;i++)
 {
  if(add->square[i]!=2)
  {
    if(level%2==0)
     points[i]=-600;
    else
     points[i]=600;
  }
  else
  {
   fill(add,i);
   check=iswin(add);
   if(check!=0)
   {
   erase(add,i);
    if(check==5)
    {
     if(level!=0)
     return 500/level;
     return i;
    }
    else
    {
    return -500/level;
    }
   }
   else
   {
    check2=isempty(add);
    if(check2==1)
    {
    erase(add,i);
    if(level!=0)
    return 0;
    else
    return i;
    }
    else
    points[i]=tictac(add,level+1);
   }
   erase(add,i);
  }
 }
 max=1;
 for(i=2;i<=9;i++)
 {
   if(level%2==0)
   {
   if(points[max]<points[i])
   max=i;
   }
   else
   {
   if(points[max]>points[i])
   max=i;
   }
 }
 if(level==0)
 return max;
 else
 return points[max];
}
}
void main()
{
int a,b,i,c,d,e=0,check=0,tile,win,lost,draw,total;
char f,name[50],x;
float w,d1,l;
FILE *fp;
fp=fopen("tttdata.txt","r");
if(fp==NULL)
{
clrscr();
printf("Enter your name:");
gets(name);
fp=fopen("tttdata.txt","w");
fprintf(fp,"0-0-0-%s",name);
printf("Registratin Completed, Enjoy Tic Tac Toe");
getch();
fclose(fp);
exit(0);
goto end;
}
struct ground *add;
add=(struct ground*)malloc(sizeof(struct ground));

fscanf(fp,"%d-%d-%d-%s",&win,&draw,&lost,name);
fclose(fp);
startgame:
check=0;
add->turn=0;
clrscr();
printf("Welcome %s\n",name);
printf("Press 'l' to move ahead\n");
printf("Press 'a' to come backward\n");
printf("Press 'h' to mark your answer\n");
printf("Press 't' to check your score\n");
printf("Press 'e' to exit\n");
printf("Press any key to start game.....");
x=getch();
if(x=='t')
{
clrscr();
total=win+draw+lost;
printf("Name:%s",name);
printf("\nWon %d games",win);
printf("\nDraw %d games",draw);
printf("\nLost %d games",lost);
printf("\nPlayed total %d games",total);
if(total!=0)
{
w=(float)win/total;
w=100*w;
d1=(float)draw/total;
d1=100*d1;
l=(float)lost/total;
l=l*100;
printf("\nWinning Rate:%.2f%",w);
printf("\nDraw Rate:%.2f%",d1);
printf("\nLost Rate:%.2f%",l);
}
gotoxy(48,24);
printf("Press any key to continue......");
getch();
goto startgame;
}
else if(x=='e')
goto end;
else
{
}
for(i=1;i<=9;i++)
add->square[i]=2;
clrscr();
printf("Press 'a' to play second, else press any key");
f=getch();
clrscr();
if(f=='a')
{
srand(time(0));
f=rand()%4;
if(f==0)
add->square[1]=5;
else if(f==1)
add->square[3]=5;
else if(f==2)
add->square[7]=5;
else
add->square[9]=5;
show(add);
}
for(i=1;i<=24;i++)
{
gotoxy(27,i);
printf("*");
gotoxy(53,i);
printf("*");
}
for(i=1;i<=78;i++)
{
gotoxy(i,8);
printf("*");
gotoxy(i,16);
printf("*");
}
c=1;
while(check==0)
{
comeback:
if(add->square[((c-1)%9)+1]!=2)
{
c=(c%9)+1;
goto comeback;
}
if(c<=3)
gotoxy(13+26*(c-1),4);
else if(c<=6)
gotoxy(13+26*(c-4),12);
else
gotoxy(13+26*(c-7),20);
printf("X");
d=getch();
if(d=='l')
{
show(add);
c=(c%9)+1;
goto comeback;
}
else if(d=='a')
{
show(add);
if(c<=1)
c=9;
else
c--;
a:
if(add->square[c]!=2)
{
if(c==1)
c=9;
else
c--;
goto a;
}
goto comeback;
}
else if(d=='0')
goto end;
else if(d=='h')
{
 fill(add,c);
 show(add);
 check=iswin(add);
 check=iswin(add);
 if(check==3)
 {
   gotoxy(35,9);
   printf("You Won");
   gotoxy(48,24);
   win++;
   printf("Press any key to continue.....");
   getch();
   goto startgame;
 }
 check=isempty(add);
 if(check==0)
 {
 tile=tictac(add,0);
 fill(add,tile);
 show(add);
 check=iswin(add);
 if(check==5)
 {
   gotoxy(35,9);
   printf("You Lost");
   gotoxy(48,24);
   lost++;
   printf("Press any key to continue.....");
   getch();
   goto startgame;
 }
 check=isempty(add);
 }
}
else
goto comeback;
}
gotoxy(31,9);
printf("Game Over, No Winner");
gotoxy(48,24);
draw++;
printf("Press any key to continue......");
getch();
goto startgame;
end:
printf("\nThank You %s, play again",name);
fp=fopen("tttdata.txt","w");
fprintf(fp,"%d-%d-%d-%s",win,draw,lost,name);
fclose(fp);
getche();
}