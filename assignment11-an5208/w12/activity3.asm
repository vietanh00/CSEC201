.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type
extern printf:NEAR

.data
	;	variables go here
	format BYTE "x = %d", 0Ah, 0

.code
	increase:
		push ebp
		mov ebp, esp
		; a = [ebp + 8], *a = [a] = [[ebp + 8]]
		; *a += 1
		mov eax, 1
		mov ecx, [ebp + 8]
		add [ecx], eax

		pop ebp
		ret
	
	main3 PROC c	
		; pass a reference to a function so that it can be modified
		push ebp
		mov ebp, esp
		sub esp, 4			; allocate space for x, same as 'int x', x is at ebp - 4
		mov ecx, 15
		mov [ebp - 4], ecx	

		lea ecx, [ebp - 4]	; ecx = ebp - 4, the address -- ecx = &x
		push ecx
		call increase
		add esp, 4

		push [ebp - 4]
		push offset format
		call printf
		add esp, 8

	INVOKE ExitProcess, 0	;
	main3 endp

end