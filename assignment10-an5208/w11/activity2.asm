.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type
extern printf:NEAR
.data
	;	variables go here
	format BYTE "%d! = %d", 0Ah, 0

.code
	main2 PROC c	
		mov eax, 1
		mov ecx, 1
		; store eax and ecx on the stack memory
		push ecx
		push eax
		; prepare arguments for printf and call it
		push eax
		push ecx
		push offset format
		call printf			; printf used and changed eax, ecx, edx, and didnt bother to change them back
		add esp, 12
		; restore those variables, according to order
		pop eax				; since eax is lower
		pop ecx

		add ecx, 1			; ecx += 1 (= 2)
		mul ecx				; eax = eax * ecx (= 2)
		; store ecx and eax on the stack
		push ecx
		push eax
		; prepare arguments for printf and call it
		push eax
		push ecx
		push offset format
		call printf
		add esp, 12
		; restore those variables
		pop eax
		pop ecx

		add ecx, 1			; ecx += 1 (= 3)
		mul ecx				; eax = eax * ecx (= 6)
		; store ecx and eax on the stack
		push ecx
		push eax
		; prepare arguments for printf and call it
		push eax
		push ecx
		push offset format
		call printf
		add esp, 12
		; restore those variables
		pop eax
		pop ecx

	INVOKE ExitProcess, 0	;
	main2 endp

end