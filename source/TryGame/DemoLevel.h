#ifndef __DEMOLEVEL_H
#define __DEMOLEVEL_H

namespace TryGame
{
	class DemoLevel
	{
	protected:

	public:
		DemoLevel(void);
		virtual ~DemoLevel(void);

		static DemoLevel *Create();
		virtual DemoLevel *NextLevel() = 0;
		virtual DemoLevel *PrevLevel() = 0;
		virtual void Init(b2World &refPhysWorld, My2DPhys::Actor **gameElements) = 0;
		virtual int GetElementCount() const = 0;
		virtual My2DPhys::Actor *GetPlayable() const = 0;
		//virtual void ArrangeLevelChain() = 0;
	};
}

#endif // __DEMOLEVEL_H
