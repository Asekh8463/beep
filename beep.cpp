#include <iostream>
#include <random>
#include <chrono>
#include <thread>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

int main ()
{
    const wchar_t* path = L"noise.wav"; 
    int d = 2;
    using namespace std::this_thread; // sleep_for
    using namespace std::chrono;
    while (d > 0) 
    {
        std::random_device rd; // obtain a random number
        std::mt19937 gen(rd()); // seed
        std::uniform_int_distribution<> distr(7, 17); // range
        int x = distr(gen); //assign
        sleep_for(seconds(x)); //pause for random amt of time
        PlaySound(path, NULL, SND_FILENAME | SND_ASYNC); //plays the sound
        cout << x; //prints no. of seconds; optional
        FreeConsole();
    }
}
