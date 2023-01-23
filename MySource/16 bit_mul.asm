.model small
.stack 64
.data 
 a db 09h
 b db 02h
 c dw ?
.code
 assume cs:code,ds:data
start:
mov ax,data
mov ds,ax
mov ax,0000h
mov bx,0000h
mov al,a
mov bl,b
mul b
mov c,ax

code ends



end start   