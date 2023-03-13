
/*
 * Copyright (c) Chris Wohlgemuth 1997-2007 
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
/************************************************************************/
/* BubblePad - Replacement class for the launchpad of Warp 3/4          */
/* (C) Chris Wohlgemuth                                                 */
/*                                                                      */
/* http://www.os2world.com/cdwriting                                    */
/* http://www.geocities.com/SiliconValley/Sector/5785/                  */
/*                                                                      */
/* Released under the GNU Public Licence                                */
/* See file COPYING for further information                             */
/*                                                                      */
/* 20.06.98 V1.00:  -First public version                               */
/* 16.08.98 V1.00a: -Corrected bug: fly over help window on some        */
/*                   systems remains visible. Workaround: When help     */
/*                   stucks on the desktop move pointer over another    */
/*                   button                                             */
/*                                                                      */
/* 18.08.98 V1.00b: -Corrected positioning of drawers. Drawers below    */
/*                   or on the left of the launchpad were placed        */
/*                   with some distance to the launchpad                */
/*                  -Timer routines rewritten.                          */
/*                                                                      */
/* 18.08.98 V1.01: -Stucking window problem for drawers with autoclose  */
/*                  feature corrected                                   */
/*                                                                      */
/* 19.09.98 V1.02: -Positioning of help windows for launchpad at the    */
/*                  top of the desktop corrected.                       */
/*                 -Drawer button hide feature added.                   */
/*                 -Individual settings for BubblePads added.           */
/*                 -Bug with broken references causing drawers to       */
/*                  disapear fixed.                                     */
/*                 -Added saving of drawer state. Drawers are reopened  */
/*                  on next reboot. Doesn't work with normal open/close */
/*                 -Moved button reordering from wpRefreshDrawer()      */
/*                  to wpSetDrawerHWND(). This eliminates the flickering*/
/*                  when opening drawers.                               */
/*                                                                      */
/* 13.11.98 V1.03: -Option to disable/enable the reopening of drawers   */
/*                  on reboot.                                          */
/*                 -Setup strings for the bubblepad features added.     */
/*                 -Option to remove each action button added           */
/*                                                                      */
/* 28.12.98 V1.04: -Bug corrected which caused opening of bubblepad     */
/*                  with default values when LAUNCHPAD entry was present*/
/*                  in AUTOSTART line of the config.sys. This bug was   */
/*                  introduced with the setup strings of V1.03.         */
/*                                                                      */
/* 22.06.03 V1.05: -Export of M_WPLnchCWClassData, M_WPLnchCWCClassData */
/*                  and M_WPLnchCWNewClass wasn't defined.              */
/*                  -> No subclassing possible                          */
/*                 -Notebook buttons are moved on Warp 4                */
/*                                                                      */
/* 26.10.03 V1.06: -BubblePad method names were mangled.                */
/*                 -Fixed some minor memory leaks.                      */
/*                 -Templates are painted as templates now. For mini    */
/*                  icons there's a small mark.                         */
/*                 -Clicking on templates works as intended  (like      */
/*                  normal templates).                                  */
/*                 -Corrected some errors in the english NLV. Thanks    */
/*                  to Peter Weilbacher for the patch.                  */
/*                                                                      */
/* 18.06.04 V1.07: -Fixed crash (endless loop) on eCS 1.1.              */
/*                 -Clicking 'Shutdown' action button now invokes the   */
/*                  system confirmation dialog.                         */
/*                 -Renamed class to CWBubblePad.                       */
/*                 -Rewritten in C instead of DTS (C++).                */
/*                 -Reworked settings dialogs.                          */
/*                 -Changed license to BSD style.                       */
/*                 -Bubblepd.dll must not be in the libpath anymore.    */
/*                                                                      */
/********************+***************************************************/

/*
 *  This file was generated by the SOM Compiler and Emitter Framework.
 *  Generated using: 
 *      SOM Emitter emitctm: 2.42
 */

#ifndef SOM_Module_bubblepd_Source
#define SOM_Module_bubblepd_Source
#endif
#define CWBubblePad_Class_Source
#define M_CWBubblePad_Class_Source

#define INCL_PM
#define INCL_WIN
#define INCL_DOS
#include <os2.h>

#include "defines.h"
#include "bubblepadres.h"
#include "bubblepd.ih"

MRESULT EXPENTRY bubbleHelpDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2);
BOOL cwMoveNotebookButtonsWarp4(HWND hwndDlg, USHORT usID, USHORT usDelta);
void SysWriteToTrapLog(const char* chrFormat, ...);
BOOL getMessage(char* text,ULONG ulID, LONG lSizeText, HMODULE hResource,HWND hwnd);
MRESULT EXPENTRY storeWindowProc(HWND hwnd, ULONG msg,MPARAM mp1,MPARAM mp2 );

HPOINTER hptrTemplate=NULLHANDLE;
HPOINTER hptrSmallTemplate=NULLHANDLE;
static PFNWP  oldButtonProc2=NULLHANDLE;  //place for original button-procedure
static PFNWP  oldLaunchPadProc=NULLHANDLE;  //place for original LaunchPad procedure
static PFNWP  oldLaunchPadProc_2=NULLHANDLE;  //place for original LaunchPad procedure
static PFNWP  oldMenuProc=NULLHANDLE;
static HWND   hwndBubbleWindow=NULLHANDLE;// The handle of the help window

char chrHelpLibraryPath[CCHMAXPATH]="";

/* This is for using the theme classes for drawing */
typedef BOOL (EXPENTRY FNWIZDRAW)(WPObject* somSelf, POWNERITEM pOwnerItem, 
                                   ULONG ulIconSize, ULONG flCnr);
typedef FNWIZDRAW *PFNWIZDRAW;
static PFNWIZDRAW wizDrawIconProc;
BOOL fHaveWizDrawIconProc=FALSE;

typedef BOOL (EXPENTRY FNHASCAIROIMG)(WPObject* somSelf, ULONG ulIdx);
typedef FNHASCAIROIMG *PFNHASCAIROIMG;
static  PFNHASCAIROIMG wizQueryHasCairoImage;

static SOMClass* somGetSomClass(char* chrClassName)
{
  somId    mySomId;
  SOMClass *somClass;

  if((mySomId=somIdFromString(chrClassName))==NULLHANDLE)
    return NULLHANDLE;

  //  somClass=_somClassFromId(SOMClassMgrObject, mySomId);
  /* somFindClass() loads the class if not already done */
  somClass=_somFindClass(SOMClassMgrObject, mySomId, 1, 1);
  SOMFree(mySomId);

  return somClass;
}

/* This function returns the module handle of our class-dll */
HMODULE QueryModuleHandle(void)
{
  static HMODULE hmod=0;
  
  if(!hmod) {
    char *chrPtr;
    PSZ pathname=  //Query Pathname of class file
      _somLocateClassFile(SOMClassMgrObject, somIdFromString("CWBubblePad"),1,2);
    strcpy(chrHelpLibraryPath, pathname);
    if((chrPtr=strrchr(chrHelpLibraryPath, '\\'))!=NULLHANDLE)
      *chrPtr=0;
      strcat(chrHelpLibraryPath, "\\bubblepd.hlp");
    DosQueryModuleHandle(pathname,&hmod);  //Query module handle
  }
  return hmod;
}

/*************************************************************/
/* This dialog procedure handles the Bubblehelp enable page  */
/*************************************************************/
MRESULT EXPENTRY bubbleHelpDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2) {	
  
  switch(msg) {
  case WM_INITDLG :
    {
      CWBubblePad * thisPtr;
      CWBubblePadData *somThis;// = CWObjectGetData(cwObject)

      thisPtr=(CWBubblePad *)LONGFROMMP(mp2);
      if(!somIsObj(thisPtr))
        return (MRESULT) TRUE;

      WinSetWindowULong(hwnd, QWL_USER, LONGFROMMP(mp2));
      /* We have to initialize the dialog controls with the approbiate values */
      
      // Set the focus on the enable checkbox
      WinSetFocus(HWND_DESKTOP, WinWindowFromID(hwnd, CWDLG_ENABLEBUBBLE));
      // Set the linits for the delay spin button
      WinSendMsg(WinWindowFromID(hwnd, CWDLG_DELAYSPIN),
                 SPBM_SETLIMITS, (MPARAM)MAXDELAY, (MPARAM)0);
      // Set the current value for delay
      somThis=CWBubblePadGetData(thisPtr);
      WinSendMsg(WinWindowFromID(hwnd, CWDLG_DELAYSPIN),
                 SPBM_SETCURRENTVALUE,
                 (MPARAM)_delayValue,
                 (MPARAM)NULL);
      // Enable or disable the spin button according to the value of bubbleEnabled
      WinEnableWindow(WinWindowFromID(hwnd, CWDLG_DELAYSPIN),_bubbleEnabled);
      // Set the state of the enable checkbox
      WinSendMsg(WinWindowFromID(hwnd, CWDLG_ENABLEBUBBLE),
                 BM_SETCHECK,MPFROMSHORT(_bubbleEnabled), (MPARAM)NULL);
      
      /* Move default buttons on Warp 4 */
      cwMoveNotebookButtonsWarp4(hwnd,
                                 CWDLG_ENABLEHELP, // every control with an ID below this will be moved
                                 20);       // delta
      return (MRESULT) TRUE;  //Initialisation done
    }
  case WM_DESTROY:
    {
      /* The notebook closes and gets destroyed */
      CWBubblePad * thisPtr;
      CWBubblePadData *somThis;
      ULONG spinValue;

      thisPtr=(CWBubblePad *) WinQueryWindowULong(hwnd, QWL_USER);
      if(!somIsObj(thisPtr))
        break;

      somThis=CWBubblePadGetData(thisPtr);

      // Query the value of the delay spin button
      WinSendMsg(WinWindowFromID(hwnd, CWDLG_DELAYSPIN),
                 SPBM_QUERYVALUE,(MPARAM)&spinValue,
                 MPFROM2SHORT(0,SPBQ_ALWAYSUPDATE));				
      _delayValue=spinValue;
      // Write the new  values to the instance permanent data
      _wpSaveDeferred(thisPtr);
      break;
    }
  case WM_CONTROL:
    /* The window controls send WM_CONTROL messages */
    switch(SHORT1FROMMP(mp1))
      {
      case CWDLG_ENABLEBUBBLE:
        {
          CWBubblePad * thisPtr;
          CWBubblePadData *somThis;
          
          thisPtr=(CWBubblePad *) WinQueryWindowULong(hwnd, QWL_USER);
          if(!somIsObj(thisPtr))
            break;
          
          somThis=CWBubblePadGetData(thisPtr);
          
          if(_bubbleEnabled)// switch the bubbleEnabled state
            _bubbleEnabled=0;						
          else 
            _bubbleEnabled=1;				
          // Enable or disable the spin button according to the value of bubbleEnabled
          WinEnableWindow(WinWindowFromID(hwnd, CWDLG_DELAYSPIN), _bubbleEnabled);			
          // Set the state of the enable checkbox	
          WinSendMsg(WinWindowFromID(hwnd, CWDLG_ENABLEBUBBLE),
                     BM_SETCHECK, MPFROMSHORT(_bubbleEnabled), (MPARAM)NULL);
          
          //   WinPostMsg(WinWindowFromID(->_wpQueryDrawerHWND(thisPtr, 0), 300),
          //   BM_CLICK, FALSE,0);
          break;
        }
      case CWDLG_DELAYSPIN:
        switch (SHORT2FROMMP(mp1))
          {
          case SPBN_UPARROW:
          case SPBN_DOWNARROW:
          case SPBN_ENDSPIN:
            {
              CWBubblePad * thisPtr;
              CWBubblePadData *somThis;
              ULONG spinValue;
              
              thisPtr=(CWBubblePad *) WinQueryWindowULong(hwnd, QWL_USER);
              if(!somIsObj(thisPtr))
                break;
              
              somThis=CWBubblePadGetData(thisPtr);

              // Query the value of the delay spin button
              WinSendMsg(WinWindowFromID(hwnd, CWDLG_DELAYSPIN),
                         SPBM_QUERYVALUE,(MPARAM)&spinValue,
                         MPFROM2SHORT(0,SPBQ_ALWAYSUPDATE));				
              _delayValue=spinValue;			
              break;
            }
          default:
            break;
          }
      } // end switch(SHORT1FROMMP(mp1))
    break;			
    //} // end switch(SHORT2FROMMP(mp1))
    return (MRESULT) TRUE;
  }
  // The WinDefDlgProc() handles the rest of the messages
  return WinDefDlgProc(hwnd, msg, mp1, mp2);
}

/********************************************************/
/* New class function which inserts the bubblehelp page */
/* into the settings notebook                           */
/********************************************************/
SOM_Scope ULONG  SOMLINK cwbubblepad_bpadAddBubbleHelpPage(CWBubblePad *somSelf, 
                                                           HWND hwndNotebook)
{
  PAGEINFO pageinfo;
  char pageName[50];

  /* CWBubblePadData *somThis = CWBubblePadGetData(somSelf); */
  CWBubblePadMethodDebug("CWBubblePad","cwbubblepad_bpadAddBubbleHelpPage");
  
  //Clear the pageinfo structure
  memset((PCH)&pageinfo, 0, sizeof(PAGEINFO));
  //Fill the pageinfo structure
  pageinfo.cb = sizeof(PAGEINFO);
  pageinfo.hwndPage = NULLHANDLE;
  //The page has got a major tab and status text
  pageinfo.usPageStyleFlags = BKA_MAJOR|BKA_STATUSTEXTON;
  pageinfo.usPageInsertFlags = BKA_FIRST;
  //We want page numbers
  pageinfo.usSettingsFlags = SETTINGS_PAGE_NUMBERS;
  //The dialog procedure for this page
  pageinfo.pfnwp = bubbleHelpDlgProc;
  //The resource is in the class file
  pageinfo.resid = QueryModuleHandle();
  pageinfo.dlgid = ID_BUBBLEENABLE;
  pageinfo.pszName = pageName;		
  //We need a pointer to our WPS-object in the dialog procedure
  //to call class functions
  pageinfo.pCreateParams = somSelf;
  //The ID of the help panel for this page
  pageinfo.idDefaultHelpPanel = 001;
  //Tell the WPS the help library name
  pageinfo.pszHelpLibraryName = chrHelpLibraryPath;
  //Load the name for the notebookpage

  if(!WinLoadString(WinQueryAnchorBlock(hwndNotebook), QueryModuleHandle(),
                    ID_BUBBLESTRING,sizeof(pageName), pageName))
    strcpy(pageName, "Bubble Help");
  
  //Insert the page into the settings notebook
  return _wpInsertSettingsPage(somSelf, hwndNotebook, &pageinfo);
}


