// PA1: Image Enhancement
// Written by: Marwin B. Alejo 2020-20221
// February 23, 2022
// 
// TODOS (for CV students, classmates, or bored kiddos):
// Plagiarism is bad hence the following must be done to alter this work:
// 1. Use switch statement
// 2. Let the code determine the max frame of the video file and perform automatic calculation instead of predefined frames.
// 3. Use an OpenCV build with QT since this code use only the keyboard button for play/pause functionality. 
// It seems that the button module of opencv4.5 is having a bad day that the program fails whenever added haha xD.
//
// Original video may be accessed through https://www.youtube.com/watch?v=Mg_Zda7b4nc 
// Video: UP naming Mahal by UP Engg Chorale
// Alright reserved to the original owner of the video.
// Downloaded and used resolution: 720p

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

using namespace cv;
using std::cout;
using std::endl;
using std::cin;

const int slider_max = 10;
int slider;
int slide = 0;
VideoCapture video_capture("C:/Users/mbale/Desktop/CS282/upnm.mp4");

void tracker(int curPos, void*)
{
    int total = video_capture.get(CAP_PROP_FRAME_COUNT);
    int slider = total / 10;
    if (curPos == 1) {
        video_capture.set(CAP_PROP_POS_FRAMES, slider*1);
    }
    else if (curPos == 2) {
        video_capture.set(CAP_PROP_POS_FRAMES, slider*2);
    }
    else if (curPos == 3) {
        video_capture.set(CAP_PROP_POS_FRAMES, slider*3);
    }
    else if (curPos == 4) {
        video_capture.set(CAP_PROP_POS_FRAMES, slider*4);
    }
    else if (curPos == 5) {
        video_capture.set(CAP_PROP_POS_FRAMES, slider*5);
    }
    else if (curPos == 6) {
        video_capture.set(CAP_PROP_POS_FRAMES, slider*6);
    }
    else if (curPos == 7) {
        video_capture.set(CAP_PROP_POS_FRAMES, slider*7);
    }
    else if (curPos == 8) {
        video_capture.set(CAP_PROP_POS_FRAMES, slider*8);
    }
    else if (curPos == 9) {
        video_capture.set(CAP_PROP_POS_FRAMES, slider*9);
    }
    else if (curPos == 10) {
        video_capture.set(CAP_PROP_POS_FRAMES, slider*10);
    }
    else {
        video_capture.set(CAP_PROP_POS_FRAMES, slider*1);
    }
}
       
int main( int argc, char** argv)
{
    bool playVideo = true;
    namedWindow("UP naming Mahal", WINDOW_AUTOSIZE);
    //VideoCapture video_capture("C:/Users/mbale/Desktop/CS282/upnm.mp4");
    int nFrames = (int)video_capture.get(CAP_PROP_FRAME_COUNT);
    if (nFrames != 0) {
        createTrackbar("Track", "UP naming Mahal", &slide, slider_max, tracker);
        cout << "\n\nPress 'p' button on your keyboard to Pause/Unpause the video." << endl;
    }
    else {
        exit(1);
    }

    Mat frame;
    while (1) {
        if(playVideo) video_capture.read(frame);
        if (frame.empty()) { cout << "Empty frame!" << endl; return 0; }
        imshow("UP naming Mahal", frame);
        char c = waitKey(5);
        if (c == 'p') playVideo = !playVideo;
    }

    video_capture.release();
    destroyWindow("UP naming Mahal");

    return 0;
}