/* This software was developed at the National Institute of Standards and
 * Technology by employees of the Federal Government in the course of their
 * official duties. Pursuant to title 17 Section 105 of the United States
 * Code this software is not subject to copyright protection and is in the
 * public domain. NIST assumes no responsibility whatsoever for its use by
 * other parties, and makes no guarantees, expressed or implied, about its
 * quality, reliability, or any other characteristic.

 * We would appreciate acknowledgement if the software is used.
 * The SAMATE project website is: http://samate.nist.gov
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define SIZE_CMD 10
const char cmd[SIZE_CMD] = "/bin/cat ";

int main(int argc, char *argv[])
{
	unsigned i;
	char buff[512];
	char sys[512];
	if (fgets(buff,512 - SIZE_CMD,stdin))
	{
		strcpy(sys, cmd);
		strcat(sys, buff);
		for (i=0;i<5;++i) {
			if(system(sys) < 0)						/* FLAW */
				fprintf(stderr, "system() failed");
		}
	}
	return 0;
}
