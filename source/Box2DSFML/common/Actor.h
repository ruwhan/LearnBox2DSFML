#ifndef __ACTOR_H
#define __ACTOR_H

namespace My2DPhys
{
	class Actor
	{
	protected:

	public:
		Actor(void);
		virtual ~Actor(void);

		virtual b2Body *GetBody() const = 0;
		virtual void Update(sf::RenderWindow &window) = NULL;
		virtual void Draw(sf::RenderWindow &window) = NULL;
	};
}

#endif //__ACTOR_H

