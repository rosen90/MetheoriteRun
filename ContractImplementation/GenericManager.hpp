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

template<class T>
inline void ContractImplementations::GenericManager<T>::RemoveClient(T client) {
	clients.erase(find(clients. begin(), clients.end(), client));
}
