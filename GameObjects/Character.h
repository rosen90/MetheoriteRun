#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../GameObjects/ControlableGameObject.h"

using namespace GameObjects;

class Character : public ControlableGameObject
{
public:
	Character(int initialPosX = 0, int initialPosY = 0, int = 10);
	virtual ~Character();

	virtual void Draw(SDL_Renderer* renderer);
	virtual void Move();

private:
	static const int CHARACTER_ANIMATION;
	static const int CLIP_HEIGHT;
	static const int CLIP_WIDTH;
	static const std::string LOAD_PATH;

	int m_currentSprite;
};

#endif /* CHARACTER_H_ */
