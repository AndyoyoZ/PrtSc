#include "opencv2/opencv.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, char** argv)
{

	if(argc!=2)
	{
		cout<<"wrong number of arguments"<<endl;
		cout<<"run with your input image file name,for example:"<<endl;
		cout<<"./PrtSc ../../data/1.mp4"<<endl;
		return -1;
	}

    int count=0;
    char img_name[20];
    cv::Mat frame;
    cv::VideoCapture cap;
	//rtsp协议
    //cap.open("rtsp://admin:admin666@192.168.1.64:554/h264/ch1/main/av_stream");
	cap.open(argv[1]);
    if(!cap.isOpened())
    {
        std::cout<<"opening capture failed!"<<std::endl;
        return -1;
    }
    while(1)
    {
    cap>>frame;
    if(frame.empty())
    {
        std::cout<<"loading frame failed!"<<std::endl;
        return -1;
    }
    cv::imshow("frame",frame);
    char c=cv::waitKey(10);
    if(c=='a')
    {
        std::sprintf(img_name,"%s%03d%s","image",count++,".jpg");
        cv::imwrite(img_name,frame);
        std::cout<<"save "<<img_name<<" succesed!"<<std::endl;
    }
    else if(c==27)
    {
        std::cout<<"exiting..."<<std::endl;
        break;
    }

    }
    cap.release();
    std::cout<<"capture release!"<<std::endl;
    return 0;
}
