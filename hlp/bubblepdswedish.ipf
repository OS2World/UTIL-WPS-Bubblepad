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

:title. Hj„lp f”r Bubblepad V1.08

:h1 res=001.Bubblepad V1.08
:i1 global.Bubblepad
:p.
Bubblepad „r en utbytesklass f”r launchpad hos OS/2 Warp 3 och Warp 4. Den ebjuder bubbelhj„lp f”r knapparna hos
launchpad och minimerar dess storlek. Det finns ytterligare ett alternativ f”r att d”lja l†dknappar. Med V1.03 och h”gre
„r det m”jligt att d”lja varje h„ndelseknapp. Aktivera den h„r funktionen p† den tredje sidan med alternativ. 
:p.
Denna DLL och tillh”rande program erbjuds 'som de „r' under villkoren hos BSD typen av licens. F”r ytterligare information l„s
filen 'License'.
:note text='Anv„ndning'.
:p.
Bubbelhj„lp aktiveras efter att ha markerat :hp2.Aktivera bubbelhj„lp:ehp2.. Justera f”rdr”jningen genom att „ndra v„rdet
hos :hp2.F”rdr”jning:ehp2.. Du kan „ndra f„rg och font p† n„sta inst„llningssida. Storleken „r justerbar p† sidan med
alternativ.
:p.
:p.
:link reftype=hd res=201.Historik:elink.
:p.
:note text='F”rfattare:'. Chris Wohlgemuth.
:nt text='Web:'. http&colon.//svn.netlabs.org/bubblepad
:ent.

:h2 res=200.Ytterligare alternativ
:p.
Du kan mimimera avst†ndet mellan knapparna genom att markera :hp2.Liten launchpad:ehp2. p† den fj„rde sidan med alternativ.
Spinnknappen :link reftype=hd res=302.Distans mellan knappar:elink. justerar avst†ndet. Om du gillar riktigt stora
launchpads kan du „ven ”ka den.
:p.
Markera :hp2.Ta bort l†dknappar:ehp2. f”r att ta bort knappar fr†n launchpad.
:p.
Med version 1.02 sparar BubblePad statusen hos l†dorna vid avst„ngning och ”ppnar dom igen vid n„sta ombootning. Anv„nd
checkboxen :hp2.™ppna l†dor under ombootning:ehp2. f”r att anpassa den h„r funktionen.
:h3 res=302.Distans mellan knappar
:p.
Avst†ndet mellan knapparna „r justerbart fr†n 4 till 18 pixels. Med sm† v„rden minskar storleken hos launchpad dramatiskt.
:h2 res=201.Historik
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
:li.tg„rdade krasch p† eCS 1.1 och h”gre.
:li.Klickning p† knappen 'St„ng av' anropar nu systemets bekr„ftelsedialog.
:li.Namn„ndrade klass till CWBubblePad
:li.Klass omskriven till ren C. Ingen mer Direkt-till-SOM s† kompilering med vilken som helst C-kompilator
skall vara m”jlig.
:li.Omarbetade inst„llningsdialoger.
:li.ndrade licens till BSD typ.
:li.Bubblepd.dll beh”ver inte vara i libpath l„ngre.
:eul.
:p.
26.10.2003 V1.06
:ul compact.
:li.BubblePad metodnamnen skadades.
:li.tg„rdade vissa mindre minnesl„ckor.
:li.Mallar ritas nu som mallar. F”r mini-ikoner finns en liten markering.
:li.Klickning p† mallar fungerar nu som avsett (som vanliga mallar).
:li.tg„rdade vissa fel i engelsk NLV. Tack till Peter Weilbacher f”r patchen.
:eul.
:p.

