#include "highgui.h"  
  
int main(int argc,char **argv)  
  
{  
  IplImage* img=cvLoadImage(argv[1]);  
  cvNamedWindow("PICTURE",CV_WINDOW_AUTOSIZE);  
  cvShowImage("PICTURE",img);  
  cvWaitKey(0);  
  cvReleaseImage(&img);  
  cvDestroyWindow("PICTURE");  
}  
