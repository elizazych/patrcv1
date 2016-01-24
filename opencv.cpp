#include <opencv2\opencv.hpp>

using namespace cv;


void main(void)
{
	int scale = 1;
	int delta = 0;
	int ddepth = CV_16S;


	Mat obrazek = imread("in.png");
	Mat src;
	cvtColor(obrazek, src, CV_RGB2GRAY);
	imwrite("grayscale.png", src);

	Mat dst;
	Mat grad;
	
	dst = src.clone();

	GaussianBlur(src, dst, Size(3, 3), 0, 0);
	imwrite("gauss.png", dst);
	
	Mat grad_x, grad_y;
	Mat abs_grad_x, abs_grad_y;
	
	///X
	Sobel(src, grad_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_x, abs_grad_x);

	/// Y
	Sobel(src, grad_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
	convertScaleAbs(grad_y, abs_grad_y);


	addWeighted(abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad);

	imwrite("sobel.png", grad);

	waitKey();
}

