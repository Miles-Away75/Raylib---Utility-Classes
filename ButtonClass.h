#ifndef GAURD_SpriteClass_h
#define GAURD_SpriteClass_h
#include "SpriteClass.h"
#endif

class Button : public Sprite {
    public: 

        int frames_since_last_click = 0;
        void (*operation_func_ptr)();
        bool func_assigned = false;

                
        Button() : Sprite() {}
        Button(float _x, float _y, int w, int h, std::string f_name) : Sprite(_x,_y,w,h,f_name) {}

        bool IsClicked() {
            if (IsMouseButtonDown(MOUSE_BUTTON_LEFT) && GetMouseX() > x && GetMouseX() < x+width && GetMouseY() > y && GetMouseY() < y+height) {
                if (frames_since_last_click <= 0) {
                    frames_since_last_click= 30;
                    if (func_assigned) {
                        operation_func_ptr();
                    }
                    return true;
                }
            }
            else {
                frames_since_last_click -= 1;
                if (frames_since_last_click < 0) {
                    frames_since_last_click = 0;
                }
                return false;
            
            }
            return false;
        }
        void AssignFunc(void (*func)()) {
            operation_func_ptr = func;
            func_assigned = true;
        }
};