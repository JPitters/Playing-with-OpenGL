#pragma once
#define _USE_MATH_DEFINES
#include "SceneNode.h"
#include "glm\glm.hpp"
#include <glm\gtx\matrix_decompose.hpp>
#include "glm\gtc\matrix_transform.hpp"
#include <vector>
#include <cmath>
#include "Square.h"

class Cube : public SceneNode
{
public:
	Cube::Cube(glm::mat4 transformation, float scale);
	void draw(float scale) override;
};
