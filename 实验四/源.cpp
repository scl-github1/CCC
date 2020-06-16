#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<stdint.h>
#include "wave.h"
#define FRAME (1024)
#define FIRLEN 82
void FIR(double *x, double*y,double*C,int Clength,int Ylength)
{
	int n, i;
	double temp;
	for (i = 0; i < Ylength; i++)
	{
		temp = 0;
		for (n = 0; n < Clength; n++)
		{
			if (i-n<0){}
			else
			{
				temp += C[n] * x[i - n];
			}
		}
		y[i] = temp;
	}
}
double RandDouble(double Max)
{
	int  range = 100 * int(Max);
	double ran = double(rand() % range) / 100;
	return ran;
}
void SiganlGeneConv()
{
	static double C1[7] = { -1,3,-5,7,-5,3,-1 };
	double z[20], ans[20];
	int i;
	for (i = 0; i < 20; i++)
	{
		z[i] = RandDouble(10);
	}
	FIR(z, ans, C1, 7, 20);
	//Display
	printf_s("Ô­ÐÅºÅ:\n");
	for (i = 0; i < 20; i++)
	{
		printf_s("%.2f  ", z[i]);
	}
	printf_s("\nÂË²¨ºó£º\n");
	for (i = 0; i < 20; i++)
	{
		printf_s("%.2f  ", ans[i]);
	}
}
int read(short* x, FILE* fp)
{
	int p =0;
	p = fread(x, sizeof(short), FRAME, fp);
	if (FRAME ==p)
	{
		return 0;
	}
	else
	{
		for (; p < FRAME; p++)
		{
			x[p] = 0;
		}
		return -1;
	}

}
int main()
{
	static double C2[82] = { 0.00020941,0.000502552,0.001016998,0.001760911,0.002714743,0.00379903,0.004869001,0.005723459,0.006131755,0.005876689,0.004807676,0.002894458,0.000266945,
	-0.002770085,-0.005759261,-0.008152134,-0.009405366,-0.009097254,-0.007042678,-0.0033798,0.001395532,0.006465894,0.010804203,0.013350573,0.013228287,0.009960354,0.003641954,
	-0.00497301,-0.014500696,-0.023081671,-0.028646955,-0.029258312,-0.023466756,-0.010624533,0.008910905,0.033727243,0.061482457,0.089194148,0.11365184,0.131886972,0.14162205,
	0.14162205,0.131886972,0.11365184,0.089194148,0.061482457,0.033727243,0.008910905,-0.010624533,-0.023466756,-0.029258312,-0.028646955,-0.023081671,-0.014500696,-0.00497301,
	0.003641954,0.009960354,0.013228287,0.013350573,0.010804203,0.006465894,0.001395532,-0.0033798,-0.007042678,-0.009097254,-0.009405366,-0.008152134,-0.005759261,-0.002770085,
	0.000266945,0.002894458,0.004807676,0.005876689,0.006131755,0.005723459,0.004869001,0.00379903,0.002714743,0.001760911,0.001016998,0.000502552,0.00020941 };
	static double C0[82] = {
	  0.0002088566718795,0.0005019666320485,  0.00101659692763, 0.001761517078465,
	   0.002717496869779, 0.003805742549565, 0.004881532449878, 0.005744013542788,
	   0.006161971401866, 0.005917629852047, 0.004859494981977, 0.002955831081991,
	  0.0003356045898205,-0.002697639896313,-0.005687071486917,-0.008084032953745,
	  -0.009344469124396,-0.009045419365927,-0.006999963923105,-0.003344508688152,
	   0.001426457367602, 0.006496401543416,  0.01083826348381,  0.01339119282049,
		0.01327693896666,   0.0100166598574, 0.003703629355468,-0.004909743327555,
	   -0.01444030683204, -0.02302828304832, -0.02860345497317, -0.02922565654424,
	   -0.02344372245441, -0.01060796387519, 0.008925525047616,  0.03374481923033,
		0.06150720551817,  0.08922868601273,   0.1136966478108,   0.1319402460404,
		 0.1416800797754,   0.1416800797754,   0.1319402460404,   0.1136966478108,
		0.08922868601273,  0.06150720551817,  0.03374481923033, 0.008925525047616,
	   -0.01060796387519, -0.02344372245441, -0.02922565654424, -0.02860345497317,
	   -0.02302828304832, -0.01444030683204,-0.004909743327555, 0.003703629355468,
		 0.0100166598574,  0.01327693896666,  0.01339119282049,  0.01083826348381,
	   0.006496401543416, 0.001426457367602,-0.003344508688152,-0.006999963923105,
	  -0.009045419365927,-0.009344469124396,-0.008084032953745,-0.005687071486917,
	  -0.002697639896313,0.0003356045898205, 0.002955831081991, 0.004859494981977,
	   0.005917629852047, 0.006161971401866, 0.005744013542788, 0.004881532449878,
	   0.003805742549565, 0.002717496869779, 0.001761517078465,  0.00101659692763,
	  0.0005019666320485,0.0002088566718795 };
	//SiganlGeneConv();
	int i;
	FILE* fr = NULL;
	FILE* fw = NULL;
	wav wave;
	errno_t err,err1;
	short x[FRAME] = { 0 };
	double ori[FRAME] = { 0 };
	double ans[FRAME] = { 0 };
	short y[FRAME] = { 0 };
	err = fopen_s(&fr, "D:\\LPF\\sin0K5+2K.wav", "rb");
	err1 = fopen_s(&fw, "D:\\LPF\\LPF(sin0K5+2K).wav", "wb");
	if (err||err1)
	{
		return 0;
	}
	fread(&wave, sizeof(wave),1, fr);
	printf("-----Information of The File:-------\n");
	printf("ChunkID: %c%c%c%c\n", wave.ChunkID[0], wave.ChunkID[1], wave.ChunkID[2], wave.ChunkID[3]);
	printf("ChunkSize: %u\n", wave.ChunkSize);
	printf("Format: %c%c%c%c\n", wave.Format[0], wave.Format[1], wave.Format[2], wave.Format[3]);
	printf("SubChunk1Size: %u\n", wave.SubChunk1Size);
	printf("AudioFormat: %u\n", wave.AudioFormat);
	printf("NumChannels: %u\n", wave.NumChannels);
	printf("SampleRate: %u\n", wave.SampleRate);
	printf("ByteRate: %u\n", wave.ByteRate);
	printf("BlockAlign: %u\n", wave.BlockAlign);
	printf("BitsPerSample: %u\n", wave.BitsPerSample);
	printf("SubChunk2ID: %c%c%c%c\n", wave.SubChunk2ID[0], wave.SubChunk2ID[1], wave.SubChunk2ID[2], wave.SubChunk2ID[3]);
	printf("SubChunk2Size: %u\n", wave.SubChunk2Size);
	printf("----------end!--------\n");
	fwrite(&wave,sizeof(wave), 1, fw);
	while (!read(x, fr))
	{
		for (i = 0; i < FRAME; i++)
		{
			ori[i] = double(x[i]);
		}
		FIR(ori, ans,C0, FIRLEN, FRAME);
		for (i = 0; i < FRAME; i++)
		{
			y[i] = short(ans[i]);
		}
		fwrite(y,sizeof(short), FRAME, fw);
	}
	fclose(fr);
	fclose(fw);
	printf("\n----------finished!--------\n");
	return 0;
}
