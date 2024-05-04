#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// Function to start the Pomodoro timer
void startPomodoro(int workTime, int breakTime) {
  printf("Pomodoro session started. Work for %d minutes.\n", workTime);
  sleep(workTime * 60); // Convert minutes to seconds
  printf("Time's up! Take a break for %d minutes.\n", breakTime);
  sleep(breakTime * 60); // Convert minutes to seconds
}

// Function to log completed Pomodoro sessions
void logSession(char *filename, char *timestamp) {
  FILE *file = fopen(filename, "a");
  if (file == NULL) {
    printf("Error opening file.\n");
    exit(1);
  }
  fprintf(file, "%s - Completed Pomodoro session\n", timestamp);
  fclose(file);
}

int main() {
  int workTime = 25; // Default work time in minutes
  int breakTime = 5; // Default break time in minutes
  char timestamp[20];
  time_t rawtime;
  struct tm *timeinfo;

  while (1) {
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", timeinfo);

    startPomodoro(workTime, breakTime);
    logSession("pomodoro_log.txt", timestamp);
  }

  return 0;
}
