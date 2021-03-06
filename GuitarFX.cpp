
#include <iostream>
#include <thread>
#include <vector>
using namespace std;

#include "olcRealTimeSFX_WASAPI.h"

int main()
{
	vector<wstring> vecInputDevices = olcRealTimeSFX_WASAPI::EnumerateInputDevices();
	vector<wstring> vecOutputDevices = olcRealTimeSFX_WASAPI::EnumerateOutputDevices();

	for (auto s : vecInputDevices)
		wcout << L"INPUT : " << s << endl;

	for (auto s : vecOutputDevices)
		wcout << L"OUTPUT: " << s << endl;


	olcRealTimeSFX_WASAPI sfx;
	sfx.Create(vecOutputDevices[1], vecInputDevices[2],44100,2,8,512);

	while (1)
	{
		this_thread::sleep_for(1000ms);
	}

    return 0;
}

