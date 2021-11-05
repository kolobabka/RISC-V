addi x1, x0, 1
add x2, x1, x0
addi x10, x0, 10
addi x5, x0, 1
add x6, x0, x2
Fibonacci:

add x2, x2, x1
add x1, x6, x0

add x6, x2, x0
addi x5, x5, 1

bne x5, x10, Fibonacci
