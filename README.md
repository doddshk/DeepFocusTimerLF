
# Pomodoro Log 

PomodoroLogCLI" is a command-line application designed to enhance productivity using the Pomodoro technique. Users can easily manage their work sessions and breaks through a simple interface in their terminal. The application allows users to set customizable timers for work and break intervals, following the Pomodoro method's structure of focused work sessions punctuated by short breaks.

Will be coded in C++

## Problem

I want a better way to track my studying, and logging it in a readable calender format. A calender resembling the github commit calender. I want to be able to view how long I studied per day, what I studied, and other notes about the focus session.

## Implementation

I have multiple angles I can tackle this problem:
- Simple cli written in C++. (Trying to learn C/C++ at the moment)
- Write a application for the calender, in Qt.

After the user opens the application, they will have the options to:

- Start a study session
- View calender
- Adjust settings

If the user selects to start a study session, a timer will appear (maybe with some ascii art).

After the user is finished studying, a timer alarm will play and the user will be prompted to type in a few things about the session. I would like to structure this comment to allign with a git commit message. For example: 

- Header (What I studied)
- Body (Other comments about the study session)

After the user inputs these things, the application will save it in a file and be viewable in the calender. 
