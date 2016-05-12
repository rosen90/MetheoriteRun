template<class T>
Contracts::IGenericManager<T>* GameObjects::World::GetManager()
{
	Contracts::IGenericManager<T>* found = 0;

	for(Contracts::IManager* mgr : clients)
	{
		found = dynamic_cast<Contracts::IGenericManager<T>*>(mgr);
		if (found != 0)
			break;
	}

	return found;
}

template<class T>
inline void GameObjects::World::AddClient(
		ContractImplementations::GenericManager<T>* client) {
	T casted = dynamic_cast<T>(this);
	if( casted != NULL)
	{
		client->AddClient(casted);
	}

	ContractImplementations::GenericManager<Contracts::IManager*>::AddClient(client);
}
