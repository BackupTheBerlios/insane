//---------------------------------------------------------------------------
#include "fxVars.h"
#include <stdio.h>
#include <string.h>
//---------------------------------------------------------------------------

typedef struct
	{
	char name[64];
	int  value;
	int  flags;
	} IntVar_t;

typedef struct
	{
	char name[64];
	float  value;
	int  flags;
	} FloatVar_t;

typedef struct
	{
	char name[64];
	char value[256];
	int  flags;
	} StringVar_t;


fxVars::fxVars()
{
ClassName = "fxVars";
RegisterObject(this, ClassName);

IntVars = new fxList;
FloatVars = new fxList;
StringVars = new fxList;

StdIntValue = 0;
StdFloatValue = 0;
StdStringValue = "NULL";
};

fxVars::~fxVars(void)
{
UnregisterObject("fxVars");
delete IntVars;
delete FloatVars;
delete StringVars;
};

void fxVars::NewIntVar( char* name, int value, int flags )
{
for (int i=0; i < IntVars->Count; i++)
        {
	IntVar_t* t_int = (IntVar_t*)IntVars->Get(i);
        if (!strcmp(name,t_int->name)) return;
        }

IntVar_t* temp_int = new IntVar_t;

strcpy(temp_int->name, name);
temp_int->flags = flags;
temp_int->value = value;

IntVars->Add(temp_int);
};

void fxVars::NewFloatVar( char* name, float value, int flags )
{
for (int i=0; i < FloatVars->Count; i++)
	{
	FloatVar_t* t_float = (FloatVar_t*)FloatVars->Get(i);
	if (!strcmp(name,t_float->name)) return;
	}

FloatVar_t* temp_float = new FloatVar_t;

strcpy(temp_float->name, name);
temp_float->flags = flags;
temp_float->value = value;

FloatVars->Add(temp_float);
};

void fxVars::NewStringVar( char* name, char* value, int flags )
{
if (strlen(value) == 0) return;
for (int i=0; i < StringVars->Count; i++)
	{
	StringVar_t* t_string = (StringVar_t*)StringVars->Get(i);
	if (!strcmp(name,t_string->name)) return;
	}

StringVar_t* temp_string = new StringVar_t;

strcpy(temp_string->name, name);
temp_string->flags = flags;
strcpy(temp_string->value, value);

StringVars->Add(temp_string);
};

int fxVars::GetIntValue ( char* name )
{
IntVar_t* temp_int;

for (int i=0; i < IntVars->Count; i++)
	{
	temp_int = (IntVar_t*)IntVars->Get(i);
	if (!strcmp(name, temp_int->name)) return temp_int->value;
	}
return StdIntValue;
};


float  fxVars::GetFloatValue ( char* name )
{
FloatVar_t* temp_float;

for (int i=0; i < FloatVars->Count; i++)
	{
	temp_float = (FloatVar_t*)FloatVars->Get(i);
	if (!strcmp(name, temp_float->name)) return temp_float->value;
	}
return StdFloatValue;
};


char* fxVars::GetStringValue ( char* name )
{
StringVar_t* temp_string;

for (int i=0; i < StringVars->Count; i++)
	{
	temp_string = (StringVar_t*)StringVars->Get(i);
	if (!strcmp(name, temp_string->name)) return temp_string->value;
	}
return StdStringValue;
};

void fxVars::SaveToFile( char * name )
{
FILE* f;
f = fopen(name,"wt");

if (!f) return;

IntVar_t* temp_int;
FloatVar_t* temp_float;
StringVar_t* temp_string;

fprintf(f,"%s","IntVars { \n");
for (int i=0; i < IntVars->Count; i++)
	{
	temp_int = (IntVar_t*)IntVars->Get(i);
	fprintf(f, "%s %s %s %i %s", "   ", temp_int->name, " { ",temp_int->value, " } \n");
	}
fprintf(f,"%s","    }\n");
fprintf(f,"%s","FloatVars { \n");
for (i=0; i < FloatVars->Count; i++)
	{
	temp_float = (FloatVar_t*)FloatVars->Get(i);
	fprintf(f, "%s %s %s %f %s", "   ", temp_float->name, " { ",temp_float->value, " } \n");
	}
fprintf(f,"%s","    }\n");
fprintf(f,"%s","StringVars { \n");
for (i=0; i < StringVars->Count; i++)
	{
        temp_string = (StringVar_t*)StringVars->Get(i);
        fprintf(f, "%s %s %s %s %s", "   ", temp_string->name, " { ",temp_string->value, " } \n");
        }
fprintf(f,"%s","    }\n");
fclose(f);
};

bool fxVars::VarExists ( char * name)
{
IntVar_t* temp_int;
FloatVar_t* temp_float;
StringVar_t* temp_string;

for (int i=0; i < IntVars->Count; i++)
        {
	temp_int = (IntVar_t*)IntVars->Get(i);
	if (strcmp(temp_int->name, name)) return true;
	}
for (i=0; i < FloatVars->Count; i++)
	{
	temp_float = (FloatVar_t*)FloatVars->Get(i);
	if (strcmp(temp_float->name, name)) return true;
	}
for (i=0; i < StringVars->Count; i++)
	{
        temp_string = (StringVar_t*)StringVars->Get(i);
        if (strcmp(temp_string->name, name)) return true;
        }
return false;
};
