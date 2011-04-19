
#include "GeneralInclude.h"
#include "AppController.h"

int main()
{
	/*sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Box2D - SFML", sf::Style::Close);
	b2World physWorld(b2Vec2(0, 10), true);*/

	My2DPhys::AppController appController;
	appController.Execute();

	return EXIT_SUCCESS;
}