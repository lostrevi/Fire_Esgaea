#ifndef CONSOLECM_H
#define CONSOLECM_H

void CCM()
{
	std::string OUTPUT = "";
	std::string INPUT = "";
	output("",9);
	
	std::cin >> INPUT;
	//Need to add commmands here
	
	
	
	////////////////////////COMMANDS//////////////////////////////////
	//
	// HELP - list all commands 
	//
	////////////////////////// LIST
	
	if(INPUT == "HELP" || INPUT == "Help" || INPUT == "help")
	{
	output("",10);
	OUTPUT = "Help - Lists all commands.";
	output(OUTPUT,0);
	OUTPUT = "#################################";
	output(OUTPUT,0);
	OUTPUT = "Help - This command";	
	output(OUTPUT,0);
	OUTPUT = "Loadlevel - Load a level just put the path and the asst(leave blank)";	
	output(OUTPUT,0);
	
	
	

	OUTPUT = "";
	}
	
	if(INPUT == "Loadlevel" || INPUT == "LOADLEVEL" || INPUT == "loadlevel")
	{
	std::string TEMP ,TEMP2;
	output("",10);
	OUTPUT = "Load level - loads level via command line";
	output(OUTPUT,0);
	OUTPUT = "#################################";
	output(OUTPUT,0);
	OUTPUT = "Enter Level Path : ";
	output(OUTPUT,9);
	std::cin >> TEMP;
	std::cout << std::endl;
	OUTPUT = "Enter asset(Level Blank)";
	output(OUTPUT,0);
	std::cin >> TEMP2;
	output("",10);
	LLd->LoadLevel(TEMP,TEMP);
	
	
	
	OUTPUT = "";
	}
	
	
	if(INPUT == "GETINFO")//this is a temp for seein mapdata in the load level calls.
	{
		loadlevel Acc;
		int a,b;
		std::cin >> a; 
		std::cin >> b;
		std::cout << std::endl <<std::endl;
		std::cout << "val is " << Acc.ACT_MAPARRAY[a][b];
	}
	
}






#endif
