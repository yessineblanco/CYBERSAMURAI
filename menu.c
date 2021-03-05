#include <stdio.h>
#include <stdbool.h>
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "setrects.h"
#include "settings.h"
int main ()
{
  const int FPS=60;
  int shade_x=80,shade_y=195;
  Mix_Music *bmusic;
  Mix_Music *click;
  SDL_Surface *screen;
  SDL_Surface *shade;
  SDL_Surface *backg;
  SDL_Surface *solo;
  SDL_Surface *multiplayer;
  SDL_Surface *options;
  SDL_Surface *quit;
  SDL_Surface *on;
  SDL_Surface *off;
  SDL_Surface *name,*name1;
  SDL_Rect r_shade,r_solo,r_multi,r_option,r_quit,r_name,positionON, positionOFF;
  SDL_Rect rects[8];
  SDL_Rect rect;
  SDL_Event event;
  int done=1;
  int frame=0;
  Uint32 start;
  SDL_Color color[3] = {{255,255,255},{255,0,0},{0,0,255}};
  TTF_Font *font = NULL;
  TTF_Font *font1=NULL;
int z;



  SDL_Init(SDL_INIT_EVERYTHING);


  screen=SDL_SetVideoMode(1280,720,32,SDL_SWSURFACE);
	if(screen==NULL)
	{
		printf("unable to set video mode :%s\n",SDL_GetError());
		exit(EXIT_FAILURE);
	}

  if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("Unable to initialize SDL sound:%s",Mix_GetError());
		exit(EXIT_FAILURE);
	}
	bmusic=Mix_LoadMUS("GFX/Music/tt.mp3");


  if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
	{
		printf("Unable to initialize SDL sound:%s",Mix_GetError());
		exit(EXIT_FAILURE);
	}
	click=Mix_LoadMUS("GFX/Music/bip.mp3");

  backg=SDL_DisplayFormat(SDL_LoadBMP("GFX/Image/animation.bmp"));
  if(backg==NULL)
	{
		printf("unable to load bitamp: %s",SDL_GetError());
		exit(EXIT_FAILURE);
	}
  setrects_backm(rects);
  on =IMG_Load("GFX/Image/on.png");
  off =IMG_Load("GFX/Image/off.png");
  shade=IMG_Load("GFX/Image/shade.png");
  if(shade==NULL)
  {
    printf("unable to load bitamp: %s",SDL_GetError());
    exit(EXIT_FAILURE);
  }
  if(TTF_Init() == -1)
	{
    printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
	}
	font = TTF_OpenFont( "GFX/Fonts/zzzz.otf", 20 );

  if(TTF_Init() == -1)
	{
    printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
	}
	font1 = TTF_OpenFont( "GFX/Fonts/zzzz.otf", 40);

  Mix_PlayMusic(bmusic,-1);
  SDL_EnableKeyRepeat(5,1);
  Mix_AllocateChannels(10);
