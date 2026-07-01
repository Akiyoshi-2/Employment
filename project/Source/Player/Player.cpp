#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"
#include "../Bullet/PlayerBullet/PlayerBullet.h"

#define MOVE_SPEED		3.0f



Player::Player()
{
	m_Handle = 0;			// 画像ハンドル
	m_HP = 10;				// HP
	m_Size = 50.0;			// プレイヤーサイズ

	m_Pos.x = 0;			// X座標
	m_Pos.y = 0;			// Y座標
	m_Pos.z = 0;			// Z座標

	m_Move.x = 0;			// X移動量
	m_Move.y = 0;			// Y移動量
	m_Move.z = 0;			// Z移動量
	
	m_isTurn = false;		// 

	m_BulletManager = nullptr;

	m_BulletCoolTime = 0.0f;
	m_BulletInterval = 10.0f;
}

Player::~Player()
{
}

void Player::Init()
{

}

void Player::Load()
{
	m_Handle = LoadGraph("Data/Player/仮Player.png");
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
		m_Move.y -= MOVE_SPEED;
	}

	if (Input::IsInputKey(Input::KEY_DOWN))
	{
		m_Move.y += MOVE_SPEED;
	}

	m_Pos.x += m_Move.x;
	m_Pos.y += m_Move.y;

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
				bullet->SetPos(m_Pos.x - 20, m_Pos.y - 7);
				bullet->SetMove(-10.0f, 0.0f);
			}
			else
			{
				// 右向き
				bullet->SetPos(m_Pos.x + 5, m_Pos.y - 7);
				bullet->SetMove(10.0f, 0.0f);
			}

			m_BulletManager->AddBullet(bullet);

			m_BulletCoolTime = m_BulletInterval;
		}
		
	}
}

void Player::Draw()
{	
	DrawRotaGraph(m_Pos.x, m_Pos.y, 1.0, 0.0, m_Handle, TRUE, m_isTurn );
	// 2D画像を3D空間に描画する
}

void Player::Fin()
{

}

void Player::SetBulletManager(BulletManager* manager)
{
	m_BulletManager = manager;
}