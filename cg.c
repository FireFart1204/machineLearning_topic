#include<stdio.h>  
#include<conio.h>  
#include<graphics.h>  
void main()  
{  
        int gm,gr,xcmin,ycmin,xcmax,ycmax,x,y,c;  
        clrscr();  
        detectgraph(&gm,&gr);  
        initgraph(&gm,&gr,"c:\\tc\\BGI");  
          printf("Enter the clipmin coordinate :\n");  
          scanf("%d%d",&xcmin,&ycmin);  
          printf("Enter the clipmax coordinate :\n");  
          scanf("%d%d",&xcmax,&ycmax);  
          rectangle(xcmin,ycmax,xcmax,ycmin);  
          printf("Enter the coordinate of the point:\n");  
          scanf("%d%d",&x,&y);  
          detectgraph(&gm,&gr);  
          initgraph(&gm,&gr,"c:\\tc\\BGI");  
          putpixel(x,y,15);  
          printf("\n1.Point clipping\n2.Exit\nEnter your choice:\n");  
           scanf("%d",&c);  
           switch(c)  
     {  
           case 1:  
          detectgraph(&gm,&gr);  
          initgraph(&gm,&gr,"d:\\tc\\BGI");  
          rectangle (xcmin,ycmax,xcmax,ycmin);  
          printf("*******POINT CLIPPING******\n");  
          if ((xcmin<x) && (x<xcmax))  
      {  
         if ((ycmin<y) && (y<ycmax))  
        {  
          printf("The point is inside the clip window\n");  
           putpixel(x,y,15);  
        }  
     }  
          else  
          printf("The point is outside the clipwindow \nThe point is clipped\n");  
          break;  
         case 2: exit(0);  
    }  
         getch();  
}  




/////////////////////////////////////////////////////////////



#include<stdio.h>  
#include<graphics.h>  
void drawline(int x0, int y0, int x1, int y1)  
{  
    int dx, dy, p, x, y;  
    dx=x1-x0;  
    dy=y1-y0;  
    x=x0;  
    y=y0;  
    p=2*dy-dx;  
    while(x<x1)  
    {  
        if(p>=0)  
        {  
            putpixel(x,y,7);  
            y=y+1;  
            p=p+2*dy-2*dx;  
        }  
        else  
        {  
            putpixel(x,y,7);  
            p=p+2*dy;}  
            x=x+1;  
        }  
}  
int main()  
{  
    int gdriver=DETECT, gmode, error, x0, y0, x1, y1;  
    initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");  
    printf("Enter co-ordinates of first point: ");  
    scanf("%d%d", &x0, &y0);  
    printf("Enter co-ordinates of second point: ");  
    scanf("%d%d", &x1, &y1);  
    drawline(x0, y0, x1, y1);  
    return 0;  
}  




/////////////////////////////////////////////////////////////////




#include <graphics.h>
#include <dos.h>
#include <conio.h>
main()
{
   int i, j = 0, gd = DETECT, gm;

   initgraph(&gd,&gm,"C:\\TC\\BGI");

   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
   outtextxy(25,240,"Press any key to view the moving car");

   getch();
   setviewport(0,0,639,440,1);

   for (i = 0; i <= 420; i = i + 10, j++)
   {
      rectangle(50+i,275,150+i,400);
      rectangle(150+i,350,200+i,400);
      circle(75+i,410,10);
      circle(175+i,410,10);
      setcolor(j);
      delay(100);

      if (i == 420)
         break;

      clearviewport();
   }

   getch();
   closegraph();
   return 0;
}




/////////////////////////////////////////////////////



// C Implementation for drawing ellipse 
#include <graphics.h> 

int main() 
{ 
	// gm is Graphics mode which is a computer display 
	// mode that generates image using pixels. 
	// DETECT is a macro defined in "graphics.h" header file 
	int gd = DETECT, gm; 

	// location of ellipse 
	int x = 250, y = 200; 

	// here is the starting angle 
	// and end angle 
	int start_angle = 0; 
	int end_angle = 360; 

	// radius from x axis and y axis 
	int x_rad = 100; 
	int y_rad = 50; 

	// initgraph initializes the graphics system 
	// by loading a graphics driver from disk 
	initgraph(&gd, &gm, ""); 

	// ellipse function 
	ellipse(x, y, start_angle, 
	end_angle, x_rad, y_rad); 

	getch(); 

	// closegraph function closes the graphics 
	// mode and deallocates all memory allocated 
	// by graphics system . 
	closegraph(); 

	return 0; 
} 





////////////////////////////////////////////////////////////////



#include<graphics.h>
 
int main() {
   int gd = DETECT, gm, x, y;
   initgraph(&gd, &gm, "C:\\TC\\BGI");
 
   settextstyle(BOLD_FONT,HORIZ_DIR,2);
   outtextxy(220,10,"PIE CHART");
   /* Setting cordinate of center of circle */
   x = getmaxx()/2;
   y = getmaxy()/2;
 
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
   setfillstyle(SOLID_FILL, RED);
   pieslice(x, y, 0, 60, 120);
   outtextxy(x + 140, y - 70, "FOOD");
 
   setfillstyle(SOLID_FILL, YELLOW);
   pieslice(x, y, 60, 160, 120);
   outtextxy(x - 30, y - 170, "RENT");
 
   setfillstyle(SOLID_FILL, GREEN);
   pieslice(x, y, 160, 220, 120);
   outtextxy(x - 250, y, "ELECTRICITY");
 
   setfillstyle(SOLID_FILL, BROWN);
   pieslice(x, y, 220, 360, 120);
   outtextxy(x, y + 150, "SAVINGS");
 
   closegraph();
   return 0;
}



////////////////////////////////////////////////////


#include<graphics.h>
#include<conio.h>
main()
{
   int gd = DETECT,gm,left=100,top=100,right=200,bottom=200,x= 300,y=150,radius=50;

   initgraph(&gd, &gm, "C:\\TC\\BGI");

   rectangle(left, top, right, bottom);
   circle(x, y, radius);
   bar(left + 300, top, right + 300, bottom);
   line(left - 10, top + 150, left + 410, top + 150);
   ellipse(x, y + 200, 0, 360, 100, 50);
   outtextxy(left + 100, top + 325, "My first C graphics program");

   getch();
   closegraph();
   return 0;
}


