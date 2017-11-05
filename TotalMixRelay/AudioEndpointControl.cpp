#include "stdafx.h"
#include "AudioEndpointControl.h"
#include <mmdeviceapi.h>

AudioEndpointControl::AudioEndpointControl()
{
}


AudioEndpointControl::~AudioEndpointControl()
{
}

void AudioEndpointControl::RegisterNotification(CVolumeNotificationHandler* handler)
{
	HRESULT hr;
	IMMDeviceEnumerator *deviceEnumerator = NULL;
	hr = CoCreateInstance(__uuidof(MMDeviceEnumerator), NULL, CLSCTX_INPROC_SERVER, __uuidof(IMMDeviceEnumerator), (LPVOID *)&deviceEnumerator);
	
	IMMDevice *defaultDevice = NULL;

	hr = deviceEnumerator->GetDefaultAudioEndpoint(eRender, eConsole, &defaultDevice);
	deviceEnumerator->Release();
	deviceEnumerator = NULL;

	hr = defaultDevice->Activate(__uuidof(IAudioEndpointVolume), CLSCTX_INPROC_SERVER, NULL, (LPVOID *)&endpointVolume);
	hr = endpointVolume->RegisterControlChangeNotify(handler);

	defaultDevice->Release();
	defaultDevice = NULL;
}

float AudioEndpointControl::GetMasterVolume()
{
	float level;
	endpointVolume->GetMasterVolumeLevelScalar(&level);
	return level;
}
