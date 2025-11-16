#ifndef GAURD_SpriteClass_h
#define GAURD_SpriteClass_h
#include "SpriteClass.h"
#endif

Texture loadTexture(std::string f_path, int w, int h) {
    Image i = LoadImage(f_path.c_str());
    ImageResize(&i, w, h);
    Texture texture = LoadTextureFromImage(i);
    UnloadImage(i);
    return texture;
}


class AnimatedSpriteClass : public Sprite {
    public:
        std::vector<Texture> frames;
        int frame_num = 0;
        bool running = false;
        int frames_bet_tick = 0.3;

        AnimatedSpriteClass() : Sprite() {}
        AnimatedSpriteClass(float _x, float _y, int time_bet) {
            frames_bet_tick = time_bet;
            x = _x;
            y = _y;
        }

        void Render(int num_of_frames,Color tint = WHITE) {
            DrawTexture(frames[frame_num], x, y, tint);
            if (running && num_of_frames % frames_bet_tick == 0) {
                Tick();
            }
        }
        void Play() {running = true;}
        void Pause() {running = false;}
        void AddFrame(std::string f_name,int  w, int h) {
            frames.push_back(loadTexture(f_name, w, h));
        }
        void Tick() {
            frame_num += 1;
            if (frame_num >= frames.size()) {
                frame_num = 0;
            }
        }

};