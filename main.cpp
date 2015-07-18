/*
	
	Fire_Esgaea 0.0.1
	
			By:
	   	  Revi09
	   	  
	   	  This is a shitty game i'm going to try to make. neat.
	
*/

#include <SDL.h>
#include <SDL_Image.h>
#include <SDL_ttf.h>
#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <algorithm>  
#include <sstream>
#include <windows.h>
#include "SDL_image.h"
#include "SDL_INIT.h"
#include "Rendering.h"
#include "Charloader.h"
#include "Levelloader.h"
#include "ConsoleCM.h"
#include "KeyEvents.h"

int main(int argc, char *argv[])
{
	output("Loading ...",2);

	INIT_EVERYTHING();
	
	NPC NPC0;
	
	
	NPC0.INIT_loadNPCdata();
	NPC0.INIT_loadmap("normal","");
	//NPC0.INIT_loadmap("Override","DATA/BUTT.txt"); //just for testing This file is no longer here.
	
	//for frame rate.
	const int FPS=60;
	Uint32 FPS_A;
	


	

	output("Loaded.",2);
	while(!Exit)
	{
		FPS_A = SDL_GetTicks(); //Frame rate code most be on top
		
		Key_Presses();

		Draw_Things();
		
		
		
		// if frame rate its over it will delay the game. must be at the end of the loop or else it will not be correct.
		if(1000/FPS > SDL_GetTicks() - FPS_A)
			SDL_Delay(1000/FPS - (SDL_GetTicks() - FPS_A));
	}
	
		SDL_DestroyTexture (Tex0);
		SDL_DestroyRenderer(Ren0);
		SDL_DestroyWindow  (Win0);
		IMG_Quit();
	return 0;
}
