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
#include "GUI.h"
#include "ConsoleCM.h"
#include "KeyEvents.h"

int main(int argc, char *argv[])
{
	output("Loading ...",2);

	INIT_EVERYTHING();
	
	NPC NPC0;
	//GUI GUI0;
	
	
	NPC0.INIT_loadNPCdata();
	NPC0.INIT_loadmap("normal","");
	//Loadlevel("","");//temp
    GUI0->Selector_CONT();
    GUI0->HUD_Dispay();
    GUI0->Text_test();
    GUI0->UI_textINIT();
    //TESTING HARDDDDDDDD REMOVE WHEN TREE IS FINISHED
    GUI0->Get_Object_UI_Tree(LLd);
    //GUI0->Get_object_UI(LLd,"","",3); // temp for testing 
    //GUI0->OBJ_GUI_TEXT_SEL(3,0); // temp for testing
   // GUI0->OBJ_GUI_TEXT_SEL(4,0); // temp for testing
    ////////////////////////////////////////////////
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
		//SDL_DestroyTexture(MAPT0);
		//SDL_DestroyTexture(MAPT0);
		SDL_DestroyTexture (Tex0);
		SDL_DestroyRenderer(Ren0);
		SDL_DestroyWindow  (Win0);
		IMG_Quit();
	return 0;
}
