#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/face.hpp"
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>

using namespace std;
using namespace cv;

int detectAndDisplay(Mat frame);
void detectemo();

string face_cascade_name = "C:\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_alt2.xml";
CascadeClassifier face_cascade;
string window_name = "Window";
int filenumber;
string filename;
String cropname;




static void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';') {
	std::ifstream file(filename.c_str(), ifstream::in);
	if (!file) {
		string error_message = "No valid input file was given, please check the given filename.";
		CV_Error(CV_StsBadArg, error_message);
	}
	string line, path, classlabel;
	while (getline(file, line)) {
		stringstream liness(line);
		getline(liness, path, separator);
		getline(liness, classlabel);
		if (!path.empty() && !classlabel.empty()) {
			images.push_back(imread(path, 0));
			labels.push_back(atoi(classlabel.c_str()));
		}
	}
}

int main(void)
{
	VideoCapture capture(0);

	if (!capture.isOpened())
		return -1;

	if (!face_cascade.load(face_cascade_name))
	{
		cout << "error" << endl;
		return (-1);
	};

	Mat frame;

	for (;;)
	{
		capture >> frame;
		int k;

		if (!frame.empty())
		{
			k=detectAndDisplay(frame);
		}
		else
		{
			cout << "error2" << endl;
			break;
		} 
		
		if (filenumber == 20) {
			detectemo(); return 0;
		}
		int c = waitKey(10);

		if (27 == char(c))
		{
			break;
		}
		
	}



		return 0;
	

}
void detectemo()
{
	Mat img = cv::imread("15.jpg");
	Rect t;
	int imw = img.size().width;
	int imh = img.size().height;
	t.x = imw / 4;
	t.y = imh - 55;
	t.width = imw / 2;
	t.height = 45;
	Mat crop = img(t);
	//imshow("cropped", crop);
	
	cropname = "";
	stringstream ssfn;
	ssfn << "cropped.jpg";
	cropname = ssfn.str();
	cv::imwrite(cropname, crop);
	char ch;
	string fn_csv = string("E:\\mypro\\emotions.csv");
	vector<Mat> images;
	vector<int> labels;
	// Read in the data (fails if no valid input filename is given, but you'll get an error message):
	try {
		read_csv(fn_csv, images, labels);
	}
	catch (cv::Exception& e) {
		cerr << "Error opening file \"" << fn_csv << "\". Reason: " << e.msg << endl;
		// nothing more we can do
		exit(1);
	}
	
//	cout << "training over";
	Mat im = imread("cropped.jpg");
	Mat imr;
	Mat gray;
	cvtColor(im, gray, CV_BGR2GRAY);
	cv::resize(gray, imr, Size(185, 110), 1.0, 1.0, INTER_CUBIC);
	Ptr<face::FaceRecognizer> model = face::createFisherFaceRecognizer();
	model->train(images, labels);
	int prediction = model->predict(imr);
	//scout << "emotion is : " ;
	if(prediction==0)
	cout << "smile";
	else if(prediction==3 || prediction==2) cout << "sad";
else if (prediction == 1) cout << "neutral";

	
	cin >> ch;
}

int detectAndDisplay(Mat frame)
{
	std::vector<Rect> faces;
	Mat frame_gray;
	Mat crop;
	Mat res;
	Mat gray;
	string text;
	stringstream sstm;

	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0 | CASCADE_SCALE_IMAGE, Size(30, 30));
	//if (faces.size() > 1) { cout << "more than 1 face";  }
	cv::Rect roi_b;
	cv::Rect roi_c;

	size_t ic = 0;
	int ac = 0;

	size_t ib = 0;
	int ab = 0;

	for (ic = 0; ic < faces.size(); ic++)

	{
		roi_c.x = faces[ic].x;
		roi_c.y = faces[ic].y;
		roi_c.width = (faces[ic].width);
		roi_c.height = (faces[ic].height);

		ac = roi_c.width * roi_c.height;

		roi_b.x = faces[ib].x;
		roi_b.y = faces[ib].y;
		roi_b.width = (faces[ib].width);
		roi_b.height = (faces[ib].height);


		crop = frame(roi_b);
		resize(crop, res, Size(128, 128), 0, 0, INTER_LINEAR);
		cvtColor(crop, gray, CV_BGR2GRAY);

		filename = "";
		stringstream ssfn;
		ssfn  << filenumber << ".jpg";
		filename = ssfn.str();
		cv::imwrite(filename, gray);
		filenumber++;

	//	if (filenumber == 10) return;
		Point pt1(faces[ic].x, faces[ic].y);
		Point pt2((faces[ic].x + faces[ic].height), (faces[ic].y + faces[ic].width));
		rectangle(frame, pt1, pt2, Scalar(0, 255, 0), 2, 8, 0);
		if ((filenumber == 20)) return 0;
	}


	sstm << "Crop area size: " << roi_b.width << "x" << roi_b.height << " Filename: " << filename;
	text = sstm.str();
	imshow("original", frame);

	if (!crop.empty())
	{
		imshow("detected", crop);
	}
	else
		destroyWindow("detected");
	
	return 0;
}