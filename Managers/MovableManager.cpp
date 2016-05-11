/*
 * MovableManager.cpp
 *
 *  Created on: May 10, 2016
 *      Author: default
 */

#include "MovableManager.h"

MovableManager::MovableManager() {
	// TODO Auto-generated constructor stub

}

MovableManager::~MovableManager() {
	// TODO Auto-generated destructor stub
}

bool MovableManager::Process()
{
	for (Contracts::IMovable* client : clients)
	{
		if(client != NULL)
		{
			client->Move();
		}
	}

	return true;
}

