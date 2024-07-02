#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <ctime>
#include <string>

int SPEED_DELAY  = 25;

/*
g++ .\vis2.cpp -o vis2.exe -lmingw32 -lSDL2_ttf -lSDL2main -lSDL2  ; .\vis2.exe
*/

class Visualizer {
public:
    Visualizer(int width, int height, int barWidth);
    ~Visualizer();
    void render(const std::vector<int>& arr, const std::string& algoName, int elapsedTime);
    void delay(int ms);
    void playSwapSound();
    void renderText(const std::string& text, int x, int y, SDL_Color color);

private:
    int screenWidth, screenHeight, barWidth;
    SDL_Window* window;
    SDL_Renderer* renderer;
    TTF_Font* font;
};

Visualizer::Visualizer(int width, int height, int barWidth) : screenWidth(width), screenHeight(height), barWidth(barWidth) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    window = SDL_CreateWindow("Sorting Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height + 30, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    font = TTF_OpenFont("./assets/IMPOS50_.ttf", 24); 
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        exit(1);
    }
}

Visualizer::~Visualizer() {
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    SDL_Quit();
}

void Visualizer::renderText(const std::string &message, int x, int y, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, message.c_str(), color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_Rect dstrect = { x, y, surface->w, surface->h };
    SDL_RenderCopy(renderer, texture, NULL, &dstrect);
    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

void Visualizer::render(const std::vector<int>& arr, const std::string& algoName, int elapsedTime) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int height = arr[i];
        SDL_Rect bar = {i * barWidth, screenHeight - height - 25, barWidth, height};
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &bar);
    }

    renderText("Algorithm: " + algoName, 10, 10, {255, 10, 0, 255});
    renderText("Time: " + std::to_string(elapsedTime) + " ms", screenWidth - 200, 10, {255, 10, 0, 255});
    renderText("Array Visualizer", 10, screenHeight - 15, {255, 10, 0, 255});
    renderText("- Mahanth Yalla", screenWidth - 200, screenHeight - 15, {255, 10, 0, 255});

    SDL_RenderPresent(renderer);
}

void Visualizer::delay(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
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
                visualizer.render(arr, algoName, elapsedTime);
                visualizer.delay(SPEED_DELAY);
            }
        }
    }
}

void selectionSort(std::vector<int> &arr, Visualizer& visualizer, const std::string& algoName){
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0 ;i < arr.size();i ++){
        int minimum = i;
        for(int j = i+1 ; j< arr.size();j++){
            if(arr[minimum] > arr[j])
                minimum = j;
        }
        if( i != minimum){
            int temp = arr[i];
            arr[i] = arr[minimum];
            arr[minimum] = temp;   
            auto end = std::chrono::high_resolution_clock::now();
            int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            visualizer.render(arr, algoName, elapsedTime);
            visualizer.delay(SPEED_DELAY);
        }
    }
}


int main() {
    const int screenWidth = 800 + 60;
    const int screenHeight = 600;
    const int barWidth = 2;
    
    int n = screenWidth / barWidth;
    std::vector<int> arr(n);
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % (screenHeight -60);
    }

    Visualizer visualizer(screenWidth, screenHeight, barWidth);
    
    // bubbleSort(arr, visualizer, "Bubble Sort");
    selectionSort(arr, visualizer, "Selection Sort");
    
    SDL_Delay(5000);

    return 0;
}
