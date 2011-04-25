#include "GeneralInclude.h"

#include "DebugDraw.h"

namespace sfb2d
{
	DebugDraw::DebugDraw(sf::RenderWindow *ptrWindow)
	{
		this->_ptrWindow = ptrWindow;
	}

	DebugDraw::~DebugDraw(void)
	{
	}

	sf::Color DebugDraw::ConvertColorB2dToSfml(const b2Color &color)
	{
		return sf::Color((int)color.r * 255, (int)color.g * 255, (int)color.b * 255);
	}

	void DebugDraw::DrawPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
	{
		sf::Shape poly;

		for(int32 i = 0; i < vertexCount; i++)
		{
			poly.AddPoint(
				vertices[i].x * PIXELS_PER_METER, 
				vertices[i].y * PIXELS_PER_METER, 
				sf::Color(0, 0, 0, 0), 
				ConvertColorB2dToSfml(color));
		}

		_ptrWindow->Draw(poly);
	}
	void DebugDraw::DrawSolidPolygon(const b2Vec2* vertices, int32 vertexCount, const b2Color& color)
	{
		sf::Shape poly;

		for(int32 i = 0; i < vertexCount; i++)
		{
			poly.AddPoint(
				vertices[i].x * PIXELS_PER_METER, 
				vertices[i].y * PIXELS_PER_METER, 
				ConvertColorB2dToSfml(color));
		}

		_ptrWindow->Draw(poly);
	}
	void DebugDraw::DrawCircle(const b2Vec2& center, float32 radius, const b2Color& color)
	{
		sf::Shape circle = sf::Shape::Circle(
			center.x * PIXELS_PER_METER, 
			center.y * PIXELS_PER_METER, 
			radius * PIXELS_PER_METER,
			sf::Color(0, 0, 0, 0),
			1.0f,
			ConvertColorB2dToSfml(color));

		_ptrWindow->Draw(circle);
	}
	void DebugDraw::DrawSolidCircle(const b2Vec2& center, float32 radius, const b2Vec2& axis, const b2Color& color)
	{
		sf::Shape circle = sf::Shape::Circle(
			center.x * PIXELS_PER_METER, 
			center.y * PIXELS_PER_METER,
			radius * PIXELS_PER_METER,
			ConvertColorB2dToSfml(color),
			1.0f);

		_ptrWindow->Draw(circle);
	}
	void DebugDraw::DrawSegment(const b2Vec2& p1, const b2Vec2& p2, const b2Color& color)
	{
	}
	void DebugDraw::DrawTransform(const b2Transform& xf)
	{
	}
}
