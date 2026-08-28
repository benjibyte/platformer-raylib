#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

// Okay! Here goes!
int main(void) {
  // Window Initialization
  const int screenW = 1280;
  const int screenH = 720;
  InitWindow(screenW, screenH, "My First real Raylib Window!");
  SetExitKey(KEY_NULL);
  

  // Load Assets into memory
  Image PlayerBox = LoadImage("assets/collisionbox.png");
  ImageResize(&PlayerBox, 32, 64); // scale 2x
  Texture2D player = LoadTextureFromImage(PlayerBox);
  UnloadImage(PlayerBox);

  SetTargetFPS(60);

  // Game Loop
  while (!WindowShouldClose()) {
    // Logic Updates go here ...

    // Drawing the Window and Graphics
    BeginDrawing();
      ClearBackground(RAYWHITE);
      
      DrawTexture(player, screenW/2 - player.width, screenH/2 - player.height/2, WHITE);
      

    EndDrawing();
  } // End of Game loop
  CloseWindow();

  return 0; // Close program
}
