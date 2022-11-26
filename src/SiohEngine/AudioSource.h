#ifndef SIOHENGINE_AUDIOSOURCE_H
#define SIOHENGINE_AUDIOSOURCE_H

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
		
		
		ALuint GetSourceId() { return m_sourceId; }

		void PlaySound(AudioClip clip, ALfloat volume);

	private:
		ALuint m_sourceId;
	};
}
#endif