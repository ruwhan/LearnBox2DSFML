#ifndef __PULLEY_JOINT_H
#define __PULLEY_JOINT_H

namespace sfb2d
{
	class PulleyJoint : public JointBase
	{
	private:
		b2PulleyJointDef _pulleyJointDefinition;

	public:
		PulleyJoint(void);
		~PulleyJoint(void);

		void Create(b2World &world,
			const BasicShape &joinedBody1,
			const BasicShape &joinedBody2,
			const b2Vec2 &bodyAnchor1,
			const b2Vec2 &bodyAnchor2,
			const b2Vec2 &groundAnchor1,
			const b2Vec2 &groundAnchor2,
			const bool collideConnected = false,
			const float maxLength1 = 1.0f,
			const float maxLength2 = 1.0f,
			const float ratio = 1.0f, 
			const float length1 = 1.0f,
			const float length2 = 1.0f);

		const b2PulleyJoint* Joint() const;
	};
}

#endif // __PULLEY_JOINT_H