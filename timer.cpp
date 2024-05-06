#include <cerrno>
#include <cstring>
#include <iostream>
#include <signal.h>
#include <sys/time.h>
#include <unistd.h>

void handleError(const char *msg) {
  std::cout << msg << ": " << strerror(errno) << std::endl;
  exit(EXIT_FAILURE);
}

void alarm_handler(int signum) {
  // Do nothing; just handle the signal
}

int main() {
  struct itimerval timer;

  // Set Up the New timer
  timer.it_value.tv_sec = 10;
  timer.it_value.tv_usec = 0;
  timer.it_interval.tv_sec = 1;
  timer.it_interval.tv_usec = 0;

  if (setitimer(ITIMER_REAL, &timer, nullptr) == -1) {
    handleError("setitimer");
  }

  // Register the signal handler
  if (signal(SIGALRM, alarm_handler) == SIG_ERR) {
    handleError("signal");
  }

  // Loop until the timer expires
  while (true) {
    // Get the current timer value
    if (getitimer(ITIMER_REAL, &timer) == -1) {
      handleError("getitimer");
    }

    // Display the time remaining on the timer
    std::cout << "Time remaining on timer: " << timer.it_value.tv_usec
              << " microseconds " << timer.it_value.tv_sec << " seconds"
              << std::endl;

    // Pause execution until the next timer expiration
    pause();
  }

  return 0;
}
