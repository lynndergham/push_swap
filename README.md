# push_swap
*This project was created as part of the 42 curriculum by **ldergham** and **pmakhoul***

---

## Description

**push_swap** is a sorting algorithm project with strict constraints.

You are given:
- A list of integer values
- Two stacks: **stack A** and **stack B**
- A limited set of allowed operations

The goal is to sort the integers in **ascending order** in stack A using the **smallest possible number of operations**, written to standard output using the *push_swap language*.

This project highlights the importance of **algorithmic complexity** and shows how choosing the right algorithm can drastically reduce the number of operations.

Sorting a random list, an almost sorted list, or a reversed list all require very different strategies to be efficient.

---

## Allowed Operations (push_swap language)

- **sa** — swap the first two elements of stack A  
- **sb** — swap the first two elements of stack B  
- **pa** — push the top element of B onto A  
- **pb** — push the top element of A onto B  
- **ra** — rotate stack A upwards  
- **rb** — rotate stack B upwards  
- **rr** — ra and rb at the same time  
- **rra** — reverse rotate stack A  
- **rrb** — reverse rotate stack B  
- **rrr** — rra and rrb at the same time  

---

## Implemented Algorithms

We implemented **four distinct sorting strategies**, each adapted to different data distributions.

---

### Simple Algorithm — *O(n²)*

Inspired by **selection sort**.

**Principle:**
- Repeatedly find the minimum value in stack A
- Rotate stack A using `ra` or `rra` (choosing the cheaper option)
- Push the minimum value to stack B
- Repeat until stack A is empty
- Push everything back from B to A

Stack B ends up sorted in descending order, and stack A becomes sorted in ascending order.

Best for very small or almost sorted inputs.

---

### Medium Algorithm — *O(n√n)*

**Chunk-based sorting strategy**

- Split the input into √n chunks
- Push values chunk by chunk into stack B
- Sort and reinsert them into stack A in the correct order

Efficient for partially sorted inputs.

---

### Complex Algorithm — *O(n log n)*

**Radix sort using binary indexing**

**Steps:**
1. Replace values with their sorted indexes
2. Process numbers bit by bit (binary representation)
3. For each bit:
   - If the bit is `0`, push to stack B
   - If the bit is `1`, rotate stack A
4. Push everything back from B to A
5. Repeat for all bits

Once all bits are processed:
- Stack A is fully sorted
- Stack B is empty

Best for large and fully random inputs.

---

### Adaptive Algorithm

The **adaptive algorithm** automatically chooses the best strategy based on input characteristics:

- Almost sorted → **Simple algorithm**
- Partially sorted → **Medium algorithm**
- Completely unsorted → **Complex algorithm**

No single algorithm is always optimal adaptability gives the best results.

---

## Instructions

### Installation
Clone the git repo. Run make to compile, and then make clean to clean p the workspace. You are now ready to use the program. Once done, make fclean will clean up everything, or make re to recompile.

```bash
git clone git@vogsphere.42beirut.com:vogsphere/intra-uuid-233f8263-95d5-4fac-904f-7e7dc5cc325e-7126667-aabi-mou
cd push_swap
make
```

### Testing
Example of a basic command:

```bash
./push_swap 2 1 3 6 5 8
```

This will sort the sequance, and print out the operations used. The default algorithm is the adaptive. You can use:

```bash
ARG="4 67 3 87 23"; ./push_swap --adaptive $ARG
```
 or replace adaptive by either simple, medium, or complex to select a specific algorithm to run. You can also use the --bench flag to go into bench mode, which will print metrics on the standard error:

 ```bash
 shuf -i 0-9999 -n 500 > args.txt ; ./push_swap --bench $(cat args.txt) 2>bench.txt cat bench.txt
 ```
You can use wc -l to print the number of operations. You can use ./checker_linux $ARG to use the checker. OK means the stack is sorted correctly, KO means an error occured. Error management examples:

```bash
$> ./push_swap --adaptive 0 one 2 3 Error 
$> ./push_swap --simple 3 2 3 Error
```

# Resources
- Linux maual pages
- Very helpful and kind peers that helped us no matter what
