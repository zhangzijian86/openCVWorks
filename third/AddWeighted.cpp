#include <cv.h>
#include <highgui.h>
//./AddWeighted  1.jpg  2.jpg  700 230 150 150 0.7 0.3
int main(int argc,char** argv){
	IplImage *src1,*src2;
	if(argc == 9 &&((src1 = cvLoadImage(argv[1],1)) != 0)&&
		((src2 = cvLoadImage(argv[2],1)) != 0))
	{
		int x = atoi(argv[3]);
		int y = atoi(argv[4]);
		int width = atoi(argv[5]);
		int height = atoi(argv[6]);
		
		double alpha = (double)atoi(argv[7]);
		double beta = (double)atoi(argv[8]);
		
		cvSetImageROI(src1,cvRect(x,y,width,height));
		cvSetImageROI(src2,cvRect(0,0,width,height));

		cvAddWeighted(src1,alpha,src2,beta,0.0,src1);

		cvResetImageROI(src1);
		//cvResetImageROI(src2);

		cvNamedWindow("cvAddWeighted",1);

		cvShowImage("cvAddWeighted",src1);

		cvWaitKey();
		
		cvReleaseImage(&src1);
                cvReleaseImage(&src2);
                cvDestroyWindow("cvAddWeighted");
		
	}
	return 0;
}
