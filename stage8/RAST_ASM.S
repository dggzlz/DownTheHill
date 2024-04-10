;File: rast_asm.s 
;Contributers: Marc Schroeder
;Project: Down the Hill
;Course: COMP 2659 - Machinery II
;Section: 001
;Instructor: Paul Pospisil
;
;PURPOSE: This file is part of the raster library (stage 2 of the project), 
;and it contains the subroutine 'clearScreen'. All credit to the algorithm are 
;given to Marc Schroeder.
;
;The subroutine clears the screen.
;
		xdef		_clearScreen

base		equ		64		; offset from SP, not A6

_clearScreen:	movem.l		d0-7/a0-6,-(sp)
		lea		zeros,a0
		movem.l		(a0)+,d1-7/a1-6
		movea.l		base(sp),a0
		adda.l		#32000,a0
		move.w		#614,d0
fillLoop:	movem.l		d1-7/a1-6,-(a0)
		dbra		d0,fillLoop
		movem.l		d1-5,-(a0)
		movem.l		(sp)+,d0-7/a0-6
		rts

zeros:	ds.l		13