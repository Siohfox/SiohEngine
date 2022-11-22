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
			_format = AL_FORMAT_MONO16;
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
		m_volume = 1.0f;

		std::vector<unsigned char> bufferData;
		load_ogg("../dixie_horn.ogg", bufferData, m_format, m_freq);

		m_bufferId = 0;
		alGenBuffers(1, &m_bufferId);

		alBufferData(m_bufferId, m_format, &bufferData.at(0), static_cast<ALsizei>(bufferData.size()), m_freq);

		/*************************************************************************
		 * Preparing sound source
		 *************************************************************************/
		m_sourceId = 0;
		alGenSources(1, &m_sourceId);

		
	}

	void AudioSource::PlaySound(AudioClip clip, ALfloat _volume)
	{
		//alSource3f(sourceId, AL_POSITION, 0.0f, 0.0f, 0.0f);
		alSourcef(m_sourceId, AL_PITCH, 2);
		alSourcef(m_sourceId, AL_GAIN, _volume);

		alSourcei(m_sourceId, AL_BUFFER, m_bufferId);
		alSourcePlay(m_sourceId);
	}

	void AudioSource::OnTick()
	{
		/*AudioClip clip;
		ALfloat volume = 1.0f;
		PlaySound(clip, volume);*/
	}
}

