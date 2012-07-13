/***********************************************************************/
/* BubblePad - Replacement class for the launchpad of Warp 3/4         */
/* (C) Chris Wohlgemuth 2004                                           */
/*                                                                     */
/* http://www.os2world.com/cdwriting                                   */
/* http://www.geocities.com/SiliconValley/Sector/5785/                 */
/*                                                                     */
/***********************************************************************/
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

#define INCL_WIN
#define INCL_DOS

#include <os2.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "defines.h"
#include "bubblepadres.h"
#include "bubblepd.h"

MRESULT EXPENTRY storeWindowProc(HWND hwnd, ULONG msg,MPARAM mp1,MPARAM mp2 )
{
#if 0
  HPS hps;
  RECTL rcl;

  switch (msg)
    {
      /*    case WM_PAINT:
            hps=WinBeginPaint(hwnd,NULLHANDLE,&rcl);
            WinFillRect(hps,&rcl,CLR_RED);
            WinEndPaint(hps);
            break;
            case WM_DESTROY:
            return (MRESULT) HT_TRANSPARENT;*/
    default:
      break;
    }
#endif
  return WinDefWindowProc(hwnd,msg,mp1,mp2);	
}


BOOL getMessage(char* text,ULONG ulID, LONG lSizeText, HMODULE hResource,HWND hwnd)
{
  if(!WinLoadString(WinQueryAnchorBlock(hwnd),hResource,ulID,lSizeText,text)) {
    strcpy(text,"");
    return FALSE;
  }
  return TRUE;
}

/****************************************************
 *                                                  *
 * This funktion returns the running OS version:    *
 *                                                  *
 * 30: Warp 3, 40 Warp 4 etc.                       *
 *                                                  *
 ****************************************************/
ULONG cwQueryOSRelease(void)
{
  static ULONG ulVersionMinor=0;

  if(!ulVersionMinor)
    if(DosQuerySysInfo(QSV_VERSION_MINOR, QSV_VERSION_MINOR, &ulVersionMinor, sizeof(ulVersionMinor)))
      ulVersionMinor=30;/* Default Warp 3 */

  return ulVersionMinor;

}

BOOL cwMoveNotebookButtonsWarp4(HWND hwndDlg, USHORT usID, USHORT usDelta)
{
  if(cwQueryOSRelease()>=40) {
    HENUM henum;
    HWND hwnd;
    
    /* Move the default notebook buttons */
    if((henum=WinBeginEnumWindows(hwndDlg))!=NULLHANDLE) {
      while((hwnd=WinGetNextWindow(henum))!=NULLHANDLE) {
        if(WinQueryWindowUShort(hwnd,QWS_ID)<=usID)
          WinSetWindowBits(hwnd, QWL_STYLE,
                           BS_NOTEBOOKBUTTON, BS_NOTEBOOKBUTTON);
        else {
          SWP swp;
          POINTL ptl= {0};
          ptl.y=usDelta;

          WinMapDlgPoints(hwndDlg, &ptl, 1, TRUE);
          /* Move all other controls */
          if(WinQueryWindowPos(hwnd, &swp))
            WinSetWindowPos(hwnd, NULLHANDLE, swp.x, swp.y-ptl.y,0,0, SWP_MOVE);
        }
      }
      WinEndEnumWindows(henum);
    }
  }
  return TRUE;
}

char SysQueryBootDriveLetter(void)
{
  ULONG ulSysValue;

  if(!DosQuerySysInfo(QSV_BOOT_DRIVE, QSV_BOOT_DRIVE,&ulSysValue,sizeof(ulSysValue)))
    return 'a'+ulSysValue-1;

  return 'c';
} 

#define EXCEPTION_LOGFILE_NAME "bubblepd.log"
/*!**************************************************/
/*                                                  */
/* @@DESC                                           */
/*                                                  */
/* This function may be used to write data into the */
/* traplog file. The syntax is similar to printf(). */
/*                                                  */
/* @@REMARKS                                        */
/*                                                  */
/* The filename of the traplog is defined in the    */
/* include file :hp2.excptLogName.h:ehp2.           */
/*                                                  */
/*                                                  */
/*                                                  */
/*!!*************************************************/
void SysWriteToTrapLog(const char* chrFormat, ...)
{
  char logNameLocal[CCHMAXPATH];
  FILE *fHandle;

  sprintf(logNameLocal,"%c:\\%s", SysQueryBootDriveLetter(), EXCEPTION_LOGFILE_NAME);
  fHandle=fopen(logNameLocal,"a");

  if(fHandle) {
    va_list arg_ptr;
    void *tb;

    va_start (arg_ptr, chrFormat);
    vfprintf(fHandle, chrFormat, arg_ptr);
    va_end (arg_ptr);
    fclose(fHandle);
  }

}








