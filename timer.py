import time
import pygame
import curses

def start_timer(stdscr, seconds):
    pygame.init()

    while seconds > 0:
        # Get terminal dimensions
        height, width = stdscr.getmaxyx()

        # Center the clock horizontally
        current_time = f"Timer: {seconds // 3600:02d}:{(seconds % 3600) // 60:02d}:{seconds % 60:02d}"
        x = (width - len(current_time)) // 2

        # Clear the screen
        stdscr.clear()

        # Add the clock to the screen
        stdscr.addstr(height // 2, x, current_time)

        # Refresh the screen
        stdscr.refresh()

        # Wait for 1 second
        time.sleep(1)
        seconds -= 1

    stdscr.clear()
    stdscr.addstr(0, 0, "Timer stopped")
    stdscr.refresh()
    stdscr.getch()

    # Play alarm sound
    pygame.mixer.init()
    pygame.mixer.music.load("alarm.wav")
    pygame.mixer.music.play()
    time.sleep(5)

def main(stdscr):
    curses.curs_set(0)
    start_timer(stdscr, 10)

if __name__ == "__main__":
    curses.wrapper(main)
