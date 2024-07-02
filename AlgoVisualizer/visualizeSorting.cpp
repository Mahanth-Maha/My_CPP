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
#include <map>
#include <sstream>


int SPEED_DELAY  = 1;
std::vector<int> sorted;
/* PowerShell $>
g++ .\visualizeSorting.cpp -o visualizeSorting.exe -lmingw32 -lSDL2_ttf -lSDL2main -lSDL2  ; .\visualizeSorting.exe
*/

class Visualizer {
public:
    Visualizer(int width, int height, int barWidth);
    ~Visualizer();
    void render(const std::vector<int>& arr, const std::string& algoName, int elapsedTime);
    void renderResults(const std::vector<int>& arr, const std::map<std::string, int>& algorithmTimes);
    void delay(int ms);
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
    // font = TTF_OpenFont("./assets/IMPOS50_.ttf", 24); 
    // font = TTF_OpenFont("./assets/SciFi.ttf", 24); 
    font = TTF_OpenFont("./assets/OriginTech.ttf", 24); 
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
        if (sorted[i] == arr[i]) 
            SDL_SetRenderDrawColor(renderer, 0, 255, 0, SDL_ALPHA_OPAQUE); 
        else 
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE); 
        SDL_RenderFillRect(renderer, &bar);
    }

    renderText("Algo : " + algoName, 10, 10, {255, 10, 0, 255});
    renderText("Time : " + std::to_string(elapsedTime) + " ms", screenWidth - 200, 10, {255, 10, 0, 255});
    renderText("Array Visualizer", 10, screenHeight - 15, {255, 10, 0, 255});
    renderText("-by Mahanth Yalla", screenWidth - 300, screenHeight - 15, {255, 10, 0, 255});

    SDL_RenderPresent(renderer);
}

bool sortBySecond(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    return a.second < b.second;
}

void Visualizer::renderResults(const std::vector<int>& arr, const std::map<std::string, int>& algorithmTimes){
    int textPosY = 10; 
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    int cnt = 0;
    renderText("Results - Performance in ms (milliseconds)", 30, textPosY, {55, 125, 220, 255});
    textPosY += 50;
    renderText("Algorithm ", 50, textPosY, {255, 10, 0, 255});
    renderText("Time ",  450, textPosY, {255, 10, 0, 255});
    SDL_Color textColor = {64, 224, 64, 255}; 
    std::vector<std::pair<std::string, int>> algorithmTimes_vec;
    for (const auto& pair : algorithmTimes) {
        algorithmTimes_vec.push_back(pair);
    }
    textPosY+=50;

    std::sort(algorithmTimes_vec.begin(), algorithmTimes_vec.end(), sortBySecond);
    for (const auto& pair : algorithmTimes_vec) {
        std::stringstream text1 , text2;
        cnt++;

        text1 << cnt << ". "<< pair.first  ;
        SDL_Surface* surface = TTF_RenderText_Solid(font, text1.str().c_str(), textColor);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_Rect rect = {50, textPosY, surface->w, surface->h};
        SDL_RenderCopy(renderer, texture, NULL, &rect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);

        text2 << std::to_string(pair.second) << " ms";
        surface = TTF_RenderText_Solid(font, text2.str().c_str(), textColor);
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        rect = { 450, textPosY, surface->w, surface->h};
        SDL_RenderCopy(renderer, texture, NULL, &rect);
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(texture);

        if(*algorithmTimes_vec.begin() == pair)
            textColor = {255, 255, 255, 255}; 
        textPosY += 50; 
    }

    SDL_RenderPresent(renderer);
}

