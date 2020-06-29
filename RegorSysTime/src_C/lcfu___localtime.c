#ifndef LC_PROT_LCFU___LOCALTIME__C
#define LC_PROT_LCFU___LOCALTIME__C

#include <lcfu___localtime.h>

#include <time.h>
#include <stdlib.h>

/*                            Functions                        */
void  lcfu___LOCALTIME(LC_TD_Function_LOCALTIME* LC_this, struct _lcoplck_epdb_1_impl* pEPDB)
{
	struct tm* time_info = NULL;
	struct tm result;
	time_t t;

	t = time(NULL);
	time_info = localtime_r(&t, &result);

	LC_this->LC_VD_SEC = time_info->tm_sec;
	LC_this->LC_VD_MIN = time_info->tm_min;
	LC_this->LC_VD_HOUR = time_info->tm_hour;
	LC_this->LC_VD_MDAY = time_info->tm_mday;
	LC_this->LC_VD_MON = time_info->tm_mon + 1;
	LC_this->LC_VD_YEAR = 1900 + time_info->tm_year;
	LC_this->LC_VD_WDAY = time_info->tm_wday;
	LC_this->LC_VD_YDAY = time_info->tm_yday;
	LC_this->LC_VD_ISDST = time_info->tm_isdst ? LC_EL_true : LC_EL_false;
}

#endif
