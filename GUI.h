#ifndef GUI_H
#define GUI_H

/*
		SDL_Surface  *GUIS0 = NULL;
	    SDL_Texture  *GUIT0 = NULL;

	    
	    SDL_Rect CropX; // this for the cropted tile you want to draw
		SDL_Rect LocX; // This is the tile location after it has been croped.
		

		int SL_X = 0, SL_Y = 0;

	
	void Selector_CONT()
	{

		GUIS0 = IMG_Load("Data/UI/Selx_ENT.bmp");
		GUIT0 = SDL_CreateTextureFromSurface(Ren0,GUIS0); 
	    SDL_FreeSurface(GUIS0);

		SDL_QueryTexture(GUIT0,NULL,NULL,&CropX.w, &CropX.w);
		
		LocX.x = CropX.x = 0;
		LocX.y = CropX.y = 0;
		LocX.w = CropX.w = 80;
		LocX.h = CropX.h = 16;
		
		

	}	
	void Draw_CONT()
	{
		SDL_RenderCopy(Ren0,GUIT0, &CropX,&LocX);
				
	}
*/

class GUI // make sure your drawing the same object you stupid fuck oh my god i that was a huge fucking wast of time I need to use the same object for this or else it will INIT in one but it will draw one that's not INTIED.
{
		SDL_Surface  *GUIS0 = NULL;
	    SDL_Texture  *GUIT0 = NULL;

	    
	    SDL_Rect CropX; // this for the cropted tile you want to draw
		SDL_Rect LocX; // This is the tile location after it has been croped.
		
	public:
		int SL_X = 0, SL_Y = 0;

	
	void Selector_CONT()
	{

		GUIS0 = IMG_Load("Data/UI/Selx_ENT.bmp");
		std::cout << SDL_GetError();
		GUIT0 = SDL_CreateTextureFromSurface(Ren0,GUIS0); 
	    SDL_FreeSurface(GUIS0);

		SDL_QueryTexture(GUIT0,NULL,NULL,&CropX.w, &CropX.w);
		
		LocX.x = CropX.x = 0;
		LocX.y = CropX.y = 0;
		LocX.w = CropX.w = 16;
		LocX.h = CropX.h = 16;
		
		LocX.x = 32;
		LocX.y = 32;
		
		

	}	
	void Draw_CONT()
	{
		CropX.x = 16 * int(((SDL_GetTicks() / 100) % 5)); // animate
		
		SDL_RenderCopy(Ren0,GUIT0, &CropX,&LocX); // draw to render
	}
	
	void MovSLT(int a)
	{
		// this is for single movment only
		// 0 - none
		// 1 - up
		// 2 - down
		// 3 - right
		// 4 - left
		// 10 - swtich select mode
		
		if(a == 0)
		{
			a = 0;
		}
		else if(a == 1 && LocX.y != 0)
		{
			LocX.y -= 16;
			a = 0;
		}
		else if (a == 2 && LocX.y != 480-16)
		{
			LocX.y += 16;
			a = 0;
		}
		else if (a == 3 && LocX.x != 640 - 16)
		{
			LocX.x += 16;
			a = 0;
		}
		else if (a == 4 && LocX.x != 0)
		{
			LocX.x -= 16;
			a = 0;
		}
		else if (a == 10) //change to starting a funtion with bring up the seletion GUI ent.
		{
			if(CropX.y == 0)
			CropX.y = 16;
			else if(CropX.y == 16)
			CropX.y = 0;
		}
		else
		{
		}
		
		
	}
};






#endif
