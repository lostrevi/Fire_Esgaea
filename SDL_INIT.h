#ifndef SDL_INIT_H
#define SDL_INIT_H
bool INIT_SUBSYSTEMS();
bool INIT_WINDOW();
bool INIT_RENDERER();

	///////////////////
	SDL_Window   *Win0;
	SDL_Renderer *Ren0;
	SDL_Surface  *Sur0;
	SDL_Texture  *Tex0;
	SDL_Event     Eve0;
	
	bool Exit = false;
	///////////////////


// starts all of SDL's subsystems
bool INIT_SUBSYSTEMS()
{

	
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
}
// Creates our window win0
bool INIT_WINDOW()
{
	Win0 = SDL_CreateWindow("BASS INVADERS", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
	if(Win0 == NULL){
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
	} 
}
// Makes our renders Ren0
bool INIT_RENDERER()
{
	Ren0 = SDL_CreateRenderer(Win0, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (Ren0 == NULL){
		SDL_DestroyWindow(Win0);
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		SDL_Quit();
		return 1;
		
		if ((IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG) != IMG_INIT_PNG)
			{
			std::cout << "SDL_PNG Error: " << SDL_GetError() << std::endl;
			SDL_Quit();
			return 1;
			}
	}
}
// runs all these from this one funtion();
void INIT_EVERYTHING()
{

	INIT_SUBSYSTEMS();
	INIT_WINDOW();
	INIT_RENDERER();
}



#endif

