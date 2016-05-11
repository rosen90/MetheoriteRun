/*
 * MovableManager.h
 *
 *  Created on: May 10, 2016
 *      Author: default
 */

#ifndef MOVABLEMANAGER_H_
#define MOVABLEMANAGER_H_

#include "../Contracts/IMovable.h"
#include "../ContractImplementation/GenericManager.h"

using namespace ContractImplementations;
using namespace Contracts;

class MovableManager : public GenericManager<IMovable*>
{
public:
	MovableManager();
	virtual ~MovableManager();

	virtual bool Process();
};

#endif /* MOVABLEMANAGER_H_ */
