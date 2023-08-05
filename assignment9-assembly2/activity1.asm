.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type

.data
	;	variables go here
	var1 DWORD 10		; int var1 = 10
	var2 DWORD 20
	var3 DWORD ?		; int var3 (not initialized)
	msg BYTE "ABCDEF %d", 0Ah, 0	; 0Ah ~ \n; the 0 indicates the end of the string, similar to \0
	var DWORD 11223344h
	extern printf:NEAR	
.code
	main PROC c	

	; 1) if msg = "ABCDEF", 0Ah,0, then printf("ABCDEF\n");
	; 2) print 25 also
	push 25
	push offset msg		; push expects to push 4 bytes
	call printf
	add esp, 8			; add the top 8 bytes to the stack to change esp back

	; add variable to printf e.g. printf("%d\n", msg);


	comment !			comment this block

	; part 2
	mov BYTE PTR [var], 55h		; put 55 at the end of var
	mov BYTE PTR [var + 1], 66h		; put 66 at the second last byte 
	mov eax, var		; or "mov eax, DWORD PTR [var]"

	; part 1
	; var3 = var1 + var2
	mov eax, var1		; store var1 in eax
	mov ebx, var2		; store var2 in ebx
	add eax, ebx		; eax = eax + ebx
	mov var3, eax		; var3 = eax (= 30 or 1E in hex)

	mov edx, 0
	mov dl, msg			; since 'A' is only a byte, using eax wont work
	

	mov ebx, offset var2	; ebx = &var2
	add var2, 5			; var2 = 20 + 5
	
	; add 10 to the value ebx is the address of (var2)
	;add [ebx], 10		; this is too complicated for the system
	mov ecx, 10			; using register eases the strain on the system
	add [ebx], ecx		
	mov eax, var2		; set eax = var2 = 35
	!

	INVOKE ExitProcess, 0	;
	main endp


end
