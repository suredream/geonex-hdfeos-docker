/* This example shows how to read a data field in HDF-EOS2 grid data. */

#include <mfhdf.h>
#include <hdf.h>
#include <HdfEosDef.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int32 gridfile1;
	int32 grid1;
	int32 datafield1rank;
	int32 datafield1dimsize[32];
	int32 datafield1type;
	char datafield1dimname[512];
	float32 *datafield1data;
	int32 i, j;

	/* Open 'AMSR_E_L3_RainGrid_B05_200707.hdf' using grid API */
	if ((gridfile1 = GDopen("AMSR_E_L3_RainGrid_B05_200707.hdf", DFACC_RDONLY)) == -1) {
		fprintf(stderr, "error: cannot open grid 'AMSR_E_L3_RainGrid_B05_200707.hdf'\n");
		return -1;
	}

	/* Open a grid named 'MonthlyRainTotal_GeoGrid' */
	if ((grid1 = GDattach(gridfile1, "MonthlyRainTotal_GeoGrid")) == -1) {
		fprintf(stderr, "error: cannot attach to 'MonthlyRainTotal_GeoGrid'\n");
		return -1;
	}

	/* Retrieve information about 'TbOceanRain' datafield */
	if ((GDfieldinfo(grid1, "TbOceanRain", &datafield1rank, datafield1dimsize, &datafield1type, datafield1dimname)) == -1) {
		fprintf(stderr, "error: cannot get the field info for 'TbOceanRain'\n");
		return -1;
	}
	/* Allocate buffer for 'TbOceanRain' */
	if ((datafield1data = malloc(sizeof(float32) * 28 * 72)) == NULL) {
		fprintf(stderr, "error: cannot allocate memory for 'TbOceanRain'\n");
		return -1;
	}
	/* Read data from 'TbOceanRain' */
	if ((GDreadfield(grid1, "TbOceanRain", NULL, NULL, NULL, datafield1data)) == -1) {
		fprintf(stderr, "error: cannot read field 'TbOceanRain'\n");
		return -1;
	}
	/* Dump data from 'TbOceanRain' */
	for (i = 0; i < 28; ++i) {
		for (j = 0; j < 72; ++j) {
			printf("%f ", datafield1data[j + 72 * i]);
		}
		printf("\n");
	}
	/* Release the buffer for 'TbOceanRain' */
	free(datafield1data);

	/* Close the grid named 'MonthlyRainTotal_GeoGrid' */
	if ((GDdetach(grid1)) == -1) {
		fprintf(stderr, "error: cannot detach from 'MonthlyRainTotal_GeoGrid'\n");
		return -1;
	}

	/* Close 'AMSR_E_L3_RainGrid_B05_200707.hdf' */
	if ((GDclose(gridfile1)) == -1) {
		fprintf(stderr, "error: cannot close grid 'AMSR_E_L3_RainGrid_B05_200707.hdf'\n");
		return -1;
	}

	return 0;
}