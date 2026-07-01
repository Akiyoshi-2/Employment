#include "Camera.h"
#include "../Player/Player.h"
#include "../Player/PlayerManager.h"

#define CAMERA_NEAR_CLIP 0.01f
#define CAMERA_FAR_CLIP 1000.0f

Camera::Camera()
{
	m_Position = VGet(0.0f, 0.0f, -20.0f);
	m_Target = VGet(0.0f, 20.0f, 0.0f);
}

Camera::~Camera()
{
}

void Camera::Init()
{
	SetCameraNearFar(CAMERA_NEAR_CLIP, CAMERA_FAR_CLIP);

	SetCameraPositionAndTarget_UpVecY(m_Position, m_Target);
}

void Camera::Load()
{

}
void Camera::Start()
{

}

void Camera::Step()
{

}

void Camera::Update()
{
	SetCameraPositionAndTarget_UpVecY(m_Position, m_Target);
}

void Camera::Draw()
{

}

void Camera::Fin()
{

}

void Camera::SetPosition(VECTOR pos)
{
	m_Position = pos;
}

void Camera::SetTarget(VECTOR target)
{
	m_Target = target;
}

VECTOR Camera::GetPosition() const
{
	return m_Position;
}

VECTOR Camera::GetTarget() const
{
	return m_Target;
}