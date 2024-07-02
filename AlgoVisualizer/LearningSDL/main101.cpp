#include <iostream>
#include <algorithm>
#include <vector>
#include <string>


#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>

/* Executed in this order (only) , should define SDL_MAIN_HANDLED in here before including sdl
> g++ .\main101.cpp -o main101.exe -lmingw32 -lSDL2main -lSDL2 ; .\main101.exe
out put : ALL OK
*/

using namespace std;

int main()
{
    (SDL_Init(SDL_INIT_VIDEO) < 0) ? cout << "ERROR in importing SDL" : cout << "SDL working fine";

    return 0;
}