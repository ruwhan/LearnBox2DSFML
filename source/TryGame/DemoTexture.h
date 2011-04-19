#ifndef __DEMOTEXTURE_H
#define __DEMOTEXTURE_H

namespace TryGame
{
	class DemoTexture : public DemoLevel
	{
	private: 
		enum ELEMENTS_COUNT
		{
			STATIC_OBJECT_COUNT = 4,
			DYNAMIC_OBJECT_COUNT = 3,
			PLAYABLE_COUNT = 1
		};

		const std::string assetsDir;
		static int _elementCounter;

		My2DPhys::Sprite **_ptrBoundaries;
		My2DPhys::Sprite **_ptrBodies;
		My2DPhys::Sprite *_ptrPlayable;

		DemoLevel *_ptrNextLevel;
		DemoLevel *_ptrPrevLevel;

		void CreateStaticBodies(b2World &refPhysWorld, My2DPhys::Actor **gameElements);
		void CreateBodies(b2World &refPhysWorld, My2DPhys::Actor **gameElements);

	public:
		DemoTexture(void);
		~DemoTexture(void);

		static DemoLevel* Create();
		virtual DemoLevel* NextLevel();
		virtual DemoLevel* PrevLevel();
		virtual void Init(b2World &refPhysWorld, My2DPhys::Actor **gameElements);
		virtual int GetElementCount() const;
		virtual My2DPhys::Actor *GetPlayable() const;
	};
}

#endif //__DEMOTEXTURE_H

