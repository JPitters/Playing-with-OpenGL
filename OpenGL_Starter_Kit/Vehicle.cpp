#include "Vehicle.h"



Vehicle::Vehicle(glm::mat4 aTransformation, float scale) : SceneNode(aTransformation, scale)
{

}

void Vehicle::draw(float scale)
{

	// Draw Sphere here using circles
	//Parent Node
	Cube body = Cube(glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, 0)), scale);
	
	
	float wheel_offset = scale / 2.0f;
	Sphere wtr = Sphere(glm::translate(glm::mat4(1.0f), glm::vec3(-wheel_offset, wheel_offset, 0)), scale/5.0f);
	Sphere wtl = Sphere(glm::translate(glm::mat4(1.0f), glm::vec3(wheel_offset, wheel_offset, 0)), scale / 5.0f);
	Sphere wbr = Sphere(glm::translate(glm::mat4(1.0f), glm::vec3(-wheel_offset, wheel_offset, 0)), scale / 5.0f);
	Sphere wbl = Sphere(glm::translate(glm::mat4(1.0f), glm::vec3(wheel_offset, -wheel_offset, 0)), scale / 5.0f);

	body.addChild(&wtr);
	body.addChild(&wtl);
	body.addChild(&wbr);
	body.addChild(&wbl);

	body.render();
}


