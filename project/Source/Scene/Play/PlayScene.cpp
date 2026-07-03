#pragma once
#include "PlayScene.h"
#include "../SceneManager.h"
#include "../../Input/Input.h"
#include "../../Player/Player.h"
#include "../../Player/PlayerManager.h"
#include "../../Bullet/BulletManager.h"
#include "../../Camera/CameraManager.h"
#include "../../Camera/FollowCamera.h"


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

	playerManager->CreatePlayer();
	playerManager->Init();

	// カメラマネージャー
	CameraManager::CreateInstance();
	CameraManager::GetInstance()->CreateCamera(FOLLOW_CAMERA);
	CameraManager::GetInstance()->Init();

	// バレットマネージャー
	BulletManager::CreateInstance();
	BulletManager::GetInstance()->Init();

	playerManager->GetPlayer()->SetBulletManager(BulletManager::GetInstance());
}

void PlayScene::Load()
{
	// プレイヤーロード
	PlayerManager::GetInstance()->Load();
	// カメラロード
	CameraManager::GetInstance()->Load();
	// バレットロード
	BulletManager::GetInstance()->Load();
}

void PlayScene::Start()
{
	// プレイヤー開始
	PlayerManager::GetInstance()->Start();
	// カメラ開始
	CameraManager::GetInstance()->Start();
	// バレット開始
	BulletManager::GetInstance()->Start();
}

void PlayScene::Step()
{
	// プレイヤーステップ
	PlayerManager::GetInstance()->Step();
	// カメラステップ
	CameraManager::GetInstance()->Step();
	// バレットステップ
	BulletManager::GetInstance()->Step();
}

void PlayScene::Update()
{
	// プレイヤー更新
	PlayerManager::GetInstance()->Update();
	// カメラ
	FollowCamera* camera = dynamic_cast<FollowCamera*>(
		CameraManager::GetInstance()->GetCamera(FOLLOW_CAMERA));

	if (camera)
	{
		camera->SetTargetPos(PlayerManager::GetInstance()->GetPlayer()->GetPos());
	}

	CameraManager::GetInstance()->Update();
	
	// バレット更新
	BulletManager::GetInstance()->Update();
}

void PlayScene::Draw()
{
	// プレイヤー描画
	PlayerManager::GetInstance()->Draw();
	// カメラ描画
	CameraManager::GetInstance()->Draw();
	// バレット描画
	BulletManager::GetInstance()->Draw();
}

void PlayScene::Fin()
{
	// プレイヤー終了
	PlayerManager::DeleteInstace();
	// カメラ終了
	CameraManager::DeleteInstance();
	// バレット終了
	BulletManager::DeleteInstance();
}