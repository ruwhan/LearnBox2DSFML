
#include "GeneralInclude.h"

#include "AppController.h"


namespace My2DPhys
{
	AppController::AppController(void)
	{
		b_ptrWorld = NULL;
	}

	AppController::~AppController(void)
	{
		if(b_ptrWorld != NULL)
		{
			delete b_ptrWorld;
			b_ptrWorld = NULL;
		}
	}

	void AppController::Execute()
	{
		OnLoad();

		while(b_windowApp.IsOpened())
		{
			while(b_windowApp.GetEvent(b_sfmlEvent))
			{
				OnEvent();
			}

			OnLoop();
		}

		OnUnload();
	}
}
