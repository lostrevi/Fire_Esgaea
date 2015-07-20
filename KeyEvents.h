#ifndef KEYEVENTS_H
#define KEYEVENTS_H



void Key_Presses()
{
	SDL_PumpEvents(); 
	
	const Uint8 * keys = SDL_GetKeyboardState(NULL);
	
	//single hit keys, mouse and other SDL events.
	while(SDL_PollEvent(&Eve0))
	{
		switch (Eve0.type)
		{
			case SDL_MOUSEMOTION:
				break;
				
			case SDL_QUIT:
				Exit = true;
				break;
				case SDL_KEYDOWN:
					switch (Eve0.key.keysym.sym)
				{
					// key events that arn't contious-response can be put here.
           				 case SDLK_ESCAPE: SDL_Quit; Exit = true; break;
           				 case SDLK_RCTRL: CCM(); break;
           				 case SDLK_UP: GUI0->MovSLT(1,LLd); break;
           				 case SDLK_DOWN: GUI0->MovSLT(2,LLd); break;
           				 case SDLK_RIGHT: GUI0->MovSLT(3,LLd); break;
           				 case SDLK_LEFT: GUI0->MovSLT(4,LLd); break;
           				 case SDLK_1: GUI0->MovSLT(10,LLd); break; //DEBUG
           				 case SDLK_w: LLd->LevelShifter(1); break; //DEBUG
           				 case SDLK_s: LLd->LevelShifter(2); break; //DEBUG
           				 case SDLK_d: LLd->LevelShifter(3); break; //DEBUG
           				 case SDLK_a: LLd->LevelShifter(4); break; //DEBUG
           				 

            		
				    default: break;
				}
				break;
		}
	}
	
}





#endif
