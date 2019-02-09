#include "Cube.h"



Cube::Cube(glm::mat4 aTransformation, float scale) : SceneNode(aTransformation, scale)
{

}

void Cube::draw(float scale)
{

	// Draw Sphere here using circles
	//Parent Node
	Square c = Square(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)), scale);
	c.render();
	
	float start = scale / 50;
	
	for (float theta = 0.0f; theta <= scale; theta += (scale/50))
	{
		float translation_value = start;
		Square sqr = Square(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, translation_value)), scale);
		c.addChild(&sqr);
		sqr.render();
		
		start += (scale / 100);

	}


}