void Visualizer::delay(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

int bubbleSort(std::vector<int>& arr, Visualizer& visualizer, const std::string& algoName) {
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
    auto end = std::chrono::high_resolution_clock::now();
    int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    visualizer.render(arr, algoName, elapsedTime);
    visualizer.delay(SPEED_DELAY);
    return elapsedTime;
}

int selectionSort(std::vector<int> &arr, Visualizer& visualizer, const std::string& algoName){
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0 ;i < arr.size();i ++){
        int minimum = i;
        for(int j = i+1 ; j< arr.size();j++){
            if(arr[minimum] > arr[j])
                minimum = j;
            auto end = std::chrono::high_resolution_clock::now();
            int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            visualizer.render(arr, algoName, elapsedTime);
            visualizer.delay(SPEED_DELAY);
        }
        if( i != minimum){
            int temp = arr[i];
            arr[i] = arr[minimum];
            arr[minimum] = temp;   
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    visualizer.render(arr, algoName, elapsedTime);
    visualizer.delay(SPEED_DELAY);
    return elapsedTime;
}



int insertionSort(std::vector<int> &arr, Visualizer& visualizer, const std::string& algoName){
    auto start = std::chrono::high_resolution_clock::now();
    for(int i  = 1 ; i< arr.size(); i++){
        int k = arr[i], j = i - 1;
        while(j >= 0 &&  arr[j] > k ){
            arr[j+1] = arr[j];
            j--;
            auto end = std::chrono::high_resolution_clock::now();
            int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            visualizer.render(arr, algoName, elapsedTime);
            visualizer.delay(SPEED_DELAY);
        }
        arr[j+1] = k ;
    }
    auto end = std::chrono::high_resolution_clock::now();
    int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    visualizer.render(arr, algoName, elapsedTime);
    visualizer.delay(SPEED_DELAY);
    return elapsedTime;
}

void merge(int p,int q,int r, std::vector<int> &arr, std::vector<int> &a, Visualizer& visualizer, const std::string& algoName, std::chrono::_V2::system_clock::time_point start){
    int i = p,  j =  q + 1, k = p;
    while(i <= q && j <= r){
        a[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
        auto end = std::chrono::high_resolution_clock::now();
        int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        visualizer.render(arr, algoName, elapsedTime);
        visualizer.delay(SPEED_DELAY);
    }
    while(i <= q){
        a[k++] = arr[i++];
        auto end = std::chrono::high_resolution_clock::now();
        int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        visualizer.render(arr, algoName, elapsedTime);
        visualizer.delay(SPEED_DELAY);
    }
    while(j <= r){
        a[k++] = arr[j++];
        auto end = std::chrono::high_resolution_clock::now();
        int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        visualizer.render(arr, algoName, elapsedTime);
        visualizer.delay(SPEED_DELAY);
    }
    for(i = p ; i <=r ; i++){
        arr[i] = a[i];
    }
}
void merge_sort_recursive(int i , int j , std::vector<int> &arr,std::vector<int> &a, Visualizer& visualizer, const std::string& algoName, std::chrono::_V2::system_clock::time_point start){
    if(i == j) return;
    if(i+1 == j){
        if(arr[i] > arr[j]) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            auto end = std::chrono::high_resolution_clock::now();
            int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            visualizer.render(arr, algoName, elapsedTime);
            visualizer.delay(SPEED_DELAY);
        }
        return;
    }
    if( i < j){
        int mid = (i + j) /2;
        merge_sort_recursive(i,mid,arr,a,visualizer,algoName,start);
        merge_sort_recursive(mid+1,j,arr,a,visualizer,algoName,start);
        merge(i,mid,j,arr,a,visualizer,algoName,start);
        auto end = std::chrono::high_resolution_clock::now();
        int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        visualizer.render(arr, algoName, elapsedTime);
        visualizer.delay(SPEED_DELAY);
    }
}
int mergeSort(std::vector<int> &arr, Visualizer& visualizer, const std::string& algoName ){
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> a(arr.size());
    merge_sort_recursive(0,arr.size()-1,arr,a,visualizer,algoName,start);
    auto end = std::chrono::high_resolution_clock::now();
    int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    visualizer.render(arr, algoName, elapsedTime);
    visualizer.delay(SPEED_DELAY);
    return elapsedTime;
}



int partition(int p,int q, std::vector<int>& arr, Visualizer& visualizer, const std::string& algoName, std::chrono::_V2::system_clock::time_point start){
    int pivot = q;
    int i = p-1 , j = p;

    while(j != q){
        if(arr[j] < arr[pivot]){
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            auto end = std::chrono::high_resolution_clock::now();
            int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
            visualizer.render(arr, algoName, elapsedTime);
            visualizer.delay(SPEED_DELAY);
        }
        j++;
    }
    i++;
    int temp = arr[pivot];
    arr[pivot] = arr[i];
    arr[i] = temp;
    auto end = std::chrono::high_resolution_clock::now();
    int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    visualizer.render(arr, algoName, elapsedTime);
    visualizer.delay(SPEED_DELAY);

    return i;
}
void quick_sort_recursive(int p , int q , std::vector<int> &arr, Visualizer& visualizer, const std::string& algoName, std::chrono::_V2::system_clock::time_point start){
    if( p < q){
        int pivot = partition(p,q,arr,visualizer,algoName,start);
        quick_sort_recursive(p,pivot - 1,arr,visualizer,algoName,start);
        quick_sort_recursive(pivot + 1,q,arr,visualizer,algoName,start);
        auto end = std::chrono::high_resolution_clock::now();
        int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        visualizer.render(arr, algoName, elapsedTime);
        visualizer.delay(SPEED_DELAY);
    }
}
int quickSort(std::vector<int> &arr, Visualizer& visualizer, const std::string& algoName ){
    auto start = std::chrono::high_resolution_clock::now();
    quick_sort_recursive(0,arr.size()-1,arr,visualizer,algoName,start);
    auto end = std::chrono::high_resolution_clock::now();
    int elapsedTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    visualizer.render(arr, algoName, elapsedTime);
    visualizer.delay(SPEED_DELAY);
    return elapsedTime;
}

int main() {
    const int screenWidth = 800 + 60;
    const int screenHeight = 600;
    const int barWidth = 5;
    std::map<std::string, int> algorithmTimes;

    int n = screenWidth / barWidth;
    std::vector<int> arr(n), algo1, algo2,algo3, algo4, algo5;
    srand(time(0));
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % (screenHeight -60);
    }
    sorted = algo1 = algo2 = algo3 = algo4 = algo5 = arr;
    sort(sorted.begin(),sorted.end());

    Visualizer visualizer(screenWidth, screenHeight, barWidth);
    
    algorithmTimes["Bubble Sort"] = bubbleSort(algo1, visualizer, "Bubble Sort");
    algorithmTimes["Selection Sort"] = selectionSort(algo2, visualizer, "Selection Sort");
    algorithmTimes["Insertion Sort"] = insertionSort(algo3, visualizer, "Insertion Sort");
    SPEED_DELAY = 3;
    algorithmTimes["Merge Sort"] =  mergeSort(algo4, visualizer, "Merge Sort");
    algorithmTimes["Quick Sort"] = quickSort(algo5, visualizer, "Quick Sort");
    
    visualizer.renderResults(arr, algorithmTimes);
    
    SDL_Delay(10000);

    return 0;
}
