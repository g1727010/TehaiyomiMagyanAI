#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::VideoCapture video(0); //カメラの起動

	if (!video.isOpened()) { //エラー処理

		std::cout << "video.error" << std::endl;
		return -1;
	}

	cv::Mat frame; //フレーム格納用

	cv::CascadeClassifier cascade; //カスケード分類機格納用

	//cascade.load("C:\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_default.xml"); //カスケードファイルの読み込み
	cascade.load("C:\\Users\\伊藤克真\\Desktop\\cv\\cascade\\cascade.xml"); //カスケードファイルの読み込み

	std::vector<cv::Rect> contour; //矩形格納用

	while (video.read(frame)) { //ループ

		cascade.detectMultiScale(frame, contour, 1.1, 5, 0, cv::Size(30, 30)); //対象の検出

		for (int i = 0; i < contour.size(); i++) { //検出個数分繰り返し
			cv::rectangle(frame, cv::Point(contour[i].x, contour[i].y), cv::Point(contour[i].x + contour[i].width, contour[i].y + contour[i].height), cv::Scalar(255, 255, 255), 1); //矩形の可視化
		}

		cv::imshow("frame", frame); //表示

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
//	Mat frame; //USBカメラから得た１フレームを格納する場所
//	CascadeClassifier cascade; //カスケード分類器格納場所
//	cascade.load("C:\\Users\\伊藤克真\\Desktop\\opencv\\build\\etc\\haarcascades\\haarcascade_frontalface_default.xml"); //正面顔情報が入っているカスケード
//	vector<Rect> faces; //輪郭情報を格納場所
//
//	VideoCapture cap(0); // USBカメラのオープン
//	if (!cap.isOpened()) //カメラが起動できなかった時のエラー処理
//	{
//		return -1;
//	}
//
//	while (1)//無限ループ
//	{
//		cap >> frame; //USBカメラが得た動画の１フレームを格納
//		cascade.detectMultiScale(frame, faces, 1.1, 3, 0, Size(30, 30)); //格納されたフレームに対してカスケードファイルに基づいて顔を検知
//		for (int i = 0; i < faces.size(); i++) //検出した顔の個数"faces.size()"分ループを行う
//		{
//			rectangle(frame, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), Scalar(0, 0, 255), 3, CV_AA); //検出した顔を赤色矩形で囲む
//		}
//
//		imshow("window", frame);//画像を表示．
//
//		int key = waitKey(1);
//		if (key == 113)//qボタンが押されたとき
//		{
//			break;//whileループから抜ける（終了）
//		}
//	}
//	destroyAllWindows();
//	return 0;
//}