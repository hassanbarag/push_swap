*This project has been created as part of the 42 curriculum by <ignmarti>, <hassamoh>.*

# Push_swap

## 📌 Description

Push_swap is a sorting algorithm project from the 42 curriculum.  
The objective is to sort a list of integers in ascending order using only a restricted set of stack operations and two stacks (A and B).

The challenge is not simply sorting numbers, but doing so while minimizing the total number of operations under strict constraints.

This project emphasizes:

- Algorithm design and optimization
- Complexity analysis (time and space)
- Data structure implementation
- Performance-driven decision making
- Clean modular architecture

---

# 🎯 Project Goals

- Parse and validate input integers
- Build two stacks (A and B)
- Sort stack A using only allowed operations
- Minimize the number of operations
- Select the most efficient sorting strategy depending on input characteristics

---

# 🏗 Architecture Overview

The project is divided into the following main components:

1. **Parsing & Validation**
   - Input checking
   - Duplicate detection
   - Integer range validation

2. **Stack Implementation**
   - Linked list-based stack structure
   - Efficient push, pop, rotate, and reverse rotate operations

3. **Operation Layer**
   - Implementation of all allowed Push_swap instructions:
     - sa, sb, ss
     - pa, pb
     - ra, rb, rr
     - rra, rrb, rrr

4. **Sorting Engine**
   - Multi-strategy sorting system
   - Strategy selection based on disorder level

5. **Disorder Measurement**
   - Evaluates how unsorted the stack is
   - Guides algorithm selection

6. **(Optional) Benchmark System**
   - Tracks operation counts
   - Measures performance per strategy

---

# 🧠 Algorithm Selection & Justification

Instead of relying on a single algorithm, the project implements three sorting regimes optimized for different input distributions.

The decision is based on a computed **disorder metric**, which estimates how far the stack deviates from sorted order.

---

# 📊 Disorder Metric

The disorder value ranges from:

- 0.0 → Fully sorted
- 1.0 → Highly unsorted

It is computed by analyzing positional deviations relative to indexed ordering.

---

# 📊 Threshold Rationale

| Disorder Range | Strategy |
|---------------|----------|
| < 0.2 | Simple |
| 0.2 – 0.5 | Medium |
| ≥ 0.5 | Complex |

### Why These Thresholds?

- **Low disorder (< 0.2)**  
  The stack is nearly sorted.  
  A quadratic algorithm does not degrade significantly in this case.  
  Using a more complex method would introduce unnecessary overhead.

- **Moderate disorder (0.2 – 0.5)**  
  The stack contains mixed ordered/unordered segments.  
  Chunk-based sorting distributes operations efficiently.

- **High disorder (≥ 0.5)**  
  The stack is heavily shuffled.  
  Radix sort guarantees predictable upper-bound performance and avoids quadratic degradation.

Thresholds were determined through empirical testing and operation count analysis.

---

# 🔎 Internal Techniques Used in Each Regime

## 🔹 Simple Strategy – Min/Max Selection

Technique:
- Find smallest indexed element
- Rotate stack efficiently
- Push to stack B
- Reassemble sorted stack

Characteristics:
- Comparison-based
- Rotation-cost optimized
- Suitable for small or nearly sorted datasets

Worst-case complexity:
- Time: O(n²)
- Space: O(1)

---

## 🔹 Medium Strategy – Chunk-Based Sorting

Technique:
- Divide indexed range into chunks
- Push chunk elements progressively to stack B
- Maintain partial ordering
- Optimize reinsertion rotations

Characteristics:
- Reduces full-stack scanning
- Balanced performance
- Suitable for medium disorder inputs

Worst-case complexity:
- Time: Approximately O(n√n)
- Space: O(1)

---

## 🔹 Complex Strategy – Binary Radix Sort

Technique:
- Normalize values into indexed form
- Process bits from least significant to most significant
- Push elements to B when bit = 0
- Rotate when bit = 1
- Reassemble progressively

Characteristics:
- Non-comparison based
- Deterministic behavior
- Stable operation growth

Worst-case complexity:
- Time: O(n log n)
- Space: O(1)

---

# 📈 Complexity Within the Push_swap Model

All complexity arguments are evaluated under Push_swap constraints:

- Only allowed stack operations are used
- No external sorting arrays during execution
- No recursion
- No dynamic auxiliary buffers

| Strategy | Time (Upper Bound) | Extra Space |
|----------|-------------------|------------|
| Simple   | O(n²)             | O(1)       |
| Medium   | O(n√n)            | O(1)       |
| Complex  | O(n log n)        | O(1)       |

Memory usage is limited to:
- The linked-list stacks
- Constant-sized helper variables

---

# 🛠 Instructions

## Compilation
To compile the project, make sure you are in the root directory of the repository and run:

`make`

This command builds the project and generates the push_swap executable.

If needed, you may also use:

`make clean`

Removes object files

`make fclean`

Removes object files and the executable

`make re`

Cleans and recompiles the entire project  

Once compiled, you can execute the program by passing a sequence of integers as arguments:

`./push_swap 2 1 3 6 5 8`

The program will output the list of stack operations required to sort the numbers in ascending order using only the allowed Push_swap instructions.

To evaluate performance on larger datasets, you can generate random numbers using shuf:

`shuf -i 0-9999 -n 500 > args.txt ; ./push_swap $(cat args.txt) | wc -l`

---

# 📚 Resources & AI Usage

- [42 Push_swap Subject Documentation](https://projects.intra.42.fr/)  
- [Radix Sort Reference](https://en.wikipedia.org/wiki/Radix_sort)  
- [Linked List Data Structure](https://www.geeksforgeeks.org/stack-data-structure/)  
- [Youtube Tutorial Explanation Video](https://youtu.be/OaG81sDEpVk?si=VlINwmGRlkJxbO7m)  

**AI Usage:**

- Documentation structuring and formatting
- Clarification of algorithmic complexity
- Technical explanation refinement

All algorithm design, implementation, architecture, and validation were written and tested manually by the authors

