#ifndef  __timer__
#define  __timer__

#include "Common.h"


class ITimer
{
public:
	virtual ~ITimer() {}
	
	virtual void OnTimer(uint dwID, uint dwCount) = 0;
};



class  ITimerMgr
{
public:
	virtual	~ITimerMgr() {}

	//poTimer:		Timer�ص��ӿ�
	//dwID:			��ʱIdentifier
	//dwInterval:	��ʱ���������Ϊ��λ	
	//nCount:		��������, -1Ϊ��Զ���� 
	//����token
	virtual uint SetTimer(ITimer* pTimer, uint dwID, uint dwInterval, uint dwCount) = 0;

	virtual uint GetTimeLeft(uint token) = 0;

	virtual void KillTimer(uint token) = 0;

	virtual void Update() = 0;

	virtual void Release() = 0;
};


#endif