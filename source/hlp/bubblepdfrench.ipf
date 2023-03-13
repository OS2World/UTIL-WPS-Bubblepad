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

:title. Aide de Bubblepad
.*************************************************************************
.* SECTION : INTRODUCTION                                                *
.*************************************************************************
:h1 res=001.Bubblepad V1.08
:i1 global.Bubblepad
:p.
Bubblepad est une classe de remplacement pour le tableau de bord d'OS/2 
Warp 3 et Warp 4. Il fournit des bulles d'aide aux boutons du tableau de 
bord et permet de r�duire sa taille. Il y a une option suppl�mentaire
pour cacher les boutons de tiroirs. 
.br
Depuis la version 1.03 il est possible de cacher chacun des boutons 
d'action. Activez cette fonctionnalit� sur la troisi�me page des
param�tres. 
:p.
Cette DLL et le programme l'accompagnant sont fournis "tels quels" 
sous 
licence de type BSD. Veuillez consulter le fichier 'License' 
pour plus d'informations. 
:note text='Utilisation'.
:p.
Les bulles d'aide seront activ�es apr�s avoir coch� l'option 
:hp2.Activer les bulles d'aide:ehp2.&per. Fixez le d�lai d'affichage en 
modifiant la valeur :hp2.D�lai:ehp2.&per. Vous pouvez modifier les 
couleurs et police sur la page des param�tres suivante. La taille peut 
elle-aussi �tre ajust�e sur ces pages d'options. 
:p.
:p.
:link reftype=hd res=201.Historique:elink.


:p.
:note text='Auteur :'. Chris Wohlgemuth.
:nt text='Web:'. http&colon.//svn.netlabs.org/bubblepad
:ent.

