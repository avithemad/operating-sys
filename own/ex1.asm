the_secret:
	db "A"

mov ah, 0x0e

mov bx, the_secret
add bx, 0x7c00
mov al, [bx] 
int 0x10

jmp $

times 510-($-$$) db 0

dw 0xaa55
