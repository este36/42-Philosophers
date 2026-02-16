# TODO — Philosopher Project

This file lists missing pieces and concrete fixes to finish the current
implementation. It is based on a quick code audit.

## Critical bugs

## Missing core behavior
- Implement `philosopher_routine()` thread routine:
  - Fork acquisition order to avoid deadlocks.
  - Eating/sleeping/thinking loop.
  - Update `last_meal`, `eat_times`, and `state`.
  - Respect `times_must_eat` if provided.
- Implement `monitor_routine()`:
  - Periodically check for starvation (`time_to_die`).
  - Stop all threads on death or when all ate enough.
  - Track `deaths` and `should_stop`.
- Finish cleanup after the simulation (destroy mutexes, free `philos`).

## Time + logging
- Implement millisecond timestamps:
  - Store a simulation start time in `t_monitor` and `t_philosopher`.
  - In `philo_log()`, compute `now - start` and print ms.

## Synchronization correctness
- Ensure fork pointers are valid for `n == 1` and handle the single-philo edge case.
- Ensure a clean shutdown:
  - Stop logging after a death or completion (avoid extra lines).
  - Prevent double-destroy of mutexes on init failure.

## Error handling and cleanup
- In `run_simulation()`, free `philos` if `init_mutexes()` fails.
- Ensure all mutexes are destroyed even on partial initialization failures.

## Optional improvements
- Validate numeric arguments strictly (digits only, no overflow).
