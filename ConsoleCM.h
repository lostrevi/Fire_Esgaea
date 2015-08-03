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
	OUTPUT = "changeobj - change the string of an object for testing";	
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
	if(INPUT == "changeobj")
	{
		OUTPUT = "changeobj - change the string of objects";
		output(OUTPUT,0);
		OUTPUT = "##########################################";
		output(OUTPUT,0);
		int a,b,c;
		output("Enter which stat you want to change 0-17 : ",9);
		std::cin >> a;
		std::cout << std::endl;
		output("Enter which Index of the object is 0-499 : ",9);
		std::cin >> b;
		std::cout << std::endl;
		output("Enter which SID of the object is 0-254 : ",9);
		std::cin >> c;
		std::cout << std::endl;
		std::string  TEMP = "";
		output("Enter what you want the string to be : ",9);
		std::cin >> TEMP;
		std::cout << std::endl;
		GUI0->Object_array[a][b][c] = TEMP;
		output("DONE!",0);
		
		OUTPUT = "";	
	}
	
}








#endif
