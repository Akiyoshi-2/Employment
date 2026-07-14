#pragma once
#include "DxLib.h"

// âºè∞ÉNÉâÉX
class Floor
{
public:
	Floor();
	~Floor();

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
};
