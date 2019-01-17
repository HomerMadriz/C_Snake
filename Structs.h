#include "allegro5/allegro.h"
#define MAX_L 32527

typedef struct point 
{
	unsigned int size_x, size_y; 
	unsigned int x, y; 
	ALLEGRO_BITMAP *image; 
	int puntaje;
} Point; 

typedef struct snake
{
	Point points[MAX_L];
	unsigned int length; 
	int dx;
	int dy;
	unsigned int offset;
	int ultimo_x, ultimo_y;
	
}Snake; 


void drawBitmap (Snake * mysnake, ALLEGRO_BITMAP * image)
{
	int i;
	for(i=mysnake->offset; i< (mysnake->length + mysnake->offset); i++)
		al_draw_bitmap(image, mysnake->points[i].x, mysnake->points[i].y, 0);
}


void fillSnake (Snake * mysnake, const int SCREEN_W, const int SCREEN_H)
{
	int i;
	for(i=1; i<MAX_L; i++){
		mysnake->points[i].size_x = 16;
		mysnake->points[i].size_y = 16;
		mysnake->points[i].x = (mysnake->points[i-1].x + mysnake->points[i-1].size_x)%SCREEN_W;
		mysnake->points[i].y = (mysnake->points[i-1].y)%SCREEN_H;
	}
}

bool intersects(int x1, int x2, int y1, int y2, Point object, int xi[4], int yi[4])
{
	int i, A, B;
	for(i=0; i<4; i++)
	{
		A= i & 1;
		B= (i>>1)&1;

		xi[i] = object.x + A * object.size_x;
		yi[i] = object.y + B * object.size_y;

		if((xi[i]>= x1) && (xi[i]<= x2) && (yi[i] >= y1) && (yi[i] <= y2))
		{
			return true;
		}
	}
	return false;
}



