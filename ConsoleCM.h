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
	output(OUTPUT,11);
	OUTPUT = "#################################";
	output(OUTPUT,11);
	OUTPUT = "Help - This command";	
	output(OUTPUT,11);
	
	
	

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
