#ifndef LEVELLOADER_H
#define LEVELLOADER_H
// make a class so shit don't get foked
// this is temp.
	SDL_Rect test; //testing
	SDL_Rect m_destinationRectangle; // testing

void Loadlevel(std::string level,std::string asset)
{

	
	Sur0 = SDL_LoadBMP("DATA/MAP/Assets/Map_Assets-temp.bmp"); // default
	Tex0 = SDL_CreateTextureFromSurface(Ren0,Sur0); //testing
	SDL_FreeSurface(Sur0); // mostlikey defualt pretty sure this just clears the sdl surface.
	
	SDL_QueryTexture(Tex0,NULL,NULL,&test.w, &test.h); // testing
	
	m_destinationRectangle.x = test.x = 0;//test
	m_destinationRectangle.y = test.y = 0;//test
	m_destinationRectangle.w = test.w = 640;// test dis is crop for x
	m_destinationRectangle.h = test.h = 480; //test dist is crop for y
	
	
	
}

void Drawshit()
{
	SDL_RenderCopy(Ren0, Tex0, &test, &m_destinationRectangle);
}


#endif
