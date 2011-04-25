
#include "GameIncludes.h"

#include "GameController.h"


namespace TryGame
{
using namespace sfb2d;

	GameController::GameController(void) : 
		TIME_STEP(1.0f / 90.0f)
	{
		_ptrDemoLevel = NULL;
		iterationIndex = 0;
	}

	GameController::~GameController(void)
	{
	}

	void GameController::OnLoad()
	{
		b_windowApp.Create(sf::VideoMode(800, 600, 32), "Learn Box2D - SFML", sf::Style::Close);
		InitPhysicsWorld();

		//_ptrDebugDraw = new DebugDraw(&windowApp);
		//_ptrWorld->SetDebugDraw(_ptrDebugDraw);

		InitDemoLevel();
	}

	void GameController::OnLoop()
	{
		const sf::Input &input = b_windowApp.GetInput();

		if(input.IsKeyDown(sf::Key::Right))
		{
			_ptrDemoLevel->GetPlayable()->GetBody()->ApplyForce(
				b2Vec2(320.0f, 1.0f), 
				_ptrDemoLevel->GetPlayable()->GetBody()->GetWorldCenter());
		}

		if(input.IsKeyDown(sf::Key::Down))
		{
			_ptrDemoLevel->GetPlayable()->GetBody()->ApplyForce(
				b2Vec2(0.0f, 320.0f), 
				_ptrDemoLevel->GetPlayable()->GetBody()->GetWorldCenter());
		}

		if(input.IsKeyDown(sf::Key::Left))
		{
			_ptrDemoLevel->GetPlayable()->GetBody()->ApplyForce(
				b2Vec2(-320.0f, 1.0f), 
				_ptrDemoLevel->GetPlayable()->GetBody()->GetWorldCenter());
		}

		if(input.IsKeyDown(sf::Key::Up))
		{
			_ptrDemoLevel->GetPlayable()->GetBody()->ApplyForce(
				b2Vec2(0.0f, -320.0f), 
				_ptrDemoLevel->GetPlayable()->GetBody()->GetWorldCenter());
		}

		b_ptrWorld->Step(TIME_STEP, VELOCITY_ITERATION, POSITION_ITERATION);
		b_ptrWorld->ClearForces();

		b_windowApp.Clear(sf::Color::White);

		for(iterationIndex = 0; iterationIndex < _ptrDemoLevel->GetElementCount(); iterationIndex++)
		{
			_ptrGameElements[iterationIndex]->Update(b_windowApp);
			_ptrGameElements[iterationIndex]->Draw(b_windowApp);
		}

		//_ptrWorld->DrawDebugData();

		b_windowApp.Display();
	}

	void GameController::OnEvent()
	{
		if(b_sfmlEvent.Type == sf::Event::Closed)
			b_windowApp.Close();

		if(b_sfmlEvent.Type == sf::Event::KeyPressed)
		{
			if(b_sfmlEvent.Key.Code == sf::Key::Escape)
			{
				b_windowApp.Close();
			}

			if(b_sfmlEvent.Key.Code == sf::Key::Comma)	
			{
				ChangeLevel(PREV);
			}

			if(b_sfmlEvent.Key.Code == sf::Key::Period)
			{
				ChangeLevel(NEXT);
			}
		}
	}

	void GameController::OnUnload()
	{	
		if(_ptrDemoLevel != NULL)
		{
			delete _ptrDemoLevel;
			_ptrDemoLevel = NULL;
		}

		this->CleanUpPhysicsWorld();

		/*if(_ptrDebugDraw != NULL)
		{
			delete _ptrDebugDraw;
			_ptrDebugDraw = NULL;
		}*/
	}

	void GameController::InitPhysicsWorld()
	{
		b_ptrWorld = new b2World(b2Vec2(0.0f, 10.0f), true);
		_aabb.lowerBound.Set(-1.0f, -1.0f);
		_aabb.upperBound.Set(20.0f, 20.0f);
		b_ptrWorld->QueryAABB(&_queryCallback, _aabb);
	}

	void GameController::CleanUpPhysicsWorld()
	{
		if(b_ptrWorld != NULL)
		{
			delete b_ptrWorld;
			b_ptrWorld = NULL;
		}
	}

	void GameController::InitDemoLevel()
	{	
		_ptrDemoLevel = DemoTexture::Create();
		//_ptrDemoLevel = DemoPolygon::Create();
		
		_ptrGameElements = new Actor *[_ptrDemoLevel->GetElementCount()];
		
		_ptrDemoLevel->Init(*b_ptrWorld, _ptrGameElements);
	}

	void GameController::ChangeLevel(const ChangeLevelState state)
	{
		DemoLevel *ptrTempDemoL = NULL;

		// Clean Up
		CleanUpPhysicsWorld();
		InitPhysicsWorld();

		ptrTempDemoL = _ptrDemoLevel;

		if(state == NEXT)
			_ptrDemoLevel = _ptrDemoLevel->NextLevel();
		else if(state == PREV)
			_ptrDemoLevel = _ptrDemoLevel->PrevLevel();

		delete [] _ptrGameElements;

		_ptrGameElements = new Actor *[_ptrDemoLevel->GetElementCount()];

		_ptrDemoLevel->Init(*b_ptrWorld, _ptrGameElements);

		delete ptrTempDemoL;
	}
}
