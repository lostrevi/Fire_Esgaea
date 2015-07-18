#ifndef RENDERING_H
#define RENDERING_H

#include "Levelloader.h"

void Draw_Background()
{
	SDL_SetRenderDrawColor( Ren0, 255, 0, 255, 255);
	SDL_RenderClear(Ren0);
}
//test/////////
loadlevel TEST;
//test/////////
void Draw_Things()
{

	
	 Draw_Background();
	 
	 
	 ///test///
	 Drawshit();
	 TEST.drawtest();
	 ///test///
	 
	 
	 
	 //////////////////
	 SDL_RenderPresent(Ren0);
	 
}


#endif
