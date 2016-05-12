/*
 * CollisionManager.cpp
 *
 *  Created on: May 11, 2016
 *      Author: default
 */

#include "CollisionManager.h"
#include "../Contracts/IColidable.h"

namespace Managers {

CollisionManager::CollisionManager()
	: ContractImplementations::GenericManager<Contracts::IColidable*>()
{
	// TODO Auto-generated constructor stub

}

CollisionManager::~CollisionManager() {
	// TODO Auto-generated destructor stub
}

bool CollisionManager::Process()
{
	for (unsigned i = 0; i < clients.size(); ++i) {
		for (unsigned g = i + 1; g < clients.size(); ++g) {
			if(clients[i]->CheckCollision(clients[g]))
			{
				clients[i]->Collide(clients[g]);
			}
		}
	}

	return true;
}

} /* namespace Managers */
