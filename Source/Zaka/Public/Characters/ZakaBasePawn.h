// Copyright Zaka Project. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ZakaBasePawn.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;

/**
 * AZakaBasePawn
 * 
 * 모든 캐릭터(플레이어, 좀비 등)의 공통 베이스 Pawn.
 * APawn을 직접 상속하며, MoverComponent는 서브클래스에서 별도 추가.
 * Capsule 충돌 + SkeletalMesh 렌더링을 기본 구성으로 제공.
 */
UCLASS(Abstract)
class ZAKA_API AZakaBasePawn : public APawn
{
	GENERATED_BODY()

public:
	AZakaBasePawn();
	
	UCapsuleComponent* GetCapsuleComponent() const { return CapsuleComponent; }
	
	USkeletalMeshComponent* GetMeshComponent() const { return MeshComponent; }
	
protected:
	/** 충돌 처리를 위한 Capsule (Root Component) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

	/** 캐릭터 메시 렌더링 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<USkeletalMeshComponent> MeshComponent;
	
	static constexpr float DefaultCapsuleRadius = 42.0f;
	static constexpr float DefaultCapsuleHalfHeight = 96.0f;
};
