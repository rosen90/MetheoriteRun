template<class T>
Contracts::IGenericManager<T>* Managers::BossManager::GetManager()
{
	Contracts::IGenericManager<T>* found = 0;
	BossManager* boss = BossManager::GetInstance();

	for(Contracts::IManager* mgr : boss->clients)
	{
		found = dynamic_cast<Contracts::IGenericManager<T>*>(mgr);
		if (found != 0)
			break;
	}

	return found;
}
