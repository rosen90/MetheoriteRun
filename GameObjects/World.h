/*
 * Background.h
 *
 *  Created on: May 11, 2016
 *      Author: default
 */

#ifndef WORLD_H_
#define WORLD_H_

#include "ControlableGameObject.h"
#include "../ContractImplementation/GenericManager.h"

namespace Contracts{
	class IManager;
}

namespace GameObjects {

class World
	: public ControlableGameObject,
	  public ContractImplementations::GenericManager<Contracts::IManager*>
{
public:
	virtual ~World();

	virtual bool Process() override;

	template<class T>
	Contracts::IGenericManager<T>* GetManager();

	template<class T>
	void AddClient(ContractImplementations::GenericManager<T>* client);

	static World* GetInstance();

private:
	World();
	static World* Instance;
	static const int FPS = 60;
	unsigned currentFrame;
	bool quit;

	virtual bool CheckCollision(IColidable* other) override;
	virtual void Draw(SDL_Renderer* renderer) override;
	virtual void Collide(IColidable* other) override;
	virtual void HandleKey(SDL_Event* e) override;
};
#include "World.hpp"
} /* namespace GameObjects */

#endif /* WORLD_H_ */
