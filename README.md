# beep-boop-beep
Random name generator

This application is created using Qt Creator. For open source purposes, download the source code and cofigure the Qt Project File in your latest verion of Qt Creator. [See Fine Print](#Fine-Print) below.

## Function 
User can choose between generating either a two or three name format, default is set to two.

#### Two name format
Uses an adjective and a noun.

#### Three name format
Uses an adjective, verb and a noun.

### Usability
Throughout the session, once generate, the names will be be added to an array which will allow the the user to traverse back and forth through the names using the buttons next to the heart button. 
If there is a name the user would like to save permanently, they can click the heart button and it will save to the favorites.txt. 

#### Liked Names
The view on the right hand side will display all the saved names. If the user no longer wants a name to be saved, there is a Remove button to delete the name from the saved list. The list will update instantaneously when names are removed or saved.

## Fine Print
* favorites.txt is saved to a local destination. When you save the source code, copy and paste the new directory into ```QString path``` to avoid runtime errors.
* Right now the application uses vectors to store the adjectives, verbs and arrays. This will later be changed over to using a data model instead. 
* An executable file (.exe) will be created once dynamic data models are implemented. 
