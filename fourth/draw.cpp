#include <cv.h>
#include <highgui.h>

int main(int argc,char** argv){
	IplImage * src;
	if((src = cvLoadImage(argv[1],1))!=0){
		//draw line
		CvPoint cvp0 = CvPoint(100,100);
		CvPoint cvp1 = CvPoint(400,400);
		CvScalar cvs = CvScalar(255,0,0);
		cvLine(src,cvp0,cvp1,cvs,10);
		//draw line
		//draw Rectangle
		CvPoint cvp2 = CvPoint(200,500);
		CvPoint cvp3 = CvPoint(400,600);
		CvScalar cvs1 = CvScalar(255,0,0);
		cvRectangle(src,cvp2,cvp3,cvs1,10);
		//draw Rectangle
		//draw Circle
		CvPoint cvp4 = CvPoint(300,300);
		CvScalar cvs2 = CvScalar(255,0,0);
		cvCircle(src,cvp4,100,cvs2,5);
		//draw Circle
		//draw Ellipse
		CvPoint cvp5 = CvPoint(500,300);
		CvScalar cvs3 = CvScalar(255,0,0);
		CvSize cs0 = CvSize(300,200);
		cvEllipse(src,cvp5,cs0,0,0,360,cvs3,5);//cvEllipse(src,cvp5,cs0,0,0,360,cvs3,5);
		//draw Ellipse
		//draw FillPoly
		CvPoint ** cp_p_p;
		CvPoint *cp_p;
		CvPoint cp0 = CvPoint(10,10);
		cp_p = &cp0;
		cp_p++;
		CvPoint cp1 = CvPoint(20,10);
		cp_p = &cp1;
		cp_p++;
		CvPoint cp2 = CvPoint(20,20);
		cp_p = &cp2;
		cp_p++;
		CvPoint cp3 = CvPoint(50,20);
		cp_p = &cp3;
		cp_p = cp_p - 3;
		cp_p_p = &cp_p;
		int *p;
		int m = 4;
		p = &m;
		CvScalar cvs4 = CvScalar(255,0,0);
		cvFillPoly(src,cp_p_p,p,1,cvs4);
		//draw FillPoly
		//draw Text
		CvFont font;
       		cvInitFont(&font,CV_FONT_HERSHEY_DUPLEX, 1.0f,1.0f, 1);//CV_AA);
		cvPutText(src,"B",CvPoint(500,600),&font,cvs4);
		cvNamedWindow("draw",1);
		cvShowImage("draw",src);
                cvWaitKey();
                cvReleaseImage(&src);
                cvDestroyWindow("draw");

	}
	return 0;
}
