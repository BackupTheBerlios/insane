//---------------------------------------------------------------------------
#include <string.h>
#include "fxConsole.h"
//---------------------------------------------------------------------------

#define IFX_CONSOLE_STRINGS 200

fxList fxConsole::StringList;

void fxConsole::DisplayString(char * s)
{
/*
StringList.Add(s);
if (StringList.Count > IFX_CONSOLE_STRINGS)
	{
	char * s = StringList.Get(0);
	free(s);
	StringList.Remove(0);
	}
*/

//Form->DisplayString(s);
}

void fxConsole::DisplayError(char * s)
{
char * s1 = "ERROR: ";
s1 = strcat(s1,s);
/*
StringList.Add(s1);
if (StringList.Count > IFX_CONSOLE_STRINGS)
	{
	char * s = StringList.Get(0);
	free(s);
	StringList.Remove(0);
	}
*/
/*
Form->DisplayString("");
Form->DisplayString(s1);
Form->ShouldClose = true;
Form->Hide();
Form->ShowModal();
exit(EXIT_FAILURE);
*/
}
