/*
* <auto-generated>
*	 The code is generated by tools
*	 Edit manually this code will lead to incorrect behavior
* </auto-generated>
*/

#include "AIRuntimeRotateSelf.h"


AIRuntimeRotateSelf::~AIRuntimeRotateSelf()
{
	
}

void AIRuntimeRotateSelf::Init(AITaskData* data)
{
	AIBase::Init(data);
	SinglemAIArgMax = (float)data->vars["SinglemAIArgMax"]->val.get<double>(); 
	SinglemAIArgMin = (float)data->vars["SinglemAIArgMin"]->val.get<double>(); 
	
}


AIStatus AIRuntimeRotateSelf::OnTick(XEntity* entity)
{
	
	return AITreeImpleted::RotateSelfUpdate(entity,SinglemAIArgMax,SinglemAIArgMin);
}