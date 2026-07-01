#include "PlayerBullet.h"
#include "DxLib.h"

#define BULLET_OUT_X 1600
#define BULLET_OUT_Y 900

PlayerBullet::PlayerBullet()
{
   
}

PlayerBullet::~PlayerBullet()
{
}

void PlayerBullet::Init()
{
}

void PlayerBullet::Load()
{
    m_Handle = LoadGraph("Data/Bullet/PlayerBullet.png");
}

void PlayerBullet::Start()
{
}

void PlayerBullet::Step()
{
}

void PlayerBullet::Update()
{
    // 基底クラスの移動処理
    BulletBase::Update();

    // 画面外に出たら削除
    if (m_Pos.x < -64 ||
        m_Pos.x > BULLET_OUT_X + 64 ||
        m_Pos.y < -64 ||
        m_Pos.y > BULLET_OUT_Y + 64)
    {
        SetDead();
    }
}

void PlayerBullet::Draw()
{
    DrawTurnGraph((int)m_Pos.x, (int)m_Pos.y, m_Handle, TRUE);
}

void PlayerBullet::Fin()
{
}
