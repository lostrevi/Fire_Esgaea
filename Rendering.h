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
loadlevel *LLd = new loadlevel;
GUI *GUI0 = new GUI;
//test/////////
void Draw_Things()
{
	
	//checkers// might make ther own funtion and put it in main
	GUI0->Object_looker(LLd);
	//checkers//	
	 Draw_Background();
	 

	 ///test///
	 
	 //Drawshit();
	 //LLd.drawtest();
	 LLd->drawmap0();
	 GUI0->Draw_CONT();
	 if(GUI0->softhudup)
	 GUI0->UI_OVERLAY_1();
	 ///test///



	 
	 //////////////////
	 
	 SDL_RenderPresent(Ren0);

	 
}


#endif
