.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type

.data
	;	variables go here


.code
	fact:
		push ebp
		mov ebp, esp
		mov ecx, [ebp + 8]
		cmp ecx, 1		; base case
		je base
			; else block
			; call fact(x-1)
			push ecx			; store this since it will be changed by 'fact'
			sub ecx, 1
			push ecx
			call fact
			add esp, 4
			
			pop ecx
			
			;eax holds factorial of (x-1)
			imul ecx, eax		; ecx = ecx*eax
			mov eax, ecx
			pop ebp
			ret

		base:
		mov eax, 1
		pop ebp
		ret

	main5 PROC c	
		push 5
		call fact
		add esp, 4


	INVOKE ExitProcess, 0	;
	main5 endp

end