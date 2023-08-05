.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type

.data
	;	variables go here


.code
	main PROC c			
	; assembly instructions for main
	; indentation below is not important
	; when storing large numbers e.g. 12345678h (heximal)
	; the most significant bytes (12) is stored last, the least significant (78) is first
		mov ebx, 10		; ebx = 10		length of the instruction is 5 bytes
		mov eax, 15		; eax = 15		the first byte corresponds to 'mov' or whatever instruction
		mov edx, 3		; edx = 3
		mul edx			; eax = eax * 3 , old eax = 15, new eax should = 45
		add eax, ebx	; order doesnt matter for add, but now eax = 10 + 45 = 55
		mov ebx, eax	; set ebx = eax = 55
		; mod can be obtained: ebx - (eax/7)*7

		; use ecx - which wasnt used before - so that integer overflow doesnt occur when dividing
		mov ecx, 7		; ecx = 7
		div ecx			; eax = eax/7, the quotient
		mul ecx			; eax = eax*7
		sub ebx, eax	
		mov eax, ebx	; store the result in eax as requested
					
		INVOKE ExitProcess, 0			; same thing as exit(0)
		main endp		; end main procedure

; end the entire program
end						