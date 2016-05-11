#pragma once
#include "MovableGameObject.h"
#include "../Contracts/IControlable.h"

namespace GameObjects {


	enum Direction {
		eRight,
		eLeft,
		eUp
	};

	class ControlableGameObject :
		public Contracts::IControlable,
		public MovableGameObject
	{
	public:
		ControlableGameObject(int x = 0, int y = 0, int w = 0, int h = 0, int vX = 0, int vY = 0, std::string path = "");
		virtual ~ControlableGameObject();

		virtual void HandleKey(SDL_Keycode e) override;

		virtual void Move() override;

	protected:
		bool moveAllowed;
		const int initialVX, initialVY;
		Direction currentDir;
	};
}
