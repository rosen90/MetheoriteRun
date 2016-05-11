/*
 * CollisionManager.h
 *
 *  Created on: May 11, 2016
 *      Author: default
 */

#ifndef COLLISIONMANAGER_H_
#define COLLISIONMANAGER_H_

#include "../ContractImplementation/GenericManager.h"

namespace Contracts {
	class IColidable;
}

namespace Managers {

class CollisionManager: public ContractImplementations::GenericManager<Contracts::IColidable*> {
public:
	CollisionManager();
	virtual ~CollisionManager();
	virtual bool Process() override;
};

} /* namespace Managers */

#endif /* COLLISIONMANAGER_H_ */
