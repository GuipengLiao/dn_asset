#ifndef  __XEntityMgr__
#define  __XEntityMgr__

#include<vector>
#include<unordered_map>
#include<unordered_set>
#include"Common.h"
//#include "NativeInterface.h"
#include"Singleton.h"

class XEntity;
class XRole;
class XPlayer;

enum EntityType
{
	//����
	Entity = 1 << 0,
	Role = 1 << 1,
	Player = 1 << 2,
	Monster = 1 << 3,
	Boss = 1 << 4,
	Npc = 1 << 5,

	//ͬ��
	Ship_Start = 6,
	Enemy = 1 << 6, //�ж� 
	Ally = 1 << 7,  //�Ѻ�
	AllyAll = 1 << 8, //˫���Ѻ� ������
	EnemyAll = 1 << 9, //˫���ж� ������
	EProtected = 1 << 10,//�жԵ������ܻ� �����ι�
	AProtected = 1 << 11,//�Ѿ������ܻ� �簲ȫ����
	Ship_End = 11
};


class XEntityMgr:public Singleton<XEntityMgr>
{
public:
	void Update(float delta);
	void LateUpdate();
	void AttachToHost();
	void DetachFromHost();
	XEntity* GetEntity(uint id);
	XRole* CreateTestRole();
	XPlayer* CreatePlayer();

private:
	std::vector<XEntity*> _empty;
	std::unordered_set<XEntity*> _hash_entities;
	std::unordered_map<uint, XEntity*> _dic_entities;
	std::unordered_map<int, std::vector<XEntity*>> _map_entities;
};


#endif