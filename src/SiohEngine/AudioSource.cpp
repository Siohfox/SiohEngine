#include "AudioSource.h"
#include <stdexcept>

namespace SiohEngine
{
	AudioSource::AudioSource()
	{
		/*************************************************************************
		 * Preparing sound source
		 *************************************************************************/
		m_sourceId = 0;
		alGenSources(1, &m_sourceId);
	}

	void AudioSource::PlaySound(std::shared_ptr<AudioClip> clip, ALfloat _volume)
	{
		//alSource3f(sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcef(m_sourceId, AL_PITCH, 2);
		alSourcef(m_sourceId, AL_GAIN, _volume);

		alSourcei(m_sourceId, AL_BUFFER, clip->GetBufferId());
		alSourcePlay(m_sourceId);
	}

	void AudioSource::SetAudio()
	{

	}
}

