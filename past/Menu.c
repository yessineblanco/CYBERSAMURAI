#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include "fonction.h"
int main()
{
SDL_Surface *screen=NULL;
SDL_Surface *background=NULL;
SDL_Surface *play=NULL;
SDL_Surface *options=NULL;
SDL_Surface *quit=NULL;
SDL_Surface *on=NULL;
SDL_Surface *off=NULL;
SDL_Surface *texte=NULL;
SDL_Surface *play2=NULL;
SDL_Surface *options2=NULL;
SDL_Surface *quit2=NULL;
SDL_Surface *pop=NULL;
SDL_Surface *menu_setting=NULL;
SDL_Surface *anim=NULL;
SDL_Rect rects[6];
SDL_Rect rect;

TTF_Font *police=NULL;
TTF_Init();
SDL_Color blanc={255,255,255};

Mix_Music *musique;
SDL_Rect positionscreen,positionplay,positionoptions,positionquit,positionON,positionOFF,positiontexte,positionplay2,positionsettings2,positionquit2,positionpop,pos,pos_set;
SDL_Event event;
int done=1,x,y,i=0;
int frame=0;



//iNITIALISER LA FENETRE
if(SDL_Init(SDL_INIT_VIDEO)!=0)
{
printf("unable t initialize SDL: %s /n",SDL_GetError());
return 1;
}
//THEL LFENETRE
screen=SDL_SetVideoMode(1280,720,0,SDL_HWSURFACE | SDL_DOUBLEBUF);
//TLOADI L'IMAGE
play =IMG_Load("GFX/Image/play.png");
options =IMG_Load("GFX/Image/settings.png");
quit =IMG_Load("GFX/Image/quit.png");
on =IMG_Load("GFX/Image/on.png");
off =IMG_Load("GFX/Image/off.png");
play2 =IMG_Load("GFX/Image/play2.png");
options2 =IMG_Load("GFX/Image/SETTINGS2.png");
quit2 =IMG_Load("GFX/Image/EXIT2.png");
menu_setting =IMG_Load("GFX/Image/pop.png");
anim=IMG_Load("GFX/Image/animation.png");

police = TTF_OpenFont("GFX/Fonts/AlmondCream.ttf",100);
texte = TTF_RenderText_Blended(police,"MENU",blanc);

anim=SDL_DisplayFormat(SDL_LoadBMP("GFX/Image/animation.bmp"));
if(anim==NULL)
{
  printf("unable to load : %s",SDL_GetError());
  exit(EXIT_FAILURE);
}
animationbg(rects);

SDL_WM_SetCaption("MENU ",NULL);//title
Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
musique = Mix_LoadMUS("GFX/Music/tt.mp3");
Mix_PlayMusic(musique, -1);
Mix_AllocateChannels(10);
Mix_Chunk *mouseEffect = Mix_LoadWAV("GFX/Music/button16.wav");
Mix_VolumeChunk(mouseEffect, 100);
Mix_VolumeMusic(MIX_MAX_VOLUME);



//POSTION LEL SCREEN
positionscreen.x=0;
positionscreen.y=0;
positionplay.x=40;
positionplay.y=100;
positionoptions.x=40;
positionoptions.y=200;
positionquit.x=40;
positionquit.y=300;
positionON.x=1100;
positionON.y=600;
positionOFF.x=1200;
positionOFF.y=600;
positiontexte.x=550;
positiontexte.y=40;
positionplay2.x=40;
positionplay2.y=100;
positionsettings2.x=40;
positionsettings2.y=200;
positionquit2.x=40;
positionquit2.y=300;
positionpop.x=0;
positionpop.y=0;
pos.x=  0;
pos.y=0;
pos_set.x=500;
pos_set.y=200;
SDL_FillRect(screen,NULL,0);
SDL_BlitSurface(anim,&rects[frame],screen,&rect);
SDL_Flip(screen);


while (done) {

        rect.x=0;
        rect.y=0;
      SDL_BlitSurface(anim,&rects[frame],screen,&rect);


        SDL_BlitSurface(play,NULL,screen,&positionplay);
        SDL_BlitSurface(options,NULL,screen,&positionoptions);
        SDL_BlitSurface(quit,NULL,screen,&positionquit);
        SDL_BlitSurface(off,NULL,screen,&positionOFF);
        SDL_BlitSurface(on,NULL,screen,&positionON);
        SDL_BlitSurface(texte,NULL,screen,&positiontexte);
  while(SDL_PollEvent(&event))
{
  switch (event.type)
	{
            case SDL_QUIT:
            done=0;
            break;


            case SDL_KEYDOWN:
            SDL_BlitSurface(off,NULL,screen,&positionOFF);
            SDL_BlitSurface(on,NULL,screen,&positionON);
            SDL_BlitSurface(texte,NULL,screen,&positiontexte);
                      switch (event.key.keysym.sym)
                      {
                      case SDLK_ESCAPE:
                      done=0;
                      break;
                      case SDLK_p:
                      Mix_VolumeMusic(MIX_MAX_VOLUME==0);
                      break;
                      case SDLK_o:
                      Mix_VolumeMusic(MIX_MAX_VOLUME);
                      break;
                      case SDLK_DOWN:


                        switch (i) {
                              case 0:

                              positionquit.x=40;
                              SDL_BlitSurface(quit,NULL,screen,&positionquit);
                              positionplay.x=100;
                              SDL_BlitSurface(play,NULL,screen,&positionplay);
                              i++;
                          break;
                              case 1:

                              positionplay.x=40;
                              SDL_BlitSurface(play,NULL,screen,&positionplay);
                              positionoptions.x=100;
                              SDL_BlitSurface(options,NULL,screen,&positionoptions);
                              i++;
                          break;
                          case 2:

                              positionoptions.x=40;
                              SDL_BlitSurface(options,NULL,screen,&positionoptions);
                              positionquit.x=100;
                              SDL_BlitSurface(quit,NULL,screen,&positionquit);
                              i=0;
                          break;
                        }
                      break;
                      case SDLK_UP:

                        switch (i) {
                              case 2:

                              positionoptions.x=40;
                              SDL_BlitSurface(options,NULL,screen,&positionoptions);
                              positionplay.x=100;
                              SDL_BlitSurface(play,NULL,screen,&positionplay);
                              i=0;

                          break;
                                case 1:

                                positionquit.x=40;
                                SDL_BlitSurface(quit,NULL,screen,&positionquit);
                                positionoptions.x=100;
                                SDL_BlitSurface(options,NULL,screen,&positionoptions);
                                i++;
                          break;
                          case 0:

                                positionplay.x=40;
                                SDL_BlitSurface(play,NULL,screen,&positionplay);
                                positionquit.x=100;
                                SDL_BlitSurface(quit,NULL,screen,&positionquit);
                                i++;
                          break;
                        }
                      break;
                      case SDLK_d:
                          Mix_VolumeMusic(MIX_MAX_VOLUME/4);
                      break;
                      case SDLK_u:
                          Mix_VolumeMusic(MIX_MAX_VOLUME);
                      break;
                      case SDLK_MINUS:
                          Mix_VolumeMusic(MIX_MAX_VOLUME);
                      break;
                      case SDLK_PLUS:
                          Mix_VolumeMusic(MIX_MAX_VOLUME);
                      break;
                      case SDLK_f:
                      switch (i) {
                            case 0:
                            screen =SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                            SDL_FillRect(screen,NULL,0);
                            SDL_Flip(screen);
                            i++;
                        break;

                        case 1:
                        screen =SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_SRCALPHA);
                        SDL_FillRect(screen,NULL,0);
                        SDL_Flip(screen);
                            i=0;
                        break;
                      }

                      break;
                      }
              break;

              case SDL_MOUSEMOTION :
                    x=event.motion.x;
                    y=event.motion.y;
                    if((x>40) && (x<360) && (y>100) && (y<195))
                    {
                      SDL_BlitSurface(play2,NULL,screen,&positionplay2);
                      SDL_Flip(screen);
                      }
                    if((x>40) && (x<360) && (y>200) && (y<295))
                    {
                      SDL_BlitSurface(options2,NULL,screen,&positionsettings2);
                      SDL_Flip(screen);
                    }
                    if((x>40) && (x<360) && (y>300) && (y<395))
                    {
                      SDL_BlitSurface(quit2,NULL,screen,&positionquit2);
                      SDL_Flip(screen);
                    }
              break;
              case SDL_MOUSEBUTTONDOWN:
                   if(event.button.button == SDL_BUTTON_LEFT)
                   {
                     x = event.button.x;
                     y = event.button.y;
                   if((x>40) && (x<360) && (y>100) && (y<195))
                   {
                     Mix_PlayChannel(-1,mouseEffect,0);
                     SDL_BlitSurface(play2,NULL,screen,&positionplay2);
                     SDL_Flip(screen);
                   }
                   if((x>40) && (x<360) && (y>200) && (y<295))
                   {
                     SDL_BlitSurface(options2,NULL,screen,&positionsettings2);
                     SDL_Flip(screen);
                     Mix_PlayChannel(-1,mouseEffect,0);
                     SDL_BlitSurface(menu_setting,NULL,screen,&pos_set);
                     SDL_Flip(screen);

                 }
                   if((x>40) && (x<360) && (y>300) && (y<395))
                   {
                     done=0;
                   }
                   if((x>1100) && (x<1150) && (y>600) && (y<700))
                   {
                     Mix_PlayChannel(-1,mouseEffect,0);
                     Mix_VolumeMusic(MIX_MAX_VOLUME);
                   }
                   if((x>1200) && (x<1250) && (y>600) && (y<700))
                   {
                     Mix_VolumeMusic(MIX_MAX_VOLUME==0);
                   }
                   if((x>520) && (x<570) && (y>320) && (y<360))
                   {
                     Mix_PlayChannel(-1,mouseEffect,0);
                     screen =SDL_SetVideoMode(1280,720,32,SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                     SDL_FillRect(screen,NULL,0);
                     SDL_Flip(screen);
                   }
                   if((x>600) && (x<700) && (y>450) && (y<500))
                   {
                     Mix_PlayChannel(-1,mouseEffect,0);
                     SDL_FillRect(screen,NULL,0);
                     SDL_Flip(screen);

                   }
                 }
              break;

 }//fin event.type
  SDL_Flip(screen);

}//fin SDL_PollEvent
}//fin while
SDL_Flip(screen);
SDL_VideoQuit();
TTF_CloseFont(police);
TTF_Quit();
SDL_Quit();
}
