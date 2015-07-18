#ifndef LEVELLOADER_H
#define LEVELLOADER_H
// make a class so shit don't get foked
// this is temp.
	SDL_Rect test; //testing
	SDL_Rect m_destinationRectangle; // testing
	
	

class loadlevel
{


	const int tX = 16, tY = 16;
	SDL_Rect CropT; // this for the cropted tile you want to draw
	SDL_Rect LocT; // This is the tile location after it has been croped.
			int j = 0; // i fucking hate that this has to be up here bacuase it keeps fucking everthing up.
	//SDL_Renderer *MAPR0; // might not need
	SDL_Surface  *MAPS0;
	SDL_Texture  *MAPT0;

	public: 
		int ACT_MAPARRAY [40] [30];
	
	void LoadLevel() //this is load level default.
	{
	
		enum STATE { SIZE, MAP0};
		
		STATE state;
		
		std::string Output;
		std::ifstream Leveldata ("Data/MAP/Levels/Default.txt");// loading default level. ... which is Data/Map/Levels/Default.txt
		
		if(Leveldata.is_open())
		{
			//while (getline (Leveldata , Output))
		   	//{
			//	output(Output,0);
			//}
			
					std::string line, value;
					if(line.empty())
					int space;
			
			
			while(!Leveldata.eof())
			{
				std::getline(Leveldata, line);
				
				//line.erase(std::remove(line.begin(), line.end(), '#'), line.end());
				
				if(line.find("[map size]") != std::string::npos)
				{
					state = SIZE;	
					continue;
					//std::stringstream str(line);
		
				/*	while(!str.eof())
					{
						
						std::getline(str, value, ' ');
						
						Output = value;
						output(Output,0);
						
					}*/
					//break;
				}
				

				
				if(line.find("[maplocdata]") != std::string::npos)
				{
					state = MAP0;
					
									//std::string s = std::to_string(ACT_MAPARRAY[0][0]);
									//Output = s;
									//output(Output,1);
					
					continue;
						
					
				}
				
				int i = 0; //check
				
				switch(state)
				{
					case SIZE:
						output("THE SIZE STATE IS WORKING!",0); break;
					case MAP0:
						{
								std::stringstream str(line);
								
									while(!str.eof())
									{
						
										std::getline(str, value, ' ');
										
										if(value.length() > 0)
										{
											//std::cout << j <<std::endl;
										
											std::istringstream buffer(value);
											int TEMP;
											buffer >> TEMP;
											
											if(ACT_MAPARRAY[i][j] != 0)
											output("ERROR",1);
											ACT_MAPARRAY[i][j] = TEMP;

										
											//std::stringstream ss;
											//ss << ACT_MAPARRAY[i][j];
											//std::string TESTTEMP = ss.str();
										
											//Output = TESTTEMP;
											//output(Output,0);
											
											i++;

										}
									}

									//std::string s = std::to_string(ACT_MAPARRAY[0][1]);
									//Output = s;
									//output(Output,1);
									
									
									j++;
									
									

						}
						
				}
				
				
				
				
				
				/*
				std::stringstream str(line);
		
					while(!str.eof())
					{
						
						std::getline(str, value, ' ');
						
						Output = value;
						output(Output,0);
						
					}
				*/
				
				
				
				//temp
			//	Output = line;
			//	output(line,0);
				
				
				
				
				
				
			}
			
			
			Leveldata.close();
		}
		else
		{
			Output = "failed to load the Data/MAP/Levels/Default.txt";
			output(Output,1);
		}
		
		
		MAPS0 = IMG_Load("Data/Map/Assets/Map_Assets-temp.bmp"); // default
		MAPT0 = SDL_CreateTextureFromSurface(Ren0,MAPS0);
		SDL_FreeSurface(MAPS0);
			
		SDL_QueryTexture(MAPT0,NULL,NULL,&CropT.w,&CropT.h);
		
			LocT.x = CropT.x = 0;
			LocT.y = CropT.y = 0;
			LocT.w = CropT.w = 16;
			LocT.h = CropT.h = 16;

	
	}
	
	void drawtest()
	{
		
		for(int y = 0; y < 30; y++)
		{
			for(int x =0; x < 40;x++)
			{
				int Index = ACT_MAPARRAY[x][y];
				
				double TileRow = floor(Index/25);
				int TileCol = Index % 25;
				
				CropT.x = TileCol * 16;
				CropT.y = TileRow * 16;
				LocT.y = 16 * y;
				LocT.x = 16 * x;
				
				SDL_RenderCopy(Ren0,MAPT0, &CropT,&LocT);
			}
		}
		
		
		
		
		/*
			for(int i = 0; i < 25; i++)//test
		{


			CropT.x = tX * i;
			LocT.x = tX *i;
			LocT.y = tY *i;
			
			SDL_RenderCopy(Ren0,MAPT0, &CropT,&LocT);

			SDL_TEXTUREACCESS_STREAMING; // might need to get rid of this line?
			


			
		}
		*/	
	}
	
};

void Loadlevel(std::string level,std::string asset)
{


	Sur0 = IMG_Load("Data/Map/Assets/Map_Assets-temp.bmp"); // default
	Tex0 = SDL_CreateTextureFromSurface(Ren0,Sur0); //testing
	SDL_FreeSurface(Sur0); // mostlikey defualt pretty sure this just clears the sdl surface.
	

	
	SDL_QueryTexture(Tex0,NULL,NULL,&test.w, &test.h); // testing
	
	
	m_destinationRectangle.x = test.x = 0;//test
	m_destinationRectangle.y = test.y = 0;//test
	m_destinationRectangle.w = test.w = 16;// test dis is crop for x
	m_destinationRectangle.h = test.h = 16; //test dist is crop for y
	
	//m_destinationRectangle.x = 16;
	//test.x = 16*3;
	//test.y = 16;
	
	
	
}






void Drawshit()
{
	SDL_RenderCopy(Ren0, Tex0, &test, &m_destinationRectangle);
	//SDL_RenderCopy(Ren0, Tex0, &test , &test);
	
}


#endif