/*************************************************************/
/* This dialog procedure handles the colour and font page    */
/*************************************************************/			
MRESULT EXPENTRY colorChangeDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2) {
  HINI hini;
  HOBJECT  hObject;
  ULONG  attrFound;
  ULONG  len;
  static RGB b;
  static RGB f;
  static 	font[FONTNAMELENGTH];
  char msgText[250];
  
  switch(msg) {
  case WM_INITDLG : 
    {
      CWBubblePad * thisPtr;
      CWBubblePadData *somThis;// = CWObjectGetData(cwObject)
      
      thisPtr=(CWBubblePad *)LONGFROMMP(mp2);
      if(!somIsObj(thisPtr))
        return (MRESULT) TRUE;
      
      WinSetWindowULong(hwnd,QWL_USER,LONGFROMMP(mp2));
      
      /* We have to initialize the dialog controls with the approbiate values */
      
      // Set the focus on the demo area
      WinSetFocus(HWND_DESKTOP, WinWindowFromID(hwnd, CWDLG_TEXTDEMOFIELD));

      somThis=CWBubblePadGetData(thisPtr);
      // Set the background colour of the demo area
      WinSetPresParam(WinWindowFromID(hwnd, CWDLG_TEXTDEMOFIELD),
                      PP_BACKGROUNDCOLOR,(ULONG)sizeof(RGB) ,&_background );
      // Set the foreground colour of the demo area
      WinSetPresParam(WinWindowFromID(hwnd, CWDLG_TEXTDEMOFIELD),
                      PP_FOREGROUNDCOLOR,(ULONG)sizeof(RGB) ,&_foreground );
      // Set the font of the demo area
      WinSetPresParam(WinWindowFromID(hwnd, CWDLG_TEXTDEMOFIELD),
                      PP_FONTNAMESIZE,(ULONG)sizeof(_fontName),
                      &_fontName );
      b=_background;  // Save value for undo 
      f=_foreground;  //Save value for undo
      memcpy(&font, &_fontName,
             sizeof(_fontName));
      /* Move default buttons on Warp 4 */
      cwMoveNotebookButtonsWarp4(hwnd,
                                 CWDLG_COLORHELP, // every control with an ID below this will be moved
                                 20);       // delta
      return (MRESULT) TRUE;
    }
  case WM_DESTROY:
    {
      /* The notebook closes and gets destroyed */
      CWBubblePad * thisPtr;
      CWBubblePadData *somThis;

      thisPtr=(CWBubblePad *) WinQueryWindowULong(hwnd, QWL_USER);
      if(!somIsObj(thisPtr))
        break;

      somThis=CWBubblePadGetData(thisPtr);

      // Query the current background colour
      len=WinQueryPresParam(WinWindowFromID(hwnd, CWDLG_TEXTDEMOFIELD),
                            PP_BACKGROUNDCOLOR,0,&attrFound, sizeof(_background),
                            &_background, QPF_NOINHERIT);
      // Query the current font
      len=WinQueryPresParam(WinWindowFromID(hwnd, CWDLG_TEXTDEMOFIELD),
                            PP_FONTNAMESIZE,0,&attrFound,sizeof(_fontName),
                            &_fontName,QPF_NOINHERIT);
      // Query the current foreground colour
      len=WinQueryPresParam(WinWindowFromID(hwnd, CWDLG_TEXTDEMOFIELD),
                            PP_FOREGROUNDCOLOR,0,&attrFound,sizeof(_foreground),
                            &_foreground,QPF_NOINHERIT);
      // Save font to instance permanent data
      _wpSaveDeferred(thisPtr);
      break;
    }
  case WM_COMMAND :
    switch (SHORT1FROMMP(mp1)) {
      // Process commands here //
    case CWDLG_COLORUNDO:
      {
        CWBubblePad * thisPtr;
        CWBubblePadData *somThis;
        
        thisPtr=(CWBubblePad *) WinQueryWindowULong(hwnd, QWL_USER);
        if(!somIsObj(thisPtr))
          break;
        
        somThis=CWBubblePadGetData(thisPtr);
        
        /* The undo button was clicked */
        _background=b;  // Restore the previous background colour
        _foreground=f;  // Restore the previous background colour
        // Set the background colour of the demo area
        WinSetPresParam(WinWindowFromID(hwnd, CWDLG_TEXTDEMOFIELD),
                        PP_BACKGROUNDCOLOR,(ULONG)sizeof(RGB) ,
                        &_background );
        // Set the foreground colour of the demo area
        WinSetPresParam(WinWindowFromID(hwnd, CWDLG_TEXTDEMOFIELD),
                        PP_FOREGROUNDCOLOR,(ULONG)sizeof(RGB) ,
                        &_foreground );			
        // Set the font of the demo area
        WinSetPresParam(WinWindowFromID(hwnd, CWDLG_TEXTDEMOFIELD),
                        PP_FONTNAMESIZE,(ULONG) sizeof(font) , &font);
        break;
      }
    case CWDLG_COLORSTANDARD:
      {
        CWBubblePad * thisPtr;
        CWBubblePadData *somThis;
        
        thisPtr=(CWBubblePad *) WinQueryWindowULong(hwnd, QWL_USER);
        if(!somIsObj(thisPtr))
          break;
        
        somThis=CWBubblePadGetData(thisPtr);

        /* The default button was clicked */
        _background.bBlue=180;  // Set the default colours
        _background.bGreen=255; 
        _background.bRed=255;
        _foreground.bBlue=0;
        _foreground.bGreen=0;			
        _foreground.bRed=0;
        // Set the default font
        memcpy(&_fontName,"8.Helv",sizeof("8.Helv"));
        // Set the background colour of the demo area
        WinSetPresParam(WinWindowFromID(hwnd, CWDLG_TEXTDEMOFIELD),
                        PP_BACKGROUNDCOLOR,(ULONG)sizeof(RGB) ,
                        &_background );
        // Set the foreground colour of the demo area
        WinSetPresParam(WinWindowFromID(hwnd, CWDLG_TEXTDEMOFIELD),
                        PP_FOREGROUNDCOLOR,(ULONG)sizeof(RGB) ,
                        &_foreground );
        // Set the font of the demo area
        WinSetPresParam(WinWindowFromID(hwnd, CWDLG_TEXTDEMOFIELD),
                        PP_FONTNAMESIZE,(ULONG)sizeof(_fontName),
                        &_fontName );
        break;
      }
    case CWDLG_COLORPALETTE:
      /* Colour... button was clicked */
      // Open the colorpalette 
      if((hObject=WinQueryObject("<WP_HIRESCLRPAL>"))!=NULLHANDLE) {
        WinOpenObject(hObject,OPEN_DEFAULT,TRUE);
      }
      else {//Error, can't open the palette
        /*  Show an error msg.						   */
        WinLoadString(WinQueryAnchorBlock(hwnd),QueryModuleHandle(),ID_NOCOLORPALETTESTRING,
                      sizeof(msgText), msgText);
        WinMessageBox(HWND_DESKTOP,
                      hwnd,         
                      msgText,          
                      (PSZ) NULL,                      
                      ID_COLORPALETTEMSGBOX,            /* Window ID */
                      MB_OK |
                      MB_MOVEABLE |
                      MB_ICONEXCLAMATION |
                      MB_DEFBUTTON1);                  /* Style     */
        
      }
      break;
    case CWDLG_FONTPALETTE:
      /* Font... button was clicked */
      // Open the fontpalette 
      if((hObject=WinQueryObject("<WP_FNTPAL>"))!=NULLHANDLE) {
        WinOpenObject(hObject,OPEN_DEFAULT,TRUE);
      }
      else {//Error, can't open the palette
        /*  Show an error msg.						   */
        WinLoadString(WinQueryAnchorBlock(hwnd),QueryModuleHandle(),ID_NOFONTPALETTESTRING,
                      sizeof(msgText), msgText);
        WinMessageBox(HWND_DESKTOP,
                      hwnd,         
                      msgText,          
                      (PSZ) NULL,                      
                      ID_COLORPALETTEMSGBOX,                   /* Window ID */
                      MB_OK |
                      MB_MOVEABLE |
                      MB_ICONEXCLAMATION |
                      MB_DEFBUTTON1);                  /* Style     */
      }
      break;
    }
    /* Don't call WinDefDlgProc here, or the dialog gets closed */
    return (MRESULT) TRUE;
  }
  // The WinDefDlgProc() handles the rest of the messages
  return WinDefDlgProc(hwnd, msg, mp1, mp2);
}

SOM_Scope ULONG  SOMLINK cwbubblepad_bpadAddColorChangePage(CWBubblePad *somSelf, 
                                                            HWND hwndNotebook)
{
  PAGEINFO pageinfo;

  /* CWBubblePadData *somThis = CWBubblePadGetData(somSelf); */
  CWBubblePadMethodDebug("CWBubblePad","cwbubblepad_bpadAddColorChangePage");

  //Clear the pageinfo structure
  memset((PCH)&pageinfo, 0, sizeof(PAGEINFO));
  //Fill the pageinfo structure
  pageinfo.cb = sizeof(PAGEINFO);
  pageinfo.hwndPage = NULLHANDLE;
  pageinfo.usPageStyleFlags = BKA_STATUSTEXTON;
  pageinfo.usPageInsertFlags = BKA_FIRST;
  //We want page numbers
  pageinfo.usSettingsFlags = SETTINGS_PAGE_NUMBERS;	
  //The dialog procedure for this page
  pageinfo.pfnwp = colorChangeDlgProc;
  //The resource is in the class file
  pageinfo.resid = QueryModuleHandle();
  pageinfo.dlgid = ID_COLORCHANGE;
  //We need a pointer to our WPS-object in the dialog procedure
  //to call class functions
  pageinfo.pCreateParams = somSelf;
  //The ID of the help panel for this page
  pageinfo.idDefaultHelpPanel = 202;
  //Tell the WPS the help library name
  pageinfo.pszHelpLibraryName = chrHelpLibraryPath;
  //We have no major tab so we need no name

  //Insert the page into the settings notebook
  return _wpInsertSettingsPage(somSelf, hwndNotebook, &pageinfo);
}

/*************************************************************/
/* This dialog procedure handles the third option page       */
/*************************************************************/
MRESULT EXPENTRY OptionDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2) {
	
  switch(msg) {
  case WM_INITDLG :	
    {
      CWBubblePad * thisPtr;
      CWBubblePadData *somThis;

      thisPtr=(CWBubblePad *)LONGFROMMP(mp2);
      if(!somIsObj(thisPtr))
        return (MRESULT) TRUE;

      somThis=CWBubblePadGetData(thisPtr);

      /* We have to initialize the dialog controls with the approbiate values */
      WinSetWindowULong(hwnd,QWL_USER,LONGFROMMP(mp2));
      // Set the focus on the smallsize checkbox
      WinSetFocus(HWND_DESKTOP, WinWindowFromID(hwnd, CWDLG_SMALLSIZE));
      // Set limits of the distance spinbutton
      WinSendMsg(WinWindowFromID(hwnd, CWDLG_DISTANCESPIN),
                 SPBM_SETLIMITS,(MPARAM)MAXBUTTONDISTANCE,(MPARAM)MINBUTTONDISTANCE);
      // Set distance spinbutton to the current value of icondistance
      WinSendMsg(WinWindowFromID(hwnd, CWDLG_DISTANCESPIN),
                 SPBM_SETCURRENTVALUE,
                 (MPARAM)_icondistance,
                 (MPARAM)NULL);
      // Enable or disable the spin button according to the value of smallSizeEnabled
      WinEnableWindow(WinWindowFromID(hwnd, CWDLG_DISTANCESPIN),
                      _smallSizeEnabled);
      // Set the state of the smallSizeEnabled checkbox
      WinSendMsg(WinWindowFromID(hwnd, CWDLG_SMALLSIZE),
                 BM_SETCHECK,MPFROMSHORT(_smallSizeEnabled),(MPARAM)NULL);
      // Enable or disable the noDrawers checkbox according to the value of smallSizeEnabled
      WinEnableWindow(WinWindowFromID(hwnd, CWDLG_NODRAWERS), _smallSizeEnabled);
      // Set the state of the noDrawers checkbox
      WinSendMsg(WinWindowFromID(hwnd, CWDLG_NODRAWERS),
                 BM_SETCHECK,MPFROMSHORT(_noDrawers),
                 (MPARAM)NULL);
      // Set the state of the ReOpenDrawers checkbox
      WinSendMsg(WinWindowFromID(hwnd, CWDLG_REOPEN),
                 BM_SETCHECK,MPFROMSHORT(_ulReOpen),(MPARAM)NULL);
      /* Move default buttons on Warp 4 */
      cwMoveNotebookButtonsWarp4(hwnd,
                                 CWDLG_SIZEHELP, // every control with an ID below this will be moved
                                 20);      // delta
      return (MRESULT) TRUE;
    }
  case WM_DESTROY:
    {
      /* The notebook closes and gets destroyed */
      CWBubblePad * thisPtr;
      
      thisPtr=(CWBubblePad *) WinQueryWindowULong(hwnd, QWL_USER);
      if(!somIsObj(thisPtr))
        break;

      // Save the value to the instance data
      _wpSaveDeferred(thisPtr);
      break;	
    }	
  case WM_CONTROL:
    switch (SHORT2FROMMP(mp1)) {
    case SPBN_ENDSPIN:
      {
        /* The value of the spinbutton has changed */
        CWBubblePad * thisPtr;
        CWBubblePadData *somThis;
        ULONG spinValue;

        thisPtr=(CWBubblePad *) WinQueryWindowULong(hwnd, QWL_USER);
        if(!somIsObj(thisPtr))
          break;
        
        somThis=CWBubblePadGetData(thisPtr);
        
        // Query the new spinbutton value
        WinSendMsg(WinWindowFromID(hwnd, CWDLG_DISTANCESPIN),
                   SPBM_QUERYVALUE,(MPARAM)&spinValue,
                   MPFROM2SHORT(0,SPBQ_ALWAYSUPDATE));		    
        _icondistance=spinValue;
        // Refresh the size of the launchpad
        _wpRefreshDrawer(thisPtr, 0);//0: LaunchPad
        break;
      }
    case BN_CLICKED:
      {
        CWBubblePad * thisPtr;
        CWBubblePadData *somThis;
            
        thisPtr=(CWBubblePad *) WinQueryWindowULong(hwnd, QWL_USER);
        if(!somIsObj(thisPtr))
          break;
        
        somThis=CWBubblePadGetData(thisPtr);
        
        switch(SHORT1FROMMP(mp1)) {
        case CWDLG_SMALLSIZE:
          /* checkbox was clicked */
          if(_smallSizeEnabled)  // Change the value of smallSizeEnabled
            _smallSizeEnabled=0;
          else 
            _smallSizeEnabled=1;				
          // Set the checkbox state
          WinSendMsg(WinWindowFromID(hwnd, CWDLG_SMALLSIZE),
                     BM_SETCHECK,MPFROMSHORT(_smallSizeEnabled),
                     (MPARAM)NULL);
          // Enable/disable the spinbutton
          WinEnableWindow(WinWindowFromID(hwnd, CWDLG_DISTANCESPIN),
                          _smallSizeEnabled);
          // Enable/disable the noDrawers checkbox
          WinEnableWindow(WinWindowFromID(hwnd, CWDLG_NODRAWERS),
                          _smallSizeEnabled);
          // Refresh the size of the launchpad
          _wpRefreshDrawer(thisPtr, 0);//0: LaunchPad
          break;
        case CWDLG_NODRAWERS:
          if(_bpadQueryHideDrawers(thisPtr))  // Change the value of smallSizeEnabled
            _bpadSetHideDrawers(thisPtr, 0);
          else 
            _bpadSetHideDrawers(thisPtr, 1);
          // Set the checkbox state
          WinSendMsg(WinWindowFromID(hwnd, CWDLG_NODRAWERS),
                     BM_SETCHECK,MPFROMSHORT(_bpadQueryHideDrawers(thisPtr)),(MPARAM)NULL);
          // Refresh the size of the launchpad
          _wpRefreshDrawer(thisPtr, 0);//0: LaunchPad
          break;
        case CWDLG_REOPEN:
          /* checkbox was clicked */
          if(_ulReOpen)  // Change the value of smallSizeEnabled
            _ulReOpen=0;
          else 
            _ulReOpen=1;				
          // Set the checkbox state
          WinSendMsg(WinWindowFromID(hwnd, CWDLG_REOPEN),
                     BM_SETCHECK,MPFROMSHORT(_ulReOpen),
                     (MPARAM)NULL);
          break;
        } // end switch(SHORT1FROMMP(mp1))
        break;
      } /* case BN_CLICKED: */
    }// end switch SHORT2FROMMP(mp1)
    return (MRESULT) FALSE;
  }
  // The WinDefDlgProc() handles the rest of the messages
  return WinDefDlgProc(hwnd, msg, mp1, mp2);
}

/********************************************************/
/* New class function which inserts the size option     */
/* page into the settings notebook                      */
/********************************************************/
SOM_Scope ULONG  SOMLINK cwbubblepad_bpadAddOptionPage(CWBubblePad *somSelf, 
                                                       HWND hwndNotebook)
{
  PAGEINFO pageinfo;
  char pageName[30];
  
  /* CWBubblePadData *somThis = CWBubblePadGetData(somSelf); */
  CWBubblePadMethodDebug("CWBubblePad","cwbubblepad_bpadAddOptionPage");

  //Clear the pageinfo structure
  memset((PCH)&pageinfo, 0, sizeof(PAGEINFO));
  //Fill the pageinfo structure
  pageinfo.cb = sizeof(PAGEINFO);
  pageinfo.hwndPage = NULLHANDLE;
  pageinfo.usPageStyleFlags = BKA_MAJOR|BKA_STATUSTEXTON;
  pageinfo.usPageInsertFlags = BKA_FIRST;
  //We want page numbers
  pageinfo.usSettingsFlags = SETTINGS_PAGE_NUMBERS;
  //The dialog procedure for this page
  pageinfo.pfnwp = OptionDlgProc;
  //The resource is in the class file
  pageinfo.resid = QueryModuleHandle();
  pageinfo.dlgid = ID_OPTIONPAGE;
  //We need a pointer to our WPS-object in the dialog procedure
  //to call class functions
  pageinfo.pCreateParams = somSelf;
  //The ID of the help panel for this page
  pageinfo.idDefaultHelpPanel = 200;
  //Tell the WPS the help library name
  pageinfo.pszHelpLibraryName = chrHelpLibraryPath;
  //We have a major tab so we need a name
  if(!getMessage(pageName, ID_SIZESTRING, sizeof(pageName), QueryModuleHandle(), hwndNotebook))
    strcpy(pageName, "Siz~e");
  pageinfo.pszName = pageName;
  
  //Insert the page into the settings notebook
  return _wpInsertSettingsPage(somSelf, hwndNotebook,&pageinfo);
}


