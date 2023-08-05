.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type
extern printf:NEAR

.data
	;	variables go here
	msg BYTE "eax = %d", 0Ah, 0

.code
	addOne:
		push ebp
		mov ebp, esp
		sub esp, 4		; make some room (4 bytes) for the variable
		; so y is at location ebp - 4 -> y = [ebp - 4]
		; x is the passed argument
		; x is pushed by the caller, so x is at location ebp + 8
		; mov	[ebp - 4], [ebp + 8]		; y = x
		mov ecx, [ebp + 8]		; x
		mov [ebp - 4], ecx		; y = x
		mov ecx, 1
		add [ebp - 4], ecx
		mov eax, [ebp - 4]

		add esp, 4		; clean up local variable
		pop ebp
		ret
	
	main1 PROC c	
	; call addOne(10), get the returned value, and print it
		push 10
		call addOne

		push eax
		push offset msg
		call printf
		add esp, 8

	INVOKE ExitProcess, 0	;
	main1 endp

end