// PA1: Image Enhancement
// Programmed by: Marwin B. Alejo 2020-20221
// February 23, 2022

#include <iostream>
#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>


using namespace cv;
using std::cout;
using std::endl;
using std::cin;

void _1a()
{
    cout << "a. Select a negative floating point number. \nTake its absolute value, round it, and then take it ceiling and floor. \nPrint the results to screen.\n" << endl;
    float inpnum;
    cout << "Enter a negative float number: ";
    cin >> inpnum;
    cout << "abs, round, ceil, floor:" << endl;
    cout << cv::abs(inpnum) << endl << cvRound(inpnum) << endl << cvCeil(inpnum) << endl << cvFloor(inpnum) << "\n\n" << endl;
}

void _1b()
{
    cout << "b. Generate a 3x4 matrix whose elements are random integers. \n Print the matrix.\n" << endl;
    Mat R = Mat(4, 3, CV_8UC1);
    randu(R, Scalar::all(0), Scalar::all(255));
    cout << "R = " << endl << " " << R << "\n\n" << endl;
}

void _1c()
{
    cout << "c. Declare matrix variables A, B, and integer c within OpenCV." << endl;

    double_t Amtx[3][9] = {
        {6,0,2,2,6,5,9,7,1},
        {1,6,4,5,4,9,6,9,2},
        {3,5,9,5,3,7,8,3,3} };

    double_t Bmtx[3][9] = {
        {9,1,9,7,0,5,2,0,3},
        {9,2,3,4,3,6,0,2,9},
        {7,2,6,0,3,8,4,2,1}
    };

    double c = 0.7;
    double d = 0.55;

    Mat A(3, 9, CV_64F, &Amtx);
    Mat B(3, 9, CV_64F, &Bmtx);
    cout << "A = " << endl << " " << A << "\n\n" << endl;
    cout << "B = " << endl << " " << B << "\n\n" << endl;

    // c.i. cA+(1-c)B+d
    Mat cA(3, 9, CV_64F);
    multiply(c, A, cA);
    double cdif = 1 - c;
    Mat cdifB(3, 9, CV_64F);
    multiply(cdif, B, cdifB);
    Mat addAB(3, 9, CV_64F);
    add(cA, cdifB, addAB);
    Mat ci(3, 9, CV_64F);
    add(addAB, d, ci);
    cout << "c.i. cA+(1-c)B+d = " << endl << " " << ci << "\n\n" << endl;

    // c.ii. inv(a) using svd
    Mat invA = A.inv(DECOMP_SVD);
    cout << "c.ii. Inverse of A via SVD\n" << invA << "\n\n" << endl;

    // c.iii. Eigenvalue of B
    cout << "c.iii. Eigenvalues of B" << "\n\n" << endl;
    PCA pcaR(B, Mat(), PCA::DATA_AS_ROW);
    Mat meanR = pcaR.mean;
    Mat eigenR = pcaR.eigenvalues;
    cout << "Eigenvalues by Rows of B\n" << eigenR << "\n\n" << endl;

    PCA pcaC(B, Mat(), PCA::DATA_AS_COL);
    Mat meanC = pcaC.mean;
    Mat eigenC = pcaC.eigenvalues;
    cout << "Eigenvalues by Cols of B\n" << eigenC << "\n\n" << endl;

    // c.iv. Solve for Ax=b
    double_t bmtx[3][3] = { {3,5,5},{7,2,8},{4,1,6} };
    Mat b(3, 3, CV_64F, &bmtx);
    cout << "b:\n" << b << "\n\n" << endl;
    Mat prod = invA * b;
    cout << "c.iv. Value of x in Ax=b:\n" << prod << "\n\n" << endl;
}

void _1d()
{
    Mat img(100, 100, CV_8UC3, Scalar(0, 0, 0));
    Point p1(30, 10);
    Point p2(60, 40);
    rectangle(img, p1, p2, Scalar(0, 0, 255));
    imshow("1.d. Red Rectangle", img);
    waitKey(0);
}

void _1e()
{
    Mat img(100, 100, CV_8UC3, Scalar(0, 0, 0));
    Point p1(30, 10);
    Point p2(60, 40);
    rectangle(img, p1, p2, Scalar(0, 0, 255));
    Mat img2, img3[3];
    img.convertTo(img2, CV_8U);
    split(img2, img3);
    Mat fImg = img3[2] * 255;
    imshow("1.e. Red Rectangle to Gray", fImg);
    waitKey(0);
}

int main(int argc, char** argv)
{
    cout << "I. Write OpenCV programs that perform the ff. computations:\n" << endl;
    _1a();
    _1b();
    _1c();
    _1d();
    _1e();

    return 0;
}