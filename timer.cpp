#include <chrono>  // Time library
#include <cstdlib> //unsure
#include <fstream>
#include <iostream> //stdio
#include <string>
#include <thread> //generate threads

void recordTask(std::string *task, std::string *notes);
int saveTask(std::string *task, std::string *notes);

int timer(int sec) {
  while (sec > 0) {
    int minutes = sec / 60;
    int seconds = sec % 60;
    std::this_thread::sleep_for(
        std::chrono::milliseconds(1000)); // sleep for 1 seconds
    std::system("clear");
    std::cout << "Time Remaining: "<< minutes << ":" << seconds << std::endl;
    sec--;
  };

  system("afplay alarm.wav &");
  std::this_thread::sleep_for(std::chrono::milliseconds(4000));
  return 0;
}

void recordTask(std::string *task, std::string *notes) {
  std::cout << "Task: " << std::endl;
  std::getline(std::cin, *task);
  std::cout << "Notes: " << std::endl;
  std::getline(std::cin, *notes);
}

int saveTask(std::string *task, std::string *notes) {

  // get the name for the file
  auto now = std::chrono::system_clock::now(); // Gets system time
  std::time_t time_now = std::chrono::system_clock::to_time_t(
      now); // Converts system time into time_t var
  std::tm *local_time = std::localtime(&time_now);

  int year = local_time->tm_year + 1900;
  int month = local_time->tm_mon + 1;
  int day = local_time->tm_mday;
  int hour = local_time->tm_hour;
  int min = local_time->tm_min;
  std::string file_name = std::to_string(hour) + ":" + std::to_string(min);

  // get string size.
  int full_size = sizeof(*task) + sizeof(*notes);

  // init the output file with its location and file name
  std::ofstream output_file(std::to_string(year) + "/" + std::to_string(month) +
                            "." + std::to_string(day) + "/" + file_name);

  // check if fail
  if (!output_file.is_open()) {
    perror("malloc failed");
    return 1;
  }

  // Write to the output_file with the task and the notes
  output_file << *task << ": \n" << *notes << std::endl;

  return 0;
}

int main() {
  timer(80);
  std::string task;
  std::string notes;
  recordTask(&task, &notes);
  saveTask(&task, &notes);
}

// TODO
// pause function
// prevent text from being read while the timer is active
// GUI (maybe in qt?)
// streak system
// way to visualize streak system, like a calander
// lazyvim like mainscreen
