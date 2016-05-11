template<class T>
inline ContractImplementations::GenericManager<T>::GenericManager()
{
}

template<class T>
inline ContractImplementations::GenericManager<T>::~GenericManager()
{
}

template<class T>
inline void ContractImplementations::GenericManager<T>::AddClient(T client)
{
	clients.push_back(client);
}
