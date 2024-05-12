#include <chrono>   // Time library
#include <cstdlib>  //unsure
#include <iostream> //stdio
#include <thread>   //generate threads

void timer(int duration) {
  while (duration > 0) {
    std::this_thread::sleep_for(
        std::chrono::milliseconds(1000)); // sleep for 1 seconds
    std::system("clear");
    std::cout << duration << std::endl;
    duration--;
  };
  system("afplay alarm.wav");
}

void recordTask(char *task, char *notes) {
  std::cout << "What did you in this hour?" << std::endl;
  std::cin >> *task;
  std::cout << "Notes:" << std::endl;
  std::cin >> *notes;
}

void saveTask() {
  FILE *pFile;
  auto now = std::chrono::system_clock::now(); // Gets system time
  std::time_t time_now = std::chrono::system_clock::to_time_t(
      now); // Converts system time into time_t var
  std::tm *local_time = std::localtime(&time_now);

  int year = local_time->tm_year + 1900;
  int month = local_time->tm_mon + 1;
  int day = local_time->tm_mday;
  int hour = local_time->tm_hour;
  int min = local_time->tm_min;
  std::cout << year << month << day << hour << min << std::endl;
}

int main() {
  timer(10);
  saveTask();
  return 0;
}
