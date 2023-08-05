.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type
extern printf:NEAR
extern gets:NEAR

.data
	;	variables go here
	str1 BYTE "Hello World!", 0
	str2 BYTE "random12char", 0
	format1 BYTE "Enter your string:", 0Ah, 0
	format2 BYTE "%s", 0
	result1 BYTE "%s and %s are the same.", 0Ah, 0
	result2 BYTE "%s and %s are NOT the same.", 0Ah, 0

.code
	main PROC c	
		push offset format1
		call printf
		add esp, 4

		push offset str2
		call gets
		add esp, 4

		mov ecx, 0			; loop counter
		mov edx, 11			; loop breaker
		loopbegin:
			cmp ecx, edx
			jg loopend
				mov al, BYTE PTR [str1 + ecx]
				mov bl, BYTE PTR [str2 + ecx]
				cmp al, bl
				jne notequal
					add ecx, 1
					jmp loopbegin

			notequal:
				push offset str2
				push offset str1
				push offset result2
				call printf
				add esp, 12
				jmp ending

			loopend:
				push offset str2
				push offset str1
				push offset result1
				call printf
				add esp, 12
				jmp ending
		
		ending:

	INVOKE ExitProcess, 0	;
	main endp

end