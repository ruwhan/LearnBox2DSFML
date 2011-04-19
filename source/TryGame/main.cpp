
#include "GameIncludes.h"

using namespace My2DPhys;

int main()
{
	My2DPhys::AppController *ptrController = new TryGame::GameController;

	ptrController->Execute();

	delete ptrController;

	/*sf::RenderWindow window(sf::VideoMode(800, 600, 32), "Box2D - SFML", sf::Style::Close);
	b2World physWorld(b2Vec2(0, 10), true);*/

	return EXIT_SUCCESS;
}