# macro.inc — label macros for splat 0.50.0 asm output (asm/<bin>/*.s), hand-edited.

.macro glabel label
    .global \label
    .type \label, @function
    \label:
.endm

.macro endlabel label
    .size \label, . - \label
.endm

.macro jlabel label
    \label:
.endm

.macro dlabel label
    .global \label
    \label:
.endm

.macro enddlabel label
    .size \label, . - \label
.endm

.macro nonmatching label, size=1
.endm

.macro alabel label
    .global \label
    \label:
.endm
