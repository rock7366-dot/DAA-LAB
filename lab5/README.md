# Experiment 5: Celebrity Problem

### Problem
Among `n` people, a celebrity is a person who:
1. Is known by everyone else.
2. Knows nobody else.

### Efficient algorithm
Use elimination:
1. Start with person `0` as the candidate.
2. For every other person `i`, if the current candidate knows `i`, the candidate cannot be a celebrity, so make `i` the candidate.
3. After one pass, only one candidate remains possible.
4. Verify that the candidate knows nobody and everyone knows the candidate.
5. If verification succeeds, the candidate is the celebrity; otherwise no celebrity exists.

### Complexity
- Candidate elimination: O(n)
- Verification: O(n)
- Overall time: **O(n)**
- Extra space: **O(1)** apart from the input matrix.

### Compilation
```bash
gcc celebrity.c -o celebrity
./celebrity
```
