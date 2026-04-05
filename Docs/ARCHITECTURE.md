# ARCHITECTURE.md — Project Zaka Global Design Specification

> This document defines the universal structure and architectural integrity of the project.
> All design specifications and implementation plans must be derived from and align with this architecture.
> Consult this document as the primary reference before introducing any new classes, modules, or systems.
> This project is written based on Unreal Engine version 5.7 and includes the latest and experimental features.

---

## 1. 시스템 전체 구조

```
┌─────────────────────────────────────────────────────────┐
│                    Presentation Layer                     │
│  ┌────────────────┐ ┌────────────────┐ ┌───────────────┐ │
│  │ GameplayCamera │ │  CommonUI HUD  │ │ Prophecy UI   │ │
│  │ (Dynamic FOV)  │ │ (Status/Infect)│ │ (Data Decrypt)│ │
│  └───────┬────────┘ └───────┬────────┘ └───────┬───────┘ │
│          │                  │                  │         │
├──────────┼──────────────────┼──────────────────┼─────────┤
│          ▼                  ▼                  ▼         │
│                    Logic & Control Layer                 │
│  ┌──────────────────┐ ┌──────────────────┐ ┌─────────────┐  │
│  │  StateTree       │ │  Motion Matching │ │ Enhanced    │  │
│  │ (World/AI State) │ │  (Pose Search)   │ │ Input       │  │
│  └───────┬──────────┘ └───────┬──────────┘ └──────┬──────┘  │
│          │                    │                   │         │
├──────────┼────────────────────┼───────────────────┼─────────┤
│          ▼                    ▼                   ▼         │
│                     Core Model Layer                      │
│  ┌──────────────┐ ┌──────────────────┐ ┌────────────────┐ │
│  │  GAS Layer   │ │  Mover Component │ │ Prophecy System│ │
│  │ (Attributes) │ │  (Physics Mov)   │ │ (Quest/Prog)   │ │
│  └──────┬───────┘ └────────┬─────────┘ └──────┬─────────┘ │
│         │                  │                  │           │
├─────────┼──────────────────┼──────────────────┼───────────┤
│         ▼                  ▼                  ▼           │
│                      Data Layer                           │
│  ┌──────────────┐ ┌──────────────────┐ ┌────────────────┐ │
│  │ Data Assets  │ │  Pose Databases  │ │ Prophecy DT    │ │
│  │ (Item/Ability)│ │  (Animation)     │ │ (Coordinates)  │ │
│  └──────────────┘ └──────────────────┘ └────────────────┘ │
└───────────────────────────────────────────────────────────┘
```

---

## 2. 설계 원칙

1. **Mover-Centric Architecture**: All movement-related logic must be processed exclusively through the MoverComponent. Reverting to or utilizing the legacy CharacterMovementComponent is strictly prohibited.

2. **Tag-Driven State Management**: All state transitions (e.g., Infected, Stealth, Aiming) must be propagated via GameplayTags. Avoid direct references to or dependencies on boolean variables for state checks.

3. **Data-Driven Animation Workflow**: Prioritize Motion Matching and Chooser Tables for animation transition logic. Avoid building complex, hard-coded State Machines within the AnimBP to maintain a scalable, data-driven pipeline.

4. **Interface-Based Decoupling**: Inter-system communication must be executed through dedicated interfaces (e.g. IBabelInteractable, IBabelCombatant). This ensures low coupling and adheres to the Interface Segregation and Dependency Inversion principles.