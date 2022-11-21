#include "Component.h"
#include "AudioClip.h"
#include <string>
#include <vector>
#include <AL/al.h>
#include <AL/alc.h>

namespace SiohEngine
{

	struct AudioSource : Component
	{
		AudioSource();
		
		ALuint GetBufferId() { return m_bufferId; }
		ALuint GetSourceId() { return m_sourceId; }

		void PlaySound(AudioClip clip, ALfloat volume);

	private:
		ALenum m_format;
		ALsizei m_freq;
		ALuint m_bufferId;
		ALuint m_sourceId;
		ALfloat m_volume;

		std::string m_clip;
	};
}