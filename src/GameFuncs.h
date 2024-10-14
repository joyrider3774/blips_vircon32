#ifndef GAMEFUNCS_H
#define GAMEFUNCS_H

#include "Texture.h"
#include "libs/DrawPrimitives/draw_primitives.h"
#include "Common.h"
#include "GameFuncs.h"
#include "CInput.h"
#include "fonts/font_13.h"
#include "fonts/font1_25.h"
#include "fonts/font2_30.h"
#include "CAudio.h"


void UnLoadGraphics()
{
    freeTexture(IMGGrid);
    freeTexture(IMGWall);
	freeTexture(IMGBackground);
	freeTexture(IMGFloor);
	freeTexture(IMGPlayer);
	freeTexture(IMGBox);
	freeTexture(IMGEmpty);
	freeTexture(IMGDiamond);
	freeTexture(IMGBomb);
	freeTexture(IMGTitleScreen);
	freeTexture(IMGIntro1);
	freeTexture(IMGIntro2);
	freeTexture(IMGIntro3);
	freeTexture(IMGExplosion);
}


void LoadSounds()
{
	CAudio_Init();
	CAudio_SetSoundEnabled(true);
	CAudio_SetMusicEnabled(true);
	Music = CAudio_LoadMusic("title");		
	Sounds[SND_MENU] = CAudio_LoadSound("menu");
	Sounds[SND_SELECT] = CAudio_LoadSound("select");
	Sounds[SND_ERROR] = CAudio_LoadSound("error");
	Sounds[SND_STAGEEND] = CAudio_LoadSound("stageend");
	Sounds[SND_EXPLODE] = CAudio_LoadSound("explode");
	Sounds[SND_COLLECT] = CAudio_LoadSound("collect");
}

void UnloadSounds()
{
	CAudio_UnloadSounds();
	CAudio_UnloadMusics();
	CAudio_DeInit();
}

void FindLevels()
{
	InstalledLevels = 0;
	if(strcmp(LevelPackName, "Bips") == 0)
		InstalledLevels = 26;
}

void WriteText(textfont* font, int* text, int x, int y, int color)
{
	if(!font)
		return;

	if(*text == 0)
		return;

	set_multiply_color(color);
	textfont_print_from_left(font, x, y, text);
	set_multiply_color(color_white);
}

void loadFonts()
{
	setupFontfont_13();
	setupFontfont1_25();
	setupFontfont2_30();
	font = &Fontfont_13;
	BigFont = &Fontfont2_30;
	MonoFont = &Fontfont1_25;
}

void SaveUnlockData()
{
	// FILE *Fp;
	// int Teller;
	// int Filename[FILENAME_MAX];
	// int LevelHash[4];
	// int HashBuffer[64];
	// int CheckSum = 0;
	// LevelHash[0] = HashTable[UnlockedLevels-1] ;
	// LevelHash[1] = HashTable[UnlockedLevels];
	// LevelHash[2] = HashTable[UnlockedLevels+1];
	// LevelHash[3] = HashTable[UnlockedLevels+2];
	// sprintf(Filename,"./%s.dat",LevelPackFileName);
	// for (Teller=0;Teller<4;Teller++)
	// 	LevelHash[Teller] = LevelHash[Teller] ^ LevelPackFileName[strlen(LevelPackFileName)-1];
	// for (Teller=0;Teller<(size_t)strlen(LevelPackFileName);Teller++)
	// 	LevelHash[Teller%4] = LevelHash[Teller%4] ^ LevelPackFileName[Teller];
	// LevelHash[0] = LevelHash[0] ^ LevelHash[2];
	// LevelHash[1] = LevelHash[1] ^ LevelHash[0];
	// LevelHash[2] = LevelHash[2] ^ LevelHash[3];
	// LevelHash[3] = LevelHash[3] ^ LevelHash[2];
	// for (Teller=0;Teller<64;Teller++)
	// 	if ((Teller+1) % 16 == 0)
	// 	{
	// 		HashBuffer[Teller] = LevelHash[(Teller)/16];
	// 		CheckSum += HashBuffer[Teller];
	// 	}
	// 	else
	// 	{
	// 		HashBuffer[Teller] = rand() % 256;
	// 		CheckSum += HashBuffer[Teller];
	// 	}
	// CheckSum = CheckSum ^ 50;
	// Fp = fopen(Filename,"wb");
	// if (Fp)
	// {
	// 	fwrite(HashBuffer,1,64,Fp);
	// 	fwrite(&CheckSum,sizeof(int),1,Fp);
	// 	fclose(Fp);
	// }
}

