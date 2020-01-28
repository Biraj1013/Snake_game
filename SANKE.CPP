#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<graphics.h>
#include<time.h>
int x[100],y[100],length,fx,fy,t,flag,gameover,score;
void set()
{
    int i;
    x[0]=300;
    y[0]=300;
    length=5;
    srand(time(NULL));
    do
    {
      fx=rand()%400;
      fy=rand()%400;
    }while(fx<200||fy<200);
     for(i=1;i<length;i++)
     {
	x[i]=x[0]-(i*10);
	y[i]=y[0];
     }
    gameover=0;
    score=0;
}
void draw()
{
   int i;
   clrscr();
   printf("i=up,k=down,l=right,j=left,z=terminated game\n");
   printf("\n\n\n\n\n\n\t\t\tSCORE=%d\n",score);
   setfillstyle(1,1);
   bar(fx,fy,fx+5,fy+5);
   line(200,200,400,200);
   line(400,200,400,400);
   line(400,400,200,400);
   line(200,400,200,200);
   if(x[0]>200&&y[0]>200&&x[0]<400&&y[0]<400)
   {
     bar(x[0],y[0],x[0]+5,y[0]+5);
     for(i=1;i<length;i++)
     {
	bar(x[i],y[i],x[i]+5,y[i]+5);
     }
     for(i=length;i>0;i--)
     {
       x[i]=x[i-1];
       y[i]=y[i-1];
     }
   }
   else
   {
     printf("\t\t\tGAME OVER\n");
    // printf("SCORE=%d",score);
     gameover=1;
   }
}
void input()
{
   char ch;
   if(kbhit())
   {
     ch=getch();
     if(ch=='i'||ch==72)
	  flag=1;
     if(ch=='j'||ch==75)
	  flag=2;
     if(ch=='k'||ch==80)
	  flag=3;
     if(ch=='l'||ch==77)
	  flag=4;
     if(ch=='z')
	  gameover=1;
   }
}
void mainlogic()
{
  int i;
  switch(flag)
   {
      case 1:
	y[0]-=5;
	break;
      case 2:
	x[0]-=5;
	break;
      case 3:
	y[0]+=5;
	break;
      case 4:
	x[0]+=5;
	break;
      default:
	break;
   }
   if(fx==x[0]&&fy==y[0])
   {
      do
      {
	 fx=rand()%396;
	 fy=rand()%396;
      }while(fx<196||fy<196);
      bar(fx,fy,fx+5,fy+5);
      score+=10;
      length+=1;
    }
 }
void main()
{
   int gd=DETECT,gm;
   clrscr();
   initgraph(&gd,&gm,"C:\\TURBOC3\\BGI");
   set();
   while(1)
   {
     draw();
     input();
     mainlogic();
     delay(500);
     if(gameover==1)
       break;
   }
     getch();
}