#pragma once

#include "student.h"
#include "professor.h"

union participant {
	PROFESSOR professor;		// size = 120
	STUDENT student;			// size = 64
};
