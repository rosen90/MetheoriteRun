#pragma once

namespace Contracts
{
	class IMovable
	{
	public:
		virtual void Move() = 0;

		virtual int GetVelocityX() = 0;
		virtual int GetVelocityY() = 0;
		virtual void SetVelocityX(int) = 0;
		virtual void SetVelocityY(int) = 0;
		
	};
}