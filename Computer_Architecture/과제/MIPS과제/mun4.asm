.globl main
.data
#main msg
selmsg:.asciiz "Select Procedure : "
#1 msg
amsg:.asciiz "a is : "
bmsg:.asciiz "b is : "
pmul:.asciiz " is multiple of three!"
nmul:.asciiz " is not multiple of three!"
#2 msg
nmsg:.asciiz "n is : "
afmsg:.asciiz "a is : "
interval: .asciiz "\t"
.text
main:
#� ��� ������ ���� ��ȣ �Է�
la $a0 selmsg
li $v0 4
syscall
li $v0 5
syscall
add $t0 $zero $v0 #t0�� ���� ��ȣ

beq $t0 1 checkn1
beq $t0 2 checkn2

#1�� ��� �θ�
checkn1:
add $sp $sp -4
sw $ra 0($sp)
jal threemul
lw $ra 0($sp)
add $sp $sp 4
li $v0 10
syscall

#2�� ��� �θ�
checkn2:
add $sp $sp -4
sw $ra 0($sp)
jal calcfib
lw $ra 0($sp)
add $sp $sp 4
li $v0 10
syscall

#1�� ���
threemul:
#a �Է�
la $a0 amsg
li $v0 4
syscall
li $v0 5
syscall
add $t1 $zero $v0
#b �Է�
la $a0 bmsg
li $v0 4
syscall
li $v0 5
syscall
add $t2 $zero $v0
# t1==a, t2==b, (a-b) #t3==a-b
sub $t3 $t1 $t2
# 3 ����
addi $t4 $zero 3
#3�� ������� Ȯ��
div $t3 $t4
mfhi $s0
#3�� ����� pcall�� �ƴϸ� ncall��
bne $s0 $zero ncall
beq $s0 $zero pcall

#3�� ����� �ƴѰ�� nthree�θ� 
ncall:
addi $sp $sp -4
sw $ra 0($sp)
jal nthree
lw $ra 0($sp)
addi $sp $sp 4
jr $ra

nthree:
#t3 ���
add $a0 $zero $t3
li $v0 1
syscall
#3�ǹ���� �ƴ϶�� ���
la $a0 nmul
li $v0 4
syscall
jr $ra

#3�� ����� ��� pthree �θ�
pcall:
addi $sp $sp -4
sw $ra 0($sp)
jal pthree
lw $ra 0($sp)
addi $sp $sp 4
jr $ra

pthree:
#t3 ���
add $a0 $zero $t3
li $v0 1
syscall
#3�ǹ���� �ƴ϶�� ���
la $a0 pmul
li $v0 4
syscall
jr $ra

#2�� ��� 
calcfib:
#n �Է�
la $a0 nmsg
li $v0 4
syscall
li $v0 5
syscall
add $a2 $v0 $zero#a2==n
#a �Է�
la $a0 afmsg
li $v0 4
syscall
li $v0 5
syscall
add $a3 $v0 $zero#a3==a
addi $a2 $a2 1
# �������� n�� a �Է� �޴� �κ�
addi $a1 $zero 0 #a1==count
addi $sp $sp -4
#���� �����͸� ������ ���� ���� Ȯ��
sw $ra, 0($sp)
#ra �������� ���� ���ÿ� ����
#fib �Լ� ȣ��
jal fib
#�ٽ� ������
lw $ra 0($sp)
addi $sp $sp 4

jr $ra

#�Ǻ���ġ �Լ�
fib:
#�ʱ�ȭ t1,t2
addi $t1 $zero 1
addi $t2 $zero 1

#count< 2�̸� ó���� ����
slti $t3 $a1 2
bne $t3 $zero firse
#count< n�� ���� ó���� ����
slt $t3 $a1 $a2
bne $t3 $zero loop

jr $ra

#count>=2�� ��� 
loop:
#t3=t1+t2+a
add $t4 $t1 $t2
add $t3 $t4 $a3
#print t3
add $a0 $zero $t3
li $v0 1
syscall
la $a0 interval
li $v0 4
syscall
#t1�� t2�� �� ����
add $t1 $zero $t2
add $t2 $zero $t3
#count����
addi $a1 $a1 1
#���� Ȯ��
slt $t4 $a1 $a2
bne $t4 $zero loop
jr $ra

#firse �Լ� count<2�� ���
firse:
#0��° ���
addi $a0 $zero 1
li $v0 1
syscall
la $a0 interval
li $v0 4
syscall
#count 1�� ����
addi $a1 $a1 1

j fib


