#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <chrono>
#include <thread>

/* RUNNING
> g++ .\viz1.cpp -o viz1.exe -lmingw32 -lSDL2main -lSDL2 ; .\viz1.exe
*/

int SPEED_DELAY = 1;

class Visualizer {
public:
    Visualizer(int width, int height, int barWidth);
    ~Visualizer();
    void render(const std::vector<int>& arr);
    void delay(int ms);

private:
    int screenWidth, screenHeight, barWidth;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

Visualizer::Visualizer(int width, int height, int barWidth)
    : screenWidth(width), screenHeight(height), barWidth(barWidth) {
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Sorting Visualizer", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Visualizer::~Visualizer() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Visualizer::render(const std::vector<int>& arr) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    int n = arr.size();
    for (int i = 0; i < n; ++i) {
        int height = arr[i];
        SDL_Rect bar = {i * barWidth, screenHeight - height, barWidth, height};
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &bar);
    }
    
    SDL_RenderPresent(renderer);
}

void Visualizer::delay(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

void bubbleSort(std::vector<int>& arr, Visualizer& visualizer) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                visualizer.render(arr);
                visualizer.delay(SPEED_DELAY);
            }
        }
    }
}


int main() {
    const int screenWidth = 800;
    const int screenHeight = 600;
    const int barWidth = 4;
    
    int n = screenWidth / barWidth;
    std::vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % screenHeight;
    }

    Visualizer visualizer(screenWidth, screenHeight, barWidth);
    
    bubbleSort(arr, visualizer);
    
    SDL_Delay(5000); 

    return 0;
}
