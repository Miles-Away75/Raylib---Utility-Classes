#ifndef GAURD_Macros_h
#define GAURD_Macros_h
#include "IncludeMacros.h"
#endif

class Sprite {
    public:
        float x;
        float y;
        int width;
        int height;
        std::string image_path;
        Texture texture;

        ~Sprite() {
            UnloadTexture(texture);
        }
        Sprite() : x(0), y(0), width(1), height(1) {}
        Sprite(float _x, float _y, int w, int h, std::string f_name) {
            x = _x;
            y = _y;
            width = w;
            height = h;
            image_path = f_name;
            LoadTextures();
        }
        Sprite(const Sprite& other) {
        // Copy logic here, e.g., deep copy of dynamic memory
        x = other.x;
        y = other.y;
        width = other.width;
        height = other.height;
        image_path = other.image_path;
        
        LoadTextures();
    }   
        void LoadTextures() {
            Image i = LoadImage(image_path.c_str());
            ImageResize(&i, width, height);
            texture = LoadTextureFromImage(i);
            UnloadImage(i);
        }
        void Render(Color tint = WHITE) {
            DrawTexture(texture, x, y, tint);
        }

};
