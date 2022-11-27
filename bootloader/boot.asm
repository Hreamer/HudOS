[org 0x7c00]  ;all places in memory are 0x7c00 bytes offset so this command offsets all memory calls by that
	
loop: 
    mov ah, 0                         
	int 0x16               
                       
	mov ah, 0x0e                    
	int 0x10
	jmp loop

;Make the binary of the code be 512 bytes and end in 0x55aa so it is reconized by BIOS
jmp $

times 510-($-$$) db 0
dw 0xaa55    ; all bios will read the first block in disk and it must end in aa55
