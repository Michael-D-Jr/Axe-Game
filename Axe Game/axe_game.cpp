#include "raylib.h"

int main()
{
    // window dimensions
    int windowWidth = 800;
    int windowHeight = 450;

    // circle variables
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};
    int movement_speed{10};
    // circle edges
    int circle_left_edge{circle_x - circle_radius};
    int circle_right_edge{circle_x + circle_radius};
    int circle_upper_edge{circle_y - circle_radius};
    int circle_bottom_edge{circle_y + circle_radius};

    // axe variables
    int axe_x_pos{400};
    int axe_y_pos{0};
    int axe_width{50};
    int axe_height{50};
    int direction{10};
    // axe edges
    int axe_left_edge{axe_x_pos};
    int axe_right_edge{axe_x_pos + axe_width};
    int axe_upper_edge{axe_y_pos};
    int axe_bottom_edge{axe_y_pos + axe_height};

    // Game Over Detection
    bool collision_with_axe = 
                            (axe_bottom_edge >= circle_upper_edge) && 
                            (axe_upper_edge <= circle_bottom_edge) && 
                            (axe_right_edge >= circle_left_edge) && 
                            (axe_left_edge <= circle_right_edge);

    // draw the window
    InitWindow(windowWidth, windowHeight, "Axe Game");

    SetTargetFPS(60);

    // control the window and its contents
    while (WindowShouldClose() != true)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        // Game Over
        if (collision_with_axe)
        {
            DrawText("Game Over!!", 400, 200, 20, RED);
        }
        else
        {
            // Game Logic begins
            
            // update circle edges
            circle_left_edge = circle_x - circle_radius;
            circle_right_edge = circle_x + circle_radius;
            circle_upper_edge = circle_y - circle_radius;
            circle_bottom_edge = circle_y + circle_radius;

            // update axe edges
            axe_left_edge = axe_x_pos;
            axe_right_edge = axe_x_pos + axe_width;
            axe_upper_edge = axe_y_pos;
            axe_bottom_edge = axe_y_pos + axe_height;

            // update collision check
            collision_with_axe = 
                            (axe_bottom_edge >= circle_upper_edge) && 
                            (axe_upper_edge <= circle_bottom_edge) && 
                            (axe_right_edge >= circle_left_edge) && 
                            (axe_left_edge <= circle_right_edge);
            
            DrawCircle(circle_x, circle_y, circle_radius, BLUE);            
            DrawRectangle(axe_x_pos, axe_y_pos, axe_width, axe_height, RED);         
            
            //move the axe
            axe_y_pos += direction;
            if (axe_y_pos > (windowHeight - axe_height) || axe_y_pos < 0)
            {
                direction = -direction;
            }

            if (IsKeyDown(KEY_D) && circle_x < (windowWidth - circle_radius))
            {
                circle_x += movement_speed;
            }

            if (IsKeyDown(KEY_A) && circle_x > (0 + circle_radius))
            {
                circle_x -= movement_speed;
            }
            // Game Logic ends
        }
        EndDrawing();
    }
    

}