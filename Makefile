prog:  menu.o  setrects.o settings.o
	gcc  menu.o  setrects.o settings.o -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
menu.o:menu.c
	gcc -c menu.c
setrects.o:setrects.c
	gcc -c setrects.c
settings.o:settings.c
	gcc -c settings.c
