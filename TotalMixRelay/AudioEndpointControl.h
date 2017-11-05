#pragma once

class CVolumeNotificationHandler : public IAudioEndpointVolumeCallback {
	LONG m_RefCount;
	boolean muteStatus;
	
public:
	CVolumeNotificationHandler(void) : m_RefCount(1)
	{
	}
	~CVolumeNotificationHandler(void) {};
	STDMETHODIMP_(ULONG)AddRef() { return InterlockedIncrement(&m_RefCount); }
	STDMETHODIMP_(ULONG)Release()
	{
		LONG ref = InterlockedDecrement(&m_RefCount);
		if (ref == 0)
			delete this;
		return ref;
	}
	STDMETHODIMP QueryInterface(REFIID IID, void **ReturnValue)
	{
		if (IID == IID_IUnknown || IID == __uuidof(IAudioEndpointVolumeCallback)) {
			*ReturnValue = static_cast<IUnknown*>(this);
			AddRef();
			return S_OK;
		}
		*ReturnValue = NULL;
		return E_NOINTERFACE;
	}

	STDMETHODIMP OnNotify(PAUDIO_VOLUME_NOTIFICATION_DATA NotificationData)
	{
		OnVolumeChanged(NotificationData->fMasterVolume);
		if (muteStatus != NotificationData->bMuted) {
			OnMuteChanged(NotificationData->bMuted);
			muteStatus = NotificationData->bMuted;
		}
		return S_OK;
	}

	virtual void OnVolumeChanged(float volumeValue) = 0;
	virtual void OnMuteChanged(bool muteValue) = 0;
};


class AudioEndpointControl {
	IAudioEndpointVolume *endpointVolume = NULL;
public:
	AudioEndpointControl();
	~AudioEndpointControl();

	void RegisterNotification(CVolumeNotificationHandler* handler);
	float GetMasterVolume();
};

