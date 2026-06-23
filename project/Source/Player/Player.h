#pragma once
#include "DxLib.h"

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

private:
	int m_Handle;
	VECTOR m_Pos;
	VECTOR m_Move;

	int m_HP;

	bool m_isTurn;
};

