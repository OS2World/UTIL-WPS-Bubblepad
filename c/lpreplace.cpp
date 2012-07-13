/*
 * LPReplace - Utility to replace the WPLaunchPad-class
 * with CWBubblePad.
 *
 * (c) 1998-2004 Chris Wohlgemuth
 *
 * http://www.os2world.com/cdwriting
 * http://www.geocities.com/SiliconValley/Sector/5785/
 *
 * V1.01 18.06.2004
 *
 */
/*
 * Copyright (c) Chris Wohlgemuth 1997-2004 
 * All rights reserved.
 *
 * http://www.os2world.com/cdwriting
 * http://www.geocities.com/SiliconValley/Sector/5785/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. The authors name may not be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 */
#define INCL_WINWORKPLACE
#include <os2.h>
#include <stdio.h>
#include <stdlib.h>

void usage(char *argv[])
{
	printf("\n%s - Replaces WPLaunchPad with new class 'CWBubblePad'\n",argv[0]);
	printf("CWBubblePad must already be registered or the replacement fails.\n\n");
	printf("Usage:\n\n %s 1 - replace WPLaunchPad\n",argv[0]);
	printf(" %s 0 - unreplace WPLaunchPad\n\n",argv[0]);
}

int main(int argc, char *argv[])
{
	APIRET rc;

	if(argc<2)
	{
		usage(argv);
		exit(10);
	}
	if(*argv[1]=='1') {
		if(WinReplaceObjectClass("WPLaunchPad","CWBubblePad",TRUE)){
          /*			printf("WPLaunchPad succesful replaced.\n");
			printf("You have to restart your WPS to see the effect.\n");*/
			DosBeep(1000,100);
			exit(0);
		}
		printf("Can't replace WPLaunchPad!\n");
		DosBeep(100,300);
		exit(20);
	}
	if(*argv[1]=='0') {
		if(WinReplaceObjectClass("WPLaunchPad","CWBubblePad",FALSE)) {
          /*			printf("WPLaunchPad unreplaced.\n");
			printf("You have to restart your WPS to see the effect.\n");*/
			DosBeep(1000,100);
			exit(0);
		}
		printf("Can't unreplace WPLaunchPad!\n");
		DosBeep(100,300);
		exit(20);	
	}
	usage(argv);
	exit(20);
}

