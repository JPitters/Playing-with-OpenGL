#pragma once
#define _USE_MATH_DEFINES
#include "SceneNode.h"
#include "glm\glm.hpp"
#include <glm\gtx\matrix_decompose.hpp>
#include "glm\gtc\matrix_transform.hpp"
#include <vector>
#include <cmath>
#include "Cube.h"
#include "Sphere.h"


class Vehicle : public SceneNode
{
public:
	Vehicle::Vehicle(glm::mat4 transformation, float scale);
	void draw(float scale) override;
};
