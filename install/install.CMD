/* */
 call RxFuncAdd 'SysLoadFuncs', 'RexxUtil', 'SysLoadFuncs'
 call SysLoadFuncs

cls

repExe='@'||DIRECTORY()||"\bin\lpreplace.exe 1 >nul"
theDLL=DIRECTORY()

/* Switch ANSI on */
theCommand='@'ANSI' ON >nul'
theCommand

/* Show copyright blurb */
call banner

/* Let user select language */
theLang=getLanguage()

SELECT
  WHEN theLang=1 THEN DO 
	theDLL=theDLL||"\English\Bubblepd.dll"
        SAY "Selected Language is: "||"1B"x || "[37;44m" || "english" || "1B"x || "[0m"
	SAY ""
	SAY "Install BubblePad now? Y(es)/N(o)"
	call checkForAbort "N"
  END
  WHEN theLang=2 THEN DO
	theDLL=theDLL||"\Deutsch\BubblePd.dll"
        SAY "Ausgew„hlte Sprache ist: "||"1B"x || "[37;44m" || "deutsch" || "1B"x || "[0m"
	SAY ""
	SAY "BubblePad nun installieren? J(a)/N(ein)"
	call checkForAbort "N"
  END
  WHEN theLang=3 THEN DO
	theDLL=theDLL||"\Nederlands\BubblePd.dll"
        SAY "Gekozen taal is: "||"1B"x || "[37;44m" || "nederlands" || "1B"x || "[0m"
	SAY ""
	SAY "BubblePad nu installeren? J(a)/N(ee)"
	call checkForAbort "N"
  END
  WHEN theLang=4 THEN DO
	theDLL=theDLL||"\Svenska\BubblePd.dll"
        SAY "Valt spr†k „r: "||"1B"x || "[37;44m" || "svenska" || "1B"x || "[0m"
	SAY ""
	SAY "Installera BubblePad nu? J(a)/N(ej)"
	call checkForAbort "N"
  END
  WHEN theLang=5 THEN DO
	theDLL=theDLL||"\Francais\BubblePd.dll"
        SAY "Langue s‚lectionn‚e: "||"1B"x || "[37;44m" || "fran‡ais" || "1B"x || "[0m"
	SAY ""
	SAY "Voulez-vous installer BubblePad? O(ui)/N(on)"
	call checkForAbort "N"
  END
OTHERWISE
        SAY "Illegal language selection. Aborting..."
	exit 1
END

rc=SysRegisterObjectClass("CWBubblePad", theDLL)
IF rc=0 THEN DO
  SELECT
  WHEN theLAng=1 THEN
    SAY "Can't register class CWBubblePad using DLL "||theDLL
  WHEN theLAng=2 THEN
    SAY "Kann Klasse CWBubblePad nicht registrieren. DLL ist: "||theDLL
  WHEN theLAng=3 THEN
    SAY "Kan CWBubblePad class niet registreren met DLL "||theDLL
  WHEN theLAng=4 THEN
    SAY "Kan inte registrera klassen CWBubblePad med DLL: "||theDLL  
  WHEN theLAng=5 THEN
    SAY "Impossible d'enregistrer la classe CWBubblePad en utilisant la DLL "||theDLL
  OTHERWISE
    SAY "Can't register class CWBubblePad using DLL "||theDLL
  END
  exit 1
END

/* Replace WPLaunchPad with CWBubblePad */
repExe
if rc\=0 THEN DO
  SELECT
  WHEN theLAng=1 THEN
    SAY "Can't replace class WPLaunchPad with CWBubblePad."
  WHEN theLAng=2 THEN
    SAY "Kann Klasse WPLaunchPad nicht durch CWBubblePad ersetzen."
  WHEN theLAng=3 THEN
    SAY "Kan WPLaunchPad class niet vervangen met CWBubblePad."
  WHEN theLAng=4 THEN
    SAY "Kan inte byta ut klassen WPLaunchPad med CWBubblePad."  
  WHEN theLAng=5 THEN
    SAY "Impossible de subsituer la classe WPLaunchPad avec la classe CWBubblePad."
  OTHERWISE
    SAY "Can't replace class WPLaunchPad with CWBubblePad."
  END
END

SAY ""

/* We are done */
SELECT
  WHEN theLAng=1 THEN
    SAY "Installation finished. You have to restart the WPS now."
  WHEN theLAng=2 THEN
    SAY "Installation beendet. Die WPS muá nun neu gestartet werden."
  WHEN theLAng=3 THEN
    SAY "Installatie afgerond. U dient de WPS nu te herstarten."
  WHEN theLAng=4 THEN
    SAY "Installationen „r klar. Du m†ste starta om WPS nu."  
  WHEN theLAng=5 THEN
    SAY "L'installation est termin‚e. Vous devez … pr‚sent relancer le WPS."
  OTHERWISE
    SAY "Installation finished. You have to restart the WPS now."
END

SAY ""
'@pause'

exit 0

/*******************************/

banner:

SAY ''
say "    "||"1B"x || "[37;44m" || " BubblePad V1.08 (c) Chris Wohlgemuth 1997-2011 " || "1B"x || "[0m"
SAY ""
SAY "     Translations by Bj”rn S”derstr”m (Swedish),"
SAY "                     Jan van der Heide (Dutch)"
SAY "                     and Guillaume Gay (French)"
SAY ""
return

getLanguage: PROCEDURE

QUIT=0
SAY "Select your language:"
SAY ""
SAY "    1: English"
SAY "    2: Deutsch"
SAY "    3: Nederlands"
SAY "    4: Svenska"
SAY "    5: Fran‡ais"
SAY ""
SAY "    ('q' for exit)"
SAY ""
Do UNTIL QUIT=1
  say '>'
  parse value SysCurPos() with aktzeile aktspalte
  newposition=SysCurPos(aktzeile-1,2)
  pull theChar
  IF theChar='Q' then EXIT 1
  if LENGTH(theChar)==1 & VERIFY(theChar, "12345")==0 THEN QUIT=1
  ELSE
   call beep 100, 100
  call SysCurPos aktzeile-1, 0
  SAY "1B"x || "[K"
  call SysCurPos aktzeile-1, 0
END
  SAY ""
return theChar

checkForAbort: PROCEDURE

abortChar=ARG(1)

  SAY ""
  say '>'
  parse value SysCurPos() with aktzeile aktspalte
  newposition=SysCurPos(aktzeile-1,2)
  pull theChar
  IF LEFT(theChar,1)=abortChar then EXIT 1
return
