#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <string>

int SPEED_DELAY = 1;

/*
g++ .\vis3.cpp -o vis3.exe -lmingw32 -lSDL2_ttf -lSDL2_mixer -lSDL2main -lSDL2  ; .\vis3.exe
*/



class Visualizer {
public:
    Visualizer(int width, int height, int barWidth);
    ~Visualizer();
    void render(const std::vector<int>& arr, const std::string& algoName, int elapsedTime);
    void delay(int ms);
    // void playSwapSound();
    void renderText(const std::string& text, int x, int y, SDL_Color color);

private:
    // void renderText(const std::string &message, int x, int y, SDL_Color color);
    
    int screenWidth, screenHeight, barWidth;
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
    Mix_Chunk* swapSound;
};

Visualizer::Visualizer(int width, int height, int barWidth)
    : screenWidth(width), screenHeight(height), barWidth(barWidth) {
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    TTF_Init();
    // Mix_Init(MIX_INIT_MP3);
    // Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);

    window = SDL_CreateWindow("Sorting Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // swapSound = Mix_LoadWAV("swap_sound.wav");
    // if (!swapSound) {
    //     std::cerr << "Failed to load swap sound: " << Mix_GetError() << std::endl;
    //     exit(1);
    // }
    font = TTF_OpenFont("./assets/IMPOS50_.ttf", 24); 
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        exit(1);
    }
}

Visualizer::~Visualizer() {
    Mix_FreeChunk(swapSound);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    Mix_CloseAudio();
    Mix_Quit();
    TTF_Quit();
    SDL_Quit();
}

void Visualizer::render(const std::vector<int>& arr, const std::string& algoName, int elapsedTime) {

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int height = arr[i];
        SDL_Rect bar = {i * barWidth, screenHeight - height, barWidth, height};
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &bar);
    }
    
    renderText("Algorithm: Bubble Sort", 10, 10, {255, 255, 255, 255});
    renderText("Time: " + std::to_string(elapsedTime) + " ms", screenWidth - 150, 10, {255, 255, 255, 255});

    renderText("Array Visualizer", 10, screenHeight - 30, {255, 255, 255, 255});
    renderText("- Mahanth Yalla", screenWidth - 100, screenHeight - 30, {255, 255, 255, 255});

    SDL_RenderPresent(renderer);
}

void Visualizer::delay(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

// void Visualizer::playSwapSound() {
//     Mix_PlayChannel(-1, swapSound, 0);
// }

void Visualizer::renderText(const std::string& text, int x, int y, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect destRect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &destRect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void bubbleSort(std::vector<int>& arr, Visualizer& visualizer, const std::string& algoName) {
    auto start = std::chrono::high_resolution_clock::now();
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                auto end = std::chrono::high_resolution_clock::now();
                int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                // visualizer.playSwapSound();
                visualizer.render(arr, algoName, elapsedTime);
                visualizer.delay(SPEED_DELAY);
            }
        }
    }
}

int main() {
    const int screenWidth = 1920;
    const int screenHeight = 1080;
    const int barWidth = 5;
    
    int n = screenWidth / barWidth;
    std::vector<int> arr(n);
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % (screenHeight - 40); 
    }

    Visualizer visualizer(screenWidth, screenHeight, barWidth);
    
    bubbleSort(arr, visualizer, "Bubble Sort");
    
    SDL_Delay(5000);

    return 0;
}
