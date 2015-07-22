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
		
		SDL_Texture *GUI_OBJ;
		SDL_Rect GUI_OBJ_icon;
		
	public:
		int SL_X = 0, SL_Y = 0;
		int TextData[5][20]; // the first is for loct.x, loct.y, loct.w, loct.h, other. and the 2nd array is per text.
		std::string Text_array[20]; // this is for TextData array it is what to put into the string before setting it up far draw.
		std::string Object_array[17][500][250]; // the first holds all 16 base stats from a file on ombject layer and the 2nd will be object id 
		int Object_Stat_array[17][500][250][2]; // same as the string but th 4th is for total and ative
		bool softhudup = false;
		
		bool levelupforcer = false;
		
	
	void Object_looker(loadlevel *LLD)// looks if the curser is over an object
	{
		//for(int j = 20< ) // this will need to be worked on after i get the SIDS setup for the objects and i'll need to add 20/20 and sucks with dynimic ints to test that it works.
		if(LLD->ONSCREEN_MAPARRAY[LocX.x/16][LocX.y/16][1] == 3)
		{
			int SIDO = OBJ_SID_FINDER(LLD,1,3); // the 1 is for layer and the 3 is for object witch will need to be changed.
						//TESTING//
						if(levelupforcer)
						{
							Object_Stat_array[3][3][SIDO][0] ++;
							levelupforcer = false;
						}
						///////////
			
			OBJ_GUI_TEXT_SEL(3,SIDO);
			softhudup = true;
			

			
		}
		else if(LLD->ONSCREEN_MAPARRAY[LocX.x/16][LocX.y/16][1] != 3)
		{
			softhudup = false;
		}
	}
		
	void Get_object_UI(loadlevel *LLDa,std::string Path,std::string Name,int ID) //ID is for the object type and SID is for eatch one of that type.
	{
		//testing by having this load strate into one object Rock0 so this will be more dynimc sooonnnn i'm sleepyyyyyyy
		enum OSTATE { OID, icon, OName, LV, HP, SP, ATK, DEF, INT, Res, Spd, HIT, Mov, Txp, Next, CTH, SIDE};
		
		OSTATE State;
		
		std::string Output;
		std::ifstream OBJ_FILE("Data/Objects/Rock0/Rock0.txt");// this will be Path.c_str() after testing is done and will be used in another funtion that can load all of them into strings. but for now it will be loading Rock0 for testing.
		
		if(OBJ_FILE.is_open())
		{
			
			std::string line, value;
			if(line.empty())
			int space;
			
			
			while(!OBJ_FILE.eof())
			{
				std::getline(OBJ_FILE, line);
				
				if(line.find("[ID]") != std::string::npos)
				{
					State = OID;
					continue;
				}
				if(line.find("[icon]") != std::string::npos)
				{
					State = icon;
					continue;
				}
				if(line.find("[Name]") != std::string::npos)
				{
					State = OName;
					continue;
				}
				if(line.find("[LVshouldb1]") != std::string::npos)
				{
					State = LV;
					continue;
				}
				if(line.find("[HP]") != std::string::npos)
				{
					State = HP;
					continue;
				}
				if(line.find("[SP]") != std::string::npos)
				{
					State = SP;
					continue;
				}
				if(line.find("[ATK]") != std::string::npos)
				{
					State = ATK;
					continue;
				}
				if(line.find("[DEF]") != std::string::npos)
				{
					State = DEF;
					continue;
				}
				if(line.find("[INT]") != std::string::npos)
				{
					State = INT;
					continue;
				}
				if(line.find("[Res]") != std::string::npos)
				{
					State = Res;
					continue;
				}
				if(line.find("[Spd]") != std::string::npos)
				{
					State = Spd;
					continue;
				}
				if(line.find("[HIT]") != std::string::npos)
				{
					State = HIT;
					continue;
				}
				if(line.find("[Mov]") != std::string::npos)
				{
					State = Mov;
					continue;
				}
				if(line.find("[Txp]") != std::string::npos)
				{
					State = Txp;
					continue;
				}
				if(line.find("[Next]") != std::string::npos)
				{
					State = Next;
					continue;
				}
				if(line.find("[CTH]") != std::string::npos)
				{
					State = CTH;
					continue;
				}
				if(line.find("[SIDE]") != std::string::npos)
				{
					State = SIDE;
					continue;
				}
				//////////STATE SWTICH!!!!!! ///////////////
				
				switch(State)
				{
					case OID:
					{
						Object_array[0][ID][0] = line;
						Object_Stat_array[0][ID][0][0] = atoi(line.c_str());
						break;
					} 
					
					case icon:
					{
						Object_array[1][ID][0] = line;
						//Object_Stat_array[0][ID][0] = atoi(line.c_str());
						break;
					} 
					
					case OName:
					{
						Object_array[2][ID][0] = line;
						//Object_Stat_array[0][ID][0] = atoi(line.c_str());
						break;
					} 
					
					case LV:
					{
						Object_array[3][ID][0] = line;
						Object_Stat_array[3][ID][0][0] = atoi(line.c_str());
						break;
					} 
					
					case HP:
					{
						Object_array[4][ID][0] = line;
						Object_Stat_array[4][ID][0][0] = atoi(line.c_str());
						Object_Stat_array[4][ID][0][1] = atoi(line.c_str());
						break;
					}
					
					case SP:
					{
						Object_array[5][ID][0] = line;
						Object_Stat_array[5][ID][0][0] = atoi(line.c_str());
						Object_Stat_array[5][ID][0][1] = atoi(line.c_str());
						break;
					} 
					
					case ATK:
					{
						Object_array[6][ID][0] = line;
						Object_Stat_array[6][ID][0][0] = atoi(line.c_str());
						break;
					} 
					
					case DEF:
					{
						Object_array[7][ID][0] = line;
						Object_Stat_array[7][ID][0][0] = atoi(line.c_str());
						break;
					} 
					
					case INT:
					{
						Object_array[8][ID][0] = line;
						Object_Stat_array[8][ID][0][0] = atoi(line.c_str());
						break;
					} 
					
					case Res:
					{
						Object_array[9][ID][0] = line;
						Object_Stat_array[9][ID][0][0] = atoi(line.c_str());
						break;
					} 
					
					case Spd:
					{
						Object_array[10][ID][0] = line;
						Object_Stat_array[10][ID][0][0] = atoi(line.c_str());
						break;
					} 
					
					case HIT:
					{
						Object_array[11][ID][0] = line;
						Object_Stat_array[11][ID][0][0] = atoi(line.c_str());
						break;
					} 
					
					case Mov:
					{
						Object_array[12][ID][0] = line;
						Object_Stat_array[12][ID][0][0] = atoi(line.c_str());
						break;
					} 
					
					case Txp:
					{
						Object_array[13][ID][0] = line;
						Object_Stat_array[13][ID][0][0] = atoi(line.c_str());
						break;
					} 
					
					case Next:
					{
						Object_array[14][ID][0] = line;
						Object_Stat_array[14][ID][0][0] = atoi(line.c_str());
						break;
					} 
					
					case CTH:
					{
						Object_array[15][ID][0] = line;
						Object_Stat_array[15][ID][0][0] = atoi(line.c_str());
						break;
					} 
					
					case SIDE:
					{
						Object_array[16][ID][0] = line;
						//Object_Stat_array[16][ID][0] = atoi(line.c_str());
						break;
					} 
					
				}
				
				
			}
			OBJ_FILE.close();
		}
		
		OBJ_SID_Setter(LLDa,1,ID); // nice
		
	}
	void OBJ_SID_Setter(loadlevel *LLD,int layer,int IndexOBJ) // this is for one object at the moment it should be for all after i get this peice working.
	{
		layer = 1; // this is object layer.
		int SID = 0;
		
		for(int j = 0; j < 500; j++)
		{
			for(int i = 0; i < 500; i++)
			{
				if(LLD->REAL_MAPARRAY[i][j][layer] == IndexOBJ)
				{
					if(SID != 0)
					{
					std::string Temp_array[17][1][1];
					for(int F = 0; F < 17; F++) // takes from base file and turns into shit.
					{
						Temp_array[F][0][0] = Object_array[F][IndexOBJ][0];
					}
					
					for(int G = 0; G < 17; G++)
					{
					Object_array[G][IndexOBJ][SID] = Temp_array[G][0][0];
					
						if(G == 4)
						{
							Object_Stat_array[G][IndexOBJ][SID][0] = atoi(Temp_array[G][0][0].c_str());
							Object_Stat_array[G][IndexOBJ][SID][1] = atoi(Temp_array[G][0][0].c_str());
							
						}
						else if(G == 5)
						{
							Object_Stat_array[G][IndexOBJ][SID][0] = atoi(Temp_array[G][0][0].c_str());
							Object_Stat_array[G][IndexOBJ][SID][1] = atoi(Temp_array[G][0][0].c_str());
							
						}
						else 
						{
						Object_Stat_array[G][IndexOBJ][SID][0] = atoi(Temp_array[G][0][0].c_str());
						}
						
					}
					
					}
				 SID++;
				 //output("A OBJ SID WAS SET!",0);
				
				}
				
			}
		}
		
	}
	
	int OBJ_SID_FINDER(loadlevel *LLD,int layer,int IndexOBJ)
	{
		layer = 1; // 1 is the object layer
		IndexOBJ = 3; // this is for testing.
		//LocX
		//if(LLD->REAL_MAPARRAY[LocX.x/16][LocX.y/16][layer])

		int idcounter = 0;
		for(int j = 0; j < 1+((LocX.y/16)+(LLD->Yoff));j++)
		{
			if(j == ((LocX.y/16) + LLD->Yoff))
			{
			for(int i = 0; i < 1+(LocX.x/16)+(LLD->Xoff);i++)
			{
				if(LLD->REAL_MAPARRAY[i][j][layer] == IndexOBJ)
				{
					idcounter++;
				}
			}
			}
			else
			{
			
			for(int i = 0; i < 500;i++)
			{
				if(LLD->REAL_MAPARRAY[i][j][layer] == IndexOBJ)
				{
					idcounter++;
				}
			}
			}
			
		}

		
		return idcounter-1;
		
		
		
		
		for(int j = 0; j < 500; j++)
		{
			for(int i = 0; i < 500; i++)
			{
				for(int SIDF = 0; SIDF < 500; SIDF++)
				{
				
					if(LLD->REAL_MAPARRAY[i][j][layer] == IndexOBJ)
					{
					
					
					}
				}
			}
		}
		
		
	}
	
	void Level_CHECK(int IndexOBJ, int SID, int LEVEL)//checks level;
	{
		// NEED TO ADD CLASS!!!!!!!!!!!!!!!!!!!!!!!!!!!! WITH SP LEVEING !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		int HLVC = atoi(Object_array[4][IndexOBJ][SID].c_str()); // checking HP to see if it has leved
		int HRL = Object_Stat_array[4][IndexOBJ][SID][0]; //checking HP
		int LV = Object_Stat_array[3][IndexOBJ][SID][0]; //get lv;
		if(HRL != (HLVC*LV))
		{
		
		//	for(int A = 0; A < LEVEL+1;A++)
		//	{
		int ST5 = atoi(Object_array[5][IndexOBJ][SID].c_str());
		int ST6 = atoi(Object_array[6][IndexOBJ][SID].c_str());
		int ST7 = atoi(Object_array[7][IndexOBJ][SID].c_str());
		int ST8 = atoi(Object_array[8][IndexOBJ][SID].c_str());
		int ST9 = atoi(Object_array[9][IndexOBJ][SID].c_str());
		int ST10 = atoi(Object_array[10][IndexOBJ][SID].c_str());
		int ST11 = atoi(Object_array[11][IndexOBJ][SID].c_str());
		
			int lv = Object_Stat_array[3][IndexOBJ][SID][0]; //get lv;
		
			Object_Stat_array[4][IndexOBJ][SID][0]= HLVC * LV; // HP                NOT FINAL for the incress in any of theses
			Object_Stat_array[4][IndexOBJ][SID][1]= HLVC * lv;
			
			Object_Stat_array[5][IndexOBJ][SID][0]= ST5 * (lv); // SP
			Object_Stat_array[5][IndexOBJ][SID][1]= ST5 * (lv); // SP
			
			Object_Stat_array[6][IndexOBJ][SID][0] = ST6 * (lv) ;//ATK
			Object_Stat_array[7][IndexOBJ][SID][0] = ST7 * (lv);//DEF
			Object_Stat_array[8][IndexOBJ][SID][0] = ST8 * (lv);//INT
			Object_Stat_array[9][IndexOBJ][SID][0] = ST9 * lv;//Res
			Object_Stat_array[10][IndexOBJ][SID][0] = ST10 * (lv);//Spd
			Object_Stat_array[11][IndexOBJ][SID][0] = ST11 * (lv);//HIT
		//	}
		}
	}
	
	void OBJ_GUI_TEXT_SEL(int IndexOBJ, int SID) // put the values in the gui It will need to put them as an int array to so they can be effected or somthing like that.
	{
		
		Level_CHECK(IndexOBJ,SID,Object_Stat_array[3][IndexOBJ][SID][0]);
		
		Text_array[0] = Object_array[2][IndexOBJ][SID];//name // could use a for loop but i'm not because these might change around so i'm keeping it this way for easyer editing.
		///////////////////////////////////////////////////////////////////////////
		Text_array[1] = std::to_string(Object_Stat_array[3][IndexOBJ][SID][0]);//LV
		
		//Text_array[2] = Object_array[4][IndexOBJ][SID];//HP
		std::string temp = std::to_string((Object_Stat_array[4][IndexOBJ][SID][1]) ); // HP ACTIVE   THIS WILL NEED A MATH CHECK WHEN IN LEVELING SYSTEM.
		std::string temp2 = std::to_string((Object_Stat_array[4][IndexOBJ][SID][0]) ); // HP TOTAL   ALL WILL NEED A VOID TO CHANGE THERE LEVELS AND SUCH.
		Text_array[2] = temp + " / " + temp2;
		
		//Text_array[3] = Object_array[5][IndexOBJ][SID];//SP
		temp = std::to_string((Object_Stat_array[5][IndexOBJ][SID][1]) ); // SP ACTIVE   
		temp2 = std::to_string((Object_Stat_array[5][IndexOBJ][SID][0]) ); // SP TOTAL   
		Text_array[3] = temp + " / " + temp2;
		
		Text_array[4] = std::to_string((Object_Stat_array[6][IndexOBJ][SID][0]) );//ATK
		Text_array[5] = std::to_string((Object_Stat_array[7][IndexOBJ][SID][0]) );//DEF
		Text_array[6] = std::to_string((Object_Stat_array[8][IndexOBJ][SID][0]) );//INT
		Text_array[7] = std::to_string((Object_Stat_array[9][IndexOBJ][SID][0]) );//Res
		Text_array[8] = std::to_string((Object_Stat_array[10][IndexOBJ][SID][0]) );//Spd
		Text_array[9] = std::to_string((Object_Stat_array[11][IndexOBJ][SID][0]) );//HIT
		Text_array[10] = std::to_string((Object_Stat_array[12][IndexOBJ][SID][0]) );//MOV
		Text_array[11] = std::to_string((Object_Stat_array[13][IndexOBJ][SID][0]) );//Txp
		Text_array[12] = std::to_string((Object_Stat_array[14][IndexOBJ][SID][0]) );//Next
		Text_array[13] = std::to_string((Object_Stat_array[15][IndexOBJ][SID][0]) );//CTH
		//////////////////////////////////////////////////////////////////////////////
		Text_array[16] = std::to_string(SID); //THE SID FOR TESTING
		
		Text_array[19] = Object_array[16][IndexOBJ][SID];//SIDE
		
		OBJ_UI_DRAW_SET(IndexOBJ,SID);
	}
	
	void OBJ_UI_DRAW_SET(int IndexOBJ,int SID)
	{
			SDL_Surface *TEMP_S;
			TEMP_S = IMG_Load(Object_array[1][IndexOBJ][SID].c_str());
			GUI_OBJ = SDL_CreateTextureFromSurface(Ren0,TEMP_S);
		    SDL_FreeSurface(TEMP_S);
			
			SDL_QueryTexture(GUI_OBJ, NULL, NULL, &GUI_OBJ_icon.w ,&GUI_OBJ_icon.h );
			
			GUI_OBJ_icon.x = 3;
			GUI_OBJ_icon.y = 351;
			GUI_OBJ_icon.w = 128;
			GUI_OBJ_icon.h = 128;
	}

	void UI_OVERLAY_1() // I'm going to move the draw for the text and such up here.
	{
			
			
			SDL_RenderCopy(Ren0,GUIT1, &Crop1,&Loc1); 
			UI_text_Draw();
			SOFT_UI_Backdrop(Text_array[19]);
			SDL_RenderCopy(Ren0,GUI_OBJ, NULL,&GUI_OBJ_icon);
			
	}
	void SOFT_UI_Backdrop(std::string fact)
	{
		std::string Path0;
			if(fact == "Blue")
			Path0 = "Data/UI/Factions/Blue.bmp";
			if(fact == "Object")
			Path0 = "Data/UI/Factions/Object.bmp";
			
			
			SDL_Surface *TEMP_S;
			SDL_Texture *Backdrop;
			TEMP_S = IMG_Load(Path0.c_str());
			Backdrop = SDL_CreateTextureFromSurface(Ren0,TEMP_S);
		    SDL_FreeSurface(TEMP_S);
		    
		    SDL_QueryTexture(Backdrop, NULL, NULL, &GUI_OBJ_icon.w ,&GUI_OBJ_icon.h );
		    
		    SDL_RenderCopy(Ren0,Backdrop,NULL,&GUI_OBJ_icon);
		    SDL_DestroyTexture (Backdrop);
	}
	
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
		Tcolor0.r=255;Tcolor0.g=255;Tcolor0.b=255;Tcolor0.a=255;
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
			TextData[0][i] = 155+32+128;//x
			TextData[1][i] = 366+((i-6)*16);//y
			TextData[2][i] = 80;//xc
			TextData[3][i] = 13;//xc
		}
		for(int i = 13; i < 19; i++)
		{
			TextData[0][i] = 155+32+128+128;//x
			TextData[1][i] = 366+((i-12)*16);//y
			TextData[2][i] = 80;//xc
			TextData[3][i] = 13;//xc
		}
			TextData[0][19] = 155+32+128+128+128;//x
			TextData[1][19] = 366+16;//y
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
		
			if(!softhudup)
			CropX.y = 0;
			else if(softhudup)
			CropX.y = 16;
	
		CropX.x = 16 * int(((SDL_GetTicks() / 100) % 5)); // animate
		
		SDL_RenderCopy(Ren0,GUIT0, &CropX,&LocX); // draw to render
		
		//if(HudUP)
		
		
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
			if(softhudup)
			softhudup=false;
			else if(!softhudup)
			softhudup=true;
			
		}
		else
		{
		}
		
		
	}
};






#endif
