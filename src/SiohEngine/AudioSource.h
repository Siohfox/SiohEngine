#include "Component.h"
#include <string>
#include <vector>
#include <AL/al.h>
#include <AL/alc.h>

namespace SiohEngine
{

	struct AudioSource : Component
	{
		AudioSource();
		AudioSource(std::string _path);

	private:
		ALenum m_format;
		ALsizei m_freq;
		ALuint m_bufferId;
		ALuint m_sourceId;
	};
}