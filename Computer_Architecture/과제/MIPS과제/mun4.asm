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
#어떤 기능 수행할 건지 번호 입력
la $a0 selmsg
li $v0 4
syscall
li $v0 5
syscall
add $t0 $zero $v0 #t0은 수행 번호

beq $t0 1 checkn1
beq $t0 2 checkn2

#1번 기능 부름
checkn1:
add $sp $sp -4
sw $ra 0($sp)
jal threemul
lw $ra 0($sp)
add $sp $sp 4
li $v0 10
syscall

#2번 기능 부름
checkn2:
add $sp $sp -4
sw $ra 0($sp)
jal calcfib
lw $ra 0($sp)
add $sp $sp 4
li $v0 10
syscall

#1번 기능
threemul:
#a 입력
la $a0 amsg
li $v0 4
syscall
li $v0 5
syscall
add $t1 $zero $v0
#b 입력
la $a0 bmsg
li $v0 4
syscall
li $v0 5
syscall
add $t2 $zero $v0
# t1==a, t2==b, (a-b) #t3==a-b
sub $t3 $t1 $t2
# 3 저장
addi $t4 $zero 3
#3의 배수인지 확인
div $t3 $t4
mfhi $s0
#3의 배수면 pcall로 아니면 ncall로
bne $s0 $zero ncall
beq $s0 $zero pcall

#3의 배수가 아닌경우 nthree부름 
ncall:
addi $sp $sp -4
sw $ra 0($sp)
jal nthree
lw $ra 0($sp)
addi $sp $sp 4
jr $ra

nthree:
#t3 출력
add $a0 $zero $t3
li $v0 1
syscall
#3의배수가 아니라고 출력
la $a0 nmul
li $v0 4
syscall
jr $ra

#3의 배수인 경우 pthree 부름
pcall:
addi $sp $sp -4
sw $ra 0($sp)
jal pthree
lw $ra 0($sp)
addi $sp $sp 4
jr $ra

pthree:
#t3 출력
add $a0 $zero $t3
li $v0 1
syscall
#3의배수가 아니라고 출력
la $a0 pmul
li $v0 4
syscall
jr $ra

#2번 기능 
calcfib:
#n 입력
la $a0 nmsg
li $v0 4
syscall
li $v0 5
syscall
add $a2 $v0 $zero#a2==n
#a 입력
la $a0 afmsg
li $v0 4
syscall
li $v0 5
syscall
add $a3 $v0 $zero#a3==a
addi $a2 $a2 1
# 위에까지 n과 a 입력 받는 부분
addi $a1 $zero 0 #a1==count
addi $sp $sp -4
#스택 포인터를 움직여 스택 공간 확보
sw $ra, 0($sp)
#ra 레지스터 값을 스택에 저장
#fib 함수 호출
jal fib
#다시 돌려줌
lw $ra 0($sp)
addi $sp $sp 4

jr $ra

#피보나치 함수
fib:
#초기화 t1,t2
addi $t1 $zero 1
addi $t2 $zero 1

#count< 2이면 처리할 내용
slti $t3 $a1 2
bne $t3 $zero firse
#count< n인 동안 처리할 내용
slt $t3 $a1 $a2
bne $t3 $zero loop

jr $ra

#count>=2인 경우 
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
#t1과 t2의 값 변경
add $t1 $zero $t2
add $t2 $zero $t3
#count증가
addi $a1 $a1 1
#조건 확인
slt $t4 $a1 $a2
bne $t4 $zero loop
jr $ra

#firse 함수 count<2인 경우
firse:
#0번째 출력
addi $a0 $zero 1
li $v0 1
syscall
la $a0 interval
li $v0 4
syscall
#count 1개 증가
addi $a1 $a1 1

j fib


