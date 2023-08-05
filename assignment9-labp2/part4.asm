.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type
extern printf:NEAR

.data
	;	variables go here
	str1 BYTE "ABCDEF", 0
	str2 BYTE "XYZ123", 0
	format BYTE "str2 = %s", 0Ah, 0

.code
	main PROC c	
		mov ecx, offset str1	
		mov edx, offset str2	
		;mov edx, ecx			; change edx from address of "XYZ123" to "ABCDEF" -- aliasing
		
		mov bl, BYTE PTR [str1]
		mov BYTE PTR [str2], bl
		mov bl, BYTE PTR [str1 + 1]
		mov BYTE PTR [str2 + 1], bl
		mov bl, BYTE PTR [str1 + 2]
		mov BYTE PTR [str2 + 2], bl
		mov bl, BYTE PTR [str1 + 3]
		mov BYTE PTR [str2 + 3], bl
		mov bl, BYTE PTR [str1 + 4]
		mov BYTE PTR [str2 + 4], bl
		mov bl, BYTE PTR [str1 + 5]
		mov BYTE PTR [str2 + 5], bl

		push offset str2
		push offset format
		call printf
		add esp, 8

	INVOKE ExitProcess, 0	;
	main endp

end 