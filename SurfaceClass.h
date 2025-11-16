#ifndef GAURD_SpriteClass_h
    #define GAURD_SpriteClass_h
    #include "SpriteClass.h"
#endif

class Portal {
    public:
        Sprite sprite;
        std::string end_state;

        Portal() {}
        Portal(float x, float y,int w,int h,std::string f, std::string end) {
            sprite = Sprite(x, y, w, h, f);
            end_state = end;
        }
};

class Surface : public Sprite {
    public:
        std::vector<Portal> portals;

        Surface() : Sprite() {}
        Surface(float _x, float _y,int w,int h,std::string f_name) : Sprite(_x, _y, w, h, f_name) {} 

        void addPortal(float _x, float _y,int w,int h,std::string f, std::string end) {
            portals.push_back(Portal(x, y, w, h, f, end));
        }

        void ChangeX(int change_num) {
            x += change_num;
            for (Portal portal : portals) {
                portal.sprite.x += change_num;
            }
        }
        void ChangeY(int change_num) {
            y += change_num;
            for (Portal portal : portals) {
                portal.sprite.y += change_num;
            }
        }
};