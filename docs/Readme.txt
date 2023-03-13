Bubblepad V 1.08 (c) Chris Wohlgemuth 1997-2011
-----------------------------------------------

Contents
-------
0. Licence

1. Overview

2. Installation

2b. Setup strings

3. Deinstallation

4. Usage

5. Compiling

6. History

7. Known Problems

8.  Author

-----------------------------------------

0. Licence
------
This package is provided 'as is' under a BSD style 
License.
See the file 'License' fo further information.


1. Overview
-----------
Welcome to Bubblepad V 1.08, a replacement class for the
launchpad of OS/2 Warp 3 and above. This new class provides
bubblehelp for all the buttons of your launchpad. With this
enhancement it is possible to distinguish all the 40 folders on
the launchpad, which have all the same icon. Never click a
wrong button again.
Further more the class reduces the size of the launchpad by 
reducing the distance between buttons and the size of the borders.

NEW with V1.02:
New with that release is an option to remove the drawer buttons.
Individual settings for different launchpads are possible now.
No more flickering when opening drawers. The state of drawers
is saved on schutdown. Reopening on next boot.

NEW with V1.03:
See file changes.

(V1.04 was never released to the public)

NEW with V1.05 and above:
See file changes.


Full online help is provided but I don't think you really need it. 
All Features are selectable.

The package contains german, dutch , swedish, freanch and english versions
of the DLL and the help file. Feel free to translate the resource file
and the strings in the *.cmd files.
If you send me the translations I put it together and compile 
a new distribution.

You can find the Bubblepad homepage at

   http://svn.netlabs.org/bubblepad
   

2. Installation
---------
Unzip the files into a directory but be sure to keep the
directory structure!

FIRST OF ALL MAKE COPIES OF YOUR INI FILES!!
I don't think it is really necessary but during installation the
program registers a new WPS-class and it is always a
good idea to have a backup of the ini files if anything goes
wrong. You know, Murphy never sleeps...

If you are running an older version of BubblePad deinstall it first and
restart the WPS.

Move the directory with the archive contents to a suitable location.
After installation this directory can not be moved because the WPS
locks the class DLL of the BubblePad.
Run the installation script 'install.cmd'.
After registering the new class and replacing the original launchpad
class WPLaunchPad you must restart the WPS, so the changes can take effect. 

If you want to perform a customized installation, you can use
REXX together with setup strings for the BubblePad features.
Refer to the section 2b. for further information about the supported
setup strings.


2b. Setup strings
-----------------
With version V1.03 setup strings are supported for the bubblepad
features so automatic installation using REXX is possible.

The following additional setup strings are supported:

LPNODRAWERS=1

   Hide the drawer buttons. The default is not to hide the buttons.

LPSMALL=0

   Disable resizing of the Launchpad. With this option LPNODRAWERS
   has no effect. If omited the default is ENABLED.

LPDISTANCE=4-18                  

   Choose the distance of buttons on the pad. Possible values are 4-18.
   The default value is 4. 

LPREOPENDRAWERS=1

   If set drawers are reopened on next boot. The default is disabled.

LPACTIONBUTTONS=1+2+4+8
       
   Enable each actionbutton. The value of this key is calculated by
   adding the values of the actionbuttons:

   Shutdown:     1
   Lock:          2
   Windowlist:   4
   Search:        8

   Example:
            If you want to enable the lock button and the search button
            use LPACTIONBUTTONS=10 (the key is decimal!).

   The default is to enable all action buttons.

LPBUBBLE=0

   Disable the bubblehelp. The default is ENABLED. 

LPDELAY=0-9999

   The delay for the help window. Choose values between
   0 and 9999ms. The default is 250ms.
 
LPBGCOLOR=RGB

   Choose the background color of the help window. The value
   is calculated in the following way:

   LPBGCOLOR=65536*R+256*G+B

   Be sure to use a decimal value. The default is a bright yellow.

LPFGCOLOR=RGB

   Choose the Foreground color of the help window.  The value
   is calculated in the following way:

   LPFGCOLOR=65536*R+256*G+B

   Be sure to use a decimal value. The default color is black.


Here's an example how to use setup strings:

------------------------------------------------
/* rexx - create Bubblepad */

call RxFuncAdd 'SysCreateObject','RexxUtil', 'SysCreateObject'

IF SYSCreateObject("WPLnchCW","Setup-Test","<WP_DESKTOP>","LPACTIONBUTTONS=8;LPNODRAWERS=1;LPREOPENDRAWERS=1","replace") THEN
   Say 'OK. New Bubblepad created.'
------------------------------------------------

This example creates a new Bubblepad with only the search-button.
The drawer buttons are hidden and the drawers are reopened on next
reboot.
This script works even if you haven't replaced WPLaunchPad with the
new BubblePad-class WPLnchCW. If the replacement is in effect you
can use WPLaunchPad as the classname.


3. Deinstallation
-----------------
Run the deinstallation script.
The script unreplaces WPLaunchPad and deregisters the class.
You have to reboot to finish deinstallation.


4. Usage
--------
The new class inserts four pages into the settings notebook.
Two pages are for customizing the bubblehelp. It's possible to
chose the colour of the bubble and the font. The delay is 
adjustable, too. Changing colour and font is done by using the
color and font palettes inside the configuration folder. You can
open these palettes directly from the settings notebook by
clicking on the appropriate buttons.
On the third Option page you can disable each action button.
Another options page let you choose if you want to minimize
the size of the launchpad. The new distance of the buttons is
adjustable.
You have an option to remove the drawer buttons with V1.02
and above. All settings are individual for every launchpad in
the system.

Full online help is provided for the new settings pages.


5. Compiling
------------
Full source code is provided with this package. For compiling of
the replacement class you need VAC++3.08 and the Warp 3 Toolkit
(both from IBM, commercial). Other C compilers may also work but
the toolkit is still required because of the SOM compiler.
You also need Gnu make and the Gnu file utilities (for rm.exe).
Maybe you also need a unix compatible shell like ash.exe, ksh.exe or
bash.

It's assumed that the compiler is properly installed.

1. CD into the source directory
4. run 'make', the Gnu make utility. That's all.

Run 'make clean' in the source directory to delete all temporary files.


6. History
----------
See file 'Changes'. 


7. Known problems
-----------------
With OS/2 Warp 4 (no FP) sometimes the WPS doesn't start. It loads
the background picture and stops with the wait pointer. It's the same
problem known with the warpcenter. Try a fixpack solving the
warpcenter problem or as a workaround put the statement 
SET RESTARTOBJECTS=NO in your config.sys.
Remove the statement LAUNCHPAD from the AUTOSTART line. 

The state of open drawers is only saved on shutdown. So drawers are
not reopened when the launchpad is closed and then reopened. 

Painting of templates on the launchpad is not perfect yet. Some
flickering may occur. 


8. Author
---------
(c) Chris Wohlgemuth 1997-2011

You can find the Bubblepad homepage here:

    http://svn.netlabs.org/bubblepad

If you send me any enhancements or translations, I incorporate them
into the distribution. 

