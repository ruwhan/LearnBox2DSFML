#ifndef __DEBUG_DRAW_H
#define __DEBUG_DRAW_H

namespace sfb2d
{
	class DebugDraw :
		public b2DebugDraw
	{
	private:
		sf::RenderWindow *_ptrWindow;
		//sf::Shape _shape;

		sf::Color ConvertColorB2dToSfml(const b2Color &color);

	public:
		DebugDraw(sf::RenderWindow *ptrWindow);
		~DebugDraw(void);

		void DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
		void DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color);
		void DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color);
		void DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color);
		void DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color);
		void DrawTransform(const b2Transform& xf);
	};
}

#endif	// __DEBUG_DRAW_H
