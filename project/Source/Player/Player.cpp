#include "DxLib.h"
#include "Player.h"
#include "../Input/Input.h"

#define MOVE_SPEED		1.0f



Player::Player()
{
	m_Handle = 0;
	m_HP = 10;

	m_Pos.x = 0;
	m_Pos.y = 0;

	m_Move.x = 0;
	m_Move.y = 0;
	
	m_isTurn = false;
	
}

Player::~Player()
{
}

void Player::Init()
{

}

void Player::Load()
{
	m_Handle = LoadGraph("Data/Player/Player.png");
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
}

void Player::Draw()
{
	DrawGraph(m_Pos.x, m_Pos.y, m_Handle, TRUE);
}

void Player::Fin()
{

}