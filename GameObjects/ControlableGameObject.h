#pragma once
#include "MovableGameObject.h"
#include "../Contracts/IControlable.h"

namespace GameObjects {

	class ControlableGameObject :
		public Contracts::IControlable,
		public MovableGameObject
	{
	public:
		ControlableGameObject(int x = 0, int y = 0, int w = 0, int h = 0, int vX = 0, int vY = 0, int health = 0, int power = 0, std::string path = "");
		virtual ~ControlableGameObject();

		virtual void HandleKey(SDL_Event * e) override;
		virtual void Move() override;

		int GetInitialVX();

		void Stop();

	protected:
		const int initialVX, initialVY;
	};
}
