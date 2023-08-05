.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type
extern printf:NEAR
extern scanf:NEAR

;Question 2: Basic Arithmetic

.data
	;	variables go here
	x DWORD ?
	format_print BYTE "ebx = %d", 0Ah, 0
	format_num BYTE "%d", 0

.code
comment!
	main PROC c	
		
		; scanf("%d", x)
		push offset x				; arg 2
		push offset format_num		; arg 1		
		call scanf
		add esp, 8

		; compute ebx
		mov eax, x
		add eax, 2
		mov ecx, 5
		mul ecx
		mov ebx, eax

		; printf("ebx = %d\n", ebx)
		push ebx
		push offset format_print
		call printf
		add esp, 8
		
	INVOKE ExitProcess, 0	;
	main endp
!
end