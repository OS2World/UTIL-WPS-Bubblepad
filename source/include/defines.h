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
/***********************************************************************/
/* BubblePad - Replacement class for the launchpad of Warp 3/4         */
/* (C) Chris Wohlgemuth                                                */
/*                                                                     */
/* http://www.os2world.com/cdwriting                                   */
/* http://www.geocities.com/SiliconValley/Sector/5785/                 */
/*                                                                     */
/*   various definitions for bubblepad                                 */
/*                                                                     */
/*   Last change: 18.06.2004                                           */
/*                                                                     */
/***********************************************************************/
#define  WM_NEWBUBBLE   WM_USER+1

#define ID_NODRAWERS                 1
#define ID_DELAYVALUE                2
#define ID_SMALLSIZEENABLED          3
#define ID_ICONDISTANCE              4
#define ID_BACKGROUND                5
#define ID_FOREGROUND                6
#define ID_FONT			             7
#define ID_BUBBLEENABLED             8
#define ID_OPENDRAWERBITS            9
#define ID_REOPEN                    10
#define ID_ACTIONBUTTONS             11

#define FONTNAMELENGTH            100
#define MINBUTTONDISTANCE         2
#define MAXBUTTONDISTANCE         18
#define MAXDELAY                  9999
#define MAXBUTTONDELTA            10

/* The name of the hidden window on the launchpad holding the
   object button and some more information.*/
#define ID_STOREWINDOW                1000

/* Useful defines */
#define MRFALSE (MRESULT)FALSE
#define MRTRUE (MRESULT)TRUE

#ifndef BS_NOTEBOOKBUTTON
#define BS_NOTEBOOKBUTTON 8L   /* Warp 4 notebook style */  
#endif

/* Store window class name */
#define STOREWND_CLASS     "CWSTOREWND"
#define STOREWNDBYTES    12
#define STORETHISPTR     0
#define STOREULDRAWER    4
#define STORESUBCLSCNT   8

#define xVal  12      //x-distance of Bubble
#define yVal  12      //y-distance of Bubble
#define delta 0       //use this if you want to reduce the button size

#ifndef MENU_OBJECTPOPUP
#define MENU_OBJECTPOPUP          0x00000001
#endif
