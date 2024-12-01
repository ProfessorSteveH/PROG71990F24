// a fully fleshed out ADT system representing a school classroom
//
// prog71990 - fall2024 - professor steveh
//

#include "student.h"
#include <stdio.h>
#include <string.h>

STUDENT createStudent(char Name[], int StudentNum)
{
	STUDENT s;
	strncpy(s.name, Name, STUDENTLEN);
	for (int i = 0; i < (int)strlen(s.name); i++)
		if (s.name[i] == '\n')
			s.name[i] = '\0';
	s.studentnum = StudentNum;
	return s;
}

void printStudent(STUDENT s) 
{ 
	printf("Student: %s, %d\n", s.name, s.studentnum); 
}

bool compareStudents(STUDENT a, STUDENT b)
{
	if (a.studentnum == b.studentnum)			// simple compare of only student number.  can be improved if required
		return true;
	else
		return false;
}

STUDENT copyStudent(STUDENT src)
{
	STUDENT dst = createStudent(src.name, src.studentnum);
	return dst;
}

bool writeStudentToStream(FILE* fp, STUDENT s)
{
	if (fprintf(fp, "STUD\n") < 0)		// msdn says negative return means fail.
		return false;

	if (fprintf(fp, "%s\n", s.name) < 0)		// msdn says negative return means fail.
		return false;

	if (fprintf(fp, "%d\n", s.studentnum) < 0)		// msdn says negative return means fail.
		return false;

	return true;
}

STUDENT readStudentFromStream(FILE* fp)
{
	char nameBuffer[MAXBUFFER];
	int studentNumber;
	fgets(nameBuffer, MAXBUFFER, fp);
	for (size_t i = 0; i < strlen(nameBuffer); i++)
		if (nameBuffer[i] == '\n')
			nameBuffer[i] = '\0';

	fscanf(fp, "%d\n", &studentNumber);
	STUDENT s = createStudent(nameBuffer, studentNumber);
	return s;
}

void disposeStudent(STUDENT s)
{
	//nothing to do.
}
