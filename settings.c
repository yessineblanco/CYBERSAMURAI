#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "setrects.h"


int settings ()
{
  const int FPS=60;
  int shade_x=80,shade_y=195;

  Mix_Music *click;
  SDL_Surface *screen;
  SDL_Surface *shade;
  SDL_Surface *backg;
  SDL_Surface *volup;
  SDL_Surface *voldown;
  SDL_Surface *credits;
  SDL_Surface *back;
  SDL_Surface *name,*name1;
  SDL_Rect r_shade,r_volup,r_multi,r_option,r_back,r_name,r_name1;
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
	click=Mix_LoadMUS("GFX/Music/bip.mp3");

  backg=SDL_DisplayFormat(SDL_LoadBMP("GFX/Image/animation.bmp"));
  if(backg==NULL)
	{
		printf("unable to load bitamp: %s",SDL_GetError());
		exit(EXIT_FAILURE);
	}
  setrects_backm(rects);
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
	font1 = TTF_OpenFont( "GFX/Fonts//zzzz.otf", 40);
  Mix_AllocateChannels(10);
Mix_Chunk *mouseEffect = Mix_LoadWAV("GFX/Music/button16.wav");
Mix_VolumeChunk(mouseEffect, 100);
Mix_VolumeMusic(MIX_MAX_VOLUME);


  while(done)
  {
    rect.x=0;
    rect.y=0;

    r_shade.x=shade_x;
    r_shade.y=shade_y;
    SDL_BlitSurface(backg,&rects[frame],screen,&rect);
    SDL_BlitSurface(shade, NULL, screen, &r_shade);

    volup= TTF_RenderText_Solid(font,"VOLUME UP", color[0]);
    voldown= TTF_RenderText_Solid(font,"VOLUME DOWN", color[0]);
    credits= TTF_RenderText_Solid(font,"CREDITS", color[0]);
    back= TTF_RenderText_Solid(font,"BACK", color[0]);
    name= TTF_RenderText_Solid(font1,"SETTINGS ", color[1]);
    name1=TTF_RenderText_Solid(font,"FULL SCREEN ", color[0]);
    r_volup.x=120;
    r_multi.x=120;
    r_option.x=120;
    r_back.x=120;
    r_volup.y=200;
    r_multi.y=240;
    r_option.y=280;
    r_back.y=320;
    r_name.x=140;
    r_name.y=60;
    r_name1.x=120;
    r_name1.y=360;


    SDL_BlitSurface(volup, NULL, screen, &r_volup);
    SDL_BlitSurface(voldown, NULL, screen, &r_multi);
    SDL_BlitSurface(credits, NULL, screen, &r_option);
    SDL_BlitSurface(back, NULL, screen, &r_name1);
    SDL_BlitSurface(name,NULL,screen,&r_name);
    SDL_BlitSurface(name1,NULL,screen,&r_back);

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

              case SDL_MOUSEMOTION:
              if((event.motion.y >= 200)&&(event.motion.y <= 200+r_volup.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_volup.w))
              {


                shade_x=80;
                shade_y=195;

              }
              else if((event.motion.y >= 240)&&(event.motion.y <= 240+r_multi.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_multi.w))
              {
                shade_x=80;
                shade_y=195+40;

              }
              //credits//
              else if((event.motion.y >= 280)&&(event.motion.y <= 280+r_option.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_option.w))
              {
                shade_x=80;
                shade_y=195+80;

              }
              //back//
              else if((event.motion.y >= 320)&&(event.motion.y <= 320+r_back.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_back.w))
              {
                shade_x=80;
                shade_y=195+120;

              }
              //fullscreen
              else if((event.motion.y >= 360)&&(event.motion.y <= 360+r_name1.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_name1.w))
              {
                shade_x=80;
                shade_y=195+160;

              }

              break;

	            case SDL_MOUSEBUTTONUP:
                  //volup//
	                if((event.motion.y >= 200)&&(event.motion.y <= 200+r_volup.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_volup.w))
	                {
                      volup= TTF_RenderText_Solid(font,"VOLUME UP", color[1]);
                      SDL_BlitSurface(volup, NULL, screen, &r_volup);
                      SDL_Flip(screen);
                      Mix_PlayChannel(-1,mouseEffect,0);
                                              Mix_VolumeMusic(MIX_MAX_VOLUME);
											done=1;
	                }
                  //voldown//
	                else if((event.motion.y >= 240)&&(event.motion.y <= 240+r_multi.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_multi.w))
	                {
                    Mix_PlayChannel(-1,mouseEffect,0);

                      voldown= TTF_RenderText_Solid(font,"VOLUME DOWN", color[1]);
                      SDL_BlitSurface(voldown, NULL, screen, &r_multi);
                      SDL_Flip(screen);
                                                Mix_VolumeMusic(MIX_MAX_VOLUME/4);
                      done=1;
	                }
                  //credits//
	                else if((event.motion.y >= 280)&&(event.motion.y <= 280+r_option.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_option.w))
	                {
                    Mix_PlayChannel(-1,mouseEffect,0);

                      credits= TTF_RenderText_Solid(font,"CREDITS", color[1]);
                      SDL_BlitSurface(credits, NULL, screen, &r_option);
                      SDL_Flip(screen);
                      done=1;
	                }
                  //back//
	                else if((event.motion.y >= 320)&&(event.motion.y <= 320+r_back.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_back.w))
	                {
                    Mix_PlayChannel(-1,mouseEffect,0);

                      name1= TTF_RenderText_Solid(font,"FULLSCREEN", color[1]);
                      SDL_BlitSurface(name1, NULL, screen, &r_name1);
                      SDL_Flip(screen);
                      int i=0;
                      switch(i) {
                                                  case 0:
                                                  screen=SDL_SetVideoMode(1280,720,32,SDL_SWSURFACE|SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_FULLSCREEN);
                                                  SDL_FillRect(screen,NULL,0);
                                                  SDL_Flip(screen);
                                                  i++;
                                              break;

                                              case 1:
                                              screen=SDL_SetVideoMode(1280,720,32,SDL_SWSURFACE|SDL_HWSURFACE | SDL_DOUBLEBUF );
                                              SDL_FillRect(screen,NULL,0);
                                              SDL_Flip(screen);
                                                  i=0;
                                              break;
                                            }

                                            break;

	                }
                  else if((event.motion.y >= 360)&&(event.motion.y <= 360+r_name1.h)&&(event.motion.x >= 120)&&(event.motion.x <= 120+r_name1.w))
	                {
                    Mix_PlayChannel(-1,mouseEffect,0);

                      back= TTF_RenderText_Solid(font,"BACK", color[1]);
                      SDL_BlitSurface(back, NULL, screen, &r_back);
                      SDL_Flip(screen);
                      done=0;
                          }
							break;


	        }
	    }


    frame++;
    if(frame>5)
      frame=0;
    if(6000/FPS>(SDL_GetTicks()-start))
      SDL_Delay(6000/FPS-(SDL_GetTicks()-start));
  }




  return done;
}
