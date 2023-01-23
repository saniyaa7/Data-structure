;addition of 8 bit number
.model small
.stack 64
.data 
a DD 12121212h
b DD 12121212h
c DD ?
.code

start:

mov ax,@data 
mov ds,ax
mov ax,a
mov bx,b 

add ax,bx
mov c,ax


end start   