/*************************************************************/
/* This dialog procedure handles the action button page      */
/*************************************************************/
MRESULT EXPENTRY ActionButtonDlgProc(HWND hwnd, ULONG msg, MPARAM mp1, MPARAM mp2) {
  
  switch(msg) {
  case WM_INITDLG :	
    {
      CWBubblePad * thisPtr;
      CWBubblePadData *somThis;

      thisPtr=(CWBubblePad *)LONGFROMMP(mp2);
      if(!somIsObj(thisPtr))
        return (MRESULT) TRUE;

      somThis=CWBubblePadGetData(thisPtr);
      /* We have to initialize the dialog controls with the approbiate values */
      WinSetWindowULong(hwnd,QWL_USER,LONGFROMMP(mp2));
      // Set the focus on the smallsize checkbox
      WinSetFocus(HWND_DESKTOP, WinWindowFromID(hwnd, CBID_SHUTDOWN));
      
      // Set the state of the shutdown checkbox
      WinSendMsg(WinWindowFromID(hwnd, CBID_SHUTDOWN),
                 BM_SETCHECK, MPFROMSHORT(_bShutdown),
                 (MPARAM)NULL);
      // Set the state of the lock checkbox
      WinSendMsg(WinWindowFromID(hwnd, CBID_LOCK),
                 BM_SETCHECK,MPFROMSHORT(_bLock),(MPARAM)NULL);
      // Set the state of the windowlist checkbox
      WinSendMsg(WinWindowFromID(hwnd, CBID_WINDOWLIST),
                 BM_SETCHECK,MPFROMSHORT(_bWindowList),
                 (MPARAM)NULL);
      // Set the state of the search checkbox
      WinSendMsg(WinWindowFromID(hwnd, CBID_SEARCH),
                 BM_SETCHECK,MPFROMSHORT(_bSearch),(MPARAM)NULL);
      /* Move default buttons on Warp 4 */
      cwMoveNotebookButtonsWarp4(hwnd,
                                 PBID_ACTIONHELP,    // // every control with an ID below this will be moved
                                 20);       // delta
      return (MRESULT) TRUE;
    }
  case WM_DESTROY:
    {
      /* The notebook closes and gets destroyed */
      CWBubblePad * thisPtr;
      
      thisPtr=(CWBubblePad *) WinQueryWindowULong(hwnd, QWL_USER);
      if(!somIsObj(thisPtr))
        break;

      // Save the value to the instance data
      _wpSaveDeferred(thisPtr);
      break;
    }
  case WM_CONTROL:
    switch (SHORT2FROMMP(mp1)) {
    case BN_CLICKED:
      {
        CWBubblePad * thisPtr;
        CWBubblePadData *somThis;
        
        thisPtr=(CWBubblePad *) WinQueryWindowULong(hwnd, QWL_USER);
        if(!somIsObj(thisPtr))
          break;
        
        somThis=CWBubblePadGetData(thisPtr);

        switch(SHORT1FROMMP(mp1)) {
        case CBID_SHUTDOWN:
          /* checkbox was clicked */
          if(_bShutdown)  // Change the value of smallSizeEnabled
            _bShutdown=FALSE;
          else 
            _bShutdown=TRUE;				
          // Set the checkbox state
          WinSendMsg(WinWindowFromID(hwnd, CBID_SHUTDOWN),
                     BM_SETCHECK,MPFROMSHORT(_bShutdown),
                     (MPARAM)NULL);
          // Refresh the size of the launchpad
          _wpRefreshDrawer(thisPtr, 0);//0: LaunchPad
          break;
        case CBID_LOCK:
          /* checkbox was clicked */
          if(_bLock)  // Change the value of smallSizeEnabled
            _bLock=FALSE;
          else 
            _bLock=TRUE;				
          // Set the checkbox state
          WinSendMsg(WinWindowFromID(hwnd, CBID_LOCK),
                     BM_SETCHECK,MPFROMSHORT(_bLock),
                     (MPARAM)NULL);
          // Refresh the size of the launchpad
          _wpRefreshDrawer(thisPtr, 0);//0: LaunchPad
          break;
        case CBID_WINDOWLIST:
          /* checkbox was clicked */
          if(_bWindowList) // Change the value of smallSizeEnabled
            _bWindowList=FALSE;
          else 
            _bWindowList=TRUE;				
          // Set the checkbox state
          WinSendMsg(WinWindowFromID(hwnd, CBID_WINDOWLIST),
                     BM_SETCHECK,MPFROMSHORT(_bWindowList),
                     (MPARAM)NULL);
          // Refresh the size of the launchpad
          _wpRefreshDrawer(thisPtr, 0);//0: LaunchPad
          break;
        case CBID_SEARCH:
          /* checkbox was clicked */
          if(_bSearch)  // Change the value of smallSizeEnabled
            _bSearch=FALSE;
          else 
            _bSearch=TRUE;				
          // Set the checkbox state
          WinSendMsg(WinWindowFromID(hwnd, CBID_SEARCH),
                     BM_SETCHECK,MPFROMSHORT(_bSearch),(MPARAM)NULL);
          // Refresh the size of the launchpad
          _wpRefreshDrawer(thisPtr, 0);//0: LaunchPad
          break;
        } // end switch(SHORT1FROMMP(mp1))
        break;
      }
    }// end switch SHORT2FROMMP(mp1)
    return (MRESULT) FALSE;
  }
  // The WinDefDlgProc() handles the rest of the messages
  return WinDefDlgProc(hwnd, msg, mp1, mp2);
}


/********************************************************/
/* New class function which inserts the action button   */
/* option page into the settings notebook               */
/********************************************************/
SOM_Scope ULONG  SOMLINK cwbubblepad_bpadAddActionButtonPage(CWBubblePad *somSelf, 
                                                             HWND hwndNotebook)
{
  PAGEINFO pageinfo;

  /* CWBubblePadData *somThis = CWBubblePadGetData(somSelf); */
  CWBubblePadMethodDebug("CWBubblePad","cwbubblepad_bpadAddActionButtonPage");
  
  //Clear the pageinfo structure
  memset((PCH)&pageinfo, 0, sizeof(PAGEINFO));
  //Fill the pageinfo structure
  pageinfo.cb = sizeof(PAGEINFO);
  pageinfo.hwndPage = NULLHANDLE;
  pageinfo.usPageStyleFlags = BKA_STATUSTEXTON;
  pageinfo.usPageInsertFlags = BKA_FIRST;
  //We want page numbers
  pageinfo.usSettingsFlags = SETTINGS_PAGE_NUMBERS;
  //The dialog procedure for this page
  pageinfo.pfnwp = ActionButtonDlgProc;
  //The resource is in the class file
  pageinfo.resid = QueryModuleHandle();
  pageinfo.dlgid = ID_ACTIONBPAGE;
  //We need a pointer to our WPS-object in the dialog procedure
  //to call class functions
  pageinfo.pCreateParams = somSelf;
  //The ID of the help panel for this page
  pageinfo.idDefaultHelpPanel = 400;
  //Tell the WPS the help library name
  pageinfo.pszHelpLibraryName = chrHelpLibraryPath;
  //We have no major tab so we need no name
  
  //Insert the page into the settings notebook
  return _wpInsertSettingsPage(somSelf, hwndNotebook,&pageinfo);
}

SOM_Scope ULONG  SOMLINK cwbubblepad_bpadQueryHideDrawers(CWBubblePad *somSelf)
{
    CWBubblePadData *somThis = CWBubblePadGetData(somSelf);
    CWBubblePadMethodDebug("CWBubblePad","cwbubblepad_bpadQueryHideDrawers");

    /* Return statement to be customized: */
    return _noDrawers;
}

SOM_Scope void  SOMLINK cwbubblepad_bpadSetHideDrawers(CWBubblePad *somSelf, 
                                                       ULONG ulHide)
{
    CWBubblePadData *somThis = CWBubblePadGetData(somSelf);
    CWBubblePadMethodDebug("CWBubblePad","cwbubblepad_bpadSetHideDrawers");
    _noDrawers=ulHide;
}


SOM_Scope BOOL  SOMLINK cwbubblepad_wpSaveState(CWBubblePad *somSelf)
{
  ULONG ulActionButtons;
  somId mySomId;
 
  CWBubblePadData *somThis = CWBubblePadGetData(somSelf);
  CWBubblePadMethodDebug("CWBubblePad","cwbubblepad_wpSaveState");
  
  _wpSaveLong(somSelf, "CWBubblePad",ID_NODRAWERS, _noDrawers);
  _wpSaveLong(somSelf, "CWBubblePad",ID_SMALLSIZEENABLED, _smallSizeEnabled);
  _wpSaveLong(somSelf, "CWBubblePad",ID_DELAYVALUE, _delayValue);
  _wpSaveLong(somSelf, "CWBubblePad",ID_ICONDISTANCE, _icondistance);
  _wpSaveLong(somSelf, "CWBubblePad",ID_BUBBLEENABLED, _bubbleEnabled);
  _wpSaveLong(somSelf, "CWBubblePad",ID_OPENDRAWERBITS, _ulOpenDrawers);
  _wpSaveLong(somSelf, "CWBubblePad",ID_REOPEN, _ulReOpen);
  _wpSaveData(somSelf, "CWBubblePad",ID_BACKGROUND,(PBYTE)&_background,sizeof(RGB));
  _wpSaveData(somSelf, "CWBubblePad",ID_FOREGROUND,(PBYTE)&_foreground,sizeof(RGB));
  _wpSaveString(somSelf, "CWBubblePad",ID_FONT,(PBYTE)&_fontName);
  ulActionButtons=0;
  if(_bShutdown)ulActionButtons+=1;
  if(_bLock)ulActionButtons+=2;
  if(_bWindowList)ulActionButtons+=4;
  if(_bSearch)ulActionButtons+=8;
  _wpSaveLong(somSelf, "CWBubblePad", ID_ACTIONBUTTONS, ulActionButtons);
  
  if((mySomId=somIdFromString("wpSaveState"))!=NULLHANDLE) {
    BOOL rc;
    rc=((somTD_WPObject_wpSaveState)
        somParentNumResolve(_somGetPClsMtabs(_CWBubblePad),
                           1,
                           _somGetMethodToken(_CWBubblePad, mySomId))					 
       )(somSelf);
    SOMFree(mySomId);
    return rc;
  }
  else
    return (CWBubblePad_parent_WPLaunchPad_wpSaveState(somSelf));
}


static BOOL doDrawUserButton(HWND hwnd, HPS hps, BOOL fHilite, WPObject *wpObject)
{
  RECTL rcl;
  MINIRECORDCORE mrec={0};
  CNRDRAWITEMINFO cdii={0};
  OWNERITEM oi={0};
  ULONG fl=0;
  ULONG attrFound;
  union{
    RGB    rgbBackground;
    ULONG  ulBackground;
  }unBackground;
  /* Paint */
  WinQueryWindowRect(hwnd, &rcl);
  
  mrec.cb=sizeof(MINIRECORDCORE);
  cdii.pRecord=(PRECORDCORE)&mrec;
  
  oi.hwnd=hwnd;
  oi.hps=hps;
  oi.rclItem=rcl;
  oi.idItem=CMA_ICON;
  oi.hItem=(ULONG)&cdii;
  
  //GpiCreateLogColorTable(hps, 0, LCOLF_RGB, 0, 0, NULLHANDLE);

  // Query the current background colour
  unBackground.ulBackground=0L;
  if(WinQueryPresParam(WinQueryWindow(hwnd, QW_PARENT),
                       PP_BACKGROUNDCOLOR,0, &attrFound, sizeof(unBackground.rgbBackground),
                       &unBackground.rgbBackground, QPF_NOINHERIT))
    {
      GpiCreateLogColorTable(hps, 0, LCOLF_RGB, 0, 0, NULLHANDLE);
      WinFillRect(hps, &rcl, unBackground.ulBackground);
      // SysWriteToTrapLog("%x %x\n", unBackground.ulBackground, 0x000000ff);
    }
  else
    WinFillRect(hps, &rcl, SYSCLR_DIALOGBACKGROUND /*0x00ff0000*/);

  //    WinFillRect(hps, &rcl, CLR_RED);

  if(fHilite)
    WinDrawBorder(hps, &rcl, 2, 2, 0, 0, 0x800);
  wizDrawIconProc(wpObject, &oi, /*ulIconSize */ rcl.xRight-rcl.xLeft-6, fl);
  
  return TRUE;
}


