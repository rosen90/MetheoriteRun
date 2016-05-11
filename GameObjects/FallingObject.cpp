///*
// * FallingObject.cpp
// *
// *  Created on: May 10, 2016
// *      Author: default
// */
//
//#include "FallingObject.h"
//
//namespace GameObjects
//{
//
//const std::string FallingObject::LOAD_PATH = "Data/Images/fallingObjects.png";
//
//FallingObject::FallingObject(int velX, int velY, int posX)
//	: MovableGame(velX, velY, { posX, 0, CLIP_SIZE, CLIP_SIZE }, LOAD_PATH)
//{
//	m_currentSprite = 0;
//}
//
//FallingObject::~FallingObject() {
//	// TODO Auto-generated destructor stub
//}
//
//
//void FallingObject::Move()
//{
//	if(m_currentSprite < MAX_SPRITE_COUNT - 1)
//		m_currentSprite++;
//
//	Movable::Move();
//}
//
//
//void FallingObject::Draw(SDL_Renderer* renderer)
//{
//	SDL_Rect clip = {
//		(m_currentSprite % SPRITE_PER_LINE) * CLIP_SIZE,
//		(m_currentSprite / SPRITE_PER_LINE ) * CLIP_SIZE,
//		CLIP_SIZE,
//		CLIP_SIZE
//	};
//	m_texture.render(renderer, &m_clip, &clip);
//}
//
//}
