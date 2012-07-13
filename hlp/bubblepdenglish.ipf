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

:title. Help for Bubblepad V1.08

:h1 res=001.Bubblepad V1.08
:i1 global.Bubblepad
:p.
The bubblepad is a replacement class for the launchpad of OS/2 Warp 3 and Warp 4. It provides bubblehelp for the
buttons of the launchpad and minimizes its size. There is an additional option to hide the drawer buttons.
With V1.03 and above it's possible to hide each action button. Activate this feature on the third otions page. 
:p.
This DLL and the accompaigning program are provided 'as is' under the terms of a BSD style license.
For further information read the file 'License'.
:note text='Usage'.
:p.
Bubblehelp is activated after checking of :hp2.Activate bubblehelp:ehp2.. Adjust the delay by changing the value
of :hp2.Delay:ehp2.. You can change the colour and font on the next settings page. The size is adjustable on the 
option pages.
:p.
:p.
:link reftype=hd res=201.History:elink.
:p.
:note text='Author:'. Chris Wohlgemuth.
:nt text='Web:'. http&colon.//svn.netlabs.org/bubblepad
:ent.

:h2 res=200.Additional Options
:p.
You can minimize the distance between buttons by checking the item :hp2.Small launchpad:ehp2. on the fourth option page.
The spin button :link reftype=hd res=302.Distance of buttons:elink. adjusts the distance.  
If you like very large launchpads you can increase it, too...
:p.
Check :hp2.Remove drawer buttons:ehp2. to remove the buttons from the launchpad.
:p.
With version 1.02 BubblePad saves the state of drawers on shutdown and reopens them during next boot. Use the
checkbox :hp2.Open drawers during reboot:ehp2. to customize this feature.
:h3 res=302.Distance of buttons
:p.
The button distance is adjustable from 4 to 18 pixel. With small values the size of the launchpad decreases dramatically.
:h2 res=201.History
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
:li.Fixed crash on eCS 1.1 and higher
:li.Clicking 'Shutdown' action button now invokes the system confirmation dialog
:li.Renamed class to CWBubblePad
:li.Rewritten class to plain C. No more Direct-to-SOM so compilation with any C-compiler
 should be possible
:li.Reworked settings dialogs
:li.Changed license to BSD style
:li.Bubblepd.dll must not be in the libpath anymore
:eul.
:p.
26.10.2003 V1.06
:ul compact.
:li.BubblePad method names were mangled
:li.Fixed some minor memory leaks
:li.Templates are painted as templates now. For mini icons there's a small mark
:li.Clicking on templates works as intended (like normal templates)
:li.Corrected some errors in the english NLV. Thanks to Peter Weilbacher for the patch
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

:h2 res=202.Colour and Font
:p.
Colour and font of the bubblehelp are adjustable. You can change it with the colour- and font palettes inside the :hp2.configuration folder:ehp2..
Just drop the colour or the font on the container on the second bubblehelp page. Press <CNTR> during dropping, if you want to change
the text colour. Open the palettes by clicking the buttons :hp2.Colour...:ehp2. and :hp2.Font...:ehp2..
:note text='Note:'.
The changes take effect after closing the notebook.
:p.
:sl.
:li.:link reftype=hd res=310.Colour...:elink. 
:li.:link reftype=hd res=311.Font...:elink.
:li.:link reftype=hd res=312.Undo:elink.
:li.:link reftype=hd res=313.Standard:elink.
:li.:link reftype=hd res=314.Help:elink.
:esl. 
:h3 res=310.Help for Colour...
:p.
Open the colour palette inside the :hp2.configuration folder:ehp2. by clicking on the button. 
:h3 res=311.Help for Font...
:p.
Open the Font palette inside the :hp2.configuration folder:ehp2. by clicking on the button. 
:h3 res=312.Help for Undo
:p.
Click on the button to reestablish the previous configuration.
:h3 res=313.Help for Standard
:p.
Click the button to chose the default values for colour and font.
Textcolour is black and the background colour is a bright yellow. The font is :hp2.8.Helv:ehp2..
:h3 res=314.Help for Help
:p.
This button opens the help.
:h2 res=400.Action buttons selection
:p.
Use the checkboxes on this page to enable or disable each of the action buttons.
:euserdoc.
