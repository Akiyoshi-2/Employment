#pragma once
#include "DxLib.h"
#include "../Bullet/BulletManager.h"

class Player
{
public:
	Player();
	~Player();

	void Init();
	void Load();
	void Start();
	void Step();
	void Update();
	void Draw();
	void Fin();

	enum PlayerGravityDir
	{
		UP,
		DOWN,
		LEFT,
		RIGHT,
	};

	void SetBulletManager(BulletManager* manager);

	VECTOR GetPos() const { return m_Pos; }

private:
	int m_Handle;
	int m_HP;
	VECTOR m_Pos;
	VECTOR m_Move;
	float m_Size;
	bool m_isTurn;

	float m_BulletCoolTime;
	float m_BulletInterval;

	BulletManager* m_BulletManager;
};

