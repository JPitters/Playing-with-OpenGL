#include "Cylinder.h"



Cylinder::Cylinder(glm::mat4 aTransformation, float scale) : SceneNode(aTransformation, scale)
{

}

void Cylinder::draw(float scale)
{

	// Draw Sphere here using circles
	//Parent Node
	Circle c = Circle(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)), scale);
	c.render();

	float start = scale / 50;

	for (float theta = 0.0f; theta <= scale; theta += (scale / 50))
	{
		float translation_value = start;
		Circle cir = Circle(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, translation_value)), scale);
		c.addChild(&cir);
		cir.render();

		start += (scale / 25);

	}


}


