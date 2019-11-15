#include <stdio.h>
#include <stdlib.h>

// The "debug()" function works like this: "debug(ON, "test = %d", test);"
// void debug(bool isActive, char* control_string, ...var_args...);

#define debug(flag, fmt, ...); \
	if (DEBUG && flag) fprintf(stdout, "[%s:%d] " \
		fmt \
		"\n", __FILE__, __LINE__, ## __VA_ARGS__);
#define ON 1
#define OFF 0

int DEBUG = 1;

void debug_init(int arg)
{
	if (arg)
	{
		debug(ON, "Verbose debugging output has been enabled.");
	}
	else
	{
		DEBUG = 0;
	}

}

/*
int main()
{
	int i = 10, j = 405;
	char k[] = "example\n";
	debug(ON, "This is a test, here is int i: %d", i);
	
	debug(ON, "Here is another test, also with two variables " \
		"(k has a new line in a string for testing purposes) j: %d, and k: %s", j, k);
	
	debug(ON, "This is a debug with no arguments");

	debug(ON, "If you do not see this message, there is an error. (last debug message)");

	char word[] = "this is the string variable being printed";
	debug(ON, "Printing a string for debugging purposes: [%s]", word);
	return 0;
}
*/
