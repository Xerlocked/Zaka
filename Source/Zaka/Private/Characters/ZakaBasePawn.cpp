// Copyright Zaka Project. All Rights Reserved.

#include "Characters/ZakaBasePawn.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"

AZakaBasePawn::AZakaBasePawn()
{
	PrimaryActorTick.bCanEverTick = false;

	// Capsule (Root)
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->InitCapsuleSize(DefaultCapsuleRadius, DefaultCapsuleHalfHeight);
	CapsuleComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	RootComponent = CapsuleComponent;

	// Skeletal Mesh
	MeshComponent = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("MeshComponent"));
	MeshComponent->SetupAttachment(CapsuleComponent);
	MeshComponent->SetRelativeLocation(FVector(0.0, 0.0, -DefaultCapsuleHalfHeight));
	MeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}
