#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../GameObjects/ControlableGameObject.h"

using namespace GameObjects;

enum Direction {
	eRight,
	eLeft,
	eDirCount
};

class Character : public ControlableGameObject
{
public:
	Character(int initialPosX = 0, int initialPosY = 0, int = 10);
	virtual ~Character();

	virtual void Draw(SDL_Renderer* renderer);
	virtual void HandleKey(SDL_Keycode e);

private:
	static const int CHARACTER_ANIMATION;
	static const int CLIP_HEIGHT;
	static const int CLIP_WIDTH;
	static const std::string LOAD_PATH;

	Direction m_currentDir;
	int m_currentSprite;
};

#endif /* CHARACTER_H_ */
