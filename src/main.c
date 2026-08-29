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
    // Get the image into a raylib texture and set the rendering 
    // filter to be "point" or in otherwords nearest-neighbor
  Texture2D player = LoadTextureFromImage(PlayerBox);
  SetTextureFilter(player, TEXTURE_FILTER_POINT);

  // Create the virtual render canvas 
  RenderTexture2D canvas = LoadRenderTexture(virtualW, virtualH);
  SetTextureFilter(canvas.texture, TEXTURE_FILTER_POINT);
  // Get rid of the no longer needed image data to save space in memory
  UnloadImage(PlayerBox);

  Vector2 playerPosition = { (float)screenW/2, (float)screenH/2 };

  SetTargetFPS(60);

  // Game Loop
  while (!WindowShouldClose()) {
    // Logic Updates go here ...
    if (IsKeyDown(KEY_D)) playerPosition.x += playerVelocity;
    if (IsKeyDown(KEY_A)) playerPosition.x -= playerVelocity;
    


    // Drawing virtual pixel art Graphics

    BeginTextureMode(canvas);
      ClearBackground(BLACK);
      
      // Because we are drawing the player on an actually small virtual 
      // canvas, we got to convert the calculated position back to integers.
      DrawTexture(player, (int)playerPosition.x, (int)playerPosition.y, WHITE); 
    EndTextureMode();

    // Draw the virtual graphics o the window
    BeginDrawing();
      ClearBackground(DARKGRAY);

    EndDrawing();
  } // End of Game loop
  CloseWindow();

  return 0; // Close program
}
