.model small 
.stack
.data 
a db 28h
b db 02h
c dw ?
sum dw ?

.code 
assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov ax,0000h
mov bx,0000h
mov al,a
mov bl,b
div b
mov c,ax







end start
