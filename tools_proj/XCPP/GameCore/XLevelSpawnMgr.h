#ifndef  __XLevelSpawnMgr__
#define  __XLevelSpawnMgr__

#include "Singleton.h"
#include "Common.h"
#include "XLevelWave.h"
#include "XLevelScriptMgr.h"
#include "LevelSpawnType.h"
#include "XLevelSpawnInfo.h"

struct XLevelStatistic
{
	XLevelStatistic()
	{
		SvrMonsterCount = 0;
		SvrBossType = 0;
		SvrMonsterAtkMAX = 0;
		SvrMonsterSkillMAX = 0;
		SvrMonsterHpMax = 0;
		SvrMonsterHpMin = (uint)(-1);
		SvrBossAtkMAX = 0;
		SvrBossSkillMAX = 0;
		SvrBossHpMax = 0;
		SvrBossHpMin = (uint)(-1);
	}

	void Check()
	{
		if (SvrBossHpMin == (uint)(-1))
		{
			SvrBossHpMin = 0;
		}
		if (SvrMonsterHpMin == (uint)(-1))
		{
			SvrMonsterHpMin = 0;
		}
	}

	int SvrMonsterCount;       	///> ���ؿ����õĹ�������������С�ֺ�boss��" 
	int SvrBossType;			///> ������BOSS���,���BOSS,����¼����BOSS"		
	int SvrMonsterAtkMAX;		///> ���ؿ����õ�С�ֹ��������ֵ" 
	int SvrMonsterSkillMAX;    	///> ���ؿ����õ�С�ּ����˺����ֵ" 		
	int SvrMonsterHpMax;		///> ���ؿ����õ�С������ֵ���ֵ" 
	int SvrMonsterHpMin;		///> ���ؿ����õ�С������ֵ��Сֵ" 
	int SvrBossAtkMAX;        	///> ���ؿ����õ�BOSS���������ֵ" 
	int SvrBossSkillMAX;		///> ���ؿ����õ�boss�����˺����ֵ" 
	int SvrBossHpMax;         	///> ���ؿ����õ�Boss����ֵ���ֵ" 
	int SvrBossHpMin;         	///> ���ؿ����õ�Boss����ֵ��Сֵ"
};


class XLevelSpawnMgr:Singleton<XLevelSpawnMgr>
{
public:
	XLevelSpawnMgr();
	~XLevelSpawnMgr();
	void OnEnterScene(uint sceneid);
	bool LoadFile();

private:
	void ParseWaves();
	void ParseWave(XLevelStatistic& info, XLevelWave* wave, uint sceneid);

private:
	std::map<uint, XLevelStatistic> m_sceneid2info;
	std::map<uint, std::map<int, XLevelWave*>> m_StaticWaves;
	float _time = 0;
	XLevelSpawnInfo* _curSpawner;
};

#endif