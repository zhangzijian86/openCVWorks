#include <cv.h>
#include <highgui.h>

int main(int argc,char** argv){
	IplImage* src;
	if(argc==7&&((src=cvLoadImage(argv[1],1)) !=0)){
		int x = atoi(argv[2]);
		int y = atoi(argv[3]);
		int width = atoi(argv[4]);
		int height = atoi(argv[5]);
		IplImage* sub_img = cvCreateImageHeader(
			cvSize(
				width,//interest_width
				height //interset_geight
			),
			src->depth,
			src->nChannels
		);
		sub_img->origin = src->origin;
		sub_img->widthStep = src->widthStep;
		sub_img->imageData = src->imageData +
		y*src->widthStep+x*src->nChannels;
		cvAddS(sub_img,cvScalar(100),sub_img);
		cvNamedWindow("Roi_Add",1);
		cvShowImage("Roi_Add",src);
		cvWaitKey();
		cvReleaseImage(&src);
		cvReleaseImage(&sub_img);
                cvDestroyWindow("Roi_Add");
	}
	return 0;
}
