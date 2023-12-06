#include "utils.h"

bool optionsCollision(Vector2 mouse, RectangleButton button)
{
	return	mouse.x > button.pos.x
		&& mouse.x < button.pos.x + button.size.x
		&& mouse.y > button.pos.y
		&& mouse.y < button.pos.y + button.size.y;
}

bool CheckCollision(const Rectangle& rectA, const Rectangle& rectB) {
  
    float leftA = rectA.x;
    float rightA = rectA.x + rectA.width;
    float topA = rectA.y;
    float bottomA = rectA.y + rectA.height;

    float leftB = rectB.x;
    float rightB = rectB.x + rectB.width;
    float topB = rectB.y;
    float bottomB = rectB.y + rectB.height;

    
    if (bottomA <= topB || topA >= bottomB || rightA <= leftB || leftA >= rightB) {
        
        return false;
    }

    return true;
}