//---------------------------------------------------------------------------
#include "fxParser.h"
#include <string.h>
#include <malloc.h>
//---------------------------------------------------------------------------

void AddChar(char * s, char ch)
{
s[strlen(s)+1] = '\0';
s[strlen(s)] = ch;
}

char fxParser::ReadChar(void)
{
char ch = (char)fgetc(stream);
if (ch == EOF) eof = true;
return ch;
}

int fxParser::GetNextToken(char * result)
{
strcpy(result, "");
char lastch;
char ch = ReadChar();


char * string;
string = (char*)malloc(256);
strcpy(string,"");

while (((ch == '\0') || (ch == '\n') || (ch == ' ') || (ch == '\t')) && (ch != EOF))
	{
	ch = ReadChar();

	}

while ((ch != '\0') && (ch != '\n') && (ch != ' ') && (ch != '\t') && (ch != EOF))
	{
	AddChar(string, ch);
	lastch = ch;
	ch = ReadChar();

	if ((lastch == '/') && (ch == '/'))
		{
		do
			{
			ch = ReadChar();
			} while (ch != '\n');
		string[strlen(string)-1] = '\0';
		break;
		}

	}

if (eof)
	{
	strcpy(result,string);
	free(string);
	return -1;
	}

if (strlen(string) == 0) GetNextToken(string);

strcpy(result,string);
free(string);
return 0;
}
