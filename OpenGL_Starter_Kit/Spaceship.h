#pragma once
#define _USE_MATH_DEFINES
#include "SceneNode.h"
#include "glm\glm.hpp"
#include <glm\gtx\matrix_decompose.hpp>
#include "glm\gtc\matrix_transform.hpp"
#include <vector>
#include <cmath>
#include "Cone.h"
#include "Cylinder.h"
#include "Sphere.h"


class Spaceship : public SceneNode
{
public:
	Spaceship::Spaceship(glm::mat4 transformation, float scale);
	void draw(float scale) override;
};