/*****************************************************************************/
/*  New launchpad button procedure with fly over help			     */
/*****************************************************************************/
static MRESULT EXPENTRY newButtonProc(HWND hwnd, ULONG msg,MPARAM mp1,MPARAM mp2 )
{
  POINTL ptl;
  HPS  hps;
  LONG  ulWinTextLen;
  POINTL aptlPoints[TXTBOX_COUNT];
  RECTL   rcl;
  LONG   deltaX,deltaY;
  static USHORT id=0;//Initialisation new in V1.00a 
  RECTL  rclWork;
  HWND hwndStore;
  static BOOL bDrawn=FALSE;

  switch (msg)
    {
    case DM_DRAGOVER:
      {
        HWND hwndStore;
        BOOL bReturn=FALSE;
        MRESULT mr;

        if(!wizDrawIconProc)
          break;

        hwndStore=WinWindowFromID(WinQueryWindow(hwnd, QW_PARENT),ID_STOREWINDOW);
        if(hwndStore) {
          ULONG num;
          HOBJECT *hObject;
          WPObject *wpObject;
          CWBubblePad *thisPtr;     
          
          /* Launchpad pointer */
          thisPtr=(CWBubblePad*)WinQueryWindowULong(hwndStore,QWL_USER);
          if(somIsObj(thisPtr)) 
            {
              ULONG ulDrawer=WinQueryWindowULong(hwndStore, STOREULDRAWER);
              
              /* Get list of objects */
              hObject=_wpQueryObjectList(thisPtr, ulDrawer, &num);
              
              /* We don't have to check here if we have objects at all because if not
                 we wouldn't have a button... */

              /* Get object of this button */
              wpObject=_wpclsQueryObject(_CWBubblePad, hObject[WinQueryWindowUShort(hwnd, QWS_ID)-200]);
              
              if(somIsObj(wpObject)) 
                {
                  PDRAGINFO pDragInfo=(PDRAGINFO) mp1;
                  if(!bDrawn)
                    {
                      HPS hps;
                      RECTL rectl;
                      SWP swp;
                      
                      /* Draw the rect */
                      hps=DrgGetPS(hwnd);
                      WinQueryWindowPos(hwnd,&swp);
                      rectl.xLeft=1;
                      rectl.yBottom=1;
                      rectl.xRight=swp.cx-1;
                      rectl.yTop=swp.cy-1;

                      WinDrawBorder(hps, &rectl, 1, 1, 0, 0, DB_STANDARD | DB_PATINVERT );  
                      DrgReleasePS(hps);
                      bDrawn=TRUE;
                    }
                  mr=_wpDragOver(wpObject, pDragInfo->hwndSource,(PDRAGINFO) mp1);                  
                  _wpUnlockObject(wpObject);
                  bReturn=TRUE;
                }/* wpObject */
            }/* thisPtr */
        }/* hwndStore */
        if(bReturn)
          return mr;

        break;
      }
    case DM_DRAGLEAVE:
      {
        /* Remove target emphasis here */
        if(wizDrawIconProc)
          {
            HPS hps;
            HWND hwndStore;
        
            hwndStore=WinWindowFromID(WinQueryWindow(hwnd, QW_PARENT),ID_STOREWINDOW);
            if(hwndStore) {
              ULONG num;
              HOBJECT *hObject;
              WPObject *wpObject;
              CWBubblePad *thisPtr;     
              
              /* Launchpad pointer */
              thisPtr=(CWBubblePad*)WinQueryWindowULong(hwndStore,QWL_USER);
              if(somIsObj(thisPtr)) 
                {
                  ULONG ulDrawer=WinQueryWindowULong(hwndStore, STOREULDRAWER);
                  
                  /* Get list of objects */
                  hObject=_wpQueryObjectList(thisPtr, ulDrawer, &num);
                  
                  /* We don't have to check here if we have objects at all because if not
                     we wouldn't have a button... */
                  
                  /* Get object of this button */
                  wpObject=_wpclsQueryObject(_CWBubblePad, hObject[WinQueryWindowUShort(hwnd, QWS_ID)-200]);
                  
                  if(somIsObj(wpObject)) 
                    {
                      hps=DrgGetPS(hwnd);
                      doDrawUserButton(hwnd, hps, FALSE, wpObject);
                      DrgReleasePS(hps);
                      _wpUnlockObject(wpObject);
                    }/* wpObject */
                }/* thisPtr */
            }/* hwndStore */                                                 
            bDrawn=FALSE;
            return (MRESULT) FALSE;
          }/* wizDrawIconProc */
        break;
      }
    case 0x41E: /* WM_MOUSEENTER mp2 holds the other window */
      {
        if(wizDrawIconProc){
          HPS hps;
          RECTL rcl;
          
          hps=WinGetPS(hwnd);
          WinQueryWindowRect(hwnd, &rcl);
          WinDrawBorder(hps, &rcl, 1, 1, 0, 0, 0x400);
          WinReleasePS(hps);
        }
      break;
      }
    case 0x41F: /* WM_MOUSELEAVE mp2 holds the other window? */
      {
        // Mouse left frame
        WinStopTimer(WinQueryAnchorBlock(hwnd), hwnd, 1);  // stop the running timer
        if(hwndBubbleWindow)
          WinDestroyWindow(hwndBubbleWindow);/*  close the bubblewindow  */
        hwndBubbleWindow=NULLHANDLE;
        
        id=WinQueryWindowUShort(hwnd, QWS_ID);

        /* Action buttons are special... */
        if(id<200)
          WinInvalidateRect(hwnd, NULL, FALSE);

        if(wizDrawIconProc)
          {
            HWND hwndStore;
            
            hwndStore=WinWindowFromID(WinQueryWindow(hwnd, QW_PARENT),ID_STOREWINDOW);
            if(hwndStore) {
              ULONG num;
              HOBJECT *hObject;
              WPObject *wpObject;
              CWBubblePad *thisPtr;
              
              thisPtr=(CWBubblePad*)WinQueryWindowULong(hwndStore,QWL_USER);
              if(somIsObj(thisPtr)) {
                ULONG ulDrawer=WinQueryWindowULong(hwndStore, STOREULDRAWER);
                
                hObject=_wpQueryObjectList(thisPtr, ulDrawer, &num);
                
                wpObject=_wpclsQueryObject(_CWBubblePad, hObject[WinQueryWindowUShort(hwnd, QWS_ID)-200]);

                if(somIsObj(wpObject))
                  {
                    HPS hps;
                    
                    hps=WinGetPS(hwnd);
                    doDrawUserButton(hwnd, hps, FALSE, wpObject);
                    WinReleasePS(hps);
                    _wpUnlockObject(wpObject);
                  }/* wpObject */
              }/* thisPtr */
            }/* hwndStore */
          }/* wizDrawIcon */
      break;
      }
    case WM_CONTEXTMENU:
      {
        /* When requesting a context menu the icon of the button is reset to the
           objects icon. For templates we want to have a template icon instead so
           put the template icon into the button again. */
        HWND hwndStore;
        MRESULT mr;

        WinStopTimer(WinQueryAnchorBlock(hwnd), hwnd, 1);  // stop the running timer
        if(hwndBubbleWindow)
          WinDestroyWindow(hwndBubbleWindow);/*  close the bubblewindow  */
        hwndBubbleWindow=NULLHANDLE;

        mr=(*oldButtonProc2)(hwnd,msg,mp1,mp2); /* Show context menu */

        hwndStore=WinWindowFromID(WinQueryWindow(hwnd, QW_PARENT),ID_STOREWINDOW);
        if(hwndStore) {
          ULONG num;
          HOBJECT *hObject;
          WPObject *wpObject;
          CWBubblePad *thisPtr;     
          
          /* Launchpad pointer */
          thisPtr=(CWBubblePad*)WinQueryWindowULong(hwndStore,QWL_USER);
          if(somIsObj(thisPtr)) {
            if(!_wpQueryDisplaySmallIcons(thisPtr)) {
              ULONG ulDrawer=WinQueryWindowULong(hwndStore, STOREULDRAWER);
            
              /* Get list of objects */
              hObject=_wpQueryObjectList(thisPtr, ulDrawer, &num);
              
              /* Get object of this button */
              wpObject=_wpclsQueryObject(_CWBubblePad, hObject[WinQueryWindowUShort(hwnd, QWS_ID)-200]);
              
              if(somIsObj(wpObject)) {
                if((_wpQueryStyle(wpObject) & OBJSTYLE_TEMPLATE)) {
                  /* It's a template so put template pointer into button again */
                  BTNCDATA btCtrl;
                  WNDPARAMS wndParams;
                  
                  memset(&btCtrl,0,sizeof(btCtrl));
                  btCtrl.cb=sizeof(btCtrl);
                  btCtrl.hImage=hptrTemplate;
                  
                  memset(&wndParams,0,sizeof(wndParams));
                  wndParams.fsStatus=WPM_CTLDATA;
                  wndParams.cbCtlData=btCtrl.cb;
                  wndParams.pCtlData=&btCtrl;
                  
                  WinSendMsg(hwnd,WM_SETWINDOWPARAMS,
                             MPFROMP(&wndParams),0);
                }
                _wpUnlockObject(wpObject);
              }/* wpObject */
            }
          }/* thisPtr */
        } /* hwndStore */
        return mr;
      }
    case WM_PAINT:
      {
        HWND hwndStore;
        
        hwndStore=WinWindowFromID(WinQueryWindow(hwnd, QW_PARENT),ID_STOREWINDOW);
        if(hwndStore) {
          ULONG num;
          HOBJECT *hObject;
          WPObject *wpObject;
          CWBubblePad *thisPtr;

          thisPtr=(CWBubblePad*)WinQueryWindowULong(hwndStore,QWL_USER);
          if(somIsObj(thisPtr)) {
            ULONG ulDrawer=WinQueryWindowULong(hwndStore, STOREULDRAWER);

            hObject=_wpQueryObjectList(thisPtr, ulDrawer, &num);
            wpObject=_wpclsQueryObject(_CWBubblePad, hObject[WinQueryWindowUShort(hwnd, QWS_ID)-200]);

            if(somIsObj(wpObject)) {
              if(_wpQueryStyle(wpObject) & OBJSTYLE_TEMPLATE) {
                /* It's a template, paint the icon */
                HPS hps;
                RECTL rcl;
                ULONG ulIconSize;
                MRESULT mr=(*oldButtonProc2)(hwnd,msg,mp1,mp2);
                WinQueryWindowRect(hwnd, &rcl);
                ulIconSize=WinQuerySysValue(HWND_DESKTOP,SV_CXICON);
                hps=WinGetPS(hwnd);

                if(!_wpQueryDisplaySmallIcons(thisPtr)) {
                  if(!ulDrawer) {
                    if(!_wpQueryDisplayText(thisPtr))
                      WinDrawPointer(hps, (rcl.xRight-ulIconSize/2)/2-2 , (rcl.yTop-ulIconSize/2)/2+2, 
                                     _wpQueryIcon(wpObject), DP_MINI);
                    else {
                      POINTL aptl[TXTBOX_COUNT];
                      char text[20];
                      ULONG len;
                      
                      /* Get size of string */
                      WinQueryWindowText(hwnd, sizeof(text), text);
                      len=strlen(text);
                      
                      GpiQueryTextBox(hps, len, text, TXTBOX_COUNT,aptl);
                      
                      WinDrawPointer(hps, (rcl.xRight-ulIconSize/2)/2-2,
                                     (rcl.yTop+aptl[TXTBOX_TOPLEFT].y*1.5-ulIconSize/2)/2+2, 
                                     _wpQueryIcon(wpObject), DP_MINI);
                    }
                  }/* !ulDrawer */
                  else
                    {
                      /* It's a drawer */
                      if(!_wpQueryDisplayTextInDrawers(thisPtr))
                        WinDrawPointer(hps, (rcl.xRight-ulIconSize/2)/2-2 , (rcl.yTop-ulIconSize/2)/2+2, 
                                       _wpQueryIcon(wpObject), DP_MINI);
                      else {
                        POINTL aptl[TXTBOX_COUNT];
                        char text[20];
                        ULONG len;
                        
                        /* Get size of string */
                        WinQueryWindowText(hwnd, sizeof(text), text);
                        len=strlen(text);
                        
                        GpiQueryTextBox(hps, len, text, TXTBOX_COUNT,aptl);
                        
                        WinDrawPointer(hps, (rcl.xRight-ulIconSize/2)/2-2 ,
                                       (rcl.yTop+aptl[TXTBOX_TOPLEFT].y*1.5-ulIconSize/2)/2+2, 
                                       _wpQueryIcon(wpObject), DP_MINI);
                      }
                    }/* !ulDrawer */
                  WinReleasePS(hps);
                  _wpUnlockObject(wpObject);
                  return mr;
                } /* !wpQueryDisplaySmallIcons() */
                else
                  {
                    /* Launchpad displays small icons */
                    if(!ulDrawer) {
                      if(!_wpQueryDisplayText(thisPtr))
                        WinDrawPointer(hps, (rcl.xRight-ulIconSize/2)/2 , (rcl.yTop-ulIconSize/2)/2, 
                                       hptrSmallTemplate, DP_MINI);
                      else {
                        POINTL aptl[TXTBOX_COUNT];
                        char text[20];
                        ULONG len;
                        
                        /* Get size of string */
                        WinQueryWindowText(hwnd, sizeof(text), text);
                        len=strlen(text);
                        
                        GpiQueryTextBox(hps, len, text, TXTBOX_COUNT,aptl);
                        
                        WinDrawPointer(hps, (rcl.xRight-ulIconSize/2)/2-2,
                                       (rcl.yTop+aptl[TXTBOX_TOPLEFT].y*1.5-ulIconSize/2)/2, 
                                       hptrSmallTemplate, DP_MINI);
                      }
                    }
                    else
                      {
                        /* It's a drawer */
                        if(!_wpQueryDisplayTextInDrawers(thisPtr))
                          WinDrawPointer(hps, (rcl.xRight-ulIconSize/2)/2 , (rcl.yTop-ulIconSize/2)/2, 
                                         hptrSmallTemplate, DP_MINI);
                        else {
                          POINTL aptl[TXTBOX_COUNT];
                          char text[20];
                          ULONG len;
                          
                          /* Get size of string */
                          WinQueryWindowText(hwnd, sizeof(text), text);
                          len=strlen(text);
                          
                          GpiQueryTextBox(hps, len, text, TXTBOX_COUNT,aptl);
                          
                          WinDrawPointer(hps, (rcl.xRight-ulIconSize/2)/2-2 ,
                                         (rcl.yTop+aptl[TXTBOX_TOPLEFT].y*1.5-ulIconSize/2)/2, 
                                         hptrSmallTemplate, DP_MINI);
                        }
                      }
                    WinReleasePS(hps);
                    _wpUnlockObject(wpObject); 
                    return mr;
                  }/* else !wpQueryDisplaySmallIcons() */
              }/* OBJSTYLE_TEMPLATE */
              _wpUnlockObject(wpObject); 
            }/* wpObject */
          }
        }
        break;
      }
    case WM_DESTROY:
      WinStopTimer(WinQueryAnchorBlock(hwnd),hwnd,1);//Stop timer if running
      if(hwndBubbleWindow)
        WinDestroyWindow(hwndBubbleWindow);/*  close the bubblewindow  */
      hwndBubbleWindow=0;
      /* Stop delay timer if running */
      WinStopTimer(WinQueryAnchorBlock(hwnd),hwnd,WinQueryWindowUShort(hwnd,QWS_ID));			
      break;
    case WM_NEWBUBBLE:
      { 
        ULONG bubbleEnabled;
        HWND hwndStore;
        CWBubblePad * thisPtr=NULLHANDLE;
        CWBubblePadData *somThis;

        bubbleEnabled=1;
        hwndStore=WinWindowFromID(WinQueryWindow(hwnd,QW_PARENT),ID_STOREWINDOW);
        if(hwndStore)
          thisPtr=(CWBubblePad*) WinQueryWindowULong(hwndStore,QWL_USER);

        if(!somIsObj(thisPtr))
          break;

        somThis=CWBubblePadGetData(thisPtr);        
        bubbleEnabled=_bubbleEnabled;
        
        /*  we have to build a new information window  */
        if(hwndBubbleWindow){// if(){...} new in V1.00a 
          WinDestroyWindow(hwndBubbleWindow);/*  close the bubblewindow  */
          hwndBubbleWindow=0;
        }
        // Query the pointer position
        WinQueryPointerPos(HWND_DESKTOP,&ptl);
        WinMapWindowPoints(HWND_DESKTOP,hwnd,&ptl,1);
        WinQueryWindowRect(hwnd,&rclWork);				
        if(!hwndBubbleWindow 
           && WinPtInRect(WinQueryAnchorBlock(hwnd),&rclWork,&ptl)
           && bubbleEnabled) {
          
          static HWND hwndBubbleClient;
          ULONG style=FCF_BORDER;
          char winText[255];
          char *pBuchst;

          /* Get window text (It's the object title) for size calculating */
          WinQueryWindowText(hwnd,sizeof(winText),winText);
          ulWinTextLen=(LONG)strlen(winText); // Query text length
          
          /* Delete 'Returns' in object title */          
          pBuchst=strchr(winText,10);
          if(pBuchst)	winText[pBuchst-winText]=' ';
          pBuchst=strchr(winText,13);
          if(pBuchst)	winText[pBuchst-winText]=' ';
          
          /* Create help window */
          hwndBubbleWindow=WinCreateStdWindow(HWND_DESKTOP,
                                              0,
                                              &style,
                                              WC_STATIC,
                                              "",
                                              SS_TEXT|DT_CENTER|DT_VCENTER,
                                              NULLHANDLE,
                                              400,
                                              &hwndBubbleClient);
          /* This custom proc handles only the WM_HITTEST msg so the help does not cover the buttons for mouse clicks */
          /*if(hwndBubbleClient)
            oldStaticProc=WinSubclassWindow(hwndBubbleClient,&newStaticProc);
            */
          // Set the font for the help
          WinSetPresParam(hwndBubbleClient,PP_FONTNAMESIZE,
                          sizeof(_fontName),
                          &_fontName);
          /* Calculate text size in pixel */
          hps=WinBeginPaint(hwndBubbleClient,(HPS)NULL,(PRECTL)NULL);
          GpiQueryTextBox(hps,ulWinTextLen,winText,TXTBOX_COUNT,aptlPoints);
          WinEndPaint(hps);
          
          /* Set colors */
          WinSetPresParam(hwndBubbleClient,
                          PP_BACKGROUNDCOLOR,sizeof(RGB) ,
                          &_background );
          WinSetPresParam(hwndBubbleClient,
                          PP_FOREGROUNDCOLOR,sizeof(RGB) ,
                          &_foreground );
          /* Calculate bubble positon and show bubble */
          WinQueryPointerPos(HWND_DESKTOP,&ptl);//Query pointer position in the desktop window
          WinQueryWindowRect(HWND_DESKTOP,&rcl);//Query desktop size
          /*        aptlPoints[TXTBOX_BOTTOMRIGHT].x-aptlPoints[TXTBOX_BOTTOMLEFT].x+7+xVal+ptl.x 
                    > rcl.xRight 
                    ? deltaX=-aptlPoints[TXTBOX_BOTTOMRIGHT].x-aptlPoints[TXTBOX_BOTTOMLEFT].x-xVal-xVal-7 
                    : deltaX=0 ;
                    */
          deltaX=(aptlPoints[TXTBOX_BOTTOMRIGHT].x-aptlPoints[TXTBOX_BOTTOMLEFT].x+7+xVal+ptl.x  > rcl.xRight 
            ? -aptlPoints[TXTBOX_BOTTOMRIGHT].x-aptlPoints[TXTBOX_BOTTOMLEFT].x-xVal-xVal-7 
            : 0 );

          /*          aptlPoints[TXTBOX_TOPLEFT].y-aptlPoints[TXTBOX_BOTTOMLEFT].y+2+yVal+ptl.y 
            > rcl.yTop 
            ? deltaY=-aptlPoints[TXTBOX_TOPLEFT].y-aptlPoints[TXTBOX_BOTTOMLEFT].y-2*yVal-7
            : deltaY=0 ;				*/
          deltaY=(aptlPoints[TXTBOX_TOPLEFT].y-aptlPoints[TXTBOX_BOTTOMLEFT].y+2+yVal+ptl.y 
                  > rcl.yTop 
                  ? -aptlPoints[TXTBOX_TOPLEFT].y-aptlPoints[TXTBOX_BOTTOMLEFT].y-2*yVal-7
                  : 0) ;				
          WinSetWindowPos(hwndBubbleWindow,
                          HWND_DESKTOP,
                          ptl.x+xVal+deltaX,ptl.y+yVal+deltaY,  //deltaY value not used yet
                          aptlPoints[TXTBOX_BOTTOMRIGHT].x-aptlPoints[TXTBOX_BOTTOMLEFT].x+8,
                          aptlPoints[TXTBOX_TOPLEFT].y-aptlPoints[TXTBOX_BOTTOMLEFT].y+2,
                          SWP_SIZE|SWP_MOVE|SWP_SHOW);
          /* Set bubble text */
          WinSetWindowText(hwndBubbleClient,winText);
          WinStartTimer(WinQueryAnchorBlock(hwnd),hwnd,1,35); 
        } // end if(!hwndBubbleWindow)
        break;
      }
    case WM_MOUSEMOVE:
      {
        USHORT  tempID;
        ULONG delayValue;
        CWBubblePad * thisPtr=NULLHANDLE;
        CWBubblePadData *somThis;

        delayValue=250;

        hwndStore=WinWindowFromID(WinQueryWindow(hwnd,QW_PARENT),ID_STOREWINDOW);
        if(hwndStore)
          thisPtr=(CWBubblePad *) WinQueryWindowULong(hwndStore, QWL_USER);
        
        if(somIsObj(thisPtr)) {
          somThis=CWBubblePadGetData(thisPtr);
          delayValue=_delayValue;
        }
        
        tempID=WinQueryWindowUShort(hwnd,QWS_ID);/*  get the id of the window under the pointer  */  			
        if(id!=tempID) {	// New Button?          
          WinStartTimer(WinQueryAnchorBlock(hwnd),hwnd,tempID,(ULONG)delayValue); // New timer for delay
          id=tempID;  // Save ID 
        }
        else {
          if(!hwndBubbleWindow)
            WinStartTimer(WinQueryAnchorBlock(hwnd),hwnd,tempID,(ULONG)delayValue); // New timer for delay	
        }	
        break;
      }
    case WM_TIMER:			
      switch (SHORT1FROMMP(mp1))
        {
        case 1: //Intervall timer
          /* Test pointer position */
          WinQueryPointerPos(HWND_DESKTOP,&ptl);
          WinMapWindowPoints(HWND_DESKTOP,hwnd,&ptl,1);
          WinQueryWindowRect(hwnd,&rclWork);
          if(!WinPtInRect(WinQueryAnchorBlock(hwnd),&rclWork,&ptl))
            {	// Button has changed				 
              WinStopTimer(WinQueryAnchorBlock(hwnd),hwnd,1);  // stop the running timer
              if(hwndBubbleWindow) 
                WinDestroyWindow(hwndBubbleWindow);/*  close the bubblewindow  */
              hwndBubbleWindow=0;
              id=0;
            }		 			
          break;
        default:// delay over
          //					if (SHORT1FROMMP(mp1)==id) {
          if (SHORT1FROMMP(mp1)==WinQueryWindowUShort(hwnd,QWS_ID)) {//our own timer. It has got the window id
            WinStopTimer(WinQueryAnchorBlock(hwnd),hwnd,SHORT1FROMMP(mp1));//Stop the delay timer
            /* Check the pointer position */
            WinQueryPointerPos(HWND_DESKTOP,&ptl);
            WinMapWindowPoints(HWND_DESKTOP,hwnd,&ptl,1);
            WinQueryWindowRect(hwnd,&rclWork);
            if(WinPtInRect(WinQueryAnchorBlock(hwnd),&rclWork,&ptl))
              WinPostMsg(hwnd,WM_NEWBUBBLE,NULL,NULL);//Request a help window
          }
          break;
        }
      break;			
    }
  
  // call the original button procedure to handle the rest of the messages
  if(oldButtonProc2)
    return (*oldButtonProc2)(hwnd,msg,mp1,mp2);	
  else
    return WinDefWindowProc(hwnd,msg,mp1,mp2); //We should never end here...
};

/*
  This is a hack to prevent showing a context menu on templates located on
  the launchpad when the user clicks the button. When clicked the template object
  should show the 'Create another dialog'. This may be done by calling wpMenuItemSelected()
  with a menu id of 101 (create another). But this dialog is only properly filled if
  the templates context menu was shown prior to calling wpMenuItemSelected().
  So when the button is clicked first the context menu is created using wpDisplayMenu().
  During processing of WM_INITMENU in the frame proc the menu is subclassed with this new
  menu proc. The new menu proc finally prevents the showing of the menu for the template
  by removing the SWP_SHOW flag..
 */