Mix_Chunk *mouseEffect = Mix_LoadWAV("GFX/Music/button16.wav");
Mix_VolumeChunk(mouseEffect, 100);
Mix_VolumeMusic(MIX_MAX_VOLUME);
positionON.x=1080;
positionON.y=620;
positionOFF.x=1180;
positionOFF.y=620;

  while(done)
  {
    rect.x=0;
    rect.y=0;

    r_shade.x=shade_x;
    r_shade.y=shade_y;
    SDL_BlitSurface(backg,&rects[frame],screen,&rect);

    SDL_BlitSurface(shade, NULL, screen, &r_shade);

    SDL_BlitSurface(off,NULL,screen,&positionOFF);
    SDL_BlitSurface(on,NULL,screen,&positionON);

    solo= TTF_RenderText_Solid(font,"PLAY", color[0]);
    multiplayer= TTF_RenderText_Solid(font,"MULTI-PLAYER", color[0]);
    options= TTF_RenderText_Solid(font,"OPTIONS", color[0]);
    quit= TTF_RenderText_Solid(font,"QUIT", color[0]);
    name= TTF_RenderText_Solid(font1,"Menu ", color[1]);
    r_solo.x=120;
    r_multi.x=120;
    r_option.x=120;
    r_quit.x=120;
    r_solo.y=200;
    r_multi.y=240;
    r_option.y=280;
    r_quit.y=320;
    r_name.x=140;
    r_name.y=60;


    SDL_BlitSurface(solo, NULL, screen, &r_solo);
    SDL_BlitSurface(multiplayer, NULL, screen, &r_multi);
    SDL_BlitSurface(options, NULL, screen, &r_option);
    SDL_BlitSurface(quit, NULL, screen, &r_quit);
    SDL_BlitSurface(name,NULL,screen,&r_name);
    SDL_Flip(screen);

    start = SDL_GetTicks();
    while(SDL_PollEvent(&event))
	    {
	        switch(event.type)
	        {
	            case SDL_QUIT:
	               	done=0;
	            break;
              case SDL_KEYDOWN:
              switch (event.key.keysym.sym)
                       {


                  case SDLK_d:
                      Mix_VolumeMusic(MIX_MAX_VOLUME/4);
                  break;
                  case SDLK_u:
                      Mix_VolumeMusic(MIX_MAX_VOLUME);
                  break;
                  case SDLK_f:
                   z=0;
                  switch(z) {
                                              case 0:
                                              screen=SDL_SetVideoMode(1280,720,32,SDL_SWSURFACE|SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                                              SDL_FillRect(screen,NULL,0);
                                              SDL_Flip(screen);
                                              z++;
                                          break;

                                          case 1:
                                          screen=SDL_SetVideoMode(1280,720,32,SDL_SWSURFACE|SDL_HWSURFACE | SDL_DOUBLEBUF );
                                          SDL_FillRect(screen,NULL,0);
                                          SDL_Flip(screen);
                                              z=0;
                                          break;
                                        }
                  break;
              }

              if (event.key.keysym.sym ==SDLK_DOWN)
              {
                  shade_y=shade_y+40;
                  if(shade_y==355)
                  {
                    shade_y=shade_y-160;
                  }
              }
              if (event.key.keysym.sym ==SDLK_UP)
              {
                  shade_y=shade_y-40;
                  if(shade_y==155)
                  {
                    shade_y=shade_y+160;
                  }
              }
              break;


              case SDL_MOUSEMOTION:
              if((event.motion.y >= 200)&&(event.motion.y <= 200+r_solo.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_solo.w))
              {


                shade_x=80;
                shade_y=195;

              }
              else if((event.motion.y >= 240)&&(event.motion.y <= 240+r_multi.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_multi.w))
              {
                shade_x=80;
                shade_y=195+40;

              }
              //options//
              else if((event.motion.y >= 280)&&(event.motion.y <= 280+r_option.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_option.w))
              {
                shade_x=80;
                shade_y=195+80;

              }
              //Quit//
              else if((event.motion.y >= 320)&&(event.motion.y <= 320+r_quit.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_quit.w))
              {
                shade_x=80;
                shade_y=195+120;

              }

              break;

	            case SDL_MOUSEBUTTONUP:
                  //solo//
	                if((event.motion.y >= 200)&&(event.motion.y <= 200+r_solo.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_solo.w))
	                {
                    Mix_PlayChannel(-1,mouseEffect,0);
                      solo= TTF_RenderText_Solid(font,"Play", color[1]);
                      SDL_BlitSurface(solo, NULL, screen, &r_solo);
                      SDL_Flip(screen);
                     										done=1;
	                }
                  //multiplayer//
	                else if((event.motion.y >= 240)&&(event.motion.y <= 240+r_multi.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_multi.w))
	                {
                                         Mix_PlayChannel(-1,mouseEffect,0);
                      multiplayer= TTF_RenderText_Solid(font,"MULTI-PLAYER", color[1]);
                      SDL_BlitSurface(multiplayer, NULL, screen, &r_multi);
                      SDL_Flip(screen);
                      done=1;
	                }
                  //options//
	                else if((event.motion.y >= 280)&&(event.motion.y <= 280+r_option.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_option.w))
	                {
                    Mix_PlayChannel(-1,mouseEffect,0);
                      options= TTF_RenderText_Solid(font,"OPTIONS", color[1]);
                      SDL_BlitSurface(options, NULL, screen, &r_option);
                      SDL_Flip(screen);
                      done=1;
                      settings();
	                }
                  //Quit//
	                else if((event.motion.y >= 320)&&(event.motion.y <= 320+r_quit.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_quit.w))
	                {
                    Mix_PlayChannel(-1,mouseEffect,0);
                      quit= TTF_RenderText_Solid(font,"QUIT", color[1]);
                      SDL_BlitSurface(quit, NULL, screen, &r_quit);
                      SDL_Flip(screen);
											done=0;
	                }
	                //SOUND ON//
	                else if((event.motion.y > 620)&&(event.motion.y < 700)&&(event.motion.x> 1080)&&(event.motion.x < 1130))
    			 {
       		 Mix_PlayChannel(-1,mouseEffect,0);
       		 Mix_VolumeMusic(MIX_MAX_VOLUME);
     			}
     			//SOUND OFF//
                	else if((event.motion.y > 620)&&(event.motion.y < 700)&&(event.motion.x> 1180)&&(event.motion.x < 1230))
     			{
       	 	Mix_VolumeMusic(MIX_MAX_VOLUME==0);

     			}
							break;


            /*      if (event.key.keysym.sym ==SDLK_DOWN)
                  {
                      shade_y=shade_y+40;
                      if(shade_y==355)
                      {
                        shade_y=shade_y-160;
                      }
                  }
                  if (event.key.keysym.sym ==SDLK_UP)
                  {
                      shade_y=shade_y-40;
                      if(shade_y==155)
                      {
                        shade_y=shade_y+160;
                      }
                  }
              break;*/

	        }
	    }


    frame++;
    if(frame>5)
      frame=0;
    if(6000/FPS>(SDL_GetTicks()-start))
      SDL_Delay(6000/FPS-(SDL_GetTicks()-start));
  }


  SDL_FreeSurface(backg);
  SDL_Quit();


  return done;
}
