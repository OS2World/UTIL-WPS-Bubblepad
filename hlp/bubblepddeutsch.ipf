.***********************************************************************/
.* BubblePad - Replacement class for the launchpad of Warp 3/4         */
.* (C) Chris Wohlgemuth                                                */
.*                                                                     */
.* http://svn.netlabs.org/bubblepad                                    */
.*                                                                     */
.* Released under a 3-clause BSD license                               */
.* See file License for further information                            */
.*                                                                     */
.*   Source file for online help                                       */
.*                                                                     */
.*   Last change: 17.12.2011                                           */
.*                                                                     */
.***********************************************************************/

.* /*
.* Copyright (c) Chris Wohlgemuth 1997-2011
.* All rights reserved.
.*
.* http://svn.netlabs.org/bubblepad
.*
.* Redistribution and use in source and binary forms, with or without
.* modification, are permitted provided that the following conditions
.* are met:
.* 1. Redistributions of source code must retain the above copyright
.*    notice, this list of conditions and the following disclaimer.
.* 2. Redistributions in binary form must reproduce the above copyright
.*    notice, this list of conditions and the following disclaimer in the
.*    documentation and/or other materials provided with the distribution.
.* 3. The authors name may not be used to endorse or promote products
.*    derived from this software without specific prior written permission.
.*
.* THIS SOFTWARE IS PROVIDED ``AS IS'' AND
.* ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
.* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
.* ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
.* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
.* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
.* OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
.* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
.* LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
.* OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
.* SUCH DAMAGE.
.*
.* */
:userdoc.

:docprof.

:title. Hilfe fÅr Bubblepad V1.08

:h1 res=001.Bubblepad V1.08
:i1 global.Bubblepad
:p.
Das Bubblepad ist eine Ersatzklasse fÅr die Klickstartleiste von OS2/2 Warp 3 und Warp 4. Sie stellt
eine Sprechblasenhilfe fÅr die Knîpfe der Klickstartleiste zur VerfÅgung. 
DarÅberhinaus verkleinert es die Dimensionen des Launchpads und enthÑlt eine Option, die Schubladenknîpfe zu
verdecken. Ab Version V1.03 besteht die Mîglichkeit, die Aktionsknîpfe einzeln zu entfernen. Diese Funktion
lÑ·t sich auf der dritten Optionsseite aktivieren.
:p. 
Dieses Programm/diese DLL unterliegt einer BSD-artigen Lizenz. NÑheres ist in
der Textdatei 'License' zu finden.
:note text='Verwendung'.
:p.
öber das Feld :hp2.Bubblehelp aktivieren:ehp2. auf der Seite Sprechblasenhilfe wird die Sprechblasenhilfe aktiviert. 
Die Zeitdauer in ms bis zum Erscheinen der
Hilfe ist dabei Åber :hp2.Verzîgerung:ehp2. einstellbar. Die Farbe und die Schriftart der Hilfe ist auf der folgenden Seite
wÑhlbar. Die Grî·e der Klickstartleiste ist auf den Optionen-Seiten des Einstellungen-Notizbuches verÑnderbar.
:p.
:p.
:link reftype=hd res=201.Versionen:elink.

:p.
:note text='Author:'. Chris Wohlgemuth
:nt text='Web:'. http&colon.//svn.netlabs.org/bubblepad
:ent.

:h2 res=200.ZusÑtzliche Optionen
:p.
Durch Aktivieren des Feldes :hp2.Klickstartleiste verkleinern:ehp2. auf der vierten Optionenseite kann der Abstand der Knîpfe verringert werden, wodurch
die Klickstartleiste weniger Platz auf dem Bildschirm wegnimmt. :link reftype=hd res=302.Buttonabstand:elink. gibt dabei den
Abstand in Bildschirmpunkten an.
NatÅrlich ist es auch mîglich den Knopfabstand zu vergrî·ern, wenn man ein Freund besonders breiter Rahmen ist...
:p.
Wird :hp2.Keine Schubladen:ehp2. angewÑhlt, so werden die entsprechenden Auswahlknîpfe auf der Klickstartleiste entfernt.
:p.
Seit V1.02 werden Schubladen, die beim Systemabschlu· offen waren, beim erneuten Booten wieder geîffnet. Durch entsprechende
Einstellung von :hp2.Schubladen beim Booten îffnen:ehp2. lÑ·t sich dieses Verhalten ein- bzw. ausschalten.
:h3 res=302.Buttonabstand
:p.
Der Knopfabstand ist von 4 bis 18 Bildschirmpunkten einstellbar. Bei kleinen AbstÑnden verringert sich der Platzbedarf der Klickstartleiste deutlich.

