#ifndef __GAME_CONTROLLER
#define __GAME_CONTROLLER

namespace TryGame
{
	using namespace My2DPhys;

	class GameController : public My2DPhys::AppController
	{
	private:

		enum CONSTANTS_INT
		{
			VELOCITY_ITERATION = 10,
			POSITION_ITERATION = 10,
		};

		enum ChangeLevelState
		{
			PREV,
			NEXT
		};

		const float TIME_STEP;		
		int iterationIndex;
		
		//DebugDraw *_ptrDebugDraw;
		QueryCallback _queryCallback;
		b2AABB _aabb;

		TryGame::DemoLevel *_ptrDemoLevel;
		My2DPhys::Actor **_ptrGameElements;

		// My Events
		virtual void OnLoad();
		virtual void OnLoop();
		virtual void OnEvent();
		//void OnRender();
		virtual void OnUnload();
		
		void InitPhysicsWorld();
		void CleanUpPhysicsWorld();
		void InitDemoLevel();
		void ChangeLevel(const ChangeLevelState state);

	public:
		GameController(void);
		~GameController(void);
	};
}

#endif // __GAME_CONTROLLER