static MRESULT EXPENTRY menuProc(HWND hwnd, ULONG msg,MPARAM mp1,MPARAM mp2 )
{

  switch(msg)
    {
    case WM_ADJUSTWINDOWPOS:
      {
        PSWP pswp=(SWP*)PVOIDFROMMP(mp1);
        if(pswp && (pswp->fl & SWP_SHOW)) {
          pswp->fl&= ~SWP_SHOW;
        }
        break;
      }
    case WM_SHOW:
      DosBeep(500, 500);
      return MRFALSE;
    default:
      break;
    }
  return (*oldMenuProc)(hwnd, msg, mp1, mp2);
};

static BOOL handleActionButtonClick(HWND hwnd, USHORT id)
{
  PACTIONS pActions;
  ULONG ulNumActions;
  CWBubblePad *thisPtr;
  HWND hwndStore;
  WPFolder *wpFolder;

  hwndStore=WinWindowFromID(hwnd,ID_STOREWINDOW);
  if(hwndStore) {
    thisPtr=(CWBubblePad*)WinQueryWindowULong(hwndStore,QWL_USER);
    if(somIsObj(thisPtr)) {
      pActions=_wpQueryActionButtons(thisPtr, &ulNumActions);
      if(ulNumActions)
        {
          /* Get current desktop */
          wpFolder=_wpclsQueryFolder(_CWBubblePad, LOCATION_DESKTOP, FALSE);
          if(somIsObj(wpFolder))
            {
              /* Call desktop menu handling routine */
              _wpMenuItemSelected(wpFolder, NULLHANDLE, pActions[id-100].ulMenuId);
              _wpUnlockObject(wpFolder);
              return TRUE;
            }
        }
    }
  }
  return FALSE;
}

static MRESULT EXPENTRY newLaunchPadProc(HWND hwnd, ULONG msg,MPARAM mp1,MPARAM mp2 )
{
  static BOOL bTemplateMenu=FALSE;
  

  switch(msg)
    {
    case WM_SYSCOMMAND:
    case WM_COMMAND:
      if(SHORT1FROMMP(mp2)==CMDSRC_PUSHBUTTON)
        {
          USHORT id=SHORT1FROMMP(mp1);

          /* An action button was clicked. Handling the button here enables the
           shutdown confirmation dialog. The system would sip it normally. Beside that
           on eCS 1.1 (at least) the first action button *always* invokes the shutdown
           even if the shutdown button was removed!!*/
          if(id>=100 && id<200) 
            {
              if(handleActionButtonClick(hwnd, id))
                return MRTRUE;
            }
          if(id>=200 && id< 300)
            {
              /* It's an object button. Try to get the object... */
              HWND hwndStore;

              hwndStore=WinWindowFromID(hwnd,ID_STOREWINDOW);
              if(hwndStore) {
                ULONG num;
                HOBJECT *hObject;
                WPObject *wpObject;
                CWBubblePad *thisPtr;

                thisPtr=(CWBubblePad*)WinQueryWindowULong(hwndStore,QWL_USER);
                if(somIsObj(thisPtr)) {
                  hObject=_wpQueryObjectList(thisPtr, WinQueryWindowULong(hwndStore, STOREULDRAWER), &num);
                  wpObject=_wpclsQueryObject(_CWBubblePad, hObject[id-200]);
                  if(somIsObj(wpObject)) {
                    if(_wpQueryStyle(wpObject) & OBJSTYLE_TEMPLATE) {
                      HWND hwndMenu;
                      POINTL ptl= {0, 0};
                      MENUITEM mi;
                      ULONG ulMenuId;
                     
                      /* Open template dialog (create object) */
                      bTemplateMenu=TRUE;
                      /* The context menu of the template MUST be shown prior to calling
                         wpMenuItemSelected() or otherwise the 'Create object' dialog
                         will not be properly filled. This is done invisible by a somewhat ugly
                         hack in WM_INITMENU. During processing of this message which is done just
                         before the menu is shown the menu window is subclassed with a new menu
                         procedure. This new procedure prevents the display of the menu by keeping
                         it invisible.
                         */
                      WinEnableWindowUpdate(WinWindowFromID(hwnd, id), FALSE);
                      hwndMenu=_wpDisplayMenu(wpObject, hwnd, hwnd, &ptl,MENU_OBJECTPOPUP, 0 );

                      /* When requesting a context menu the icon of the button is reset to the
                         objects icon. For templates we want to have a template icon instead so
                         put the template icon into the button again. */
                      if(!_wpQueryDisplaySmallIcons(thisPtr)) {
                        BTNCDATA btCtrl;
                        WNDPARAMS wndParams;
                        
                        memset(&btCtrl,0,sizeof(btCtrl));
                        btCtrl.cb=sizeof(btCtrl);
                        btCtrl.hImage=hptrTemplate;
                        
                        memset(&wndParams,0,sizeof(wndParams));
                        wndParams.fsStatus=WPM_CTLDATA;
                        wndParams.cbCtlData=btCtrl.cb;
                        wndParams.pCtlData=&btCtrl;
                        
                        WinSendMsg(WinWindowFromID(hwnd, id),WM_SETWINDOWPARAMS,
                                   MPFROMP(&wndParams),0);
                      }
                      
                      WinEnableWindowUpdate(WinWindowFromID(hwnd, id), TRUE);
                      WinSendMsg(hwndMenu, MM_QUERYITEM, MPFROM2SHORT(101, FALSE), &mi);
                      /* Get default template item from 'Create another menu' */
                      ulMenuId=(ULONG)WinSendMsg(mi.hwndSubMenu, MM_QUERYDEFAULTITEMID, MPFROM2SHORT(101, FALSE), &mi);
                      /* Make sure the submenu will not be shown */
                      oldMenuProc=WinSubclassWindow(mi.hwndSubMenu, menuProc);
                      /* Now 'click' the menu item */
                      WinSendMsg(mi.hwndSubMenu, MM_SELECTITEM, MPFROM2SHORT(ulMenuId, FALSE), MPFROM2SHORT(0, TRUE));
                      /* Repaint template picture */
                      WinInvalidateRect(WinWindowFromID(hwnd, id), NULLHANDLE, FALSE);
                      _wpUnlockObject(wpObject);
                      return FALSE;
                    }
                    _wpUnlockObject(wpObject);
                  }/* wpObject */
                }
              }
            }
        }
      break;
    case WM_INITMENU:
      if(bTemplateMenu)
        {
          bTemplateMenu=FALSE;
          /*
            Ok hacking time:
            
            This is a hack to prevent showing a context menu on templates located on
            the launchpad when the user clicks the button. When clicked the template object
            should show the 'Create another dialog'. This may be done by calling wpMenuItemSelected()
            with a menu id of 101 (create another). But this dialog is only properly filled if
            the templates context menu was shown prior to calling wpMenuItemSelected().
            So when the button is clicked first the context menu is created using wpDisplayMenu().
            During processing of WM_INITMENU in the frame proc the menu is subclassed with a new
            menu proc. The new menu proc finally prevents the showing of the menu for the template
            by removing the SWP_SHOW flag..
            */
          oldMenuProc=WinSubclassWindow(HWNDFROMMP(mp2), menuProc);
        }
     case WM_CONTROL:
      {
        switch(SHORT2FROMMP(mp1))
          {
            /* The buttons are created as ownerdrawn */
            case BN_PAINT:
              {
                USHORT id=SHORT1FROMMP(mp1);

                if(id<200){

                  break;
                  DosBeep(5000, 10);
                  return (MRESULT)FALSE;
                }

                /* wizDrawIconProc is queried in cwFillPad() */
                if(wizDrawIconProc)
                  {
                    PUSERBUTTON pub=(PUSERBUTTON)PVOIDFROMMP(mp2);
                    HWND hwndStore;

                    hwndStore=WinWindowFromID(hwnd,ID_STOREWINDOW);
                    if(hwndStore) {
                      ULONG num;
                      HOBJECT *hObject;
                      WPObject *wpObject;
                      CWBubblePad *thisPtr;

                      thisPtr=(CWBubblePad*)WinQueryWindowULong(hwndStore,QWL_USER);
                      if(somIsObj(thisPtr)) {
                        hObject=_wpQueryObjectList(thisPtr, WinQueryWindowULong(hwndStore, STOREULDRAWER), &num);
                        wpObject=_wpclsQueryObject(_CWBubblePad, hObject[id-200]);
                        if(somIsObj(wpObject)) {
                          BOOL rc=doDrawUserButton(pub->hwnd, pub->hps, (pub->fsState & BDS_HILITED)!=0, wpObject);
                          _wpUnlockObject(wpObject);
                          if(rc)
                            return (MRESULT)FALSE;
                        }/* wpObject */
                      }/* thisPtr */
                    }/* hwndStore */
                  }/* wizDrawIcon */
                break;
              }
          default:
            break;
          }
        break;
      }
    default:
      break;
    }
  
  // call the original procedure to handle the rest of the messages
  if(oldLaunchPadProc)
    return (*oldLaunchPadProc)(hwnd,msg,mp1,mp2);	
  else
    return WinDefWindowProc(hwnd,msg,mp1,mp2); //We should never end here...

};

static MRESULT EXPENTRY newLaunchPadProc_2(HWND hwnd, ULONG msg,MPARAM mp1,MPARAM mp2 )
{
  static BOOL bTemplateMenu=FALSE;

  switch(msg)
    {
     case WM_CONTROL:
      {
        switch(SHORT2FROMMP(mp1))
          {
            /* The buttons are created as ownerdrawn */
            case BN_PAINT:
              {
                USHORT id=SHORT1FROMMP(mp1);

                if(id<200){
                  break;
                  DosBeep(5000, 10);
                  return (MRESULT)FALSE;
                }

                /* wizDrawIconProc is queried in cwFillPad() */
                if(wizDrawIconProc)
                  {
                    PUSERBUTTON pub=(PUSERBUTTON)PVOIDFROMMP(mp2);
                    HWND hwndStore;

                    hwndStore=WinWindowFromID(hwnd,ID_STOREWINDOW);
                    if(hwndStore) {
                      ULONG num;
                      HOBJECT *hObject;
                      WPObject *wpObject;
                      CWBubblePad *thisPtr;

                      thisPtr=(CWBubblePad*)WinQueryWindowULong(hwndStore,QWL_USER);
                      if(somIsObj(thisPtr)) {
                        hObject=_wpQueryObjectList(thisPtr, WinQueryWindowULong(hwndStore, STOREULDRAWER), &num);
                        wpObject=_wpclsQueryObject(_CWBubblePad, hObject[id-200]);
                        if(somIsObj(wpObject)) {
                          BOOL rc=doDrawUserButton(pub->hwnd, pub->hps, (pub->fsState & BDS_HILITED)!=0, wpObject);
                          _wpUnlockObject(wpObject);
                          if(rc)
                            return (MRESULT)FALSE;
                        }/* wpObject */
                      }/* thisPtr */
                    }/* hwndStore */
                  }/* wizDrawIcon */
                break;
              }
          default:
            break;
          }
        break;
      }
    case WM_SYSCOMMAND:
    case WM_COMMAND:
      if(SHORT1FROMMP(mp2)==CMDSRC_PUSHBUTTON)
        {
          USHORT id=SHORT1FROMMP(mp1);

          /* An action button was clicked. Handling the button here enables the
           shutdown confirmation dialog. The system would sip it normally. Beside that
           on eCS 1.1 (at least) the first action button *always* invokes the shutdown
           even if the shutdown button was removed!!*/
          if(id>=100 && id<200) 
            {
              if(handleActionButtonClick(hwnd, id))
                return MRTRUE;
            }

          if(id>=200 && id< 300)
            {
              /* It's an object button. Try to get the object... */
              HWND hwndStore;

              hwndStore=WinWindowFromID(hwnd,ID_STOREWINDOW);
              if(hwndStore) {
                ULONG num;
                HOBJECT *hObject;
                WPObject *wpObject;
                CWBubblePad *thisPtr;

                thisPtr=(CWBubblePad*)WinQueryWindowULong(hwndStore,QWL_USER);
                if(somIsObj(thisPtr)) {
                  hObject=_wpQueryObjectList(thisPtr, WinQueryWindowULong(hwndStore, STOREULDRAWER), &num);
                  wpObject=_wpclsQueryObject(_CWBubblePad, hObject[id-200]);
                  if(somIsObj(wpObject)) {
                    if(_wpQueryStyle(wpObject) & OBJSTYLE_TEMPLATE) {
                      HWND hwndMenu;
                      POINTL ptl= {0, 0};
                      MENUITEM mi;
                      ULONG ulMenuId;
                     
                      /* Open template dialog (create object) */
                      bTemplateMenu=TRUE;
                      /* The context menu of the template MUST be shown prior to calling
                         wpMenuItemSelected() or otherwise the 'Create object' dialog
                         will not be properly filled. This is done invisible by a somewhat ugly
                         hack in WM_INITMENU. During processing of this message which is done just
                         before the menu is shown the menu window is subclassed with a new menu
                         procedure. This new procedure prevents the display of the menu by keeping
                         it invisible.
                         */
                      WinEnableWindowUpdate(WinWindowFromID(hwnd, id), FALSE);
                      hwndMenu=_wpDisplayMenu(wpObject, hwnd, hwnd, &ptl,MENU_OBJECTPOPUP, 0 );

                      /* When requesting a context menu the icon of the button is reset to the
                         objects icon. For templates we want to have a template icon instead so
                         put the template icon into the button again. */
                      if(!_wpQueryDisplaySmallIcons(thisPtr)) {
                        BTNCDATA btCtrl;
                        WNDPARAMS wndParams;
                        
                        memset(&btCtrl,0,sizeof(btCtrl));
                        btCtrl.cb=sizeof(btCtrl);
                        btCtrl.hImage=hptrTemplate;
                        
                        memset(&wndParams,0,sizeof(wndParams));
                        wndParams.fsStatus=WPM_CTLDATA;
                        wndParams.cbCtlData=btCtrl.cb;
                        wndParams.pCtlData=&btCtrl;
                        
                        WinSendMsg(WinWindowFromID(hwnd, id),WM_SETWINDOWPARAMS,
                                   MPFROMP(&wndParams),0);
                      }
                      
                      WinEnableWindowUpdate(WinWindowFromID(hwnd, id), TRUE);
                      WinSendMsg(hwndMenu, MM_QUERYITEM, MPFROM2SHORT(101, FALSE), &mi);
                      /* Get default template item from 'Create another menu' */
                      ulMenuId=(ULONG)WinSendMsg(mi.hwndSubMenu, MM_QUERYDEFAULTITEMID, MPFROM2SHORT(101, FALSE), &mi);
                      /* Make sure the submenu will not be shown */
                      oldMenuProc=WinSubclassWindow(mi.hwndSubMenu, menuProc);
                      /* Now 'click' the menu item */
                      WinSendMsg(mi.hwndSubMenu, MM_SELECTITEM, MPFROM2SHORT(ulMenuId, FALSE), MPFROM2SHORT(0, TRUE));
                      /* Repaint template picture */
                      WinInvalidateRect(WinWindowFromID(hwnd, id), NULLHANDLE, FALSE);
                      _wpUnlockObject(wpObject);
                      return FALSE;
                    }
                    _wpUnlockObject(wpObject);
                  }/* wpObject */
                }
              }
            }
        }
      break;
    case WM_INITMENU:
      if(bTemplateMenu)
        {
          bTemplateMenu=FALSE;
          /*
            Ok hacking time:
            
            This is a hack to prevent showing a context menu on templates located on
            the launchpad when the user clicks the button. When clicked the template object
            should show the 'Create another dialog'. This may be done by calling wpMenuItemSelected()
            with a menu id of 101 (create another). But this dialog is only properly filled if
            the templates context menu was shown prior to calling wpMenuItemSelected().
            So when the button is clicked first the context menu is created using wpDisplayMenu().
            During processing of WM_INITMENU in the frame proc the menu is subclassed with a new
            menu proc. The new menu proc finally prevents the showing of the menu for the template
            by removing the SWP_SHOW flag..
            */
          oldMenuProc=WinSubclassWindow(HWNDFROMMP(mp2), menuProc);
        }
    default:
      break;
    }
  
  // call the original procedure to handle the rest of the messages
  if(oldLaunchPadProc_2)
    return (*oldLaunchPadProc_2)(hwnd,msg,mp1,mp2);	
  else
    return WinDefWindowProc(hwnd,msg,mp1,mp2); //We should never end here...

};

