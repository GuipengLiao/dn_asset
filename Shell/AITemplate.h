/*
* <auto-generated>
*	 The code is generated by tools
*	 Edit manually this code will lead to incorrect behavior
* </auto-generated>
*/

#ifndef  __AIRuntime[*Name*]__
#define  __AIRuntime[*Name*]__

#include "../GameObject.h"
#include "../Vector3.h"
#include "../AIBehaviour.h"
#include "../AITreeImpleted.h"

class XEntity;

class AIRuntime[*Name*] :public AIBase
{
public:
	~AIRuntime[*Name*]();
	virtual void Init(AITaskData* data);
	virtual AIStatus OnTick(XEntity* entity);
	

private:
	[*Arg*]
};

#endif