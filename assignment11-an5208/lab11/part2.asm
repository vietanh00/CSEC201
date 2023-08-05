.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type
extern printf:NEAR
.data
	;	variables go here
	format BYTE "a = %d, b = %d", 0Ah, 0

.code
	swap:
		push ebp
		mov ebp, esp

		mov eax, [ebp + 8]		; eax = a (address)
		mov ecx, [ebp + 12]		; ecx = b (address)
		
		sub esp, 4				; int temp

		mov [ebp - 4], eax		; temp = a
		mov edx, [ebp - 4]
		mov edx, [edx]
		mov [ebp - 4], edx		; temp = [a] = 10

		mov edx, ecx
		mov edx, [edx]			; edx = [b] = 20

		mov [eax], edx			; *a = *b
		mov edx, [ebp - 4]
		mov [ecx], edx			; *b = temp
		
		add esp, 4

		pop ebp
		ret
		
	main PROC c	
		push ebp
		mov ebp, esp

		sub esp, 8			; int a, b
		mov ecx, 10
		mov [ebp - 4], ecx	; a = [ebp - 4] = 10
		mov ecx, 20
		mov [ebp - 8], ecx	; b = [ebp - 8] = 20

		lea ecx, [ebp - 8]	; ecx = &b
		lea eax, [ebp - 4]	; eax = &a
		push ecx
		push eax
		call swap
		add esp, 8

		push [ebp - 8]
		push [ebp - 4]
		push offset format
		call printf
		add esp, 12

	INVOKE ExitProcess, 0	;
	main endp
end