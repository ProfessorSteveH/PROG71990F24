#pragma once

#include "student.h"
#include "professor.h"

// steveh - prog71990-f24 - week06

	// unions work on the principle of OR (attrib1 OR attrib2 OR ... )
typedef union attendee {			// sizeof(PARTICIPANT) = 
	PROFESSOR professor;		// size = 120
	STUDENT student;			// size = 64
} ATTENDEE;

typedef enum type { NONE, STUD, PROF, GUEST } TYPE;

typedef struct participant {
	TYPE type;		
	ATTENDEE attendee;
} PARTICIPANT;

//C - create
//PARTICIPANT Create(name, num, dept);// only 2 of these 3 needed for any create.
									  // how do we determine which?  and how do
                                      // we code this (without too many errors)
//PARTICIPANT Create(type, attendee); // i don't wish to share internal workings
                                      // with users of the software. (and my labels
                                      // are weak)
									  // this is known as encapsulation or 
									  // 'data hiding' and is important in OOP design
PARTICIPANT CreateParticipantFromStudent(STUDENT s);
PARTICIPANT CreateParticipantFromProfessor(PROFESSOR p);



//R - read


//U - update


//D - delete
void DestroyParticipant(PARTICIPANT p);

