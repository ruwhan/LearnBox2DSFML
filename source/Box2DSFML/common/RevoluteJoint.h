#ifndef __REVOLUTE_JOINT_H
#define __REVOLUTE_JOINT_H

namespace sfb2d
{
	class RevoluteJoint : public JointBase
	{
	private: 
		b2RevoluteJointDef _revoluteJointDefinition;

	public:
		RevoluteJoint(void);
		~RevoluteJoint(void);

		void Create(b2World &world,
			const BasicShape &joinedBody1,
			const BasicShape &joinedBody2,
			const b2Vec2 &anchor1,
			const b2Vec2 &anchor2,
			const bool collideConnected = false,
			const float lowerAngle = 0.0f,
			const float upperAngle = 0.0f,
			const bool enableLimit = false,
			const float maxMotorTorque = 1.0f,
			const float motorSpeed = 0.0f,
			const bool enableMotor = false,
			const float referenceAngle = 0.0f);

		const b2RevoluteJoint* Joint() const;
	};
}

#endif // __REVOLUTE_JOINT_H
