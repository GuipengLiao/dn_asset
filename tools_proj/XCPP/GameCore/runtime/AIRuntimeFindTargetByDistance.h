/*
* <auto-generated>
*	 The code is generated by tools
*	 Edit manually this code will lead to incorrect behavior
* </auto-generated>
*/

#ifndef  __AIRuntimeFindTargetByDistance__
#define  __AIRuntimeFindTargetByDistance__

#include "../GameObject.h"
#include "../Vector3.h"
#include "../AIBehaviour.h"
#include "../AITreeImpleted.h"

class XEntity;

class AIRuntimeFindTargetByDistance :public AIBase
{
public:
	~AIRuntimeFindTargetByDistance();
	virtual void Init(AITaskData* data);
	virtual AIStatus OnTick(XEntity* entity);
	

private:
	float floatmAIArgDistance;
	float SinglemAIArgAngle;
	
};

#endif