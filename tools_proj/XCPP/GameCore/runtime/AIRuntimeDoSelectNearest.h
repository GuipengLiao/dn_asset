/*
* <auto-generated>
*	 The code is generated by tools
*	 Edit manually this code will lead to incorrect behavior
* </auto-generated>
*/

#ifndef  __AIRuntimeDoSelectNearest__
#define  __AIRuntimeDoSelectNearest__

#include "../GameObject.h"
#include "../Vector3.h"
#include "../AIBehaviour.h"
#include "../AITreeImpleted.h"

class XEntity;

class AIRuntimeDoSelectNearest :public AIBase
{
public:
	~AIRuntimeDoSelectNearest();
	virtual void Init(AITaskData* data);
	virtual AIStatus OnTick(XEntity* entity);
	

private:
	
};

#endif