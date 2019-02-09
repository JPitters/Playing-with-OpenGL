#pragma once

#include "SceneNode.h"
#include "glm\glm.hpp"
#include <glm\gtx\matrix_decompose.hpp>
#include "glm\gtc\matrix_transform.hpp"
#include <vector>
#include "Square.h"
#include "Tank.h"

class Tank_Group : public SceneNode
{
public:
	Tank_Group::Tank_Group(glm::mat4 transformation, float scale);
	void draw(float scale) override;
};