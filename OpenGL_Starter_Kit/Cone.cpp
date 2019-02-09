#include "Cone.h"



Cone::Cone(glm::mat4 aTransformation, float scale) : SceneNode(aTransformation, scale)
{

}

void Cone::draw(float scale)
{

	// Draw Sphere here using circles
	//Parent Node

	float newScale = scale/20.0f;
	Circle c = Circle(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)), newScale);
	c.render();
	
	float translation_value = scale / 10.0f;

	for (float theta = 0.0f; theta < 3.141 / 4.0f; theta += 0.01)
	{

		newScale -= 0.01; // scale * (cos(theta) - 0.1);
		translation_value -= 0.01; // scale * sin(theta);
		Circle bottom_circle = Circle(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -translation_value)), newScale);
		c.addChild(&bottom_circle);
		bottom_circle.render();


	}


}


