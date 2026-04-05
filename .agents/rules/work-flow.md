---
trigger: always_on
---

# Agent Workflow (Standard Operating Procedure)

1. **Design Specification First**: Before any implementation, you must read and understand Docs/ARCHITECTURE.md. If a design for the requested feature does not exist, you must first create a new design specification.

2. **Review Existing Plans**: Always read and adhere to the design instructions in the Docs/Plans/ directory for the specific feature. If no plan exists, follow Step 1 to create one before proceeding.

3. **Context Awareness**: Thoroughly inspect the Source/Zaka/ directory and existing code to ensure compatibility and prevent redundancy.

4. **Strict Implementation**: Implement classes, functions, and UPROPERTY specifiers exactly as defined in the design specification. Do not deviate from the approved architecture. If you discover a contradiction with the design specifications during implementation, stop immediately and report it to the user.

5. **Post-Implementation Report**: Upon completion, create a new section using ### (Heading 3) in Logs/yyyy_MM_DD_daily_log.md. Summarize the work performed and note any technical debt or follow-up tasks.