#ifndef __QUERY_CALLBACK_H
#define __QUERY_CALLBACK_H

namespace sfb2d
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
