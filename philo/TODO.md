# TODO — Philosopher Project

This file lists missing pieces and concrete fixes to finish the current
implementation. It is based on a quick code audit.

## Critical bugs

1. Détection de mort inversée → un philo ne meurt jamais.
     Dans `philosopher_routine.c:19`, la condition est inversée :
     `get_prop(&p->last_meal) - now_ms() >= time_to_die` devrait être `now_ms() - last_meal >= time_to_die`.
     Sinon la différence est négative et la mort ne se déclenche pas.
     Fichier: `philosopher_routine.c:19`.
2. `last_meal` jamais mis à jour lors de l’eat → logique de mort/sleep incohérente.
     `philo_is_dead()` et `philo_sleep()` s’appuient sur `last_meal`, mais il n’est jamais mis à jour `dans eat_routine`.
     Résultat: calculs incohérents (souvent basés sur zéro).
     Fichier: `philosopher_routine.c:43-52`.
3. `philo_sleep`: risque de durée négative / type.
     Dans `philo_sleep.c:36-41`, si t <= 0, `sleep_ms(t)` reçoit une valeur négative (int).
     Ça sort quasi immédiatement, mais c’est fragile et rend le flow “mort imminente” peu clair.
     À minima, garde if (t <= 0) return false; avant d’appeler `sleep_ms(t)`.
     Fichier: `philo_sleep.c:34-41`.

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

