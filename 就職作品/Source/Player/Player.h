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

private:
	int m_Handle;
	VECTOR m_Pos;
	VECTOR m_Move;

	int m_HP;
	int m_DeadTimer;
	bool IsDead;

	bool isRespawn;

	bool active;
	bool isTurn;
	bool isAir;
	bool gravityDir;


};

