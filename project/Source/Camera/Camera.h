#pragma once
#include "CameraBase.h"

class Camera : public CameraBase
{
public:
	Camera();
	~Camera();

	void Init() override;
	void Load() override;
	void Start() override;
	void Step() override;

	void Update(VECTOR playerPos);

	void Update() override;
	
	void Draw() override;
	void Fin() override;

	void SetPosition(VECTOR pos);
	void SetTarget(VECTOR target);

	void Follow(VECTOR playerPos);

	VECTOR GetPosition() const;
	VECTOR GetTarget() const;

private:
	VECTOR m_Position;
	VECTOR m_Target;
};

