#include <stdio.h>
#include <stdlib.h>
#include <mfhdf.h>
#include <hdf.h>
#include <HdfEosDef.h>

int16 * getArray(char *infn)
{
  FILE *fp;
  static int16 arr[5036850];
  //fp = fopen("arr.int16.600.600.bin","rb");
  //fread(arr,sizeof(int16),360000,fp);
  fp = fopen("modis.nir.int16.geo.bin","rb");
  fread(arr,sizeof(int16),5036850,fp);
  fclose(fp);
  return arr;
}

int make_hdf(char *infn, char *outfn)
{
  intn status;
  int i;
  static int16 arr[5036850];
  printf("input fn:%s, output fn: %s\n",infn,outfn);
  // arr = getArray(infn);
  printf("%d\n",*(arr+0));
  int32 fid = GDopen(outfn, DFACC_CREATE);

  float64 uplft[2] = {132000019.65,-10000000.00};
  float64 lowrgt[2] ={148059005.60,-20000000.00};
  int xdim = 2925, ydim = 1722;
  int32 gridID = GDcreate(fid, "Geo", xdim, ydim, uplft, lowrgt);
  status = GDdefproj(gridID, GCTP_GEO, '\0', '\0', NULL); 
  //status = GDdefdimscale(gridID, "XDim", xdim, DFNT_FLOAT64, NULL);
  //status = GDdefdimscale(gridID, "YDim", ydim, DFNT_FLOAT64, NULL);
  status = GDdeffield(gridID, "1km", "YDim,XDim", DFNT_UINT16, HDFE_NOMERGE);
  status = GDwritefield(gridID, "1km", NULL, NULL, NULL, arr);
  status = GDdeffield(gridID, "10km", "YDim,XDim", DFNT_UINT16, HDFE_NOMERGE);
  status = GDwritefield(gridID, "10km", NULL, NULL, NULL, arr);
  status = GDdeffield(gridID, "100km", "YDim,XDim", DFNT_UINT16, HDFE_NOMERGE);
  status = GDwritefield(gridID, "100km", NULL, NULL, NULL, arr);
  status = GDdetach(gridID);
  status = GDclose(fid);
  return 0;
}

// int main(int argc, char **argv)
// {
//   // char *infn,*outfn;
//   // intn status;
//   // int i;
//   // int16 *arr;
//   // infn = argv[1];
//   // outfn = argv[2];
//   // printf("input fn:%s, output fn: %s\n",infn,outfn);
//   // arr = getArray(infn);
//   // printf("%d\n",*(arr+0));
//   // int32 fid = GDopen("./HM08.hdf",DFACC_CREATE);

//   // float64 uplft[2] = {132000019.65,-10000000.00};
//   // float64 lowrgt[2] ={148059005.60,-20000000.00};
//   // int xdim = 2925, ydim = 1722;
//   // int32 gridID = GDcreate(fid, "Geo", xdim, ydim, uplft, lowrgt);
//   // status = GDdefproj(gridID, GCTP_GEO, '\0', '\0', NULL); 
//   // //status = GDdefdimscale(gridID, "XDim", xdim, DFNT_FLOAT64, NULL);
//   // //status = GDdefdimscale(gridID, "YDim", ydim, DFNT_FLOAT64, NULL);
//   // status = GDdeffield(gridID, "1km", "YDim,XDim", DFNT_UINT16, HDFE_NOMERGE);
//   // status = GDwritefield(gridID, "1km", NULL, NULL, NULL, arr);
//   // status = GDdeffield(gridID, "10km", "YDim,XDim", DFNT_UINT16, HDFE_NOMERGE);
//   // status = GDwritefield(gridID, "10km", NULL, NULL, NULL, arr);
//   // status = GDdeffield(gridID, "100km", "YDim,XDim", DFNT_UINT16, HDFE_NOMERGE);
//   // status = GDwritefield(gridID, "100km", NULL, NULL, NULL, arr);
//   // status = GDdetach(gridID);
//   // status = GDclose(fid);

//   return 0;
// }