#ifndef GUI_H
#define GUI_H



class GUI
{
	public:
		SDL_Surface  *GUIS0;
	    SDL_Texture  *GUIT0;
	    int SL_X = 0, SL_Y = 0;
	    
	    SDL_Rect CropX; // this for the cropted tile you want to draw
		SDL_Rect LocX; // This is the tile location after it has been croped.
		
	
	void Selector_CONT()
	{
		GUIS0 = IMG_Load("Data/Map/Assets/Map_Assets-temp.bmp");//("Data/UI/Selx_ENT.bmp");
		GUIT0 = SDL_CreateTextureFromSurface(Ren0,GUIS0); 
	    SDL_FreeSurface(GUIS0);
			
		SDL_QueryTexture(GUIT0,NULL,NULL,&CropX.w, &CropX.w);
		
		LocX.x = CropX.x = 0;
		LocX.y = CropX.y = 0;
		LocX.w = CropX.w = 640;
		LocX.h = CropX.h = 480;
		
		

	}	
	void Draw_CONT()
	{
		SDL_RenderCopy(Ren0,GUIT0, &CropX,&LocX);
				std::cout << " error: " << SDL_GetError() << std::endl;
	}
};






#endif
