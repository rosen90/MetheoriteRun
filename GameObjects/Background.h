/*
 * Background.h
 *
 *  Created on: May 11, 2016
 *      Author: default
 */

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "BaseGameObject.h"

namespace GameObjects {

class Background: public BaseGameObject {
public:
	Background();
	virtual ~Background();

	virtual bool CheckCollision(IColidable* other) override;
	virtual void Draw(SDL_Renderer* renderer) override;
	virtual void Collide(IColidable* other) override;
};

} /* namespace GameObjects */

#endif /* BACKGROUND_H_ */
