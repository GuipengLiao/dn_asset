#ifndef  __Transform__
#define  __Transform__

#include "Vector3.h"
class  GameObject;

class Transform
{
public:
	Transform(const char* nm);
	~Transform();
	
	Vector3 position;
	Vector3 scale;
	Vector3 rotation;
	Vector3 forward;
	Transform* parent;
	const char* name;
	GameObject* gameObject;

	Transform* Find(const char* name);
};


#endif