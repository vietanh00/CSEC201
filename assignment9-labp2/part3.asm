.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type

.data
	;	variables go here
	a DWORD 10
	b DWORD 20

.code
comment !
	main PROC c	
		mov eax, a				; eax = a
		mov ebx, b				; ebx = b
		mov ecx, offset a		; ecx = &a
		mov edx, offset b		; edx = &b
		add b, eax				; b += a
		
		mov esi, [edx]			
		add [ecx], esi			; *(&a) += *(&b)
		mov eax, a				; store a in eax
		; final result: a = 40 (28 in hex), b = 30 (1E in hex)

	INVOKE ExitProcess, 0	;
	main endp
!
end