#ifndef __PRISMATIC_JOINT_H
#define __PRISMATIC_JOINT_H

namespace My2DPhys
{
	class PrismaticJoint : public JointBase
	{
	private:
		b2PrismaticJointDef _prismaticJointDefinition;

	public:
		PrismaticJoint(void);
		~PrismaticJoint(void);

		void Create(b2World &world,
			const BasicShape &joinedBody1,
			const BasicShape &joinedBody2,
			const b2Vec2 &anchor1,
			const b2Vec2 &anchor2,
			const bool collideConnected = false,
			const float lowerTranslation = 0.0f,
			const float upperTranslation = 0.0f,
			const bool enableLimit = false,
			const float maxMotorTorque = 1.0f,
			const float motorSpeed = 0.0f,
			const bool enableMotor = false,
			const b2Vec2 &localTranslationBody1 = b2Vec2(0.0f, 0.0f));

		const b2PrismaticJoint* Joint() const;
	};
}

#endif // __PRISMATIC_JOINT_H