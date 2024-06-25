#include "iostream"


int main(){

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    int a = 10;
    float g = 9.8;
    std::string s = "Mahanth" , w ;
    // std::cin >> w ;
    /*
    To get an entire line : use getline() function
    */
    getline(std::cin , w);
    std::cout << a << "\tHello " << s << "\n" << g <<  "\nYou typed :"  << w <<  std::endl;

    return 0;
}
