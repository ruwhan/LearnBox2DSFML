#include "GeneralInclude.h"
#include "QueryCallback.h"

namespace My2DPhys
{
	QueryCallback::QueryCallback(void)
	{
		_ptrTempBody = NULL;
	}


	QueryCallback::~QueryCallback(void)
	{
	}

	bool QueryCallback::ReportFixture(b2Fixture *fixture)
	{
		_ptrTempBody = fixture->GetBody();
		_ptrTempBody->SetAwake(true);

		return true;
	}
}