void LoadUnlockData()
{
	// FILE *Fp;
	// int LevelHash[4];
	// int Teller=0;
	// int HashBuffer[64];
	// int Filename[FILENAME_MAX];
	// sprintf(Filename,"./%s.dat",LevelPackFileName);
	// Fp = fopen(Filename,"rb");
	// int CheckSum,ValidCheckSum=0;
	// if (Fp)
	// {
	// 	fflush(Fp);
	// 	fread(HashBuffer,1,64,Fp);
	// 	fread(&CheckSum,sizeof(int),1,Fp);
	// 	fclose(Fp);
	// 	for (Teller = 0 ;Teller<64;Teller++)
	// 	{
	// 		ValidCheckSum += HashBuffer[Teller];
	// 		if ((Teller+1)%16 == 0)
	// 			LevelHash[Teller/16] = HashBuffer[Teller];
	// 	}
	// 	CheckSum = CheckSum ^ 50;
	// 	if (CheckSum == ValidCheckSum)
	// 	{
	// 		LevelHash[3] = LevelHash[3] ^ LevelHash[2];
	// 		LevelHash[2] = LevelHash[2] ^ LevelHash[3];
	// 		LevelHash[1] = LevelHash[1] ^ LevelHash[0];
	// 		LevelHash[0] = LevelHash[0] ^ LevelHash[2];
	// 		for (Teller=0;Teller<(int)strlen(LevelPackFileName);Teller++)
	// 			LevelHash[Teller%4] = LevelHash[Teller%4] ^ LevelPackFileName[Teller];
	// 		for (Teller=0;Teller<4;Teller++)
	// 			LevelHash[Teller] = LevelHash[Teller] ^ LevelPackFileName[strlen(LevelPackFileName)-1];

	// 		Teller=0;
	// 		while (LevelHash[0] != HashTable[Teller] || LevelHash[1] != HashTable[Teller+1] || 	LevelHash[2] != HashTable[Teller+2] || LevelHash[3] != HashTable[Teller+3] && Teller+3 < 1004)
	// 			Teller++;
	// 		if (Teller < InstalledLevels)
	// 			UnlockedLevels = Teller+1;
	// 		else
	// 			UnlockedLevels = 1;
	// 	}
	// 	else
	// 		UnlockedLevels = 1;
	// }
	// else
	//  	UnlockedLevels = 1;
	UnlockedLevels = 1;

}

bool AskQuestion(int *Msg)
{
	CInput *Input = CInput_Create(InputDelay);
	while(CInput_HasInput(Input))
		end_frame();
	set_multiply_color(MenuBoxColor);
	draw_filled_rectangle(60*UI_WIDTH_SCALE,80*UI_HEIGHT_SCALE,260*UI_WIDTH_SCALE,160*UI_HEIGHT_SCALE);
	set_multiply_color(MenuBoxBorderColor);
	draw_rectangle(60*UI_WIDTH_SCALE,80*UI_HEIGHT_SCALE,260*UI_WIDTH_SCALE,160*UI_HEIGHT_SCALE);
	draw_rectangle(61*UI_WIDTH_SCALE,81*UI_HEIGHT_SCALE,259*UI_WIDTH_SCALE,159*UI_HEIGHT_SCALE);
	set_multiply_color(color_white);
	WriteText(font,Msg,65*UI_WIDTH_SCALE,83*UI_HEIGHT_SCALE,MenuTextColor);
	end_frame();
	{
		//BUT_A BUT_X
		while (!( Input->JoystickHeld[BUT_A] ||  Input->JoystickHeld[BUT_X] || Input->JoystickHeld[BUT_START]))
		{
		    CInput_Update(Input);
			end_frame();
		}
		//BUT_A
		if (Input->JoystickHeld[BUT_A] || Input->JoystickHeld[BUT_START])
			return true;
		else
			return false;

	}
	CInput_Destroy(Input);
}

void PrintForm(int *msg)
{
    CInput *Input = CInput_Create(InputDelay);
	while(CInput_HasInput(Input))
		end_frame();
	set_multiply_color(MenuBoxColor);
	draw_filled_rectangle(60*UI_WIDTH_SCALE,80*UI_HEIGHT_SCALE,260*UI_WIDTH_SCALE,160*UI_HEIGHT_SCALE);
	set_multiply_color(MenuBoxBorderColor);
	draw_rectangle(60*UI_WIDTH_SCALE,80*UI_HEIGHT_SCALE,260*UI_WIDTH_SCALE,160*UI_HEIGHT_SCALE);
	draw_rectangle(61*UI_WIDTH_SCALE,81*UI_HEIGHT_SCALE,259*UI_WIDTH_SCALE,159*UI_HEIGHT_SCALE);
	set_multiply_color(color_white);
	WriteText(font,msg,65*UI_WIDTH_SCALE,83*UI_HEIGHT_SCALE,MenuTextColor);
    end_frame();
	//BUT_A
    while (!( Input->JoystickHeld[BUT_A] || Input->JoystickHeld[BUT_START]))
    {
        CInput_Update(Input);
        end_frame();
    }

	CInput_Destroy(Input);
}

void SearchForLevelPacks()
{
	InstalledLevelPacksCount = 1;
	strcpy(&InstalledLevelPacks[0][0], "Bips");
	SelectedLevelPack=0;
	if (InstalledLevelPacksCount > 0)
	{
	 	strcpy(LevelPackName ,InstalledLevelPacks[SelectedLevelPack]);
	}
}

void LoadGraphics()
{
    IMGBackground = newTextureHorz(0,0,1,0,0,640,360,1.0,1.0);
	IMGGrid = newTextureHorz(0,1,1,0,360,640,360,1.0,1.0);
	IMGFloor = newTextureHorz(0,2,1,128,720,32,32,1.0,1.0);
	IMGWall = newTextureHorz(0,3,1,160,720,32,32,1.0,1.0);
	IMGBomb = newTextureHorz(0,4,1,0,720,32,32,1.0,1.0);
	IMGDiamond = newTextureHorz(0,5,1,64,720,32,32,1.0,1.0);
	IMGBox = newTextureHorz(0,6,1,32,720,32,32,1.0,1.0);
	IMGEmpty = newTextureHorz(0,7,1,96,720,32,32,1.0,1.0);
	IMGPlayer = newTextureHorz(0,8,16,0,752,16*32,32,1.0,1.0);
	IMGExplosion = newTextureHorz(0,40,8,192,720,8*32,32,1.0,1.0);
    IMGIntro1 = newTextureHorz(1,1,1,0,0,640,360,1.0,1.0);
	IMGIntro2 = newTextureHorz(1,2,1,0,360,640,360,1.0,1.0);
	IMGIntro3 = newTextureHorz(2,1,1,0,0,640,360,1.0,1.0);
	IMGTitleScreen = newTextureHorz(2,2,1,0,360,640,360,1.0,1.0);
}


#endif