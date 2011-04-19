#ifndef __DISTANCE_JOINT_H
#define __DISTANCE_JOINT_H

namespace My2DPhys
{
	class DistanceJoint : public JointBase
	{
	private:
		b2DistanceJointDef _distanceJointDefinition;

	public:

		DistanceJoint(void);
		~DistanceJoint(void);

		void Create(b2World &world,
			const BasicShape &joinedBody1, 
			const BasicShape &joinedBody2, 
			const b2Vec2 &anchor1, 
			const b2Vec2 &anchor2, 
			const bool collideConnected = false,
			const float length = 0.0f,
			const float frequencyHz = 0.0f,
			const float dampingRatio = 0.0f);

		const b2DistanceJoint* Joint() const;
	};
}

#endif // __DISTANCE_JOINT_H

