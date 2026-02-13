# TODO — Philosopher Project

This file lists missing pieces and concrete fixes to finish the current
implementation. It is based on a quick code audit.

## Critical bugs
- Fix argument parsing in `main.c`:
  - `argc` must be `5` or `6` (program name + 4 required + 1 optional).
  - The optional `times_must_eat` should be read when `argc == 6`, not `4`.
  - Do not read `argv[5]` when `argc == 5`.

## Missing core behavior
- Implement `philosopher()` thread routine:
  - Fork acquisition order to avoid deadlocks.
  - Eating/sleeping/thinking loop.
  - Update `last_meal`, `eat_times`, and `state`.
  - Respect `times_must_eat` if provided.
- Implement `monitor()` routine:
  - Periodically check for starvation (`time_to_die`).
  - Stop all threads on death or when all ate enough.
  - Track `deaths` and `should_stop`.
- Wire up thread creation/joining in `run_simulation()`:
  - Create N philosopher threads.
  - Start monitor.
  - Join all threads.
  - Destroy mutexes and free allocated memory.

## Time + logging
- Implement millisecond timestamps:
  - Store a simulation start time in `t_monitor` and `t_philosopher`.
  - In `philo_log()`, compute `now - start` and print ms.

## Synchronization correctness
- Make `t_prop` access thread-safe:
  - Implement `get_prop()` / `set_prop()` in a .c file.
  - Lock `prop->mtx` consistently for `state`, `can_eat`, `eat_times`, `last_meal`,
    and `should_stop`.
- Ensure fork pointers are valid for `n == 1` and handle the single-philo edge case.
- Ensure a clean shutdown:
  - Stop logging after a death or completion (avoid extra lines).
  - Prevent double-destroy of mutexes on init failure.

## Error handling and cleanup
- In `run_simulation()`, free `philos` if `init_mutexes()` fails.
- Ensure all mutexes are destroyed even on partial initialization failures.

## Optional improvements
- Validate numeric arguments strictly (digits only, no overflow).
