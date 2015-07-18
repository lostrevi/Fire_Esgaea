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

            		
				    default: break;
				}
				break;
		}
	}
	
}





#endif
