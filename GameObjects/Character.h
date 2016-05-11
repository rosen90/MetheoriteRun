#ifndef CHARACTER_H_
#define CHARACTER_H_

#include "../GameObjects/ControlableGameObject.h"

using namespace GameObjects;

class Character : public ControlableGameObject
{
public:
	Character(int initialPosX = 0, int initialPosY = 0, int = 1, int = 1);
	virtual ~Character();

	virtual void Draw(SDL_Renderer* renderer) override;
	virtual void Move() override;

private:
	static const int CHARACTER_ANIMATION;
	static const int CLIP_HEIGHT;
	static const int CLIP_WIDTH;
	static const std::string LOAD_PATH;

	int m_currentSprite;
	int jumpFrame;

	unsigned currentFrame;
	static const int FPS = 24;
};

#endif /* CHARACTER_H_ */
