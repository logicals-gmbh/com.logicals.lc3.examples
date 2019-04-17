#ifndef LC_PROT_LCFU___STRINGFROMBYTEARRAY__C
#define LC_PROT_LCFU___STRINGFROMBYTEARRAY__C

#include <lcfu___stringfrombytearray.h>

/*                            Functions                        */
void  lcfu___STRINGFROMBYTEARRAY(LC_TD_Function_STRINGFROMBYTEARRAY* LC_this, LC_TD_BYTE LC_VD_BYTEARRAY[1024], LC_TD_DINT LC_VD_LEN, struct _lcoplck_epdb_1_impl* pEPDB)
{
	int index;
	for (index = 0; index < LC_VD_LEN; index++)
	{
		LC_this->LC_VD_STRINGFROMBYTEARRAY[index] = LC_VD_BYTEARRAY[index];
	}
}

#endif
