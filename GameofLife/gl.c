/**
 * @file gl.c
 * @breif holds calls to functions that implement conways game of life
 * @detail take user input from command line, set defaults if no args given, then loop rendering and testing for new generation forever
 *
 *
 *
 *
 * @author Joseph Ladino
 * @date Dec 1 2016
 * @bug none
 * @todo fix sdl files' memory problems
 **/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SDL2/SDL.h" 
#include "sdl.h"
#include "life.h"
#include <unistd.h> //used for getopt

int main(int argc, char *argv[])
{
	int width = 600;
	int height = 800; /*these will be dynamically set in the end*/
	int sprite_size = 8; /* either 2, 4, 8, or 16 */
//	int m = -66;
//	int n = -10;
        /* colors are RGB model valid values [0, 255] */
	unsigned char red = 255;
	unsigned char green = 255;
	unsigned char blue = 255;
        struct sdl_info_t sdl_info; /* this is needed to graphically display the game */
        
        /* set up SDL -- works with SDL2 */
//	init_sdl_info(&sdl_info, height, width, sprite_size, red, green, blue);

	/* your life initialization code here */
        
        
        int c = 0;
        FILE *pattern = NULL;
        int x_start, y_start;
        width = 600;
        height = 800;
        sprite_size = 4;
        x_start = (height/sprite_size)/2;
        y_start = (width/sprite_size)/2;
        pattern = fopen("growths/glider_106.lif", "r");
        int edge = 0;


        if (argc == 1){
                goto DEFAULTS;
        }

        while((c=getopt(argc, argv, ":e:hf:l:w:s:o:c:")) !=-1) {
                switch (c) {
                        case 'e': //edge
                                if (strcmp("hedge", optarg) == 0) {
                                        printf("edge = hedge\n");
                                        edge = 0;
                                }
                                else if (strcmp("torus", optarg) == 0){
                                        printf("edge = torus\n");
                                        edge = 1;
                                }
                                else if (strcmp("klein", optarg) == 0){
                                        printf("edge = klein bottle\n");
                                        edge = 2;
                                }
                                else {
                                        printf("error: missing arg - using default\n");
                                }
        
                                                       
                                break;
                        case 'c':
                                sscanf(optarg, "%c:%c:%c", &red, &green, &blue);
                               break; 

                        case 'f'://file
                                pattern=fopen(optarg, "r");
                                if (!pattern) {
                                        printf("'-f' failed - file not found. using defaults");
                      
                                }
                                else {
                                        printf("file scanned\n");
                                }
                                break;
                        case 'l': //length (height)
                                height = atoi(optarg);
                                printf("height = %d\n", height);
                                break;
                        case 'w': //width
                                width = atoi(optarg);
                                printf("width = %d\n", width);
                                break;
                        case 'o': 
                                if (!optarg) {
                                        printf("error: missing arg.\n using default\n");
                                }
                                sscanf(optarg, "%d,%d", &x_start, &y_start);
                                printf("[x, y] = [%d, %d]\n", x_start, y_start);
                                break;
                                
                        case 's'://sprite size
                                sprite_size = atoi(optarg);
                                if (sprite_size != 2) {
                                        if (sprite_size != 4){
                                                if (sprite_size != 8) {
                                                        if (sprite_size != 16) {
                                                                printf("error: illegal size.\n");
                                                        }
                                                }
                                        }
                                }
                                printf("sprite size = %d\n", sprite_size);
                                break;

                        case 'h': //help
                                printf("usage: life [-h -c -e -f -l -w -s -o]\n");
                                printf("h: help\n");
                                printf("c: sets color (expects arg: )\n");
                                printf("o: sets (0, 0) point in matrix (espects arg: x_cordinate,y_cordinate)\n");
                                printf("e: edge type (expects arg: hedge torus klein)\n");
                                printf("f: file to read (expects arg: file path)\n");
                                printf("l: length (expects arg: length in bits)\n");
                                printf("w: width (expects arg: width in bits)\n");
                                printf("s: sprite size (expects arg: size)\n");
                                printf("        size must be [2, 4, 8, 16]\n");
                                return 0;
                                break;
                        case ':': //missing arg
                                printf("error: missing arguement\n");
                                printf("using defaults\n");
                                break;
                        case '?': //unknown thing
                        default: //error in input
                                printf("error: illegal option %c - ignored\n", optopt);
                                printf("using defaults\n\n");
                                printf("usage: life -h -e -f -l -w -s\n");
                                break;
                }
        }


DEFAULTS: 
        init_sdl_info(&sdl_info, height, width, sprite_size, red, green, blue);
       
        
        int cols = (width/sprite_size);
        int rows = (height/sprite_size);
        unsigned char **world = NULL;
        unsigned char **hell = NULL;
        
//        pattern = fopen("growths/gunstar2_106.lif", "r");
        
        world = init_matrix(rows, cols);
        hell = init_matrix(rows, cols);
        read_file(pattern, world, x_start, y_start);

        /* Main loop: loop forever. */
	while (1)
	{
		/* your game of life code goes here  */		



		/* change the  modulus value to slow the rendering */
		 if (SDL_GetTicks() % 1 == 0) {
		//	sdl_test(&sdl_info, m, n);
                        sdl_render_life(&sdl_info, world);
                        switch (edge){
                                /*only renders one array
                                 * in each calculation function a dumby array is passed in, the main array is copied to the dumby, the dumby is altered based on the main, and then the contense of the dumby is copied back to main. A lot more sensible in this case than alternating between two different martricies*/
                                case 0:
                                        life(world, hell, rows, cols);
                                        break;
                                case 1:
                                        torus(world, hell, rows, cols);
                                        break;
                                case 2:
                                        klein(world, hell, rows, cols);
                                        break;
                                default:
                                        printf("critical error: self destrcut sequence initiated.\n");
                        }
                 }

                 /* Poll for events, and handle the ones we care about. 
                  * You can click the X button to close the window
                  */
		SDL_Event event;
		while (SDL_PollEvent(&event)) 
		{
			switch (event.type) 
			{
			case SDL_KEYDOWN:
				break;
			case SDL_KEYUP:
                        /* If escape is pressed, return (and thus, quit) */
				if (event.key.keysym.sym == SDLK_ESCAPE)
					return 0;
				break;
			case SDL_QUIT:
                                kill_with_fire(world, rows, cols);
                                kill_with_fire(hell, rows, cols);
                                return(0);
			}
		}
	}
	return 0;
}
