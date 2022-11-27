[org 0x7c00]  ;all places in memory are 0x7c00 bytes offset so this command offsets all memory calls by that
mov ah, 0x0e  ;put the bios into teletype mode
mov bx, helloWorld   ;move the helloWorld "variable" into bx
	
loop:         ;do { 
	mov al, [bx]     ;    al = *bx  
	cmp al, 0        ;    if(al == 0) 
	je end           ;         break;
	int 0x10         ;    printf("%c", al);
	inc bx           ;    al++;
	jmp loop  ;while(al != 0)
end:

;Make the binary of the code be 512 bytes and end in 0x55aa so it is reconized by BIOS
jmp $

helloWorld:               ;variable to hold string terminated by a 0
    db "Hello World", 0

times 510-($-$$) db 0
dw 0xaa55    ; all bios will read the first block in disk and it must end in aa55
