#include <script.h>

sentences:
	in shell:
		Script started, output file is typescript
		Script started, output file is fuck
	in file:
		Script started on Sat Sep 19 08:03:50 2015
		Script done on Sat Sep 19 08:03:53 2015

options obligatoires:
	-a:	apprend to file
	-q:	quiet mode (aucune sentences)

options bonus:
	-k:	log keys sent
	-t:	time interval between flushes, default 30s

know:
	rediriger 1 sur file: dup2(file, 1);
	dup: duplique un fd?..
STDIN_FILENO	0
STDOUT_FILENO	1
STDERR_FILENO	2


	gestion du ctrl-C
	touche del affichee
