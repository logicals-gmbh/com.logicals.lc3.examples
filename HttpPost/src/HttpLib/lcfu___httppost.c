#ifndef LC_PROT_LCFU___HTTPPOST__C
#define LC_PROT_LCFU___HTTPPOST__C

#include <lcfu___httppost.h>
#include <curl/curl.h>

/* source code taken from the libcurl examples: https://curl.haxx.se/libcurl/c/http-post.html */

/*                            Functions                        */
void lcfu___HTTPPOST(LC_TD_Function_HTTPPOST* LC_this, LcCgChar LC_VD_URL[1025],
		LcCgChar LC_VD_POSTFIELDS[1025], struct _lcoplck_epdb_1_impl* pEPDB) {
	CURL *curl;
	CURLcode res;

	/* In windows, this will init the winsock stuff */
	curl_global_init(CURL_GLOBAL_ALL);

	/* get a curl handle */
	curl = curl_easy_init();
	if (!curl) {
		LC_this->LC_VD_ENO = LC_EL_false;
		curl_global_cleanup();
		return;
	}

	/* First set the URL that is about to receive our POST. This URL can
	 just as well be a https:// URL if that is what should receive the
	 data. */
	curl_easy_setopt(curl, CURLOPT_URL, (char const* )LC_VD_URL);
	/* Now specify the POST data */
	curl_easy_setopt(curl, CURLOPT_POSTFIELDS, (char const* )LC_VD_POSTFIELDS);

	/* Perform the request, res will get the return code */
	res = curl_easy_perform(curl);
	/* Check for errors */
	if (res != CURLE_OK) {
		LC_this->LC_VD_ENO = LC_EL_false;
	} else {
		long http_code;
		curl_easy_getinfo(curl, CURLINFO_RESPONSE_CODE, &http_code);
		LC_this->LC_VD_RETURNCODE = http_code;
	}
	curl_easy_cleanup(curl);
	curl_global_cleanup();
}

#endif
