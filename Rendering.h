#ifndef RENDERING_H
#define RENDERING_H

#include "Levelloader.h"
#include "GUI.h"

void Draw_Background()
{
	SDL_SetRenderDrawColor( Ren0, 255, 0, 255, 255);
	SDL_RenderClear(Ren0);
}
//test/////////
loadlevel LLd;
GUI GUI0;
//test/////////
void Draw_Things()
{

	
	 Draw_Background();
	 

	 ///test///
	 
	 //Drawshit();
	 LLd.drawtest();
	 GUI0.Draw_CONT();
	 ///test///



	 
	 //////////////////
	 
	 SDL_RenderPresent(Ren0);

	 
}


#endif
