.586					; indicates what assembly (version, type) is being used
.model flat, stdcall	; memory module
.stack 4096				; stack size in bytes
includelib libcmt.lib	; this and the next lib are usually used
includelib legacy_stdio_definitions.lib
ExitProcess PROTO, dwExitCode: DWORD	; prototype for the function and param type

.data
	;	variables go here
	array BYTE 10h, 20h, 30h, 40h

.code
	main1 PROC c			; change this back to main to run
		; push 10 -- add some room for 10
		sub esp, 4
		mov ecx, DWORD PTR [array]		; DWORD PTR -> 4 bytes starting at the array
		mov [esp], ecx		; put this at the location that esp points to

		; push 20
		sub esp, 4
		mov edx, 20
		mov [esp], edx		; put 20 at the location that esp now points to

		; pop eax			; 20
		mov eax, [esp]		; move the content that esp is pointing to
		add esp, 4

		;pop ebx			; 10
		mov ebx, [esp]
		add esp, 4

	INVOKE ExitProcess, 0	;
	main1 endp

end