SOM_Scope void  SOMLINK cwbubblepad_wpSetDrawerHWND(CWBubblePad *somSelf, 
                                                    ULONG ulDrawer, 
                                                    HWND hwndDrawer)
{
  somId    mySomId;
  PFNWP  tempProc;

  ULONG tempBit;
  ULONG res;
  int hasActionButtons;
  int actionButtonsText;
  int deltaActionButtons;
  ULONG numActionButtons;
  static fCheckedIsCWThemeObject=FALSE;

  CWBubblePadData *somThis = CWBubblePadGetData(somSelf);
  CWBubblePadMethodDebug("CWBubblePad","cwbubblepad_wpSetDrawerHWND");

  actionButtonsText=0;	
  hasActionButtons=1;

  if(!hwndDrawer) {//Drawer closes, no reordering of buttons necessary
    if(ulDrawer)
      {//We have a drawer. Mark it as closed
        ULONG tempBit;
        tempBit=1;
        tempBit=tempBit<<(ulDrawer-1);
        _ulOpenDrawers&=~tempBit;
      }
    if((mySomId=somIdFromString("wpSetDrawerHWND"))!=NULLHANDLE) {
      ((somTD_WPLaunchPad_wpSetDrawerHWND)
       somParentNumResolve(_somGetPClsMtabs(_CWBubblePad),
                           1,
                           _somGetMethodToken(_CWBubblePad, mySomId))
       )(somSelf, ulDrawer, hwndDrawer);
      SOMFree(mySomId);
    }
    else
      CWBubblePad_parent_WPLaunchPad_wpSetDrawerHWND(somSelf, ulDrawer, 
                                                     hwndDrawer);
    return;
  }

  if(!WinWindowFromID(hwndDrawer, 200)){//That's the first Button. If we have it, the launchpad is built.
    // No the pad isn't ready. Call parent and wait for next call
    if((mySomId=somIdFromString("wpSetDrawerHWND"))!=NULLHANDLE) {
      ((somTD_WPLaunchPad_wpSetDrawerHWND)
       somParentNumResolve(_somGetPClsMtabs(_CWBubblePad),
                           1,
                           _somGetMethodToken(_CWBubblePad, mySomId))
       )(somSelf, ulDrawer,hwndDrawer);
      SOMFree(mySomId);
    }
    else
      CWBubblePad_parent_WPLaunchPad_wpSetDrawerHWND(somSelf, ulDrawer, 
                                                     hwndDrawer);
    return;
  }

  // The original Launchpad has built the buttons. We can now reorder them. The Launchpad isn't visible yet.
  // When calling wpSetDrawerHWND() of the parent the launchpad will be displayed  
  if(ulDrawer)
    {//We have a drawer. Mark it as opened, so we can save the open state on shutdown and reopen it on IPL
      ULONG tempBit;
      tempBit=1;
      tempBit=tempBit << (ulDrawer-1);
      _ulOpenDrawers|=tempBit;
      _wpSaveDeferred(somSelf);//Save open state
    }

  
  //Query state of ActionButtons?
  res=_wpQueryActionButtonStyle(somSelf);	
  if(res==ACTION_BUTTONS_OFF)
    hasActionButtons=0;
  if(res==ACTION_BUTTONS_TEXT)
    actionButtonsText=1;
  _wpQueryActionButtons(somSelf, &numActionButtons);
  deltaActionButtons=2;
  if(numActionButtons<=3)
    deltaActionButtons=1;
  if(numActionButtons==1)
    deltaActionButtons=0;

  
  //The Warpcenter is a Child of WPLaunchPad, so it inherits all the features.
  // We substitute WPLaunchPad with WPLnchCW, so the Warpcenter inherits the 
  // bubblehelp but it doesn't need it cause it has its own. So if it's the WarpCenter
  // do nothing.
  if(strcmp(_somGetClassName(somSelf),"SmartCenter")) 
    {// 0 if equal
      // It's not the Warpcenter
      HWND hwnd;
      HWND hwndStore;
      BOOL  isVertical;
      
      // Query the window handle of the drawer
      //It may be the launchpad itself or a drawer
      //hwnd=wpQueryDrawerHWND(ulDrawer);
      hwnd=hwndDrawer;

      
      if(!WinWindowFromID(hwnd, ID_STOREWINDOW)){//We use this window to store our object ptr
        hwndStore=WinCreateWindow(hwnd, STOREWND_CLASS, "StoreWindow",0,0,0,0,0, NULLHANDLE, HWND_TOP,ID_STOREWINDOW,NULL,NULL);
        if(hwndStore)
          WinSetWindowULong(hwndStore, STORESUBCLSCNT, 0L);
      }
      hwndStore=WinWindowFromID(hwnd,ID_STOREWINDOW);

      isVertical=_wpQueryDisplayVertical(somSelf);//true if vertical 

      if(hwnd && hwndStore) {  // Just to catch errors
        int maxcy,maxcy1,maxcy3,maxcy2,maxcx,maxcx1,maxcx2,maxcx3;
        //ULONG xpos,ypos;
        HOBJECT *hobject;
        HENUM henum;
        HWND hwndNext;
        ULONG  num;
        int titlebarSize;
        //        BOOL  succ;
        SWP  desktopSWP;
        SWP  swp;

        WinSetWindowULong(hwndStore,QWL_USER,(ULONG) somSelf);
        WinSetWindowULong(hwndStore,STOREULDRAWER, (ULONG)ulDrawer);

        // Query the list of objects living on this drawer
        hobject=_wpQueryObjectList(somSelf, ulDrawer,&num);
        //xpos=0;
        maxcx=0;
        maxcy=0;						
        maxcx1=-1;
        maxcy1=-1;
        
        henum=WinBeginEnumWindows(hwnd);// We will query all child windows
        while((hwndNext=WinGetNextWindow(henum))!=NULLHANDLE) {
          USHORT  id;
          // Get windowsize and position
          WinQueryWindowPos(hwndNext,(PSWP)&swp);
          
          // Query window ID
          // The small drawer buttons have got ID 3XX
          // The object buttons have got ID 2XX
          // The action buttons (e.g. shutdown) have got ID 1XX
          id=WinQueryWindowUShort(hwndNext,QWS_ID);	
          if(id<400) {
            if(id>=300) //ID 3XX Drawer-Buttons
              {
                maxcy3=swp.cy;//Vert. size of Drawer-Buttons. We need it later
                maxcx3=swp.cx;//Horz. size of Drawer-Buttons
                if(_noDrawers){
                  maxcx3=-(int)(_icondistance/2);
                  maxcy3=-(int)(_icondistance/2);
                }
              }
            else{
              if(id>=200){   //ID 2XX object Buttons on the launchpad
                maxcy2=swp.cy;//Vert. size of Prog-Buttons
                maxcx2=swp.cx;//Horz. size of Prog-Buttons
                maxcx+=swp.cx-delta+_icondistance;  // We need this for sizechanging of the launchpad
                maxcy+=swp.cy-delta+_icondistance;                
              }
              else{
                if(id==100){ //ID 1XX System-Buttons auf der Klickstart
                  //xpos=swp.x;//x-pos of leftmost button
                  //ypos=swp.y;
                  maxcx1=swp.cx;
                  maxcy1=swp.cy;
                  maxcx+=((swp.cx-delta+1)*numActionButtons);// There're 4 system buttons (normaly)
                  maxcy+=((swp.cy-delta+1)*numActionButtons);							
                }
              }
            }				
          }//end id<400
          else {//id>400. One of these windows must be the Titlebar
            char classname[4];
            //Check if it's the titlebar
            if(WinQueryClassName(hwndNext,sizeof(classname),classname)==2) {
              if(*(classname+1)==0x39) {//WC_TITLEBAR
                // We can't use the system defined value for the titlebar size
                // because the user may use a custom font for the titlebar so
                // the size is unknown.
                WinQueryWindowPos(hwndNext,(PSWP)&swp);//Titlebardimensions
                // We have to take care of the titlebar size if we resize the launchpad
                // so save the value
                titlebarSize=swp.cy;//y-size=0 if titlebar isn't visible
              }
            }					
          }
        }
        WinEndEnumWindows(henum);
        
        /****************************************
         *                     
         * Size Launchpad 
         *
         ****************************************/
        WinQueryWindowPos(HWND_DESKTOP,(PSWP)&desktopSWP);//Get desktop size
        WinQueryWindowPos(hwnd,(PSWP)&swp);//Get launchpadsize or drawersize
        // Only resize launchpad if user enabled this feature
        if(_smallSizeEnabled)
          {
            // Hide the launchpad (or drawer) so the user can't see the resizing
            //	WinShowWindow(hwnd,FALSE);				
            HWND lpHWND=_wpQueryDrawerHWND(somSelf, 0);//Query HWND of launchpad
            
            //*************** Launchpad is horizontal				
            if(!isVertical) {
              if(!ulDrawer){
                //Launchpad
                WinSetWindowPos(hwnd, NULLHANDLE,0,0,
                                maxcx+(1+hasActionButtons)*_icondistance
                                -actionButtonsText*(maxcx1-delta)*deltaActionButtons,
                                maxcy3+maxcy2-delta-actionButtonsText*delta+_icondistance/2
                                +2*_icondistance+titlebarSize,
                                SWP_SIZE|SWP_HIDE);
              }
              else {  //Drawer
                SWP  lpSWP;
                if(WinQueryWindowPos(lpHWND,(PSWP)&lpSWP)&&swp.y<lpSWP.y){//got launchpad size and drawer is below launchpad
                  //Check if small drawer fits above launchpad
                  if((_icondistance+maxcy+titlebarSize)<(desktopSWP.cy-(lpSWP.y+lpSWP.cy+titlebarSize)))
                    {// yes, place it above
                      WinSetWindowPos(hwnd, NULLHANDLE,swp.x+(swp.cx-maxcx2-_icondistance)/2,
                                      lpSWP.y+lpSWP.cy+titlebarSize,
                                      maxcx2+_icondistance-delta,
                                      _icondistance+maxcy+titlebarSize,
                                      SWP_SIZE|SWP_MOVE);
                    }
                  else
                    {//No, no place for drawer
                      WinSetWindowPos(hwnd, NULLHANDLE,swp.x+(swp.cx-maxcx2-_icondistance)/2,
                                      lpSWP.y-(_icondistance+maxcy+titlebarSize),
                                      maxcx2+_icondistance-delta,
                                      _icondistance+maxcy+titlebarSize,
                                      SWP_SIZE|SWP_MOVE);						
                    }
                }
                else {//couldn't get launchpad size, using default positions
                  WinSetWindowPos(hwnd, NULLHANDLE,swp.x+(swp.cx-maxcx2-_icondistance)/2,
                                  swp.y,
                                  maxcx2+_icondistance-delta,
                                  _icondistance+maxcy+titlebarSize,
                                  SWP_SIZE|SWP_MOVE);
                }
              }
            }/* if(!isVertical) */
            // ************** Launchpad is vertical **************
            else {
              if(!ulDrawer){//Launchpad
                WinSetWindowPos(hwnd, NULLHANDLE, 0, 0, maxcx3+maxcx2+_icondistance/2+2*_icondistance-delta,
                                maxcy+titlebarSize+(1+hasActionButtons)*_icondistance,SWP_SIZE);
                
              }
              else {  //Drawer needs some position tweaking
                SWP  lpSWP;
                if(WinQueryWindowPos(lpHWND,(PSWP)&lpSWP)&&swp.x<lpSWP.x){//got launchpad size and drawer is left of launchpad
                  //Check if small drawer fits to the right of launchpad
                  if((_icondistance+maxcx)<(desktopSWP.cx-(lpSWP.x+lpSWP.cx)))
                    {// yes, place it on the right side
                      WinSetWindowPos(hwnd, NULLHANDLE, lpSWP.x+lpSWP.cx,
                                      swp.y+(swp.cy-maxcy2-_icondistance)/2,
                                      maxcx+_icondistance,
                                      _icondistance+maxcy2+titlebarSize-delta,
                                      SWP_SIZE|SWP_MOVE);
                    }
                  else
                    {//No, no place for drawer
                      WinSetWindowPos(hwnd,NULLHANDLE,lpSWP.x-(maxcx+_icondistance),
                                      swp.y+(swp.cy-maxcy2-_icondistance)/2,
                                      maxcx+_icondistance,
                                      _icondistance+maxcy2+titlebarSize-delta,
                                      SWP_SIZE|SWP_MOVE);						
                    }
                }
                else {//couldn't get launchpad size, using default positions
                  WinSetWindowPos(hwnd, NULLHANDLE,
                                  swp.x,
                                  swp.y+(swp.cy-maxcy2-_icondistance)/2,
                                  _icondistance+maxcx,
                                  maxcy2+_icondistance+titlebarSize-delta,SWP_SIZE|SWP_MOVE);
                }
              }	
            }
          }/* _smallSizeEnabled*/

        /****************************************
         *                     
         * Size the buttons and change the window procedure
         *
         ****************************************/
        henum=WinBeginEnumWindows(hwnd);
        // We will query all child windows
        while((hwndNext=WinGetNextWindow(henum))!=NULLHANDLE) {
          USHORT id;
          // Query the current position of the buttons
          WinQueryWindowPos(hwndNext,(PSWP)&swp);
          // Query the window ID
          id=WinQueryWindowUShort(hwndNext,QWS_ID);
          if(id>=300)//ID 3XX Drawer-Icons
            {
              if(_smallSizeEnabled) {
                if(id<400) {
                  if(!_noDrawers) {
                    //**************** Launchpad is horizontal *************	
                    if(!isVertical) {
                      // Set new position and size of the icons
                      
                      WinSetWindowPos(hwndNext, NULLHANDLE,
                                      numActionButtons*(maxcx1+1-(hasActionButtons*delta))
                                      +(id-300)*(maxcx2-delta+_icondistance)
                                      -actionButtonsText*(maxcx1-(hasActionButtons*delta))*deltaActionButtons
                                      +(1+hasActionButtons)*_icondistance,
                                      maxcy2-delta-(delta*actionButtonsText)+_icondistance/2+_icondistance,
                                      swp.cx-delta,swp.cy,SWP_MOVE|SWP_SIZE);
                    }
                    //*************** Launchpad is vertical *****************
                    else{
                      //  Set new position and size of the icons
                      WinSetWindowPos(hwndNext, NULLHANDLE,maxcx2-delta+_icondistance/2+_icondistance,
                                      numActionButtons*(maxcy1-delta+1)*hasActionButtons
                                    +(id-300)*(_icondistance+maxcy2-delta)
                                    +(1+hasActionButtons)*_icondistance,
                                    swp.cx,swp.cy-delta,SWP_MOVE|SWP_SIZE);
                    
                  }	// else
                } //if(!NODRAWERS)
                else {
                  WinSetWindowPos(hwndNext, NULLHANDLE, 0, 0, 0, 0, SWP_HIDE);
                  
                } // else if(!NODRAWERS)
              }// endif(id<400)
            }// endif(smallSizeEnabled)
          }
        else //id>=300
          {
            if(id>=200)//ID 2XX Progicons auf der Klickstartleiste
              {
                PFNWP  tempProc;
                WPObject *wpObject;
                PSZ  objectTitle;
                
                // Now we need the class object to get a WPObject* from the HOBJECT
                //wpObject=((M_WPObject*)this->somGetClass())->wpclsQueryObject(hobject[id-200]);
                if(hobject)
                  wpObject=_wpclsQueryObject(_CWBubblePad, hobject[id-200]);

                if(somIsObj(wpObject))
                  {
                    //  We use one of the objects from the launchpad here because if using somSelf we would get the
                    //  proc address for launchpads while objects on the launchpad are shadows. Only inside the shadowclass
                    //  there is some special code to handle launchpad object painting.
                    //  The queried procs are used to do Cairo painting later on.
                    if(!fCheckedIsCWThemeObject)
                      {
                        if(_somIsA(somSelf, somGetSomClass("CWObject")))
                          {
                            //SysWriteToTrapLog("%s %d %x\n", __FUNCTION__, __LINE__, wizDrawIconProc);
                            // Get method for icon painting
                            wizDrawIconProc=(PFNWIZDRAW)somResolveByName(wpObject, "wizDrawIcon");
                            if(wizDrawIconProc)
                              fHaveWizDrawIconProc=TRUE;
                            wizQueryHasCairoImage=(PFNHASCAIROIMG)somResolveByName(wpObject, "wizQueryHasCairoImage");
                          }
                        fCheckedIsCWThemeObject=TRUE;
                      }
                    
                    objectTitle=_wpQueryTitle(wpObject);
                    
                    // Set template icon for templates. In WM_PAINT the object icon will
                    // be painted over the template image. */
                    if((_wpQueryStyle(wpObject) & OBJSTYLE_TEMPLATE) && !_wpQueryDisplaySmallIcons(somSelf))
                      {
                        BTNCDATA btCtrl;
                        WNDPARAMS wndParams;
                        
                        memset(&btCtrl,0,sizeof(btCtrl));
                        btCtrl.cb=sizeof(btCtrl);
                        btCtrl.hImage=hptrTemplate;
                        
                        memset(&wndParams,0,sizeof(wndParams));
                        wndParams.fsStatus=WPM_CTLDATA;
                        wndParams.cbCtlData=btCtrl.cb;
                        wndParams.pCtlData=&btCtrl;
                        
                        WinSendMsg(hwndNext,WM_SETWINDOWPARAMS,
                                   MPFROMP(&wndParams),0);
                      }
                    _wpUnlockObject(wpObject);
                  }/* wpObject */
                else
                  objectTitle="";
                
                // We subclass the window so we can track mouse movements
                // over the buttons and can build a bubble help if the mouse
                // resides over a button.
                // WinSubclassWindow() returns the old procedure and sets our procedure
                // as the default.
                // If the returned procedure is the same as our own we have already subclassed
                // the window otherwise we save the original procedure pointer.


                if(fHaveWizDrawIconProc && !_wpQueryDisplayText(somSelf))
                  {
                    ULONG ulStyle;

                    ulStyle=WinQueryWindowULong(hwndNext,QWL_STYLE);
                    ulStyle|=BS_USERBUTTON;
                    WinSetWindowULong(hwndNext, QWL_STYLE, ulStyle);
                  }

                tempProc=WinSubclassWindow(hwndNext, newButtonProc);
                //      SysWriteToTrapLog("id: %d newButtonProc: %x, tempProc: %x, %x\n",
                //                id, newButtonProc, tempProc, oldButtonProc2);
                if(tempProc!=(*newButtonProc))
                  {
                    oldButtonProc2=tempProc; 
                  }

                // Set the object title as the window title. In our button proc we
                // take this window title and display it in the help window.
                // The original launchpad only sets the window title in this way if
                // you've switched on text on the launchpad.
                WinSetWindowText(hwndNext, objectTitle);
                
                //if(_smallSizeEnabled)
                  //WinSetWindowBits(hwndNext,QWL_STYLE,BS_NOPOINTERFOCUS,BS_NOPOINTERFOCUS);
                if(!ulDrawer)//Launchpad
                  {
                    if(_smallSizeEnabled) {
                      //************ Horizontal
                      if(!isVertical) 
                        // Set new position and size of the icons
                        /* 
                           original:		    WinSetWindowPos(hwndNext,NULL,
                           numActionButtons*(maxcx1+1)+(id-200)*(maxcx2+icondistance)
                           +(1+hasActionButtons)*icondistance
                           -actionButtonsText*maxcx1*deltaActionButtons,
                           icondistance,swp.cx-delta,swp.cy-delta,
                           SWP_MOVE|SWP_SIZE);*/
                        
                        
                        WinSetWindowPos(hwndNext, NULLHANDLE,
                                        numActionButtons*(maxcx1-(hasActionButtons*delta)+1)
                                        +(id-200)*(maxcx2-delta+_icondistance)
                                        +(1+hasActionButtons)*_icondistance
                                        -actionButtonsText*(maxcx1-(hasActionButtons*delta))*deltaActionButtons,
                                        _icondistance,swp.cx-delta,swp.cy-delta-(delta*actionButtonsText),
                                        SWP_MOVE|SWP_SIZE);
                      
                      //************ Vertikal
                      else  
                        // Set new position and size of the icons
                        /*
                          WinSetWindowPos(hwndNext,NULL,icondistance,
                          numActionButtons*(maxcy1+1)+(id-200)*(icondistance+maxcy2)
                          +(1+hasActionButtons)*icondistance,						
                          swp.cx-delta,swp.cy-delta,SWP_MOVE|SWP_SIZE);*/
                          
                          WinSetWindowPos(hwndNext, NULLHANDLE, _icondistance,
                                          numActionButtons*(maxcy1-delta+1)*hasActionButtons
                                          +(id-200)*(_icondistance+maxcy2-delta)
                                          +(1+hasActionButtons)*_icondistance,						
                                          swp.cx-delta,swp.cy-delta,SWP_MOVE|SWP_SIZE);
                          
                    }//endif(smallSizeEnabled)
                  }// endif(!ulDrawer)
                else//Launchpad-drawer
                  {
                    if(_smallSizeEnabled) {
                      //************ Horizontal
                      if(!isVertical)
                        WinSetWindowPos(hwndNext, NULLHANDLE, _icondistance/2,
                                        _icondistance+(id-200)*(maxcy2+_icondistance),
                                        swp.cx-delta,swp.cy-delta,SWP_MOVE|SWP_SIZE);
                      //************ Vertikal
                      else
                        WinSetWindowPos(hwndNext,NULLHANDLE,//swp.x,
                                        _icondistance+(id-200)*(maxcx2+_icondistance),
                                        _icondistance/2,swp.cx-delta,
                                        swp.cy-delta,SWP_MOVE|SWP_SIZE);	
                    }
                  }//#end else Launchpad-drawer

              }
          else  //ID 1XX; shutdown, window list etc.
            {
              PFNWP  tempProc;
              WPObject *wpObject;

              if(hobject)
                wpObject=_wpclsQueryObject(_CWBubblePad, hobject[0]);

              if(somIsObj(wpObject))
                {
                  //  We use one of the objects from the launchpad here because if using somSelf we would get the
                  //  proc address for launchpads while objects on the launchpad are shadows. Only inside the shadowclass
                  //  there is some special code to handle launchpad object painting.
                  //  The queried procs are used to do Cairo painting later on.
                  if(!fCheckedIsCWThemeObject)
                    {
                      if(_somIsA(somSelf, somGetSomClass("CWObject")))
                        {
                          //SysWriteToTrapLog("%s %d %x\n", __FUNCTION__, __LINE__, wizDrawIconProc);
                          // Get method for icon painting
                          wizDrawIconProc=(PFNWIZDRAW)somResolveByName(wpObject, "wizDrawIcon");
                          if(wizDrawIconProc)
                            fHaveWizDrawIconProc=TRUE;
                          wizQueryHasCairoImage=(PFNHASCAIROIMG)somResolveByName(wpObject, "wizQueryHasCairoImage");
                        }
                      fCheckedIsCWThemeObject=TRUE;
                    }
                  _wpUnlockObject(wpObject);
                }/* wpObject */

              if(fHaveWizDrawIconProc && !_wpQueryDisplayText(somSelf))
                {
                  ULONG ulStyle;
                  
                  ulStyle=WinQueryWindowULong(hwndNext,QWL_STYLE);
                  //ulStyle|=BS_USERBUTTON;
                  ulStyle|=BS_NOBORDER;
                  WinSetWindowULong(hwndNext, QWL_STYLE, ulStyle);
                }

              tempProc=WinSubclassWindow(hwndNext, newButtonProc);
              if(tempProc!=(*newButtonProc)){
                oldButtonProc2=tempProc;
              }

              if(_smallSizeEnabled) {
                /*
                  eCS 1.1:
                  For some strange reason the shutdown button does NOT send a WM_COMMAND msg
                  to the frame. Or it is eaten by some other code. This may be related with the
                  strange frame procedure handling in eCS 1.1. See below.
                  */

                if(id==100)// Shutdown button
                  WinSetWindowBits(hwndNext,QWL_STYLE, BS_SYSCOMMAND, BS_SYSCOMMAND);
                //                WinSetWindowBits(hwndNext,QWL_STYLE, BS_NOPOINTERFOCUS, BS_NOPOINTERFOCUS);
                // ********** Launchpad is horizontal	
                if(!isVertical)
                  if(actionButtonsText) {
                    int textDelta2;
                    int textDelta;
                    
                    //ActionButtons with Text
                    textDelta=id-100;
                    textDelta2=textDelta;
                    textDelta2/=2;
                    textDelta&=1;
                    
                    WinSetWindowPos(hwndNext,NULLHANDLE,
                                    _icondistance+textDelta2*(1+maxcx1-delta),
                                    _icondistance+(maxcy1-_icondistance*_noDrawers*2-delta)*textDelta,
                                    swp.cx-delta,(maxcy2+maxcy3)/2-delta,SWP_MOVE|SWP_SIZE);
                  }
                  else {
                    /*
                      original:		  WinSetWindowPos(hwndNext,NULL,
                      icondistance+(id-100)*(1+maxcx1),
                      icondistance,
                      swp.cx-delta,maxcy2+maxcy3+icondistance/2-delta,SWP_MOVE|SWP_SIZE);
                      */
                    
                    WinSetWindowPos(hwndNext, NULLHANDLE,
                                    _icondistance+(id-100)*(1+maxcx1-delta),
                                    _icondistance,
                                    swp.cx-delta,maxcy2+maxcy3+_icondistance/2-delta,SWP_MOVE|SWP_SIZE);
                  }
                    // ******** Verikal
              else
                WinSetWindowPos(hwndNext, NULLHANDLE, _icondistance,
                                _icondistance+(id-100)*(1+swp.cy-delta),
                                maxcx2+maxcx3+_icondistance/2-delta,swp.cy-delta,SWP_MOVE|SWP_SIZE);
              
              }// endif(smallSizeEnabled)
            };
          };
        };
          WinEndEnumWindows(henum);
          
          /* Subclass launchpad (not button) to handle templates */
          
          /*
            eCS 1.1 (and maybe MCP) changed the frame proc handling of the LP.
            In older versions of BubblePad the LP frame was always subclassed here
            on every invocation of the method. This does not work anymore because it
            leads to a circle of procs. Unfortunately during some events our subclassing is
            lost. E.g. adding an object. This discarding of our proc only happens one time 
            and only after this method was called the second time for a particular pad. So a two
            step subclassing was chosen here to ensure in the end the pad remains subclassed
            but prevent a circle of procs (because for a short time we would have subclassed
            the pad with the same proc twice just before the drop of the first proc would have
            happened, leading to a crash).

            It seems the WPS changes internally the default frame proc for the pad at some
            point. At this point in time the first subclassing is lost.
            Interestingly this happens to a CWBubblePad object when the default LP is opened
            even if the default LP class is NOT replaced by CWBubblePad. One would assume
            both object classes are completetly independend because WPLaunchPad doesn't know
            anything about CWBubblePad and the frames of CWBubblePad.

            In the end the following happens. Proc 1 is in effect, on second method invocation
            proc 1 and proc 2 are in effect, after openeing of the default LP or adding an
            object to the pad only proc 2 is in effect and will be used in the future.
            */

          if(hwndDrawer &&  !WinQueryWindowULong(hwndStore, STORESUBCLSCNT)) {
            oldLaunchPadProc=WinSubclassWindow(hwndDrawer, newLaunchPadProc);
            WinSetWindowULong(hwndStore, STORESUBCLSCNT, 1L);
          }
          else if(hwndDrawer && WinQueryWindowULong(hwndStore, STORESUBCLSCNT)==1)
            {
              oldLaunchPadProc_2=WinSubclassWindow(hwndDrawer, newLaunchPadProc_2);
              WinSetWindowULong(hwndStore, STORESUBCLSCNT, 2L);
            }
          WinSetWindowPos(hwnd, NULLHANDLE,0,0,0,0,SWP_SHOW);  // Show the launchpad
      };		
    }; // endif strcmp()
    
  //Make Launchpad visible by calling the parent
  if((mySomId=somIdFromString("wpSetDrawerHWND"))!=NULLHANDLE) {
    ((somTD_WPLaunchPad_wpSetDrawerHWND)
     somParentNumResolve(_somGetPClsMtabs(_CWBubblePad),
                         1,
                         _somGetMethodToken(_CWBubblePad, mySomId))
     )(somSelf, ulDrawer,hwndDrawer);
    SOMFree(mySomId);
  }
  else
    CWBubblePad_parent_WPLaunchPad_wpSetDrawerHWND(somSelf, ulDrawer, 
                                                   hwndDrawer);

  if(fHaveWizDrawIconProc && !_wpQueryDisplayText(somSelf))
    {
      HENUM henum;
      HWND hwndNext;

      henum=WinBeginEnumWindows(hwndDrawer);
      // We will query all child windows
      while((hwndNext=WinGetNextWindow(henum))!=NULLHANDLE) {
        USHORT id;
        // Query the window ID
        id=WinQueryWindowUShort(hwndNext,QWS_ID);
        if(id>=300)//ID 3XX Drawer-Icons
          {
            ;
          }
        else
          {
            if(id>=100)//ID 2XX Progicons auf der Klickstartleiste, ID 1XX; shutdown, window list etc.
              {
                PFNWP  tempProc;

                tempProc=WinSubclassWindow(hwndNext, newButtonProc);
                //      SysWriteToTrapLog("id: %d newButtonProc: %x, tempProc: %x, %x\n",
                //                id, newButtonProc, tempProc, oldButtonProc2);
                if(tempProc!=(*newButtonProc))
                  {
                    /* Don't overwrite oldButtonProc2 here with another proc or otherwise context menus
                       won't work. The first proc we got before does all the WPS stuff. */
                    //oldButtonProc2=tempProc; 
                  }
              }
          }
      }/* while() */
      WinEndEnumWindows(henum);
    }
  return;
}

