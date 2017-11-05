#include "stdafx.h"
#include "MasterVolumeNotificationHandler.h"


OSCMasterVolumeNotificationHandler::OSCMasterVolumeNotificationHandler(OSCController* c) {
	control = c;
}

OSCMasterVolumeNotificationHandler::~OSCMasterVolumeNotificationHandler() {
}

void OSCMasterVolumeNotificationHandler::OnVolumeChanged(float volumeValue) {
	control->SetMasterVolume(volumeValue);
}

void OSCMasterVolumeNotificationHandler::OnMuteChanged(bool muteValue) {
	control->SetMasterMute(muteValue);
}
