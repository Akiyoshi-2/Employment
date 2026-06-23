#include "DxLib.h"

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 900

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_  HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd)
{
	ChangeWindowMode(TRUE);

	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, 32);

	if (DxLib_Init() == -1)	
	{
		return -1;
	}

	SetDrawScreen(DX_SCREEN_BACK);

	while (ProcessMessage() >= 0)
	{
		Sleep(1);

		ClearDrawScreen();

		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		ScreenFlip();
	}

	DxLib_End();

	return 0;				
}