SOM_Scope BOOL  SOMLINK cwbubblepad_wpSetup(CWBubblePad *somSelf, 
                                            PSZ pszSetupString)
{
  /**************************************************
   *                                                *
   * Supported setupstrings:                        *
   *                                                *
   * LPNODRAWERS=1/0                                *
   * LPBUBBLE=1/0                                   *
   * LPSMALL=1/0                                    *
   * LPREOPENDRAWERS=1/0                            *
   * LPDELAY=1-9999                                 *
   * LPDISTANCE=4-18                                *
   * LPBGCOLOR= RGB                                 *
   * LPFGCOLOR= RGB                                 *
   * LPACTIONBUTTONS=1+2+4+8                        *
   *                                                *
   **************************************************/
  BOOL rcParent;
  char buffer[CCHMAXPATH];
  ULONG ulBufferSize;
  ULONG ulBackground;
  ULONG ulForeground;
  ULONG ulActionButtons;
  somId mySomId;

  CWBubblePadData *somThis = CWBubblePadGetData(somSelf);
  CWBubblePadMethodDebug("CWBubblePad","cwbubblepad_wpSetup");

  if((mySomId=somIdFromString("wpSetup"))!=NULLHANDLE) {
    rcParent=((somTD_WPObject_wpSetup)
              somParentNumResolve(_somGetPClsMtabs(_CWBubblePad),
                                  1,
                                  _somGetMethodToken(_CWBubblePad, mySomId))					 
              )(somSelf, pszSetupString);
    SOMFree(mySomId);
  }
  else
    rcParent=(CWBubblePad_parent_WPLaunchPad_wpSetup(somSelf, pszSetupString));

  /* Doing our own setup here */
  /* If LAUNCHPAD is set in the autostart line of the config.sys */
  /* the WPS calls this function after calling wpRestore() when double clicking */
  /* on the desktop */
  /* To prevent overriding of restored values the initialization of values was moved */
  /* to wpSetupOnce() with version 1.04 */
  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPNODRAWERS",buffer,&ulBufferSize))
    if(buffer[0]=='1') _noDrawers=1;	
  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPBUBBLE",buffer,&ulBufferSize))
    if(buffer[0]=='0') _bubbleEnabled=0;
  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPSMALL",buffer,&ulBufferSize))
    if(buffer[0]=='0') _smallSizeEnabled=0;
  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPREOPENDRAWERS",buffer,&ulBufferSize))
    if(buffer[0]=='1') _ulReOpen=1;		
  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPDELAY", buffer, &ulBufferSize)) {
    _delayValue=atol(buffer);/* convert to long */
    if(_delayValue>MAXDELAY) _delayValue=MAXDELAY;
  }

  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPDISTANCE",buffer,&ulBufferSize)) {
    _icondistance=atol(buffer);
    if(_icondistance<MINBUTTONDISTANCE)_icondistance=MINBUTTONDISTANCE;
    if(_icondistance>MAXBUTTONDISTANCE)_icondistance=MAXBUTTONDISTANCE;
  }
  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPBGCOLOR",buffer,&ulBufferSize)) {
    ulBackground=atol(buffer);
    _background.bBlue=(BYTE)(ulBackground & 0xFF);
    ulBackground=ulBackground>>8;
    _background.bGreen=(BYTE)(ulBackground & 0xFF);
    ulBackground=ulBackground>>8;
    _background.bRed=(BYTE)(ulBackground & 0xFF);
  }
  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPFGCOLOR",buffer,&ulBufferSize)) {
    ulForeground=atol(buffer);
    _foreground.bBlue=(BYTE)(ulForeground & 0xFF);
    ulForeground=ulForeground>>8;
    _foreground.bGreen=(BYTE)(ulForeground & 0xFF);
    ulForeground=ulForeground>>8;
    _foreground.bRed=(BYTE)(ulForeground & 0xFF);
  }
  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPACTIONBUTTONS",buffer,&ulBufferSize)) {
    ulActionButtons=atol(buffer);
    if(~ulActionButtons & 1)_bShutdown=FALSE;
    if(~ulActionButtons & 2)_bLock=FALSE;
    if(~ulActionButtons & 4)_bWindowList=FALSE;
    if(~ulActionButtons & 8)_bSearch=FALSE;
  }

  return rcParent;
}

SOM_Scope ULONG  SOMLINK cwbubblepad_wpAddLaunchPadPage2(CWBubblePad *somSelf, 
                                                         HWND hwndNotebook)
{
  somId mySomId;
  BOOL rc, rc2;
  
  /* CWBubblePadData *somThis = CWBubblePadGetData(somSelf); */
  CWBubblePadMethodDebug("CWBubblePad","cwbubblepad_wpAddLaunchPadPage2");
  
  rc=_bpadAddOptionPage(somSelf, hwndNotebook)&& 
    _bpadAddActionButtonPage(somSelf, hwndNotebook);
  
  if((mySomId=somIdFromString("wpAddLaunchPadPage2"))!=NULLHANDLE) {
    rc2=((somTD_WPLaunchPad_wpAddLaunchPadPage2)
         somParentNumResolve(_somGetPClsMtabs(_CWBubblePad),
                             1,
                             _somGetMethodToken(_CWBubblePad, mySomId))
         )(somSelf, hwndNotebook);
    SOMFree(mySomId);
  }
  else
    rc2=(CWBubblePad_parent_WPLaunchPad_wpAddLaunchPadPage2(somSelf, 
                                                            hwndNotebook));

  return rc && rc2;      
}

