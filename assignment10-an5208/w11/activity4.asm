.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type
extern printf:NEAR

.data
	;	variables go here
	num DWORD 5
	msg BYTE "%d! = %d", 0Ah, 0
.code
	main4 PROC c	
	comment !
		result = 1;
		for (i = 1, i <= num; i++) {
			result *= i;
		}
	!
	mov eax, 1				; eax = result = 1
	mov ecx, 1					; ecx = i = 1
	loopbegin:
		cmp ecx, num
		jg loopend			; i > num -> exit the loop
			; loop body
			mul ecx			; result *= i
			; store eax and ecx
				push eax
				push ecx
			; printf the current result
				push eax
				push ecx
				push offset msg
				call printf	; printf uses eax and ecx
				add esp, 12
			pop ecx
			pop eax
			add ecx, 1		; i++
			jmp loopbegin	; go back to the loop
	loopend:

	INVOKE ExitProcess, 0	;
	main4 endp

end