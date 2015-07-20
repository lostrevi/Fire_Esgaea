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
	    
	    SDL_Surface  *GUIS1 = NULL;
	    SDL_Texture  *GUIT1 = NULL;

		bool HudUP = false;
	    
	    SDL_Rect CropX; // this for the cropted tile you want to draw
		SDL_Rect LocX; // This is the tile location after it has been croped.
		
		SDL_Rect Crop1;
		SDL_Rect Loc1;
		
		//text test
		TTF_Font *font = NULL;
		SDL_Surface *Message;
		SDL_Texture *textT;
		SDL_Rect textRect;
		SDL_Color textcolor;
		//text test
		TTF_Font *Font = NULL;
		SDL_Surface *message;
		SDL_Texture *text;
		SDL_Rect LocT;
		SDL_Color Tcolor0;
		
	public:
		int SL_X = 0, SL_Y = 0;
		int TextData[5][20]; // the first is for loct.x, loct.y, loct.w, loct.h, other. and the 2nd array is per text.
		std::string Text_array[20]; // this is for TextData array it is what to put into the string before setting it up far draw.
		
	void UI_textINIT()
	{
		//temp
		for(int j = 0; j < 20; j++)
		{
			for(int i = 0; i < 5; i++)
			{
				TextData[i][j] = 0;
			}
			Text_array[j] = "00000";
		}
		//temp
		Tcolor0.r=0;Tcolor0.g=0;Tcolor0.b=0;Tcolor0.a=255;
		Font = TTF_OpenFont("Data/Font.ttf",10);
		if(Font == NULL)
		output("Font.ttf has failed to load",1);
	}
	void UI_text_Draw()
	{
		TextData[0][0] = 14+32;//x
		TextData[1][0] = 332;//y
		TextData[2][0] = 128;//xc
		TextData[3][0] = 13;//xc
		
		TextData[0][1] = 155;//x
		TextData[1][1] = 366+32;//y
		TextData[2][1] = 80;//xc
		TextData[3][1] = 13;//xc
		
		for(int i = 1; i < 7; i++)
		{
			TextData[0][i] = 155+32;//x
			TextData[1][i] = 366+(i*16);//y
			TextData[2][i] = 80;//xc
			TextData[3][i] = 13;//xc
		}
		for(int i = 7; i < 13; i++)
		{
			TextData[0][i] = 155+32+96;//x
			TextData[1][i] = 366+((i-6)*16);//y
			TextData[2][i] = 80;//xc
			TextData[3][i] = 13;//xc
		}
		for(int i = 13; i < 19; i++)
		{
			TextData[0][i] = 155+32+96+96;//x
			TextData[1][i] = 366+((i-12)*16);//y
			TextData[2][i] = 80;//xc
			TextData[3][i] = 13;//xc
		}
			TextData[0][19] = 155+32+96+96+96;//x
			TextData[1][19] = 366+32;//y
			TextData[2][19] = 80;//xc
			TextData[3][19] = 13;//xc
			
		//add the rest with a for loop since the will be in less random locations
		
		for(int j = 0; j < 20; j++)
		{
			SDL_Texture *TEMP0;

				LocT.x = TextData[0][j];
				LocT.y = TextData[1][j];
				LocT.w = TextData[2][j];
				LocT.h = TextData[3][j];
			
			message = TTF_RenderText_Solid(Font, Text_array[j].c_str(),Tcolor0);
			TEMP0 = SDL_CreateTextureFromSurface(Ren0,message);
			SDL_FreeSurface(message);
			
			SDL_QueryTexture(TEMP0,NULL,NULL,&LocT.w,&LocT.h);
			
			SDL_RenderCopy(Ren0,TEMP0, NULL,&LocT);
			
			SDL_DestroyTexture (TEMP0);
			//text = NULL;
		}
	}
	

	void Text_test()
	{
		textcolor.r=255;textcolor.g=255;textcolor.b=255;textcolor.a=255;
		font = TTF_OpenFont("Data/Font.ttf",10);
		if(font == NULL)
		output("Font file failed to load!",1);
		
		Message = TTF_RenderText_Solid( font, "THIS IS TEST TEXT!", textcolor);
		textT = SDL_CreateTextureFromSurface(Ren0,Message);
		SDL_FreeSurface(Message);
		
		SDL_QueryTexture(textT,NULL,NULL,&textRect.w,&textRect.h);
		
		textRect.x=0;textRect.y=0;textRect.w=100;textRect.h=50;
		
	}
	
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
		
		if(HudUP)
		SDL_RenderCopy(Ren0,GUIT1, &Crop1,&Loc1); 
		
		//SDL_RenderCopy(Ren0,textT, NULL,&textRect);
		
	}
	
	void HUD_Dispay()
	{
		GUIS1 = IMG_Load("Data/UI/HUD_GUI.bmp");
		GUIT1 = SDL_CreateTextureFromSurface(Ren0,GUIS1);
		SDL_FreeSurface(GUIS1);
		
		SDL_QueryTexture(GUIT1,NULL,NULL, &Crop1.w,&Crop1.h);
		
		Loc1.x = Crop1.x = 0;
		Loc1.y = Crop1.y = 0;
		Loc1.w = Crop1.w = 640;
		Loc1.h = Crop1.h = 150;
		Loc1.y = 330;
	}
	
	void MovSLT(int a, loadlevel *lld)
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
		/////////// SHIFT THE MAP //////////////////
		else if(a == 1 && LocX.y == 0)
		{
			lld->LevelShifter(1);
			a = 0;
		}
		else if (a == 2 && LocX.y == 480-16)
		{
			lld->LevelShifter(2);
			a = 0;
		}
		else if (a == 3 && LocX.x == 640 - 16)
		{
			lld->LevelShifter(3);
			a = 0;
		}
		else if (a == 4 && LocX.x == 0)
		{
			lld->LevelShifter(4);
			a = 0;
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////
		else if (a == 10) //change to starting a funtion with bring up the seletion GUI ent.
		{
			if(CropX.y == 0)
			{
				CropX.y = 16;
				HudUP = true;
			}
			
			else if(CropX.y == 16)
			{
				CropX.y = 0;
				HudUP = false;
			}
			
		}
		else
		{
		}
		
		
	}
};






#endif
