//---------------------------------------------------------------------------
#include "../kernel/fxClass.h"
#include "../shared/fxList.h"

#include "../kernel/fxConsole.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//---------------------------------------------------------------------------

struct fxObjectNode
	{
	char * ObjectName;
	void * ObjectPointer;
	};


fxList fxClass::ObjectList;

void * fxClass::FindObject(char * ObjectName)
{
for (int i=0; i < ObjectList.Count; i++)
	{
	fxObjectNode * node = (fxObjectNode*)ObjectList.Get(i);
	if (strcmp(ObjectName, node->ObjectName) ==0)
		{
		return node->ObjectPointer;
		}
	}
return NULL;
}

void fxClass::RegisterObject(void * ObjectPointer, char * ObjectName)
{
fxConsole * Console = (fxConsole*)FindObject("fxConsole");
if (Console != NULL)
	{
	char * s;
	s = (char*)malloc(64);
	sprintf(s,"registering object: %s", ObjectName);
	Console->DisplayString(s);
	}

fxObjectNode * node;
node = new fxObjectNode;

node->ObjectName = (char*)malloc(strlen(ObjectName)+1);
strcpy(node->ObjectName, ObjectName);

node->ObjectPointer = ObjectPointer;

void * o = FindObject(ObjectName);

if (o != NULL) ObjectList.Delete(o);

ObjectList.Add(node);
}

void fxClass::UnregisterObject(char * ObjectName)
{
for (int i=0; i < ObjectList.Count; i++)
	{
	fxObjectNode * node = (fxObjectNode*)ObjectList.Get(i);
	if (strcmp(ObjectName, node->ObjectName) ==0)
		{
		fxConsole * Console = (fxConsole*)FindObject("fxConsole");
		if (Console != NULL)
			{
			char * s;
			s = (char*)malloc(64);
			sprintf(s,"unregistering object: %s", ObjectName);
			Console->DisplayString(s);
			}
		ObjectList.Remove(i);
		return;
		}
	}
}
