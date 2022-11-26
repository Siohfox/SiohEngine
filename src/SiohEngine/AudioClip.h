#ifndef SIOHENGINE_AUDIOCLIP_H
#define SIOHENGINE_AUDIOCLIP_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include <AL/al.h>
#include <AL/alc.h>

namespace SiohEngine
{
	struct AudioSource;

	/*
	* A container for audio data
	* An audio clip stores the audio file as an ogg vorbis
	*/
	struct AudioClip
	{
		AudioClip();

		ALuint GetBufferId() { return m_bufferId; }

		static void load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer,
			ALenum& _format, ALsizei& _freq);

	private:
		ALenum m_format;
		ALsizei m_freq;
		ALuint m_bufferId;
	};
}

#endif