.*************************************************************************
.* SECTION : ADDITIONNAL OPTIONS                                         *
.*************************************************************************
:h2 res=200.Options suppl�mentaires
:p.
Vous pouvez r�duire la distance entre les boutons en cochant l'�l�ment 
:hp2.Tableau de bord r�duit:ehp2. sur la quatri�me page des options. Le 
s�lecteur rotatif 
:link reftype=hd res=302.Distance entre les boutons:elink. permet
d'ajuster l'espace de s�paration des boutons. Ou si vous pr�f�rez avoir 
un tableau de bord plus large, vous pouver aussi augmenter la valeur... 
:p.
Cochez :hp2.Retirer les boutons de tiroirs:ehp2. pour enlever les
boutons correspondants du tableau de bord. 
:p.
Depuis la version 1.02, Bubblepad enregistre l'�tat des tiroirs � 
l'arr�t du syst�me et les r�ouvre au prochain lancement. 
Utilisez la case � cocher :hp2.Ouvrir les tiroirs au lancement:ehp2. 
pour activer cette fonctionnalit�. 
:p.
.*************************************************************************
.* SECTION : DISTANCE BETWEEN BUTTONS                                    *
.*************************************************************************
:h3 res=302.Distance entre boutons
:p.
La distance entre les boutons est modifiable de 4 � 17 pixels. 
Plus la valeur sera petite, plus la taille du tableau de bord diminuera. 
:p.
.*************************************************************************
.* SECTION : HISTORY                                                     *
.*************************************************************************
:h2 res=201.Historique
:p.
18.12.2011 V1.08 &colon. 
:ul compact.
:li.Support de la langue fran�aise (par Guillaume Gay).
:li.Dutch translation thanks to Jan van der Heide
:li.Swedish translation thanks to Bj�rn S�derstr�m
:li.Use of PNG icons if WPS-Wizard (http://svn.netlabs.org/wps-wizard) is installed
:eul.
:p.
V1.07 &colon. 
:ul compact.
:li.Correction du plantage sur eCS version 1.1 et sup�rieures. 
:li.Cliquer sur le bouton "Arr�t" invoque � pr�sent la bo�te de dialogue 
de confirmation du syst�me. 
:li.Renommage de la classe en CWBubblePad. 
:li.R��criture de la classe en C pur. Plus de Direct-to-SOM de mani�re � 
ce que la compilation avec n'importe quel compilateur C soit possible. 
:li.Bo�tes de dialogue des param�tres retravaill�es. 
:li.Changement du style de licence pour celui de BSD. 
:li.Bubblepd.dll n'a plus � �tre dans l'un des chemins de LIBPATH. 
:eul.
:p.
26.10.03 V1.06 &colon. 
:ul compact.
:li.Les noms de m�thodes Bubblepad �taient corrompus. 
:li.Correction de fuites de m�moire mineures. 
:li.Les mod�les prennent � pr�sent la forme de mod�les. Pour les 
mini-ic�nes il y a une petite marque. 
:li.Cliquer sur un mod�le fonction comme pr�vu (comme pour les 
mod�les normaux). 
:li.Correction d'erreurs dans la version anglaise. Merci � Peter 
Weilbacher pour le correctif. 
:eul.
:p.
22.06.2003 V1.05 &colon. 
:ul compact.
:li.Les exportations de M_WPLnchCWClassData, M_WPLnchCWCClassData et 
M_WPLnchCWNewClass n'�taient pas d�finies -&gt. pas de surclassage 
possible. 
:li.Les boutons du bloc-notes ne sont pas � la m�me place sur Warp 4. 
:eul.
:p.
28.12.98 V1.04 (version interne) &colon. 
:ul compact.
:li.Correction de bug qui provoquait l'ouverture de BubblePad avec les 
valeurs par d�faut lorsque l'entr�e LAUNCHPAD �tait pr�sente dans la 
ligne AUTOSTART du CONFIG.SYS. Ce bug a �t� introduit avec les cha�nes 
de param�tres de la V1.03. 
:eul.
:p.
15.11.98 V1.03 &colon. 
:sl.
:li.Nouvelles fonctionnalit�s &colon. 
:ul compact.
:li.Ajout de l'option pour d�sactiver la r�ouverture des tiroirs. 
:li.Ajout de la page d'options pour cacher chacun des boutons d'action. 
:li.Ajout de cha�nes de param�tres pour faciliter l'automatisation 
de l'installation. 
:li.Inclusion d'un utilitaire pour remplacer/restituer la classe 
WPLaunchPad. 
:eul.
:esl.
:p.
19.09.98 V1.02:
:sl.
:li.Nouvelles fonctionnalit�s &colon. 
:ul compact.
:li.Ajout de la fonction Cacher les boutons de tiroirs. 
:li.Ajout de param�tres individuels pour BubblePads. 
:li.Ajout de la sauvegarde de l'�tat des tiroirs. Les tiroirs sont 
r�ouverts au prochain d�marrage du syst�me. Ne fonctionne pas avec 
l'ouverture/fermeture usuelle. 
:eul.
:li.Corrections de bugs &colon. 
:ul compact.
:li.Correction du positionnement de la fen�tre d'aide du tableau de bord 
en haut du bureau. 
:li.Correction du bugs des r�f�rences bris�es engendrant la disparition 
de tiroirs. 
:li.D�placement du r�arrangement des boutons de wpRefreshDrawer() vers 
wpSetDrawerHWND(). Ceci �limine le clignotement � l'ouverture des 
tiroirs. 
:li.INSTALL.EXE copiait toujours le fichier d'aide en anglais dans les 
versions pr�c�dentes. 
:eul.
:esl.
:p.
20.08.98 V1.01 &colon. 
:ul compact.
:li.Correction du probl�me de fen�tres d'aide persistantes. Les fen�tres 
d'aide sont � pr�sent toujours correctement d�truites, m�me si les 
tiroirs sont param�tr�s pour de refermer automatiquement. 
:eul.
:p.
18.08.98 V1.00b &colon. 
:ul compact.
:li.Correction du positionnement des tiroirs. Les tiroirs sous ou � 
gauche du tableau de bord �taient plac�s avec un d�calage par rapport � 
ce dernier. 
:li.R��criture des routines de temporisation pour les fen�tres d'aide. 
:eul.
:p.
16.08.98 V1.00a &colon. 
:ul compact.
:li.Correction d'un bug dans INSTALL.EXE qui emp�chait parfois 
l'acceptation du r�pertoire d'installation par d�faut. 
:li.Contournement de probl�me &colon. la fen�tre d'aide dynamique reste 
visible sur certains syst�mes. Lorsque l'aide reste coll�e sur le bureau, 
d�placez le curseur sur un autre bouton pour vous en d�barrasser. 
:eul.
:p.
25.06.98 V1.00 &colon. 
:sl.
:li.Premi�re version publique. 
:esl.
:p.
.*************************************************************************
.* SECTION : COLOR AND FONT                                              *
.*************************************************************************
:h2 res=202.Couleurs et police
:p.
Les couleurs et la police des bulles d'aide peuvent �tre personnalis�es. 
Vous pouvez les modifier � l'aide des palettes de couleurs et de polices 
situ�es dans le dossier :hp2.Configuration du syst�me:ehp2.&per. 
D�posez juste la couleur ou la police sur le conteneur de la deuxi�me 
page d'aide "Bulles d'aide". Appuyez sur la touche 'Ctrl' pendant 
l'op�ration de glisser/d�poser si vous voulez modifier la couleur du 
texte. 
Ouvrez les palettes de couleurs et de police en cliquant sur les boutons 
:hp2.Couleur...:ehp2. et :hp2.Polices...:ehp2. respectivement. 
:note.les modifications prennent effet apr�s avoir ferm� le bloc-notes. 

:p.
:sl.
:li.:link reftype=hd res=310.Couleur...:elink. 
:li.:link reftype=hd res=311.Police...:elink.
:li.:link reftype=hd res=312.D�faire:elink.
:li.:link reftype=hd res=313.Par d�faut:elink.
:li.:link reftype=hd res=314.Aide:elink.
:esl. 
.*************************************************************************
.* SECTION : HELP FOR COLOR                                              *
.*************************************************************************
:h3 res=310.Aide pour Couleur...
:p.
Ouvrez la palette de couleurs situ�e dans le dossier :hp2.Configuration 
du syst�me:ehp2.&per. en cliquant sur ce bouton. 
:p.
.*************************************************************************
.* SECTION : HELP FOR FONT                                               *
.*************************************************************************
:h3 res=311.Aide pour la police...
:p.
Ouvrez la palette de polices situ�e dans le dossier :hp2.Configuration 
du syst�me:ehp2.&per. en cliquant sur ce bouton. 
:p.
.*************************************************************************
.* SECTION : HELP FOR UNDO                                               *
.*************************************************************************
:h3 res=312.Aide pour D�faire
:p.
Cliquez sur ce bouton pour r�tablir la configuration pr�c�dente. 
:p.
.*************************************************************************
.* SECTION : HELP FOR STANDARD                                           *
.*************************************************************************
:h3 res=313.Aide pour Par d�faut
:p.
Cliquez sur ce bouton pour s�lectionner les valeurs par d�faut pour les 
couleurs et la police. 
.br
Le texte est en :hp2.noir:ehp2. sur fond :hp2.jaune p�le:ehp2.&per. La 
police est :hp2.8.Helv:ehp2.&per. 
:p.
.*************************************************************************
.* SECTION : HELP FOR STANDARD                                           *
.*************************************************************************
:h3 res=314.Aide pour Aide
:p.
Ce bouton invoque l'aide. 
:p.
.*************************************************************************
.* SECTION : HELP FOR STANDARD                                           *
.*************************************************************************
:h2 res=400.S�lection des boutons d'action
:p.
Utilisez les cases � cocher de cette page pour activer ou d�sactiver 
chacun des boutons d'action. 
:p.
:euserdoc.
