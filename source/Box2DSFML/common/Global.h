#ifndef __GLOBAL_H
#define __GLOBAL_H

namespace sfb2d
{
	typedef sf::Vector2f Point2f;
	typedef b2Vec2 Vector2f;

	const float PIXELS_PER_METER = 8.0f;
	const float METERS_PER_PIXEL = 1.0f / PIXELS_PER_METER;
	const float DEG_TO_RAD = b2_pi / 180.0f;
	const float RAD_TO_DEG = 180.0f / b2_pi;
}

#endif // __GLOBAL_H