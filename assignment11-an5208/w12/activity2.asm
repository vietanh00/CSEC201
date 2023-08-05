.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type
extern printf:NEAR

.data
	;	variables go here
	format BYTE "z = %d", 0Ah, 0

.code
	add_them:
		push ebp
		mov ebp, esp
		sub esp, 4				; make room for c
		; arguments: a = [ebp + 8], b = [ebp + 12]; result c = [ebp - 4]
		mov eax, [ebp + 12]		; ebx is callee-safe!
		mov ecx, [ebp + 8]

		add eax, ecx
		mov [ebp - 4], eax

		mov eax, [ebp - 4]			; store c in eax (convention)
		add esp, 4				; deallocate c
		pop ebp					; return to ebp (in main)
		ret


	main2 PROC c		
		push ebp
		mov ebp, esp
		sub esp, 12				; make space for 3 local variables
		; x is at ebp - 4 so x = [ebp - 4], similarly y = [ebp - 8], z = [ebp - 12]
		mov eax, 10
		mov [ebp - 4], eax
		mov eax, 20
		mov [ebp - 8], eax

		; push variables in reverse order
		push [ebp - 8]
		push [ebp - 4]
		call add_them
		add esp, 8

		mov [ebp - 12], eax		; results are generally stored in eax

		; print z
		push [ebp - 12]
		push offset format
		call printf
		add esp, 8

		add esp, 12				; deallocate space of the 3 variables
		pop ebp
		
	INVOKE ExitProcess, 0	;
	main2 endp

end