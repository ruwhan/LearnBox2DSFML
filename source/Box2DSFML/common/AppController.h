#ifndef __APP_CONTROLLER
#define __APP_CONTROLLER

namespace sfb2d
{
	class AppController
	{
	protected:
		sf::RenderWindow b_windowApp;
		sf::Event b_sfmlEvent;
		
		b2World *b_ptrWorld;

		// My Events
		virtual void OnLoad() = NULL;
		virtual void OnLoop() = NULL;
		virtual void OnEvent() = NULL;
		//virtual void OnRender() = NULL;
		virtual void OnUnload() = NULL;
		
	public:
		AppController(void);
		virtual ~AppController(void);

		void Execute();
	};
}

#endif // __APP_CONTROLLER

