#include "Tank_Group.h"



Tank_Group::Tank_Group(glm::mat4 aTransformation, float scale) : SceneNode(aTransformation, scale)
{

}

void Tank_Group::draw(float scale)
{
	Square body = Square(glm::mat4(1.0f), scale);
	body.setColor(r, g, b);


	float tank_offset = scale / 4.0f;
	Tank w1 = Tank(glm::translate(glm::mat4(1.0), glm::vec3(-tank_offset, -tank_offset, 0.0f)), scale / 5.0f);
	w1.setColor(r, g, b);
	Tank w2 = Tank(glm::translate(glm::mat4(1.0), glm::vec3(tank_offset, tank_offset, 0.0f)), scale / 5.0f);
	w2.setColor(r, g, b);
	Tank w3 = Tank(glm::translate(glm::mat4(1.0), glm::vec3(-tank_offset, tank_offset, 0.0f)), scale / 5.0f);
	w3.setColor(r, g, b);
	Tank w4 = Tank(glm::translate(glm::mat4(1.0), glm::vec3(tank_offset, -tank_offset, 0.0f)), scale / 5.0f);
	w4.setColor(r, g, b);


	body.addChild(&w1);
	body.addChild(&w2);
	body.addChild(&w3);
	body.addChild(&w4);

	body.render();


}


