#pragma once
#include "Mesh.h"
#include "Texture.h"
#include "Transform.h"
#include "DeviceAccessPoint.h"
class Object
{
public:
	DeviceAccessPoint* device;
	Mesh* mesh;
	Texture* texture;
	Transform* transform;
	Object() {}
	virtual void _init() = 0;
	virtual void _draw() = 0;
	virtual void _update() = 0;
};

