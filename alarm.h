#include <SDL2/SDL.h>
#include <iostream>

// Function to play the alarm sound
void playAlarmSound() {
  // Initialize SDL Audio
  if (SDL_Init(SDL_INIT_AUDIO) < 0) {
    std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError()
              << std::endl;
    return;
  }

  // Load WAV file
  SDL_AudioSpec wavSpec;
  Uint32 wavLength;
  Uint8 *wavBuffer;
  if (SDL_LoadWAV("alarm.wav", &wavSpec, &wavBuffer, &wavLength) == NULL) {
    std::cerr << "Failed to load sound file! SDL_Error: " << SDL_GetError()
              << std::endl;
    SDL_Quit();
    return;
  }

  // Open audio device
  SDL_AudioDeviceID deviceId = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
  if (deviceId == 0) {
    std::cerr << "Failed to open audio device! SDL_Error: " << SDL_GetError()
              << std::endl;
    SDL_FreeWAV(wavBuffer);
    SDL_Quit();
    return;
  }

  // Queue audio
  SDL_QueueAudio(deviceId, wavBuffer, wavLength);
  SDL_PauseAudioDevice(deviceId, 0);

  // Wait for sound to finish
  SDL_Delay(wavSpec.samples * 1000 / wavSpec.freq);

  // Clean up
  SDL_CloseAudioDevice(deviceId);
  SDL_FreeWAV(wavBuffer);
  SDL_Quit();
}
