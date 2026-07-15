#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"
#include "../Bullet/PlayerBullet/PlayerBullet.h"

#define MOVE_SPEED		0.4f
#define JUMP_POWER		12.0f
#define BULLET_SPEED	5.0f

struct PlayerAnimParam
{
	int interval;
	int frameNum;
	int width;
	int height;
};

Player::Player()
{
	m_HP = 10;		// HP
	m_Size = 7.5;	// プレイヤーサイズ

	m_Pos = VGet(0.0f, 0.0f, 0.0f);
	m_Move = VGet(0.0f, 0.0f, 0.0f);
	
	m_isTurn = false;

	m_NowAnim = PlayerAnimationType::IDLE;

	m_BulletManager = nullptr;

	m_BulletCoolTime = 0.0f;
	m_BulletInterval = 7.0f;
}

Player::~Player()
{
}

void Player::Init()
{

}

void Player::Load()
{
	
	// IDLE
	LoadDivGraph(
		TEXT("Data/Player/Player_Idle.png"),
		1,
		1,
		1,
		256,
		256,
		m_Animation[static_cast<int>(PlayerAnimationType::IDLE)].handle);

	StartAnimation(
		&m_Animation[static_cast<int>(PlayerAnimationType::IDLE)],
		9999,
		1,
		true);

	// RUN
	LoadDivGraph(
		TEXT("Data/Player/Player_Run2.png"),
		5,
		5,
		1,
		256,
		256,
		m_Animation[static_cast<int>(PlayerAnimationType::RUN)].handle);

	StartAnimation(
		&m_Animation[static_cast<int>(PlayerAnimationType::RUN)],
		7,
		5,
		true);

	// JUMP
	LoadDivGraph(
		TEXT("Data/Player/Player_Jump.png"),
		1,
		1,
		1,
		256,
		256,
		m_Animation[static_cast<int>(PlayerAnimationType::JUMP)].handle);

	StartAnimation(
		&m_Animation[static_cast<int>(PlayerAnimationType::JUMP)],
		9999,
		1,
		true);
}

void Player::Start()
{

}

void Player::Step()
{

}

void Player::Update()
{
	m_Move.x = 0.0f;
	m_Move.y = 0.0f;
	m_Move.z = 0.0f;

	if (Input::IsInputKey(Input::KEY_RIGHT))
	{
		m_Move.x += MOVE_SPEED;
		m_isTurn = false;
	}

	if (Input::IsInputKey(Input::KEY_LEFT))
	{
		m_Move.x -= MOVE_SPEED;
		m_isTurn = true;
	}

	if (Input::IsInputKey(Input::KEY_UP))
	{
		m_Move.z += MOVE_SPEED;
	}

	if (Input::IsInputKey(Input::KEY_DOWN))
	{
		m_Move.z -= MOVE_SPEED;
	}
	if (Input::IsTriggerKey(Input::KEY_SPACE))
	{
		
	}

	m_Pos.x += m_Move.x;
	m_Pos.y += m_Move.y;
	m_Pos.z += m_Move.z;

	// アニメーション切り替え
	if (m_Move.x != 0.0f || m_Move.y != 0.0f || m_Move.z != 0.0f)
	{
		m_NowAnim = PlayerAnimationType::RUN;
	}
	else if (m_Move.y < 0)
	{
		m_NowAnim = PlayerAnimationType::JUMP;
	}
	else
	{
		m_NowAnim = PlayerAnimationType::IDLE;
	}

	// 弾発射間隔
	if (m_BulletCoolTime > 0.0f)
	{
		m_BulletCoolTime--;
	}

	if (Input::IsInputKey(Input::KEY_Z))
	{
		if (m_BulletCoolTime <= 0.0f)
		{
			PlayerBullet* bullet = new PlayerBullet();

			bullet->Load();

			if (m_isTurn)
			{
				// 左向き
				bullet->SetPos(m_Pos.x -1.0f, m_Pos.y, m_Pos.z);
				bullet->SetMove(-BULLET_SPEED, 0.0f, 0.0f);
			}
			else
			{
				// 右向き
				bullet->SetPos(m_Pos.x + 1.0f, m_Pos.y, m_Pos.z);
				bullet->SetMove(BULLET_SPEED, 0.0f, 0.0f);
			}

			m_BulletManager->AddBullet(bullet);

			m_BulletCoolTime = m_BulletInterval;
		}
		
	}

	UpdateAnimation(&m_Animation[static_cast<int>(m_NowAnim)]);
}

void Player::Draw()
{		
	AnimationData* anim = &m_Animation[static_cast<int>(m_NowAnim)];

	// 2D画像を3D空間に描画する
	DrawBillboard3D(
		m_Pos,
		0.5f,          // 画像中央(X)
		0.5f,          // 画像中央(Y)
		m_Size,        // サイズ
		0.0f,          // 回転
		GetAnimationHandle(anim),
		TRUE,
		m_isTurn,      // 左右反転
		FALSE          // 上下反転
	);
}

void Player::Fin()
{

}

void Player::SetBulletManager(BulletManager* manager)
{
	m_BulletManager = manager;
}

void Player::ChangeAnimation(PlayerAnimationType anim)
{
	if (m_NowAnim == anim)
	{
		return;
	}

	m_NowAnim = anim;

	m_Animation[static_cast<int>(anim)].nowFrame = 0;
	m_Animation[static_cast<int>(anim)].timer =
		m_Animation[static_cast<int>(anim)].interval;
}