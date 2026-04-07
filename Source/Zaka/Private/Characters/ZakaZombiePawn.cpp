// Copyright Zaka Project. All Rights Reserved.

#include "Characters/ZakaZombiePawn.h"

AZakaZombiePawn::AZakaZombiePawn()
{
	// 월드 배치 또는 스폰 시 AI 컨트롤러 자동 할당
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
}
