.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type
extern printf:NEAR
extern scanf:NEAR

.data
	;	variables go here
	var1 DWORD ?
	var2 DWORD ?
	var3 DWORD ?
	msg1 BYTE "Enter your number:", 0Ah, 0
	msg2 BYTE "Maximum is %d", 0Ah, 0
	format BYTE "%d", 0

.code
	main3 PROC c	
		push offset msg1
		call printf
		add esp, 4
		push offset var1
		push offset format
		call scanf
		add esp, 8

		push offset msg1
		call printf
		add esp, 4
		push offset var2
		push offset format
		call scanf
		add esp, 8

		push offset msg1
		call printf
		add esp, 4
		push offset var3
		push offset format
		call scanf
		add esp, 8

		mov eax, var1
		mov ebx, var2
		mov ecx, var3

		cmp eax, ebx
		jg cond1			; jump if var1 > var2, here compare var2 and 3
			cmp ebx, ecx
			jg end2		; print msg for when var2 is the greatest
				jmp end3	; else var3 is the greatest

		cond1:				; rn var1 > var2, now compare var1 and 3
			cmp eax, ecx
			jg end1			; var1 is the greatest
				jmp end3
			

		end1:
			push eax
			push offset msg2
			call printf
			add esp, 8
			jmp ending
		end2:
			push ebx
			push offset msg2
			call printf
			add esp, 8
			jmp ending
		end3:
			push ecx
			push offset msg2
			call printf
			add esp, 8
			jmp ending
		
		ending:
	INVOKE ExitProcess, 0	;
	main3 endp

end