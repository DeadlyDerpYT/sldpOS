PrintString:
	mov ah, 0x0e
	cmp [bx], byte 0
	je .Exit
	.Loop:
		mov al, [bx]
		int 0x10
		inc bx
		jmp .Loop
	.Exit:
	ret
