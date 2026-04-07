---
trigger: always_on
---

Zaka/
├── .agents/                         # AI Agent configuration and rules folder
├── Config/                          # Unreal Engine project configuration files
├── Docs/                            # Project documentation and specifications
│   ├── ARCHITECTURE.md              # Overall architecture design specification
│   ├── Logs/                        # Completion and progress reports
│   │   └── yyyy_MM_DD_daily_log.md  # Daily report (work summary and areas for improvement)
│   └── Plans/                       # Design specs and planning docs for each feature
│       ├── etc.md                   # (Ex: Miscellaneous/Others)
│       ├── MotionMatching.md        # (Ex: Design spec and plan for Motion Matching)
│       └── Mover.md                 # (Ex: Design spec and plan for Mover component)
├── Zaka.uproject                    # Unreal Engine project file
└── Source/
    └── Zaka/
        ├── Core/                    # Engine Extensions & Global Utilities
        ├── Framework/               # Game Rules & Flow Control (GameMode, State)
        ├── Interfaces/              # Centralized Interface Definitions (Abstraction Layer)
        ├── Characters/              # Character Logic (Mover, Motion Matching, etc.)
        ├── Movement/                # Mover Component Logic
        │   ├── Modes/               # Custom Mover Modes (Crouch, Slide, Ladder, etc.)
        │   └── Transitions/         # Logic for Mode Transitions
        │
        ├── AbilitySystem/           # GAS Implementation (Attributes, Abilities, Effects, MMC)
        │   ├── Attributes/          # AttributeSet Classes
        │   └── Abilities/           # GameplayAbilities (Sub-folders by feature recommended)
        │
        ├── Systems/                 # Independent & Modular Game Systems
        │   ├── Extraction/          # Extraction-related Logic
        │   ├── Inventory/           # Item & Inventory System
        │   └── Sandbox/             # Construction & Environment Interaction
        │
        ├── AI/                      # StateTree & AI Logic
        │   ├── Evaluators/          # StateTree Condition Evaluators
        │   └── Tasks/               # StateTree Execution Tasks
        │
        ├── UI/                      # C++ Base Classes for Slate/UMG
        │   └── HUD/                 # HUD Specific Logic
        │
        └── Data/                    # DataAsset & Raw Data Definitions

Follow the Public/Private folder structure for file generation. All .h files must be located under Public/ [Category] and all .cpp files under Private/[Category]. (e.g. `Public/Character/ZakaBasePawn.h`, `Private/Character/ZakaBasePawn.cpp`)