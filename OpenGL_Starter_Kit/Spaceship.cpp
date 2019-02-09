#include "Spaceship.h"



Spaceship::Spaceship(glm::mat4 aTransformation, float scale) : SceneNode(aTransformation, scale)
{

}

void Spaceship::draw(float scale)
{
	// Draw Sphere here using circles
	//Parent Node
	float body_offset = 1.0f;
	Cylinder body = Cylinder(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, body_offset)), scale);


	float tail_offset = scale / 2.0f;
	float head_offset = scale * 2.0f;
	//Sphere wtr = Sphere(glm::translate(glm::mat4(1.0f), glm::vec3(-wheel_offset, wheel_offset, 0)), scale / 5.0f);
	//Sphere wtl = Sphere(glm::translate(glm::mat4(1.0f), glm::vec3(wheel_offset, wheel_offset, 0)), scale / 5.0f);
	//Sphere wbr = Sphere(glm::translate(glm::mat4(1.0f), glm::vec3(-wheel_offset, wheel_offset, 0)), scale / 5.0f);
	//Sphere wbl = Sphere(glm::translate(glm::mat4(1.0f), glm::vec3(wheel_offset, -wheel_offset, 0)), scale / 5.0f);

	Sphere head = Sphere(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, head_offset)), scale);
	Cone tail = Cone(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -0.7)), scale);

	body.addChild(&head);
	body.addChild(&tail);
	//body.addChild(&wbr);
	//body.addChild(&wbl);

	body.render();
	






}


