#include <chrono>   // Time library
#include <cstdlib>  //unsure
#include <iostream> //stdio
#include <thread>   //generate threads

void timer(int duration) {
  while (duration > 0) {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(1000)); // sleep for 1 seconds
    // do something here after every 1 seconds...
    std::system("clear");
    std::cout << duration << std::endl;
    duration--;
  };
}

int main() { timer(10); }
