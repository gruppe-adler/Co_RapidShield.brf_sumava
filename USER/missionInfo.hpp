/*
*   Legt allgemeine Information über die Mission fest.
*/

author = "nomisum für Gruppe Adler";                                               // Missionsersteller
onLoadName = "Co Rapid Shield";                                                   // Name der Mission
onLoadMission = "";                                                             // Beschreibung der Mission (wird im Ladebildschirm unterhalb des Ladebildes angezeigt)
loadScreen = "data\loading.jpg";                                                // Ladebild
overviewPicture = "";                                                           // Bild, das in der Missionsauswahl angezeigt wird
overviewText = "";                                                              // Text, der in der Missionsauswahl angezeigt wird


#include "..\node_modules\grad-leaveNotes\grad_leaveNotes.hpp"

class GRAD_leaveNotes {
    playerDistance = 1;             
    actOffset[] = {0,0,0.1};        
    actDist = 2;                    
    noteObject = "Land_Notepad_F";  
    startAmount = 10;               
    visibleHandwriting = 1;         
    canWriteDefault = 1;            
    canInspectDefault = 1;          
};