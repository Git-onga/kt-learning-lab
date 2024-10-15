/*#include <raylib.h>

int main() {

    InitWindow(300, 600, "raylib tetris");
    SetTargetFPS(60);

    while(WindowShouldClose() == false ){
        BeginDrawing();

        EndDrawing();
    }
     
    CloseWindow(); 
} */

#include <raylib.h>

int main() {
    // Initialize the window with a width of 300, height of 600, and a title
    InitWindow(300, 600, "raylib tetris");
    SetTargetFPS(60);  // Set the game to run at 60 frames per second

    while (!WindowShouldClose()) {  // Main game loop, runs until window is closed

        // Start drawing
        BeginDrawing();
        
        // Clear the background with a color (e.g., RAYWHITE)
        ClearBackground(RAYWHITE);
        
        // Draw some text on the window
        DrawText("Tetris Game Window", 50, 50, 20, DARKGRAY);

        // End drawing
        EndDrawing();
    }

    // Close the window and release resources
    CloseWindow(); 
}


