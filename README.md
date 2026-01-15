_This project has been created as part of the 42 curriculum by abellavi_

**DESCRIPTION**

This project is called push_swap.
This project's goal is to sort the args given by the user.
You have to sort this numbers with 2 stacks:
1. Stack_a: contains a random number of unique negative and/or positive integers.

2. Stack_b: is empty.

To sort, you have some operations:

1. sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one element or none.

2. sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one element or none.

3. ss : sa and sb at the same time.

4. pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

5. pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

6. ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

7. rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

8. rr : ra and rb at the same time.

9. rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

10. rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

11. rrr : rra and rrb at the same time.

With all of this, the goal is get the maximum eficiency you can, not only sorting.

**INSTRUCTIONS**
As i said the goal is sorting the numbers as fast as you can.
I did a 80% of the validation with my program.

For maximum project validation (100%) and eligibility for bonuses, you must:
◦ Sort 100 random numbers in fewer than 700 operations.
◦ Sort 500 random numbers in no more than 5500 operations.

• For minimal project validation (which implies a minimum grade of 80%), you
can succeed with different averages:
◦ 100 numbers in under 1100 operations and 500 numbers in under
8500 operations
◦ 100 numbers in under 700 operations and 500 numbers in under
11500 operations
◦ 100 numbers in under 1300 operations and 500 numbers in under
5500 operations

I sorted 100 numbers in 1084 operations and 500 numbers in 6784.

Apart of checking number of operations, here are some things to keep in mind:

$>ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
6
$>ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
OK

If the program checker_OS displays "KO", it means that your push_swap came up
with a list of instructions that doesn’t sort the numbers.

**RESOURCES**

1. I saw some repos to see how people used the operations to give me ideas.
2. AI helped me to implement and understand the system i wanted to use. 
I saw that i could use indexes and work with binary to sort the numbers.

It helped me to implement:
1. void	sort_index(t_stack *stack_a, t_stack *stack_b);
2. int	stack_max_bits(t_stack *stack_a);

Also helped me how structs work.