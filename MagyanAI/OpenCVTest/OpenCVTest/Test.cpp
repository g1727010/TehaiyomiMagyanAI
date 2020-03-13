#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::VideoCapture video(0); //�J�����̋N��

	if (!video.isOpened()) { //�G���[����

		std::cout << "video.error" << std::endl;
		return -1;
	}

	cv::Mat frame; //�t���[���i�[�p

	cv::CascadeClassifier cascade; //�J�X�P�[�h���ދ@�i�[�p

	//cascade.load("C:\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_default.xml"); //�J�X�P�[�h�t�@�C���̓ǂݍ���
	cascade.load("C:\\Users\\�ɓ����^\\Desktop\\cv\\cascade\\cascade.xml"); //�J�X�P�[�h�t�@�C���̓ǂݍ���

	std::vector<cv::Rect> contour; //��`�i�[�p

	while (video.read(frame)) { //���[�v

		cascade.detectMultiScale(frame, contour, 1.1, 5, 0, cv::Size(30, 30)); //�Ώۂ̌��o

		for (int i = 0; i < contour.size(); i++) { //���o�����J��Ԃ�
			cv::rectangle(frame, cv::Point(contour[i].x, contour[i].y), cv::Point(contour[i].x + contour[i].width, contour[i].y + contour[i].height), cv::Scalar(255, 255, 255), 1); //��`�̉���
		}

		cv::imshow("frame", frame); //�\��

		int key = cv::waitKey(1);

		if (key == 'q') {

			cv::destroyWindow("frame");
			break;
		}
	}

	return 0;
}

//#include "opencv2/opencv.hpp"
//#include "opencv2/highgui.hpp"
//#include <vector>
//
//using namespace cv;
//using namespace std;
//
//constexpr auto CV_AA = 16;
//
//int main()
//{
//	Mat frame; //USB�J�������瓾���P�t���[�����i�[����ꏊ
//	CascadeClassifier cascade; //�J�X�P�[�h���ފ�i�[�ꏊ
//	cascade.load("C:\\Users\\�ɓ����^\\Desktop\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_default.xml"); //���ʊ��񂪓����Ă���J�X�P�[�h
//	vector<Rect> faces; //�֊s�����i�[�ꏊ
//
//	VideoCapture cap(0); // USB�J�����̃I�[�v��
//	if (!cap.isOpened()) //�J�������N���ł��Ȃ��������̃G���[����
//	{
//		return -1;
//	}
//
//	while (1)//�������[�v
//	{
//		cap >> frame; //USB�J��������������̂P�t���[�����i�[
//		cascade.detectMultiScale(frame, faces, 1.1, 3, 0, Size(30, 30)); //�i�[���ꂽ�t���[���ɑ΂��ăJ�X�P�[�h�t�@�C���Ɋ�Â��Ċ�����m
//		for (int i = 0; i < faces.size(); i++) //���o������̌�"faces.size()"�����[�v���s��
//		{
//			rectangle(frame, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 0, 255), 3, CV_AA); //���o�������ԐF��`�ň͂�
//		}
//
//		imshow("window", frame);//�摜��\���D
//
//		int key = waitKey(1);
//		if (key == 113)//q�{�^���������ꂽ�Ƃ�
//		{
//			break;//while���[�v���甲����i�I���j
//		}
//	}
//	destroyAllWindows();
//	return 0;
//}