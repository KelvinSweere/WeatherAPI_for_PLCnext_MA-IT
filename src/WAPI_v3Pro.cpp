#include "WAPI_v3Pro.hpp"
#include "Arp/System/Commons/Logging.h"
#include "Arp/System/Core/ByteConverter.hpp"

#include <iostream>
#include <stdio.h>

//Include all curl packages...
#include "curl/curl.h"

//JSON library...
#include "nlohmann/json.hpp"
using json = nlohmann::json;

using namespace std;

//External functions
size_t CurlWrite_CallbackFunc_StdString(void* contents, size_t size, size_t nmemb, std::string* s);

namespace WAPI_v3
{

void WAPI_v3Pro::Execute()
{
	//Convert from StaticString<80> to regular C++ string.
	std::string _key = key.ToString();
	std::string _city = city.ToString();

	//Only continue if non of the two strings are empty.
	if(!_city.empty() && !_key.empty())
	{
		//Convert key and city to a (string) URL.
		string url = "http://api.openweathermap.org/data/2.5/weather?q=" + _city + "&appid=" + _key;

		const char* c_url = url.c_str();

		//Create a new instance from the CURL class, as a pointer, with the name curl.
		curl_global_init(CURL_GLOBAL_DEFAULT);
		CURL* curl = curl_easy_init();
		CURLcode res;

		std::string curl_string;

		//If curl is correctly initialized.
		if (curl)
		{
			curl_easy_setopt(curl, CURLOPT_URL, c_url);
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L); //only for https
			curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L); //only for https
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWrite_CallbackFunc_StdString);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curl_string);
			curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L); //remove this to disable verbose output

			res = curl_easy_perform(curl);
			curl_easy_cleanup(curl);

			//If the curl messages is correctly send.
			if (res == CURLE_OK)
			{
				// Convert string to json object. NOTE: The program can't find j_complete or parse. It's a bug from Phoenix...
				json j_complete = json::parse(curl_string);

				//Get the termpature from the object.
				temperature = (float32) j_complete["main"]["temp"];
				//Convert temperature from Kelvin to Celcuis.
				temperature -= 273.15;
			}
		}
	}
}

} // end of namespace

//Callback function within curl to convert data to string.
size_t CurlWrite_CallbackFunc_StdString(void* contents, size_t size, size_t nmemb, std::string* s)
{
	size_t newLength = size * nmemb;
	try
	{
		s->append((char*)contents, newLength);
	}
	catch (std::bad_alloc& e)
	{
		//handle memory problem
		return 0;
	}
	return newLength;
}
