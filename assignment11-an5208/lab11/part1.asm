.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type
extern gets:NEAR
extern printf:NEAR
extern scanf:NEAR
.data
	;	variables go here
	format1 BYTE "%c", 0Ah, 0
	format2 BYTE "%s", 0
.code
	main1 PROC c	
		push ebp
		mov ebp, esp
		sub esp, 20			; allocate 20 bytes for the string

		lea edx, [ebp -20]
		push edx
		push offset format2
		call scanf
		add esp, 8

		mov ecx, 0			; loop counter

		loopbegin:
			sub al, al
			mov bl, BYTE PTR [ebp - 20 + ecx]
			cmp al, bl
			je done
				mov ebx, 0
				mov bl, BYTE PTR [ebp - 20 + ecx]
				push ebx
				push ecx

				push ebx
				push offset format1
				call printf
				add esp, 8

				pop ecx
				pop ebx

				add ecx, 1
				jmp loopbegin

		done:		
	INVOKE ExitProcess, 0	;
	main1 endp

end