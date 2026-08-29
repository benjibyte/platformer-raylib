#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

const float playerVelocity = 8.0f;

// Okay! Here goes!
int main(void) {
  // Window Initialization
  
  const int virtualW = 320;
  const int virtualH = 180;

  const int scale = 4;
  const int screenW = virtualW * scale;
  const int screenH = virtualH * scale;

  InitWindow(screenW, screenH, "My First real Raylib Window!");
  SetExitKey(KEY_NULL);
  

  // Load Assets into memory, and sharpen Pixel art
  Image PlayerBox = LoadImage("assets/collisionbox.png");
  ImageResize(&PlayerBox, 32, 64); // scale 2x
  Texture2D player = LoadTextureFromImage(PlayerBox);
  UnloadImage(PlayerBox);

  Vector2 playerPosition = { (float)screenW/2, (float)screenH/2 };

  SetTargetFPS(60);

  // Game Loop
  while (!WindowShouldClose()) {
    // Logic Updates go here ...
    if (IsKeyDown(KEY_D)) playerPosition.x += playerVelocity;
    if (IsKeyDown(KEY_A)) playerPosition.x -= playerVelocity;
    


    // Drawing the Window and Graphics
    BeginDrawing();
      ClearBackground(RAYWHITE);
      
      DrawTexture(player, playerPosition.x, playerPosition.y, WHITE);
      

    EndDrawing();
  } // End of Game loop
  CloseWindow();

  return 0; // Close program
}
