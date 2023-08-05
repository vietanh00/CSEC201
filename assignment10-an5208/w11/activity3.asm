.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type

.data
	;	variables go here
	format BYTE "%d! = %d", 0Ah, 0

.code
	main3 PROC c	
		; indentation is just for clarity
		mov eax, 20h
		mov ebx, 0
		; if eax > 10h then eax = 30h and ebx = 40h
		cmp eax, 10h	; eax > 10h 
		jle pastif		; if eax <= 10h then jump to pastif
			mov eax, 30h
			mov ebx, 40h
		pastif:			; eax <= 10h

		
		; if (eax > ebx || ebx < 40h) then ebx = 50h; else ebx = 60h
		cmp eax, ebx
		jg ifblock			; if eax <= ebx then jump to ifblock

			cmp ebx, 40h	; ebx is > 40h
			jl ifblock		; if ebx >= 40h, do pastif2
				mov ebx, 60h
				jmp pastif2

			ifblock:
				mov ebx, 50h

			pastif2:
				add ebx, 1

	INVOKE ExitProcess, 0	;
	main3 endp

end