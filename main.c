#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

// Okay! Here goes!
int main(void) {
  // Window Initialization

  const int screenW = 1280;
  const int screenH = 720;
  InitWindow(screenW, screenH, "My First real Raylib Window!");
  SetTargetFPS(60);

  // Game Loop
  while (!WindowShouldClose) {
    // Logic Updates go here ...

    // Drawing the Window and Graphics
    BeginDrawing();
      ClearBackground(RAYWHITE);
      DrawText("Congrats! I created my first window!", 190, 200, 20, LIGHTGRAY);
    EndDrawing();
  } // End of Game loop


  return 0; // Close program
}