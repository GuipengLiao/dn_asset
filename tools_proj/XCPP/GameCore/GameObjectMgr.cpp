#include "GameObjectMgr.h"
#include "GameObject.h"
#include "Transform.h"
#include "Common.h"
#include "CommandDef.h"
#include "NativeInterface.h"


void GameObjectMgr::Clear()
{
	for (std::map<uint, GameObject*>::iterator it = pool.begin(); it != pool.end(); it++)
	{
		delete it->second;
	}
	pool.clear();
}

GameObject* GameObjectMgr::Create(const char* name)
{
	uint hash = xhash(name);
	if (pool.find(hash) == pool.end())
	{
		GameObject* go = new GameObject(name);
		Add(go);
		return go;
	}
	return pool[hash];
}

bool GameObjectMgr::Add(GameObject* go)
{
	const char* name = go->name;
	uint hash = xhash(name);
	if (pool.find(hash) == pool.end())
	{
		pool.insert(std::make_pair(hash, go));
		return true;
	}
	return false;
}

bool GameObjectMgr::Remv(GameObject* go)
{
	const char* name = go->name;
	return  Remv(name);
}


bool GameObjectMgr::Remv(const char* name)
{
	uint hash = xhash(name);
	return Remv(hash);
}

bool GameObjectMgr::Remv(uint hash)
{
	if (pool.find(hash) != pool.end())
	{
		delete pool[hash];
		pool.erase(hash);
		return true;
	}
	return false;
}

GameObject* GameObjectMgr::Get(uint id)
{
	if (pool.find(id) != pool.end())
	{
		return pool[id];
	}
	return NULL;
}

size_t GameObjectMgr::Count()
{
	return pool.size();
}

