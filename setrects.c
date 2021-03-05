#include <stdio.h>
#include "SDL/SDL.h"

void setrects_backm(SDL_Rect* clip)
{
  int c;


  for( c=0; c<5; c++)
  {

     clip[c].x = 0 +c*1280;
     clip[c].y = 0;
     clip[c].w = 1280;
     clip[c].h = 720;
  }
}



