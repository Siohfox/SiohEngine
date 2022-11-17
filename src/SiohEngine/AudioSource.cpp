#include "AudioSource.h"
#include "STB_vorbis.c"
#include <stdexcept>

namespace SiohEngine
{
	static void load_ogg(const std::string& _path, std::vector<unsigned char>& _buffer,
		ALenum& _format, ALsizei& _freq)
	{
		int channels = 0;
		int sampleRate = 0;
		short* output = NULL;

		size_t samples = stb_vorbis_decode_filename(_path.c_str(),
			&channels, &sampleRate, &output);

		if (samples == -1)
		{
			throw std::runtime_error("Failed to open file '" + _path + "' for decoding");
		}

		// Record the format required by OpenAL
		if (channels < 2)
		{
			_format = AL_FORMAT_MONO16;
		}
		else
		{
			_format = AL_FORMAT_STEREO16;
		}

		// Copy (# samples) * (1 or 2 channels) * (16 bits == 2 bytes == short)
		_buffer.resize(samples * channels * sizeof(short));
		memcpy(&_buffer.at(0), output, _buffer.size());

		// Record the sample rate required by OpenAL
		_freq = sampleRate;

		// Clean up the read data
		free(output);
	}


	AudioSource::AudioSource()
	{
		m_format = 0;
		m_freq = 0;

		std::vector<unsigned char> bufferData;
		load_ogg("../dixie_horn.ogg", bufferData, m_format, m_freq);

		ALuint bufferId = 0;
		alGenBuffers(1, &bufferId);

		alBufferData(bufferId, m_format, &bufferData.at(0),
			static_cast<ALsizei>(bufferData.size()), m_freq);

		/*************************************************************************
		 * Preparing sound source
		 *************************************************************************/
		ALuint sourceId = 0;
		alGenSources(1, &sourceId);

		alSourcei(sourceId, AL_BUFFER, bufferId);
		//alSource3f(sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
		//alSourcef(sourceId, AL_PITCH, 10);
		//alSourcef(sourceId, AL_GAIN, vol);

		/*************************************************************************
		 * Play audio
		 *************************************************************************/
		alSourcePlay(sourceId);
	}

	AudioSource::AudioSource(std::string _path)
	{
		m_format = 0;
		m_freq = 0;

		std::vector<unsigned char> bufferData;
		load_ogg(_path, bufferData, m_format, m_freq);

		ALuint bufferId = 0;
		alGenBuffers(1, &bufferId);

		alBufferData(bufferId, m_format, &bufferData.at(0),
			static_cast<ALsizei>(bufferData.size()), m_freq);

		/*************************************************************************
		 * Preparing sound source
		 *************************************************************************/
		ALuint sourceId = 0;
		alGenSources(1, &sourceId);

		alSourcei(sourceId, AL_BUFFER, bufferId);
		//alSource3f(sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
		//alSourcef(sourceId, AL_PITCH, 10);
		//alSourcef(sourceId, AL_GAIN, vol);

		/*************************************************************************
		 * Play audio
		 *************************************************************************/
		alSourcePlay(sourceId);
	}
}

