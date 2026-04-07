// Copyright Zaka Project. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/ZakaBasePawn.h"
#include "ZakaZombiePawn.generated.h"

/**
 * AZakaZombiePawn
 * 
 * 좀비 AI 전용 Pawn. AZakaBasePawn의 Capsule + Mesh를 상속.
 * AI 로직, 공격, 감염 시스템은 향후 별도 구현 예정.
 */
UCLASS()
class ZAKA_API AZakaZombiePawn : public AZakaBasePawn
{
	GENERATED_BODY()

public:
	AZakaZombiePawn();
};
