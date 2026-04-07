// Copyright Zaka Project. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Characters/ZakaBasePawn.h"
#include "ZakaPlayerCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

/**
 * AZakaPlayerCharacter
 * 
 * 플레이어 전용 Pawn. 3인칭 카메라 + Enhanced Input 바인딩을 포함.
 * CachedMoveInput / bIsJumpPressed는 향후 MoverComponent의
 * ProduceInput에서 소비하기 위한 입력 캐시.
 */
UCLASS()
class ZAKA_API AZakaPlayerCharacter : public AZakaBasePawn
{
	GENERATED_BODY()

public:
	AZakaPlayerCharacter();
	
	virtual void BeginPlay() override;
	
	UFUNCTION(BlueprintCallable, Category = "Input")
	void SetupInput();
	
protected:
	// --- Camera ---
	// Todo: switch to Gameplay Camera

	/** 카메라 붐 (Pawn 회전과 독립) */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<USpringArmComponent> SpringArmComponent;

	/** 3인칭 카메라 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	TObjectPtr<UCameraComponent> CameraComponent;

	// --- Input Mapping Context (에디터에서 할당) ---
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
	TObjectPtr<UInputMappingContext> DefaultMappingContext;

	// --- Cached Input State ---
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	FVector2D CachedMoveInput;

	/** 점프 입력 */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Input")
	bool bIsJumpPressed;

private:
	// --- Camera Defaults ---
	static constexpr float DefaultArmLength = 400.0f;
	static constexpr float DefaultSocketOffsetZ = 80.0f;
};
