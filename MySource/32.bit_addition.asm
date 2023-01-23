.model small 
.stack
.data 
num1 dd 4832AC40h
num2 dd 341C4359h
sum dw ?

.code 
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax 
mov dl,00h
mov ax,num1 
mov bx,num2
add ax,bx
mov sum,ax
mov ax, num1+2
mov bx, num2+2
add ax,bx

mov sum+2,ax
jnc move
inc dl
move: mov byte ptr sum+4,dl






end start
