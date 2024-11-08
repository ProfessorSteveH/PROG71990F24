#include "participant.h"
#include <stdio.h>

// prog7199-f24 - steveh - week10
// participant impl


void PrintParticipant(PARTICIPANT p) {
	switch (p.type) {
	case STUD: PrintStudent(p.attendee.student);
			   break;
	case PROF: PrintProfessor(p.attendee.professor);
			   break;
	default:   fprintf(stderr, "error: unknown participant type specified\n");
			   break;
	}
}