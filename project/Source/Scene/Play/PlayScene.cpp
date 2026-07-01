#pragma once
#include "PlayScene.h"
#include "../SceneManager.h"
#include "../../Input/Input.h"
#include "../../Player/Player.h"
#include "../../Player/PlayerManager.h"
#include "../../Bullet/BulletManager.h"


PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
	Fin();
}

void PlayScene::Init()
{
	PlayerManager::CreateInstance();
	PlayerManager* playerManager = PlayerManager::GetInstance();

	playerManager->CreatePlayer();
	playerManager->Init();

	BulletManager::CreateInstance();
	BulletManager::GetInstance()->Init();

	playerManager->GetPlayer()->SetBulletManager(BulletManager::GetInstance());
}

void PlayScene::Load()
{
	// プレイヤーロード
	PlayerManager::GetInstance()->Load();
	// バレットロード
	BulletManager::GetInstance()->Load();
}

void PlayScene::Start()
{
	// プレイヤー開始
	PlayerManager::GetInstance()->Start();
	// バレット開始
	BulletManager::GetInstance()->Start();
}

void PlayScene::Step()
{
	PlayerManager::GetInstance()->Step();
	BulletManager::GetInstance()->Step();
}

void PlayScene::Update()
{
	PlayerManager::GetInstance()->Update();
	BulletManager::GetInstance()->Update();
}

void PlayScene::Draw()
{
	PlayerManager::GetInstance()->Draw();
	BulletManager::GetInstance()->Draw();
}

void PlayScene::Fin()
{
	PlayerManager::DeleteInstace();
	BulletManager::DeleteInstance();
}