// Copyright Zaka Project. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "ZakaPlayerController.generated.h"

/**
 * AZakaPlayerController
 * 
 * 플레이어 전용 컨트롤러.
 * 향후 UI, 인벤토리, 인터랙션 시스템의 진입점으로 확장 예정.
 */
UCLASS()
class ZAKA_API AZakaPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AZakaPlayerController();
};