22.06.2003 V1.05
:ul compact.
:li.Export av M_WPLnchCWClassData, M_WPLnchCWCClassData och M_WPLnchCWNewClass
var inte definierad. -> Ingen subklassning m”jlig.
:li.Anteckningsbokens knappar „r flyttade p† Warp 4.
:eul.
:p.
28.12.98 V1.04 (aldrig offentligt utgiven)
:ul compact.
:li.Bugg †tg„rdad vilken orsakade ”ppning av bubblepad med standardv„rden n„r LAUNCHPAD argumentet fanns
i AUTOSTART raden hos config.sys. Den h„r buggen introducerades med setupstr„ngarna hos V1.03.        
:eul.
:p.
15.11.98 V1.03
:sl.
:li.Nya funktioner:
:ul compact.
:li.Alternativ att avaktivera ny ”ppning av l†dor.
:li.Alternativsida f”r att ta bort varje h„ndelseknapp tillagd.
:li.Setupstr„ngar p†lagda f”r att f”renkla automatisk installation.
:li.Verktyg inkluderat f”r att byta ut/†ngra utbyte av WPLaunchPad klass.
:eul.
:esl.
:p.
19.09.98 V1.02:
:sl.
:li.Nya funktioner:
:ul compact.
:li.D”lj l†dknapp funktion tillagd. 
:li.Individuella inst„llningar f”r BubblePads tillagda.
:li.Lagt till sparande av l†dstatus. L†dor ”ppna p† nytt vid n„sta ombootning. Fungerar inte med det vanliga ”ppna/st„ng. 
:eul.
:li.Buggar †tg„rdade:
:ul compact.
:li.Positionering av hj„lpf”nster f”r launchpad vid toppen av skrivbordet †tg„rdat.
:li.Bugg med brutna referenser orsakade att l†dor f”rsvann †tg„rdad. 
:li.Flyttade omplacering av knappar fr†n wpRefreshDrawer() till wpSetDrawerHWND(). Detta eliminerar blinkningar vid ”ppning av l†dor. 
:li.Install.exe kopierade alltid den engelska hj„lpfilen i tidigare versioner.
:eul.
:esl.
:p.
20.08.98 V1.01:
:ul compact.
:li.tg„rdade problem med fastnande hj„lpf”nster. Hj„lpf”nstren f”rst”rs alltid ordentligt nu, „ven om l†dor „r inst„llda f”r
att st„ngas automatiskt.
:eul.
:p.
18.08.98 V1.00b:
:ul compact.
:li.tg„rdade positionering av l†dor. L†dor nedanf”r eller till v„nster om launchpad placerades med ett avst†nd till launchpad.
:li.Timerrutiner f”r hj„lpf”nster omskrivna.
:eul.
:p.
16.08.98 V1.00a:
:ul compact.
:li.tg„rdade bugg i install.exe vilken ibland hindrade att standard installationskatalog accepterades.
:li.tg„rd: flygande hj„lpf”nster f”rblir synliga p† vissa system. N„r hj„lpen fastnar ”ver vissa skrivbord, flytta pekaren
”ver en annan knapp f”r att bli av med den.              
:eul.
:p.
25.06.98 V1.00:  
:sl.
:li.F”rsta publika versionen.
:esl.

:h2 res=202.F„rg och Font
:p.
F„rg och font hos bubbelhj„lp „r justerbar. Du kan „ndra detta med f„rg- och fontpaletterna i :hp2.konfigurationsmappen:ehp2..
Sl„pp bara f„rg eller font p† containern p† den andra bubbelhj„lpssidan. Tryck <CNTR> under sl„pp, och du vill „ndra textf„rgen. 
™ppna paletterna genom att klicka p† knapparna :hp2.F„rg...:ehp2. och :hp2.Font...:ehp2..
:note text='Notera:'.
ndringarna blir effektiva efter att anteckningsboken har st„ngts.
:p.
:sl.
:li.:link reftype=hd res=310.F„rg...:elink. 
:li.:link reftype=hd res=311.Font...:elink.
:li.:link reftype=hd res=312.ngra:elink.
:li.:link reftype=hd res=313.Standard:elink.
:li.:link reftype=hd res=314.Hj„lp:elink.
:esl. 
:h3 res=310.Hj„lp f”r F„rg...
:p.
™ppna f„rgpaletten i :hp2.konfigurationsmappen:ehp2. genom att klicka p† knappen. 
:h3 res=311.Hj„lp f”r Font...
:p.
™ppna fontpaletten i :hp2.konfigurationsmappen:ehp2. genom att klicka p† knappen. 
:h3 res=312.Hj„lp f”r ngra
:p.
Klicka p† knappen f”r att †terta den f”reg†ende konfigurationen.
:h3 res=313.Hj„lp f”r Standard
:p.
Klicka p† knappen f”r att v„lja standardv„rden f”r f„rg och font. Textf„rgen „r svart och 
bakgrundsf„rgen „r klargul. Fonten „r :hp2.8.Helv:ehp2..
:h3 res=314.Hj„lp f”r Hj„lp
:p.
Den h„r knappen ”ppnar hj„lpen.
:h2 res=400.Val av h„ndelseknappar
:p.
Anv„nd checkboxarna p† den h„r sidan f”r att aktivera eller avaktivera varje h„ndelsknapp.
:euserdoc.