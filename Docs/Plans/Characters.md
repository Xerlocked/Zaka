# Characters Design Specification

> Defines the class hierarchy and component composition for all playable and AI-driven characters.
> All characters inherit from APawn (not ACharacter) to support the Mover-Centric Architecture.

---

## 1. Class Hierarchy

```
APawn
  └── AZakaBasePawn              (공통 베이스: Capsule, SkeletalMesh)
        ├── AZakaPlayerCharacter  (플레이어: Camera, SpringArm, Enhanced Input)
        └── AZakaZombiePawn       (좀비: AI 전용, 최소 구성)
```

---

## 2. AZakaBasePawn — Base Pawn

**Location**: `Source/Zaka/Characters/ZakaBasePawn.h / .cpp`

### Components

| Component              | Type                    | Role          | Attachment     |
|------------------------|-------------------------|---------------|----------------|
| CapsuleComponent       | UCapsuleComponent       | Root / 충돌    | RootComponent  |
| MeshComponent          | USkeletalMeshComponent  | 메시 렌더링     | CapsuleComponent |

### UPROPERTY Specifiers

```cpp
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
TObjectPtr<UCapsuleComponent> CapsuleComponent;

UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
TObjectPtr<USkeletalMeshComponent> MeshComponent;
```

### Constants

```cpp
static constexpr float DefaultCapsuleRadius = 42.0f;
static constexpr float DefaultCapsuleHalfHeight = 96.0f;
```

### Notes
- MoverComponent는 이 클래스에 포함하지 않음 (별도 추가 예정)
- 향후 GAS (AbilitySystemComponent, AttributeSet) 통합 지점

---

## 3. AZakaPlayerCharacter — Player Character

**Location**: `Source/Zaka/Characters/ZakaPlayerCharacter.h / .cpp`

### Components

| Component         | Type                  | Role             | Attachment          |
|-------------------|-----------------------|------------------|---------------------|
| SpringArmComponent| USpringArmComponent  | 카메라 암         | CapsuleComponent    |
| CameraComponent   | UCameraComponent     | 3인칭 카메라       | SpringArmComponent  |

### UPROPERTY Specifiers

```cpp
// Components
UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
TObjectPtr<USpringArmComponent> SpringArmComponent;

UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
TObjectPtr<UCameraComponent> CameraComponent;

// Input Actions (에디터에서 할당)
UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
TObjectPtr<UInputMappingContext> DefaultMappingContext;

UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
TObjectPtr<UInputAction> MoveAction;

UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
TObjectPtr<UInputAction> LookAction;

UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
TObjectPtr<UInputAction> JumpAction;
```

### Camera Defaults

```cpp
static constexpr float DefaultArmLength = 400.0f;
static constexpr FVector DefaultSocketOffset = FVector(0.0f, 0.0f, 80.0f);
```

### Key Functions

| Function                | Description                              |
|-------------------------|------------------------------------------|
| SetupPlayerInputComponent | Enhanced Input 바인딩                    |
| Move(FInputActionValue&) | MoveAction 핸들러 (방향 입력 캐시)         |
| Look(FInputActionValue&) | LookAction 핸들러 (컨트롤러 회전)          |
| JumpPressed()           | JumpAction Started 핸들러                 |
| JumpReleased()          | JumpAction Completed 핸들러               |

### Notes
- bUseControllerRotationYaw = false (카메라 기반 회전)
- SpringArm: bUsePawnControlRotation = true
- Input Action 에셋은 에디터에서 Blueprint로 할당

---

## 4. AZakaZombiePawn — Zombie Pawn

**Location**: `Source/Zaka/Characters/ZakaZombiePawn.h / .cpp`

### Current Scope
- AZakaBasePawn 상속, 최소 구성
- AI 로직은 향후 구현

---

## 5. AZakaPlayerController — Player Controller

**Location**: `Source/Zaka/Framework/ZakaPlayerController.h / .cpp`

### Purpose
- Enhanced Input Mapping Context 등록
- BeginPlay에서 IMC 추가

### UPROPERTY Specifiers

```cpp
UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Input")
TObjectPtr<UInputMappingContext> DefaultMappingContext;
```

### Key Functions

| Function       | Description                                              |
|----------------|----------------------------------------------------------|
| BeginPlay()    | AddMappingContext를 통해 DefaultMappingContext 등록         |

---

## 6. File Summary

| File                          | Module     | Status |
|-------------------------------|-----------|--------|
| Characters/ZakaBasePawn.h/cpp | Characters | NEW    |
| Characters/ZakaPlayerCharacter.h/cpp | Characters | NEW |
| Characters/ZakaZombiePawn.h/cpp | Characters | NEW |
| Framework/ZakaPlayerController.h/cpp | Framework | NEW |
