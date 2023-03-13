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

:title. Help voor Bubblepad V1.08

:h1 res=001.Bubblepad V1.08
:i1 global.Bubblepad
:p.
Bubblepad is een vervangende class voor het hoofdvenster van OS/2 Warp 3 en Warp 4. Het voorziet in 
hulpwolkjes voor de knoppen van het hoofdvenster en verkleind de grootte. Daarnaast is er een mogelijkheid 
om de lade-knoppen te verbergen.
Vanaf versie 1.03 is het mogelijk om de actie knoppen stuk voor stuk te verbergen. Deze voorziening kan geactiveerd
worden op de derde instellingen pagina. 
:p.
Deze DLL en het bijbehorende programma worden geleverd onder de voorwaarden van een licentie in BSD stijl.
Lees voor meer informatie het bestand "Licence"
:note text='Gebruik'.
:p.
Hulpwolkjes wordt geactiveerd door het aanvinken van :hp2.Hulpwolkjes activeren:ehp2.. De vertraging kan worden 
ingesteld door de waarde te wijzigen. Kleur en lettertype kunnen worden gewijzigd op de volgende pagina.
De grootte is instelbaar op de instellingen pagina's.
:p.
:p.
:link reftype=hd res=201.Geschiedenis:elink.
:p.
:note text='Auteur:'. Chris Wohlgemuth.
:nt text='Internet:'. http&colon.//svn.netlabs.org/bubblepad
:ent.

:h2 res=200.Aanvullende opties
:p.
De afstand tussen de knoppen wordt instelbaar door het aanvinken van  :hp2.Klein Hoofdvenster:ehp2. op de vierde instellingen pagina.
De waarde kan worden gewijzigd in het veld: :link reftype=hd res=302.Afstand tussen de knoppen:elink.
Zowel verkleinen als vergroten is mogelijk.
:p.
Vink :hp2.Lade knoppen verwijderen:ehp2. aan om de lade knoppen van het hoofdvenster te verwijderen.
:p.
Vanaf versie 1.02 bewaart BubblePad de stand van de laden tijdens het afsluiten van het systeem om ze bij de volgende opstart
weer te heropenen.
Deze voorziening wordt geactiveerd door :hp2.Laden openen tijdens herstarten:ehp2. aan te vinken.
:h3 res=302.Afstand tussen de knoppen
:p.
De afstand tussen de knoppen is verstelbaar van 4 tot 18 pixels. Met kleine waarden wordt het Hoofdvenster bijzonder compact.
:h2 res=201.Geschiedenis
:p.
18.12.2011 V1.08
:ul compact.
:li.Use of PNG icons if WPS-Wizard (http://svn.netlabs.org/wps-wizard) is installed
:li.Dutch translation thanks to Jan van der Heide
:li.Swedish translation thanks to Bj”rn S”derstr”m
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
wasn't defined. -> No subclassing possible.
:li.Notebook buttons are moved on Warp 4.
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
:li.Optionpage to remove each action button added.
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
:h2 res=202.Kleur en Lettertype
:p.
Achtergrondkleur en lettertype van de hulpwolkjes zijn instelbaar. Gebruik het kleuren- en lettertype palet in de :hp2.Configuratie map:ehp2.. Direct te openen met de knoppen op de tweede hulpwolkjespagina.
Laat de kleur of het lettertype vallen op de container van de tweede hulpwolkjes pagina. Houdt de CONTROL knop ingedrukt tijdens het slepen en loslaten als u de tekstkleur wilt wijzigen.
Open de paletten door te klikken op de knoppen :hp2.Kleur...:ehp2. en :hp2.Lettertype...:ehp2..
:note text='Opmerking:'.
De wijzigingen worden geactiveerd na het sluiten van het instellingen notitieblok.
:p.
:sl.
:li.:link reftype=hd res=310.Kleur...:elink. 
:li.:link reftype=hd res=311.Lettertype...:elink.
:li.:link reftype=hd res=312.Beginwaarde:elink.
:li.:link reftype=hd res=313.Standaard:elink.
:li.:link reftype=hd res=314.Help:elink.
:esl. 
:h3 res=310.Help voor Kleur...
:p.
Open het Kleuren palet in de :hp2.Configuratie map:ehp2. door op de knop te klikken.
:h3 res=311.Help voor Lettertype...
:p.
Open het Lettertype palet in de :hp2.Configuratie map:ehp2. door op de knop te klikken.
:h3 res=312.Help voor Beginwaarde
:p.
Gebruik deze knop om terug te gaan naar de beginwaarde.
:h3 res=313.Help voor Standaard
:p.
Gebruik deze knop om de standaardinstelling van kleur en lettertype te herstellen.
De tekstkleur is zwart en de achtergrondkleur is helder geel. Het lettertype is :hp2.8.Helv:ehp2..
:h3 res=314.Help voor Help
:p.
Open het helpvenster.
:h2 res=400.Actie knoppen selectie
:p.
Toon of verberg de Actie knoppen door ze op deze pagina aan- of uit- te vinken.
:euserdoc.
