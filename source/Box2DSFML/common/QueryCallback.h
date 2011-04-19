#ifndef __QUERY_CALLBACK_H
#define __QUERY_CALLBACK_H

namespace My2DPhys
{
	class QueryCallback : public b2QueryCallback
	{
	private:
		b2Body *_ptrTempBody;

	public:
		QueryCallback(void);
		~QueryCallback(void);

		bool ReportFixture(b2Fixture *fixture);
	};
}

#endif // __QUERY_CALLBACK_H
