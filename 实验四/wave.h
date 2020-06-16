typedef struct _tagMsWavPcmHeader44 {
	unsigned char ChunkID[4]; // "RIFF"; The "RIFF" the mainchunk;
	unsigned long ChunkSize; // FileSize - 8; The size following this data
	unsigned char Format[4];
	// "WAVE"; The "WAVE" format consists of two subchunks: "fmt " and "data"
	unsigned char SubChunk1ID[4]; // "fmt "
	unsigned long SubChunk1Size;
	// 16 for PCM. This is the size of the rest of the subchunk which follows this data.
	unsigned short AudioFormat; // 1 for PCM. Linear quantization
	unsigned short NumChannels; // 1->Mono, 2->stereo, etc..
	unsigned long SampleRate; // 8000, 11025, 16000, 44100, 48000, etc..
	unsigned long ByteRate; // = SampleRate * NumChannels * BitsPerSample/8
	unsigned short BlockAlign; // = NumChannels * BitsPerSample / 8
	unsigned short BitsPerSample; // 8->8bits, 16->16bits, etc..
	unsigned char SubChunk2ID[4]; // "data"
	unsigned long SubChunk2Size;
	// = NumSamples * NumChannels * BitsPerSample / 8. The size of data
} wav ;
