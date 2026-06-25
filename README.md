*This project has been created as part of the 42 curriculum by hmnatsak*

# push_swap

## Description

This repository contains a solution for the Push_swap project: a C program that
calculates and prints a sequence of stack operations that sorts a list of integers
using two stacks (a and b) and a limited set of operations. The goal is to
produce a correct sequence with as few operations as possible.

This implementation includes four strategies (simple, medium, complex, and an
adaptive selector), a `checker` program to verify operation lists, a benchmark
mode, and helper utilities for input parsing and stack manipulation.

## Instructions

Build the project (creates `push_swap` and `checker` via the `bonus` target):

```sh
make
make bonus
```

Basic usage examples:

```sh
# run push_swap (adaptive by default)
./push_swap 4 67 3 87 23

# force a strategy
./push_swap --simple 5 4 3 2 1
./push_swap --complex 4 67 3 87 23

# print benchmark to stderr (operations still go to stdout)
./push_swap --bench 4 67 3 87 23

# verify operations with checker
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

Error handling:
- Invalid arguments (non-integers, out-of-range values, duplicates) print
  "Error\n" to stderr and the program exits.
- `checker` prints `OK` or `KO` to stdout after applying instructions.

## Project structure

- `push_swap` — main program that computes operations
- `checker` — reads operations from stdin and validates them
- `*.c`, `*.h` — source files including strategies and utilities
- `Makefile` — build targets: `all`, `bonus`, `clean`, `fclean`, `re`

## Algorithms and complexity

This project implements four strategies. Complexity claims refer to the number
of push_swap operations produced (not CPU complexity of array algorithms).

1. Simple (O(n^2))
   - Approach: Repeatedly find the minimum element, rotate it to the top and
     push it to stack `b`. When `a` is empty, push everything back to `a`.
   - Complexity intuition: each extraction may require O(n) rotations and we
     extract O(n) elements -> O(n^2) operations.

2. Medium (O(n * sqrt(n)))
   - Approach: Partition the range into sqrt(n)-sized chunks and push chunks
     from `a` to `b`, then bring elements back by repeatedly bringing the max
     to the top of `b` and pushing to `a`.
   - Complexity intuition: there are about sqrt(n) chunks; moving each chunk
     costs roughly O(n) operations overall giving O(n * sqrt(n)).

3. Complex (O(n log n))
   - Approach: Normalize values to ranks and perform a radix-style bitwise
     partitioning (LSD) across bits of the rank values: push numbers with the
     bit unset to `b`, rotate those with the bit set; then push back from `b`.
   - Complexity intuition: number of bits is O(log n); each pass touches each
     element once -> O(n log n) operations.

4. Adaptive
   - Approach: Compute a disorder metric (inversion count / total pairs) and
     choose a strategy:
       - disorder < 0.2: simple (O(n^2))
       - 0.2 ≤ disorder < 0.5: medium (O(n * sqrt(n)))
       - disorder ≥ 0.5: complex (O(n log n))
   - Rationale: low-disorder inputs are close to sorted so simple extraction is
     cheap; medium disorder benefits from chunking; high disorder needs an
     asymptotically faster approach.

### Disorder metric

Disorder is computed as the number of inverted pairs divided by total pairs:

mistakes / total

This is measured before any moves and is printed by `--bench` as a percentage
with two decimal places.

## Operation semantics

All push_swap operations implemented follow subject rules:
- `sa`, `sb`, `ss`: swap top two elements; do nothing if fewer than 2 elements.
- `pa`, `pb`: push top element from source to destination; do nothing if
  source is empty.
- `ra`, `rb`, `rr`: rotate up; do nothing if fewer than 2 elements.
- `rra`, `rrb`, `rrr`: reverse rotate; do nothing if fewer than 2 elements.

Operations are printed to stdout (one per line) when run in normal mode.

## Benchmark mode

Use `--bench` to print metrics to stderr after sorting. Bench output includes:
- Disorder (percent, two decimals)
- Strategy name and theoretical class
- Total operation count and per-operation counts (sa, sb, ss, pa, pb, ra, rb,
  rr, rra, rrb, rrr)

## Safety and tests

- Memory: allocations are freed; `error_exit` frees resources before exiting.
- Operations are guarded against empty or too-small stacks to avoid invalid
  memory access (prevents invalid read/write reported by valgrind).

Recommended tests (add to your test suite):

```sh
# tiny correctness
./push_swap 2 1 3 | ./checker 2 1 3

# bench example
./push_swap --bench 5 1 4 2 3
```

## AI usage

AI was used for code review and debugging assistance (fixing an invalid-read
bug in operation functions and for creating this README). All generated code
changes were reviewed and tested locally with `valgrind` and `make` before
acceptance.

## Resources
- Push_swap subject specification (local class materials).
- Standard references on sorting, radix sort, and complexity (Knuth, CLRS).

---
