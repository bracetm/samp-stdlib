/*  SA-MP Extra Functions
 *
 *  (c) Copyright 2005-2015, SA-MP Team
 *
 *  Modified by the SA:MP API team.
 *
 */

#if defined _extra_included
	#endinput
#endif
#define _extra_included
#pragma library extra

stock strtok(const string[], &index, delimiter = ' ') 
{
	new length = strlen(string);
	while ((index < length) && (string[index] <= delimiter)) {
		index++;
	}
	new offset = index;
	new result[128];
	while ((index < length) && (string[index] > delimiter) && ((index - offset) < (sizeof(result) - 1))) {
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}

stock strrest(const string[], &index)
{
	new length = strlen(string);
	while ((index < length) && (string[index] <= ' '))
	{
		index++;
	}
	new offset = index;
	new result[128];
	while ((index < length) && ((index - offset) < (sizeof(result) - 1)))
	{
		result[index - offset] = string[index];
		index++;
	}
	result[index - offset] = EOS;
	return result;
}