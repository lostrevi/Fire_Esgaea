#ifndef CHARLOADER_H
#define CHARLOADER_H

#include <fstream>
#include <windows.h>

void output(std::string line, int num)
{
	// 0 - normal - WHITE
	// 1 - ERROR - RED ON BLUE 
	// 2 - GREAT! - GREEN
		HANDLE h= GetStdHandle( STD_OUTPUT_HANDLE );
		
	 	WORD wOldColorAttrs;
  		CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
  		
  		GetConsoleScreenBufferInfo(h, &csbiInfo);
 		wOldColorAttrs = csbiInfo.wAttributes;
  
	
	SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY);
	std::cout << "NPC> ";
	SetConsoleTextAttribute ( h, wOldColorAttrs);
	
	if(num == 1)
	{
		SetConsoleTextAttribute(h,FOREGROUND_RED | FOREGROUND_INTENSITY | BACKGROUND_BLUE);
		std::cout << line << std::endl;
		SetConsoleTextAttribute ( h, wOldColorAttrs);
	}
	else if(num == 2)
	{
		SetConsoleTextAttribute(h,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		std::cout << line << std::endl;
		SetConsoleTextAttribute ( h, wOldColorAttrs);
	}
	else
	std::cout << line << std::endl;
	
	
}

class NPC
{
	public:
		void INIT_loadNPCdata()
		{
		//this is just a quick test|| start
		std::string tempholder;
		std::ifstream NPCMaster ("DATA/NPC/NPC_tree.txt");
		
		if(NPCMaster.is_open())
		{
			while (getline (NPCMaster , tempholder))
			{
				output(tempholder,0);
			}
			NPCMaster.close();
		}
		else
		{
			tempholder = "Failed to load DATA/NPC/NPC_tree.txt. The Programe will shutdown.";
			output(tempholder,1);
			std::cin.ignore();
			SDL_Quit();
		}
		//this is just a quick test|| end	
		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////	
		void loadmap(std::string level)
		{
			//loads levels.
			//call funtion
		}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		void INIT_loadmap(std::string input, std::string input2)
		{
			std::string OUTPUT = "";
			//will add normal mode where it look for the tree of levels to findout with one to load.
			
			if(input == "Normal" || input ==  "normal")
			{
				OUTPUT = "INIT_loadmap is set to " + input + ".";
				output(OUTPUT,0);
				std::ifstream MAPMaster ("DATA/MAP/MAP_tree.txt");
				
				if(MAPMaster.is_open())
				{
					OUTPUT = "The file is here but this has yet to be programed.";
					output(OUTPUT,0);
				}
				else
				{
					OUTPUT = "MAP_tree.txt failed to load. Make sure the file is there. the file is at DATA/MAP/MAP_tree.txt";
					output(OUTPUT,1);
					//testing///////////////////////////////////////
					//std::cin.ignore();
					Loadlevel("","");
					//testing///////////////////////////////////////
					//will load the defualt map insted of exiting.
					OUTPUT = "Loading default (NOT SETUP YET)";
					output(OUTPUT,0);
					//SDL_Quit();
				}
			}
			else if(input == "Override" || input == "override")
			{
				// uesed for loading a level and not a the the level tree.
				OUTPUT = "INIT_loadmap is set to " + input + ".";
				output(OUTPUT,0);
				OUTPUT = "OverRiding to the selected level to " + input2;
				output(OUTPUT,0);
				std::ifstream MAPMaster (input2);
				if(MAPMaster.is_open())
				{
					OUTPUT = "The file is here but this has yet to be programed.";
					output(OUTPUT,0);
				}
				else
				{
					OUTPUT = "The level file " + input2 + " was not found. Make sure you enterd the path of the file correct.";
					output(OUTPUT,1);
					std::cin.ignore();
					//will load the defualt map insted of exiting.
					OUTPUT = "Loading default (NOT SETUP YET)";
					output(OUTPUT,0);
					//SDL_Quit();
					
				}
			}
		}
		
};



#endif
