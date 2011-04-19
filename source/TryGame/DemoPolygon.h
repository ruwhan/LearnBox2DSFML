#ifndef __DEMO_POLYGON_H
#define __DEMO_POLYGON_H

namespace TryGame
{
	class DemoPolygon : public DemoLevel
	{
	private:
		enum elementCount
		{
			GROUND_ELEMENT_COUNT = 4,
		};

		static int _elementCounter;

		My2DPhys::BasicShape **_ptrGround;

	public:
		DemoPolygon(void);
		~DemoPolygon(void);

		static DemoLevel* Create();
		virtual DemoLevel* NextLevel();
		virtual DemoLevel* PrevLevel();
		virtual void Init(b2World &refPhysWorld, My2DPhys::Actor **gameElements);
		virtual int GetElementCount() const;
		virtual My2DPhys::Actor *GetPlayable() const;
	};
}

#endif // __DEMO_POLYGON_H
