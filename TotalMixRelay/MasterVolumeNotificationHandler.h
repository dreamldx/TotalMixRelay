#pragma once
#include "AudioEndpointControl.h"
#include "OSCController.h"

class OSCMasterVolumeNotificationHandler :
	public CVolumeNotificationHandler {
	OSCController* control;
public:
	OSCMasterVolumeNotificationHandler(OSCController* c);
	~OSCMasterVolumeNotificationHandler();

	void OnVolumeChanged(float volumeValue);
	void OnMuteChanged(bool muteValue);
};

