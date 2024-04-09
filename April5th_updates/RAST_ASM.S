;File: rast_asm.s 
;Contributers: Marc Schroeder, Diego Gonzalez, Juan Diego Serrato
;Project: Down the Hill
;Course: COMP 2659 - Machinery II
;Section: 001
;Instructor: Paul Pospisil
;
;PURPOSE: This file is part of the raster library (stage 2 of the project), 
;and it contains the subroutines 'clearScreen' and 'setVideoBase'. 

;------------------SUBROUTINE-----------------------
;NAME: 	  
;	  clearScreen
;PURPOSE: 
; 	  Clears the screen, i.e. the framebuffer.
;AUTHOR:
;	  All credit to the algorithm are given to Marc Schroeder.
;DETAILS:
; 	  For any questions about this subroutine, Please only contact 
;     Marc Schroeder, only him and God knows how this works
;
		xdef		_clearScreen,_setVideoBase
VIDEO_BASE	EQU	$FFFF8201

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


;--------------SUBROUTINE-----------------
;NAME: setVideoBase
;
;PURPOSE: 
;	   This subroutine take a buffer and set the screen to that buffer.
;	   this function is implemented in 68000 ASL because the instruction movep.
;      must be used. This is so the two bytes of the 16-bit video register 
;      are updated at the same time. Not doing so can trigger a bug if VSYNC 
;      happens midway through the setVideoBase algorithm’s execution, at the point
;      when the two 8-bit portions of the video base register are inconsistent.
;OUTPUT:
;	   None
;
;STACKFRAME
;+------------------+
;|	old A6		    | 0
;|	return address	| 
;+------------------+
;|	BUFFER_OFFSET	| 8
;+------------------+

BUFFER_OFFSET	EQU	8

_setVideoBase:	link	a6,#0
				movem.l	d0-1/a0-1,-(sp)
				
				move.l	#VIDEO_BASE,a0
				move.l	BUFFER_OFFSET(a6),d0
				lsr.l	#8,d0
				
				movep.w	d0,(a0)
				
				movem.l	(sp)+,d0-1/a0-1
				unlk	a6
				rts

zeros:	ds.l		13