SOM_Scope BOOL  SOMLINK cwbubblepad_wpAddSettingsPages(CWBubblePad *somSelf, 
                                                       HWND hwndNotebook)
{
  ULONG   ulPageIdColor=1;
  ULONG   ulPageIdBubble;
  somId mySomId;
  
  /* CWBubblePadData *somThis = CWBubblePadGetData(somSelf); */
  CWBubblePadMethodDebug("CWBubblePad","cwbubblepad_wpAddSettingsPages");

  //The Warpcenter is a Child of WPLaunchPad, so it inherits all the features.
  // We substitute WPLaunchPad with WPLnchCW, so the Warpcenter inherits the 
  // Bubblehelp pages but it doesn't need them cause it has its own bubblehelp.
  
  // Check if it's the Warpcenter (classname is 'SmartCenter')
  // somGetClassName() returns our class name
  if(strcmp(_somGetClassName(somSelf),"SmartCenter")) {// 0 if equal
    BOOL rc;
    //Insert our settings pages
    ulPageIdColor=_bpadAddColorChangePage(somSelf, hwndNotebook);
    ulPageIdBubble=_bpadAddBubbleHelpPage(somSelf, hwndNotebook);

    //call parent
    if((mySomId=somIdFromString("wpAddSettingsPages"))!=NULLHANDLE) {
      rc=((somTD_WPObject_wpAddSettingsPages)
          somParentNumResolve(_somGetPClsMtabs(_CWBubblePad),
                              1,
                              _somGetMethodToken(_CWBubblePad, mySomId))
          )(somSelf ,hwndNotebook);
      SOMFree(mySomId);
    }
    else
      rc=CWBubblePad_parent_WPLaunchPad_wpAddSettingsPages(somSelf, hwndNotebook);
    
    return(ulPageIdColor 
           && ulPageIdBubble && rc);
  }
  else {// If SmartCenter only call parent
    if((mySomId=somIdFromString("wpAddSettingsPages"))!=NULLHANDLE) {
      BOOL rc;
      rc=((somTD_WPObject_wpAddSettingsPages)
          somParentNumResolve(_somGetPClsMtabs(_CWBubblePad),
                              1,
                              _somGetMethodToken(_CWBubblePad, mySomId))
          )(somSelf, hwndNotebook);
      SOMFree(mySomId);
      return rc;
    }
    else
      return CWBubblePad_parent_WPLaunchPad_wpAddSettingsPages(somSelf, hwndNotebook);
  }
  // Durch obige Konstruktion wird die Elternmethode des direkten VorgÑngers aufgerufen,
  // und nicht die ursprÅngliche von WPLaunchPad, falls WPLaunchPad replaced wurde.
  // Durch diesen Aufruf gehen eventuelle Erweiterungen durch Vererbung verloren:
  //            < return WPLaunchPad::wpMenuItemSelected(hwndFrame, ulMenuId); >
  // Dieser Aufruf macht ErgÑnzungen in wpobject.hh erforderlich!!! Wird durch ein VAC-Fixpack vielleicht spÑter
  //erledigt. Obiger Code dÅrfte jetzt ÅberflÅssig sein, da BubblePad nun in C geschrieben ist.
}

/*
 *!!!!
 */

SOM_Scope HWND  SOMLINK cwbubblepad_wpOpen(CWBubblePad *somSelf, 
                                           HWND hwndCnr, ULONG ulView, 
                                           ULONG param)
{
  HWND rcHWND;
  HWND hwndDrawerButton;
  ULONG ulTemp;
  int a;
  somId mySomId;

  CWBubblePadData *somThis = CWBubblePadGetData(somSelf);
  CWBubblePadMethodDebug("CWBubblePad","cwbubblepad_wpOpen");

  if((mySomId=somIdFromString("wpOpen"))!=NULLHANDLE) {
    rcHWND=((somTD_WPObject_wpOpen)
            somParentNumResolve(_somGetPClsMtabs(_CWBubblePad),
                                1,
                                _somGetMethodToken(_CWBubblePad, mySomId))					 
            )(somSelf, hwndCnr, ulView, param);
    SOMFree(mySomId);
  }
  else
    rcHWND=(CWBubblePad_parent_WPLaunchPad_wpOpen(somSelf, hwndCnr, 
                                                  ulView, param));
  
  if(ulView==OPEN_SETTINGS)
    return rcHWND;

  // The parent function opened the launchpad. We look which drawers were open on last shutdown and
  // reopen them now if user selected it.
  ulTemp=_ulOpenDrawers;

  if(_ulReOpen) {			
    for(a=0;a<32;a++) {
      if(ulTemp&1) {
        hwndDrawerButton=WinWindowFromID(rcHWND, 300+a);
        if(hwndDrawerButton)
          WinPostMsg(hwndDrawerButton, BM_CLICK, MPFROMSHORT(FALSE), MPFROMSHORT(0));
      }
      ulTemp=ulTemp>>1;
    }
  }/* end of if(ulReOpen) */
  return rcHWND;
}

/*
 *!!!!
 */

SOM_Scope PACTIONS  SOMLINK cwbubblepad_wpQueryActionButtons(CWBubblePad *somSelf, 
                                                             PULONG pulNumActions)
{
  ULONG num;         /* Number of action buttons */
  PACTIONS pActions; /* struct ACTIONS is described wrongly in the docs!! See *.h instead. */
  somId mySomId;

  /* this var holds the original action buttons. So if we call this method again
     the same buttons are removed as before.*/
  static ACTIONS backupActions[4];
  static BOOL bBackup=FALSE;
  
  CWBubblePadData *somThis = CWBubblePadGetData(somSelf);
  CWBubblePadMethodDebug("CWBubblePad","cwbubblepad_wpQueryActionButtons");

  if((mySomId=somIdFromString("wpQueryActionButtons"))!=NULLHANDLE) {
    pActions=((somTD_WPLaunchPad_wpQueryActionButtons)
              somParentNumResolve(_somGetPClsMtabs(_CWBubblePad),
                                  1,
                                  _somGetMethodToken(_CWBubblePad, mySomId))					 
              )(somSelf, pulNumActions);
    SOMFree(mySomId);
  }
  else
    pActions=(CWBubblePad_parent_WPLaunchPad_wpQueryActionButtons(somSelf, 
                                                                  pulNumActions));


  if(*pulNumActions!=4)
    return pActions;// We cannot handle unusual buttonnumbers
  
  if(!bBackup) {
    /* Save the default Warp actions */
    memmove(backupActions,pActions, sizeof(ACTIONS)*4);
    bBackup=TRUE;
  }

  num=0;
  if(_bShutdown){
    /* Shutdown button */
    memmove(&pActions[num], &backupActions[0], sizeof(ACTIONS));
    num++;
  }
  
  if(_bLock){
    memmove(&pActions[num], &backupActions[1],sizeof(ACTIONS));
    num++;
  }
  
  if(_bWindowList){
    memmove(&pActions[num], &backupActions[2], sizeof(ACTIONS));
    num++;
  }
  
  if(_bSearch){
    memmove(&pActions[num], &backupActions[3], sizeof(ACTIONS));
    num++;
  }

  *pulNumActions=num;

  return pActions;	
}


/************************************************************/
/* We have to override wpRefreshDrawer() cause we must know */
/* if there're new objects on the launchpad. Every object   */
/* has got a button and we have to change the window        */
/* procedure of the button                                  */
/************************************************************/ 
SOM_Scope void  SOMLINK cwbubblepad_wpRefreshDrawer(CWBubblePad *somSelf, 
                                                    ULONG ulDrawer)
{
  somId    mySomId;

  /* CWBubblePadData *somThis = CWBubblePadGetData(somSelf); */
  CWBubblePadMethodDebug("CWBubblePad","cwbubblepad_wpRefreshDrawer");

  // Call parent so it can update its private structures and build the
  // buttons
  // We will change the button procedures later on to provide the 
  // bubble help 
  if((mySomId=somIdFromString("wpRefreshDrawer"))!=NULLHANDLE) {
    ((somTD_WPLaunchPad_wpRefreshDrawer)
     somParentNumResolve(_somGetPClsMtabs(_CWBubblePad),
                         1,
                         _somGetMethodToken(_CWBubblePad, mySomId))
     )(somSelf,ulDrawer);
    SOMFree(mySomId);
  }
  else
    CWBubblePad_parent_WPLaunchPad_wpRefreshDrawer(somSelf, ulDrawer);

  // This piece of code looks strange, because we're doing no additional processing. Only if we're doing that
  // wpSetDrawerHWND(ULONG ulDrawer,HWND hwnd) is called with the new hwnd. Might be a bug.
  // Docs say wpSetDrawer() is called every time a drawer is build. I realized it is only called when the drawer
  // closes. 
}

SOM_Scope BOOL  SOMLINK cwbubblepad_wpRestoreState(CWBubblePad *somSelf, 
                                                   ULONG ulReserved)
{
  BOOL  rc;
  ULONG dataSize=sizeof(USHORT);
  ULONG ulActionButtons;
  somId mySomId;  
  
  CWBubblePadData *somThis = CWBubblePadGetData(somSelf);
  CWBubblePadMethodDebug("CWBubblePad","cwbubblepad_wpRestoreState");

  if((mySomId=somIdFromString("wpRestoreState"))!=NULLHANDLE) {
    rc=((somTD_WPObject_wpRestoreState)
        somParentNumResolve(_somGetPClsMtabs(_CWBubblePad),
                            1,
                            _somGetMethodToken(_CWBubblePad, mySomId))					 
        )(somSelf, ulReserved);
    SOMFree(mySomId);
  }
  else
    rc=CWBubblePad_parent_WPLaunchPad_wpRestoreState(somSelf, ulReserved);

  /* Read values from instance data                                         */
  /* If we start the BubblePad for the first time there're no values in the */
  /* instance data. In this case use defaults.                              */
  
  if(!_wpRestoreLong(somSelf, "CWBubblePad", ID_NODRAWERS,&_noDrawers))
    _noDrawers=0;
  if(!_wpRestoreLong(somSelf, "CWBubblePad", ID_SMALLSIZEENABLED,&_smallSizeEnabled))
    _smallSizeEnabled=1;
  if(!_wpRestoreLong(somSelf, "CWBubblePad", ID_DELAYVALUE,&_delayValue))
    _delayValue=250;


  if(!_wpRestoreLong(somSelf, "CWBubblePad",ID_ICONDISTANCE,&_icondistance))
    _icondistance=4;
  if(!_wpRestoreLong(somSelf, "CWBubblePad",ID_BUBBLEENABLED,&_bubbleEnabled))
    _bubbleEnabled=1;
  if(!_wpRestoreLong(somSelf, "CWBubblePad",ID_OPENDRAWERBITS,&_ulOpenDrawers))
    _ulOpenDrawers=(ULONG)0;
  if(!_wpRestoreLong(somSelf, "CWBubblePad",ID_REOPEN,&_ulReOpen))
    _ulReOpen=(ULONG)0;
  _bShutdown=TRUE;
  _bLock=TRUE;
  _bWindowList=TRUE;
  _bSearch=TRUE;
  if(_wpRestoreLong(somSelf, "CWBubblePad",ID_ACTIONBUTTONS,&ulActionButtons)) {
    if(~ulActionButtons & 1)_bShutdown=FALSE;
    if(~ulActionButtons & 2)_bLock=FALSE;
    if(~ulActionButtons & 4)_bWindowList=FALSE;
    if(~ulActionButtons & 8)_bSearch=FALSE;
  }
  dataSize=sizeof(RGB);
  if(!_wpRestoreData(somSelf, "CWBubblePad",ID_BACKGROUND,(PBYTE)&_background,&dataSize)) {
    _background.bBlue=180;
    _background.bGreen=255;
    _background.bRed=255;
  }
  dataSize=sizeof(RGB);
  if(!_wpRestoreData(somSelf, "WPLnchCW",ID_FOREGROUND,(PBYTE)&_foreground,&dataSize)) {
    _foreground.bRed=0;
    _foreground.bGreen=0;
    _foreground.bBlue=0;
  }
  memset(_fontName,0,sizeof(_fontName));	
  dataSize=sizeof(_fontName);
  if(!_wpRestoreString(somSelf, "CWBubblePad",ID_FONT,(PBYTE)&_fontName,&dataSize))
    memcpy(&_fontName,"8.Helv",sizeof("8.Helv"));
  
  return rc;

  // Durch obige Konstruktion wird die direkte Elternmethode aufgerufen,
  // und nicht die ursprÅngliche von WPLaunchPad, falls WPLaunchPad replaced wurde.
  // Durch diesen Aufruf gehen eventuelle Erweiterungen durch Vererbung verloren:
  //    
}


SOM_Scope BOOL  SOMLINK cwbubblepad_wpSetupOnce(CWBubblePad *somSelf, 
                                                PSZ pszSetupString)
{
  /**************************************************
   *                                                *
   * Supported setupstrings:                        *
   *                                                *
   * LPNODRAWERS=1/0                                *
   * LPBUBBLE=1/0                                   *
   * LPSMALL=1/0                                    *
   * LPREOPENDRAWERS=1/0                            *
   * LPDELAY=1-9999                                 *
   * LPDISTANCE=4-18                                *
   * LPBGCOLOR= RGB                                 *
   * LPFGCOLOR= RGB                                 *
   * LPACTIONBUTTONS=1+2+4+8                        *
   *                                                *
   **************************************************/
  BOOL rcParent;
  char buffer[CCHMAXPATH];
  ULONG ulBufferSize;
  ULONG ulBackground;
  ULONG ulForeground;
  ULONG ulActionButtons;
  somId mySomId;

  CWBubblePadData *somThis = CWBubblePadGetData(somSelf);
  CWBubblePadMethodDebug("CWBubblePad","cwbubblepad_wpSetupOnce");

  if((mySomId=somIdFromString("wpSetupOnce"))!=NULLHANDLE) {
    rcParent=((somTD_WPObject_wpSetupOnce)
              somParentNumResolve(_somGetPClsMtabs(_CWBubblePad),
                                  1,
                                  _somGetMethodToken(_CWBubblePad, mySomId))					 
              )(somSelf, pszSetupString);
    SOMFree(mySomId);
  }
  else
    rcParent=(CWBubblePad_parent_WPLaunchPad_wpSetupOnce(somSelf, 
                                                         pszSetupString));


  /* Doing our own setup here */
  ulBufferSize=sizeof(buffer);
  _noDrawers=0;
  if(_wpScanSetupString(somSelf, pszSetupString,"LPNODRAWERS",buffer,&ulBufferSize))
    if(buffer[0]=='1') _noDrawers=1;
  _bubbleEnabled=1;	
  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPBUBBLE",buffer,&ulBufferSize))
    if(buffer[0]=='0') _bubbleEnabled=0;
  _smallSizeEnabled=1;
  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPSMALL",buffer,&ulBufferSize))
    if(buffer[0]=='0') _smallSizeEnabled=0;
  _ulReOpen=0;
  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPREOPENDRAWERS",buffer,&ulBufferSize))
    if(buffer[0]=='1') _ulReOpen=1;		
  _delayValue=250;
  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPDELAY",buffer,&ulBufferSize)) {
    _delayValue=atol(buffer);/* convert to long */
    if(_delayValue>MAXDELAY)_delayValue=MAXDELAY;
  }

  _icondistance=4;
  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPDISTANCE",buffer,&ulBufferSize)) {
    _icondistance=atol(buffer);
    if(_icondistance<MINBUTTONDISTANCE)_icondistance=MINBUTTONDISTANCE;
    if(_icondistance>MAXBUTTONDISTANCE)_icondistance=MAXBUTTONDISTANCE;
  }
  _background.bBlue=180;
  _background.bGreen=255;
  _background.bRed=255;
  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPBGCOLOR",buffer,&ulBufferSize)) {
    ulBackground=atol(buffer);
    _background.bBlue=(BYTE)(ulBackground & 0xFF);
    ulBackground=ulBackground>>8;
    _background.bGreen=(BYTE)(ulBackground & 0xFF);
    ulBackground=ulBackground>>8;
    _background.bRed=(BYTE)(ulBackground & 0xFF);
  }
  _foreground.bRed=0;
  _foreground.bGreen=0;
  _foreground.bBlue=0;
  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPFGCOLOR",buffer,&ulBufferSize)) {
    ulForeground=atol(buffer);
    _foreground.bBlue=(BYTE)(ulForeground & 0xFF);
    ulForeground=ulForeground>>8;
    _foreground.bGreen=(BYTE)(ulForeground & 0xFF);
    ulForeground=ulForeground>>8;
    _foreground.bRed=(BYTE)(ulForeground & 0xFF);
  }
  _bShutdown=TRUE;
  _bLock=TRUE;
  _bWindowList=TRUE;
  _bSearch=TRUE;
  ulBufferSize=sizeof(buffer);
  if(_wpScanSetupString(somSelf, pszSetupString,"LPACTIONBUTTONS",buffer,&ulBufferSize)) {
    ulActionButtons=atol(buffer);
    if(~ulActionButtons & 1)_bShutdown=FALSE;
    if(~ulActionButtons & 2)_bLock=FALSE;
    if(~ulActionButtons & 4)_bWindowList=FALSE;
    if(~ulActionButtons & 8)_bSearch=FALSE;
  }

  /* Fill in defaults */
  _ulOpenDrawers=(ULONG)0;
  memcpy(&_fontName,"8.Helv",sizeof("8.Helv"));
  return rcParent;
}


/* This class function returns the name of our class */
SOM_Scope PSZ  SOMLINK cwbubblepadM_wpclsQueryTitle(M_CWBubblePad *somSelf)
{
    /* M_CWBubblePadData *somThis = M_CWBubblePadGetData(somSelf); */
    M_CWBubblePadMethodDebug("M_CWBubblePad","cwbubblepadM_wpclsQueryTitle");

	return "BubblePad";
}

SOM_Scope void  SOMLINK cwbubblepadM_wpclsInitData(M_CWBubblePad *somSelf)
{
  HMODULE hmodTemplate;
  static BOOL bStoreWndRegistered=FALSE;

  /* M_CWBubblePadData *somThis = M_CWBubblePadGetData(somSelf); */
  M_CWBubblePadMethodDebug("M_CWBubblePad","cwbubblepadM_wpclsInitData");

  /* Call parent */  
  M_CWBubblePad_parent_M_WPLaunchPad_wpclsInitData(somSelf);

  /* Register the store window class */
  if(!bStoreWndRegistered)
    {
      WinRegisterClass(WinQueryAnchorBlock(HWND_DESKTOP), STOREWND_CLASS, storeWindowProc, 0, STOREWNDBYTES);
      bStoreWndRegistered=TRUE;
    }

  /* Load WPS template icon */
  if(!hptrTemplate)
    if(!DosQueryModuleHandle("PMWP",&hmodTemplate))
      hptrTemplate=WinLoadPointer(HWND_DESKTOP, hmodTemplate, 20);
  /* Load our private template icon */
  if(!hptrSmallTemplate)
      hptrSmallTemplate=WinLoadPointer(HWND_DESKTOP, QueryModuleHandle(), ICO_TEMPLATE);
}