:h2 res=201.Versionen
:p.
18.12.2011 V1.08
:ul compact.
:li.Use of PNG icons if WPS-Wizard (http://svn.netlabs.org/wps-wizard) is installed
:li.Dutch translation thanks to Jan van der Heide
:li.Swedish translation thanks to Bjîrn Sîderstrîm
:li.French translation thanks to Guillaume Gay
:eul.
:p.
18.06.2004 V1.07
:ul compact.
:li.Fixed crash on eCS 1.1 and higher.
:li.Clicking 'Shutdown' action button now invokes the system confirmation dialog.
:li.Renamed class to CWBubblePad
:li.Rewritten class to plain C. No more Direct-to-SOM so compilation with any C-compiler
 should be possible.
:li.Reworked settings dialogs.
:li.Changed license to BSD style.
:li.Bubblepd.dll must not be in the libpath anymore.
:eul.
:p.
26.10.2003 V1.06
:ul compact.
:li.BubblePad method names were mangled.
:li.Fixed some minor memory leaks.
:li.Templates are painted as templates now. For mini icons there's a small mark.
:li.Clicking on templates works as intended (like normal templates).
:li.Corrected some errors in the english NLV. Thanks to Peter Weilbacher for the patch.
:eul.
:p.
22.06.2003 V1.05
:ul compact.
:li.Export of M_WPLnchCWClassData, M_WPLnchCWCClassData and M_WPLnchCWNewClass
 wasn't defined. -> No subclassing possible
:li.Notebook buttons are moved on Warp 4
:eul.
:p.
28.12.98 V1.04 (never released to the public)
:ul compact.
:li.Bug corrected which caused opening of bubblepad with default values when LAUNCHPAD entry was present
in the AUTOSTART line of the config.sys. This bug was introduced with the setup strings of V1.03.        
:eul.
:p.
15.11.98 V1.03
:sl.
:li.New features:
:ul compact.
:li.Option to disable reopening of drawers added.
:li.Option to remove each action button added.
:li.Setup strings added to ease automatic installation.
:li.Utility included to replace/unreplace the WPLaunchPad class.
:eul.
:esl.
:p.
19.09.98 V1.02:
:sl.
:li.New features:
:ul compact.
:li.Hide drawer button feature added. 
:li.Individual settings for BubblePads added.
:li.Added saving of drawer state. Drawers are reopened on next reboot. Doesn't work with normal open/close. 
:eul.
:li.Bugs corrected:
:ul compact.
:li.Positioning of help windows for launchpad at the top of the desktop corrected.
:li.Bug with broken references causing drawers to disapear fixed. 
:li.Moved button reordering from wpRefreshDrawer() to wpSetDrawerHWND(). This eliminates the flickering when opening drawers. 
:li.Install.exe always copied the english help-file in previous versions.
:eul.
:esl.
:p.
20.08.98 V1.01:
:ul compact.
:li.Corrected stucking help window problem. Help windows are always properly destroyed now, even if drawers are set to autoclose.
:eul.
:p.
18.08.98 V1.00b:
:ul compact.
:li.Corrected positioning of drawers. Drawers below or on the left of the launchpad were placed with an offset to the launchpad.
:li.Timer routines for the help windows rewritten.
:eul.
:p.
16.08.98 V1.00a:
:ul compact.
:li.Corrected bug in install.exe which sometimes prevented accepting of default installation directory.
:li.Workaround: fly over help window on some systems remains visible. When help stucks on the desktop move pointer over
another button to get rid of it.              
:eul.
:p.
25.06.98 V1.00:  
:sl.
:li.First public version.
:esl.
:h2 res=202.Farbe und Schriftart
:p.
Die Farbe und Schriftart der Hilfe ist frei wÑhlbar. Mittels der Farb- bzw. Schriftartenpalette aus dem Ordner
:hp2.Systemkonfiguration:ehp2. lassen sie sich Åber Drag and Drop (Ziehen und Fallenlassen) einstellen. Hierzu ist lediglich
die gewÅnschte Farbe oder Schriftart Åber dem Auswahlfeld auf der zweiten Sprechblasenhilfeseite fallenzulassen. Soll die Schriftfarbe geÑndert werden, so mu·
wÑhrend des Fallenlassens die Taste <STRG> gedrÅckt werden. öber die Knîpfe :hp2.Farbe...:ehp2. und :hp2.Schriftart...:ehp2.
werden die entsprechenden Paletten direkt geîffnet.
:note text='Anmerkung:'.
Die énderungen auf dieser Seite werden erst nach Schlie·en des EinstellungenNotizbuches wirksam.
:p.
:sl.
:li.:link reftype=hd res=310.Farbe...:elink. 
:li.:link reftype=hd res=311.Schriftart...:elink.
:li.:link reftype=hd res=312.Widerrufen:elink.
:li.:link reftype=hd res=313.Standard:elink.
:li.:link reftype=hd res=314.Hilfe:elink.
:esl. 
:h3 res=310.Hilfe fÅr Farbe...
:p.
Durch Anklicken dieses Knopfes wird die Farbpalette aus dem Ordner :hp2.Systemkonfiguration:ehp2. aufgerufen.
:h3 res=311.Hilfe fÅr Schriftart...
:p.
Durch Anklicken dieses Knopfes wird die Schriftartpalette aus dem Ordner :hp2.Systemkonfiguration:ehp2. aufgerufen.
:h3 res=312.Hilfe fÅr Widerrufen
:p.
Durch Anklicken dieses Knopfes werden die vorherigen Einstellungen fÅr die Farbe und Schriftart wiederhergestellt.
:h3 res=313.Hilfe fÅr Standard
:p.
Durch Anklicken dieses Knopfes werden die Standardeinsttellungen fÅr die Farbe und Schriftart wiederhergestellt. Diese sind
ein helles Pastellgelb fÅr den Texthintergrund und Schwarz fÅr den Text. Standardschriftart ist :hp2.8.Helv:ehp2..
:h3 res=314.Hilfe fÅr Hilfe
:p.
Aufruf dieser Hilfe.
:h2 res=400.Auswahl der Aktionsknîpfe
:p.
Auf dieser Seite des Einstellungennotizbuches lassen sich die einzelnen Aktionsknîpfe aktivieren bzw. deaktivieren.
:euserdoc.