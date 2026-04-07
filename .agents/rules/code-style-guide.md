---
trigger: always_on
---

# Coding Convention for UE

## Naming Conventions
- UnrealEngine C++ Prefixes: `U`(UObject), `A`(AActor), `F`(Structs/Value types), `E`(Enum), `I`(Interface).
- Member Variables: Use PascalCase. Boolean variables must start with 'b'(e.g. `bIsRotated`), and others should use descriptive names (e.g. `GridWidth`).
- Functions: Use PascalCase and start with a verb (e.g. `TryAddItem`, `FindFirstAvailableSlot`).
- Filenames: Must match the class name, excluding the prefix (e.g. `InventoryComponent.h`).

## Includes Order (Strict Policy)
```
#include "InventoryComponent.h"            // 1. Module header (Self)
#include "CoreMinimal.h"                   // 2. Engine core
#include "Components/..."                  // 3. Engine module headers
#include "ZakaInventoryTypes.h"           // 4. Project-specific headers
#include "InventoryComponent.generated.h"  // 5. Must be the last include
```
Ensure #include paths in .cpp files correctly reflect the Public folder structure.

## UPROPERTY / UFUNCTION Macros
- Data Exposure: `UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "CategoryName")`
- Runtime-only (Read-only in Editor): `UPROPERTY(VisibleAnywhere, BlueprintReadOnly)`
- Networking/Replication: `UPROPERTY(Replicated)` or `UPROPERTY(ReplicatedUsing=OnRep_XXX)`
- API Functions: `UFUNCTION(BlueprintCallable, Category = "CategoryName")`
- Read-only Queries: `UFUNCTION(BlueprintCallable, BlueprintPure, Category = "CategoryName")`
- Server-side RPCs: `UFUNCTION(Server, Reliable, WithValidation)`
- Client-side RPCs: `UFUNCTION(Client, Reliable)`