#pragma once
#include "PlayScene.h"
#include "../SceneManager.h"
#include "../../Input/Input.h"
#include "../../Player/PlayerManager.h"


PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
	Fin();
}

void PlayScene::Init()
{

	// プレイヤーマネージャー
	PlayerManager::CreateInstance();
	PlayerManager* playerManager = PlayerManager::GetInstance();
	// プレイヤー生成
	playerManager->CreatePlayer();
	// プレイヤー初期化
	playerManager->Init();
}

void PlayScene::Load()
{
	// プレイヤーロード
	PlayerManager::GetInstance()->Load();
}

void PlayScene::Start()
{
	// プレイヤー開始
	PlayerManager::GetInstance()->Start();
}

void PlayScene::Step()
{
	PlayerManager::GetInstance()->Step();
}

void PlayScene::Update()
{
	PlayerManager::GetInstance();
}

void PlayScene::Draw()
{
	PlayerManager::GetInstance()->Draw();
}

void PlayScene::Fin()
{
	PlayerManager::DeleteInstace();
}